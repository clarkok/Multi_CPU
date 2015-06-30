#include "ALU.h"

void ALU_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
}


int ALU_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* ALU_t::clone() {
  mod_t* cloned = new ALU_t(*this);
  return cloned;
}


bool ALU_t::set_circuit_from ( mod_t* src ) {
  ALU_t* mod_typed = dynamic_cast<ALU_t*>(src);
  assert(mod_typed);
  ALU__io_in_b = mod_typed->ALU__io_in_b;
  ALU__io_in_a = mod_typed->ALU__io_in_a;
  ALU__io_alu_op = mod_typed->ALU__io_alu_op;
  ALU__io_out = mod_typed->ALU__io_out;
  ALU__io_zero = mod_typed->ALU__io_zero;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void ALU_t::print ( FILE* f ) {
}
void ALU_t::print ( std::ostream& s ) {
}


void ALU_t::dump_init ( FILE* f ) {
}


void ALU_t::dump ( FILE* f, int t ) {
}




void ALU_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  T0 = ALU__io_in_a.values[0]<ALU__io_in_b.values[0];
  val_t T1;
  { T1 = T0 | 0x0L << 1;}
  val_t T2;
  T2 = ALU__io_alu_op.values[0] == 0x7L;
  val_t T3;
  { T3 = TERNARY(T2, T1, 0x0L);}
  val_t T4;
  { T4 = ALU__io_in_a.values[0]-ALU__io_in_b.values[0];}
  T4 = T4 & 0xffffffffL;
  val_t T5;
  T5 = ALU__io_alu_op.values[0] == 0x6L;
  val_t T6;
  { T6 = TERNARY_1(T5, T4, T3);}
  val_t T7;
  { T7 = ALU__io_in_b.values[0];}
  T7 = T7 & 0x1fL;
  val_t T8;
  T8 = ALU__io_in_a.values[0] >> T7;
  val_t T9;
  T9 = ALU__io_alu_op.values[0] == 0x5L;
  val_t T10;
  { T10 = TERNARY_1(T9, T8, T6);}
  val_t T11;
  { T11 = ALU__io_in_a.values[0] | ALU__io_in_b.values[0];}
  val_t T12;
  { T12 = ~T11;}
  T12 = T12 & 0xffffffffL;
  val_t T13;
  T13 = ALU__io_alu_op.values[0] == 0x4L;
  val_t T14;
  { T14 = TERNARY_1(T13, T12, T10);}
  val_t T15;
  { T15 = ALU__io_in_a.values[0] ^ ALU__io_in_b.values[0];}
  val_t T16;
  T16 = ALU__io_alu_op.values[0] == 0x3L;
  val_t T17;
  { T17 = TERNARY_1(T16, T15, T14);}
  val_t T18;
  { T18 = ALU__io_in_a.values[0]+ALU__io_in_b.values[0];}
  T18 = T18 & 0xffffffffL;
  val_t T19;
  T19 = ALU__io_alu_op.values[0] == 0x2L;
  val_t T20;
  { T20 = TERNARY_1(T19, T18, T17);}
  val_t T21;
  { T21 = ALU__io_in_a.values[0] | ALU__io_in_b.values[0];}
  val_t T22;
  T22 = ALU__io_alu_op.values[0] == 0x1L;
  val_t T23;
  { T23 = TERNARY_1(T22, T21, T20);}
  val_t T24;
  { T24 = ALU__io_in_a.values[0] & ALU__io_in_b.values[0];}
  val_t T25;
  T25 = ALU__io_alu_op.values[0] == 0x0L;
  val_t T26;
  { T26 = TERNARY_1(T25, T24, T23);}
  { ALU__io_out.values[0] = T26;}
  val_t T27;
  T27 = ALU__io_out.values[0] != 0x0L;
  val_t T28;
  { T28 = T27 ^ 0x1L;}
  { ALU__io_zero.values[0] = T28;}
}


void ALU_t::clock_hi ( dat_t<1> reset ) {
}


void ALU_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  ALU_t* mod_typed = dynamic_cast<ALU_t*>(module);
  assert(mod_typed);
  dat_table["ALU.io_in_b"] = new dat_api<32>(&mod_typed->ALU__io_in_b, "ALU.io_in_b", "");
  dat_table["ALU.io_in_a"] = new dat_api<32>(&mod_typed->ALU__io_in_a, "ALU.io_in_a", "");
  dat_table["ALU.io_alu_op"] = new dat_api<3>(&mod_typed->ALU__io_alu_op, "ALU.io_alu_op", "");
  dat_table["ALU.io_out"] = new dat_api<32>(&mod_typed->ALU__io_out, "ALU.io_out", "");
  dat_table["ALU.io_zero"] = new dat_api<1>(&mod_typed->ALU__io_zero, "ALU.io_zero", "");
}
