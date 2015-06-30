import Chisel._

class WB_Sw_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val SW = Bits(INPUT, 8)
    }
    
    io.bus.dat4 := io.SW
    io.bus.ack := Bool(true)
}