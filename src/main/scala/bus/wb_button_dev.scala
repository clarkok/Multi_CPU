import Chisel._

class WB_Button_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val BTN = Bits(INPUT, 5)
    }
    
    io.bus.dat4 := io.BTN
    io.bus.ack := Bool(true)
}