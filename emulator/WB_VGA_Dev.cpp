#include "WB_VGA_Dev.h"

void WB_VGA_Dev_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  WB_VGA_Dev_vga__p_counter.randomize(&__rand_seed);
  WB_VGA_Dev_vga__h_counter.randomize(&__rand_seed);
  WB_VGA_Dev_vga__v_counter.randomize(&__rand_seed);
  WB_VGA_Dev__vmem.randomize(&__rand_seed);
}


int WB_VGA_Dev_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* WB_VGA_Dev_t::clone() {
  mod_t* cloned = new WB_VGA_Dev_t(*this);
  return cloned;
}


bool WB_VGA_Dev_t::set_circuit_from ( mod_t* src ) {
  WB_VGA_Dev_t* mod_typed = dynamic_cast<WB_VGA_Dev_t*>(src);
  assert(mod_typed);
  WB_VGA_Dev_vga__reset = mod_typed->WB_VGA_Dev_vga__reset;
  T4 = mod_typed->T4;
  WB_VGA_Dev_vga__p_counter = mod_typed->WB_VGA_Dev_vga__p_counter;
  T13 = mod_typed->T13;
  WB_VGA_Dev_vga__h_counter = mod_typed->WB_VGA_Dev_vga__h_counter;
  T21 = mod_typed->T21;
  WB_VGA_Dev_vga__v_counter = mod_typed->WB_VGA_Dev_vga__v_counter;
  WB_VGA_Dev_vga__io_ctrl_x = mod_typed->WB_VGA_Dev_vga__io_ctrl_x;
  WB_VGA_Dev_vga__io_ctrl_y = mod_typed->WB_VGA_Dev_vga__io_ctrl_y;
  WB_VGA_Dev_font__io_addr = mod_typed->WB_VGA_Dev_font__io_addr;
  WB_VGA_Dev_font__io_data = mod_typed->WB_VGA_Dev_font__io_data;
  WB_VGA_Dev_vga__io_ctrl_color = mod_typed->WB_VGA_Dev_vga__io_ctrl_color;
  WB_VGA_Dev_vga__io_vga_red = mod_typed->WB_VGA_Dev_vga__io_vga_red;
  WB_VGA_Dev__io_vga_red = mod_typed->WB_VGA_Dev__io_vga_red;
  WB_VGA_Dev_vga__io_vga_green = mod_typed->WB_VGA_Dev_vga__io_vga_green;
  WB_VGA_Dev__io_vga_green = mod_typed->WB_VGA_Dev__io_vga_green;
  WB_VGA_Dev_vga__io_vga_blue = mod_typed->WB_VGA_Dev_vga__io_vga_blue;
  WB_VGA_Dev__io_vga_blue = mod_typed->WB_VGA_Dev__io_vga_blue;
  WB_VGA_Dev_vga__io_vga_hsync = mod_typed->WB_VGA_Dev_vga__io_vga_hsync;
  WB_VGA_Dev__io_vga_hsync = mod_typed->WB_VGA_Dev__io_vga_hsync;
  WB_VGA_Dev_vga__io_vga_vsync = mod_typed->WB_VGA_Dev_vga__io_vga_vsync;
  WB_VGA_Dev__io_vga_vsync = mod_typed->WB_VGA_Dev__io_vga_vsync;
  WB_VGA_Dev__io_bus_dat2 = mod_typed->WB_VGA_Dev__io_bus_dat2;
  T130 = mod_typed->T130;
  WB_VGA_Dev__io_bus_addr = mod_typed->WB_VGA_Dev__io_bus_addr;
  T131 = mod_typed->T131;
  WB_VGA_Dev__io_bus_we = mod_typed->WB_VGA_Dev__io_bus_we;
  WB_VGA_Dev__io_bus_sel = mod_typed->WB_VGA_Dev__io_bus_sel;
  T135 = mod_typed->T135;
  WB_VGA_Dev__vmem = mod_typed->WB_VGA_Dev__vmem;
  WB_VGA_Dev__io_bus_dat4 = mod_typed->WB_VGA_Dev__io_bus_dat4;
  WB_VGA_Dev__io_bus_ack = mod_typed->WB_VGA_Dev__io_bus_ack;
  WB_VGA_Dev_font__reset = mod_typed->WB_VGA_Dev_font__reset;
  T139 = mod_typed->T139;
  T140 = mod_typed->T140;
  T141 = mod_typed->T141;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void WB_VGA_Dev_t::print ( FILE* f ) {
#if __cplusplus >= 201103L
  if (T139.values[0]) dat_fprintf<80>(f, "addr %d\n", T140);
#endif
fflush(f);
}
void WB_VGA_Dev_t::print ( std::ostream& s ) {
#if __cplusplus >= 201103L
  if (T139.values[0]) dat_prints<80>(s, "addr %d\n", T140);
#endif
s.flush();
}


void WB_VGA_Dev_t::dump_init ( FILE* f ) {
}


void WB_VGA_Dev_t::dump ( FILE* f, int t ) {
}




void WB_VGA_Dev_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = WB_VGA_Dev_vga__p_counter.values[0]+0x1L;}
  T0 = T0 & 0x3L;
  val_t T1;
  T1 = WB_VGA_Dev_vga__p_counter.values[0] == 0x3L;
  val_t T2;
  { T2 = T1 ^ 0x1L;}
  val_t T3;
  { T3 = TERNARY(T2, T0, 0x0L);}
  { WB_VGA_Dev_vga__reset.values[0] = reset.values[0];}
  { T4.values[0] = TERNARY(WB_VGA_Dev_vga__reset.values[0], 0x0L, T3);}
  val_t T5;
  T5 = WB_VGA_Dev_vga__h_counter.values[0] == 0x31fL;
  val_t T6;
  T6 = WB_VGA_Dev_vga__p_counter.values[0] == 0x0L;
  val_t T7;
  { T7 = T6 & T5;}
  val_t T8;
  { T8 = TERNARY(T7, 0x0L, WB_VGA_Dev_vga__h_counter.values[0]);}
  val_t T9;
  { T9 = WB_VGA_Dev_vga__h_counter.values[0]+0x1L;}
  T9 = T9 & 0xffffffffL;
  val_t T10;
  { T10 = T5 ^ 0x1L;}
  val_t T11;
  { T11 = T6 & T10;}
  val_t T12;
  { T12 = TERNARY_1(T11, T9, T8);}
  { T13.values[0] = TERNARY(WB_VGA_Dev_vga__reset.values[0], 0x0L, T12);}
  val_t T14;
  T14 = WB_VGA_Dev_vga__v_counter.values[0] == 0x208L;
  val_t T15;
  { T15 = T7 & T14;}
  val_t T16;
  { T16 = TERNARY(T15, 0x0L, WB_VGA_Dev_vga__v_counter.values[0]);}
  val_t T17;
  { T17 = WB_VGA_Dev_vga__v_counter.values[0]+0x1L;}
  T17 = T17 & 0xffffffffL;
  val_t T18;
  { T18 = T14 ^ 0x1L;}
  val_t T19;
  { T19 = T7 & T18;}
  val_t T20;
  { T20 = TERNARY_1(T19, T17, T16);}
  { T21.values[0] = TERNARY(WB_VGA_Dev_vga__reset.values[0], 0x0L, T20);}
  val_t T22;
  { T22 = WB_VGA_Dev_vga__h_counter.values[0]-0x90L;}
  T22 = T22 & 0xffffffffL;
  val_t T23;
  T23 = WB_VGA_Dev_vga__h_counter.values[0]<0x320L;
  val_t T24;
  T24 = 0x310L<=WB_VGA_Dev_vga__h_counter.values[0];
  val_t T25;
  { T25 = T24 & T23;}
  val_t T26;
  { T26 = TERNARY(T25, 0x3L, 0x0L);}
  val_t T27;
  T27 = WB_VGA_Dev_vga__h_counter.values[0]<0x310L;
  val_t T28;
  T28 = 0x90L<=WB_VGA_Dev_vga__h_counter.values[0];
  val_t T29;
  { T29 = T28 & T27;}
  val_t T30;
  { T30 = TERNARY(T29, 0x2L, T26);}
  val_t T31;
  T31 = WB_VGA_Dev_vga__h_counter.values[0]<0x90L;
  val_t T32;
  T32 = 0x60L<=WB_VGA_Dev_vga__h_counter.values[0];
  val_t T33;
  { T33 = T32 & T31;}
  val_t T34;
  { T34 = TERNARY(T33, 0x1L, T30);}
  val_t T35;
  T35 = WB_VGA_Dev_vga__h_counter.values[0]<0x60L;
  val_t T36;
  T36 = 0x0L<=WB_VGA_Dev_vga__h_counter.values[0];
  val_t T37;
  { T37 = T36 & T35;}
  val_t WB_VGA_Dev_vga__h_state;
  { WB_VGA_Dev_vga__h_state = TERNARY(T37, 0x0L, T34);}
  val_t T38;
  T38 = WB_VGA_Dev_vga__h_state == 0x2L;
  val_t T39;
  { T39 = TERNARY(T38, T22, 0x0L);}
  { WB_VGA_Dev_vga__io_ctrl_x.values[0] = T39;}
  val_t T40;
  { T40 = WB_VGA_Dev_vga__io_ctrl_x.values[0];}
  T40 = T40 & 0x7L;
  val_t T41;
  { T41 = T40-T40;}
  T41 = T41 & 0x7L;
  val_t T42;
  { T42 = T41+0x1L;}
  T42 = T42 & 0x7L;
  val_t T43;
  T43 = 0x1L << T42;
  T43 = T43 & 0x1L;
  val_t T44;
  { T44 = T43-0x1L;}
  T44 = T44 & 0x1L;
  val_t T45;
  { T45 = WB_VGA_Dev_vga__v_counter.values[0]-0x1fL;}
  T45 = T45 & 0xffffffffL;
  val_t T46;
  T46 = WB_VGA_Dev_vga__v_counter.values[0]<0x209L;
  val_t T47;
  T47 = 0x1ffL<=WB_VGA_Dev_vga__v_counter.values[0];
  val_t T48;
  { T48 = T47 & T46;}
  val_t T49;
  { T49 = TERNARY(T48, 0x3L, 0x0L);}
  val_t T50;
  T50 = WB_VGA_Dev_vga__v_counter.values[0]<0x1ffL;
  val_t T51;
  T51 = 0x1fL<=WB_VGA_Dev_vga__v_counter.values[0];
  val_t T52;
  { T52 = T51 & T50;}
  val_t T53;
  { T53 = TERNARY(T52, 0x2L, T49);}
  val_t T54;
  T54 = WB_VGA_Dev_vga__v_counter.values[0]<0x1fL;
  val_t T55;
  T55 = 0x2L<=WB_VGA_Dev_vga__v_counter.values[0];
  val_t T56;
  { T56 = T55 & T54;}
  val_t T57;
  { T57 = TERNARY(T56, 0x1L, T53);}
  val_t T58;
  T58 = WB_VGA_Dev_vga__v_counter.values[0]<0x2L;
  val_t T59;
  T59 = 0x0L<=WB_VGA_Dev_vga__v_counter.values[0];
  val_t T60;
  { T60 = T59 & T58;}
  val_t WB_VGA_Dev_vga__v_state;
  { WB_VGA_Dev_vga__v_state = TERNARY(T60, 0x0L, T57);}
  val_t T61;
  T61 = WB_VGA_Dev_vga__v_state == 0x2L;
  val_t T62;
  { T62 = TERNARY(T61, T45, 0x0L);}
  { WB_VGA_Dev_vga__io_ctrl_y.values[0] = T62;}
  val_t T63;
  { T63 = WB_VGA_Dev_vga__io_ctrl_y.values[0];}
  T63 = T63 & 0xfL;
  val_t T64;
  { T64 = T63 | 0x0L << 4;}
  val_t T65;
  T65 = 0x41L * 0x10L;
  val_t T66;
  { T66 = T65+T64;}
  T66 = T66 & 0x1fffL;
  val_t T67;
  { T67 = T66;}
  T67 = T67 & 0xfffL;
  { WB_VGA_Dev_font__io_addr.values[0] = T67;}
  val_t T68;
  T68 = WB_VGA_Dev_font__io_addr.values[0] == 0xbL;
  val_t T69;
  { T69 = TERNARY(T68, 0xc6L, 0x0L);}
  val_t T70;
  T70 = WB_VGA_Dev_font__io_addr.values[0] == 0xaL;
  val_t T71;
  { T71 = TERNARY(T70, 0xc6L, T69);}
  val_t T72;
  T72 = WB_VGA_Dev_font__io_addr.values[0] == 0x9L;
  val_t T73;
  { T73 = TERNARY(T72, 0xc6L, T71);}
  val_t T74;
  T74 = WB_VGA_Dev_font__io_addr.values[0] == 0x8L;
  val_t T75;
  { T75 = TERNARY(T74, 0xc6L, T73);}
  val_t T76;
  T76 = WB_VGA_Dev_font__io_addr.values[0] == 0x7L;
  val_t T77;
  { T77 = TERNARY(T76, 0xc6L, T75);}
  val_t T78;
  T78 = WB_VGA_Dev_font__io_addr.values[0] == 0x6L;
  val_t T79;
  { T79 = TERNARY(T78, 0xfeL, T77);}
  val_t T80;
  T80 = WB_VGA_Dev_font__io_addr.values[0] == 0x5L;
  val_t T81;
  { T81 = TERNARY(T80, 0xc6L, T79);}
  val_t T82;
  T82 = WB_VGA_Dev_font__io_addr.values[0] == 0x4L;
  val_t T83;
  { T83 = TERNARY(T82, 0xc6L, T81);}
  val_t T84;
  T84 = WB_VGA_Dev_font__io_addr.values[0] == 0x3L;
  val_t T85;
  { T85 = TERNARY(T84, 0xc6L, T83);}
  val_t T86;
  T86 = WB_VGA_Dev_font__io_addr.values[0] == 0x2L;
  val_t T87;
  { T87 = TERNARY(T86, 0xc6L, T85);}
  val_t T88;
  T88 = WB_VGA_Dev_font__io_addr.values[0] == 0x1L;
  val_t T89;
  { T89 = TERNARY(T88, 0x55L, T87);}
  val_t T90;
  T90 = WB_VGA_Dev_font__io_addr.values[0] == 0x0L;
  val_t T91;
  { T91 = TERNARY(T90, 0xaaL, T89);}
  { WB_VGA_Dev_font__io_data.values[0] = T91;}
  val_t T92;
  T92 = WB_VGA_Dev_font__io_data.values[0] >> T40;
  val_t T93;
  { T93 = T92 & T44;}
  val_t T94;
  T94 = T93 == 0x1L;
  val_t T95;
  { T95 = TERNARY(T94, 0xffL, 0x0L);}
  val_t T96;
  { T96 = WB_VGA_Dev_vga__io_ctrl_x.values[0];}
  T96 = T96 & 0x7L;
  val_t T97;
  { T97 = T96-T96;}
  T97 = T97 & 0x7L;
  val_t T98;
  { T98 = T97+0x1L;}
  T98 = T98 & 0x7L;
  val_t T99;
  T99 = 0x1L << T98;
  T99 = T99 & 0x1L;
  val_t T100;
  { T100 = T99-0x1L;}
  T100 = T100 & 0x1L;
  val_t T101;
  T101 = WB_VGA_Dev_font__io_data.values[0] >> T96;
  val_t T102;
  { T102 = T101 & T100;}
  val_t T103;
  T103 = T102 == 0x0L;
  val_t T104;
  { T104 = TERNARY(T103, 0x0L, T95);}
  { WB_VGA_Dev_vga__io_ctrl_color.values[0] = T104;}
  val_t T105;
  { T105 = WB_VGA_Dev_vga__io_ctrl_color.values[0] >> 5;}
  T105 = T105 & 0x7L;
  val_t T106;
  T106 = WB_VGA_Dev_vga__v_state == 0x2L;
  val_t T107;
  T107 = WB_VGA_Dev_vga__h_state == 0x2L;
  val_t WB_VGA_Dev_vga__output_en;
  { WB_VGA_Dev_vga__output_en = T107 & T106;}
  val_t T108;
  T108 = WB_VGA_Dev_vga__output_en == 0x1L;
  val_t T109;
  { T109 = TERNARY(T108, T105, 0x0L);}
  { WB_VGA_Dev_vga__io_vga_red.values[0] = T109;}
  { WB_VGA_Dev__io_vga_red.values[0] = WB_VGA_Dev_vga__io_vga_red.values[0];}
  val_t T110;
  { T110 = WB_VGA_Dev_vga__io_ctrl_color.values[0] >> 2;}
  T110 = T110 & 0x7L;
  val_t T111;
  T111 = WB_VGA_Dev_vga__output_en == 0x1L;
  val_t T112;
  { T112 = TERNARY(T111, T110, 0x0L);}
  { WB_VGA_Dev_vga__io_vga_green.values[0] = T112;}
  { WB_VGA_Dev__io_vga_green.values[0] = WB_VGA_Dev_vga__io_vga_green.values[0];}
  val_t T113;
  { T113 = WB_VGA_Dev_vga__io_ctrl_color.values[0];}
  T113 = T113 & 0x3L;
  val_t T114;
  T114 = WB_VGA_Dev_vga__output_en == 0x1L;
  val_t T115;
  { T115 = TERNARY(T114, T113, 0x0L);}
  { WB_VGA_Dev_vga__io_vga_blue.values[0] = T115;}
  { WB_VGA_Dev__io_vga_blue.values[0] = WB_VGA_Dev_vga__io_vga_blue.values[0];}
  val_t T116;
  T116 = WB_VGA_Dev_vga__h_state == 0x3L;
  val_t T117;
  T117 = WB_VGA_Dev_vga__h_state == 0x2L;
  val_t T118;
  { T118 = TERNARY(T117, 0x1L, T116);}
  val_t T119;
  T119 = WB_VGA_Dev_vga__h_state == 0x1L;
  val_t T120;
  { T120 = TERNARY(T119, 0x1L, T118);}
  val_t T121;
  T121 = WB_VGA_Dev_vga__h_state == 0x0L;
  val_t T122;
  { T122 = TERNARY(T121, 0x0L, T120);}
  { WB_VGA_Dev_vga__io_vga_hsync.values[0] = T122;}
  { WB_VGA_Dev__io_vga_hsync.values[0] = WB_VGA_Dev_vga__io_vga_hsync.values[0];}
  val_t T123;
  T123 = WB_VGA_Dev_vga__v_state == 0x3L;
  val_t T124;
  T124 = WB_VGA_Dev_vga__v_state == 0x2L;
  val_t T125;
  { T125 = TERNARY(T124, 0x1L, T123);}
  val_t T126;
  T126 = WB_VGA_Dev_vga__v_state == 0x1L;
  val_t T127;
  { T127 = TERNARY(T126, 0x1L, T125);}
  val_t T128;
  T128 = WB_VGA_Dev_vga__v_state == 0x0L;
  val_t T129;
  { T129 = TERNARY(T128, 0x0L, T127);}
  { WB_VGA_Dev_vga__io_vga_vsync.values[0] = T129;}
  { WB_VGA_Dev__io_vga_vsync.values[0] = WB_VGA_Dev_vga__io_vga_vsync.values[0];}
  { T130.values[0] = WB_VGA_Dev__io_bus_dat2.values[0];}
  T130.values[0] = T130.values[0] & 0xffffL;
  { T131.values[0] = WB_VGA_Dev__io_bus_addr.values[0];}
  T131.values[0] = T131.values[0] & 0xfffL;
  val_t T132;
  { T132 = T131.values[0];}
  T132 = T132 & 0xfffL;
  val_t T133;
  T133 = T132<0x960L;
  val_t T134;
  { T134 = WB_VGA_Dev__io_bus_sel.values[0] & WB_VGA_Dev__io_bus_we.values[0];}
  { T135.values[0] = T134 & T133;}
  val_t T136;
  { T136 = WB_VGA_Dev__io_bus_addr.values[0];}
  T136 = T136 & 0xfffL;
  val_t T137;
  { T137 = WB_VGA_Dev__vmem.get(T136, 0);}
  val_t T138;
  { T138 = T137 | 0x0L << 16;}
  { WB_VGA_Dev__io_bus_dat4.values[0] = T138;}
  { WB_VGA_Dev__io_bus_ack.values[0] = 0x1L;}
  { WB_VGA_Dev_font__reset.values[0] = reset.values[0];}
  { T139.values[0] = WB_VGA_Dev_font__reset.values[0] ^ 0x1L;}
  { T140.values[0] = WB_VGA_Dev_font__io_addr.values[0];}
}


