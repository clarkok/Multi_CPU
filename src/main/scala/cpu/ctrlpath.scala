import Chisel._

class CtrlIO extends Bundle {
    val bus_data = Bits(OUTPUT, 32)
    
    val inst = Bits(INPUT, 32)
    val inst_we = Bool(OUTPUT)
    
    val pc_we = Bool(OUTPUT)
    val pc_next_sel = UInt(OUTPUT, 2)
        /**
         * 0 : pc + 4
         * 1 : branch ( pc + (imm << 2) )
         * 2 : jump ( pc[31:30] | (jump_imm << 2) )
         * 3 : rs ( regfile.douta )
         */
    val pc_out = UInt(INPUT, 32)
    
    val reg_we = Bool(OUTPUT)
    val reg_we_src = UInt(OUTPUT, 2)
        /**
         * 0 : alu_out
         * 1 : bus_data
         * 2 : pc + 4
         * 3 : alu_out << 16 // lui
         */
    val reg_we_dst = UInt(OUTPUT, 2)
        /**
         * 0 : rd
         * 1 : rt
         * 2 : $31
         */
         
    val alu_op = UInt(OUTPUT, 3)
    val alu_b_sel = UInt(OUTPUT, 2)
        /**
         * 0 : rt
         * 1 : imm
         * 2 : rt // only for bne
         */
    val alu_out = UInt(INPUT, 32)
         
    val data_out = UInt(INPUT, 32)
    
    val ack = Bool(OUTPUT)
}

object States {
    final val FETCH = UInt(0)
    
    final val ADD   = UInt(1)
    final val ADDU  = UInt(2)
    final val SUB   = UInt(3)
    final val SUBU  = UInt(4)
    final val AND   = UInt(5)
    final val OR    = UInt(6)
    final val XOR   = UInt(7)
    final val NOR   = UInt(8)
    final val SLT   = UInt(9)
    final val SRLV  = UInt(10)
    final val JR    = UInt(11)
    
    final val ADDI  = UInt(12)
    final val ADDIU = UInt(13)
    final val ANDI  = UInt(14)
    final val ORI   = UInt(15)
    final val XORI  = UInt(16)
    final val LUI   = UInt(17)
    final val LW    = UInt(18)
    final val SW    = UInt(19)
    
    final val BEQ   = UInt(20)
    final val BNE   = UInt(21)
    final val SLTI  = UInt(22)
    final val J     = UInt(23)
    final val JAL   = UInt(24)
    
    final val R_WB  = UInt(100)
    final val I_WB  = UInt(101)
    final val L_WB  = UInt(102)
    
    final val PC_INC    = UInt(110)
    
    final val LW_BUS    = UInt(120)
    final val LW_WB     = UInt(121)
    final val SW_BUS    = UInt(122)
    
    final val BEQ_SET_PC    = UInt(150)
    final val BNE_SET_PC    = UInt(151)
    
    final val DECODE    = UInt(200)
}

class Ctrlpath extends Module {
    val io = new Bundle {
        val ctrl = new CtrlIO()
        val bus = new WB_IO()
        // val debug = new Debug_IO()
    }
    
    val next_state = UInt(width=32)
    val state = Reg(init = States.FETCH)
    
