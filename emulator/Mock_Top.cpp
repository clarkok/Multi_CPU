#include "Mock_Top.h"

void Mock_Top_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  Mock_Top_soc_dev_seven_seg__data_out.randomize(&__rand_seed);
  Mock_Top_soc_dev_seven_seg__disp_data.randomize(&__rand_seed);
  Mock_Top_soc_dev_led__data_out.randomize(&__rand_seed);
  Mock_Top_soc_dev_led__led_data.randomize(&__rand_seed);
  Mock_Top_soc_cpu_dpath_regfile__rf.randomize(&__rand_seed);
  Mock_Top_soc_cpu_dpath__inst_reg.randomize(&__rand_seed);
  Mock_Top_soc_cpu_dpath__pc.randomize(&__rand_seed);
  Mock_Top_soc_cpu_cpath__state.randomize(&__rand_seed);
}


int Mock_Top_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* Mock_Top_t::clone() {
  mod_t* cloned = new Mock_Top_t(*this);
  return cloned;
}


bool Mock_Top_t::set_circuit_from ( mod_t* src ) {
  Mock_Top_t* mod_typed = dynamic_cast<Mock_Top_t*>(src);
  assert(mod_typed);
  Mock_Top_soc_cpu_dpath_regfile__io_addrb = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_addrb;
  Mock_Top_soc_cpu_dpath_regfile__io_doutb = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_doutb;
  Mock_Top_soc_cpu_dpath__io_data_out = mod_typed->Mock_Top_soc_cpu_dpath__io_data_out;
  Mock_Top_soc_cpu_cpath__io_ctrl_data_out = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_data_out;
  Mock_Top_soc_cpu_cpath__io_bus_dat2 = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_dat2;
  Mock_Top_soc_cpu__io_bus_dat2 = mod_typed->Mock_Top_soc_cpu__io_bus_dat2;
  Mock_Top_soc_dev__io_bus_dat2 = mod_typed->Mock_Top_soc_dev__io_bus_dat2;
  Mock_Top_soc_dev_bus__io_from_cpu_dat2 = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_dat2;
  Mock_Top_soc_dev_bus__io_slaves_4_dat2 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_dat2;
  Mock_Top_soc_dev_seven_seg__io_bus_dat2 = mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_dat2;
  Mock_Top_soc_cpu_dpath__io_pc_out = mod_typed->Mock_Top_soc_cpu_dpath__io_pc_out;
  Mock_Top_soc_cpu_cpath__io_ctrl_pc_out = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_out;
  Mock_Top_soc_cpu_cpath__io_ctrl_alu_b_sel = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_b_sel;
  Mock_Top_soc_cpu_dpath__io_alu_b_sel = mod_typed->Mock_Top_soc_cpu_dpath__io_alu_b_sel;
  Mock_Top_soc_cpu_dpath_alu__io_in_b = mod_typed->Mock_Top_soc_cpu_dpath_alu__io_in_b;
  Mock_Top_soc_cpu_dpath_regfile__io_addra = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_addra;
  Mock_Top_soc_cpu_dpath_regfile__io_douta = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_douta;
  Mock_Top_soc_cpu_dpath_alu__io_in_a = mod_typed->Mock_Top_soc_cpu_dpath_alu__io_in_a;
  Mock_Top_soc_cpu_cpath__io_ctrl_alu_op = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_op;
  Mock_Top_soc_cpu_dpath__io_alu_op = mod_typed->Mock_Top_soc_cpu_dpath__io_alu_op;
  Mock_Top_soc_cpu_dpath_alu__io_alu_op = mod_typed->Mock_Top_soc_cpu_dpath_alu__io_alu_op;
  Mock_Top_soc_cpu_dpath_alu__io_out = mod_typed->Mock_Top_soc_cpu_dpath_alu__io_out;
  Mock_Top_soc_cpu_dpath__io_alu_out = mod_typed->Mock_Top_soc_cpu_dpath__io_alu_out;
  Mock_Top_soc_cpu_cpath__io_ctrl_alu_out = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_out;
  Mock_Top_soc_cpu_cpath__io_bus_addr = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_addr;
  Mock_Top_soc_cpu__io_bus_addr = mod_typed->Mock_Top_soc_cpu__io_bus_addr;
  Mock_Top_soc_dev__io_bus_addr = mod_typed->Mock_Top_soc_dev__io_bus_addr;
  Mock_Top_soc_dev_bus__io_from_cpu_addr = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_addr;
  Mock_Top_soc_cpu_cpath__io_bus_we = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_we;
  Mock_Top_soc_cpu__io_bus_we = mod_typed->Mock_Top_soc_cpu__io_bus_we;
  Mock_Top_soc_dev__io_bus_we = mod_typed->Mock_Top_soc_dev__io_bus_we;
  Mock_Top_soc_dev_bus__io_from_cpu_we = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_we;
  Mock_Top_soc_dev_bus__io_slaves_4_we = mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_we;
  Mock_Top_soc_dev_seven_seg__io_bus_we = mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_we;
  Mock_Top_soc_cpu_cpath__io_bus_sel = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_sel;
  Mock_Top_soc_cpu__io_bus_sel = mod_typed->Mock_Top_soc_cpu__io_bus_sel;
  Mock_Top_soc_dev__io_bus_sel = mod_typed->Mock_Top_soc_dev__io_bus_sel;
  Mock_Top_soc_dev_bus__io_from_cpu_sel = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_sel;
  Mock_Top_soc_dev_bus__io_slaves_4_sel = mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_sel;
  Mock_Top_soc_dev_seven_seg__io_bus_sel = mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_sel;
  Mock_Top_soc__reset = mod_typed->Mock_Top_soc__reset;
  Mock_Top_soc_dev__reset = mod_typed->Mock_Top_soc_dev__reset;
  Mock_Top_soc_dev_seven_seg__reset = mod_typed->Mock_Top_soc_dev_seven_seg__reset;
  T183 = mod_typed->T183;
  Mock_Top_soc_dev_seven_seg__data_out = mod_typed->Mock_Top_soc_dev_seven_seg__data_out;
  T185 = mod_typed->T185;
  Mock_Top_soc_dev_seven_seg__disp_data = mod_typed->Mock_Top_soc_dev_seven_seg__disp_data;
  Mock_Top_soc_dev_bus__io_slaves_2_dat2 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_dat2;
  Mock_Top_soc_dev_led__io_bus_dat2 = mod_typed->Mock_Top_soc_dev_led__io_bus_dat2;
  Mock_Top_soc_dev_bus__io_slaves_2_we = mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_we;
  Mock_Top_soc_dev_led__io_bus_we = mod_typed->Mock_Top_soc_dev_led__io_bus_we;
  Mock_Top_soc_dev_bus__io_slaves_2_sel = mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_sel;
  Mock_Top_soc_dev_led__io_bus_sel = mod_typed->Mock_Top_soc_dev_led__io_bus_sel;
  Mock_Top_soc_dev_led__reset = mod_typed->Mock_Top_soc_dev_led__reset;
  T203 = mod_typed->T203;
  Mock_Top_soc_dev_led__data_out = mod_typed->Mock_Top_soc_dev_led__data_out;
  T207 = mod_typed->T207;
  Mock_Top_soc_dev_led__led_data = mod_typed->Mock_Top_soc_dev_led__led_data;
  Mock_Top_soc_cpu__reset = mod_typed->Mock_Top_soc_cpu__reset;
  Mock_Top_soc_cpu_dpath__reset = mod_typed->Mock_Top_soc_cpu_dpath__reset;
  Mock_Top_soc_cpu_dpath_regfile__reset = mod_typed->Mock_Top_soc_cpu_dpath_regfile__reset;
  Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_src = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_src;
  Mock_Top_soc_cpu_dpath__io_reg_we_src = mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we_src;
  Mock_Top_soc_dev_bus__io_ram_slave_addr = mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_addr;
  Mock_Top_soc_dev_ram_dev__io_bus_addr = mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_addr;
  Mock_Top_soc_dev_ram_dev__io_ram_addra = mod_typed->Mock_Top_soc_dev_ram_dev__io_ram_addra;
  Mock_Top_soc_dev__io_devices_RAM_addra = mod_typed->Mock_Top_soc_dev__io_devices_RAM_addra;
  Mock_Top_soc__io_devices_RAM_addra = mod_typed->Mock_Top_soc__io_devices_RAM_addra;
  Mock_Top_ram__io_addra = mod_typed->Mock_Top_ram__io_addra;
  Mock_Top_ram__io_douta = mod_typed->Mock_Top_ram__io_douta;
  Mock_Top_soc__io_devices_RAM_douta = mod_typed->Mock_Top_soc__io_devices_RAM_douta;
  Mock_Top_soc_dev__io_devices_RAM_douta = mod_typed->Mock_Top_soc_dev__io_devices_RAM_douta;
  Mock_Top_soc_dev_ram_dev__io_ram_douta = mod_typed->Mock_Top_soc_dev_ram_dev__io_ram_douta;
  Mock_Top_soc_dev_ram_dev__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_ram_slave_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_dat4;
  Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_7_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_7_dat4;
  Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_6_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_6_dat4;
  Mock_Top_soc_dev_WB_Empty_Dev__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_5_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_5_dat4;
  Mock_Top_soc_dev_seven_seg__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_4_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_dat4;
  Mock_Top_soc_dev_counter__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_counter__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_3_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_3_dat4;
  Mock_Top_soc_dev_led__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_led__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_2_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_dat4;
  Mock_Top__io_devices_BTN = mod_typed->Mock_Top__io_devices_BTN;
  Mock_Top_soc__io_devices_BTN = mod_typed->Mock_Top_soc__io_devices_BTN;
  Mock_Top_soc_dev__io_devices_BTN = mod_typed->Mock_Top_soc_dev__io_devices_BTN;
  Mock_Top_soc_dev_btn__io_BTN = mod_typed->Mock_Top_soc_dev_btn__io_BTN;
  Mock_Top_soc_dev_btn__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_btn__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_1_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_1_dat4;
  Mock_Top__io_devices_SW = mod_typed->Mock_Top__io_devices_SW;
  Mock_Top_soc__io_devices_SW = mod_typed->Mock_Top_soc__io_devices_SW;
  Mock_Top_soc_dev__io_devices_SW = mod_typed->Mock_Top_soc_dev__io_devices_SW;
  Mock_Top_soc_dev_sw__io_SW = mod_typed->Mock_Top_soc_dev_sw__io_SW;
  Mock_Top_soc_dev_sw__io_bus_dat4 = mod_typed->Mock_Top_soc_dev_sw__io_bus_dat4;
  Mock_Top_soc_dev_bus__io_slaves_0_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_slaves_0_dat4;
  Mock_Top_soc_dev_bus__io_from_cpu_dat4 = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_dat4;
  Mock_Top_soc_dev__io_bus_dat4 = mod_typed->Mock_Top_soc_dev__io_bus_dat4;
  Mock_Top_soc_cpu__io_bus_dat4 = mod_typed->Mock_Top_soc_cpu__io_bus_dat4;
  Mock_Top_soc_cpu_cpath__io_bus_dat4 = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_dat4;
  Mock_Top_soc_cpu_cpath__io_ctrl_bus_data = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_bus_data;
  Mock_Top_soc_cpu_dpath__io_bus_data = mod_typed->Mock_Top_soc_cpu_dpath__io_bus_data;
  Mock_Top_soc_cpu_dpath_regfile__io_wtdata = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_wtdata;
  Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_dst = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_dst;
  Mock_Top_soc_cpu_dpath__io_reg_we_dst = mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we_dst;
  Mock_Top_soc_cpu_dpath_regfile__io_wtaddr = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_wtaddr;
  Mock_Top_soc_cpu_cpath__io_ctrl_reg_we = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we;
  Mock_Top_soc_cpu_dpath__io_reg_we = mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we;
  Mock_Top_soc_cpu_dpath_regfile__io_we = mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_we;
  T354 = mod_typed->T354;
  Mock_Top_soc_cpu_dpath_regfile__rf = mod_typed->Mock_Top_soc_cpu_dpath_regfile__rf;
  Mock_Top_soc_cpu_cpath__io_ctrl_inst_we = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_inst_we;
  Mock_Top_soc_cpu_dpath__io_inst_we = mod_typed->Mock_Top_soc_cpu_dpath__io_inst_we;
  T356 = mod_typed->T356;
  Mock_Top_soc_cpu_dpath__inst_reg = mod_typed->Mock_Top_soc_cpu_dpath__inst_reg;
  Mock_Top_soc_cpu_cpath__io_ctrl_pc_next_sel = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_next_sel;
  Mock_Top_soc_cpu_dpath__io_pc_next_sel = mod_typed->Mock_Top_soc_cpu_dpath__io_pc_next_sel;
  Mock_Top_soc_cpu_dpath_alu__io_zero = mod_typed->Mock_Top_soc_cpu_dpath_alu__io_zero;
  Mock_Top_soc_cpu_cpath__io_ctrl_pc_we = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_we;
  Mock_Top_soc_cpu_dpath__io_pc_we = mod_typed->Mock_Top_soc_cpu_dpath__io_pc_we;
  T415 = mod_typed->T415;
  Mock_Top_soc_cpu_dpath__pc = mod_typed->Mock_Top_soc_cpu_dpath__pc;
  Mock_Top_soc_cpu_dpath__io_inst = mod_typed->Mock_Top_soc_cpu_dpath__io_inst;
  Mock_Top_soc_cpu_cpath__io_ctrl_inst = mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_inst;
  Mock_Top_soc_dev_ram_dev__io_bus_ack = mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_ack;
  Mock_Top_soc_dev_bus__io_ram_slave_ack = mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_ack;
  Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_ack = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_7_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_7_ack;
  Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_ack = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_6_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_6_ack;
  Mock_Top_soc_dev_WB_Empty_Dev__io_bus_ack = mod_typed->Mock_Top_soc_dev_WB_Empty_Dev__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_5_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_5_ack;
  Mock_Top_soc_dev_seven_seg__io_bus_ack = mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_4_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_ack;
  Mock_Top_soc_dev_counter__io_bus_ack = mod_typed->Mock_Top_soc_dev_counter__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_3_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_3_ack;
  Mock_Top_soc_dev_led__io_bus_ack = mod_typed->Mock_Top_soc_dev_led__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_2_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_ack;
  Mock_Top_soc_dev_btn__io_bus_ack = mod_typed->Mock_Top_soc_dev_btn__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_1_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_1_ack;
  Mock_Top_soc_dev_sw__io_bus_ack = mod_typed->Mock_Top_soc_dev_sw__io_bus_ack;
  Mock_Top_soc_dev_bus__io_slaves_0_ack = mod_typed->Mock_Top_soc_dev_bus__io_slaves_0_ack;
  Mock_Top_soc_dev_bus__io_from_cpu_ack = mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_ack;
  Mock_Top_soc_dev__io_bus_ack = mod_typed->Mock_Top_soc_dev__io_bus_ack;
  Mock_Top_soc_cpu__io_bus_ack = mod_typed->Mock_Top_soc_cpu__io_bus_ack;
  Mock_Top_soc_cpu_cpath__io_bus_ack = mod_typed->Mock_Top_soc_cpu_cpath__io_bus_ack;
  Mock_Top_soc_cpu_cpath__reset = mod_typed->Mock_Top_soc_cpu_cpath__reset;
  T490 = mod_typed->T490;
  Mock_Top_soc_cpu_cpath__state = mod_typed->Mock_Top_soc_cpu_cpath__state;
  Mock_Top_soc_dev_seven_seg__io_DISP_NUM = mod_typed->Mock_Top_soc_dev_seven_seg__io_DISP_NUM;
  Mock_Top_soc_dev__io_devices_DISP_NUM = mod_typed->Mock_Top_soc_dev__io_devices_DISP_NUM;
  Mock_Top_soc__io_devices_DISP_NUM = mod_typed->Mock_Top_soc__io_devices_DISP_NUM;
  Mock_Top_soc_cpu_cpath__io_debug_inst_out = mod_typed->Mock_Top_soc_cpu_cpath__io_debug_inst_out;
  Mock_Top_soc_cpu__io_debug_inst_out = mod_typed->Mock_Top_soc_cpu__io_debug_inst_out;
  Mock_Top_soc__io_debug_inst_out = mod_typed->Mock_Top_soc__io_debug_inst_out;
  Mock_Top__io_debug_inst_out = mod_typed->Mock_Top__io_debug_inst_out;
  Mock_Top_soc_cpu_cpath__io_debug_bus_addr = mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_addr;
  Mock_Top_soc_cpu__io_debug_bus_addr = mod_typed->Mock_Top_soc_cpu__io_debug_bus_addr;
  Mock_Top_soc__io_debug_bus_addr = mod_typed->Mock_Top_soc__io_debug_bus_addr;
  Mock_Top__io_debug_bus_addr = mod_typed->Mock_Top__io_debug_bus_addr;
  Mock_Top_soc_cpu_cpath__io_debug_bus_dat2 = mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_dat2;
  Mock_Top_soc_cpu__io_debug_bus_dat2 = mod_typed->Mock_Top_soc_cpu__io_debug_bus_dat2;
  Mock_Top_soc__io_debug_bus_dat2 = mod_typed->Mock_Top_soc__io_debug_bus_dat2;
  Mock_Top__io_debug_bus_dat2 = mod_typed->Mock_Top__io_debug_bus_dat2;
  Mock_Top_soc_cpu_cpath__io_debug_bus_dat4 = mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_dat4;
  Mock_Top_soc_cpu__io_debug_bus_dat4 = mod_typed->Mock_Top_soc_cpu__io_debug_bus_dat4;
  Mock_Top_soc__io_debug_bus_dat4 = mod_typed->Mock_Top_soc__io_debug_bus_dat4;
  Mock_Top__io_debug_bus_dat4 = mod_typed->Mock_Top__io_debug_bus_dat4;
  Mock_Top_soc_cpu_cpath__io_debug_pc_out = mod_typed->Mock_Top_soc_cpu_cpath__io_debug_pc_out;
  Mock_Top_soc_cpu__io_debug_pc_out = mod_typed->Mock_Top_soc_cpu__io_debug_pc_out;
  Mock_Top_soc__io_debug_pc_out = mod_typed->Mock_Top_soc__io_debug_pc_out;
  Mock_Top__io_debug_pc_out = mod_typed->Mock_Top__io_debug_pc_out;
  Mock_Top_soc_dev_led__io_LED = mod_typed->Mock_Top_soc_dev_led__io_LED;
  Mock_Top_soc_dev__io_devices_LED = mod_typed->Mock_Top_soc_dev__io_devices_LED;
  Mock_Top_soc__io_devices_LED = mod_typed->Mock_Top_soc__io_devices_LED;
  Mock_Top__io_devices_LED = mod_typed->Mock_Top__io_devices_LED;
  Mock_Top__io_devices_DISP_NUM = mod_typed->Mock_Top__io_devices_DISP_NUM;
  Mock_Top__io_devices_RAM_addra = mod_typed->Mock_Top__io_devices_RAM_addra;
  Mock_Top__io_devices_RAM_dina = mod_typed->Mock_Top__io_devices_RAM_dina;
  Mock_Top__io_devices_RAM_we = mod_typed->Mock_Top__io_devices_RAM_we;
  Mock_Top__io_devices_RAM_douta = mod_typed->Mock_Top__io_devices_RAM_douta;
  T492 = mod_typed->T492;
  T493 = mod_typed->T493;
  T494 = mod_typed->T494;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void Mock_Top_t::print ( FILE* f ) {
#if __cplusplus >= 201103L
  if (T492.values[0]) dat_fprintf<168>(f, " - state: %d\n", T493);
#endif
fflush(f);
}
void Mock_Top_t::print ( std::ostream& s ) {
#if __cplusplus >= 201103L
  if (T492.values[0]) dat_prints<168>(s, " - state: %d\n", T493);
#endif
s.flush();
}


void Mock_Top_t::dump_init ( FILE* f ) {
}


void Mock_Top_t::dump ( FILE* f, int t ) {
}




void Mock_Top_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = Mock_Top_soc_cpu_dpath__inst_reg.values[0] >> 16;}
  T0 = T0 & 0x1fL;
  { Mock_Top_soc_cpu_dpath_regfile__io_addrb.values[0] = T0;}
  val_t T1;
  { T1 = Mock_Top_soc_cpu_dpath_regfile__rf.get(Mock_Top_soc_cpu_dpath_regfile__io_addrb.values[0], 0);}
  { Mock_Top_soc_cpu_dpath_regfile__io_doutb.values[0] = T1;}
  { Mock_Top_soc_cpu_dpath__io_data_out.values[0] = Mock_Top_soc_cpu_dpath_regfile__io_doutb.values[0];}
  { Mock_Top_soc_cpu_cpath__io_ctrl_data_out.values[0] = Mock_Top_soc_cpu_dpath__io_data_out.values[0];}
  { Mock_Top_soc_cpu_cpath__io_bus_dat2.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_data_out.values[0];}
  { Mock_Top_soc_cpu__io_bus_dat2.values[0] = Mock_Top_soc_cpu_cpath__io_bus_dat2.values[0];}
  { Mock_Top_soc_dev__io_bus_dat2.values[0] = Mock_Top_soc_cpu__io_bus_dat2.values[0];}
  { Mock_Top_soc_dev_bus__io_from_cpu_dat2.values[0] = Mock_Top_soc_dev__io_bus_dat2.values[0];}
  { Mock_Top_soc_dev_bus__io_slaves_4_dat2.values[0] = Mock_Top_soc_dev_bus__io_from_cpu_dat2.values[0];}
  { Mock_Top_soc_dev_seven_seg__io_bus_dat2.values[0] = Mock_Top_soc_dev_bus__io_slaves_4_dat2.values[0];}
  { Mock_Top_soc_cpu_dpath__io_pc_out.values[0] = Mock_Top_soc_cpu_dpath__pc.values[0];}
  { Mock_Top_soc_cpu_cpath__io_ctrl_pc_out.values[0] = Mock_Top_soc_cpu_dpath__io_pc_out.values[0];}
  val_t T2;
  T2 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x13L;
  val_t T3;
  T3 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x12L;
  val_t T4;
  { T4 = TERNARY(T3, 0x1L, T2);}
  val_t T5;
  T5 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x11L;
  val_t T6;
  { T6 = TERNARY(T5, 0x0L, T4);}
  val_t T7;
  T7 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x10L;
  val_t T8;
  { T8 = TERNARY(T7, 0x0L, T6);}
  val_t T9;
  T9 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xfL;
  val_t T10;
  { T10 = TERNARY(T9, 0x0L, T8);}
  val_t T11;
  T11 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xeL;
  val_t T12;
  { T12 = TERNARY(T11, 0x0L, T10);}
  val_t T13;
  T13 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xdL;
  val_t T14;
  { T14 = TERNARY(T13, 0x0L, T12);}
  val_t T15;
  T15 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xcL;
  val_t T16;
  { T16 = TERNARY(T15, 0x0L, T14);}
  val_t T17;
  T17 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xbL;
  val_t T18;
  { T18 = TERNARY(T17, 0x0L, T16);}
  val_t T19;
  T19 = Mock_Top_soc_cpu_cpath__state.values[0] == 0xaL;
  val_t T20;
  { T20 = TERNARY(T19, 0x0L, T18);}
  val_t T21;
  T21 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x9L;
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T20);}
  val_t T23;
  T23 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x8L;
  val_t T24;
  { T24 = TERNARY(T23, 0x0L, T22);}
  val_t T25;
  T25 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x7L;
  val_t T26;
  { T26 = TERNARY(T25, 0x0L, T24);}
  val_t T27;
  T27 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x6L;
  val_t T28;
  { T28 = TERNARY(T27, 0x0L, T26);}
  val_t T29;
  T29 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x5L;
  val_t T30;
  { T30 = TERNARY(T29, 0x0L, T28);}
  val_t T31;
  T31 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x4L;
  val_t T32;
  { T32 = TERNARY(T31, 0x0L, T30);}
  val_t T33;
  T33 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x3L;
  val_t T34;
  { T34 = TERNARY(T33, 0x0L, T32);}
  val_t T35;
  T35 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x2L;
  val_t T36;
  { T36 = TERNARY(T35, 0x0L, T34);}
  val_t T37;
  T37 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x1L;
  val_t T38;
  { T38 = TERNARY(T37, 0x0L, T36);}
  val_t Mock_Top_soc_cpu_cpath__inst_we;
  Mock_Top_soc_cpu_cpath__inst_we = Mock_Top_soc_cpu_cpath__state.values[0] == 0x0L;
  val_t Mock_Top_soc_cpu_cpath__bus_addr_src;
  { Mock_Top_soc_cpu_cpath__bus_addr_src = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T38);}
  val_t T39;
  T39 = Mock_Top_soc_cpu_cpath__bus_addr_src == 0x0L;
  val_t T40;
  { T40 = TERNARY(T39, Mock_Top_soc_cpu_cpath__io_ctrl_pc_out.values[0], 0x0L);}
  val_t T41;
  { T41 = ~Mock_Top_soc_cpu_dpath_regfile__io_doutb.values[0];}
  T41 = T41 & 0xffffffffL;
  val_t T42;
  T42 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x16L;
  val_t T43;
  { T43 = T42 | 0x0L << 1;}
  val_t T44;
  T44 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x15L;
  val_t T45;
  { T45 = TERNARY(T44, 0x2L, T43);}
  val_t T46;
  T46 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x14L;
  val_t T47;
  { T47 = TERNARY(T46, 0x0L, T45);}
  val_t T48;
  { T48 = TERNARY(T2, 0x1L, T47);}
  val_t T49;
  { T49 = TERNARY(T3, 0x1L, T48);}
  val_t T50;
  { T50 = TERNARY(T5, 0x1L, T49);}
  val_t T51;
  { T51 = TERNARY(T7, 0x1L, T50);}
  val_t T52;
  { T52 = TERNARY(T9, 0x1L, T51);}
  val_t T53;
  { T53 = TERNARY(T11, 0x1L, T52);}
  val_t T54;
  { T54 = TERNARY(T13, 0x1L, T53);}
  val_t T55;
  { T55 = TERNARY(T15, 0x1L, T54);}
  val_t T56;
  { T56 = TERNARY(T17, 0x0L, T55);}
  val_t T57;
  { T57 = TERNARY(T19, 0x0L, T56);}
  val_t T58;
  { T58 = TERNARY(T21, 0x0L, T57);}
  val_t T59;
  { T59 = TERNARY(T23, 0x0L, T58);}
  val_t T60;
  { T60 = TERNARY(T25, 0x0L, T59);}
  val_t T61;
  { T61 = TERNARY(T27, 0x0L, T60);}
  val_t T62;
  { T62 = TERNARY(T29, 0x0L, T61);}
  val_t T63;
  { T63 = TERNARY(T31, 0x0L, T62);}
  val_t T64;
  { T64 = TERNARY(T33, 0x0L, T63);}
  val_t T65;
  { T65 = TERNARY(T35, 0x0L, T64);}
  val_t T66;
  { T66 = TERNARY(T37, 0x0L, T65);}
  val_t Mock_Top_soc_cpu_cpath__alu_b_sel;
  { Mock_Top_soc_cpu_cpath__alu_b_sel = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T66);}
  val_t T67;
  T67 = (Mock_Top_soc_cpu_cpath__alu_b_sel >> 0) & 1;
  { Mock_Top_soc_cpu_cpath__io_ctrl_alu_b_sel.values[0] = T67;}
  { Mock_Top_soc_cpu_dpath__io_alu_b_sel.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_alu_b_sel.values[0];}
  val_t T68;
  { T68 = Mock_Top_soc_cpu_dpath__io_alu_b_sel.values[0] | 0x0L << 1;}
  val_t T69;
  T69 = T68 == 0x2L;
  val_t T70;
  { T70 = TERNARY(T69, T41, 0x0L);}
  val_t T71;
  { T71 = Mock_Top_soc_cpu_dpath__inst_reg.values[0];}
  T71 = T71 & 0xffffL;
  val_t T72;
  { T72 = T71 | 0x0L << 16;}
  val_t T73;
  T73 = Mock_Top_soc_cpu_dpath__io_alu_b_sel.values[0] == 0x1L;
  val_t T74;
  { T74 = TERNARY_1(T73, T72, T70);}
  val_t T75;
  T75 = Mock_Top_soc_cpu_dpath__io_alu_b_sel.values[0] == 0x0L;
  val_t T76;
  { T76 = TERNARY_1(T75, Mock_Top_soc_cpu_dpath_regfile__io_doutb.values[0], T74);}
  { Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0] = T76;}
  val_t T77;
  { T77 = Mock_Top_soc_cpu_dpath__inst_reg.values[0] >> 21;}
  T77 = T77 & 0x1fL;
  { Mock_Top_soc_cpu_dpath_regfile__io_addra.values[0] = T77;}
  val_t T78;
  { T78 = Mock_Top_soc_cpu_dpath_regfile__rf.get(Mock_Top_soc_cpu_dpath_regfile__io_addra.values[0], 0);}
  { Mock_Top_soc_cpu_dpath_regfile__io_douta.values[0] = T78;}
  { Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] = Mock_Top_soc_cpu_dpath_regfile__io_douta.values[0];}
  val_t T79;
  T79 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0]<Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];
  val_t T80;
  { T80 = T79 | 0x0L << 1;}
  val_t T81;
  { T81 = TERNARY(T42, 0x7L, 0x0L);}
  val_t T82;
  { T82 = TERNARY(T44, 0x4L, T81);}
  val_t T83;
  { T83 = TERNARY(T46, 0x6L, T82);}
  val_t T84;
  { T84 = TERNARY(T2, 0x2L, T83);}
  val_t T85;
  { T85 = TERNARY(T3, 0x2L, T84);}
  val_t T86;
  { T86 = TERNARY(T5, 0x2L, T85);}
  val_t T87;
  { T87 = TERNARY(T7, 0x3L, T86);}
  val_t T88;
  { T88 = TERNARY(T9, 0x1L, T87);}
  val_t T89;
  { T89 = TERNARY(T11, 0x0L, T88);}
  val_t T90;
  { T90 = TERNARY(T13, 0x2L, T89);}
  val_t T91;
  { T91 = TERNARY(T15, 0x2L, T90);}
  val_t T92;
  { T92 = TERNARY(T17, 0x0L, T91);}
  val_t T93;
  { T93 = TERNARY(T19, 0x5L, T92);}
  val_t T94;
  { T94 = TERNARY(T21, 0x7L, T93);}
  val_t T95;
  { T95 = TERNARY(T23, 0x4L, T94);}
  val_t T96;
  { T96 = TERNARY(T25, 0x3L, T95);}
  val_t T97;
  { T97 = TERNARY(T27, 0x1L, T96);}
  val_t T98;
  { T98 = TERNARY(T29, 0x0L, T97);}
  val_t T99;
  { T99 = TERNARY(T31, 0x6L, T98);}
  val_t T100;
  { T100 = TERNARY(T33, 0x6L, T99);}
  val_t T101;
  { T101 = TERNARY(T35, 0x2L, T100);}
  val_t T102;
  { T102 = TERNARY(T37, 0x2L, T101);}
  val_t Mock_Top_soc_cpu_cpath__alu_op;
  { Mock_Top_soc_cpu_cpath__alu_op = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T102);}
  { Mock_Top_soc_cpu_cpath__io_ctrl_alu_op.values[0] = Mock_Top_soc_cpu_cpath__alu_op;}
  { Mock_Top_soc_cpu_dpath__io_alu_op.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_alu_op.values[0];}
  { Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] = Mock_Top_soc_cpu_dpath__io_alu_op.values[0];}
  val_t T103;
  T103 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x7L;
  val_t T104;
  { T104 = TERNARY(T103, T80, 0x0L);}
  val_t T105;
  { T105 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0]-Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  T105 = T105 & 0xffffffffL;
  val_t T106;
  T106 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x6L;
  val_t T107;
  { T107 = TERNARY_1(T106, T105, T104);}
  val_t T108;
  { T108 = Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  T108 = T108 & 0x1fL;
  val_t T109;
  T109 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] >> T108;
  val_t T110;
  T110 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x5L;
  val_t T111;
  { T111 = TERNARY_1(T110, T109, T107);}
  val_t T112;
  { T112 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] | Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  val_t T113;
  { T113 = ~T112;}
  T113 = T113 & 0xffffffffL;
  val_t T114;
  T114 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x4L;
  val_t T115;
  { T115 = TERNARY_1(T114, T113, T111);}
  val_t T116;
  { T116 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] ^ Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  val_t T117;
  T117 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x3L;
  val_t T118;
  { T118 = TERNARY_1(T117, T116, T115);}
  val_t T119;
  { T119 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0]+Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  T119 = T119 & 0xffffffffL;
  val_t T120;
  T120 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x2L;
  val_t T121;
  { T121 = TERNARY_1(T120, T119, T118);}
  val_t T122;
  { T122 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] | Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  val_t T123;
  T123 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x1L;
  val_t T124;
  { T124 = TERNARY_1(T123, T122, T121);}
  val_t T125;
  { T125 = Mock_Top_soc_cpu_dpath_alu__io_in_a.values[0] & Mock_Top_soc_cpu_dpath_alu__io_in_b.values[0];}
  val_t T126;
  T126 = Mock_Top_soc_cpu_dpath_alu__io_alu_op.values[0] == 0x0L;
  val_t T127;
  { T127 = TERNARY_1(T126, T125, T124);}
  { Mock_Top_soc_cpu_dpath_alu__io_out.values[0] = T127;}
  { Mock_Top_soc_cpu_dpath__io_alu_out.values[0] = Mock_Top_soc_cpu_dpath_alu__io_out.values[0];}
  { Mock_Top_soc_cpu_cpath__io_ctrl_alu_out.values[0] = Mock_Top_soc_cpu_dpath__io_alu_out.values[0];}
  val_t T128;
  T128 = Mock_Top_soc_cpu_cpath__bus_addr_src == 0x1L;
  val_t T129;
  { T129 = TERNARY_1(T128, Mock_Top_soc_cpu_cpath__io_ctrl_alu_out.values[0], T40);}
  { Mock_Top_soc_cpu_cpath__io_bus_addr.values[0] = T129;}
  { Mock_Top_soc_cpu__io_bus_addr.values[0] = Mock_Top_soc_cpu_cpath__io_bus_addr.values[0];}
  { Mock_Top_soc_dev__io_bus_addr.values[0] = Mock_Top_soc_cpu__io_bus_addr.values[0];}
  { Mock_Top_soc_dev_bus__io_from_cpu_addr.values[0] = Mock_Top_soc_dev__io_bus_addr.values[0];}
  val_t Mock_Top_soc_dev_bus__current_slave;
  { Mock_Top_soc_dev_bus__current_slave = Mock_Top_soc_dev_bus__io_from_cpu_addr.values[0] >> 28;}
  Mock_Top_soc_dev_bus__current_slave = Mock_Top_soc_dev_bus__current_slave & 0x7L;
  val_t T130;
  T130 = Mock_Top_soc_dev_bus__current_slave == 0x4L;
  val_t T131;
  { T131 = TERNARY(T3, 0x0L, T2);}
  val_t T132;
  { T132 = TERNARY(T5, 0x0L, T131);}
  val_t T133;
  { T133 = TERNARY(T7, 0x0L, T132);}
  val_t T134;
  { T134 = TERNARY(T9, 0x0L, T133);}
  val_t T135;
  { T135 = TERNARY(T11, 0x0L, T134);}
  val_t T136;
  { T136 = TERNARY(T13, 0x0L, T135);}
  val_t T137;
  { T137 = TERNARY(T15, 0x0L, T136);}
  val_t T138;
  { T138 = TERNARY(T17, 0x0L, T137);}
  val_t T139;
  { T139 = TERNARY(T19, 0x0L, T138);}
  val_t T140;
  { T140 = TERNARY(T21, 0x0L, T139);}
  val_t T141;
  { T141 = TERNARY(T23, 0x0L, T140);}
  val_t T142;
  { T142 = TERNARY(T25, 0x0L, T141);}
  val_t T143;
  { T143 = TERNARY(T27, 0x0L, T142);}
  val_t T144;
  { T144 = TERNARY(T29, 0x0L, T143);}
  val_t T145;
  { T145 = TERNARY(T31, 0x0L, T144);}
  val_t T146;
  { T146 = TERNARY(T33, 0x0L, T145);}
  val_t T147;
  { T147 = TERNARY(T35, 0x0L, T146);}
  val_t T148;
  { T148 = TERNARY(T37, 0x0L, T147);}
  val_t Mock_Top_soc_cpu_cpath__bus_we;
  { Mock_Top_soc_cpu_cpath__bus_we = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T148);}
  { Mock_Top_soc_cpu_cpath__io_bus_we.values[0] = Mock_Top_soc_cpu_cpath__bus_we;}
  { Mock_Top_soc_cpu__io_bus_we.values[0] = Mock_Top_soc_cpu_cpath__io_bus_we.values[0];}
  { Mock_Top_soc_dev__io_bus_we.values[0] = Mock_Top_soc_cpu__io_bus_we.values[0];}
  { Mock_Top_soc_dev_bus__io_from_cpu_we.values[0] = Mock_Top_soc_dev__io_bus_we.values[0];}
  val_t T149;
  T149 = (Mock_Top_soc_dev_bus__io_from_cpu_addr.values[0] >> 31) & 1;
  val_t Mock_Top_soc_dev_bus__ram_op;
  { Mock_Top_soc_dev_bus__ram_op = ~T149;}
  Mock_Top_soc_dev_bus__ram_op = Mock_Top_soc_dev_bus__ram_op & 0x1L;
  val_t T150;
  { T150 = ~Mock_Top_soc_dev_bus__ram_op;}
  T150 = T150 & 0x1L;
  val_t T151;
  { T151 = T150 & Mock_Top_soc_dev_bus__io_from_cpu_we.values[0];}
  val_t T152;
  { T152 = T151 & T130;}
  { Mock_Top_soc_dev_bus__io_slaves_4_we.values[0] = T152;}
  { Mock_Top_soc_dev_seven_seg__io_bus_we.values[0] = Mock_Top_soc_dev_bus__io_slaves_4_we.values[0];}
  val_t T153;
  T153 = Mock_Top_soc_dev_bus__current_slave == 0x4L;
  val_t T154;
  { T154 = TERNARY(T3, 0x1L, T2);}
  val_t T155;
  { T155 = TERNARY(T5, 0x0L, T154);}
  val_t T156;
  { T156 = TERNARY(T7, 0x0L, T155);}
  val_t T157;
  { T157 = TERNARY(T9, 0x0L, T156);}
  val_t T158;
  { T158 = TERNARY(T11, 0x0L, T157);}
  val_t T159;
  { T159 = TERNARY(T13, 0x0L, T158);}
  val_t T160;
  { T160 = TERNARY(T15, 0x0L, T159);}
  val_t T161;
  { T161 = TERNARY(T17, 0x0L, T160);}
  val_t T162;
  { T162 = TERNARY(T19, 0x0L, T161);}
  val_t T163;
  { T163 = TERNARY(T21, 0x0L, T162);}
  val_t T164;
  { T164 = TERNARY(T23, 0x0L, T163);}
  val_t T165;
  { T165 = TERNARY(T25, 0x0L, T164);}
  val_t T166;
  { T166 = TERNARY(T27, 0x0L, T165);}
  val_t T167;
  { T167 = TERNARY(T29, 0x0L, T166);}
  val_t T168;
  { T168 = TERNARY(T31, 0x0L, T167);}
  val_t T169;
  { T169 = TERNARY(T33, 0x0L, T168);}
  val_t T170;
  { T170 = TERNARY(T35, 0x0L, T169);}
  val_t T171;
  { T171 = TERNARY(T37, 0x0L, T170);}
  val_t Mock_Top_soc_cpu_cpath__bus_sel;
  { Mock_Top_soc_cpu_cpath__bus_sel = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x1L, T171);}
  { Mock_Top_soc_cpu_cpath__io_bus_sel.values[0] = Mock_Top_soc_cpu_cpath__bus_sel;}
  { Mock_Top_soc_cpu__io_bus_sel.values[0] = Mock_Top_soc_cpu_cpath__io_bus_sel.values[0];}
  { Mock_Top_soc_dev__io_bus_sel.values[0] = Mock_Top_soc_cpu__io_bus_sel.values[0];}
  { Mock_Top_soc_dev_bus__io_from_cpu_sel.values[0] = Mock_Top_soc_dev__io_bus_sel.values[0];}
  val_t T172;
  { T172 = ~Mock_Top_soc_dev_bus__ram_op;}
  T172 = T172 & 0x1L;
  val_t T173;
  { T173 = T172 & Mock_Top_soc_dev_bus__io_from_cpu_sel.values[0];}
  val_t T174;
  { T174 = T173 & T153;}
  { Mock_Top_soc_dev_bus__io_slaves_4_sel.values[0] = T174;}
  { Mock_Top_soc_dev_seven_seg__io_bus_sel.values[0] = Mock_Top_soc_dev_bus__io_slaves_4_sel.values[0];}
  val_t T175;
  { T175 = Mock_Top_soc_dev_seven_seg__io_bus_sel.values[0] & Mock_Top_soc_dev_seven_seg__io_bus_we.values[0];}
  val_t T176;
  { T176 = TERNARY_1(T175, Mock_Top_soc_dev_seven_seg__io_bus_dat2.values[0], Mock_Top_soc_dev_seven_seg__data_out.values[0]);}
  val_t T177;
  { T177 = T175 ^ 0x1L;}
  val_t T178;
  { T178 = T177 & Mock_Top_soc_dev_seven_seg__io_bus_sel.values[0];}
  val_t T179;
  { T179 = TERNARY_1(T178, Mock_Top_soc_dev_seven_seg__disp_data.values[0], T176);}
  val_t T180;
  { T180 = T175 | Mock_Top_soc_dev_seven_seg__io_bus_sel.values[0];}
  val_t T181;
  { T181 = T180 ^ 0x1L;}
  val_t T182;
  { T182 = TERNARY(T181, 0x0L, T179);}
  { Mock_Top_soc__reset.values[0] = reset.values[0];}
  { Mock_Top_soc_dev__reset.values[0] = Mock_Top_soc__reset.values[0];}
  { Mock_Top_soc_dev_seven_seg__reset.values[0] = Mock_Top_soc_dev__reset.values[0];}
  { T183.values[0] = TERNARY(Mock_Top_soc_dev_seven_seg__reset.values[0], 0x0L, T182);}
  val_t T184;
  { T184 = TERNARY_1(T175, Mock_Top_soc_dev_seven_seg__io_bus_dat2.values[0], Mock_Top_soc_dev_seven_seg__disp_data.values[0]);}
  { T185.values[0] = TERNARY(Mock_Top_soc_dev_seven_seg__reset.values[0], 0x0L, T184);}
  { Mock_Top_soc_dev_bus__io_slaves_2_dat2.values[0] = Mock_Top_soc_dev_bus__io_from_cpu_dat2.values[0];}
  { Mock_Top_soc_dev_led__io_bus_dat2.values[0] = Mock_Top_soc_dev_bus__io_slaves_2_dat2.values[0];}
  val_t T186;
  T186 = Mock_Top_soc_dev_bus__current_slave == 0x2L;
  val_t T187;
  { T187 = ~Mock_Top_soc_dev_bus__ram_op;}
  T187 = T187 & 0x1L;
  val_t T188;
  { T188 = T187 & Mock_Top_soc_dev_bus__io_from_cpu_we.values[0];}
  val_t T189;
  { T189 = T188 & T186;}
  { Mock_Top_soc_dev_bus__io_slaves_2_we.values[0] = T189;}
  { Mock_Top_soc_dev_led__io_bus_we.values[0] = Mock_Top_soc_dev_bus__io_slaves_2_we.values[0];}
  val_t T190;
  T190 = Mock_Top_soc_dev_bus__current_slave == 0x2L;
  val_t T191;
  { T191 = ~Mock_Top_soc_dev_bus__ram_op;}
  T191 = T191 & 0x1L;
  val_t T192;
  { T192 = T191 & Mock_Top_soc_dev_bus__io_from_cpu_sel.values[0];}
  val_t T193;
  { T193 = T192 & T190;}
  { Mock_Top_soc_dev_bus__io_slaves_2_sel.values[0] = T193;}
  { Mock_Top_soc_dev_led__io_bus_sel.values[0] = Mock_Top_soc_dev_bus__io_slaves_2_sel.values[0];}
  val_t T194;
  { T194 = Mock_Top_soc_dev_led__io_bus_sel.values[0] & Mock_Top_soc_dev_led__io_bus_we.values[0];}
  val_t T195;
  { T195 = TERNARY_1(T194, Mock_Top_soc_dev_led__io_bus_dat2.values[0], Mock_Top_soc_dev_led__data_out.values[0]);}
  val_t T196;
  { T196 = Mock_Top_soc_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T197;
  { T197 = T194 ^ 0x1L;}
  val_t T198;
  { T198 = T197 & Mock_Top_soc_dev_led__io_bus_sel.values[0];}
  val_t T199;
  { T199 = TERNARY_1(T198, T196, T195);}
  val_t T200;
  { T200 = T194 | Mock_Top_soc_dev_led__io_bus_sel.values[0];}
  val_t T201;
  { T201 = T200 ^ 0x1L;}
  val_t T202;
  { T202 = TERNARY(T201, 0x0L, T199);}
  { Mock_Top_soc_dev_led__reset.values[0] = Mock_Top_soc_dev__reset.values[0];}
  { T203.values[0] = TERNARY(Mock_Top_soc_dev_led__reset.values[0], 0x0L, T202);}
  val_t T204;
  { T204 = Mock_Top_soc_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T205;
  { T205 = TERNARY_1(T194, Mock_Top_soc_dev_led__io_bus_dat2.values[0], T204);}
  val_t T206;
  { T206 = TERNARY(Mock_Top_soc_dev_led__reset.values[0], 0x0L, T205);}
  { T207.values[0] = T206;}
  T207.values[0] = T207.values[0] & 0xffL;
  { Mock_Top_soc_cpu__reset.values[0] = Mock_Top_soc__reset.values[0];}
  { Mock_Top_soc_cpu_dpath__reset.values[0] = Mock_Top_soc_cpu__reset.values[0];}
  { Mock_Top_soc_cpu_dpath_regfile__reset.values[0] = Mock_Top_soc_cpu_dpath__reset.values[0];}
  val_t T208;
  T208 = Mock_Top_soc_cpu_dpath_alu__io_out.values[0] << 0x10L;
  T208 = T208 & 0xffffffffffffL;
  val_t T209;
  T209 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x18L;
  val_t T210;
  { T210 = TERNARY(T209, 0x2L, 0x0L);}
  val_t T211;
  T211 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x17L;
  val_t T212;
  { T212 = TERNARY(T211, 0x0L, T210);}
  val_t T213;
  { T213 = TERNARY(T42, 0x0L, T212);}
  val_t T214;
  { T214 = TERNARY(T44, 0x0L, T213);}
  val_t T215;
  { T215 = TERNARY(T46, 0x0L, T214);}
  val_t T216;
  { T216 = TERNARY(T2, 0x0L, T215);}
  val_t T217;
  { T217 = TERNARY(T3, 0x1L, T216);}
  val_t T218;
  { T218 = TERNARY(T5, 0x3L, T217);}
  val_t T219;
  { T219 = TERNARY(T7, 0x0L, T218);}
  val_t T220;
  { T220 = TERNARY(T9, 0x0L, T219);}
  val_t T221;
  { T221 = TERNARY(T11, 0x0L, T220);}
  val_t T222;
  { T222 = TERNARY(T13, 0x0L, T221);}
  val_t T223;
  { T223 = TERNARY(T15, 0x0L, T222);}
  val_t T224;
  { T224 = TERNARY(T17, 0x0L, T223);}
  val_t T225;
  { T225 = TERNARY(T19, 0x0L, T224);}
  val_t T226;
  { T226 = TERNARY(T21, 0x0L, T225);}
  val_t T227;
  { T227 = TERNARY(T23, 0x0L, T226);}
  val_t T228;
  { T228 = TERNARY(T25, 0x0L, T227);}
  val_t T229;
  { T229 = TERNARY(T27, 0x0L, T228);}
  val_t T230;
  { T230 = TERNARY(T29, 0x0L, T229);}
  val_t T231;
  { T231 = TERNARY(T31, 0x0L, T230);}
  val_t T232;
  { T232 = TERNARY(T33, 0x0L, T231);}
  val_t T233;
  { T233 = TERNARY(T35, 0x0L, T232);}
  val_t T234;
  { T234 = TERNARY(T37, 0x0L, T233);}
  val_t Mock_Top_soc_cpu_cpath__reg_we_src;
  { Mock_Top_soc_cpu_cpath__reg_we_src = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T234);}
  { Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_src.values[0] = Mock_Top_soc_cpu_cpath__reg_we_src;}
  { Mock_Top_soc_cpu_dpath__io_reg_we_src.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_src.values[0];}
  val_t T235;
  T235 = Mock_Top_soc_cpu_dpath__io_reg_we_src.values[0] == 0x3L;
  val_t T236;
  { T236 = TERNARY(T235, T208, 0x0L);}
  val_t T237;
  { T237 = Mock_Top_soc_cpu_dpath__pc.values[0]+0x4L;}
  T237 = T237 & 0xffffffffL;
  val_t T238;
  { T238 = T237 | 0x0L << 32;}
  val_t T239;
  T239 = Mock_Top_soc_cpu_dpath__io_reg_we_src.values[0] == 0x2L;
  val_t T240;
  { T240 = TERNARY_1(T239, T238, T236);}
  val_t T241;
  { T241 = Mock_Top_soc_dev_bus__io_from_cpu_addr.values[0];}
  T241 = T241 & 0xfffffffL;
  val_t T242;
  { T242 = T241 | 0x0L << 28;}
  { Mock_Top_soc_dev_bus__io_ram_slave_addr.values[0] = T242;}
  { Mock_Top_soc_dev_ram_dev__io_bus_addr.values[0] = Mock_Top_soc_dev_bus__io_ram_slave_addr.values[0];}
  val_t T243;
  { T243 = Mock_Top_soc_dev_ram_dev__io_bus_addr.values[0] >> 2;}
  T243 = T243 & 0x3ffL;
  { Mock_Top_soc_dev_ram_dev__io_ram_addra.values[0] = T243;}
  { Mock_Top_soc_dev__io_devices_RAM_addra.values[0] = Mock_Top_soc_dev_ram_dev__io_ram_addra.values[0];}
  { Mock_Top_soc__io_devices_RAM_addra.values[0] = Mock_Top_soc_dev__io_devices_RAM_addra.values[0];}
  { Mock_Top_ram__io_addra.values[0] = Mock_Top_soc__io_devices_RAM_addra.values[0];}
  val_t T244;
  T244 = Mock_Top_ram__io_addra.values[0] == 0x4L;
  val_t T245;
  { T245 = TERNARY(T244, 0x8000002L, 0x0L);}
  val_t T246;
  T246 = Mock_Top_ram__io_addra.values[0] == 0x3L;
  val_t T247;
  { T247 = TERNARY(T246, 0xac430000L, T245);}
  val_t T248;
  T248 = Mock_Top_ram__io_addra.values[0] == 0x2L;
  val_t T249;
  { T249 = TERNARY(T248, 0x8c230000L, T247);}
  val_t T250;
  T250 = Mock_Top_ram__io_addra.values[0] == 0x1L;
  val_t T251;
  { T251 = TERNARY(T250, 0x3c018000L, T249);}
  val_t T252;
  T252 = Mock_Top_ram__io_addra.values[0] == 0x0L;
  val_t T253;
  { T253 = TERNARY(T252, 0x3c02a000L, T251);}
  { Mock_Top_ram__io_douta.values[0] = T253;}
  { Mock_Top_soc__io_devices_RAM_douta.values[0] = Mock_Top_ram__io_douta.values[0];}
  { Mock_Top_soc_dev__io_devices_RAM_douta.values[0] = Mock_Top_soc__io_devices_RAM_douta.values[0];}
  { Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0] = Mock_Top_soc_dev__io_devices_RAM_douta.values[0];}
  val_t T254;
  { T254 = Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0] >> 24;}
  T254 = T254 & 0xffL;
  val_t T255;
  { T255 = T254 | 0x0L << 8;}
  val_t T256;
  { T256 = Mock_Top_soc_dev_ram_dev__io_bus_addr.values[0];}
  T256 = T256 & 0x3L;
  val_t T257;
  T257 = T256 == 0x3L;
  val_t T258;
  { T258 = TERNARY_1(T257, T255, Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0]);}
  val_t T259;
  { T259 = Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0] >> 16;}
  T259 = T259 & 0xffffL;
  val_t T260;
  { T260 = T259 | 0x0L << 16;}
  val_t T261;
  T261 = T256 == 0x2L;
  val_t T262;
  { T262 = TERNARY_1(T261, T260, T258);}
  val_t T263;
  { T263 = Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0] >> 8;}
  T263 = T263 & 0xffffffL;
  val_t T264;
  { T264 = T263 | 0x0L << 24;}
  val_t T265;
  T265 = T256 == 0x1L;
  val_t T266;
  { T266 = TERNARY_1(T265, T264, T262);}
  val_t T267;
  T267 = T256 == 0x0L;
  val_t T268;
  { T268 = TERNARY_1(T267, Mock_Top_soc_dev_ram_dev__io_ram_douta.values[0], T266);}
  { Mock_Top_soc_dev_ram_dev__io_bus_dat4.values[0] = T268;}
  { Mock_Top_soc_dev_bus__io_ram_slave_dat4.values[0] = Mock_Top_soc_dev_ram_dev__io_bus_dat4.values[0];}
  val_t T269;
  T269 = Mock_Top_soc_dev_bus__ram_op == 0x1L;
  val_t T270;
  { T270 = TERNARY(T269, Mock_Top_soc_dev_bus__io_ram_slave_dat4.values[0], 0x0L);}
  { Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_dat4.values[0] = 0x0L;}
  { Mock_Top_soc_dev_bus__io_slaves_7_dat4.values[0] = Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_dat4.values[0];}
  val_t T271;
  T271 = Mock_Top_soc_dev_bus__current_slave == 0x7L;
  val_t T272;
  { T272 = TERNARY(T271, Mock_Top_soc_dev_bus__io_slaves_7_dat4.values[0], 0x0L);}
  { Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_dat4.values[0] = 0x0L;}
  { Mock_Top_soc_dev_bus__io_slaves_6_dat4.values[0] = Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_dat4.values[0];}
  val_t T273;
  T273 = Mock_Top_soc_dev_bus__current_slave == 0x6L;
  val_t T274;
  { T274 = TERNARY(T273, Mock_Top_soc_dev_bus__io_slaves_6_dat4.values[0], T272);}
  { Mock_Top_soc_dev_WB_Empty_Dev__io_bus_dat4.values[0] = 0x0L;}
  { Mock_Top_soc_dev_bus__io_slaves_5_dat4.values[0] = Mock_Top_soc_dev_WB_Empty_Dev__io_bus_dat4.values[0];}
  val_t T275;
  T275 = Mock_Top_soc_dev_bus__current_slave == 0x5L;
  val_t T276;
  { T276 = TERNARY(T275, Mock_Top_soc_dev_bus__io_slaves_5_dat4.values[0], T274);}
  { Mock_Top_soc_dev_seven_seg__io_bus_dat4.values[0] = Mock_Top_soc_dev_seven_seg__data_out.values[0];}
  { Mock_Top_soc_dev_bus__io_slaves_4_dat4.values[0] = Mock_Top_soc_dev_seven_seg__io_bus_dat4.values[0];}
  val_t T277;
  T277 = Mock_Top_soc_dev_bus__current_slave == 0x4L;
  val_t T278;
  { T278 = TERNARY_1(T277, Mock_Top_soc_dev_bus__io_slaves_4_dat4.values[0], T276);}
  { Mock_Top_soc_dev_counter__io_bus_dat4.values[0] = 0x0L;}
  { Mock_Top_soc_dev_bus__io_slaves_3_dat4.values[0] = Mock_Top_soc_dev_counter__io_bus_dat4.values[0];}
  val_t T279;
  T279 = Mock_Top_soc_dev_bus__current_slave == 0x3L;
  val_t T280;
  { T280 = TERNARY(T279, Mock_Top_soc_dev_bus__io_slaves_3_dat4.values[0], T278);}
  { Mock_Top_soc_dev_led__io_bus_dat4.values[0] = Mock_Top_soc_dev_led__data_out.values[0];}
  { Mock_Top_soc_dev_bus__io_slaves_2_dat4.values[0] = Mock_Top_soc_dev_led__io_bus_dat4.values[0];}
  val_t T281;
  T281 = Mock_Top_soc_dev_bus__current_slave == 0x2L;
  val_t T282;
  { T282 = TERNARY_1(T281, Mock_Top_soc_dev_bus__io_slaves_2_dat4.values[0], T280);}
  { Mock_Top_soc__io_devices_BTN.values[0] = Mock_Top__io_devices_BTN.values[0];}
  { Mock_Top_soc_dev__io_devices_BTN.values[0] = Mock_Top_soc__io_devices_BTN.values[0];}
  { Mock_Top_soc_dev_btn__io_BTN.values[0] = Mock_Top_soc_dev__io_devices_BTN.values[0];}
  val_t T283;
  { T283 = Mock_Top_soc_dev_btn__io_BTN.values[0] | 0x0L << 5;}
  { Mock_Top_soc_dev_btn__io_bus_dat4.values[0] = T283;}
  { Mock_Top_soc_dev_bus__io_slaves_1_dat4.values[0] = Mock_Top_soc_dev_btn__io_bus_dat4.values[0];}
  val_t T284;
  T284 = Mock_Top_soc_dev_bus__current_slave == 0x1L;
  val_t T285;
  { T285 = TERNARY_1(T284, Mock_Top_soc_dev_bus__io_slaves_1_dat4.values[0], T282);}
  { Mock_Top_soc__io_devices_SW.values[0] = Mock_Top__io_devices_SW.values[0];}
  { Mock_Top_soc_dev__io_devices_SW.values[0] = Mock_Top_soc__io_devices_SW.values[0];}
  { Mock_Top_soc_dev_sw__io_SW.values[0] = Mock_Top_soc_dev__io_devices_SW.values[0];}
  val_t T286;
  { T286 = Mock_Top_soc_dev_sw__io_SW.values[0] | 0x0L << 8;}
  { Mock_Top_soc_dev_sw__io_bus_dat4.values[0] = T286;}
  { Mock_Top_soc_dev_bus__io_slaves_0_dat4.values[0] = Mock_Top_soc_dev_sw__io_bus_dat4.values[0];}
  val_t T287;
  T287 = Mock_Top_soc_dev_bus__current_slave == 0x0L;
  val_t T288;
  { T288 = TERNARY_1(T287, Mock_Top_soc_dev_bus__io_slaves_0_dat4.values[0], T285);}
  val_t T289;
  T289 = Mock_Top_soc_dev_bus__ram_op == 0x0L;
  val_t T290;
  { T290 = TERNARY_1(T289, T288, T270);}
  { Mock_Top_soc_dev_bus__io_from_cpu_dat4.values[0] = T290;}
  { Mock_Top_soc_dev__io_bus_dat4.values[0] = Mock_Top_soc_dev_bus__io_from_cpu_dat4.values[0];}
  { Mock_Top_soc_cpu__io_bus_dat4.values[0] = Mock_Top_soc_dev__io_bus_dat4.values[0];}
  { Mock_Top_soc_cpu_cpath__io_bus_dat4.values[0] = Mock_Top_soc_cpu__io_bus_dat4.values[0];}
  { Mock_Top_soc_cpu_cpath__io_ctrl_bus_data.values[0] = Mock_Top_soc_cpu_cpath__io_bus_dat4.values[0];}
  { Mock_Top_soc_cpu_dpath__io_bus_data.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_bus_data.values[0];}
  val_t T291;
  { T291 = Mock_Top_soc_cpu_dpath__io_bus_data.values[0] | 0x0L << 32;}
  val_t T292;
  T292 = Mock_Top_soc_cpu_dpath__io_reg_we_src.values[0] == 0x1L;
  val_t T293;
  { T293 = TERNARY_1(T292, T291, T240);}
  val_t T294;
  { T294 = Mock_Top_soc_cpu_dpath_alu__io_out.values[0] | 0x0L << 32;}
  val_t T295;
  T295 = Mock_Top_soc_cpu_dpath__io_reg_we_src.values[0] == 0x0L;
  val_t T296;
  { T296 = TERNARY_1(T295, T294, T293);}
  val_t T297;
  { T297 = T296;}
  T297 = T297 & 0xffffffffL;
  { Mock_Top_soc_cpu_dpath_regfile__io_wtdata.values[0] = T297;}
  val_t T298;
  { T298 = TERNARY(T209, 0x2L, 0x0L);}
  val_t T299;
  { T299 = TERNARY(T211, 0x0L, T298);}
  val_t T300;
  { T300 = TERNARY(T42, 0x1L, T299);}
  val_t T301;
  { T301 = TERNARY(T44, 0x0L, T300);}
  val_t T302;
  { T302 = TERNARY(T46, 0x0L, T301);}
  val_t T303;
  { T303 = TERNARY(T2, 0x0L, T302);}
  val_t T304;
  { T304 = TERNARY(T3, 0x1L, T303);}
  val_t T305;
  { T305 = TERNARY(T5, 0x1L, T304);}
  val_t T306;
  { T306 = TERNARY(T7, 0x1L, T305);}
  val_t T307;
  { T307 = TERNARY(T9, 0x1L, T306);}
  val_t T308;
  { T308 = TERNARY(T11, 0x1L, T307);}
  val_t T309;
  { T309 = TERNARY(T13, 0x1L, T308);}
  val_t T310;
  { T310 = TERNARY(T15, 0x1L, T309);}
  val_t T311;
  { T311 = TERNARY(T17, 0x0L, T310);}
  val_t T312;
  { T312 = TERNARY(T19, 0x0L, T311);}
  val_t T313;
  { T313 = TERNARY(T21, 0x0L, T312);}
  val_t T314;
  { T314 = TERNARY(T23, 0x0L, T313);}
  val_t T315;
  { T315 = TERNARY(T25, 0x0L, T314);}
  val_t T316;
  { T316 = TERNARY(T27, 0x0L, T315);}
  val_t T317;
  { T317 = TERNARY(T29, 0x0L, T316);}
  val_t T318;
  { T318 = TERNARY(T31, 0x0L, T317);}
  val_t T319;
  { T319 = TERNARY(T33, 0x0L, T318);}
  val_t T320;
  { T320 = TERNARY(T35, 0x0L, T319);}
  val_t T321;
  { T321 = TERNARY(T37, 0x0L, T320);}
  val_t Mock_Top_soc_cpu_cpath__reg_we_dst;
  { Mock_Top_soc_cpu_cpath__reg_we_dst = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T321);}
  { Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_dst.values[0] = Mock_Top_soc_cpu_cpath__reg_we_dst;}
  { Mock_Top_soc_cpu_dpath__io_reg_we_dst.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_dst.values[0];}
  val_t T322;
  T322 = Mock_Top_soc_cpu_dpath__io_reg_we_dst.values[0] == 0x2L;
  val_t T323;
  { T323 = TERNARY(T322, 0x1fL, 0x0L);}
  val_t T324;
  { T324 = Mock_Top_soc_cpu_dpath__inst_reg.values[0] >> 16;}
  T324 = T324 & 0x1fL;
  val_t T325;
  T325 = Mock_Top_soc_cpu_dpath__io_reg_we_dst.values[0] == 0x1L;
  val_t T326;
  { T326 = TERNARY_1(T325, T324, T323);}
  val_t T327;
  { T327 = Mock_Top_soc_cpu_dpath__inst_reg.values[0] >> 11;}
  T327 = T327 & 0x1fL;
  val_t T328;
  T328 = Mock_Top_soc_cpu_dpath__io_reg_we_dst.values[0] == 0x0L;
  val_t T329;
  { T329 = TERNARY_1(T328, T327, T326);}
  { Mock_Top_soc_cpu_dpath_regfile__io_wtaddr.values[0] = T329;}
  val_t T330;
  T330 = Mock_Top_soc_cpu_dpath_regfile__io_wtaddr.values[0] != 0x0L;
  val_t T331;
  { T331 = TERNARY(T211, 0x0L, T209);}
  val_t T332;
  { T332 = TERNARY(T42, 0x1L, T331);}
  val_t T333;
  { T333 = TERNARY(T44, 0x0L, T332);}
  val_t T334;
  { T334 = TERNARY(T46, 0x0L, T333);}
  val_t T335;
  { T335 = TERNARY(T2, 0x0L, T334);}
  val_t T336;
  { T336 = TERNARY(T3, 0x1L, T335);}
  val_t T337;
  { T337 = TERNARY(T5, 0x1L, T336);}
  val_t T338;
  { T338 = TERNARY(T7, 0x1L, T337);}
  val_t T339;
  { T339 = TERNARY(T9, 0x1L, T338);}
  val_t T340;
  { T340 = TERNARY(T11, 0x1L, T339);}
  val_t T341;
  { T341 = TERNARY(T13, 0x1L, T340);}
  val_t T342;
  { T342 = TERNARY(T15, 0x1L, T341);}
  val_t T343;
  { T343 = TERNARY(T17, 0x0L, T342);}
  val_t T344;
  { T344 = TERNARY(T19, 0x1L, T343);}
  val_t T345;
  { T345 = TERNARY(T21, 0x1L, T344);}
  val_t T346;
  { T346 = TERNARY(T23, 0x1L, T345);}
  val_t T347;
  { T347 = TERNARY(T25, 0x1L, T346);}
  val_t T348;
  { T348 = TERNARY(T27, 0x1L, T347);}
  val_t T349;
  { T349 = TERNARY(T29, 0x1L, T348);}
  val_t T350;
  { T350 = TERNARY(T31, 0x1L, T349);}
  val_t T351;
  { T351 = TERNARY(T33, 0x1L, T350);}
  val_t T352;
  { T352 = TERNARY(T35, 0x1L, T351);}
  val_t T353;
  { T353 = TERNARY(T37, 0x1L, T352);}
  val_t Mock_Top_soc_cpu_cpath__reg_we;
  { Mock_Top_soc_cpu_cpath__reg_we = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T353);}
  { Mock_Top_soc_cpu_cpath__io_ctrl_reg_we.values[0] = Mock_Top_soc_cpu_cpath__reg_we;}
  { Mock_Top_soc_cpu_dpath__io_reg_we.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_reg_we.values[0];}
  { Mock_Top_soc_cpu_dpath_regfile__io_we.values[0] = Mock_Top_soc_cpu_dpath__io_reg_we.values[0];}
  { T354.values[0] = Mock_Top_soc_cpu_dpath_regfile__io_we.values[0] & T330;}
  { Mock_Top_soc_cpu_cpath__io_ctrl_inst_we.values[0] = Mock_Top_soc_cpu_cpath__inst_we;}
  { Mock_Top_soc_cpu_dpath__io_inst_we.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_inst_we.values[0];}
  val_t T355;
  { T355 = TERNARY_1(Mock_Top_soc_cpu_dpath__io_inst_we.values[0], Mock_Top_soc_cpu_dpath__io_bus_data.values[0], Mock_Top_soc_cpu_dpath__inst_reg.values[0]);}
  { T356.values[0] = TERNARY(Mock_Top_soc_cpu_dpath__reset.values[0], 0x0L, T355);}
  val_t T357;
  { T357 = Mock_Top_soc_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T358;
  { T358 = TERNARY(T209, 0x2L, 0x0L);}
  val_t T359;
  { T359 = TERNARY(T211, 0x2L, T358);}
  val_t T360;
  { T360 = TERNARY(T42, 0x0L, T359);}
  val_t T361;
  { T361 = TERNARY(T44, 0x1L, T360);}
  val_t T362;
  { T362 = TERNARY(T46, 0x1L, T361);}
  val_t T363;
  { T363 = TERNARY(T2, 0x0L, T362);}
  val_t T364;
  { T364 = TERNARY(T3, 0x0L, T363);}
  val_t T365;
  { T365 = TERNARY(T5, 0x0L, T364);}
  val_t T366;
  { T366 = TERNARY(T7, 0x0L, T365);}
  val_t T367;
  { T367 = TERNARY(T9, 0x0L, T366);}
  val_t T368;
  { T368 = TERNARY(T11, 0x0L, T367);}
  val_t T369;
  { T369 = TERNARY(T13, 0x0L, T368);}
  val_t T370;
  { T370 = TERNARY(T15, 0x0L, T369);}
  val_t T371;
  { T371 = TERNARY(T17, 0x3L, T370);}
  val_t T372;
  { T372 = TERNARY(T19, 0x0L, T371);}
  val_t T373;
  { T373 = TERNARY(T21, 0x0L, T372);}
  val_t T374;
  { T374 = TERNARY(T23, 0x0L, T373);}
  val_t T375;
  { T375 = TERNARY(T25, 0x0L, T374);}
  val_t T376;
  { T376 = TERNARY(T27, 0x0L, T375);}
  val_t T377;
  { T377 = TERNARY(T29, 0x0L, T376);}
  val_t T378;
  { T378 = TERNARY(T31, 0x0L, T377);}
  val_t T379;
  { T379 = TERNARY(T33, 0x0L, T378);}
  val_t T380;
  { T380 = TERNARY(T35, 0x0L, T379);}
  val_t T381;
  { T381 = TERNARY(T37, 0x0L, T380);}
  val_t Mock_Top_soc_cpu_cpath__pc_next_sel;
  { Mock_Top_soc_cpu_cpath__pc_next_sel = TERNARY(Mock_Top_soc_cpu_cpath__inst_we, 0x0L, T381);}
  { Mock_Top_soc_cpu_cpath__io_ctrl_pc_next_sel.values[0] = Mock_Top_soc_cpu_cpath__pc_next_sel;}
  { Mock_Top_soc_cpu_dpath__io_pc_next_sel.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_pc_next_sel.values[0];}
  val_t T382;
  T382 = Mock_Top_soc_cpu_dpath__io_pc_next_sel.values[0] == 0x3L;
  val_t T383;
  { T383 = TERNARY(T382, Mock_Top_soc_cpu_dpath_regfile__io_douta.values[0], 0x0L);}
  val_t T384;
  { T384 = Mock_Top_soc_cpu_dpath__inst_reg.values[0];}
  T384 = T384 & 0x3ffffffL;
  val_t T385;
  T385 = T384 << 0x2L;
  T385 = T385 & 0xfffffffL;
  val_t T386;
  { T386 = Mock_Top_soc_cpu_dpath__pc.values[0] >> 28;}
  T386 = T386 & 0xfL;
  val_t T387;
  { T387 = T386 | 0x0L << 4;}
  val_t T388;
  { T388 = T387 | T385;}
  val_t T389;
  { T389 = T388 | 0x0L << 28;}
  val_t T390;
  T390 = Mock_Top_soc_cpu_dpath__io_pc_next_sel.values[0] == 0x2L;
  val_t T391;
  { T391 = TERNARY_1(T390, T389, T383);}
  val_t T392;
  { T392 = T391 | 0x0L << 32;}
  val_t T393;
  { T393 = Mock_Top_soc_cpu_dpath__pc.values[0]+0x4L;}
  T393 = T393 & 0xffffffffL;
  val_t T394;
  T394 = Mock_Top_soc_cpu_dpath_alu__io_out.values[0] != 0x0L;
  val_t T395;
  { T395 = T394 ^ 0x1L;}
  { Mock_Top_soc_cpu_dpath_alu__io_zero.values[0] = T395;}
  val_t T396;
  T396 = Mock_Top_soc_cpu_dpath_alu__io_zero.values[0] == 0x0L;
  val_t T397;
  { T397 = TERNARY(T396, T393, 0x0L);}
  val_t T398;
  { T398 = T397 | 0x0L << 32;}
  val_t T399;
  { T399 = Mock_Top_soc_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T400;
  { T400 = Mock_Top_soc_cpu_dpath__inst_reg.values[0];}
  T400 = T400 & 0xffffL;
  val_t T401;
  T401 = T400 << 0x2L;
  T401 = T401 & 0x3ffffL;
  val_t T402;
  T402 = (T401 >> 17) & 1;
  val_t T403;
  { T403 = TERNARY(T402, 0x7fffL, 0x0L);}
  val_t T404;
  { T404 = T401 | T403 << 18;}
  val_t T405;
  { T405 = T404+T399;}
  T405 = T405 & 0x1ffffffffL;
  val_t T406;
  T406 = Mock_Top_soc_cpu_dpath_alu__io_zero.values[0] == 0x1L;
  val_t T407;
  { T407 = TERNARY_1(T406, T405, T398);}
  val_t T408;
  T408 = Mock_Top_soc_cpu_dpath__io_pc_next_sel.values[0] == 0x1L;
  val_t T409;
  { T409 = TERNARY_1(T408, T407, T392);}
  val_t T410;
  { T410 = Mock_Top_soc_cpu_dpath__pc.values[0]+0x4L;}
  T410 = T410 & 0xffffffffL;
  val_t T411;
  { T411 = T410 | 0x0L << 32;}
  val_t T412;
  T412 = Mock_Top_soc_cpu_dpath__io_pc_next_sel.values[0] == 0x0L;
  val_t Mock_Top_soc_cpu_dpath__pc_next;
  { Mock_Top_soc_cpu_dpath__pc_next = TERNARY_1(T412, T411, T409);}
  val_t Mock_Top_soc_cpu_cpath__pc_we;
  Mock_Top_soc_cpu_cpath__pc_we = Mock_Top_soc_cpu_cpath__inst_we == 0x0L;
  { Mock_Top_soc_cpu_cpath__io_ctrl_pc_we.values[0] = Mock_Top_soc_cpu_cpath__pc_we;}
  { Mock_Top_soc_cpu_dpath__io_pc_we.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_pc_we.values[0];}
  val_t T413;
  { T413 = TERNARY_1(Mock_Top_soc_cpu_dpath__io_pc_we.values[0], Mock_Top_soc_cpu_dpath__pc_next, T357);}
  val_t T414;
  { T414 = TERNARY(Mock_Top_soc_cpu_dpath__reset.values[0], 0x0L, T413);}
  { T415.values[0] = T414;}
  T415.values[0] = T415.values[0] & 0xffffffffL;
  { Mock_Top_soc_cpu_dpath__io_inst.values[0] = Mock_Top_soc_cpu_dpath__inst_reg.values[0];}
  { Mock_Top_soc_cpu_cpath__io_ctrl_inst.values[0] = Mock_Top_soc_cpu_dpath__io_inst.values[0];}
  val_t T416;
  T416 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x0L;
  val_t Mock_Top_soc_cpu_cpath__inst;
  { Mock_Top_soc_cpu_cpath__inst = TERNARY_1(T416, Mock_Top_soc_cpu_cpath__io_bus_dat4.values[0], Mock_Top_soc_cpu_cpath__io_ctrl_inst.values[0]);}
  val_t Mock_Top_soc_cpu_cpath__inst_op;
  { Mock_Top_soc_cpu_cpath__inst_op = Mock_Top_soc_cpu_cpath__inst >> 26;}
  Mock_Top_soc_cpu_cpath__inst_op = Mock_Top_soc_cpu_cpath__inst_op & 0x3fL;
  val_t T417;
  T417 = Mock_Top_soc_cpu_cpath__inst_op == 0x3L;
  val_t T418;
  { T418 = TERNARY(T417, 0x18L, 0x0L);}
  val_t T419;
  T419 = Mock_Top_soc_cpu_cpath__inst_op == 0x2L;
  val_t T420;
  { T420 = TERNARY(T419, 0x17L, T418);}
  val_t T421;
  T421 = Mock_Top_soc_cpu_cpath__inst_op == 0xaL;
  val_t T422;
  { T422 = TERNARY(T421, 0x16L, T420);}
  val_t T423;
  T423 = Mock_Top_soc_cpu_cpath__inst_op == 0x5L;
  val_t T424;
  { T424 = TERNARY(T423, 0x15L, T422);}
  val_t T425;
  T425 = Mock_Top_soc_cpu_cpath__inst_op == 0x4L;
  val_t T426;
  { T426 = TERNARY(T425, 0x14L, T424);}
  val_t T427;
  T427 = Mock_Top_soc_cpu_cpath__inst_op == 0x2bL;
  val_t T428;
  { T428 = TERNARY(T427, 0x13L, T426);}
  val_t T429;
  T429 = Mock_Top_soc_cpu_cpath__inst_op == 0x23L;
  val_t T430;
  { T430 = TERNARY(T429, 0x12L, T428);}
  val_t T431;
  T431 = Mock_Top_soc_cpu_cpath__inst_op == 0xfL;
  val_t T432;
  { T432 = TERNARY(T431, 0x11L, T430);}
  val_t T433;
  T433 = Mock_Top_soc_cpu_cpath__inst_op == 0xeL;
  val_t T434;
  { T434 = TERNARY(T433, 0x10L, T432);}
  val_t T435;
  T435 = Mock_Top_soc_cpu_cpath__inst_op == 0xdL;
  val_t T436;
  { T436 = TERNARY(T435, 0xfL, T434);}
  val_t T437;
  T437 = Mock_Top_soc_cpu_cpath__inst_op == 0xcL;
  val_t T438;
  { T438 = TERNARY(T437, 0xeL, T436);}
  val_t T439;
  T439 = Mock_Top_soc_cpu_cpath__inst_op == 0x9L;
  val_t T440;
  { T440 = TERNARY(T439, 0xdL, T438);}
  val_t T441;
  T441 = Mock_Top_soc_cpu_cpath__inst_op == 0x8L;
  val_t T442;
  { T442 = TERNARY(T441, 0xcL, T440);}
  val_t Mock_Top_soc_cpu_cpath__inst_func;
  { Mock_Top_soc_cpu_cpath__inst_func = Mock_Top_soc_cpu_cpath__inst;}
  Mock_Top_soc_cpu_cpath__inst_func = Mock_Top_soc_cpu_cpath__inst_func & 0x3fL;
  val_t T443;
  T443 = Mock_Top_soc_cpu_cpath__inst_func == 0x8L;
  val_t T444;
  { T444 = TERNARY(T443, 0xbL, 0x0L);}
  val_t T445;
  T445 = Mock_Top_soc_cpu_cpath__inst_func == 0x6L;
  val_t T446;
  { T446 = TERNARY(T445, 0xaL, T444);}
  val_t T447;
  T447 = Mock_Top_soc_cpu_cpath__inst_func == 0x2aL;
  val_t T448;
  { T448 = TERNARY(T447, 0x9L, T446);}
  val_t T449;
  T449 = Mock_Top_soc_cpu_cpath__inst_func == 0x27L;
  val_t T450;
  { T450 = TERNARY(T449, 0x8L, T448);}
  val_t T451;
  T451 = Mock_Top_soc_cpu_cpath__inst_func == 0x26L;
  val_t T452;
  { T452 = TERNARY(T451, 0x7L, T450);}
  val_t T453;
  T453 = Mock_Top_soc_cpu_cpath__inst_func == 0x25L;
  val_t T454;
  { T454 = TERNARY(T453, 0x6L, T452);}
  val_t T455;
  T455 = Mock_Top_soc_cpu_cpath__inst_func == 0x24L;
  val_t T456;
  { T456 = TERNARY(T455, 0x5L, T454);}
  val_t T457;
  T457 = Mock_Top_soc_cpu_cpath__inst_func == 0x23L;
  val_t T458;
  { T458 = TERNARY(T457, 0x4L, T456);}
  val_t T459;
  T459 = Mock_Top_soc_cpu_cpath__inst_func == 0x22L;
  val_t T460;
  { T460 = TERNARY(T459, 0x3L, T458);}
  val_t T461;
  T461 = Mock_Top_soc_cpu_cpath__inst_func == 0x21L;
  val_t T462;
  { T462 = TERNARY(T461, 0x2L, T460);}
  val_t T463;
  T463 = Mock_Top_soc_cpu_cpath__inst_func == 0x20L;
  val_t T464;
  { T464 = TERNARY(T463, 0x1L, T462);}
  val_t T465;
  T465 = Mock_Top_soc_cpu_cpath__inst_op == 0x0L;
  val_t T466;
  { T466 = TERNARY_1(T465, T464, T442);}
  val_t T467;
  T467 = Mock_Top_soc_cpu_cpath__state.values[0] == 0x0L;
  val_t T468;
  { T468 = TERNARY(T467, T466, 0x0L);}
  { Mock_Top_soc_dev_ram_dev__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_ram_slave_ack.values[0] = Mock_Top_soc_dev_ram_dev__io_bus_ack.values[0];}
  val_t T469;
  T469 = Mock_Top_soc_dev_bus__ram_op == 0x1L;
  val_t T470;
  { T470 = TERNARY(T469, Mock_Top_soc_dev_bus__io_ram_slave_ack.values[0], 0x0L);}
  { Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_7_ack.values[0] = Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_ack.values[0];}
  val_t T471;
  T471 = Mock_Top_soc_dev_bus__current_slave == 0x7L;
  val_t T472;
  { T472 = TERNARY(T471, Mock_Top_soc_dev_bus__io_slaves_7_ack.values[0], 0x0L);}
  { Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_6_ack.values[0] = Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_ack.values[0];}
  val_t T473;
  T473 = Mock_Top_soc_dev_bus__current_slave == 0x6L;
  val_t T474;
  { T474 = TERNARY(T473, Mock_Top_soc_dev_bus__io_slaves_6_ack.values[0], T472);}
  { Mock_Top_soc_dev_WB_Empty_Dev__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_5_ack.values[0] = Mock_Top_soc_dev_WB_Empty_Dev__io_bus_ack.values[0];}
  val_t T475;
  T475 = Mock_Top_soc_dev_bus__current_slave == 0x5L;
  val_t T476;
  { T476 = TERNARY(T475, Mock_Top_soc_dev_bus__io_slaves_5_ack.values[0], T474);}
  { Mock_Top_soc_dev_seven_seg__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_4_ack.values[0] = Mock_Top_soc_dev_seven_seg__io_bus_ack.values[0];}
  val_t T477;
  T477 = Mock_Top_soc_dev_bus__current_slave == 0x4L;
  val_t T478;
  { T478 = TERNARY(T477, Mock_Top_soc_dev_bus__io_slaves_4_ack.values[0], T476);}
  { Mock_Top_soc_dev_counter__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_3_ack.values[0] = Mock_Top_soc_dev_counter__io_bus_ack.values[0];}
  val_t T479;
  T479 = Mock_Top_soc_dev_bus__current_slave == 0x3L;
  val_t T480;
  { T480 = TERNARY(T479, Mock_Top_soc_dev_bus__io_slaves_3_ack.values[0], T478);}
  { Mock_Top_soc_dev_led__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_2_ack.values[0] = Mock_Top_soc_dev_led__io_bus_ack.values[0];}
  val_t T481;
  T481 = Mock_Top_soc_dev_bus__current_slave == 0x2L;
  val_t T482;
  { T482 = TERNARY(T481, Mock_Top_soc_dev_bus__io_slaves_2_ack.values[0], T480);}
  { Mock_Top_soc_dev_btn__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_1_ack.values[0] = Mock_Top_soc_dev_btn__io_bus_ack.values[0];}
  val_t T483;
  T483 = Mock_Top_soc_dev_bus__current_slave == 0x1L;
  val_t T484;
  { T484 = TERNARY(T483, Mock_Top_soc_dev_bus__io_slaves_1_ack.values[0], T482);}
  { Mock_Top_soc_dev_sw__io_bus_ack.values[0] = 0x1L;}
  { Mock_Top_soc_dev_bus__io_slaves_0_ack.values[0] = Mock_Top_soc_dev_sw__io_bus_ack.values[0];}
  val_t T485;
  T485 = Mock_Top_soc_dev_bus__current_slave == 0x0L;
  val_t T486;
  { T486 = TERNARY(T485, Mock_Top_soc_dev_bus__io_slaves_0_ack.values[0], T484);}
  val_t T487;
  T487 = Mock_Top_soc_dev_bus__ram_op == 0x0L;
  val_t T488;
  { T488 = TERNARY_1(T487, T486, T470);}
  { Mock_Top_soc_dev_bus__io_from_cpu_ack.values[0] = T488;}
  { Mock_Top_soc_dev__io_bus_ack.values[0] = Mock_Top_soc_dev_bus__io_from_cpu_ack.values[0];}
  { Mock_Top_soc_cpu__io_bus_ack.values[0] = Mock_Top_soc_dev__io_bus_ack.values[0];}
  { Mock_Top_soc_cpu_cpath__io_bus_ack.values[0] = Mock_Top_soc_cpu__io_bus_ack.values[0];}
  val_t T489;
  { T489 = TERNARY_1(Mock_Top_soc_cpu_cpath__io_bus_ack.values[0], T468, Mock_Top_soc_cpu_cpath__state.values[0]);}
  { Mock_Top_soc_cpu_cpath__reset.values[0] = Mock_Top_soc_cpu__reset.values[0];}
  { T490.values[0] = TERNARY(Mock_Top_soc_cpu_cpath__reset.values[0], 0x0L, T489);}
  { Mock_Top_soc_dev_seven_seg__io_DISP_NUM.values[0] = Mock_Top_soc_dev_seven_seg__disp_data.values[0];}
  { Mock_Top_soc_dev__io_devices_DISP_NUM.values[0] = Mock_Top_soc_dev_seven_seg__io_DISP_NUM.values[0];}
  { Mock_Top_soc__io_devices_DISP_NUM.values[0] = Mock_Top_soc_dev__io_devices_DISP_NUM.values[0];}
  { Mock_Top_soc_cpu_cpath__io_debug_inst_out.values[0] = Mock_Top_soc_cpu_cpath__inst;}
  { Mock_Top_soc_cpu__io_debug_inst_out.values[0] = Mock_Top_soc_cpu_cpath__io_debug_inst_out.values[0];}
  { Mock_Top_soc__io_debug_inst_out.values[0] = Mock_Top_soc_cpu__io_debug_inst_out.values[0];}
  { Mock_Top__io_debug_inst_out.values[0] = Mock_Top_soc__io_debug_inst_out.values[0];}
  { Mock_Top_soc_cpu_cpath__io_debug_bus_addr.values[0] = Mock_Top_soc_cpu_cpath__io_bus_addr.values[0];}
  { Mock_Top_soc_cpu__io_debug_bus_addr.values[0] = Mock_Top_soc_cpu_cpath__io_debug_bus_addr.values[0];}
  { Mock_Top_soc__io_debug_bus_addr.values[0] = Mock_Top_soc_cpu__io_debug_bus_addr.values[0];}
  { Mock_Top__io_debug_bus_addr.values[0] = Mock_Top_soc__io_debug_bus_addr.values[0];}
  { Mock_Top_soc_cpu_cpath__io_debug_bus_dat2.values[0] = Mock_Top_soc_cpu_cpath__io_bus_dat2.values[0];}
  { Mock_Top_soc_cpu__io_debug_bus_dat2.values[0] = Mock_Top_soc_cpu_cpath__io_debug_bus_dat2.values[0];}
  { Mock_Top_soc__io_debug_bus_dat2.values[0] = Mock_Top_soc_cpu__io_debug_bus_dat2.values[0];}
  { Mock_Top__io_debug_bus_dat2.values[0] = Mock_Top_soc__io_debug_bus_dat2.values[0];}
  { Mock_Top_soc_cpu_cpath__io_debug_bus_dat4.values[0] = Mock_Top_soc_cpu_cpath__io_bus_dat4.values[0];}
  { Mock_Top_soc_cpu__io_debug_bus_dat4.values[0] = Mock_Top_soc_cpu_cpath__io_debug_bus_dat4.values[0];}
  { Mock_Top_soc__io_debug_bus_dat4.values[0] = Mock_Top_soc_cpu__io_debug_bus_dat4.values[0];}
  { Mock_Top__io_debug_bus_dat4.values[0] = Mock_Top_soc__io_debug_bus_dat4.values[0];}
  { Mock_Top_soc_cpu_cpath__io_debug_pc_out.values[0] = Mock_Top_soc_cpu_cpath__io_ctrl_pc_out.values[0];}
  { Mock_Top_soc_cpu__io_debug_pc_out.values[0] = Mock_Top_soc_cpu_cpath__io_debug_pc_out.values[0];}
  { Mock_Top_soc__io_debug_pc_out.values[0] = Mock_Top_soc_cpu__io_debug_pc_out.values[0];}
  { Mock_Top__io_debug_pc_out.values[0] = Mock_Top_soc__io_debug_pc_out.values[0];}
  { Mock_Top_soc_dev_led__io_LED.values[0] = Mock_Top_soc_dev_led__led_data.values[0];}
  { Mock_Top_soc_dev__io_devices_LED.values[0] = Mock_Top_soc_dev_led__io_LED.values[0];}
  { Mock_Top_soc__io_devices_LED.values[0] = Mock_Top_soc_dev__io_devices_LED.values[0];}
  { Mock_Top__io_devices_LED.values[0] = Mock_Top_soc__io_devices_LED.values[0];}
  { val_t __r = this->__rand_val(); Mock_Top__io_devices_DISP_NUM.values[0] = __r;}
  Mock_Top__io_devices_DISP_NUM.values[0] = Mock_Top__io_devices_DISP_NUM.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); Mock_Top__io_devices_RAM_addra.values[0] = __r;}
  Mock_Top__io_devices_RAM_addra.values[0] = Mock_Top__io_devices_RAM_addra.values[0] & 0x3ffL;
  { val_t __r = this->__rand_val(); Mock_Top__io_devices_RAM_dina.values[0] = __r;}
  Mock_Top__io_devices_RAM_dina.values[0] = Mock_Top__io_devices_RAM_dina.values[0] & 0xffffffffL;
  { val_t __r = this->__rand_val(); Mock_Top__io_devices_RAM_we.values[0] = __r;}
  Mock_Top__io_devices_RAM_we.values[0] = Mock_Top__io_devices_RAM_we.values[0] & 0x1L;
  val_t T491;
  { T491 = Mock_Top_soc_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T492.values[0] = Mock_Top_soc_cpu_cpath__io_bus_ack.values[0] & T491;}
  { T493.values[0] = Mock_Top_soc_cpu_cpath__state.values[0];}
}


