#include "WB_Bus.h"

void WB_Bus_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  WB_Bus__slave_sel_7.randomize(&__rand_seed);
  WB_Bus__slave_we_7.randomize(&__rand_seed);
  WB_Bus__slave_sel_6.randomize(&__rand_seed);
  WB_Bus__slave_we_6.randomize(&__rand_seed);
  WB_Bus__slave_sel_5.randomize(&__rand_seed);
  WB_Bus__slave_we_5.randomize(&__rand_seed);
  WB_Bus__slave_sel_4.randomize(&__rand_seed);
  WB_Bus__slave_we_4.randomize(&__rand_seed);
  WB_Bus__slave_sel_3.randomize(&__rand_seed);
  WB_Bus__slave_we_3.randomize(&__rand_seed);
  WB_Bus__slave_sel_2.randomize(&__rand_seed);
  WB_Bus__slave_we_2.randomize(&__rand_seed);
  WB_Bus__slave_sel_1.randomize(&__rand_seed);
  WB_Bus__slave_we_1.randomize(&__rand_seed);
  WB_Bus__slave_sel_0.randomize(&__rand_seed);
  WB_Bus__slave_we_0.randomize(&__rand_seed);
  WB_Bus__ack_out.randomize(&__rand_seed);
}


int WB_Bus_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* WB_Bus_t::clone() {
  mod_t* cloned = new WB_Bus_t(*this);
  return cloned;
}


