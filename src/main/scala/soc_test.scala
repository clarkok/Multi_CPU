import Chisel._

class SOC_Tests(c : SOC) extends Tester(c) {
    step(1)
    expect(c.io.debug.pc_out, 0)
    
    step(1)
    expect(c.io.debug.pc_out, 4)
    step(1)
    expect(c.io.debug.pc_out, 4)
    
    step(1)
    expect(c.io.debug.pc_out, 8)
    step(1)
    expect(c.io.debug.pc_out, 8)
    
    step(1)
    expect(c.io.debug.pc_out, 12)
    step(1)
    expect(c.io.debug.pc_out, 12)
    
    step(1)
    expect(c.io.debug.pc_out, 16)
    step(1)
    expect(c.io.debug.pc_out, 16)
    
    step(1)
    expect(c.io.devices.LED, 1)
    expect(c.io.debug.pc_out, 20)
    step(1)
    expect(c.io.debug.pc_out, 20)
    
    step(1)
    expect(c.io.debug.pc_out, 24)
    step(1)
    expect(c.io.debug.pc_out, 24)
    
    step(1)
    expect(c.io.debug.pc_out, 28)
    step(1)
    expect(c.io.debug.pc_out, 28)
    
    step(1)
    expect(c.io.devices.LED, 8)
    expect(c.io.debug.pc_out, 32)
    step(1)
    expect(c.io.debug.pc_out, 32)
    
    step(1)
    expect(c.io.debug.pc_out, 36)
    step(1)
    expect(c.io.debug.pc_out, 36)
    
    step(1)
    expect(c.io.debug.pc_out, 44)
    step(1)
    expect(c.io.debug.pc_out, 44)
    
    step(1)
    expect(c.io.devices.LED, 16)
}