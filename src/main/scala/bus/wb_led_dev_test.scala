import Chisel._

class WB_Led_Dev_Tests(c : WB_Led_Dev) extends Tester(c) {
    poke(c.io.bus.addr, 0)
    poke(c.io.bus.dat2, 0)
    poke(c.io.bus.sel, 1)
    poke(c.io.bus.we, 0)
    step(1)
    expect(c.io.bus.dat4, 0)
    expect(c.io.LED, 0)
    
    poke(c.io.bus.addr, 0)
    poke(c.io.bus.dat2, 1)
    poke(c.io.bus.sel, 1)
    poke(c.io.bus.we, 1)
    step(1)
    expect(c.io.bus.dat4, 1)
    expect(c.io.LED, 1)
    
    poke(c.io.bus.addr, 0)
    poke(c.io.bus.dat2, 1)
    poke(c.io.bus.sel, 1)
    poke(c.io.bus.we, 0)
    step(1)
    expect(c.io.bus.dat4, 1)
    expect(c.io.LED, 1)
    
    poke(c.io.bus.addr, 0)
    poke(c.io.bus.dat2, 1)
    poke(c.io.bus.sel, 0)
    poke(c.io.bus.we, 0)
    step(1)
    expect(c.io.bus.dat4, 0)
    expect(c.io.LED, 1)
}