void Mock_Top_t::clock_hi ( dat_t<1> reset ) {
  dat_t<32> Mock_Top_soc_dev_seven_seg__data_out__shadow = T183;
  dat_t<32> Mock_Top_soc_dev_seven_seg__disp_data__shadow = T185;
  dat_t<32> Mock_Top_soc_dev_led__data_out__shadow = T203;
  dat_t<8> Mock_Top_soc_dev_led__led_data__shadow = T207;
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1fL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1eL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1dL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1cL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1bL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1aL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x19L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x18L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x17L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x16L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x15L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x14L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x13L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x12L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x11L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x10L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xfL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xeL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xdL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xcL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xbL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0xaL, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x9L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x8L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x7L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x6L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x5L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x4L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x3L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x2L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x1L, 0, 0x0L);}
  { if (Mock_Top_soc_cpu_dpath_regfile__reset.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(0x0L, 0, 0x0L);}
  { if (T354.values[0]) Mock_Top_soc_cpu_dpath_regfile__rf.put(Mock_Top_soc_cpu_dpath_regfile__io_wtaddr.values[0], 0, Mock_Top_soc_cpu_dpath_regfile__io_wtdata.values[0]);}
  dat_t<32> Mock_Top_soc_cpu_dpath__inst_reg__shadow = T356;
  dat_t<32> Mock_Top_soc_cpu_dpath__pc__shadow = T415;
  dat_t<32> Mock_Top_soc_cpu_cpath__state__shadow = T490;
  Mock_Top_soc_dev_seven_seg__data_out = T183;
  Mock_Top_soc_dev_seven_seg__disp_data = T185;
  Mock_Top_soc_dev_led__data_out = T203;
  Mock_Top_soc_dev_led__led_data = T207;
  Mock_Top_soc_cpu_dpath__inst_reg = T356;
  Mock_Top_soc_cpu_dpath__pc = T415;
  Mock_Top_soc_cpu_cpath__state = T490;
}


