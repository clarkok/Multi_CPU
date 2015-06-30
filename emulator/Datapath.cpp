#include "Datapath.h"

void Datapath_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  Datapath_regfile__rf.randomize(&__rand_seed);
  Datapath__inst_reg.randomize(&__rand_seed);
  Datapath__pc.randomize(&__rand_seed);
}


int Datapath_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* Datapath_t::clone() {
  mod_t* cloned = new Datapath_t(*this);
  return cloned;
}


bool Datapath_t::set_circuit_from ( mod_t* src ) {
  Datapath_t* mod_typed = dynamic_cast<Datapath_t*>(src);
  assert(mod_typed);
  Datapath__io_reg_we_src = mod_typed->Datapath__io_reg_we_src;
  Datapath__io_bus_data = mod_typed->Datapath__io_bus_data;
  Datapath__io_alu_b_sel = mod_typed->Datapath__io_alu_b_sel;
  Datapath_regfile__io_addrb = mod_typed->Datapath_regfile__io_addrb;
  Datapath_regfile__io_doutb = mod_typed->Datapath_regfile__io_doutb;
  Datapath_alu__io_in_b = mod_typed->Datapath_alu__io_in_b;
  Datapath_regfile__io_addra = mod_typed->Datapath_regfile__io_addra;
  Datapath_regfile__io_douta = mod_typed->Datapath_regfile__io_douta;
  Datapath_alu__io_in_a = mod_typed->Datapath_alu__io_in_a;
  Datapath__io_alu_op = mod_typed->Datapath__io_alu_op;
  Datapath_alu__io_alu_op = mod_typed->Datapath_alu__io_alu_op;
  Datapath_alu__io_out = mod_typed->Datapath_alu__io_out;
  Datapath_regfile__io_wtdata = mod_typed->Datapath_regfile__io_wtdata;
  Datapath__io_reg_we_dst = mod_typed->Datapath__io_reg_we_dst;
  Datapath_regfile__io_wtaddr = mod_typed->Datapath_regfile__io_wtaddr;
  Datapath__io_reg_we = mod_typed->Datapath__io_reg_we;
  Datapath_regfile__io_we = mod_typed->Datapath_regfile__io_we;
  T53 = mod_typed->T53;
  Datapath_regfile__rf = mod_typed->Datapath_regfile__rf;
  Datapath__io_inst = mod_typed->Datapath__io_inst;
  Datapath__io_pc_out = mod_typed->Datapath__io_pc_out;
  Datapath__io_alu_out = mod_typed->Datapath__io_alu_out;
  Datapath__io_data_out = mod_typed->Datapath__io_data_out;
  Datapath__io_inst_we = mod_typed->Datapath__io_inst_we;
  T55 = mod_typed->T55;
  Datapath__inst_reg = mod_typed->Datapath__inst_reg;
  Datapath__io_pc_next_sel = mod_typed->Datapath__io_pc_next_sel;
  Datapath_alu__io_zero = mod_typed->Datapath_alu__io_zero;
  Datapath__io_pc_we = mod_typed->Datapath__io_pc_we;
  T90 = mod_typed->T90;
  Datapath__pc = mod_typed->Datapath__pc;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void Datapath_t::print ( FILE* f ) {
}
void Datapath_t::print ( std::ostream& s ) {
}


void Datapath_t::dump_init ( FILE* f ) {
}


void Datapath_t::dump ( FILE* f, int t ) {
}




void Datapath_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = Datapath__pc.values[0]+0x4L;}
  T0 = T0 & 0xffffffffL;
  val_t T1;
  T1 = Datapath__io_reg_we_src.values[0] == 0x2L;
  val_t T2;
  { T2 = TERNARY(T1, T0, 0x0L);}
  val_t T3;
  T3 = Datapath__io_reg_we_src.values[0] == 0x1L;
  val_t T4;
  { T4 = TERNARY_1(T3, Datapath__io_bus_data.values[0], T2);}
  val_t T5;
  { T5 = Datapath__inst_reg.values[0];}
  T5 = T5 & 0xffffL;
  val_t T6;
  { T6 = T5 | 0x0L << 16;}
  val_t T7;
  T7 = Datapath__io_alu_b_sel.values[0] == 0x1L;
  val_t T8;
  { T8 = TERNARY(T7, T6, 0x0L);}
  val_t T9;
  { T9 = Datapath__inst_reg.values[0] >> 16;}
  T9 = T9 & 0x1fL;
  { Datapath_regfile__io_addrb.values[0] = T9;}
  val_t T10;
  { T10 = Datapath_regfile__rf.get(Datapath_regfile__io_addrb.values[0], 0);}
  { Datapath_regfile__io_doutb.values[0] = T10;}
  val_t T11;
  T11 = Datapath__io_alu_b_sel.values[0] == 0x0L;
  val_t T12;
  { T12 = TERNARY_1(T11, Datapath_regfile__io_doutb.values[0], T8);}
  { Datapath_alu__io_in_b.values[0] = T12;}
  val_t T13;
  { T13 = Datapath__inst_reg.values[0] >> 21;}
  T13 = T13 & 0x1fL;
  { Datapath_regfile__io_addra.values[0] = T13;}
  val_t T14;
  { T14 = Datapath_regfile__rf.get(Datapath_regfile__io_addra.values[0], 0);}
  { Datapath_regfile__io_douta.values[0] = T14;}
  { Datapath_alu__io_in_a.values[0] = Datapath_regfile__io_douta.values[0];}
  val_t T15;
  T15 = Datapath_alu__io_in_a.values[0]<Datapath_alu__io_in_b.values[0];
  val_t T16;
  { T16 = T15 | 0x0L << 1;}
  { Datapath_alu__io_alu_op.values[0] = Datapath__io_alu_op.values[0];}
  val_t T17;
  T17 = Datapath_alu__io_alu_op.values[0] == 0x7L;
  val_t T18;
  { T18 = TERNARY(T17, T16, 0x0L);}
  val_t T19;
  { T19 = Datapath_alu__io_in_a.values[0]-Datapath_alu__io_in_b.values[0];}
  T19 = T19 & 0xffffffffL;
  val_t T20;
  T20 = Datapath_alu__io_alu_op.values[0] == 0x6L;
  val_t T21;
  { T21 = TERNARY_1(T20, T19, T18);}
  val_t T22;
  { T22 = Datapath_alu__io_in_b.values[0];}
  T22 = T22 & 0x1fL;
  val_t T23;
  T23 = Datapath_alu__io_in_a.values[0] >> T22;
  val_t T24;
  T24 = Datapath_alu__io_alu_op.values[0] == 0x5L;
  val_t T25;
  { T25 = TERNARY_1(T24, T23, T21);}
  val_t T26;
  { T26 = Datapath_alu__io_in_a.values[0] | Datapath_alu__io_in_b.values[0];}
  val_t T27;
  { T27 = ~T26;}
  T27 = T27 & 0xffffffffL;
  val_t T28;
  T28 = Datapath_alu__io_alu_op.values[0] == 0x4L;
  val_t T29;
  { T29 = TERNARY_1(T28, T27, T25);}
  val_t T30;
  { T30 = Datapath_alu__io_in_a.values[0] ^ Datapath_alu__io_in_b.values[0];}
  val_t T31;
  T31 = Datapath_alu__io_alu_op.values[0] == 0x3L;
  val_t T32;
  { T32 = TERNARY_1(T31, T30, T29);}
  val_t T33;
  { T33 = Datapath_alu__io_in_a.values[0]+Datapath_alu__io_in_b.values[0];}
  T33 = T33 & 0xffffffffL;
  val_t T34;
  T34 = Datapath_alu__io_alu_op.values[0] == 0x2L;
  val_t T35;
  { T35 = TERNARY_1(T34, T33, T32);}
  val_t T36;
  { T36 = Datapath_alu__io_in_a.values[0] | Datapath_alu__io_in_b.values[0];}
  val_t T37;
  T37 = Datapath_alu__io_alu_op.values[0] == 0x1L;
  val_t T38;
  { T38 = TERNARY_1(T37, T36, T35);}
  val_t T39;
  { T39 = Datapath_alu__io_in_a.values[0] & Datapath_alu__io_in_b.values[0];}
  val_t T40;
  T40 = Datapath_alu__io_alu_op.values[0] == 0x0L;
  val_t T41;
  { T41 = TERNARY_1(T40, T39, T38);}
  { Datapath_alu__io_out.values[0] = T41;}
  val_t T42;
  T42 = Datapath__io_reg_we_src.values[0] == 0x0L;
  val_t T43;
  { T43 = TERNARY_1(T42, Datapath_alu__io_out.values[0], T4);}
  { Datapath_regfile__io_wtdata.values[0] = T43;}
  val_t T44;
  T44 = Datapath__io_reg_we_dst.values[0] == 0x2L;
  val_t T45;
  { T45 = TERNARY(T44, 0x1fL, 0x0L);}
  val_t T46;
  { T46 = Datapath__inst_reg.values[0] >> 16;}
  T46 = T46 & 0x1fL;
  val_t T47;
  T47 = Datapath__io_reg_we_dst.values[0] == 0x1L;
  val_t T48;
  { T48 = TERNARY_1(T47, T46, T45);}
  val_t T49;
  { T49 = Datapath__inst_reg.values[0] >> 11;}
  T49 = T49 & 0x1fL;
  val_t T50;
  T50 = Datapath__io_reg_we_dst.values[0] == 0x0L;
  val_t T51;
  { T51 = TERNARY_1(T50, T49, T48);}
  { Datapath_regfile__io_wtaddr.values[0] = T51;}
  val_t T52;
  T52 = Datapath_regfile__io_wtaddr.values[0] != 0x0L;
  { Datapath_regfile__io_we.values[0] = Datapath__io_reg_we.values[0];}
  { T53.values[0] = Datapath_regfile__io_we.values[0] & T52;}
  { Datapath__io_inst.values[0] = Datapath__inst_reg.values[0];}
  { Datapath__io_pc_out.values[0] = Datapath__pc.values[0];}
  { Datapath__io_alu_out.values[0] = Datapath_alu__io_out.values[0];}
  { Datapath__io_data_out.values[0] = Datapath_regfile__io_doutb.values[0];}
  val_t T54;
  { T54 = TERNARY_1(Datapath__io_inst_we.values[0], Datapath__io_bus_data.values[0], Datapath__inst_reg.values[0]);}
  { T55.values[0] = TERNARY(reset.values[0], 0x0L, T54);}
  val_t T56;
  { T56 = Datapath__pc.values[0] | 0x0L << 32;}
  val_t T57;
  T57 = Datapath__io_pc_next_sel.values[0] == 0x3L;
  val_t T58;
  { T58 = TERNARY(T57, Datapath_regfile__io_douta.values[0], 0x0L);}
  val_t T59;
  { T59 = Datapath__inst_reg.values[0];}
  T59 = T59 & 0x3ffffffL;
  val_t T60;
  T60 = T59 << 0x2L;
  T60 = T60 & 0xfffffffL;
  val_t T61;
  { T61 = Datapath__pc.values[0] >> 28;}
  T61 = T61 & 0xfL;
  val_t T62;
  { T62 = T61 | 0x0L << 4;}
  val_t T63;
  { T63 = T62 | T60;}
  val_t T64;
  { T64 = T63 | 0x0L << 28;}
  val_t T65;
  T65 = Datapath__io_pc_next_sel.values[0] == 0x2L;
  val_t T66;
  { T66 = TERNARY_1(T65, T64, T58);}
  val_t T67;
  { T67 = T66 | 0x0L << 32;}
  val_t T68;
  { T68 = Datapath__pc.values[0]+0x4L;}
  T68 = T68 & 0xffffffffL;
  val_t T69;
  T69 = Datapath_alu__io_out.values[0] != 0x0L;
  val_t T70;
  { T70 = T69 ^ 0x1L;}
  { Datapath_alu__io_zero.values[0] = T70;}
  val_t T71;
  T71 = Datapath_alu__io_zero.values[0] == 0x0L;
  val_t T72;
  { T72 = TERNARY(T71, T68, 0x0L);}
  val_t T73;
  { T73 = T72 | 0x0L << 32;}
  val_t T74;
  { T74 = Datapath__pc.values[0] | 0x0L << 32;}
  val_t T75;
  { T75 = Datapath__inst_reg.values[0];}
  T75 = T75 & 0xffffL;
  val_t T76;
  T76 = T75 << 0x2L;
  T76 = T76 & 0x3ffffL;
  val_t T77;
  T77 = (T76 >> 17) & 1;
  val_t T78;
  { T78 = TERNARY(T77, 0x7fffL, 0x0L);}
  val_t T79;
  { T79 = T76 | T78 << 18;}
  val_t T80;
  { T80 = T79+T74;}
  T80 = T80 & 0x1ffffffffL;
  val_t T81;
  T81 = Datapath_alu__io_zero.values[0] == 0x1L;
  val_t T82;
  { T82 = TERNARY_1(T81, T80, T73);}
  val_t T83;
  T83 = Datapath__io_pc_next_sel.values[0] == 0x1L;
  val_t T84;
  { T84 = TERNARY_1(T83, T82, T67);}
  val_t T85;
  { T85 = Datapath__pc.values[0]+0x4L;}
  T85 = T85 & 0xffffffffL;
  val_t T86;
  { T86 = T85 | 0x0L << 32;}
  val_t T87;
  T87 = Datapath__io_pc_next_sel.values[0] == 0x0L;
  val_t Datapath__pc_next;
  { Datapath__pc_next = TERNARY_1(T87, T86, T84);}
  val_t T88;
  { T88 = TERNARY_1(Datapath__io_pc_we.values[0], Datapath__pc_next, T56);}
  val_t T89;
  { T89 = TERNARY(reset.values[0], 0x0L, T88);}
  { T90.values[0] = T89;}
  T90.values[0] = T90.values[0] & 0xffffffffL;
}


