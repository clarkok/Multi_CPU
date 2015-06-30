#ifndef __Datapath__
#define __Datapath__

#include "emulator.h"

class Datapath_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> Datapath__io_alu_b_sel;
  dat_t<1> Datapath__io_reg_we;
  dat_t<1> Datapath_regfile__io_we;
  dat_t<1> T53;
  dat_t<1> Datapath__io_inst_we;
  dat_t<1> reset;
  dat_t<1> Datapath_alu__io_zero;
  dat_t<1> Datapath__io_pc_we;
  dat_t<2> Datapath__io_reg_we_src;
  dat_t<2> Datapath__io_reg_we_dst;
  dat_t<2> Datapath__io_pc_next_sel;
  dat_t<3> Datapath__io_alu_op;
  dat_t<3> Datapath_alu__io_alu_op;
  dat_t<5> Datapath_regfile__io_addrb;
  dat_t<5> Datapath_regfile__io_addra;
  dat_t<5> Datapath_regfile__io_wtaddr;
  dat_t<32> Datapath__io_bus_data;
  dat_t<32> Datapath_regfile__io_doutb;
  dat_t<32> Datapath_alu__io_in_b;
  dat_t<32> Datapath_regfile__io_douta;
  dat_t<32> Datapath_alu__io_in_a;
  dat_t<32> Datapath_alu__io_out;
  dat_t<32> Datapath_regfile__io_wtdata;
  dat_t<32> Datapath__io_inst;
  dat_t<32> Datapath__io_pc_out;
  dat_t<32> Datapath__io_alu_out;
  dat_t<32> Datapath__io_data_out;
  dat_t<32> T55;
  dat_t<32> Datapath__inst_reg;
  dat_t<32> T90;
  dat_t<32> Datapath__pc;
  mem_t<32,32> Datapath_regfile__rf;
  int clk;
  int clk_cnt;

  void init ( val_t rand_init = 0 );
  void clock_lo ( dat_t<1> reset );
  void clock_hi ( dat_t<1> reset );
  int clock ( dat_t<1> reset );
  mod_t* clone();
  bool set_circuit_from(mod_t* src);
  void print ( FILE* f );
  void print ( std::ostream& s );
  void dump ( FILE* f, int t );
  void dump_init ( FILE* f );

};

class Datapath_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