bool WB_Bus_t::set_circuit_from ( mod_t* src ) {
  WB_Bus_t* mod_typed = dynamic_cast<WB_Bus_t*>(src);
  assert(mod_typed);
  WB_Bus__io_ram_slave_dat4 = mod_typed->WB_Bus__io_ram_slave_dat4;
  WB_Bus__io_from_cpu_addr = mod_typed->WB_Bus__io_from_cpu_addr;
  WB_Bus__io_slaves_7_dat4 = mod_typed->WB_Bus__io_slaves_7_dat4;
  WB_Bus__io_slaves_6_dat4 = mod_typed->WB_Bus__io_slaves_6_dat4;
  WB_Bus__io_slaves_5_dat4 = mod_typed->WB_Bus__io_slaves_5_dat4;
  WB_Bus__io_slaves_4_dat4 = mod_typed->WB_Bus__io_slaves_4_dat4;
  WB_Bus__io_slaves_3_dat4 = mod_typed->WB_Bus__io_slaves_3_dat4;
  WB_Bus__io_slaves_2_dat4 = mod_typed->WB_Bus__io_slaves_2_dat4;
  WB_Bus__io_slaves_1_dat4 = mod_typed->WB_Bus__io_slaves_1_dat4;
  WB_Bus__io_slaves_0_dat4 = mod_typed->WB_Bus__io_slaves_0_dat4;
  WB_Bus__io_from_cpu_dat4 = mod_typed->WB_Bus__io_from_cpu_dat4;
  WB_Bus__io_ram_slave_ack = mod_typed->WB_Bus__io_ram_slave_ack;
  WB_Bus__io_slaves_7_ack = mod_typed->WB_Bus__io_slaves_7_ack;
  WB_Bus__io_slaves_6_ack = mod_typed->WB_Bus__io_slaves_6_ack;
  WB_Bus__io_slaves_5_ack = mod_typed->WB_Bus__io_slaves_5_ack;
  WB_Bus__io_slaves_4_ack = mod_typed->WB_Bus__io_slaves_4_ack;
  WB_Bus__io_slaves_3_ack = mod_typed->WB_Bus__io_slaves_3_ack;
  WB_Bus__io_slaves_2_ack = mod_typed->WB_Bus__io_slaves_2_ack;
  WB_Bus__io_slaves_1_ack = mod_typed->WB_Bus__io_slaves_1_ack;
  WB_Bus__io_slaves_0_ack = mod_typed->WB_Bus__io_slaves_0_ack;
  WB_Bus__io_from_cpu_ack = mod_typed->WB_Bus__io_from_cpu_ack;
  WB_Bus__io_slaves_7_addr = mod_typed->WB_Bus__io_slaves_7_addr;
  WB_Bus__io_from_cpu_dat2 = mod_typed->WB_Bus__io_from_cpu_dat2;
  WB_Bus__io_slaves_7_dat2 = mod_typed->WB_Bus__io_slaves_7_dat2;
  WB_Bus__io_from_cpu_sel = mod_typed->WB_Bus__io_from_cpu_sel;
  T51 = mod_typed->T51;
  WB_Bus__slave_sel_7 = mod_typed->WB_Bus__slave_sel_7;
  WB_Bus__io_slaves_7_sel = mod_typed->WB_Bus__io_slaves_7_sel;
  WB_Bus__io_from_cpu_we = mod_typed->WB_Bus__io_from_cpu_we;
  T57 = mod_typed->T57;
  WB_Bus__slave_we_7 = mod_typed->WB_Bus__slave_we_7;
  WB_Bus__io_slaves_7_we = mod_typed->WB_Bus__io_slaves_7_we;
  WB_Bus__io_slaves_6_addr = mod_typed->WB_Bus__io_slaves_6_addr;
  WB_Bus__io_slaves_6_dat2 = mod_typed->WB_Bus__io_slaves_6_dat2;
  T64 = mod_typed->T64;
  WB_Bus__slave_sel_6 = mod_typed->WB_Bus__slave_sel_6;
  WB_Bus__io_slaves_6_sel = mod_typed->WB_Bus__io_slaves_6_sel;
  T69 = mod_typed->T69;
  WB_Bus__slave_we_6 = mod_typed->WB_Bus__slave_we_6;
  WB_Bus__io_slaves_6_we = mod_typed->WB_Bus__io_slaves_6_we;
  WB_Bus__io_slaves_5_addr = mod_typed->WB_Bus__io_slaves_5_addr;
  WB_Bus__io_slaves_5_dat2 = mod_typed->WB_Bus__io_slaves_5_dat2;
  T76 = mod_typed->T76;
  WB_Bus__slave_sel_5 = mod_typed->WB_Bus__slave_sel_5;
  WB_Bus__io_slaves_5_sel = mod_typed->WB_Bus__io_slaves_5_sel;
  T81 = mod_typed->T81;
  WB_Bus__slave_we_5 = mod_typed->WB_Bus__slave_we_5;
  WB_Bus__io_slaves_5_we = mod_typed->WB_Bus__io_slaves_5_we;
  WB_Bus__io_slaves_4_addr = mod_typed->WB_Bus__io_slaves_4_addr;
  WB_Bus__io_slaves_4_dat2 = mod_typed->WB_Bus__io_slaves_4_dat2;
  T88 = mod_typed->T88;
  WB_Bus__slave_sel_4 = mod_typed->WB_Bus__slave_sel_4;
  WB_Bus__io_slaves_4_sel = mod_typed->WB_Bus__io_slaves_4_sel;
  T93 = mod_typed->T93;
  WB_Bus__slave_we_4 = mod_typed->WB_Bus__slave_we_4;
  WB_Bus__io_slaves_4_we = mod_typed->WB_Bus__io_slaves_4_we;
  WB_Bus__io_slaves_3_addr = mod_typed->WB_Bus__io_slaves_3_addr;
  WB_Bus__io_slaves_3_dat2 = mod_typed->WB_Bus__io_slaves_3_dat2;
  T100 = mod_typed->T100;
  WB_Bus__slave_sel_3 = mod_typed->WB_Bus__slave_sel_3;
  WB_Bus__io_slaves_3_sel = mod_typed->WB_Bus__io_slaves_3_sel;
  T105 = mod_typed->T105;
  WB_Bus__slave_we_3 = mod_typed->WB_Bus__slave_we_3;
  WB_Bus__io_slaves_3_we = mod_typed->WB_Bus__io_slaves_3_we;
  WB_Bus__io_slaves_2_addr = mod_typed->WB_Bus__io_slaves_2_addr;
  WB_Bus__io_slaves_2_dat2 = mod_typed->WB_Bus__io_slaves_2_dat2;
  T112 = mod_typed->T112;
  WB_Bus__slave_sel_2 = mod_typed->WB_Bus__slave_sel_2;
  WB_Bus__io_slaves_2_sel = mod_typed->WB_Bus__io_slaves_2_sel;
  T117 = mod_typed->T117;
  WB_Bus__slave_we_2 = mod_typed->WB_Bus__slave_we_2;
  WB_Bus__io_slaves_2_we = mod_typed->WB_Bus__io_slaves_2_we;
  WB_Bus__io_slaves_1_addr = mod_typed->WB_Bus__io_slaves_1_addr;
  WB_Bus__io_slaves_1_dat2 = mod_typed->WB_Bus__io_slaves_1_dat2;
  T124 = mod_typed->T124;
  WB_Bus__slave_sel_1 = mod_typed->WB_Bus__slave_sel_1;
  WB_Bus__io_slaves_1_sel = mod_typed->WB_Bus__io_slaves_1_sel;
  T129 = mod_typed->T129;
  WB_Bus__slave_we_1 = mod_typed->WB_Bus__slave_we_1;
  WB_Bus__io_slaves_1_we = mod_typed->WB_Bus__io_slaves_1_we;
  WB_Bus__io_slaves_0_addr = mod_typed->WB_Bus__io_slaves_0_addr;
  WB_Bus__io_slaves_0_dat2 = mod_typed->WB_Bus__io_slaves_0_dat2;
  T136 = mod_typed->T136;
  WB_Bus__slave_sel_0 = mod_typed->WB_Bus__slave_sel_0;
  WB_Bus__io_slaves_0_sel = mod_typed->WB_Bus__io_slaves_0_sel;
  T141 = mod_typed->T141;
  WB_Bus__slave_we_0 = mod_typed->WB_Bus__slave_we_0;
  WB_Bus__io_slaves_0_we = mod_typed->WB_Bus__io_slaves_0_we;
  WB_Bus__io_ram_slave_addr = mod_typed->WB_Bus__io_ram_slave_addr;
  WB_Bus__io_ram_slave_dat2 = mod_typed->WB_Bus__io_ram_slave_dat2;
  WB_Bus__io_ram_slave_sel = mod_typed->WB_Bus__io_ram_slave_sel;
  T145 = mod_typed->T145;
  WB_Bus__ack_out = mod_typed->WB_Bus__ack_out;
  WB_Bus__io_ram_slave_we = mod_typed->WB_Bus__io_ram_slave_we;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void WB_Bus_t::print ( FILE* f ) {
}
void WB_Bus_t::print ( std::ostream& s ) {
}


void WB_Bus_t::dump_init ( FILE* f ) {
}


void WB_Bus_t::dump ( FILE* f, int t ) {
}




void WB_Bus_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  T0 = (WB_Bus__io_from_cpu_addr.values[0] >> 31) & 1;
  val_t WB_Bus__ram_op;
  { WB_Bus__ram_op = ~T0;}
  WB_Bus__ram_op = WB_Bus__ram_op & 0x1L;
  val_t T1;
  T1 = WB_Bus__ram_op == 0x1L;
  val_t T2;
  { T2 = TERNARY(T1, WB_Bus__io_ram_slave_dat4.values[0], 0x0L);}
  val_t WB_Bus__current_slave;
  { WB_Bus__current_slave = WB_Bus__io_from_cpu_addr.values[0] >> 28;}
  WB_Bus__current_slave = WB_Bus__current_slave & 0x7L;
  val_t T3;
  T3 = WB_Bus__current_slave == 0x7L;
  val_t T4;
  { T4 = TERNARY(T3, WB_Bus__io_slaves_7_dat4.values[0], 0x0L);}
  val_t T5;
  T5 = WB_Bus__current_slave == 0x6L;
  val_t T6;
  { T6 = TERNARY_1(T5, WB_Bus__io_slaves_6_dat4.values[0], T4);}
  val_t T7;
  T7 = WB_Bus__current_slave == 0x5L;
  val_t T8;
  { T8 = TERNARY_1(T7, WB_Bus__io_slaves_5_dat4.values[0], T6);}
  val_t T9;
  T9 = WB_Bus__current_slave == 0x4L;
  val_t T10;
  { T10 = TERNARY_1(T9, WB_Bus__io_slaves_4_dat4.values[0], T8);}
  val_t T11;
  T11 = WB_Bus__current_slave == 0x3L;
  val_t T12;
  { T12 = TERNARY_1(T11, WB_Bus__io_slaves_3_dat4.values[0], T10);}
  val_t T13;
  T13 = WB_Bus__current_slave == 0x2L;
  val_t T14;
  { T14 = TERNARY_1(T13, WB_Bus__io_slaves_2_dat4.values[0], T12);}
  val_t T15;
  T15 = WB_Bus__current_slave == 0x1L;
  val_t T16;
  { T16 = TERNARY_1(T15, WB_Bus__io_slaves_1_dat4.values[0], T14);}
  val_t T17;
  T17 = WB_Bus__current_slave == 0x0L;
  val_t T18;
  { T18 = TERNARY_1(T17, WB_Bus__io_slaves_0_dat4.values[0], T16);}
  val_t T19;
  T19 = WB_Bus__ram_op == 0x0L;
  val_t T20;
  { T20 = TERNARY_1(T19, T18, T2);}
  { WB_Bus__io_from_cpu_dat4.values[0] = T20;}
  val_t T21;
  T21 = WB_Bus__ram_op == 0x1L;
  val_t T22;
  { T22 = TERNARY(T21, WB_Bus__io_ram_slave_ack.values[0], 0x0L);}
  val_t T23;
  T23 = WB_Bus__current_slave == 0x7L;
  val_t T24;
  { T24 = TERNARY(T23, WB_Bus__io_slaves_7_ack.values[0], 0x0L);}
  val_t T25;
  T25 = WB_Bus__current_slave == 0x6L;
  val_t T26;
  { T26 = TERNARY_1(T25, WB_Bus__io_slaves_6_ack.values[0], T24);}
  val_t T27;
  T27 = WB_Bus__current_slave == 0x5L;
  val_t T28;
  { T28 = TERNARY_1(T27, WB_Bus__io_slaves_5_ack.values[0], T26);}
  val_t T29;
  T29 = WB_Bus__current_slave == 0x4L;
  val_t T30;
  { T30 = TERNARY_1(T29, WB_Bus__io_slaves_4_ack.values[0], T28);}
  val_t T31;
  T31 = WB_Bus__current_slave == 0x3L;
  val_t T32;
  { T32 = TERNARY_1(T31, WB_Bus__io_slaves_3_ack.values[0], T30);}
  val_t T33;
  T33 = WB_Bus__current_slave == 0x2L;
  val_t T34;
  { T34 = TERNARY_1(T33, WB_Bus__io_slaves_2_ack.values[0], T32);}
  val_t T35;
  T35 = WB_Bus__current_slave == 0x1L;
  val_t T36;
  { T36 = TERNARY_1(T35, WB_Bus__io_slaves_1_ack.values[0], T34);}
  val_t T37;
  T37 = WB_Bus__current_slave == 0x0L;
  val_t T38;
  { T38 = TERNARY_1(T37, WB_Bus__io_slaves_0_ack.values[0], T36);}
  val_t T39;
  T39 = WB_Bus__ram_op == 0x0L;
  val_t T40;
  { T40 = TERNARY_1(T39, T38, T22);}
  { WB_Bus__io_from_cpu_ack.values[0] = T40;}
  val_t T41;
  { T41 = WB_Bus__io_from_cpu_addr.values[0];}
  T41 = T41 & 0xfffffffL;
  val_t T42;
  { T42 = T41 | 0x0L << 28;}
  { WB_Bus__io_slaves_7_addr.values[0] = T42;}
  { WB_Bus__io_slaves_7_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T43;
  { T43 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_7.values[0]);}
  val_t T44;
  T44 = 0x1L << WB_Bus__current_slave;
  T44 = T44 & 0xffL;
  val_t T45;
  T45 = (T44 >> 7) & 1;
  val_t T46;
  { T46 = WB_Bus__ram_op ^ 0x1L;}
  val_t T47;
  { T47 = WB_Bus__ack_out.values[0] & WB_Bus__io_from_cpu_sel.values[0];}
  val_t T48;
  { T48 = T47 & T46;}
  val_t T49;
  { T49 = T48 & T45;}
  val_t T50;
  { T50 = TERNARY(T49, 0x1L, T43);}
  { T51.values[0] = TERNARY(reset.values[0], 0x0L, T50);}
  { WB_Bus__io_slaves_7_sel.values[0] = WB_Bus__slave_sel_7.values[0];}
  val_t T52;
  { T52 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_7.values[0]);}
  val_t T53;
  T53 = 0x1L << WB_Bus__current_slave;
  T53 = T53 & 0xffL;
  val_t T54;
  T54 = (T53 >> 7) & 1;
  val_t T55;
  { T55 = T48 & T54;}
  val_t T56;
  { T56 = TERNARY_1(T55, WB_Bus__io_from_cpu_we.values[0], T52);}
  { T57.values[0] = TERNARY(reset.values[0], 0x0L, T56);}
  { WB_Bus__io_slaves_7_we.values[0] = WB_Bus__slave_we_7.values[0];}
  val_t T58;
  { T58 = WB_Bus__io_from_cpu_addr.values[0];}
  T58 = T58 & 0xfffffffL;
  val_t T59;
  { T59 = T58 | 0x0L << 28;}
  { WB_Bus__io_slaves_6_addr.values[0] = T59;}
  { WB_Bus__io_slaves_6_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T60;
  { T60 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_6.values[0]);}
  val_t T61;
  T61 = (T44 >> 6) & 1;
  val_t T62;
  { T62 = T48 & T61;}
  val_t T63;
  { T63 = TERNARY(T62, 0x1L, T60);}
  { T64.values[0] = TERNARY(reset.values[0], 0x0L, T63);}
  { WB_Bus__io_slaves_6_sel.values[0] = WB_Bus__slave_sel_6.values[0];}
  val_t T65;
  { T65 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_6.values[0]);}
  val_t T66;
  T66 = (T53 >> 6) & 1;
  val_t T67;
  { T67 = T48 & T66;}
  val_t T68;
  { T68 = TERNARY_1(T67, WB_Bus__io_from_cpu_we.values[0], T65);}
  { T69.values[0] = TERNARY(reset.values[0], 0x0L, T68);}
  { WB_Bus__io_slaves_6_we.values[0] = WB_Bus__slave_we_6.values[0];}
  val_t T70;
  { T70 = WB_Bus__io_from_cpu_addr.values[0];}
  T70 = T70 & 0xfffffffL;
  val_t T71;
  { T71 = T70 | 0x0L << 28;}
  { WB_Bus__io_slaves_5_addr.values[0] = T71;}
  { WB_Bus__io_slaves_5_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T72;
  { T72 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_5.values[0]);}
  val_t T73;
  T73 = (T44 >> 5) & 1;
  val_t T74;
  { T74 = T48 & T73;}
  val_t T75;
  { T75 = TERNARY(T74, 0x1L, T72);}
  { T76.values[0] = TERNARY(reset.values[0], 0x0L, T75);}
  { WB_Bus__io_slaves_5_sel.values[0] = WB_Bus__slave_sel_5.values[0];}
  val_t T77;
  { T77 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_5.values[0]);}
  val_t T78;
  T78 = (T53 >> 5) & 1;
  val_t T79;
  { T79 = T48 & T78;}
  val_t T80;
  { T80 = TERNARY_1(T79, WB_Bus__io_from_cpu_we.values[0], T77);}
  { T81.values[0] = TERNARY(reset.values[0], 0x0L, T80);}
  { WB_Bus__io_slaves_5_we.values[0] = WB_Bus__slave_we_5.values[0];}
  val_t T82;
  { T82 = WB_Bus__io_from_cpu_addr.values[0];}
  T82 = T82 & 0xfffffffL;
  val_t T83;
  { T83 = T82 | 0x0L << 28;}
  { WB_Bus__io_slaves_4_addr.values[0] = T83;}
  { WB_Bus__io_slaves_4_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T84;
  { T84 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_4.values[0]);}
  val_t T85;
  T85 = (T44 >> 4) & 1;
  val_t T86;
  { T86 = T48 & T85;}
  val_t T87;
  { T87 = TERNARY(T86, 0x1L, T84);}
  { T88.values[0] = TERNARY(reset.values[0], 0x0L, T87);}
  { WB_Bus__io_slaves_4_sel.values[0] = WB_Bus__slave_sel_4.values[0];}
  val_t T89;
  { T89 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_4.values[0]);}
  val_t T90;
  T90 = (T53 >> 4) & 1;
  val_t T91;
  { T91 = T48 & T90;}
  val_t T92;
  { T92 = TERNARY_1(T91, WB_Bus__io_from_cpu_we.values[0], T89);}
  { T93.values[0] = TERNARY(reset.values[0], 0x0L, T92);}
  { WB_Bus__io_slaves_4_we.values[0] = WB_Bus__slave_we_4.values[0];}
  val_t T94;
  { T94 = WB_Bus__io_from_cpu_addr.values[0];}
  T94 = T94 & 0xfffffffL;
  val_t T95;
  { T95 = T94 | 0x0L << 28;}
  { WB_Bus__io_slaves_3_addr.values[0] = T95;}
  { WB_Bus__io_slaves_3_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T96;
  { T96 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_3.values[0]);}
  val_t T97;
  T97 = (T44 >> 3) & 1;
  val_t T98;
  { T98 = T48 & T97;}
  val_t T99;
  { T99 = TERNARY(T98, 0x1L, T96);}
  { T100.values[0] = TERNARY(reset.values[0], 0x0L, T99);}
  { WB_Bus__io_slaves_3_sel.values[0] = WB_Bus__slave_sel_3.values[0];}
  val_t T101;
  { T101 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_3.values[0]);}
  val_t T102;
  T102 = (T53 >> 3) & 1;
  val_t T103;
  { T103 = T48 & T102;}
  val_t T104;
  { T104 = TERNARY_1(T103, WB_Bus__io_from_cpu_we.values[0], T101);}
  { T105.values[0] = TERNARY(reset.values[0], 0x0L, T104);}
  { WB_Bus__io_slaves_3_we.values[0] = WB_Bus__slave_we_3.values[0];}
  val_t T106;
  { T106 = WB_Bus__io_from_cpu_addr.values[0];}
  T106 = T106 & 0xfffffffL;
  val_t T107;
  { T107 = T106 | 0x0L << 28;}
  { WB_Bus__io_slaves_2_addr.values[0] = T107;}
  { WB_Bus__io_slaves_2_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T108;
  { T108 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_2.values[0]);}
  val_t T109;
  T109 = (T44 >> 2) & 1;
  val_t T110;
  { T110 = T48 & T109;}
  val_t T111;
  { T111 = TERNARY(T110, 0x1L, T108);}
  { T112.values[0] = TERNARY(reset.values[0], 0x0L, T111);}
  { WB_Bus__io_slaves_2_sel.values[0] = WB_Bus__slave_sel_2.values[0];}
  val_t T113;
  { T113 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_2.values[0]);}
  val_t T114;
  T114 = (T53 >> 2) & 1;
  val_t T115;
  { T115 = T48 & T114;}
  val_t T116;
  { T116 = TERNARY_1(T115, WB_Bus__io_from_cpu_we.values[0], T113);}
  { T117.values[0] = TERNARY(reset.values[0], 0x0L, T116);}
  { WB_Bus__io_slaves_2_we.values[0] = WB_Bus__slave_we_2.values[0];}
  val_t T118;
  { T118 = WB_Bus__io_from_cpu_addr.values[0];}
  T118 = T118 & 0xfffffffL;
  val_t T119;
  { T119 = T118 | 0x0L << 28;}
  { WB_Bus__io_slaves_1_addr.values[0] = T119;}
  { WB_Bus__io_slaves_1_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T120;
  { T120 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_1.values[0]);}
  val_t T121;
  T121 = (T44 >> 1) & 1;
  val_t T122;
  { T122 = T48 & T121;}
  val_t T123;
  { T123 = TERNARY(T122, 0x1L, T120);}
  { T124.values[0] = TERNARY(reset.values[0], 0x0L, T123);}
  { WB_Bus__io_slaves_1_sel.values[0] = WB_Bus__slave_sel_1.values[0];}
  val_t T125;
  { T125 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_1.values[0]);}
  val_t T126;
  T126 = (T53 >> 1) & 1;
  val_t T127;
  { T127 = T48 & T126;}
  val_t T128;
  { T128 = TERNARY_1(T127, WB_Bus__io_from_cpu_we.values[0], T125);}
  { T129.values[0] = TERNARY(reset.values[0], 0x0L, T128);}
  { WB_Bus__io_slaves_1_we.values[0] = WB_Bus__slave_we_1.values[0];}
  val_t T130;
  { T130 = WB_Bus__io_from_cpu_addr.values[0];}
  T130 = T130 & 0xfffffffL;
  val_t T131;
  { T131 = T130 | 0x0L << 28;}
  { WB_Bus__io_slaves_0_addr.values[0] = T131;}
  { WB_Bus__io_slaves_0_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T132;
  { T132 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_sel_0.values[0]);}
  val_t T133;
  T133 = (T44 >> 0) & 1;
  val_t T134;
  { T134 = T48 & T133;}
  val_t T135;
  { T135 = TERNARY(T134, 0x1L, T132);}
  { T136.values[0] = TERNARY(reset.values[0], 0x0L, T135);}
  { WB_Bus__io_slaves_0_sel.values[0] = WB_Bus__slave_sel_0.values[0];}
  val_t T137;
  { T137 = TERNARY(WB_Bus__ack_out.values[0], 0x0L, WB_Bus__slave_we_0.values[0]);}
  val_t T138;
  T138 = (T53 >> 0) & 1;
  val_t T139;
  { T139 = T48 & T138;}
  val_t T140;
  { T140 = TERNARY_1(T139, WB_Bus__io_from_cpu_we.values[0], T137);}
  { T141.values[0] = TERNARY(reset.values[0], 0x0L, T140);}
  { WB_Bus__io_slaves_0_we.values[0] = WB_Bus__slave_we_0.values[0];}
  val_t T142;
  { T142 = WB_Bus__io_from_cpu_addr.values[0];}
  T142 = T142 & 0xfffffffL;
  val_t T143;
  { T143 = T142 | 0x0L << 28;}
  { WB_Bus__io_ram_slave_addr.values[0] = T143;}
  { WB_Bus__io_ram_slave_dat2.values[0] = WB_Bus__io_from_cpu_dat2.values[0];}
  val_t T144;
  { T144 = T47 & WB_Bus__ram_op;}
  { WB_Bus__io_ram_slave_sel.values[0] = T144;}
  { T145.values[0] = TERNARY(reset.values[0], 0x1L, WB_Bus__ack_out.values[0]);}
  val_t T146;
  { T146 = TERNARY(T144, WB_Bus__io_from_cpu_we.values[0], 0x0L);}
  { WB_Bus__io_ram_slave_we.values[0] = T146;}
}