void Datapath_t::clock_hi ( dat_t<1> reset ) {
  { if (T53.values[0]) Datapath_regfile__rf.put(Datapath_regfile__io_wtaddr.values[0], 0, Datapath_regfile__io_wtdata.values[0]);}
  dat_t<32> Datapath__inst_reg__shadow = T55;
  dat_t<32> Datapath__pc__shadow = T90;
  Datapath__inst_reg = T55;
  Datapath__pc = T90;
}


void Datapath_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  Datapath_t* mod_typed = dynamic_cast<Datapath_t*>(module);
  assert(mod_typed);
  dat_table["Datapath.io_reg_we_src"] = new dat_api<2>(&mod_typed->Datapath__io_reg_we_src, "Datapath.io_reg_we_src", "");
  dat_table["Datapath.io_bus_data"] = new dat_api<32>(&mod_typed->Datapath__io_bus_data, "Datapath.io_bus_data", "");
  dat_table["Datapath.io_alu_b_sel"] = new dat_api<1>(&mod_typed->Datapath__io_alu_b_sel, "Datapath.io_alu_b_sel", "");
  dat_table["Datapath.regfile.io_addrb"] = new dat_api<5>(&mod_typed->Datapath_regfile__io_addrb, "Datapath.regfile.io_addrb", "");
  dat_table["Datapath.regfile.io_doutb"] = new dat_api<32>(&mod_typed->Datapath_regfile__io_doutb, "Datapath.regfile.io_doutb", "");
  dat_table["Datapath.alu.io_in_b"] = new dat_api<32>(&mod_typed->Datapath_alu__io_in_b, "Datapath.alu.io_in_b", "");
  dat_table["Datapath.regfile.io_addra"] = new dat_api<5>(&mod_typed->Datapath_regfile__io_addra, "Datapath.regfile.io_addra", "");
  dat_table["Datapath.regfile.io_douta"] = new dat_api<32>(&mod_typed->Datapath_regfile__io_douta, "Datapath.regfile.io_douta", "");
  dat_table["Datapath.alu.io_in_a"] = new dat_api<32>(&mod_typed->Datapath_alu__io_in_a, "Datapath.alu.io_in_a", "");
  dat_table["Datapath.io_alu_op"] = new dat_api<3>(&mod_typed->Datapath__io_alu_op, "Datapath.io_alu_op", "");
  dat_table["Datapath.alu.io_alu_op"] = new dat_api<3>(&mod_typed->Datapath_alu__io_alu_op, "Datapath.alu.io_alu_op", "");
  dat_table["Datapath.alu.io_out"] = new dat_api<32>(&mod_typed->Datapath_alu__io_out, "Datapath.alu.io_out", "");
  dat_table["Datapath.regfile.io_wtdata"] = new dat_api<32>(&mod_typed->Datapath_regfile__io_wtdata, "Datapath.regfile.io_wtdata", "");
  dat_table["Datapath.io_reg_we_dst"] = new dat_api<2>(&mod_typed->Datapath__io_reg_we_dst, "Datapath.io_reg_we_dst", "");
  dat_table["Datapath.regfile.io_wtaddr"] = new dat_api<5>(&mod_typed->Datapath_regfile__io_wtaddr, "Datapath.regfile.io_wtaddr", "");
  dat_table["Datapath.io_reg_we"] = new dat_api<1>(&mod_typed->Datapath__io_reg_we, "Datapath.io_reg_we", "");
  dat_table["Datapath.regfile.io_we"] = new dat_api<1>(&mod_typed->Datapath_regfile__io_we, "Datapath.regfile.io_we", "");
  mem_table["Datapath.regfile.rf"] = new mem_api<32, 32>(&mod_typed->Datapath_regfile__rf, "Datapath.regfile.rf", "");
  dat_table["Datapath.io_inst"] = new dat_api<32>(&mod_typed->Datapath__io_inst, "Datapath.io_inst", "");
  dat_table["Datapath.io_pc_out"] = new dat_api<32>(&mod_typed->Datapath__io_pc_out, "Datapath.io_pc_out", "");
  dat_table["Datapath.io_alu_out"] = new dat_api<32>(&mod_typed->Datapath__io_alu_out, "Datapath.io_alu_out", "");
  dat_table["Datapath.io_data_out"] = new dat_api<32>(&mod_typed->Datapath__io_data_out, "Datapath.io_data_out", "");
  dat_table["Datapath.io_inst_we"] = new dat_api<1>(&mod_typed->Datapath__io_inst_we, "Datapath.io_inst_we", "");
  dat_table["Datapath.inst_reg"] = new dat_api<32>(&mod_typed->Datapath__inst_reg, "Datapath.inst_reg", "");
  dat_table["Datapath.io_pc_next_sel"] = new dat_api<2>(&mod_typed->Datapath__io_pc_next_sel, "Datapath.io_pc_next_sel", "");
  dat_table["Datapath.alu.io_zero"] = new dat_api<1>(&mod_typed->Datapath_alu__io_zero, "Datapath.alu.io_zero", "");
  dat_table["Datapath.io_pc_we"] = new dat_api<1>(&mod_typed->Datapath__io_pc_we, "Datapath.io_pc_we", "");
  dat_table["Datapath.pc"] = new dat_api<32>(&mod_typed->Datapath__pc, "Datapath.pc", "");
}
