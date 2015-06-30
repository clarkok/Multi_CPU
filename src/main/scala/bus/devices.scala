import Chisel._

class Devices_IO extends Bundle {
    val SW = Bits(INPUT, 8)
    val LED = Bits(OUTPUT, 8)
    val BTN = Bits(INPUT, 5)
    val DISP_NUM = Bits(OUTPUT, 32)
}

class Ram_Wrap extends BlackBox {
    val io = new Ram_IO().flip()
}

/*
class Ram_Wrap extends Module {
    val io = new Ram_IO().flip()
    
    io.douta := MuxLookup(
        io.addra,
        UInt(0),
        Array(
            UInt(0) -> UInt("h20010001"),
            UInt(1) -> UInt("h20020002"),
            UInt(2) -> UInt("h0022182a"),
            UInt(3) -> UInt("h3c04a000"),
            UInt(4) -> UInt("hac830000"),
            UInt(5) -> UInt("h20020010"),
            UInt(6) -> UInt("h00411806"),
            UInt(7) -> UInt("hac830000"),
            UInt(8) -> UInt("h2001002c"),
            UInt(9) -> UInt("h00200008"),
            UInt(10) -> UInt("h20420001"),
            UInt(11) -> UInt("hac820000")
        )
    )
}
*/

class Devices extends Module {
    val io = new Bundle {
        val bus = new WB_IO().flip()
        val devices = new Devices_IO()
    }
    
    val bus         = Module(new WB_Bus())
    
    val sw          = Module(new WB_Sw_Dev())
    val btn         = Module(new WB_Button_Dev())
    val led         = Module(new WB_Led_Dev())
    val counter     = Module(new WB_Empty_Dev())
    val seven_seg   = Module(new WB_Seven_Dev())
    
    val ram_dev     = Module(new WB_Ram_Dev())
    val ram         = Module(new Ram_Wrap())
    
    ram.io <> ram_dev.io.ram
    
    io.bus <> bus.io.from_cpu
    bus.io.slaves(0) <> sw.io.bus
    bus.io.slaves(1) <> btn.io.bus
    bus.io.slaves(2) <> led.io.bus
    bus.io.slaves(3) <> counter.io.bus
    bus.io.slaves(4) <> seven_seg.io.bus
    bus.io.slaves(5) <> Module(new WB_Empty_Dev()).io.bus
    bus.io.slaves(6) <> Module(new WB_Empty_Dev()).io.bus
    bus.io.slaves(7) <> Module(new WB_Empty_Dev()).io.bus
    bus.io.ram_slave <> ram_dev.io.bus
    
    io.devices.SW   <> sw.io.SW
    io.devices.LED  <> led.io.LED
    io.devices.BTN  <> btn.io.BTN
    io.devices.DISP_NUM <> seven_seg.io.DISP_NUM
}