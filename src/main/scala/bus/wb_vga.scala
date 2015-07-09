import Chisel._

class VGA_IO extends Bundle {
    val red = UInt(OUTPUT, 3)
    val green = UInt(OUTPUT, 3)
    val blue = UInt(OUTPUT, 2)
    val hsync = Bool(OUTPUT)
    val vsync = Bool(OUTPUT)
}

object VGA_Constants {
    final val VGA_H_LIMIT = UInt(800)
    final val VGA_V_LIMIT = UInt(521)
    
    final val S_PW = UInt(0)
    final val S_BW = UInt(1)
    final val S_DP = UInt(2)
    final val S_FP = UInt(3)
}

class VGA_Ctrl extends Module {
    val io = new Bundle {
        val vga = new VGA_IO()
        val ctrl = new Bundle {
            val x = UInt(OUTPUT, 32)
            val y = UInt(OUTPUT, 32)
            val color = UInt(INPUT, 8)
        }
    }
    
    // pixel counter
    val p_counter = Reg(init = UInt(0, width=1))
    when(p_counter === UInt(1))
        { p_counter := UInt(0) }
    .otherwise
        { p_counter := p_counter + UInt(1) }
    
    // horizontal counter
    val h_counter = Reg(init = UInt(0, width=32))
    // vertical counter
    val v_counter = Reg(init = UInt(0, width=32))
    
    when(p_counter === UInt(0)) {
        when(h_counter === VGA_Constants.VGA_H_LIMIT - UInt(1))
            {
                h_counter := UInt(0)
                when(v_counter === VGA_Constants.VGA_V_LIMIT - UInt(1))
                    { v_counter := UInt(0) }
                .otherwise
                    { v_counter := v_counter + UInt(1) }
            }
        .otherwise
            { h_counter := h_counter + UInt(1) }
    }
        
    val h_state =
        MuxCase(
            VGA_Constants.S_PW,
            Array(
                (h_counter >= UInt(0) && h_counter < UInt(96)) 
                    -> VGA_Constants.S_PW,
                (h_counter >= UInt(96) && h_counter < UInt(144))
                    -> VGA_Constants.S_BW,
                (h_counter >= UInt(144) && h_counter < UInt(784))
                    -> VGA_Constants.S_DP,
                (h_counter >= UInt(784) && h_counter < UInt(800))
                    -> VGA_Constants.S_FP
            )
        )
    val v_state =
        MuxCase(
            VGA_Constants.S_PW,
            Array(
                (v_counter >= UInt(0) && v_counter < UInt(2)) 
                    -> VGA_Constants.S_PW,
                (v_counter >= UInt(2) && v_counter < UInt(31))
                    -> VGA_Constants.S_BW,
                (v_counter >= UInt(31) && v_counter < UInt(511))
                    -> VGA_Constants.S_DP,
                (v_counter >= UInt(511) && v_counter < UInt(521))
                    -> VGA_Constants.S_FP
            )
        )
        
    val output_en =
        (h_state === VGA_Constants.S_DP) &&
        (v_state === VGA_Constants.S_DP)
    
    io.vga.red := 
        Mux(
            output_en,
            io.ctrl.color.apply(7, 5),
            UInt(0)
        )
    io.vga.green :=
        Mux(
            output_en,
            io.ctrl.color.apply(4, 2),
            UInt(0)
        )
    io.vga.blue :=
        Mux(
            output_en,
            io.ctrl.color.apply(1, 0),
            UInt(0)
        )
    
    io.ctrl.x :=
        Mux(
            (h_state === VGA_Constants.S_DP),
            (h_counter - UInt(144)),
            UInt(0)
        )
        
