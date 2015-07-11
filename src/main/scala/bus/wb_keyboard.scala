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
    
    val k_clk_test_reg  = Reg(init = UInt(0, width=32))
    
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
                UInt(0x4E) -> UInt(45), // -
                UInt(0x55) -> UInt(43), // +
                UInt(0x15) -> UInt('q'),
                UInt(0x1D) -> UInt('w'),
                UInt(0x24) -> UInt('e'),
                UInt(0x2D) -> UInt('r'),
                UInt(0x2C) -> UInt('t'),
                UInt(0x35) -> UInt('y'),
                UInt(0x3C) -> UInt('u'),
                UInt(0x43) -> UInt('i'),
                UInt(0x44) -> UInt('o'),
                UInt(0x4D) -> UInt('p'),
                UInt(0x54) -> UInt('['),
                UInt(0x5B) -> UInt(']'),
                UInt(0x1C) -> UInt('a'),
                UInt(0x1B) -> UInt('s'),
                UInt(0x23) -> UInt('d'),
                UInt(0x2B) -> UInt('f'),
                UInt(0x34) -> UInt('g'),
                UInt(0x33) -> UInt('h'),
                UInt(0x3B) -> UInt('j'),
                UInt(0x42) -> UInt('k'),
                UInt(0x4B) -> UInt('l'),
                UInt(0x4C) -> UInt(';'),
                UInt(0x52) -> UInt('\''),
                UInt(0x1A) -> UInt('z'),
                UInt(0x22) -> UInt('x'),
                UInt(0x21) -> UInt('c'),
                UInt(0x2A) -> UInt('v'),
                UInt(0x32) -> UInt('b'),
                UInt(0x31) -> UInt('n'),
                UInt(0x3A) -> UInt('m'),
                UInt(0x41) -> UInt(','),
                UInt(0x49) -> UInt('.'),
                UInt(0x4A) -> UInt('/'),
                UInt(0x29) -> UInt(' '),
                UInt(0x66) -> UInt(8),  // Backspace
                // UInt(0x5A) -> UInt(13)  // Enter
                UInt(0x5A) -> UInt(10)  // Enter to '\n'
            )
        )
    
    when(kb.io.ctrl.interrupt) {
        raw := kb.io.ctrl.data
        r_count := r_count + UInt(1)
        
        when(kb.io.ctrl.data === UInt("hF0")) {
            p_f0 := Bool(true)
        }
        .elsewhen(cooked_next.orR()) {
            cooked := cooked_next + (p_f0 << UInt(8))
            c_count := c_count + UInt(1)
            p_f0 := Bool(false)
        }
    }
    
    when(io.keyboard.kb_clk) {
        k_clk_test_reg := k_clk_test_reg + UInt(1)
    }
    
    io.bus.ack := Bool(true)
    io.bus.dat4 :=
        MuxLookup(
            io.bus.addr.apply(2, 0),
            UInt(0),
            Array(
                UInt(0) -> raw,
                UInt(1) -> r_count,
                UInt(2) -> cooked,
                UInt(3) -> c_count,
                UInt(4) -> k_clk_test_reg,
                UInt(5) -> k_clk_test_reg,
                UInt(6) -> k_clk_test_reg,
                UInt(7) -> k_clk_test_reg
            )
        )
}