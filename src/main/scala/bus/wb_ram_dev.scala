import Chisel._

class Ram_IO extends Bundle {
    val addra = UInt(OUTPUT, 10)
    val dina = UInt(OUTPUT, 32)
    val we = Bool(OUTPUT)
    val douta = UInt(INPUT, 32)
}

class WB_Ram_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val ram = new Ram_IO()
    }
    
    io.bus.ack := Bool(true)
    io.ram.addra := io.bus.addr.apply(11, 2)
    io.ram.dina := io.bus.dat2
    io.ram.we := io.bus.sel & io.bus.we
    io.bus.dat4 := MuxLookup(
            io.bus.addr.apply(1, 0),
            io.ram.douta,
            Array(
                UInt(0) -> io.ram.douta,
                UInt(1) -> (io.ram.douta.apply(31, 8)),
                UInt(2) -> (io.ram.douta.apply(31, 16)),
                UInt(3) -> (io.ram.douta.apply(31, 24))
            )
        )
}