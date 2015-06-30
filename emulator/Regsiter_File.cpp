#include "Regsiter_File.h"

void Regsiter_File_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  Regsiter_File__rf.randomize(&__rand_seed);
}


int Regsiter_File_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* Regsiter_File_t::clone() {
  mod_t* cloned = new Regsiter_File_t(*this);
  return cloned;
}


bool Regsiter_File_t::set_circuit_from ( mod_t* src ) {
  Regsiter_File_t* mod_typed = dynamic_cast<Regsiter_File_t*>(src);
  assert(mod_typed);
  Regsiter_File__io_addra = mod_typed->Regsiter_File__io_addra;
  Regsiter_File__io_douta = mod_typed->Regsiter_File__io_douta;
  Regsiter_File__io_wtdata = mod_typed->Regsiter_File__io_wtdata;
  Regsiter_File__io_wtaddr = mod_typed->Regsiter_File__io_wtaddr;
  Regsiter_File__io_we = mod_typed->Regsiter_File__io_we;
  T2 = mod_typed->T2;
  Regsiter_File__rf = mod_typed->Regsiter_File__rf;
  Regsiter_File__io_addrb = mod_typed->Regsiter_File__io_addrb;
  Regsiter_File__io_doutb = mod_typed->Regsiter_File__io_doutb;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void Regsiter_File_t::print ( FILE* f ) {
}
void Regsiter_File_t::print ( std::ostream& s ) {
}


void Regsiter_File_t::dump_init ( FILE* f ) {
}


void Regsiter_File_t::dump ( FILE* f, int t ) {
}




void Regsiter_File_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = Regsiter_File__rf.get(Regsiter_File__io_addra.values[0], 0);}
  { Regsiter_File__io_douta.values[0] = T0;}
  val_t T1;
  T1 = Regsiter_File__io_wtaddr.values[0] != 0x0L;
  { T2.values[0] = Regsiter_File__io_we.values[0] & T1;}
  val_t T3;
  { T3 = Regsiter_File__rf.get(Regsiter_File__io_addrb.values[0], 0);}
  { Regsiter_File__io_doutb.values[0] = T3;}
}


void Regsiter_File_t::clock_hi ( dat_t<1> reset ) {
  { if (T2.values[0]) Regsiter_File__rf.put(Regsiter_File__io_wtaddr.values[0], 0, Regsiter_File__io_wtdata.values[0]);}
}


void Regsiter_File_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  Regsiter_File_t* mod_typed = dynamic_cast<Regsiter_File_t*>(module);
  assert(mod_typed);
  dat_table["Regsiter_File.io_addra"] = new dat_api<5>(&mod_typed->Regsiter_File__io_addra, "Regsiter_File.io_addra", "");
  dat_table["Regsiter_File.io_douta"] = new dat_api<32>(&mod_typed->Regsiter_File__io_douta, "Regsiter_File.io_douta", "");
  dat_table["Regsiter_File.io_wtdata"] = new dat_api<32>(&mod_typed->Regsiter_File__io_wtdata, "Regsiter_File.io_wtdata", "");
  dat_table["Regsiter_File.io_wtaddr"] = new dat_api<5>(&mod_typed->Regsiter_File__io_wtaddr, "Regsiter_File.io_wtaddr", "");
  dat_table["Regsiter_File.io_we"] = new dat_api<1>(&mod_typed->Regsiter_File__io_we, "Regsiter_File.io_we", "");
  mem_table["Regsiter_File.rf"] = new mem_api<32, 32>(&mod_typed->Regsiter_File__rf, "Regsiter_File.rf", "");
  dat_table["Regsiter_File.io_addrb"] = new dat_api<5>(&mod_typed->Regsiter_File__io_addrb, "Regsiter_File.io_addrb", "");
  dat_table["Regsiter_File.io_doutb"] = new dat_api<32>(&mod_typed->Regsiter_File__io_doutb, "Regsiter_File.io_doutb", "");
}
