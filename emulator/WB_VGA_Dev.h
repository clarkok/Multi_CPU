#ifndef __WB_VGA_Dev__
#define __WB_VGA_Dev__

#include "emulator.h"

class WB_VGA_Dev_t : public mod_t {
 private:
  val_t __rand_seed;
  void __srand(val_t seed) { __rand_seed = seed; }
  val_t __rand_val() { return ::__rand_val(&__rand_seed); }
 public:
  dat_t<1> reset;
  dat_t<1> WB_VGA_Dev_vga__reset;
  dat_t<1> WB_VGA_Dev_vga__io_vga_hsync;
  dat_t<1> WB_VGA_Dev__io_vga_hsync;
  dat_t<1> WB_VGA_Dev_vga__io_vga_vsync;
  dat_t<1> WB_VGA_Dev__io_vga_vsync;
  dat_t<1> WB_VGA_Dev__io_bus_we;
  dat_t<1> WB_VGA_Dev__io_bus_sel;
  dat_t<1> T135;
  dat_t<1> WB_VGA_Dev__io_bus_ack;
  dat_t<1> WB_VGA_Dev_font__reset;
  dat_t<1> T139;
  dat_t<2> T4;
  dat_t<2> WB_VGA_Dev_vga__p_counter;
  dat_t<2> WB_VGA_Dev_vga__io_vga_blue;
  dat_t<2> WB_VGA_Dev__io_vga_blue;
  dat_t<3> WB_VGA_Dev_vga__io_vga_red;
  dat_t<3> WB_VGA_Dev__io_vga_red;
  dat_t<3> WB_VGA_Dev_vga__io_vga_green;
  dat_t<3> WB_VGA_Dev__io_vga_green;
  dat_t<8> WB_VGA_Dev_font__io_data;
  dat_t<8> WB_VGA_Dev_vga__io_ctrl_color;
  dat_t<12> WB_VGA_Dev_font__io_addr;
  dat_t<12> T131;
  dat_t<12> T140;
  dat_t<16> T130;
  dat_t<32> T13;
  dat_t<32> WB_VGA_Dev_vga__h_counter;
  dat_t<32> T21;
  dat_t<32> WB_VGA_Dev_vga__v_counter;
  dat_t<32> WB_VGA_Dev_vga__io_ctrl_x;
  dat_t<32> WB_VGA_Dev_vga__io_ctrl_y;
  dat_t<32> WB_VGA_Dev__io_bus_dat2;
  dat_t<32> WB_VGA_Dev__io_bus_addr;
  dat_t<32> WB_VGA_Dev__io_bus_dat4;
  dat_t<80> T141;
  mem_t<16,2400> WB_VGA_Dev__vmem;
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

class WB_VGA_Dev_api_t : public mod_api_t {
  void init_mapping_table();
};



#endif