void WB_VGA_Dev_t::clock_hi ( dat_t<1> reset ) {
  dat_t<2> WB_VGA_Dev_vga__p_counter__shadow = T4;
  dat_t<32> WB_VGA_Dev_vga__h_counter__shadow = T13;
  dat_t<32> WB_VGA_Dev_vga__v_counter__shadow = T21;
  { if (T135.values[0]) WB_VGA_Dev__vmem.put(T131.values[0], 0, T130.values[0]);}
  WB_VGA_Dev_vga__p_counter = T4;
  WB_VGA_Dev_vga__h_counter = T13;
  WB_VGA_Dev_vga__v_counter = T21;
}


void WB_VGA_Dev_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  WB_VGA_Dev_t* mod_typed = dynamic_cast<WB_VGA_Dev_t*>(module);
  assert(mod_typed);
  dat_table["WB_VGA_Dev.vga.p_counter"] = new dat_api<2>(&mod_typed->WB_VGA_Dev_vga__p_counter, "WB_VGA_Dev.vga.p_counter", "");
  dat_table["WB_VGA_Dev.vga.h_counter"] = new dat_api<32>(&mod_typed->WB_VGA_Dev_vga__h_counter, "WB_VGA_Dev.vga.h_counter", "");
  dat_table["WB_VGA_Dev.vga.v_counter"] = new dat_api<32>(&mod_typed->WB_VGA_Dev_vga__v_counter, "WB_VGA_Dev.vga.v_counter", "");
  dat_table["WB_VGA_Dev.vga.io_ctrl_x"] = new dat_api<32>(&mod_typed->WB_VGA_Dev_vga__io_ctrl_x, "WB_VGA_Dev.vga.io_ctrl_x", "");
  dat_table["WB_VGA_Dev.vga.io_ctrl_y"] = new dat_api<32>(&mod_typed->WB_VGA_Dev_vga__io_ctrl_y, "WB_VGA_Dev.vga.io_ctrl_y", "");
  dat_table["WB_VGA_Dev.font.io_addr"] = new dat_api<12>(&mod_typed->WB_VGA_Dev_font__io_addr, "WB_VGA_Dev.font.io_addr", "");
  dat_table["WB_VGA_Dev.font.io_data"] = new dat_api<8>(&mod_typed->WB_VGA_Dev_font__io_data, "WB_VGA_Dev.font.io_data", "");
  dat_table["WB_VGA_Dev.vga.io_ctrl_color"] = new dat_api<8>(&mod_typed->WB_VGA_Dev_vga__io_ctrl_color, "WB_VGA_Dev.vga.io_ctrl_color", "");
  dat_table["WB_VGA_Dev.vga.io_vga_red"] = new dat_api<3>(&mod_typed->WB_VGA_Dev_vga__io_vga_red, "WB_VGA_Dev.vga.io_vga_red", "");
  dat_table["WB_VGA_Dev.io_vga_red"] = new dat_api<3>(&mod_typed->WB_VGA_Dev__io_vga_red, "WB_VGA_Dev.io_vga_red", "");
  dat_table["WB_VGA_Dev.vga.io_vga_green"] = new dat_api<3>(&mod_typed->WB_VGA_Dev_vga__io_vga_green, "WB_VGA_Dev.vga.io_vga_green", "");
  dat_table["WB_VGA_Dev.io_vga_green"] = new dat_api<3>(&mod_typed->WB_VGA_Dev__io_vga_green, "WB_VGA_Dev.io_vga_green", "");
  dat_table["WB_VGA_Dev.vga.io_vga_blue"] = new dat_api<2>(&mod_typed->WB_VGA_Dev_vga__io_vga_blue, "WB_VGA_Dev.vga.io_vga_blue", "");
  dat_table["WB_VGA_Dev.io_vga_blue"] = new dat_api<2>(&mod_typed->WB_VGA_Dev__io_vga_blue, "WB_VGA_Dev.io_vga_blue", "");
  dat_table["WB_VGA_Dev.vga.io_vga_hsync"] = new dat_api<1>(&mod_typed->WB_VGA_Dev_vga__io_vga_hsync, "WB_VGA_Dev.vga.io_vga_hsync", "");
  dat_table["WB_VGA_Dev.io_vga_hsync"] = new dat_api<1>(&mod_typed->WB_VGA_Dev__io_vga_hsync, "WB_VGA_Dev.io_vga_hsync", "");
  dat_table["WB_VGA_Dev.vga.io_vga_vsync"] = new dat_api<1>(&mod_typed->WB_VGA_Dev_vga__io_vga_vsync, "WB_VGA_Dev.vga.io_vga_vsync", "");
  dat_table["WB_VGA_Dev.io_vga_vsync"] = new dat_api<1>(&mod_typed->WB_VGA_Dev__io_vga_vsync, "WB_VGA_Dev.io_vga_vsync", "");
  dat_table["WB_VGA_Dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->WB_VGA_Dev__io_bus_dat2, "WB_VGA_Dev.io_bus_dat2", "");
  dat_table["WB_VGA_Dev.io_bus_addr"] = new dat_api<32>(&mod_typed->WB_VGA_Dev__io_bus_addr, "WB_VGA_Dev.io_bus_addr", "");
  dat_table["WB_VGA_Dev.io_bus_we"] = new dat_api<1>(&mod_typed->WB_VGA_Dev__io_bus_we, "WB_VGA_Dev.io_bus_we", "");
  dat_table["WB_VGA_Dev.io_bus_sel"] = new dat_api<1>(&mod_typed->WB_VGA_Dev__io_bus_sel, "WB_VGA_Dev.io_bus_sel", "");
  mem_table["WB_VGA_Dev.vmem"] = new mem_api<16, 2400>(&mod_typed->WB_VGA_Dev__vmem, "WB_VGA_Dev.vmem", "");
  dat_table["WB_VGA_Dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->WB_VGA_Dev__io_bus_dat4, "WB_VGA_Dev.io_bus_dat4", "");
  dat_table["WB_VGA_Dev.io_bus_ack"] = new dat_api<1>(&mod_typed->WB_VGA_Dev__io_bus_ack, "WB_VGA_Dev.io_bus_ack", "");
}
