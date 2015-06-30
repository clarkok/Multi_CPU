#ifndef __ALU__
#define __ALU__

#include "emulator.h"

class ALU_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> ALU__io_zero;
  dat_t<3> ALU__io_alu_op;
  dat_t<32> ALU__io_in_b;
  dat_t<32> ALU__io_in_a;
  dat_t<32> ALU__io_out;
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

class ALU_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