void WB_Bus_t::clock_hi ( dat_t<1> reset ) {
  dat_t<1> WB_Bus__slave_sel_7__shadow = T51;
  dat_t<1> WB_Bus__slave_we_7__shadow = T57;
  dat_t<1> WB_Bus__slave_sel_6__shadow = T64;
  dat_t<1> WB_Bus__slave_we_6__shadow = T69;
  dat_t<1> WB_Bus__slave_sel_5__shadow = T76;
  dat_t<1> WB_Bus__slave_we_5__shadow = T81;
  dat_t<1> WB_Bus__slave_sel_4__shadow = T88;
  dat_t<1> WB_Bus__slave_we_4__shadow = T93;
  dat_t<1> WB_Bus__slave_sel_3__shadow = T100;
  dat_t<1> WB_Bus__slave_we_3__shadow = T105;
  dat_t<1> WB_Bus__slave_sel_2__shadow = T112;
  dat_t<1> WB_Bus__slave_we_2__shadow = T117;
  dat_t<1> WB_Bus__slave_sel_1__shadow = T124;
  dat_t<1> WB_Bus__slave_we_1__shadow = T129;
  dat_t<1> WB_Bus__slave_sel_0__shadow = T136;
  dat_t<1> WB_Bus__slave_we_0__shadow = T141;
  dat_t<1> WB_Bus__ack_out__shadow = T145;
  WB_Bus__slave_sel_7 = T51;
  WB_Bus__slave_we_7 = T57;
  WB_Bus__slave_sel_6 = T64;
  WB_Bus__slave_we_6 = T69;
  WB_Bus__slave_sel_5 = T76;
  WB_Bus__slave_we_5 = T81;
  WB_Bus__slave_sel_4 = T88;
  WB_Bus__slave_we_4 = T93;
  WB_Bus__slave_sel_3 = T100;
  WB_Bus__slave_we_3 = T105;
  WB_Bus__slave_sel_2 = T112;
  WB_Bus__slave_we_2 = T117;
  WB_Bus__slave_sel_1 = T124;
  WB_Bus__slave_we_1 = T129;
  WB_Bus__slave_sel_0 = T136;
  WB_Bus__slave_we_0 = T141;
  WB_Bus__ack_out = T145;
}


