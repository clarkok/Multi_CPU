import Chisel._

class Keyboard_IO extends Bundle {
    val kb_clk = Bool(INPUT)
    val kb_data = Bool(INPUT)
}

class Keyboard_Ctrl extends BlackBox {
    val io = new Bundle {
        val keyboard = new Keyboard_IO()
        val ctrl = new Bundle {
            val data = UInt(OUTPUT, 8)
            val interrupt = Bool(OUTPUT)
        }
    }
    addClock(Driver.implicitClock)
}

class WB_Keyboard_Dev extends Module {
    val io = new Bundle {
        val keyboard = new Keyboard_IO()
        val bus = new WB_IO().flip()
    }
    
    val kb      = Module(new Keyboard_Ctrl())
    kb.io.keyboard <> io.keyboard
    
    val r_count = Reg(init = UInt(0, width=32))
    val raw     = Reg(init = UInt(0, width=8))
    val c_count = Reg(init = UInt(0, width=32))
    val cooked  = Reg(init = UInt(0, width=16))
    
    val p_f0    = Reg(init = Bool(false))
    val cooked_next =
        MuxLookup(
            kb.io.ctrl.data,
            UInt(0),
            Array(
                UInt(0x16) -> UInt(49), // 1
                UInt(0x1E) -> UInt(50), // 2
                UInt(0x26) -> UInt(51), // 3
                UInt(0x25) -> UInt(52), // 4
                UInt(0x2E) -> UInt(53), // 5
                UInt(0x36) -> UInt(54), // 6
                UInt(0x3D) -> UInt(55), // 7
                UInt(0x3E) -> UInt(56), // 8
                UInt(0x46) -> UInt(57), // 9
                UInt(0x45) -> UInt(48), // 0
                UInt(0x66) -> UInt(8),  // Backspace
                UInt(0x5A) -> UInt(13)  // Enter
            )
        )
    
    when(kb.io.ctrl.interrupt) {
        raw := kb.io.ctrl.data
        r_count := r_count + UInt(1)
        
        when(kb.io.ctrl.data === UInt("hF0")) {
            p_f0 := Bool(true)
        }
        .otherwise {
            cooked := cooked_next + (p_f0 << UInt(8))
            c_count := c_count + UInt(1)
            p_f0 := Bool(false)
        }
    }
    
    io.bus.ack := Bool(true)
    io.bus.dat4 :=
        MuxLookup(
            io.bus.addr.apply(1, 0),
            UInt(0),
            Array(
                UInt(0) -> raw,
                UInt(1) -> r_count,
                UInt(2) -> cooked,
                UInt(3) -> c_count
            )
        )
}