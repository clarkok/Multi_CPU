import Chisel._

class Debug_IO extends Bundle {
    val inst_out = UInt(OUTPUT, 32)
    val bus_addr = UInt(OUTPUT, 32)
    val bus_dat2 = UInt(OUTPUT, 32)
    val bus_dat4 = UInt(OUTPUT, 32)
    val pc_out = UInt(OUTPUT, 32)
}

class SOC extends Module {
    val io = new Bundle {
        val devices = new Devices_IO()
    }
    
    val cpu = Module(new Core())
    val dev = Module(new Devices())
    
    io.devices <> dev.io.devices
    cpu.io.bus <> dev.io.bus
}