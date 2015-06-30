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
    
    io.from_cpu.dat4 := MuxCase(
            UInt(0, 32),
            Array(
                (ram_op === Bool(false)) -> MuxLookup(
                        current_slave,
                        UInt(0, 32),
                        Array(
                            UInt(0) -> io.slaves(0).dat4,
                            UInt(1) -> io.slaves(1).dat4,
                            UInt(2) -> io.slaves(2).dat4,
                            UInt(3) -> io.slaves(3).dat4,
                            UInt(4) -> io.slaves(4).dat4,
                            UInt(5) -> io.slaves(5).dat4,
                            UInt(6) -> io.slaves(6).dat4,
                            UInt(7) -> io.slaves(7).dat4
                        )
                    ),
                (ram_op === Bool(true)) -> io.ram_slave.dat4
            )
        )
    
    io.from_cpu.ack := MuxCase(
            Bool(false),
            Array(
                (ram_op === Bool(false)) -> MuxLookup(
                        current_slave,
                        Bool(false),
                        Array(
                            UInt(0) -> io.slaves(0).ack,
                            UInt(1) -> io.slaves(1).ack,
                            UInt(2) -> io.slaves(2).ack,
                            UInt(3) -> io.slaves(3).ack,
                            UInt(4) -> io.slaves(4).ack,
                            UInt(5) -> io.slaves(5).ack,
                            UInt(6) -> io.slaves(6).ack,
                            UInt(7) -> io.slaves(7).ack
                        )
                    ),
                (ram_op === Bool(true)) -> io.ram_slave.ack
            )
        )
    
    when(ack_out) {
        printf(" --- current_slave: %d\n", current_slave);
        printf(" --- cpu_we: %d\n", io.from_cpu.we);
        printf(" --- ram_op: %d\n", ram_op);
        printf(" --- led_sel: %d\n", io.slaves(2).sel);
        printf(" --- led_we: %d\n", io.slaves(2).we);
    }
}