import Chisel._

class Ram_Mock extends Module {
    val io = new Ram_IO().flip()
    
    io.douta := MuxLookup(
            io.addra,
            UInt(0, 32),
            Array(
                UInt(0) -> UInt("h3c02a000"),
                UInt(1) -> UInt("h3c018000"),
                UInt(2) -> UInt("h8c230000"),
                UInt(3) -> UInt("hac430000"),
                UInt(4) -> UInt("h08000002")
            )
        )
}

class Mock_Top extends Module {
    val io = new Bundle {
        val debug = new Debug_IO()
        val devices = new Devices_IO()
    }
    
    val soc = Module(new SOC())
    
    val ram = Module(new Ram_Mock())
    
    io.debug <> soc.io.debug
    soc.io.devices.RAM <> ram.io
    
    io.devices.LED <> soc.io.devices.LED
    io.devices.SW <> soc.io.devices.SW
    io.devices.BTN <> soc.io.devices.BTN
    io.devices.VGA <> soc.io.devices.VGA
}

class Mock_Test(c : Mock_Top) extends Tester(c) {
    step(1)
    expect(c.io.debug.pc_out, 0)
    step(1)
    expect(c.io.debug.pc_out, 4)
    
    step(1)
    expect(c.io.debug.pc_out, 4)
    step(1)
    expect(c.io.debug.pc_out, 8)
    
    poke(c.io.devices.SW, 1)
    step(1)
    expect(c.io.debug.pc_out, 8)
    step(1)
    expect(c.io.debug.pc_out, 12)
    
    step(1)
    expect(c.io.debug.pc_out, 12)
    step(1)
    expect(c.io.debug.pc_out, 16)
    expect(c.io.devices.LED, 1)
    
    step(1)
    expect(c.io.debug.pc_out, 16)
    step(1)
    expect(c.io.debug.pc_out, 8)
    
    poke(c.io.devices.SW, 2)
    step(1)
    expect(c.io.debug.pc_out, 8)
    step(1)
    expect(c.io.debug.pc_out, 12)
    
    step(1)
    expect(c.io.debug.pc_out, 12)
    step(1)
    expect(c.io.debug.pc_out, 16)
    expect(c.io.devices.LED, 2)
    
    step(1)
    expect(c.io.debug.pc_out, 16)
    step(1)
    expect(c.io.debug.pc_out, 8)
}