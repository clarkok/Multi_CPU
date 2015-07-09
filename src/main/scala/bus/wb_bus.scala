import Chisel._

class WB_Empty_Dev extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
    }
    
    io.bus.dat4 := UInt(0)
    io.bus.ack := Bool(true)
}

class WB_Bus() extends Module {
    val io = new Bundle {
        val from_cpu = new WB_IO().flip()
        val slaves = Vec.fill(8) { new WB_IO() }
        val ram_slave = new WB_IO()
    }
    
    val data_out = Reg(init = UInt(0, 32))
    val ack_out = Reg(init = Bool(true))
    
    val current_slave = io.from_cpu.addr.apply(30, 28)
    
    val ram_op = ~io.from_cpu.addr(31)
    
    for (i <- 0 until 8) {
        io.slaves(i).addr := io.from_cpu.addr.apply(27, 0)
        io.slaves(i).sel := ~ram_op & io.from_cpu.sel & (current_slave === UInt(i))
        io.slaves(i).we := ~ram_op & io.from_cpu.we & (current_slave === UInt(i))
        io.slaves(i).dat2 := io.from_cpu.dat2
    }
    io.ram_slave.addr := io.from_cpu.addr.apply(27, 0)
    io.ram_slave.sel := ram_op & io.from_cpu.sel
    io.ram_slave.we := ram_op & io.from_cpu.we
    io.ram_slave.dat2 := io.from_cpu.dat2
    
    io.from_cpu.dat4    :=
        Mux(
            ram_op,
            io.ram_slave.dat4,
            io.slaves(current_slave).dat4
        )
    
    io.from_cpu.ack     :=
        Mux(
            ram_op,
            io.ram_slave.ack,
            io.slaves(current_slave).ack
        )
}