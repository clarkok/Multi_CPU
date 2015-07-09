import Chisel._

class WB_Counter_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
    }
    
    val counter_next = UInt(width = 32)
    val counter = Reg(init = UInt(0, 32), next = counter_next)
    
    when(io.bus.we) {
        counter_next := io.bus.dat2
    }
    .otherwise {
        counter_next := counter + UInt(1)
    }
    
    io.bus.dat4 := counter
    io.bus.ack := Bool(true)
}