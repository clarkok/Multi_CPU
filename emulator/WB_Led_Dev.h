#ifndef __WB_Led_Dev__
#define __WB_Led_Dev__

#include "emulator.h"

class WB_Led_Dev_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> WB_Led_Dev__io_bus_we;
  dat_t<1> WB_Led_Dev__io_bus_sel;
  dat_t<1> reset;
  dat_t<1> WB_Led_Dev__io_bus_ack;
  dat_t<8> T13;
  dat_t<8> WB_Led_Dev__led_data;
  dat_t<8> WB_Led_Dev__io_LED;
  dat_t<32> WB_Led_Dev__io_bus_dat2;
  dat_t<32> T9;
  dat_t<32> WB_Led_Dev__data_out;
  dat_t<32> WB_Led_Dev__io_bus_dat4;
  dat_t<32> WB_Led_Dev__io_bus_addr;
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

class WB_Led_Dev_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
