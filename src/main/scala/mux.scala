import Chisel._

class Mux8to1_32bit extends BlackBox {
    val io = new Bundle {
        val sel = UInt(INPUT, 3)
        val in0 = UInt(INPUT, 32)
        val in1 = UInt(INPUT, 32)
        val in2 = UInt(INPUT, 32)
        val in3 = UInt(INPUT, 32)
        val in4 = UInt(INPUT, 32)
        val in5 = UInt(INPUT, 32)
        val in6 = UInt(INPUT, 32)
        val in7 = UInt(INPUT, 32)
        val out = UInt(OUTPUT, 32)
    }
}

class Mux8to1_1bit extends BlackBox {
    val io = new Bundle {
        val sel = UInt(INPUT, 3)
        val in0 = UInt(INPUT, 1)
        val in1 = UInt(INPUT, 1)
        val in2 = UInt(INPUT, 1)
        val in3 = UInt(INPUT, 1)
        val in4 = UInt(INPUT, 1)
        val in5 = UInt(INPUT, 1)
        val in6 = UInt(INPUT, 1)
        val in7 = UInt(INPUT, 1)
        val out = UInt(OUTPUT, 1)
    }
}