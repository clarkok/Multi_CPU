import Chisel._

class WB_Bus_Tests(c : WB_Bus) extends Tester(c) {
    poke(c.io.from_cpu.addr, 0x80000000)
    poke(c.io.from_cpu.dat2, 0)
    poke(c.io.from_cpu.sel, 1)
    poke(c.io.from_cpu.we, 0)
    step(1)
    expect(c.io.slaves(0).addr, 0)
    expect(c.io.slaves(0).dat2, 0)
    expect(c.io.slaves(0).sel, 1)
    expect(c.io.slaves(0).we, 0)
    for (i <- 1 until 8) {
        expect(c.io.slaves(i).addr, 0)
        expect(c.io.slaves(i).dat2, 0)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    
    poke(c.io.slaves(0).ack, 1)
    poke(c.io.slaves(0).dat4, 10010)
    poke(c.io.from_cpu.sel, 0)
    step(1)
    expect(c.io.from_cpu.dat4, 10010)
    expect(c.io.from_cpu.ack, 1)
    expect(c.io.slaves(0).addr, 0)
    expect(c.io.slaves(0).dat2, 0)
    expect(c.io.slaves(0).sel, 0)
    expect(c.io.slaves(0).we, 0)
    for (i <- 1 until 8) {
        expect(c.io.slaves(i).addr, 0)
        expect(c.io.slaves(i).dat2, 0)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    
    poke(c.io.from_cpu.addr, 0x80000001)
    poke(c.io.from_cpu.dat2, 10011)
    poke(c.io.from_cpu.sel, 1)
    poke(c.io.from_cpu.we, 1)
    step(1)
    expect(c.io.slaves(0).addr, 1)
    expect(c.io.slaves(0).dat2, 10011)
    expect(c.io.slaves(0).sel, 1)
    expect(c.io.slaves(0).we, 1)
    for (i <- 1 until 8) {
        expect(c.io.slaves(i).addr, 1)
        expect(c.io.slaves(i).dat2, 10011)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    
    poke(c.io.from_cpu.addr, 0xFFFFFFFF)
    poke(c.io.from_cpu.dat2, 10110)
    poke(c.io.from_cpu.sel, 1)
    poke(c.io.from_cpu.we, 1)
    step(1)
    expect(c.io.slaves(7).addr, 0x0FFFFFFF)
    expect(c.io.slaves(7).dat2, 10110)
    expect(c.io.slaves(7).sel, 1)
    expect(c.io.slaves(7).we, 1)
    for (i <- 0 until 7) {
        expect(c.io.slaves(i).addr, 0x0FFFFFFF)
        expect(c.io.slaves(i).dat2, 10110)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    
    poke(c.io.from_cpu.addr, 0x0FFFFFFF)
    poke(c.io.from_cpu.dat2, 11111)
    poke(c.io.from_cpu.sel, 1)
    poke(c.io.from_cpu.we, 1)
    poke(c.io.ram_slave.ack, 0)
    step(1)
    for (i <- 0 until 8) {
        expect(c.io.slaves(i).addr, 0x0FFFFFFF)
        expect(c.io.slaves(i).dat2, 11111)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    expect(c.io.ram_slave.addr, 0x0FFFFFFF)
    expect(c.io.ram_slave.dat2, 11111)
    expect(c.io.ram_slave.sel, 1)
    expect(c.io.ram_slave.we, 1)
    expect(c.io.from_cpu.ack, 0)
    
    step(1)
    for (i <- 0 until 8) {
        expect(c.io.slaves(i).addr, 0x0FFFFFFF)
        expect(c.io.slaves(i).dat2, 11111)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    expect(c.io.ram_slave.addr, 0x0FFFFFFF)
    expect(c.io.ram_slave.dat2, 11111)
    expect(c.io.ram_slave.sel, 1)
    expect(c.io.ram_slave.we, 1)
    expect(c.io.from_cpu.ack, 0)
    
    poke(c.io.ram_slave.ack, 1)
    poke(c.io.from_cpu.sel, 0)
    poke(c.io.from_cpu.we, 0)
    step(1)
    for (i <- 0 until 8) {
        expect(c.io.slaves(i).addr, 0x0FFFFFFF)
        expect(c.io.slaves(i).dat2, 11111)
        expect(c.io.slaves(i).sel, 0)
        expect(c.io.slaves(i).we, 0)
    }
    expect(c.io.ram_slave.addr, 0x0FFFFFFF)
    expect(c.io.ram_slave.dat2, 11111)
    expect(c.io.ram_slave.sel, 0)
    expect(c.io.ram_slave.we, 0)
    expect(c.io.from_cpu.ack, 1)
}