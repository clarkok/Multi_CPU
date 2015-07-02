import Chisel._

object TestMain {
    def main(args : Array[String]): Unit = {
        /*
        chiselMainTest(args, () => Module(new WB_Led_Dev())) {
            c => new WB_Led_Dev_Tests(c)
        }
        chiselMainTest(args, () => Module(new WB_Seven_Dev())) {
            c => new WB_Seven_Dev_Tests(c)
        }
        chiselMainTest(args, () => Module(new WB_Bus())) {
            c => new WB_Bus_Tests(c)
        }
        chiselMainTest(args, () => Module(new ALU())) {
            c => new ALU_Tests(c)
        }
        chiselMainTest(args, () => Module(new Register_File())) {
            c => new Register_File_Tests(c)
        }
        chiselMainTest(args, () => Module(new Datapath())) {
            c => new Datapath_Tests(c)
        }
        */
        chiselMainTest(args, () => Module(new Mock_Top())) {
            c => new Mock_Test(c)
        }
        chiselMain(args, () => Module(new SOC()))
    }
}