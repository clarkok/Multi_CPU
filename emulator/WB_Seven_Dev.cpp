#include "WB_Seven_Dev.h"

void WB_Seven_Dev_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  WB_Seven_Dev__data_out.randomize(&__rand_seed);
  WB_Seven_Dev__disp_data.randomize(&__rand_seed);
}


int WB_Seven_Dev_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* WB_Seven_Dev_t::clone() {
  mod_t* cloned = new WB_Seven_Dev_t(*this);
  return cloned;
}


bool WB_Seven_Dev_t::set_circuit_from ( mod_t* src ) {
  WB_Seven_Dev_t* mod_typed = dynamic_cast<WB_Seven_Dev_t*>(src);
  assert(mod_typed);
  WB_Seven_Dev__io_bus_dat2 = mod_typed->WB_Seven_Dev__io_bus_dat2;
  WB_Seven_Dev__io_bus_we = mod_typed->WB_Seven_Dev__io_bus_we;
  WB_Seven_Dev__io_bus_sel = mod_typed->WB_Seven_Dev__io_bus_sel;
  T8 = mod_typed->T8;
  WB_Seven_Dev__data_out = mod_typed->WB_Seven_Dev__data_out;
  WB_Seven_Dev__io_bus_dat4 = mod_typed->WB_Seven_Dev__io_bus_dat4;
  WB_Seven_Dev__io_bus_ack = mod_typed->WB_Seven_Dev__io_bus_ack;
  T10 = mod_typed->T10;
  WB_Seven_Dev__disp_data = mod_typed->WB_Seven_Dev__disp_data;
  WB_Seven_Dev__io_DISP_NUM = mod_typed->WB_Seven_Dev__io_DISP_NUM;
  WB_Seven_Dev__io_bus_addr = mod_typed->WB_Seven_Dev__io_bus_addr;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void WB_Seven_Dev_t::print ( FILE* f ) {
}
void WB_Seven_Dev_t::print ( std::ostream& s ) {
}


void WB_Seven_Dev_t::dump_init ( FILE* f ) {
}


void WB_Seven_Dev_t::dump ( FILE* f, int t ) {
}




void WB_Seven_Dev_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = WB_Seven_Dev__io_bus_sel.values[0] & WB_Seven_Dev__io_bus_we.values[0];}
  val_t T1;
  { T1 = TERNARY_1(T0, WB_Seven_Dev__io_bus_dat2.values[0], WB_Seven_Dev__data_out.values[0]);}
  val_t T2;
  { T2 = T0 ^ 0x1L;}
  val_t T3;
  { T3 = T2 & WB_Seven_Dev__io_bus_sel.values[0];}
  val_t T4;
  { T4 = TERNARY_1(T3, WB_Seven_Dev__disp_data.values[0], T1);}
  val_t T5;
  { T5 = T0 | WB_Seven_Dev__io_bus_sel.values[0];}
  val_t T6;
  { T6 = T5 ^ 0x1L;}
  val_t T7;
  { T7 = TERNARY(T6, 0x0L, T4);}
  { T8.values[0] = TERNARY(reset.values[0], 0x0L, T7);}
  { WB_Seven_Dev__io_bus_dat4.values[0] = WB_Seven_Dev__data_out.values[0];}
  { WB_Seven_Dev__io_bus_ack.values[0] = 0x1L;}
  val_t T9;
  { T9 = TERNARY_1(T0, WB_Seven_Dev__io_bus_dat2.values[0], WB_Seven_Dev__disp_data.values[0]);}
  { T10.values[0] = TERNARY(reset.values[0], 0x0L, T9);}
  { WB_Seven_Dev__io_DISP_NUM.values[0] = WB_Seven_Dev__disp_data.values[0];}
}


void WB_Seven_Dev_t::clock_hi ( dat_t<1> reset ) {
  dat_t<32> WB_Seven_Dev__data_out__shadow = T8;
  dat_t<32> WB_Seven_Dev__disp_data__shadow = T10;
  WB_Seven_Dev__data_out = T8;
  WB_Seven_Dev__disp_data = T10;
}


void WB_Seven_Dev_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  WB_Seven_Dev_t* mod_typed = dynamic_cast<WB_Seven_Dev_t*>(module);
  assert(mod_typed);
  dat_table["WB_Seven_Dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__io_bus_dat2, "WB_Seven_Dev.io_bus_dat2", "");
  dat_table["WB_Seven_Dev.io_bus_we"] = new dat_api<1>(&mod_typed->WB_Seven_Dev__io_bus_we, "WB_Seven_Dev.io_bus_we", "");
  dat_table["WB_Seven_Dev.io_bus_sel"] = new dat_api<1>(&mod_typed->WB_Seven_Dev__io_bus_sel, "WB_Seven_Dev.io_bus_sel", "");
  dat_table["WB_Seven_Dev.data_out"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__data_out, "WB_Seven_Dev.data_out", "");
  dat_table["WB_Seven_Dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__io_bus_dat4, "WB_Seven_Dev.io_bus_dat4", "");
  dat_table["WB_Seven_Dev.io_bus_ack"] = new dat_api<1>(&mod_typed->WB_Seven_Dev__io_bus_ack, "WB_Seven_Dev.io_bus_ack", "");
  dat_table["WB_Seven_Dev.disp_data"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__disp_data, "WB_Seven_Dev.disp_data", "");
  dat_table["WB_Seven_Dev.io_DISP_NUM"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__io_DISP_NUM, "WB_Seven_Dev.io_DISP_NUM", "");
  dat_table["WB_Seven_Dev.io_bus_addr"] = new dat_api<32>(&mod_typed->WB_Seven_Dev__io_bus_addr, "WB_Seven_Dev.io_bus_addr", "");
}
