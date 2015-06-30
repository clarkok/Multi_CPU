import Chisel._

class WB_Seven_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val DISP_NUM = Bits(OUTPUT, 32)
    }
    
    val data_out = Reg(init = UInt(0, 32))
    val disp_data = Reg(init = UInt(0, 32))
    
    io.bus.dat4 := data_out
    io.bus.ack := Bool(true)
    io.DISP_NUM := disp_data
    
    when(io.bus.sel & io.bus.we) {
        disp_data := io.bus.dat2
        data_out := io.bus.dat2
    }
    .elsewhen(io.bus.sel) {
        data_out := disp_data
    }
    .otherwise {
        data_out := UInt(0)
    }
}