void Mock_Top_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  Mock_Top_t* mod_typed = dynamic_cast<Mock_Top_t*>(module);
  assert(mod_typed);
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_addrb"] = new dat_api<5>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_addrb, "Mock_Top.soc.cpu.dpath.regfile.io_addrb", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_doutb"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_doutb, "Mock_Top.soc.cpu.dpath.regfile.io_doutb", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_data_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__io_data_out, "Mock_Top.soc.cpu.dpath.io_data_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_data_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_data_out, "Mock_Top.soc.cpu.cpath.io_ctrl_data_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_dat2, "Mock_Top.soc.cpu.cpath.io_bus_dat2", "");
  dat_table["Mock_Top.soc.cpu.io_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_bus_dat2, "Mock_Top.soc.cpu.io_bus_dat2", "");
  dat_table["Mock_Top.soc.dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev__io_bus_dat2, "Mock_Top.soc.dev.io_bus_dat2", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_dat2, "Mock_Top.soc.dev.bus.io_from_cpu_dat2", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_4_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_dat2, "Mock_Top.soc.dev.bus.io_slaves_4_dat2", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_dat2, "Mock_Top.soc.dev.seven_seg.io_bus_dat2", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__io_pc_out, "Mock_Top.soc.cpu.dpath.io_pc_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_out, "Mock_Top.soc.cpu.cpath.io_ctrl_pc_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_alu_b_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_b_sel, "Mock_Top.soc.cpu.cpath.io_ctrl_alu_b_sel", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_alu_b_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath__io_alu_b_sel, "Mock_Top.soc.cpu.dpath.io_alu_b_sel", "");
  dat_table["Mock_Top.soc.cpu.dpath.alu.io_in_b"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_alu__io_in_b, "Mock_Top.soc.cpu.dpath.alu.io_in_b", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_addra"] = new dat_api<5>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_addra, "Mock_Top.soc.cpu.dpath.regfile.io_addra", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_douta"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_douta, "Mock_Top.soc.cpu.dpath.regfile.io_douta", "");
  dat_table["Mock_Top.soc.cpu.dpath.alu.io_in_a"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_alu__io_in_a, "Mock_Top.soc.cpu.dpath.alu.io_in_a", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_alu_op"] = new dat_api<3>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_op, "Mock_Top.soc.cpu.cpath.io_ctrl_alu_op", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_alu_op"] = new dat_api<3>(&mod_typed->Mock_Top_soc_cpu_dpath__io_alu_op, "Mock_Top.soc.cpu.dpath.io_alu_op", "");
  dat_table["Mock_Top.soc.cpu.dpath.alu.io_alu_op"] = new dat_api<3>(&mod_typed->Mock_Top_soc_cpu_dpath_alu__io_alu_op, "Mock_Top.soc.cpu.dpath.alu.io_alu_op", "");
  dat_table["Mock_Top.soc.cpu.dpath.alu.io_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_alu__io_out, "Mock_Top.soc.cpu.dpath.alu.io_out", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_alu_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__io_alu_out, "Mock_Top.soc.cpu.dpath.io_alu_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_alu_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_alu_out, "Mock_Top.soc.cpu.cpath.io_ctrl_alu_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_addr, "Mock_Top.soc.cpu.cpath.io_bus_addr", "");
  dat_table["Mock_Top.soc.cpu.io_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_bus_addr, "Mock_Top.soc.cpu.io_bus_addr", "");
  dat_table["Mock_Top.soc.dev.io_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev__io_bus_addr, "Mock_Top.soc.dev.io_bus_addr", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_addr, "Mock_Top.soc.dev.bus.io_from_cpu_addr", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_we, "Mock_Top.soc.cpu.cpath.io_bus_we", "");
  dat_table["Mock_Top.soc.cpu.io_bus_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu__io_bus_we, "Mock_Top.soc.cpu.io_bus_we", "");
  dat_table["Mock_Top.soc.dev.io_bus_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev__io_bus_we, "Mock_Top.soc.dev.io_bus_we", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_we, "Mock_Top.soc.dev.bus.io_from_cpu_we", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_4_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_we, "Mock_Top.soc.dev.bus.io_slaves_4_we", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_bus_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_we, "Mock_Top.soc.dev.seven_seg.io_bus_we", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_sel, "Mock_Top.soc.cpu.cpath.io_bus_sel", "");
  dat_table["Mock_Top.soc.cpu.io_bus_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu__io_bus_sel, "Mock_Top.soc.cpu.io_bus_sel", "");
  dat_table["Mock_Top.soc.dev.io_bus_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev__io_bus_sel, "Mock_Top.soc.dev.io_bus_sel", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_sel, "Mock_Top.soc.dev.bus.io_from_cpu_sel", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_4_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_sel, "Mock_Top.soc.dev.bus.io_slaves_4_sel", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_bus_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_sel, "Mock_Top.soc.dev.seven_seg.io_bus_sel", "");
  dat_table["Mock_Top.soc.dev.seven_seg.data_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_seven_seg__data_out, "Mock_Top.soc.dev.seven_seg.data_out", "");
  dat_table["Mock_Top.soc.dev.seven_seg.disp_data"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_seven_seg__disp_data, "Mock_Top.soc.dev.seven_seg.disp_data", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_2_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_dat2, "Mock_Top.soc.dev.bus.io_slaves_2_dat2", "");
  dat_table["Mock_Top.soc.dev.led.io_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_led__io_bus_dat2, "Mock_Top.soc.dev.led.io_bus_dat2", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_2_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_we, "Mock_Top.soc.dev.bus.io_slaves_2_we", "");
  dat_table["Mock_Top.soc.dev.led.io_bus_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_led__io_bus_we, "Mock_Top.soc.dev.led.io_bus_we", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_2_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_sel, "Mock_Top.soc.dev.bus.io_slaves_2_sel", "");
  dat_table["Mock_Top.soc.dev.led.io_bus_sel"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_led__io_bus_sel, "Mock_Top.soc.dev.led.io_bus_sel", "");
  dat_table["Mock_Top.soc.dev.led.data_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_led__data_out, "Mock_Top.soc.dev.led.data_out", "");
  dat_table["Mock_Top.soc.dev.led.led_data"] = new dat_api<8>(&mod_typed->Mock_Top_soc_dev_led__led_data, "Mock_Top.soc.dev.led.led_data", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_reg_we_src"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_src, "Mock_Top.soc.cpu.cpath.io_ctrl_reg_we_src", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_reg_we_src"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we_src, "Mock_Top.soc.cpu.dpath.io_reg_we_src", "");
  dat_table["Mock_Top.soc.dev.bus.io_ram_slave_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_addr, "Mock_Top.soc.dev.bus.io_ram_slave_addr", "");
  dat_table["Mock_Top.soc.dev.ram_dev.io_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_addr, "Mock_Top.soc.dev.ram_dev.io_bus_addr", "");
  dat_table["Mock_Top.soc.dev.ram_dev.io_ram_addra"] = new dat_api<10>(&mod_typed->Mock_Top_soc_dev_ram_dev__io_ram_addra, "Mock_Top.soc.dev.ram_dev.io_ram_addra", "");
  dat_table["Mock_Top.soc.dev.io_devices_RAM_addra"] = new dat_api<10>(&mod_typed->Mock_Top_soc_dev__io_devices_RAM_addra, "Mock_Top.soc.dev.io_devices_RAM_addra", "");
  dat_table["Mock_Top.soc.io_devices_RAM_addra"] = new dat_api<10>(&mod_typed->Mock_Top_soc__io_devices_RAM_addra, "Mock_Top.soc.io_devices_RAM_addra", "");
  dat_table["Mock_Top.ram.io_addra"] = new dat_api<10>(&mod_typed->Mock_Top_ram__io_addra, "Mock_Top.ram.io_addra", "");
  dat_table["Mock_Top.ram.io_douta"] = new dat_api<32>(&mod_typed->Mock_Top_ram__io_douta, "Mock_Top.ram.io_douta", "");
  dat_table["Mock_Top.soc.io_devices_RAM_douta"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_devices_RAM_douta, "Mock_Top.soc.io_devices_RAM_douta", "");
  dat_table["Mock_Top.soc.dev.io_devices_RAM_douta"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev__io_devices_RAM_douta, "Mock_Top.soc.dev.io_devices_RAM_douta", "");
  dat_table["Mock_Top.soc.dev.ram_dev.io_ram_douta"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_ram_dev__io_ram_douta, "Mock_Top.soc.dev.ram_dev.io_ram_douta", "");
  dat_table["Mock_Top.soc.dev.ram_dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_dat4, "Mock_Top.soc.dev.ram_dev.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_ram_slave_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_dat4, "Mock_Top.soc.dev.bus.io_ram_slave_dat4", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev_2.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_dat4, "Mock_Top.soc.dev.WB_Empty_Dev_2.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_7_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_7_dat4, "Mock_Top.soc.dev.bus.io_slaves_7_dat4", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev_1.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_dat4, "Mock_Top.soc.dev.WB_Empty_Dev_1.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_6_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_6_dat4, "Mock_Top.soc.dev.bus.io_slaves_6_dat4", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev__io_bus_dat4, "Mock_Top.soc.dev.WB_Empty_Dev.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_5_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_5_dat4, "Mock_Top.soc.dev.bus.io_slaves_5_dat4", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_dat4, "Mock_Top.soc.dev.seven_seg.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_4_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_dat4, "Mock_Top.soc.dev.bus.io_slaves_4_dat4", "");
  dat_table["Mock_Top.soc.dev.counter.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_counter__io_bus_dat4, "Mock_Top.soc.dev.counter.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_3_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_3_dat4, "Mock_Top.soc.dev.bus.io_slaves_3_dat4", "");
  dat_table["Mock_Top.soc.dev.led.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_led__io_bus_dat4, "Mock_Top.soc.dev.led.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_2_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_dat4, "Mock_Top.soc.dev.bus.io_slaves_2_dat4", "");
  dat_table["Mock_Top.io_devices_BTN"] = new dat_api<5>(&mod_typed->Mock_Top__io_devices_BTN, "Mock_Top.io_devices_BTN", "");
  dat_table["Mock_Top.soc.io_devices_BTN"] = new dat_api<5>(&mod_typed->Mock_Top_soc__io_devices_BTN, "Mock_Top.soc.io_devices_BTN", "");
  dat_table["Mock_Top.soc.dev.io_devices_BTN"] = new dat_api<5>(&mod_typed->Mock_Top_soc_dev__io_devices_BTN, "Mock_Top.soc.dev.io_devices_BTN", "");
  dat_table["Mock_Top.soc.dev.btn.io_BTN"] = new dat_api<5>(&mod_typed->Mock_Top_soc_dev_btn__io_BTN, "Mock_Top.soc.dev.btn.io_BTN", "");
  dat_table["Mock_Top.soc.dev.btn.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_btn__io_bus_dat4, "Mock_Top.soc.dev.btn.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_1_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_1_dat4, "Mock_Top.soc.dev.bus.io_slaves_1_dat4", "");
  dat_table["Mock_Top.io_devices_SW"] = new dat_api<8>(&mod_typed->Mock_Top__io_devices_SW, "Mock_Top.io_devices_SW", "");
  dat_table["Mock_Top.soc.io_devices_SW"] = new dat_api<8>(&mod_typed->Mock_Top_soc__io_devices_SW, "Mock_Top.soc.io_devices_SW", "");
  dat_table["Mock_Top.soc.dev.io_devices_SW"] = new dat_api<8>(&mod_typed->Mock_Top_soc_dev__io_devices_SW, "Mock_Top.soc.dev.io_devices_SW", "");
  dat_table["Mock_Top.soc.dev.sw.io_SW"] = new dat_api<8>(&mod_typed->Mock_Top_soc_dev_sw__io_SW, "Mock_Top.soc.dev.sw.io_SW", "");
  dat_table["Mock_Top.soc.dev.sw.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_sw__io_bus_dat4, "Mock_Top.soc.dev.sw.io_bus_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_0_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_0_dat4, "Mock_Top.soc.dev.bus.io_slaves_0_dat4", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_dat4, "Mock_Top.soc.dev.bus.io_from_cpu_dat4", "");
  dat_table["Mock_Top.soc.dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev__io_bus_dat4, "Mock_Top.soc.dev.io_bus_dat4", "");
  dat_table["Mock_Top.soc.cpu.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_bus_dat4, "Mock_Top.soc.cpu.io_bus_dat4", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_dat4, "Mock_Top.soc.cpu.cpath.io_bus_dat4", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_bus_data"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_bus_data, "Mock_Top.soc.cpu.cpath.io_ctrl_bus_data", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_bus_data"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__io_bus_data, "Mock_Top.soc.cpu.dpath.io_bus_data", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_wtdata"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_wtdata, "Mock_Top.soc.cpu.dpath.regfile.io_wtdata", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_reg_we_dst"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we_dst, "Mock_Top.soc.cpu.cpath.io_ctrl_reg_we_dst", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_reg_we_dst"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we_dst, "Mock_Top.soc.cpu.dpath.io_reg_we_dst", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_wtaddr"] = new dat_api<5>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_wtaddr, "Mock_Top.soc.cpu.dpath.regfile.io_wtaddr", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_reg_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_reg_we, "Mock_Top.soc.cpu.cpath.io_ctrl_reg_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_reg_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath__io_reg_we, "Mock_Top.soc.cpu.dpath.io_reg_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.regfile.io_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__io_we, "Mock_Top.soc.cpu.dpath.regfile.io_we", "");
  mem_table["Mock_Top.soc.cpu.dpath.regfile.rf"] = new mem_api<32, 32>(&mod_typed->Mock_Top_soc_cpu_dpath_regfile__rf, "Mock_Top.soc.cpu.dpath.regfile.rf", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_inst_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_inst_we, "Mock_Top.soc.cpu.cpath.io_ctrl_inst_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_inst_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath__io_inst_we, "Mock_Top.soc.cpu.dpath.io_inst_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.inst_reg"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__inst_reg, "Mock_Top.soc.cpu.dpath.inst_reg", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_pc_next_sel"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_next_sel, "Mock_Top.soc.cpu.cpath.io_ctrl_pc_next_sel", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_pc_next_sel"] = new dat_api<2>(&mod_typed->Mock_Top_soc_cpu_dpath__io_pc_next_sel, "Mock_Top.soc.cpu.dpath.io_pc_next_sel", "");
  dat_table["Mock_Top.soc.cpu.dpath.alu.io_zero"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath_alu__io_zero, "Mock_Top.soc.cpu.dpath.alu.io_zero", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_pc_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_pc_we, "Mock_Top.soc.cpu.cpath.io_ctrl_pc_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_pc_we"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_dpath__io_pc_we, "Mock_Top.soc.cpu.dpath.io_pc_we", "");
  dat_table["Mock_Top.soc.cpu.dpath.pc"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__pc, "Mock_Top.soc.cpu.dpath.pc", "");
  dat_table["Mock_Top.soc.cpu.dpath.io_inst"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_dpath__io_inst, "Mock_Top.soc.cpu.dpath.io_inst", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_ctrl_inst"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_ctrl_inst, "Mock_Top.soc.cpu.cpath.io_ctrl_inst", "");
  dat_table["Mock_Top.soc.dev.ram_dev.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_ram_dev__io_bus_ack, "Mock_Top.soc.dev.ram_dev.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_ram_slave_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_ram_slave_ack, "Mock_Top.soc.dev.bus.io_ram_slave_ack", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev_2.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_2__io_bus_ack, "Mock_Top.soc.dev.WB_Empty_Dev_2.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_7_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_7_ack, "Mock_Top.soc.dev.bus.io_slaves_7_ack", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev_1.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev_1__io_bus_ack, "Mock_Top.soc.dev.WB_Empty_Dev_1.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_6_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_6_ack, "Mock_Top.soc.dev.bus.io_slaves_6_ack", "");
  dat_table["Mock_Top.soc.dev.WB_Empty_Dev.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_WB_Empty_Dev__io_bus_ack, "Mock_Top.soc.dev.WB_Empty_Dev.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_5_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_5_ack, "Mock_Top.soc.dev.bus.io_slaves_5_ack", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_bus_ack, "Mock_Top.soc.dev.seven_seg.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_4_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_4_ack, "Mock_Top.soc.dev.bus.io_slaves_4_ack", "");
  dat_table["Mock_Top.soc.dev.counter.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_counter__io_bus_ack, "Mock_Top.soc.dev.counter.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_3_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_3_ack, "Mock_Top.soc.dev.bus.io_slaves_3_ack", "");
  dat_table["Mock_Top.soc.dev.led.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_led__io_bus_ack, "Mock_Top.soc.dev.led.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_2_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_2_ack, "Mock_Top.soc.dev.bus.io_slaves_2_ack", "");
  dat_table["Mock_Top.soc.dev.btn.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_btn__io_bus_ack, "Mock_Top.soc.dev.btn.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_1_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_1_ack, "Mock_Top.soc.dev.bus.io_slaves_1_ack", "");
  dat_table["Mock_Top.soc.dev.sw.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_sw__io_bus_ack, "Mock_Top.soc.dev.sw.io_bus_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_slaves_0_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_slaves_0_ack, "Mock_Top.soc.dev.bus.io_slaves_0_ack", "");
  dat_table["Mock_Top.soc.dev.bus.io_from_cpu_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev_bus__io_from_cpu_ack, "Mock_Top.soc.dev.bus.io_from_cpu_ack", "");
  dat_table["Mock_Top.soc.dev.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_dev__io_bus_ack, "Mock_Top.soc.dev.io_bus_ack", "");
  dat_table["Mock_Top.soc.cpu.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu__io_bus_ack, "Mock_Top.soc.cpu.io_bus_ack", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_bus_ack"] = new dat_api<1>(&mod_typed->Mock_Top_soc_cpu_cpath__io_bus_ack, "Mock_Top.soc.cpu.cpath.io_bus_ack", "");
  dat_table["Mock_Top.soc.cpu.cpath.state"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__state, "Mock_Top.soc.cpu.cpath.state", "");
  dat_table["Mock_Top.soc.dev.seven_seg.io_DISP_NUM"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev_seven_seg__io_DISP_NUM, "Mock_Top.soc.dev.seven_seg.io_DISP_NUM", "");
  dat_table["Mock_Top.soc.dev.io_devices_DISP_NUM"] = new dat_api<32>(&mod_typed->Mock_Top_soc_dev__io_devices_DISP_NUM, "Mock_Top.soc.dev.io_devices_DISP_NUM", "");
  dat_table["Mock_Top.soc.io_devices_DISP_NUM"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_devices_DISP_NUM, "Mock_Top.soc.io_devices_DISP_NUM", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_debug_inst_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_debug_inst_out, "Mock_Top.soc.cpu.cpath.io_debug_inst_out", "");
  dat_table["Mock_Top.soc.cpu.io_debug_inst_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_debug_inst_out, "Mock_Top.soc.cpu.io_debug_inst_out", "");
  dat_table["Mock_Top.soc.io_debug_inst_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_debug_inst_out, "Mock_Top.soc.io_debug_inst_out", "");
  dat_table["Mock_Top.io_debug_inst_out"] = new dat_api<32>(&mod_typed->Mock_Top__io_debug_inst_out, "Mock_Top.io_debug_inst_out", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_addr, "Mock_Top.soc.cpu.cpath.io_debug_bus_addr", "");
  dat_table["Mock_Top.soc.cpu.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_debug_bus_addr, "Mock_Top.soc.cpu.io_debug_bus_addr", "");
  dat_table["Mock_Top.soc.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_debug_bus_addr, "Mock_Top.soc.io_debug_bus_addr", "");
  dat_table["Mock_Top.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->Mock_Top__io_debug_bus_addr, "Mock_Top.io_debug_bus_addr", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_dat2, "Mock_Top.soc.cpu.cpath.io_debug_bus_dat2", "");
  dat_table["Mock_Top.soc.cpu.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_debug_bus_dat2, "Mock_Top.soc.cpu.io_debug_bus_dat2", "");
  dat_table["Mock_Top.soc.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_debug_bus_dat2, "Mock_Top.soc.io_debug_bus_dat2", "");
  dat_table["Mock_Top.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->Mock_Top__io_debug_bus_dat2, "Mock_Top.io_debug_bus_dat2", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_debug_bus_dat4, "Mock_Top.soc.cpu.cpath.io_debug_bus_dat4", "");
  dat_table["Mock_Top.soc.cpu.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_debug_bus_dat4, "Mock_Top.soc.cpu.io_debug_bus_dat4", "");
  dat_table["Mock_Top.soc.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_debug_bus_dat4, "Mock_Top.soc.io_debug_bus_dat4", "");
  dat_table["Mock_Top.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->Mock_Top__io_debug_bus_dat4, "Mock_Top.io_debug_bus_dat4", "");
  dat_table["Mock_Top.soc.cpu.cpath.io_debug_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu_cpath__io_debug_pc_out, "Mock_Top.soc.cpu.cpath.io_debug_pc_out", "");
  dat_table["Mock_Top.soc.cpu.io_debug_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc_cpu__io_debug_pc_out, "Mock_Top.soc.cpu.io_debug_pc_out", "");
  dat_table["Mock_Top.soc.io_debug_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top_soc__io_debug_pc_out, "Mock_Top.soc.io_debug_pc_out", "");
  dat_table["Mock_Top.io_debug_pc_out"] = new dat_api<32>(&mod_typed->Mock_Top__io_debug_pc_out, "Mock_Top.io_debug_pc_out", "");
  dat_table["Mock_Top.soc.dev.led.io_LED"] = new dat_api<8>(&mod_typed->Mock_Top_soc_dev_led__io_LED, "Mock_Top.soc.dev.led.io_LED", "");
  dat_table["Mock_Top.soc.dev.io_devices_LED"] = new dat_api<8>(&mod_typed->Mock_Top_soc_dev__io_devices_LED, "Mock_Top.soc.dev.io_devices_LED", "");
  dat_table["Mock_Top.soc.io_devices_LED"] = new dat_api<8>(&mod_typed->Mock_Top_soc__io_devices_LED, "Mock_Top.soc.io_devices_LED", "");
  dat_table["Mock_Top.io_devices_LED"] = new dat_api<8>(&mod_typed->Mock_Top__io_devices_LED, "Mock_Top.io_devices_LED", "");
  dat_table["Mock_Top.io_devices_DISP_NUM"] = new dat_api<32>(&mod_typed->Mock_Top__io_devices_DISP_NUM, "Mock_Top.io_devices_DISP_NUM", "");
  dat_table["Mock_Top.io_devices_RAM_addra"] = new dat_api<10>(&mod_typed->Mock_Top__io_devices_RAM_addra, "Mock_Top.io_devices_RAM_addra", "");
  dat_table["Mock_Top.io_devices_RAM_dina"] = new dat_api<32>(&mod_typed->Mock_Top__io_devices_RAM_dina, "Mock_Top.io_devices_RAM_dina", "");
  dat_table["Mock_Top.io_devices_RAM_we"] = new dat_api<1>(&mod_typed->Mock_Top__io_devices_RAM_we, "Mock_Top.io_devices_RAM_we", "");
  dat_table["Mock_Top.io_devices_RAM_douta"] = new dat_api<32>(&mod_typed->Mock_Top__io_devices_RAM_douta, "Mock_Top.io_devices_RAM_douta", "");
}