void WB_Bus_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  WB_Bus_t* mod_typed = dynamic_cast<WB_Bus_t*>(module);
  assert(mod_typed);
  dat_table["WB_Bus.io_ram_slave_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_ram_slave_dat4, "WB_Bus.io_ram_slave_dat4", "");
  dat_table["WB_Bus.io_from_cpu_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_from_cpu_addr, "WB_Bus.io_from_cpu_addr", "");
  dat_table["WB_Bus.io_slaves_7_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_7_dat4, "WB_Bus.io_slaves_7_dat4", "");
  dat_table["WB_Bus.io_slaves_6_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_6_dat4, "WB_Bus.io_slaves_6_dat4", "");
  dat_table["WB_Bus.io_slaves_5_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_5_dat4, "WB_Bus.io_slaves_5_dat4", "");
  dat_table["WB_Bus.io_slaves_4_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_4_dat4, "WB_Bus.io_slaves_4_dat4", "");
  dat_table["WB_Bus.io_slaves_3_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_3_dat4, "WB_Bus.io_slaves_3_dat4", "");
  dat_table["WB_Bus.io_slaves_2_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_2_dat4, "WB_Bus.io_slaves_2_dat4", "");
  dat_table["WB_Bus.io_slaves_1_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_1_dat4, "WB_Bus.io_slaves_1_dat4", "");
  dat_table["WB_Bus.io_slaves_0_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_0_dat4, "WB_Bus.io_slaves_0_dat4", "");
  dat_table["WB_Bus.io_from_cpu_dat4"] = new dat_api<32>(&mod_typed->WB_Bus__io_from_cpu_dat4, "WB_Bus.io_from_cpu_dat4", "");
  dat_table["WB_Bus.io_ram_slave_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_ram_slave_ack, "WB_Bus.io_ram_slave_ack", "");
  dat_table["WB_Bus.io_slaves_7_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_7_ack, "WB_Bus.io_slaves_7_ack", "");
  dat_table["WB_Bus.io_slaves_6_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_6_ack, "WB_Bus.io_slaves_6_ack", "");
  dat_table["WB_Bus.io_slaves_5_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_5_ack, "WB_Bus.io_slaves_5_ack", "");
  dat_table["WB_Bus.io_slaves_4_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_4_ack, "WB_Bus.io_slaves_4_ack", "");
  dat_table["WB_Bus.io_slaves_3_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_3_ack, "WB_Bus.io_slaves_3_ack", "");
  dat_table["WB_Bus.io_slaves_2_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_2_ack, "WB_Bus.io_slaves_2_ack", "");
  dat_table["WB_Bus.io_slaves_1_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_1_ack, "WB_Bus.io_slaves_1_ack", "");
  dat_table["WB_Bus.io_slaves_0_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_0_ack, "WB_Bus.io_slaves_0_ack", "");
  dat_table["WB_Bus.io_from_cpu_ack"] = new dat_api<1>(&mod_typed->WB_Bus__io_from_cpu_ack, "WB_Bus.io_from_cpu_ack", "");
  dat_table["WB_Bus.io_slaves_7_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_7_addr, "WB_Bus.io_slaves_7_addr", "");
  dat_table["WB_Bus.io_from_cpu_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_from_cpu_dat2, "WB_Bus.io_from_cpu_dat2", "");
  dat_table["WB_Bus.io_slaves_7_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_7_dat2, "WB_Bus.io_slaves_7_dat2", "");
  dat_table["WB_Bus.io_from_cpu_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_from_cpu_sel, "WB_Bus.io_from_cpu_sel", "");
  dat_table["WB_Bus.slave_sel_7"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_7, "WB_Bus.slave_sel_7", "");
  dat_table["WB_Bus.io_slaves_7_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_7_sel, "WB_Bus.io_slaves_7_sel", "");
  dat_table["WB_Bus.io_from_cpu_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_from_cpu_we, "WB_Bus.io_from_cpu_we", "");
  dat_table["WB_Bus.slave_we_7"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_7, "WB_Bus.slave_we_7", "");
  dat_table["WB_Bus.io_slaves_7_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_7_we, "WB_Bus.io_slaves_7_we", "");
  dat_table["WB_Bus.io_slaves_6_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_6_addr, "WB_Bus.io_slaves_6_addr", "");
  dat_table["WB_Bus.io_slaves_6_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_6_dat2, "WB_Bus.io_slaves_6_dat2", "");
  dat_table["WB_Bus.slave_sel_6"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_6, "WB_Bus.slave_sel_6", "");
  dat_table["WB_Bus.io_slaves_6_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_6_sel, "WB_Bus.io_slaves_6_sel", "");
  dat_table["WB_Bus.slave_we_6"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_6, "WB_Bus.slave_we_6", "");
  dat_table["WB_Bus.io_slaves_6_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_6_we, "WB_Bus.io_slaves_6_we", "");
  dat_table["WB_Bus.io_slaves_5_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_5_addr, "WB_Bus.io_slaves_5_addr", "");
  dat_table["WB_Bus.io_slaves_5_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_5_dat2, "WB_Bus.io_slaves_5_dat2", "");
  dat_table["WB_Bus.slave_sel_5"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_5, "WB_Bus.slave_sel_5", "");
  dat_table["WB_Bus.io_slaves_5_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_5_sel, "WB_Bus.io_slaves_5_sel", "");
  dat_table["WB_Bus.slave_we_5"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_5, "WB_Bus.slave_we_5", "");
  dat_table["WB_Bus.io_slaves_5_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_5_we, "WB_Bus.io_slaves_5_we", "");
  dat_table["WB_Bus.io_slaves_4_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_4_addr, "WB_Bus.io_slaves_4_addr", "");
  dat_table["WB_Bus.io_slaves_4_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_4_dat2, "WB_Bus.io_slaves_4_dat2", "");
  dat_table["WB_Bus.slave_sel_4"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_4, "WB_Bus.slave_sel_4", "");
  dat_table["WB_Bus.io_slaves_4_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_4_sel, "WB_Bus.io_slaves_4_sel", "");
  dat_table["WB_Bus.slave_we_4"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_4, "WB_Bus.slave_we_4", "");
  dat_table["WB_Bus.io_slaves_4_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_4_we, "WB_Bus.io_slaves_4_we", "");
  dat_table["WB_Bus.io_slaves_3_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_3_addr, "WB_Bus.io_slaves_3_addr", "");
  dat_table["WB_Bus.io_slaves_3_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_3_dat2, "WB_Bus.io_slaves_3_dat2", "");
  dat_table["WB_Bus.slave_sel_3"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_3, "WB_Bus.slave_sel_3", "");
  dat_table["WB_Bus.io_slaves_3_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_3_sel, "WB_Bus.io_slaves_3_sel", "");
  dat_table["WB_Bus.slave_we_3"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_3, "WB_Bus.slave_we_3", "");
  dat_table["WB_Bus.io_slaves_3_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_3_we, "WB_Bus.io_slaves_3_we", "");
  dat_table["WB_Bus.io_slaves_2_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_2_addr, "WB_Bus.io_slaves_2_addr", "");
  dat_table["WB_Bus.io_slaves_2_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_2_dat2, "WB_Bus.io_slaves_2_dat2", "");
  dat_table["WB_Bus.slave_sel_2"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_2, "WB_Bus.slave_sel_2", "");
  dat_table["WB_Bus.io_slaves_2_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_2_sel, "WB_Bus.io_slaves_2_sel", "");
  dat_table["WB_Bus.slave_we_2"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_2, "WB_Bus.slave_we_2", "");
  dat_table["WB_Bus.io_slaves_2_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_2_we, "WB_Bus.io_slaves_2_we", "");
  dat_table["WB_Bus.io_slaves_1_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_1_addr, "WB_Bus.io_slaves_1_addr", "");
  dat_table["WB_Bus.io_slaves_1_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_1_dat2, "WB_Bus.io_slaves_1_dat2", "");
  dat_table["WB_Bus.slave_sel_1"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_1, "WB_Bus.slave_sel_1", "");
  dat_table["WB_Bus.io_slaves_1_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_1_sel, "WB_Bus.io_slaves_1_sel", "");
  dat_table["WB_Bus.slave_we_1"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_1, "WB_Bus.slave_we_1", "");
  dat_table["WB_Bus.io_slaves_1_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_1_we, "WB_Bus.io_slaves_1_we", "");
  dat_table["WB_Bus.io_slaves_0_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_0_addr, "WB_Bus.io_slaves_0_addr", "");
  dat_table["WB_Bus.io_slaves_0_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_slaves_0_dat2, "WB_Bus.io_slaves_0_dat2", "");
  dat_table["WB_Bus.slave_sel_0"] = new dat_api<1>(&mod_typed->WB_Bus__slave_sel_0, "WB_Bus.slave_sel_0", "");
  dat_table["WB_Bus.io_slaves_0_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_0_sel, "WB_Bus.io_slaves_0_sel", "");
  dat_table["WB_Bus.slave_we_0"] = new dat_api<1>(&mod_typed->WB_Bus__slave_we_0, "WB_Bus.slave_we_0", "");
  dat_table["WB_Bus.io_slaves_0_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_slaves_0_we, "WB_Bus.io_slaves_0_we", "");
  dat_table["WB_Bus.io_ram_slave_addr"] = new dat_api<32>(&mod_typed->WB_Bus__io_ram_slave_addr, "WB_Bus.io_ram_slave_addr", "");
  dat_table["WB_Bus.io_ram_slave_dat2"] = new dat_api<32>(&mod_typed->WB_Bus__io_ram_slave_dat2, "WB_Bus.io_ram_slave_dat2", "");
  dat_table["WB_Bus.io_ram_slave_sel"] = new dat_api<1>(&mod_typed->WB_Bus__io_ram_slave_sel, "WB_Bus.io_ram_slave_sel", "");
  dat_table["WB_Bus.ack_out"] = new dat_api<1>(&mod_typed->WB_Bus__ack_out, "WB_Bus.ack_out", "");
  dat_table["WB_Bus.io_ram_slave_we"] = new dat_api<1>(&mod_typed->WB_Bus__io_ram_slave_we, "WB_Bus.io_ram_slave_we", "");
}
