#ifndef __WB_Bus__
#define __WB_Bus__

#include "emulator.h"

class WB_Bus_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> WB_Bus__io_ram_slave_ack;
  dat_t<1> WB_Bus__io_slaves_7_ack;
  dat_t<1> WB_Bus__io_slaves_6_ack;
  dat_t<1> WB_Bus__io_slaves_5_ack;
  dat_t<1> WB_Bus__io_slaves_4_ack;
  dat_t<1> WB_Bus__io_slaves_3_ack;
  dat_t<1> WB_Bus__io_slaves_2_ack;
  dat_t<1> WB_Bus__io_slaves_1_ack;
  dat_t<1> WB_Bus__io_slaves_0_ack;
  dat_t<1> WB_Bus__io_from_cpu_ack;
  dat_t<1> WB_Bus__io_from_cpu_sel;
  dat_t<1> reset;
  dat_t<1> T51;
  dat_t<1> WB_Bus__slave_sel_7;
  dat_t<1> WB_Bus__io_slaves_7_sel;
  dat_t<1> WB_Bus__io_from_cpu_we;
  dat_t<1> T57;
  dat_t<1> WB_Bus__slave_we_7;
  dat_t<1> WB_Bus__io_slaves_7_we;
  dat_t<1> T64;
  dat_t<1> WB_Bus__slave_sel_6;
  dat_t<1> WB_Bus__io_slaves_6_sel;
  dat_t<1> T69;
  dat_t<1> WB_Bus__slave_we_6;
  dat_t<1> WB_Bus__io_slaves_6_we;
  dat_t<1> T76;
  dat_t<1> WB_Bus__slave_sel_5;
  dat_t<1> WB_Bus__io_slaves_5_sel;
  dat_t<1> T81;
  dat_t<1> WB_Bus__slave_we_5;
  dat_t<1> WB_Bus__io_slaves_5_we;
  dat_t<1> T88;
  dat_t<1> WB_Bus__slave_sel_4;
  dat_t<1> WB_Bus__io_slaves_4_sel;
  dat_t<1> T93;
  dat_t<1> WB_Bus__slave_we_4;
  dat_t<1> WB_Bus__io_slaves_4_we;
  dat_t<1> T100;
  dat_t<1> WB_Bus__slave_sel_3;
  dat_t<1> WB_Bus__io_slaves_3_sel;
  dat_t<1> T105;
  dat_t<1> WB_Bus__slave_we_3;
  dat_t<1> WB_Bus__io_slaves_3_we;
  dat_t<1> T112;
  dat_t<1> WB_Bus__slave_sel_2;
  dat_t<1> WB_Bus__io_slaves_2_sel;
  dat_t<1> T117;
  dat_t<1> WB_Bus__slave_we_2;
  dat_t<1> WB_Bus__io_slaves_2_we;
  dat_t<1> T124;
  dat_t<1> WB_Bus__slave_sel_1;
  dat_t<1> WB_Bus__io_slaves_1_sel;
  dat_t<1> T129;
  dat_t<1> WB_Bus__slave_we_1;
  dat_t<1> WB_Bus__io_slaves_1_we;
  dat_t<1> T136;
  dat_t<1> WB_Bus__slave_sel_0;
  dat_t<1> WB_Bus__io_slaves_0_sel;
  dat_t<1> T141;
  dat_t<1> WB_Bus__slave_we_0;
  dat_t<1> WB_Bus__io_slaves_0_we;
  dat_t<1> WB_Bus__io_ram_slave_sel;
  dat_t<1> T145;
  dat_t<1> WB_Bus__ack_out;
  dat_t<1> WB_Bus__io_ram_slave_we;
  dat_t<32> WB_Bus__io_ram_slave_dat4;
  dat_t<32> WB_Bus__io_from_cpu_addr;
  dat_t<32> WB_Bus__io_slaves_7_dat4;
  dat_t<32> WB_Bus__io_slaves_6_dat4;
  dat_t<32> WB_Bus__io_slaves_5_dat4;
  dat_t<32> WB_Bus__io_slaves_4_dat4;
  dat_t<32> WB_Bus__io_slaves_3_dat4;
  dat_t<32> WB_Bus__io_slaves_2_dat4;
  dat_t<32> WB_Bus__io_slaves_1_dat4;
  dat_t<32> WB_Bus__io_slaves_0_dat4;
  dat_t<32> WB_Bus__io_from_cpu_dat4;
  dat_t<32> WB_Bus__io_slaves_7_addr;
  dat_t<32> WB_Bus__io_from_cpu_dat2;
  dat_t<32> WB_Bus__io_slaves_7_dat2;
  dat_t<32> WB_Bus__io_slaves_6_addr;
  dat_t<32> WB_Bus__io_slaves_6_dat2;
  dat_t<32> WB_Bus__io_slaves_5_addr;
  dat_t<32> WB_Bus__io_slaves_5_dat2;
  dat_t<32> WB_Bus__io_slaves_4_addr;
  dat_t<32> WB_Bus__io_slaves_4_dat2;
  dat_t<32> WB_Bus__io_slaves_3_addr;
  dat_t<32> WB_Bus__io_slaves_3_dat2;
  dat_t<32> WB_Bus__io_slaves_2_addr;
  dat_t<32> WB_Bus__io_slaves_2_dat2;
  dat_t<32> WB_Bus__io_slaves_1_addr;
  dat_t<32> WB_Bus__io_slaves_1_dat2;
  dat_t<32> WB_Bus__io_slaves_0_addr;
  dat_t<32> WB_Bus__io_slaves_0_dat2;
  dat_t<32> WB_Bus__io_ram_slave_addr;
  dat_t<32> WB_Bus__io_ram_slave_dat2;
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

class WB_Bus_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
