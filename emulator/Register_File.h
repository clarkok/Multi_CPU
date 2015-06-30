#ifndef __Register_File__
#define __Register_File__

#include "emulator.h"

class Register_File_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> Register_File__io_we;
  dat_t<1> T2;
  dat_t<5> Register_File__io_addra;
  dat_t<5> Register_File__io_wtaddr;
  dat_t<5> Register_File__io_addrb;
  dat_t<32> Register_File__io_douta;
  dat_t<32> Register_File__io_wtdata;
  dat_t<32> Register_File__io_doutb;
  mem_t<32,32> Register_File__rf;
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

class Register_File_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
