import Chisel._

class WB_Led_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val LED = Bits(OUTPUT, 8)
    }
    
    val data_out = Reg(init = UInt(0, 32))
    val led_data = Reg(init = Bits(0, 8))
    
    io.bus.dat4 := data_out
    io.bus.ack := Bool(true)
    io.LED := led_data
    
    when(io.bus.sel & io.bus.we) {
        printf(" ---- sel: %d\n", io.bus.sel);
        printf(" ---- we: %d\n", io.bus.we);
        printf(" ---- data: %d\n", io.bus.dat2);
        led_data := io.bus.dat2
        data_out := io.bus.dat2
    }
    .elsewhen(io.bus.sel) {
        data_out := led_data
    }
    .otherwise {
        data_out := UInt(0)
    }
}