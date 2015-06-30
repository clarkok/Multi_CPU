import Chisel._

class WB_IO extends Bundle {
    val addr = UInt(OUTPUT, 32)
    val dat2 = UInt(OUTPUT, 32)
    val dat4 = UInt(INPUT, 32)
    val sel  = Bool(OUTPUT)
    val we   = Bool(OUTPUT)
    val ack  = Bool(INPUT)
}
