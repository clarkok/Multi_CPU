import Chisel._

class Devices_IO extends Bundle {
    val SW = Bits(INPUT, 8)
    val LED = Bits(OUTPUT, 8)
    val BTN = Bits(INPUT, 5)
    val DISP_NUM = Bits(OUTPUT, 32)
    val VGA = new VGA_IO()
    val RAM = new Ram_IO()
    val KEYBOARD = new Keyboard_IO()
}

class Devices extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val devices = new Devices_IO()
    }
    
    val bus         = Module(new WB_Bus())
    
    val sw          = Module(new WB_Sw_Dev())
    val btn         = Module(new WB_Button_Dev())
    val led         = Module(new WB_Led_Dev())
    val counter     = Module(new WB_Counter_Dev())
    val seven_seg   = Module(new WB_Seven_Dev())
    val ram_dev     = Module(new WB_Ram_Dev())
    val vga_dev     = Module(new WB_VGA_Dev())
    val kb_dev      = Module(new WB_Keyboard_Dev())
    
    io.bus <> bus.io.from_cpu
    bus.io.slaves(0) <> sw.io.bus
    bus.io.slaves(1) <> btn.io.bus
    bus.io.slaves(2) <> led.io.bus
    bus.io.slaves(3) <> counter.io.bus
    bus.io.slaves(4) <> seven_seg.io.bus
    bus.io.slaves(5) <> vga_dev.io.bus
    bus.io.slaves(6) <> kb_dev.io.bus
    bus.io.slaves(7) <> Module(new WB_Empty_Dev()).io.bus
    bus.io.ram_slave <> ram_dev.io.bus
    
    io.devices.SW   <> sw.io.SW
    io.devices.LED  <> led.io.LED
    io.devices.BTN  <> btn.io.BTN
    io.devices.DISP_NUM <> seven_seg.io.DISP_NUM
    io.devices.RAM  <> ram_dev.io.ram
    io.devices.VGA  <> vga_dev.io.vga
    io.devices.KEYBOARD <> kb_dev.io.keyboard
}