    val ctrl_signal =
        ListLookup(
            state,
    /**
     *                  inst_we,        pc_we,          pc_next_sel,    reg_we,         reg_we_src, reg_we_dst, alu_op,     alu_b_sel
     *                  bus_sel,        bus_we,         bus_addr_alu
     */
                    List(Bool(false),   Bool(true),     UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
            Array(
                States.FETCH -> 
                    List(Bool(true),    Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(true),    Bool(false),    Bool(false)),
                
                States.DECODE ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.ADD -> 
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(2),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.ADDU ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(2),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.SUB -> 
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.SUBU ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.AND ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.OR ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(1),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.XOR ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(3),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.NOR ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(4),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.SLT ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(7),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.SRLV ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(5),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.JR ->
                    List(Bool(false),   Bool(true),     UInt(3),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.R_WB ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(true ),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                         
    /**
     *                  inst_we,        pc_we,          pc_next_sel,    reg_we,         reg_we_src, reg_we_dst, alu_op,     alu_b_sel
     *                  bus_sel,        bus_we,         bus_addr_alu
     */
                States.ADDI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                States.ADDIU ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                States.ANDI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(0),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                States.ORI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(1),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                States.XORI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(3),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                States.SLTI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(1),    UInt(7),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.I_WB ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(true ),    UInt(0),    UInt(1),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.LUI ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(3),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.L_WB ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(true ),    UInt(3),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                         
                States.LW ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(1),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(true)),
                States.SW ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(true)),
                         
                States.LW_BUS ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(1),    UInt(1),    UInt(2),    UInt(1),
                         Bool(true ),   Bool(false),    Bool(true)),
                         
                States.LW_WB ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(true ),    UInt(1),    UInt(1),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(true)),
                         
                States.SW_BUS ->
                    List(Bool(false),   Bool(false),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(2),    UInt(1),
                         Bool(true ),   Bool(true),     Bool(true)),
                         
                States.PC_INC ->
                    List(Bool(false),   Bool(true ),    UInt(0),        Bool(false),    UInt(0),    UInt(0),    UInt(2),    UInt(1),
                         Bool(false),   Bool(false),    Bool(false)),
                         
