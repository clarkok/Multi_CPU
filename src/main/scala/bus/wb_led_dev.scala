import Chisel._

class WB_Led_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val LED = Bits(OUTPUT, 8)
    }
    
    val led_data = Reg(init = UInt(0, 8))
    
    io.LED := led_data
    io.bus.dat4 := led_data
    
    io.bus.ack := Bool(true)
    
    when(io.bus.sel & io.bus.we) {
        led_data := io.bus.dat2
    }
}