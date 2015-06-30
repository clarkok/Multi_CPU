import Chisel._

class ALU extends Module {
    val io = new Bundle {
        val alu_op = UInt(INPUT, 3)
        val in_a = UInt(INPUT, 32)
        val in_b = UInt(INPUT, 32)
        val out = UInt(OUTPUT, 32)
        val zero = Bool(OUTPUT)
    }
    
    io.out := MuxLookup(
        io.alu_op,
        UInt(0, 32),
        Array(
            UInt(0) -> (io.in_a & io.in_b).toUInt(),
            UInt(1) -> (io.in_a | io.in_b).toUInt(),
            UInt(2) -> (io.in_a + io.in_b).toUInt(),
            UInt(3) -> (io.in_a ^ io.in_b).toUInt(),
            UInt(4) -> (~(io.in_a | io.in_b)).toUInt(),
            UInt(5) -> (io.in_a >> io.in_b.apply(4, 0)).toUInt(),
            UInt(6) -> (io.in_a - io.in_b).toUInt(),
            UInt(7) -> (io.in_a < io.in_b).toUInt()
        )
    )
    
    io.zero := !(io.out.orR())
}

class Register_File extends Module {
    val io = new Bundle {
        val addra = UInt(INPUT, 5)
        val douta = UInt(OUTPUT, 32)
        val addrb = UInt(INPUT, 5)
        val doutb = UInt(OUTPUT, 32)
        
        val wtaddr = UInt(INPUT, 5)
        val wtdata = UInt(INPUT, 32)
        val we = Bool(INPUT)
    }
    
    val rf = Mem(UInt(width = 32), 32)
    
    io.douta := rf(io.addra)
    io.doutb := rf(io.addrb)
    
    when (io.we && io.wtaddr != UInt(0)) {
        rf(io.wtaddr) := io.wtdata
    }
}

class Datapath extends Module {
    val io = new CtrlIO().flip()
    
    val pc = Reg(init = UInt(0, 32))
    val alu = Module(new ALU())
    val regfile = Module(new Register_File())
    val inst_reg = Reg(init = UInt(0, 32))
    
    when(io.inst_we) { inst_reg := io.bus_data }
    io.inst := inst_reg
    
    val pc_next = 
        MuxLookup(
            io.pc_next_sel,
            UInt(0, 32),
            Array(
                UInt(0) -> (pc + UInt(4)),
                UInt(1) -> (
                    MuxCase(
                        UInt(0, 32),
                        Array(
                            (alu.io.zero === Bool(true)) ->
                                (pc + (inst_reg.apply(15, 0).toSInt() << UInt(2))).toUInt(),
                            (alu.io.zero === Bool(false)) ->
                                (pc + UInt(4))
                        )
                    )
                ),
                UInt(2) -> (pc.apply(31, 28) | (inst_reg.apply(25, 0) << UInt(2))),
                UInt(3) -> (regfile.io.douta)
            )
        )
    when(io.pc_we) { pc := pc_next }
    io.pc_out := pc
    
    regfile.io.addra := inst_reg.apply(25, 21)
    regfile.io.addrb := inst_reg.apply(20, 16)
    regfile.io.we := io.reg_we
    regfile.io.wtdata :=
        MuxLookup(
            io.reg_we_src,
            UInt(0, 32),
            Array(
                UInt(0) -> (alu.io.out),
                UInt(1) -> (io.bus_data),
                UInt(2) -> (pc + UInt(4)),
                UInt(3) -> (alu.io.out << UInt(16))
            )
        )
    regfile.io.wtaddr :=
        MuxLookup(
            io.reg_we_dst,
            UInt(0, 5),
            Array(
                UInt(0) -> inst_reg.apply(15, 11),
                UInt(1) -> inst_reg.apply(20, 16),
                UInt(2) -> UInt(31)
            )
        )
        
    alu.io.alu_op := io.alu_op
    alu.io.in_a := regfile.io.douta
    alu.io.in_b :=
        MuxLookup(
            io.alu_b_sel,
            UInt(0, 32),
            Array(
                UInt(0) -> regfile.io.doutb,
                UInt(1) -> inst_reg.apply(15, 0),
                UInt(2) -> (~regfile.io.doutb)
            )
        )
    io.alu_out := alu.io.out
    
    io.data_out := regfile.io.doutb
}