    /**
     *                  inst_we,        pc_we,          pc_next_sel,    reg_we,         reg_we_src, reg_we_dst, alu_op,     alu_b_sel
     *                  bus_sel,        bus_we,         bus_addr_alu
     */
                States.BEQ ->
                    List(Bool(false),   Bool(false),    UInt(1),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.BEQ_SET_PC ->
                    List(Bool(false),   Bool(true ),    UInt(1),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                
                States.BNE ->
                    List(Bool(false),   Bool(false),    UInt(1),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(2),
                         Bool(false),   Bool(false),    Bool(false)),
                States.BNE_SET_PC ->
                    List(Bool(false),   Bool(true ),    UInt(1),        Bool(false),    UInt(0),    UInt(0),    UInt(6),    UInt(2),
                         Bool(false),   Bool(false),    Bool(false)),
                
                States.J ->
                    List(Bool(false),   Bool(true),     UInt(2),        Bool(false),    UInt(0),    UInt(0),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false)),
                States.JAL ->
                    List(Bool(false),   Bool(true),     UInt(2),        Bool(true),     UInt(2),    UInt(2),    UInt(0),    UInt(0),
                         Bool(false),   Bool(false),    Bool(false))
            )
        )
        
    val (inst_we : Bool) :: (pc_we : Bool) :: pc_next_sel :: (reg_we : Bool) :: reg_we_src :: reg_we_dst :: alu_op :: alu_b_sel :: (bus_sel : Bool) :: (bus_we : Bool) :: bus_addr_src :: Nil = ctrl_signal
    
    val bus_addr_buf    = Reg(init = UInt(0, 32))
    val bus_dat2_buf    = Reg(init = UInt(0, 32))
    val bus_dat4_buf    = Reg(init = UInt(0, 32))
    
    val inst        = io.ctrl.inst
    val inst_op     = inst.apply(31, 26)
    val inst_func   = inst.apply(5, 0)
    
    next_state :=
        MuxLookup(
            state,
            States.FETCH,
            Array(
                States.ADD      -> States.R_WB,
                States.ADDU     -> States.R_WB,
                States.SUB      -> States.R_WB,
                States.SUBU     -> States.R_WB,
                States.AND      -> States.R_WB,
                States.OR       -> States.R_WB,
                States.XOR      -> States.R_WB,
                States.NOR      -> States.R_WB,
                States.SLT      -> States.R_WB,
                States.SRLV     -> States.R_WB,
                
                States.ADDI     -> States.I_WB,
                States.ADDIU    -> States.I_WB,
                States.ANDI     -> States.I_WB,
                States.ORI      -> States.I_WB,
                States.XORI     -> States.I_WB,
                States.SLTI     -> States.I_WB,
                States.LUI      -> States.L_WB,
                
                States.LW       -> States.LW_BUS,
                States.LW_BUS   -> States.LW_WB,
                States.LW_WB    -> States.PC_INC,
                
                States.SW       -> States.SW_BUS,
                States.SW_BUS   -> States.PC_INC,
                
                States.BEQ      -> States.BEQ_SET_PC,
                States.BNE      -> States.BNE_SET_PC,
                
                States.R_WB     -> States.PC_INC,
                States.I_WB     -> States.PC_INC,
                States.L_WB     -> States.PC_INC,
                
                States.PC_INC   -> States.FETCH,
                States.BEQ_SET_PC   -> States.FETCH,
                States.BNE_SET_PC   -> States.FETCH,
                
                States.JAL      -> States.FETCH,
    
                States.FETCH    -> States.DECODE,
                
                States.DECODE -> (
                    MuxLookup(
                        inst_op,
                        States.FETCH,
                        Array(
                            UInt(0) -> (
                                MuxLookup(
                                    inst_func,
                                    States.FETCH,
                                    Array(
                                        UInt("b100000") -> States.ADD,
                                        UInt("b100001") -> States.ADDU,
                                        UInt("b100010") -> States.SUB,
                                        UInt("b100011") -> States.SUBU,
                                        UInt("b100100") -> States.AND,
                                        UInt("b100101") -> States.OR,
                                        UInt("b100110") -> States.XOR,
                                        UInt("b100111") -> States.NOR,
                                        UInt("b101010") -> States.SLT,
                                        UInt("b000110") -> States.SRLV,
                                        UInt("b001000") -> States.JR
                                    )
                                )
                            ),
                            UInt("b001000") -> States.ADDI,
                            UInt("b001001") -> States.ADDIU,
                            UInt("b001100") -> States.ANDI,
                            UInt("b001101") -> States.ORI,
                            UInt("b001110") -> States.XORI,
                            UInt("b001111") -> States.LUI,
                            UInt("b100011") -> States.LW,
                            UInt("b101011") -> States.SW,
                            
                            UInt("b000100") -> States.BEQ,
                            UInt("b000101") -> States.BNE,
                            UInt("b001010") -> States.SLTI,
                            UInt("b000010") -> States.J,
                            UInt("b000011") -> States.JAL
                        )
                    )
                )
            )
        )
    
    when(io.bus.ack) {
        state := next_state
    }
    
    io.ctrl.inst_we     := inst_we
    io.ctrl.pc_we       := pc_we
    io.ctrl.pc_next_sel := pc_next_sel
    io.ctrl.reg_we      := reg_we
    io.ctrl.reg_we_src  := reg_we_src
    io.ctrl.reg_we_dst  := reg_we_dst
    io.ctrl.alu_op      := alu_op
    io.ctrl.alu_b_sel   := alu_b_sel
    io.ctrl.ack         := io.bus.ack
    io.ctrl.bus_data    := io.bus.dat4
    
    io.bus.sel          := bus_sel
    io.bus.we           := bus_we
    io.bus.addr         := 
        Mux(
            bus_addr_src.toBool(),
            io.ctrl.alu_out,
            io.ctrl.pc_out
        )
    io.bus.dat2         := io.ctrl.data_out
    
    /*
    // FOR DEBUG
    io.debug.inst_out   := inst
    io.debug.bus_addr   := io.bus.addr
    io.debug.bus_dat2   := io.bus.dat2
    io.debug.bus_dat4   := io.bus.dat4
    io.debug.pc_out     := io.ctrl.pc_out
    */
}