    io.ctrl.y :=
        Mux(
            (v_state === VGA_Constants.S_DP),
            (v_counter - UInt(31)),
            UInt(0)
        )
    io.vga.vsync :=
        MuxLookup(
            v_state,
            Bool(false),
            Array(
                VGA_Constants.S_PW -> Bool(false),
                VGA_Constants.S_BW -> Bool(true),
                VGA_Constants.S_DP -> Bool(true),
                VGA_Constants.S_FP -> Bool(true)
            )
        )
    io.vga.hsync :=
        MuxLookup(
            h_state,
            Bool(false),
            Array(
                VGA_Constants.S_PW -> Bool(false),
                VGA_Constants.S_BW -> Bool(true),
                VGA_Constants.S_DP -> Bool(true),
                VGA_Constants.S_FP -> Bool(true)
            )
        )
}

class Font_Rom_Wrapper extends BlackBox {
    val io = new Bundle {
        val addr = UInt(INPUT, 12)
        val data = UInt(OUTPUT, 8)
    }
    
    io.data := 
        MuxLookup(
            io.addr,
            UInt(0),
            Array(
                UInt(0) -> UInt("b10101010"),
                UInt(1) -> UInt("b01010101"),
                UInt(2) -> UInt("b11000110"),
                UInt(3) -> UInt("b11000110"),
                UInt(4) -> UInt("b11000110"),
                UInt(5) -> UInt("b11000110"),
                UInt(6) -> UInt("b11111110"),
                UInt(7) -> UInt("b11000110"),
                UInt(8) -> UInt("b11000110"),
                UInt(9) -> UInt("b11000110"),
                UInt(10) -> UInt("b11000110"),
                UInt(11) -> UInt("b11000110"),
                UInt(12) -> UInt("b00000000"),
                UInt(13) -> UInt("b00000000"),
                UInt(14) -> UInt("b00000000"),
                UInt(15) -> UInt("b00000000")
            )
        )
}

class WB_VGA_Dev extends Module {
    val io = new Bundle {
        val vga = new VGA_IO()
        val bus = new WB_IO().flip()
    }
    
    val vga = Module(new VGA_Ctrl())
    val font = Module(new Font_Rom_Wrapper())
    val vmem = Mem(UInt(width = 16), 80 * 30)
    
    val data = vmem(
        (vga.io.ctrl.y.apply(31, 4)) * UInt(80) +
        (vga.io.ctrl.x.apply(31, 3))
    )
    
    val char = data.apply(7, 0)
    val color = data.apply(15, 8)
    
    font.io.addr := (char << UInt(4)) + vga.io.ctrl.y.apply(3, 0)
    val mask = font.io.data
    
    val front_color =
        color.apply(2) ## color.apply(2) ## color.apply(2) ##
        color.apply(1) ## color.apply(1) ## color.apply(1) ##
        color.apply(0) ## color.apply(0)
    val back_color =
        color.apply(6) ## color.apply(6) ## color.apply(6) ##
        color.apply(5) ## color.apply(5) ## color.apply(5) ##
        color.apply(4) ## color.apply(4)
    
    vga.io.ctrl.color :=
        Mux(
            mask.apply(UInt(7) - vga.io.ctrl.x.apply(2, 0)),
            front_color,
            back_color
        )
    
    io.vga := vga.io.vga
    
    val out_buf     = Reg(init = UInt(0, 32))
    val addr_buf    = Reg(init = UInt(0, 32))
    val data_buf    = Reg(init = UInt(0, 32))
    val is_writing  = Reg(init = Bool(false))
    val ack         = Reg(init = Bool(true))
    
    when(io.bus.sel) {
        ack         := ~ack
        addr_buf    := io.bus.addr.apply(11, 0)
        data_buf    := io.bus.dat2
        is_writing  := io.bus.we
    }
    .otherwise {
        ack         := Bool(true)
    }
    
    when(~ack) {
        when(is_writing)    { vmem(addr_buf)    := data_buf }
        .otherwise          { out_buf           := vmem(addr_buf) }
    }
    
    io.bus.dat4 := out_buf
    io.bus.ack  := ack
}