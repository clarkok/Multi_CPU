import Chisel._

class ALU extends Module {
    val io = new Bundle {
        val alu_op = UInt(INPUT, 3)
        val in_a = UInt(INPUT, 32)
        val in_b = UInt(INPUT, 32)
        val out = UInt(OUTPUT, 32)
        val zero = Bool(OUTPUT)
    }
    
    io.out := 
        Vec(Array(
            (io.in_a & io.in_b),
            (io.in_a | io.in_b),
            (io.in_a + io.in_b),
            (io.in_a ^ io.in_b),
            (~(io.in_a | io.in_b)),
            (io.in_a >> io.in_b.apply(4, 0)),
            (io.in_a - io.in_b),
            (io.in_a < io.in_b)
        ))(io.alu_op);
    
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
    
    when (reset) {
        for (i <- 0 until 32) {
            rf(UInt(i)) := UInt(0)
        }
    }
}

class Datapath extends Module {
    val io = new CtrlIO().flip()
    
    val pc = RegInit(init = UInt(0, 32))
    val alu = Module(new ALU())
    val regfile = Module(new Register_File())
    val inst_reg = Reg(init = UInt(0, 32))
    val alu_out = Reg(init = UInt(0, 32), next = alu.io.out)
    val alu_zero = Reg(init = Bool(false), next = alu.io.zero)
    val bus_buf = Reg(init = UInt(0, 32), next = io.bus_data)
    
    when(io.inst_we & io.ack) { inst_reg := io.bus_data }
    io.inst := inst_reg
        
    val branch_pc =
        Mux(
            (alu_zero ^ (io.alu_b_sel === UInt(2))),
            (pc + SInt(4) + (inst_reg.apply(15, 0) << UInt(2)).toSInt()).toUInt(),
            (pc + UInt(4))
        )
    val pc_next = 
        Vec(Array(
            (pc + UInt(4)),
            branch_pc,
            (pc.apply(31, 28) ## (inst_reg.apply(25, 0)) ## UInt(0, 2)),
            regfile.io.douta
        ))(io.pc_next_sel)
    when(io.pc_we && io.ack) { pc := pc_next }
    io.pc_out := pc
    
    regfile.io.addra := inst_reg.apply(25, 21)
    regfile.io.addrb := inst_reg.apply(20, 16)
    regfile.io.we := io.reg_we & io.ack
    regfile.io.wtdata :=
        Vec(Array(
            alu_out,
            bus_buf,
            pc + UInt(4),
            (alu_out.apply(15, 0) ## UInt(0, 16))
        ))(io.reg_we_src)
    regfile.io.wtaddr :=
        Vec(Array(
            inst_reg.apply(15, 11),
            inst_reg.apply(20, 16),
            UInt(31)
        ))(io.reg_we_dst)
        
    alu.io.alu_op   := io.alu_op
    alu.io.in_a     := regfile.io.douta
    alu.io.in_b     :=
        Vec(Array(
            regfile.io.doutb,
            inst_reg.apply(15, 0),
            regfile.io.doutb
        ))(io.alu_b_sel)
        
    io.data_out     := regfile.io.doutb
    io.alu_out      := alu_out
}