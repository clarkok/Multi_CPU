import Chisel._

class Core extends Module {
    val io = new Bundle {
        val bus = new WB_IO()
        val debug = new Debug_IO()
    }
    
    val cpath = Module(new Ctrlpath())
    val dpath = Module(new Datapath())
    
    io.bus <> cpath.io.bus
    cpath.io.ctrl <> dpath.io
    
    io.debug <> cpath.io.debug
}