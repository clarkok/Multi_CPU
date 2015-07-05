import Chisel._

class WB_VGA_Dev_Tests(c : WB_VGA_Dev) extends Tester(c) {
    poke(c.io.bus.sel, 1)
    poke(c.io.bus.we, 1)
    poke(c.io.bus.addr, 0)
    poke(c.io.bus.dat2, 0x0F00)
    step(1)
    poke(c.io.bus.sel, 0)
    poke(c.io.bus.we, 0)
    for (i <- 0 until 416800) {
        step(1)
        expect(c.io.vga.red, 0)
    }
}