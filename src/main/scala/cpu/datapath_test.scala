import Chisel._

class ALU_Tests(c : ALU) extends Tester(c) {
    poke(c.io.in_a, 0x0000FFFF)
    poke(c.io.in_b, 0x0F0F0F0F)
    
    for (op <- 0 until 8) {
        poke(c.io.alu_op, op)
        step(1)
        expect(c.io.zero, 0)
        expect(c.io.out, 
            (op) match {
                case 0 => 0x0000FFFF & 0x0F0F0F0F
                case 1 => 0x0000FFFF | 0x0F0F0F0F
                case 2 => 0x0000FFFF + 0x0F0F0F0F
                case 3 => 0x0000FFFF ^ 0x0F0F0F0F
                case 4 => ~(0x0000FFFF | 0x0F0F0F0F)
                case 5 => 0x0000FFFF >> (0x0F0F0F0F % 32)
                case 6 => 0x0000FFFF - 0x0F0F0F0F
                case 7 => if (0x0000FFFF < 0x0F0F0F0F) 1 else 0
            }
        )
    }
}

class Register_File_Tests(c : Register_File) extends Tester(c) {
    poke(c.io.wtaddr, 1)
    poke(c.io.wtdata, 1)
    poke(c.io.we, 1)
    poke(c.io.addra, 1)
    step(1)
    expect(c.io.douta, 1)
    
    poke(c.io.wtaddr, 0)
    step(1)
    expect(c.io.addrb, 0)
}

class Datapath_Tests(c : Datapath) extends Tester(c) {
    // empty instrument
    poke(c.io.bus_data, 0)
    poke(c.io.inst_we, 0)
    poke(c.io.pc_we, 1)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    expect(c.io.pc_out, 4)
    
    // load instrument: set imm to 1
    poke(c.io.bus_data, 1)
    poke(c.io.inst_we, 1)
    poke(c.io.pc_we, 0)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    expect(c.io.inst, 1)
    
    // branch
    poke(c.io.bus_data, 1)
    poke(c.io.inst_we, 0)
    poke(c.io.pc_we, 1)
    poke(c.io.pc_next_sel, 1)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    expect(c.io.pc_out, 8)
    
    // jump
    poke(c.io.bus_data, 1)
    poke(c.io.inst_we, 0)
    poke(c.io.pc_we, 1)
    poke(c.io.pc_next_sel, 2)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    expect(c.io.pc_out, 4)
    
    // addi $1, $0, 1
    poke(c.io.bus_data, 0x20010001)
    poke(c.io.inst_we, 1)
    poke(c.io.pc_we, 0)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    // exec
    poke(c.io.bus_data, 0)
    poke(c.io.inst_we, 0)
    poke(c.io.pc_we, 0)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 1)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 2)
    poke(c.io.alu_b_sel, 1)
    step(1)
    expect(c.io.alu_out, 1)
    
    // lw $2, 0($0)
    poke(c.io.bus_data, 0x8c020000)
    poke(c.io.inst_we, 1)
    poke(c.io.pc_we, 0)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 0)
    poke(c.io.reg_we_src, 0)
    poke(c.io.reg_we_dst, 0)
    poke(c.io.alu_op, 0)
    poke(c.io.alu_b_sel, 0)
    step(1)
    // exec
    poke(c.io.bus_data, 2)
    poke(c.io.inst_we, 0)
    poke(c.io.pc_we, 0)
    poke(c.io.pc_next_sel, 0)
    poke(c.io.reg_we, 1)
    poke(c.io.reg_we_src, 1)
    poke(c.io.reg_we_dst, 1)
    poke(c.io.alu_op, 2)
    poke(c.io.alu_b_sel, 1)
    step(1)
    expect(c.io.alu_out, 0)
    expect(c.io.data_out, 2)
}