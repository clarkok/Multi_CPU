#include "SOC.h"

void SOC_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  SOC_dev_seven_seg__data_out.randomize(&__rand_seed);
  SOC_dev_seven_seg__disp_data.randomize(&__rand_seed);
  SOC_dev_led__data_out.randomize(&__rand_seed);
  SOC_dev_led__led_data.randomize(&__rand_seed);
  SOC_dev_bus__ack_out.randomize(&__rand_seed);
  SOC_cpu_dpath_regfile__rf.randomize(&__rand_seed);
  SOC_cpu_dpath__inst_reg.randomize(&__rand_seed);
  SOC_cpu_dpath__pc.randomize(&__rand_seed);
  SOC_cpu_cpath__state.randomize(&__rand_seed);
}


int SOC_t::clock ( dat_t<1> reset ) {
  uint32_t min = ((uint32_t)1<<31)-1;
  if (clk_cnt < min) min = clk_cnt;
  clk_cnt-=min;
  if (clk_cnt == 0) clock_hi( reset );
  if (clk_cnt == 0) clock_lo( reset );
  if (clk_cnt == 0) clk_cnt = clk;
  return min;
}


mod_t* SOC_t::clone() {
  mod_t* cloned = new SOC_t(*this);
  return cloned;
}


bool SOC_t::set_circuit_from ( mod_t* src ) {
  SOC_t* mod_typed = dynamic_cast<SOC_t*>(src);
  assert(mod_typed);
  SOC_cpu_dpath_regfile__io_addrb = mod_typed->SOC_cpu_dpath_regfile__io_addrb;
  SOC_cpu_dpath_regfile__io_doutb = mod_typed->SOC_cpu_dpath_regfile__io_doutb;
  SOC_cpu_dpath__io_data_out = mod_typed->SOC_cpu_dpath__io_data_out;
  SOC_cpu_cpath__io_ctrl_data_out = mod_typed->SOC_cpu_cpath__io_ctrl_data_out;
  SOC_cpu_cpath__io_bus_dat2 = mod_typed->SOC_cpu_cpath__io_bus_dat2;
  SOC_cpu__io_bus_dat2 = mod_typed->SOC_cpu__io_bus_dat2;
  SOC_dev__io_bus_dat2 = mod_typed->SOC_dev__io_bus_dat2;
  SOC_dev_bus__io_from_cpu_dat2 = mod_typed->SOC_dev_bus__io_from_cpu_dat2;
  SOC_dev_bus__io_slaves_4_dat2 = mod_typed->SOC_dev_bus__io_slaves_4_dat2;
  SOC_dev_seven_seg__io_bus_dat2 = mod_typed->SOC_dev_seven_seg__io_bus_dat2;
  SOC_cpu_dpath__io_pc_out = mod_typed->SOC_cpu_dpath__io_pc_out;
  SOC_cpu_cpath__io_ctrl_pc_out = mod_typed->SOC_cpu_cpath__io_ctrl_pc_out;
  SOC_cpu_cpath__io_ctrl_alu_b_sel = mod_typed->SOC_cpu_cpath__io_ctrl_alu_b_sel;
  SOC_cpu_dpath__io_alu_b_sel = mod_typed->SOC_cpu_dpath__io_alu_b_sel;
  SOC_cpu_dpath_alu__io_in_b = mod_typed->SOC_cpu_dpath_alu__io_in_b;
  SOC_cpu_dpath_regfile__io_addra = mod_typed->SOC_cpu_dpath_regfile__io_addra;
  SOC_cpu_dpath_regfile__io_douta = mod_typed->SOC_cpu_dpath_regfile__io_douta;
  SOC_cpu_dpath_alu__io_in_a = mod_typed->SOC_cpu_dpath_alu__io_in_a;
  SOC_cpu_cpath__io_ctrl_alu_op = mod_typed->SOC_cpu_cpath__io_ctrl_alu_op;
  SOC_cpu_dpath__io_alu_op = mod_typed->SOC_cpu_dpath__io_alu_op;
  SOC_cpu_dpath_alu__io_alu_op = mod_typed->SOC_cpu_dpath_alu__io_alu_op;
  SOC_cpu_dpath_alu__io_out = mod_typed->SOC_cpu_dpath_alu__io_out;
  SOC_cpu_dpath__io_alu_out = mod_typed->SOC_cpu_dpath__io_alu_out;
  SOC_cpu_cpath__io_ctrl_alu_out = mod_typed->SOC_cpu_cpath__io_ctrl_alu_out;
  SOC_cpu_cpath__io_bus_addr = mod_typed->SOC_cpu_cpath__io_bus_addr;
  SOC_cpu__io_bus_addr = mod_typed->SOC_cpu__io_bus_addr;
  SOC_dev__io_bus_addr = mod_typed->SOC_dev__io_bus_addr;
  SOC_dev_bus__io_from_cpu_addr = mod_typed->SOC_dev_bus__io_from_cpu_addr;
  SOC_cpu_cpath__io_bus_we = mod_typed->SOC_cpu_cpath__io_bus_we;
  SOC_cpu__io_bus_we = mod_typed->SOC_cpu__io_bus_we;
  SOC_dev__io_bus_we = mod_typed->SOC_dev__io_bus_we;
  SOC_dev_bus__io_from_cpu_we = mod_typed->SOC_dev_bus__io_from_cpu_we;
  SOC_dev_bus__io_slaves_4_we = mod_typed->SOC_dev_bus__io_slaves_4_we;
  SOC_dev_seven_seg__io_bus_we = mod_typed->SOC_dev_seven_seg__io_bus_we;
  SOC_cpu_cpath__io_bus_sel = mod_typed->SOC_cpu_cpath__io_bus_sel;
  SOC_cpu__io_bus_sel = mod_typed->SOC_cpu__io_bus_sel;
  SOC_dev__io_bus_sel = mod_typed->SOC_dev__io_bus_sel;
  SOC_dev_bus__io_from_cpu_sel = mod_typed->SOC_dev_bus__io_from_cpu_sel;
  SOC_dev_bus__io_slaves_4_sel = mod_typed->SOC_dev_bus__io_slaves_4_sel;
  SOC_dev_seven_seg__io_bus_sel = mod_typed->SOC_dev_seven_seg__io_bus_sel;
  SOC_dev__reset = mod_typed->SOC_dev__reset;
  SOC_dev_seven_seg__reset = mod_typed->SOC_dev_seven_seg__reset;
  T183 = mod_typed->T183;
  SOC_dev_seven_seg__data_out = mod_typed->SOC_dev_seven_seg__data_out;
  T185 = mod_typed->T185;
  SOC_dev_seven_seg__disp_data = mod_typed->SOC_dev_seven_seg__disp_data;
  SOC_dev_seven_seg__io_DISP_NUM = mod_typed->SOC_dev_seven_seg__io_DISP_NUM;
  SOC_dev_bus__io_slaves_2_dat2 = mod_typed->SOC_dev_bus__io_slaves_2_dat2;
  SOC_dev_led__io_bus_dat2 = mod_typed->SOC_dev_led__io_bus_dat2;
  SOC_dev_bus__io_slaves_2_we = mod_typed->SOC_dev_bus__io_slaves_2_we;
  SOC_dev_led__io_bus_we = mod_typed->SOC_dev_led__io_bus_we;
  SOC_dev_bus__io_slaves_2_sel = mod_typed->SOC_dev_bus__io_slaves_2_sel;
  SOC_dev_led__io_bus_sel = mod_typed->SOC_dev_led__io_bus_sel;
  SOC_dev_led__reset = mod_typed->SOC_dev_led__reset;
  T203 = mod_typed->T203;
  SOC_dev_led__data_out = mod_typed->SOC_dev_led__data_out;
  T207 = mod_typed->T207;
  SOC_dev_led__led_data = mod_typed->SOC_dev_led__led_data;
  SOC_dev_bus__reset = mod_typed->SOC_dev_bus__reset;
  T208 = mod_typed->T208;
  SOC_dev_bus__ack_out = mod_typed->SOC_dev_bus__ack_out;
  SOC_cpu_cpath__io_ctrl_reg_we_src = mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_src;
  SOC_cpu_dpath__io_reg_we_src = mod_typed->SOC_cpu_dpath__io_reg_we_src;
  SOC_dev_bus__io_ram_slave_addr = mod_typed->SOC_dev_bus__io_ram_slave_addr;
  SOC_dev_ram_dev__io_bus_addr = mod_typed->SOC_dev_ram_dev__io_bus_addr;
  SOC_dev_ram_dev__io_ram_addra = mod_typed->SOC_dev_ram_dev__io_ram_addra;
  SOC_dev_ram__io_addra = mod_typed->SOC_dev_ram__io_addra;
  SOC_dev_ram__io_douta = mod_typed->SOC_dev_ram__io_douta;
  SOC_dev_ram_dev__io_ram_douta = mod_typed->SOC_dev_ram_dev__io_ram_douta;
  SOC_dev_ram_dev__io_bus_dat4 = mod_typed->SOC_dev_ram_dev__io_bus_dat4;
  SOC_dev_bus__io_ram_slave_dat4 = mod_typed->SOC_dev_bus__io_ram_slave_dat4;
  SOC_dev_WB_Empty_Dev_2__io_bus_dat4 = mod_typed->SOC_dev_WB_Empty_Dev_2__io_bus_dat4;
  SOC_dev_bus__io_slaves_7_dat4 = mod_typed->SOC_dev_bus__io_slaves_7_dat4;
  SOC_dev_WB_Empty_Dev_1__io_bus_dat4 = mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_dat4;
  SOC_dev_bus__io_slaves_6_dat4 = mod_typed->SOC_dev_bus__io_slaves_6_dat4;
  SOC_dev_WB_Empty_Dev__io_bus_dat4 = mod_typed->SOC_dev_WB_Empty_Dev__io_bus_dat4;
  SOC_dev_bus__io_slaves_5_dat4 = mod_typed->SOC_dev_bus__io_slaves_5_dat4;
  SOC_dev_seven_seg__io_bus_dat4 = mod_typed->SOC_dev_seven_seg__io_bus_dat4;
  SOC_dev_bus__io_slaves_4_dat4 = mod_typed->SOC_dev_bus__io_slaves_4_dat4;
  SOC_dev_counter__io_bus_dat4 = mod_typed->SOC_dev_counter__io_bus_dat4;
  SOC_dev_bus__io_slaves_3_dat4 = mod_typed->SOC_dev_bus__io_slaves_3_dat4;
  SOC_dev_led__io_bus_dat4 = mod_typed->SOC_dev_led__io_bus_dat4;
  SOC_dev_bus__io_slaves_2_dat4 = mod_typed->SOC_dev_bus__io_slaves_2_dat4;
  SOC__io_devices_BTN = mod_typed->SOC__io_devices_BTN;
  SOC_dev__io_devices_BTN = mod_typed->SOC_dev__io_devices_BTN;
  SOC_dev_btn__io_BTN = mod_typed->SOC_dev_btn__io_BTN;
  SOC_dev_btn__io_bus_dat4 = mod_typed->SOC_dev_btn__io_bus_dat4;
  SOC_dev_bus__io_slaves_1_dat4 = mod_typed->SOC_dev_bus__io_slaves_1_dat4;
  SOC__io_devices_SW = mod_typed->SOC__io_devices_SW;
  SOC_dev__io_devices_SW = mod_typed->SOC_dev__io_devices_SW;
  SOC_dev_sw__io_SW = mod_typed->SOC_dev_sw__io_SW;
  SOC_dev_sw__io_bus_dat4 = mod_typed->SOC_dev_sw__io_bus_dat4;
  SOC_dev_bus__io_slaves_0_dat4 = mod_typed->SOC_dev_bus__io_slaves_0_dat4;
  SOC_dev_bus__io_from_cpu_dat4 = mod_typed->SOC_dev_bus__io_from_cpu_dat4;
  SOC_dev__io_bus_dat4 = mod_typed->SOC_dev__io_bus_dat4;
  SOC_cpu__io_bus_dat4 = mod_typed->SOC_cpu__io_bus_dat4;
  SOC_cpu_cpath__io_bus_dat4 = mod_typed->SOC_cpu_cpath__io_bus_dat4;
  SOC_cpu_cpath__io_ctrl_bus_data = mod_typed->SOC_cpu_cpath__io_ctrl_bus_data;
  SOC_cpu_dpath__io_bus_data = mod_typed->SOC_cpu_dpath__io_bus_data;
  SOC_cpu_dpath_regfile__io_wtdata = mod_typed->SOC_cpu_dpath_regfile__io_wtdata;
  SOC_cpu_cpath__io_ctrl_reg_we_dst = mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_dst;
  SOC_cpu_dpath__io_reg_we_dst = mod_typed->SOC_cpu_dpath__io_reg_we_dst;
  SOC_cpu_dpath_regfile__io_wtaddr = mod_typed->SOC_cpu_dpath_regfile__io_wtaddr;
  SOC_cpu_cpath__io_ctrl_reg_we = mod_typed->SOC_cpu_cpath__io_ctrl_reg_we;
  SOC_cpu_dpath__io_reg_we = mod_typed->SOC_cpu_dpath__io_reg_we;
  SOC_cpu_dpath_regfile__io_we = mod_typed->SOC_cpu_dpath_regfile__io_we;
  T369 = mod_typed->T369;
  SOC_cpu_dpath_regfile__rf = mod_typed->SOC_cpu_dpath_regfile__rf;
  SOC_cpu_cpath__io_ctrl_inst_we = mod_typed->SOC_cpu_cpath__io_ctrl_inst_we;
  SOC_cpu_dpath__io_inst_we = mod_typed->SOC_cpu_dpath__io_inst_we;
  SOC_cpu__reset = mod_typed->SOC_cpu__reset;
  SOC_cpu_dpath__reset = mod_typed->SOC_cpu_dpath__reset;
  T371 = mod_typed->T371;
  SOC_cpu_dpath__inst_reg = mod_typed->SOC_cpu_dpath__inst_reg;
  SOC_cpu_cpath__io_ctrl_pc_next_sel = mod_typed->SOC_cpu_cpath__io_ctrl_pc_next_sel;
  SOC_cpu_dpath__io_pc_next_sel = mod_typed->SOC_cpu_dpath__io_pc_next_sel;
  SOC_cpu_dpath_alu__io_zero = mod_typed->SOC_cpu_dpath_alu__io_zero;
  SOC_cpu_cpath__io_ctrl_pc_we = mod_typed->SOC_cpu_cpath__io_ctrl_pc_we;
  SOC_cpu_dpath__io_pc_we = mod_typed->SOC_cpu_dpath__io_pc_we;
  T430 = mod_typed->T430;
  SOC_cpu_dpath__pc = mod_typed->SOC_cpu_dpath__pc;
  SOC_cpu_dpath__io_inst = mod_typed->SOC_cpu_dpath__io_inst;
  SOC_cpu_cpath__io_ctrl_inst = mod_typed->SOC_cpu_cpath__io_ctrl_inst;
  SOC_dev_ram_dev__io_bus_ack = mod_typed->SOC_dev_ram_dev__io_bus_ack;
  SOC_dev_bus__io_ram_slave_ack = mod_typed->SOC_dev_bus__io_ram_slave_ack;
  SOC_dev_WB_Empty_Dev_2__io_bus_ack = mod_typed->SOC_dev_WB_Empty_Dev_2__io_bus_ack;
  SOC_dev_bus__io_slaves_7_ack = mod_typed->SOC_dev_bus__io_slaves_7_ack;
  SOC_dev_WB_Empty_Dev_1__io_bus_ack = mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_ack;
  SOC_dev_bus__io_slaves_6_ack = mod_typed->SOC_dev_bus__io_slaves_6_ack;
  SOC_dev_WB_Empty_Dev__io_bus_ack = mod_typed->SOC_dev_WB_Empty_Dev__io_bus_ack;
  SOC_dev_bus__io_slaves_5_ack = mod_typed->SOC_dev_bus__io_slaves_5_ack;
  SOC_dev_seven_seg__io_bus_ack = mod_typed->SOC_dev_seven_seg__io_bus_ack;
  SOC_dev_bus__io_slaves_4_ack = mod_typed->SOC_dev_bus__io_slaves_4_ack;
  SOC_dev_counter__io_bus_ack = mod_typed->SOC_dev_counter__io_bus_ack;
  SOC_dev_bus__io_slaves_3_ack = mod_typed->SOC_dev_bus__io_slaves_3_ack;
  SOC_dev_led__io_bus_ack = mod_typed->SOC_dev_led__io_bus_ack;
  SOC_dev_bus__io_slaves_2_ack = mod_typed->SOC_dev_bus__io_slaves_2_ack;
  SOC_dev_btn__io_bus_ack = mod_typed->SOC_dev_btn__io_bus_ack;
  SOC_dev_bus__io_slaves_1_ack = mod_typed->SOC_dev_bus__io_slaves_1_ack;
  SOC_dev_sw__io_bus_ack = mod_typed->SOC_dev_sw__io_bus_ack;
  SOC_dev_bus__io_slaves_0_ack = mod_typed->SOC_dev_bus__io_slaves_0_ack;
  SOC_dev_bus__io_from_cpu_ack = mod_typed->SOC_dev_bus__io_from_cpu_ack;
  SOC_dev__io_bus_ack = mod_typed->SOC_dev__io_bus_ack;
  SOC_cpu__io_bus_ack = mod_typed->SOC_cpu__io_bus_ack;
  SOC_cpu_cpath__io_bus_ack = mod_typed->SOC_cpu_cpath__io_bus_ack;
  SOC_cpu_cpath__reset = mod_typed->SOC_cpu_cpath__reset;
  T505 = mod_typed->T505;
  SOC_cpu_cpath__state = mod_typed->SOC_cpu_cpath__state;
  SOC_dev_led__io_LED = mod_typed->SOC_dev_led__io_LED;
  SOC_dev__io_devices_LED = mod_typed->SOC_dev__io_devices_LED;
  SOC__io_devices_LED = mod_typed->SOC__io_devices_LED;
  SOC_dev__io_devices_SEGMENT = mod_typed->SOC_dev__io_devices_SEGMENT;
  SOC__io_devices_SEGMENT = mod_typed->SOC__io_devices_SEGMENT;
  SOC_dev__io_devices_AN = mod_typed->SOC_dev__io_devices_AN;
  SOC__io_devices_AN = mod_typed->SOC__io_devices_AN;
  SOC_cpu_cpath__io_debug_inst_out = mod_typed->SOC_cpu_cpath__io_debug_inst_out;
  SOC_cpu__io_debug_inst_out = mod_typed->SOC_cpu__io_debug_inst_out;
  SOC__io_debug_inst_out = mod_typed->SOC__io_debug_inst_out;
  SOC_cpu_cpath__io_debug_bus_addr = mod_typed->SOC_cpu_cpath__io_debug_bus_addr;
  SOC_cpu__io_debug_bus_addr = mod_typed->SOC_cpu__io_debug_bus_addr;
  SOC__io_debug_bus_addr = mod_typed->SOC__io_debug_bus_addr;
  SOC_cpu_cpath__io_debug_bus_dat2 = mod_typed->SOC_cpu_cpath__io_debug_bus_dat2;
  SOC_cpu__io_debug_bus_dat2 = mod_typed->SOC_cpu__io_debug_bus_dat2;
  SOC__io_debug_bus_dat2 = mod_typed->SOC__io_debug_bus_dat2;
  SOC_cpu_cpath__io_debug_bus_dat4 = mod_typed->SOC_cpu_cpath__io_debug_bus_dat4;
  SOC_cpu__io_debug_bus_dat4 = mod_typed->SOC_cpu__io_debug_bus_dat4;
  SOC__io_debug_bus_dat4 = mod_typed->SOC__io_debug_bus_dat4;
  SOC_cpu_cpath__io_debug_pc_out = mod_typed->SOC_cpu_cpath__io_debug_pc_out;
  SOC_cpu__io_debug_pc_out = mod_typed->SOC_cpu__io_debug_pc_out;
  SOC__io_debug_pc_out = mod_typed->SOC__io_debug_pc_out;
  T507 = mod_typed->T507;
  T508 = mod_typed->T508;
  T569 = mod_typed->T569;
  T510 = mod_typed->T510;
  T511 = mod_typed->T511;
  T570 = mod_typed->T570;
  T513 = mod_typed->T513;
  T514 = mod_typed->T514;
  T571 = mod_typed->T571;
  T516 = mod_typed->T516;
  T517 = mod_typed->T517;
  T572 = mod_typed->T572;
  T519 = mod_typed->T519;
  T520 = mod_typed->T520;
  T573 = mod_typed->T573;
  T522 = mod_typed->T522;
  T523 = mod_typed->T523;
  T574 = mod_typed->T574;
  T525 = mod_typed->T525;
  T526 = mod_typed->T526;
  T575 = mod_typed->T575;
  T528 = mod_typed->T528;
  T529 = mod_typed->T529;
  T576 = mod_typed->T576;
  T531 = mod_typed->T531;
  T577 = mod_typed->T577;
  T533 = mod_typed->T533;
  T534 = mod_typed->T534;
  T578 = mod_typed->T578;
  T536 = mod_typed->T536;
  T537 = mod_typed->T537;
  T579 = mod_typed->T579;
  T539 = mod_typed->T539;
  T540 = mod_typed->T540;
  T580 = mod_typed->T580;
  T542 = mod_typed->T542;
  T543 = mod_typed->T543;
  T581 = mod_typed->T581;
  T545 = mod_typed->T545;
  T546 = mod_typed->T546;
  T582 = mod_typed->T582;
  T548 = mod_typed->T548;
  T549 = mod_typed->T549;
  T583 = mod_typed->T583;
  T551 = mod_typed->T551;
  T552 = mod_typed->T552;
  T584 = mod_typed->T584;
  T554 = mod_typed->T554;
  T555 = mod_typed->T555;
  T556 = mod_typed->T556;
  T557 = mod_typed->T557;
  T558 = mod_typed->T558;
  T559 = mod_typed->T559;
  T560 = mod_typed->T560;
  T561 = mod_typed->T561;
  T562 = mod_typed->T562;
  T563 = mod_typed->T563;
  T564 = mod_typed->T564;
  T565 = mod_typed->T565;
  T585 = mod_typed->T585;
  T567 = mod_typed->T567;
  T568 = mod_typed->T568;
  T586 = mod_typed->T586;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void SOC_t::print ( FILE* f ) {
#if __cplusplus >= 201103L
  if (T567.values[0]) dat_fprintf<168>(f, " - state: %d\n", T568);
#endif
#if __cplusplus >= 201103L
  if (T554.values[0]) dat_fprintf<336>(f, " - ctrls: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", T565, T564, T563, T562, T561, T560, T559, T558, T557, T556, T555);
#endif
#if __cplusplus >= 201103L
  if (T551.values[0]) dat_fprintf<144>(f, " - inst: %h\n", T552);
#endif
#if __cplusplus >= 201103L
  if (T548.values[0]) dat_fprintf<176>(f, " - inst_reg: %h\n", T549);
#endif
#if __cplusplus >= 201103L
  if (T545.values[0]) dat_fprintf<208>(f, " - next_state: %d\n", T546);
#endif
#if __cplusplus >= 201103L
  if (T542.values[0]) dat_fprintf<184>(f, " -- bus_addr: %h\n", T543);
#endif
#if __cplusplus >= 201103L
  if (T539.values[0]) dat_fprintf<184>(f, " -- bus_dat2: %h\n", T540);
#endif
#if __cplusplus >= 201103L
  if (T536.values[0]) dat_fprintf<184>(f, " -- bus_dat4: %h\n", T537);
#endif
#if __cplusplus >= 201103L
  if (T533.values[0]) dat_fprintf<176>(f, " -- alu_out: %h\n", T534);
#endif
#if __cplusplus >= 201103L
  if (T531.values[0]) dat_fprintf<8>(f, "\n");
#endif
#if __cplusplus >= 201103L
  if (T528.values[0]) dat_fprintf<176>(f, " --- current_slave: %d\n", T529);
#endif
#if __cplusplus >= 201103L
  if (T525.values[0]) dat_fprintf<120>(f, " --- cpu_we: %d\n", T526);
#endif
#if __cplusplus >= 201103L
  if (T522.values[0]) dat_fprintf<120>(f, " --- ram_op: %d\n", T523);
#endif
#if __cplusplus >= 201103L
  if (T519.values[0]) dat_fprintf<128>(f, " --- led_sel: %d\n", T520);
#endif
#if __cplusplus >= 201103L
  if (T516.values[0]) dat_fprintf<120>(f, " --- led_we: %d\n", T517);
#endif
#if __cplusplus >= 201103L
  if (T513.values[0]) dat_fprintf<104>(f, " ---- sel: %d\n", T514);
#endif
#if __cplusplus >= 201103L
  if (T510.values[0]) dat_fprintf<96>(f, " ---- we: %d\n", T511);
#endif
#if __cplusplus >= 201103L
  if (T507.values[0]) dat_fprintf<184>(f, " ---- data: %d\n", T508);
#endif
fflush(f);
}
void SOC_t::print ( std::ostream& s ) {
#if __cplusplus >= 201103L
  if (T567.values[0]) dat_prints<168>(s, " - state: %d\n", T568);
#endif
#if __cplusplus >= 201103L
  if (T554.values[0]) dat_prints<336>(s, " - ctrls: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", T565, T564, T563, T562, T561, T560, T559, T558, T557, T556, T555);
#endif
#if __cplusplus >= 201103L
  if (T551.values[0]) dat_prints<144>(s, " - inst: %h\n", T552);
#endif
#if __cplusplus >= 201103L
  if (T548.values[0]) dat_prints<176>(s, " - inst_reg: %h\n", T549);
#endif
#if __cplusplus >= 201103L
  if (T545.values[0]) dat_prints<208>(s, " - next_state: %d\n", T546);
#endif
#if __cplusplus >= 201103L
  if (T542.values[0]) dat_prints<184>(s, " -- bus_addr: %h\n", T543);
#endif
#if __cplusplus >= 201103L
  if (T539.values[0]) dat_prints<184>(s, " -- bus_dat2: %h\n", T540);
#endif
#if __cplusplus >= 201103L
  if (T536.values[0]) dat_prints<184>(s, " -- bus_dat4: %h\n", T537);
#endif
#if __cplusplus >= 201103L
  if (T533.values[0]) dat_prints<176>(s, " -- alu_out: %h\n", T534);
#endif
#if __cplusplus >= 201103L
  if (T531.values[0]) dat_prints<8>(s, "\n");
#endif
#if __cplusplus >= 201103L
  if (T528.values[0]) dat_prints<176>(s, " --- current_slave: %d\n", T529);
#endif
#if __cplusplus >= 201103L
  if (T525.values[0]) dat_prints<120>(s, " --- cpu_we: %d\n", T526);
#endif
#if __cplusplus >= 201103L
  if (T522.values[0]) dat_prints<120>(s, " --- ram_op: %d\n", T523);
#endif
#if __cplusplus >= 201103L
  if (T519.values[0]) dat_prints<128>(s, " --- led_sel: %d\n", T520);
#endif
#if __cplusplus >= 201103L
  if (T516.values[0]) dat_prints<120>(s, " --- led_we: %d\n", T517);
#endif
#if __cplusplus >= 201103L
  if (T513.values[0]) dat_prints<104>(s, " ---- sel: %d\n", T514);
#endif
#if __cplusplus >= 201103L
  if (T510.values[0]) dat_prints<96>(s, " ---- we: %d\n", T511);
#endif
#if __cplusplus >= 201103L
  if (T507.values[0]) dat_prints<184>(s, " ---- data: %d\n", T508);
#endif
s.flush();
}


void SOC_t::dump_init ( FILE* f ) {
}


void SOC_t::dump ( FILE* f, int t ) {
}




void SOC_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = SOC_cpu_dpath__inst_reg.values[0] >> 16;}
  T0 = T0 & 0x1fL;
  { SOC_cpu_dpath_regfile__io_addrb.values[0] = T0;}
  val_t T1;
  { T1 = SOC_cpu_dpath_regfile__rf.get(SOC_cpu_dpath_regfile__io_addrb.values[0], 0);}
  { SOC_cpu_dpath_regfile__io_doutb.values[0] = T1;}
  { SOC_cpu_dpath__io_data_out.values[0] = SOC_cpu_dpath_regfile__io_doutb.values[0];}
  { SOC_cpu_cpath__io_ctrl_data_out.values[0] = SOC_cpu_dpath__io_data_out.values[0];}
  { SOC_cpu_cpath__io_bus_dat2.values[0] = SOC_cpu_cpath__io_ctrl_data_out.values[0];}
  { SOC_cpu__io_bus_dat2.values[0] = SOC_cpu_cpath__io_bus_dat2.values[0];}
  { SOC_dev__io_bus_dat2.values[0] = SOC_cpu__io_bus_dat2.values[0];}
  { SOC_dev_bus__io_from_cpu_dat2.values[0] = SOC_dev__io_bus_dat2.values[0];}
  { SOC_dev_bus__io_slaves_4_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_seven_seg__io_bus_dat2.values[0] = SOC_dev_bus__io_slaves_4_dat2.values[0];}
  { SOC_cpu_dpath__io_pc_out.values[0] = SOC_cpu_dpath__pc.values[0];}
  { SOC_cpu_cpath__io_ctrl_pc_out.values[0] = SOC_cpu_dpath__io_pc_out.values[0];}
  val_t T2;
  T2 = SOC_cpu_cpath__state.values[0] == 0x13L;
  val_t T3;
  T3 = SOC_cpu_cpath__state.values[0] == 0x12L;
  val_t T4;
  { T4 = TERNARY(T3, 0x1L, T2);}
  val_t T5;
  T5 = SOC_cpu_cpath__state.values[0] == 0x11L;
  val_t T6;
  { T6 = TERNARY(T5, 0x0L, T4);}
  val_t T7;
  T7 = SOC_cpu_cpath__state.values[0] == 0x10L;
  val_t T8;
  { T8 = TERNARY(T7, 0x0L, T6);}
  val_t T9;
  T9 = SOC_cpu_cpath__state.values[0] == 0xfL;
  val_t T10;
  { T10 = TERNARY(T9, 0x0L, T8);}
  val_t T11;
  T11 = SOC_cpu_cpath__state.values[0] == 0xeL;
  val_t T12;
  { T12 = TERNARY(T11, 0x0L, T10);}
  val_t T13;
  T13 = SOC_cpu_cpath__state.values[0] == 0xdL;
  val_t T14;
  { T14 = TERNARY(T13, 0x0L, T12);}
  val_t T15;
  T15 = SOC_cpu_cpath__state.values[0] == 0xcL;
  val_t T16;
  { T16 = TERNARY(T15, 0x0L, T14);}
  val_t T17;
  T17 = SOC_cpu_cpath__state.values[0] == 0xbL;
  val_t T18;
  { T18 = TERNARY(T17, 0x0L, T16);}
  val_t T19;
  T19 = SOC_cpu_cpath__state.values[0] == 0xaL;
  val_t T20;
  { T20 = TERNARY(T19, 0x0L, T18);}
  val_t T21;
  T21 = SOC_cpu_cpath__state.values[0] == 0x9L;
  val_t T22;
  { T22 = TERNARY(T21, 0x0L, T20);}
  val_t T23;
  T23 = SOC_cpu_cpath__state.values[0] == 0x8L;
  val_t T24;
  { T24 = TERNARY(T23, 0x0L, T22);}
  val_t T25;
  T25 = SOC_cpu_cpath__state.values[0] == 0x7L;
  val_t T26;
  { T26 = TERNARY(T25, 0x0L, T24);}
  val_t T27;
  T27 = SOC_cpu_cpath__state.values[0] == 0x6L;
  val_t T28;
  { T28 = TERNARY(T27, 0x0L, T26);}
  val_t T29;
  T29 = SOC_cpu_cpath__state.values[0] == 0x5L;
  val_t T30;
  { T30 = TERNARY(T29, 0x0L, T28);}
  val_t T31;
  T31 = SOC_cpu_cpath__state.values[0] == 0x4L;
  val_t T32;
  { T32 = TERNARY(T31, 0x0L, T30);}
  val_t T33;
  T33 = SOC_cpu_cpath__state.values[0] == 0x3L;
  val_t T34;
  { T34 = TERNARY(T33, 0x0L, T32);}
  val_t T35;
  T35 = SOC_cpu_cpath__state.values[0] == 0x2L;
  val_t T36;
  { T36 = TERNARY(T35, 0x0L, T34);}
  val_t T37;
  T37 = SOC_cpu_cpath__state.values[0] == 0x1L;
  val_t T38;
  { T38 = TERNARY(T37, 0x0L, T36);}
  val_t SOC_cpu_cpath__inst_we;
  SOC_cpu_cpath__inst_we = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t SOC_cpu_cpath__bus_addr_src;
  { SOC_cpu_cpath__bus_addr_src = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T38);}
  val_t T39;
  T39 = SOC_cpu_cpath__bus_addr_src == 0x0L;
  val_t T40;
  { T40 = TERNARY(T39, SOC_cpu_cpath__io_ctrl_pc_out.values[0], 0x0L);}
  val_t T41;
  { T41 = ~SOC_cpu_dpath_regfile__io_doutb.values[0];}
  T41 = T41 & 0xffffffffL;
  val_t T42;
  T42 = SOC_cpu_cpath__state.values[0] == 0x16L;
  val_t T43;
  { T43 = T42 | 0x0L << 1;}
  val_t T44;
  T44 = SOC_cpu_cpath__state.values[0] == 0x15L;
  val_t T45;
  { T45 = TERNARY(T44, 0x2L, T43);}
  val_t T46;
  T46 = SOC_cpu_cpath__state.values[0] == 0x14L;
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
  val_t SOC_cpu_cpath__alu_b_sel;
  { SOC_cpu_cpath__alu_b_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T66);}
  val_t T67;
  T67 = (SOC_cpu_cpath__alu_b_sel >> 0) & 1;
  { SOC_cpu_cpath__io_ctrl_alu_b_sel.values[0] = T67;}
  { SOC_cpu_dpath__io_alu_b_sel.values[0] = SOC_cpu_cpath__io_ctrl_alu_b_sel.values[0];}
  val_t T68;
  { T68 = SOC_cpu_dpath__io_alu_b_sel.values[0] | 0x0L << 1;}
  val_t T69;
  T69 = T68 == 0x2L;
  val_t T70;
  { T70 = TERNARY(T69, T41, 0x0L);}
  val_t T71;
  { T71 = SOC_cpu_dpath__inst_reg.values[0];}
  T71 = T71 & 0xffffL;
  val_t T72;
  { T72 = T71 | 0x0L << 16;}
  val_t T73;
  T73 = SOC_cpu_dpath__io_alu_b_sel.values[0] == 0x1L;
  val_t T74;
  { T74 = TERNARY_1(T73, T72, T70);}
  val_t T75;
  T75 = SOC_cpu_dpath__io_alu_b_sel.values[0] == 0x0L;
  val_t T76;
  { T76 = TERNARY_1(T75, SOC_cpu_dpath_regfile__io_doutb.values[0], T74);}
  { SOC_cpu_dpath_alu__io_in_b.values[0] = T76;}
  val_t T77;
  { T77 = SOC_cpu_dpath__inst_reg.values[0] >> 21;}
  T77 = T77 & 0x1fL;
  { SOC_cpu_dpath_regfile__io_addra.values[0] = T77;}
  val_t T78;
  { T78 = SOC_cpu_dpath_regfile__rf.get(SOC_cpu_dpath_regfile__io_addra.values[0], 0);}
  { SOC_cpu_dpath_regfile__io_douta.values[0] = T78;}
  { SOC_cpu_dpath_alu__io_in_a.values[0] = SOC_cpu_dpath_regfile__io_douta.values[0];}
  val_t T79;
  T79 = SOC_cpu_dpath_alu__io_in_a.values[0]<SOC_cpu_dpath_alu__io_in_b.values[0];
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
  val_t SOC_cpu_cpath__alu_op;
  { SOC_cpu_cpath__alu_op = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T102);}
  { SOC_cpu_cpath__io_ctrl_alu_op.values[0] = SOC_cpu_cpath__alu_op;}
  { SOC_cpu_dpath__io_alu_op.values[0] = SOC_cpu_cpath__io_ctrl_alu_op.values[0];}
  { SOC_cpu_dpath_alu__io_alu_op.values[0] = SOC_cpu_dpath__io_alu_op.values[0];}
  val_t T103;
  T103 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x7L;
  val_t T104;
  { T104 = TERNARY(T103, T80, 0x0L);}
  val_t T105;
  { T105 = SOC_cpu_dpath_alu__io_in_a.values[0]-SOC_cpu_dpath_alu__io_in_b.values[0];}
  T105 = T105 & 0xffffffffL;
  val_t T106;
  T106 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x6L;
  val_t T107;
  { T107 = TERNARY_1(T106, T105, T104);}
  val_t T108;
  { T108 = SOC_cpu_dpath_alu__io_in_b.values[0];}
  T108 = T108 & 0x1fL;
  val_t T109;
  T109 = SOC_cpu_dpath_alu__io_in_a.values[0] >> T108;
  val_t T110;
  T110 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x5L;
  val_t T111;
  { T111 = TERNARY_1(T110, T109, T107);}
  val_t T112;
  { T112 = SOC_cpu_dpath_alu__io_in_a.values[0] | SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T113;
  { T113 = ~T112;}
  T113 = T113 & 0xffffffffL;
  val_t T114;
  T114 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x4L;
  val_t T115;
  { T115 = TERNARY_1(T114, T113, T111);}
  val_t T116;
  { T116 = SOC_cpu_dpath_alu__io_in_a.values[0] ^ SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T117;
  T117 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x3L;
  val_t T118;
  { T118 = TERNARY_1(T117, T116, T115);}
  val_t T119;
  { T119 = SOC_cpu_dpath_alu__io_in_a.values[0]+SOC_cpu_dpath_alu__io_in_b.values[0];}
  T119 = T119 & 0xffffffffL;
  val_t T120;
  T120 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x2L;
  val_t T121;
  { T121 = TERNARY_1(T120, T119, T118);}
  val_t T122;
  { T122 = SOC_cpu_dpath_alu__io_in_a.values[0] | SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T123;
  T123 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x1L;
  val_t T124;
  { T124 = TERNARY_1(T123, T122, T121);}
  val_t T125;
  { T125 = SOC_cpu_dpath_alu__io_in_a.values[0] & SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T126;
  T126 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x0L;
  val_t T127;
  { T127 = TERNARY_1(T126, T125, T124);}
  { SOC_cpu_dpath_alu__io_out.values[0] = T127;}
  { SOC_cpu_dpath__io_alu_out.values[0] = SOC_cpu_dpath_alu__io_out.values[0];}
  { SOC_cpu_cpath__io_ctrl_alu_out.values[0] = SOC_cpu_dpath__io_alu_out.values[0];}
  val_t T128;
  T128 = SOC_cpu_cpath__bus_addr_src == 0x1L;
  val_t T129;
  { T129 = TERNARY_1(T128, SOC_cpu_cpath__io_ctrl_alu_out.values[0], T40);}
  { SOC_cpu_cpath__io_bus_addr.values[0] = T129;}
  { SOC_cpu__io_bus_addr.values[0] = SOC_cpu_cpath__io_bus_addr.values[0];}
  { SOC_dev__io_bus_addr.values[0] = SOC_cpu__io_bus_addr.values[0];}
  { SOC_dev_bus__io_from_cpu_addr.values[0] = SOC_dev__io_bus_addr.values[0];}
  val_t SOC_dev_bus__current_slave;
  { SOC_dev_bus__current_slave = SOC_dev_bus__io_from_cpu_addr.values[0] >> 28;}
  SOC_dev_bus__current_slave = SOC_dev_bus__current_slave & 0x7L;
  val_t T130;
  T130 = SOC_dev_bus__current_slave == 0x4L;
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
  val_t SOC_cpu_cpath__bus_we;
  { SOC_cpu_cpath__bus_we = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T148);}
  { SOC_cpu_cpath__io_bus_we.values[0] = SOC_cpu_cpath__bus_we;}
  { SOC_cpu__io_bus_we.values[0] = SOC_cpu_cpath__io_bus_we.values[0];}
  { SOC_dev__io_bus_we.values[0] = SOC_cpu__io_bus_we.values[0];}
  { SOC_dev_bus__io_from_cpu_we.values[0] = SOC_dev__io_bus_we.values[0];}
  val_t T149;
  T149 = (SOC_dev_bus__io_from_cpu_addr.values[0] >> 31) & 1;
  val_t SOC_dev_bus__ram_op;
  { SOC_dev_bus__ram_op = ~T149;}
  SOC_dev_bus__ram_op = SOC_dev_bus__ram_op & 0x1L;
  val_t T150;
  { T150 = ~SOC_dev_bus__ram_op;}
  T150 = T150 & 0x1L;
  val_t T151;
  { T151 = T150 & SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T152;
  { T152 = T151 & T130;}
  { SOC_dev_bus__io_slaves_4_we.values[0] = T152;}
  { SOC_dev_seven_seg__io_bus_we.values[0] = SOC_dev_bus__io_slaves_4_we.values[0];}
  val_t T153;
  T153 = SOC_dev_bus__current_slave == 0x4L;
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
  val_t SOC_cpu_cpath__bus_sel;
  { SOC_cpu_cpath__bus_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x1L, T171);}
  { SOC_cpu_cpath__io_bus_sel.values[0] = SOC_cpu_cpath__bus_sel;}
  { SOC_cpu__io_bus_sel.values[0] = SOC_cpu_cpath__io_bus_sel.values[0];}
  { SOC_dev__io_bus_sel.values[0] = SOC_cpu__io_bus_sel.values[0];}
  { SOC_dev_bus__io_from_cpu_sel.values[0] = SOC_dev__io_bus_sel.values[0];}
  val_t T172;
  { T172 = ~SOC_dev_bus__ram_op;}
  T172 = T172 & 0x1L;
  val_t T173;
  { T173 = T172 & SOC_dev_bus__io_from_cpu_sel.values[0];}
  val_t T174;
  { T174 = T173 & T153;}
  { SOC_dev_bus__io_slaves_4_sel.values[0] = T174;}
  { SOC_dev_seven_seg__io_bus_sel.values[0] = SOC_dev_bus__io_slaves_4_sel.values[0];}
  val_t T175;
  { T175 = SOC_dev_seven_seg__io_bus_sel.values[0] & SOC_dev_seven_seg__io_bus_we.values[0];}
  val_t T176;
  { T176 = TERNARY_1(T175, SOC_dev_seven_seg__io_bus_dat2.values[0], SOC_dev_seven_seg__data_out.values[0]);}
  val_t T177;
  { T177 = T175 ^ 0x1L;}
  val_t T178;
  { T178 = T177 & SOC_dev_seven_seg__io_bus_sel.values[0];}
  val_t T179;
  { T179 = TERNARY_1(T178, SOC_dev_seven_seg__disp_data.values[0], T176);}
  val_t T180;
  { T180 = T175 | SOC_dev_seven_seg__io_bus_sel.values[0];}
  val_t T181;
  { T181 = T180 ^ 0x1L;}
  val_t T182;
  { T182 = TERNARY(T181, 0x0L, T179);}
  { SOC_dev__reset.values[0] = reset.values[0];}
  { SOC_dev_seven_seg__reset.values[0] = SOC_dev__reset.values[0];}
  { T183.values[0] = TERNARY(SOC_dev_seven_seg__reset.values[0], 0x0L, T182);}
  val_t T184;
  { T184 = TERNARY_1(T175, SOC_dev_seven_seg__io_bus_dat2.values[0], SOC_dev_seven_seg__disp_data.values[0]);}
  { T185.values[0] = TERNARY(SOC_dev_seven_seg__reset.values[0], 0x0L, T184);}
  { SOC_dev_seven_seg__io_DISP_NUM.values[0] = SOC_dev_seven_seg__disp_data.values[0];}
  { SOC_dev_bus__io_slaves_2_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_led__io_bus_dat2.values[0] = SOC_dev_bus__io_slaves_2_dat2.values[0];}
  val_t T186;
  T186 = SOC_dev_bus__current_slave == 0x2L;
  val_t T187;
  { T187 = ~SOC_dev_bus__ram_op;}
  T187 = T187 & 0x1L;
  val_t T188;
  { T188 = T187 & SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T189;
  { T189 = T188 & T186;}
  { SOC_dev_bus__io_slaves_2_we.values[0] = T189;}
  { SOC_dev_led__io_bus_we.values[0] = SOC_dev_bus__io_slaves_2_we.values[0];}
  val_t T190;
  T190 = SOC_dev_bus__current_slave == 0x2L;
  val_t T191;
  { T191 = ~SOC_dev_bus__ram_op;}
  T191 = T191 & 0x1L;
  val_t T192;
  { T192 = T191 & SOC_dev_bus__io_from_cpu_sel.values[0];}
  val_t T193;
  { T193 = T192 & T190;}
  { SOC_dev_bus__io_slaves_2_sel.values[0] = T193;}
  { SOC_dev_led__io_bus_sel.values[0] = SOC_dev_bus__io_slaves_2_sel.values[0];}
  val_t T194;
  { T194 = SOC_dev_led__io_bus_sel.values[0] & SOC_dev_led__io_bus_we.values[0];}
  val_t T195;
  { T195 = TERNARY_1(T194, SOC_dev_led__io_bus_dat2.values[0], SOC_dev_led__data_out.values[0]);}
  val_t T196;
  { T196 = SOC_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T197;
  { T197 = T194 ^ 0x1L;}
  val_t T198;
  { T198 = T197 & SOC_dev_led__io_bus_sel.values[0];}
  val_t T199;
  { T199 = TERNARY_1(T198, T196, T195);}
  val_t T200;
  { T200 = T194 | SOC_dev_led__io_bus_sel.values[0];}
  val_t T201;
  { T201 = T200 ^ 0x1L;}
  val_t T202;
  { T202 = TERNARY(T201, 0x0L, T199);}
  { SOC_dev_led__reset.values[0] = SOC_dev__reset.values[0];}
  { T203.values[0] = TERNARY(SOC_dev_led__reset.values[0], 0x0L, T202);}
  val_t T204;
  { T204 = SOC_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T205;
  { T205 = TERNARY_1(T194, SOC_dev_led__io_bus_dat2.values[0], T204);}
  val_t T206;
  { T206 = TERNARY(SOC_dev_led__reset.values[0], 0x0L, T205);}
  { T207.values[0] = T206;}
  T207.values[0] = T207.values[0] & 0xffL;
  { SOC_dev_bus__reset.values[0] = SOC_dev__reset.values[0];}
  { T208.values[0] = TERNARY(SOC_dev_bus__reset.values[0], 0x1L, SOC_dev_bus__ack_out.values[0]);}
  val_t T209;
  T209 = SOC_cpu_dpath_alu__io_out.values[0] << 0x10L;
  T209 = T209 & 0xffffffffffffL;
  val_t T210;
  T210 = SOC_cpu_cpath__state.values[0] == 0x18L;
  val_t T211;
  { T211 = TERNARY(T210, 0x2L, 0x0L);}
  val_t T212;
  T212 = SOC_cpu_cpath__state.values[0] == 0x17L;
  val_t T213;
  { T213 = TERNARY(T212, 0x0L, T211);}
  val_t T214;
  { T214 = TERNARY(T42, 0x0L, T213);}
  val_t T215;
  { T215 = TERNARY(T44, 0x0L, T214);}
  val_t T216;
  { T216 = TERNARY(T46, 0x0L, T215);}
  val_t T217;
  { T217 = TERNARY(T2, 0x0L, T216);}
  val_t T218;
  { T218 = TERNARY(T3, 0x1L, T217);}
  val_t T219;
  { T219 = TERNARY(T5, 0x3L, T218);}
  val_t T220;
  { T220 = TERNARY(T7, 0x0L, T219);}
  val_t T221;
  { T221 = TERNARY(T9, 0x0L, T220);}
  val_t T222;
  { T222 = TERNARY(T11, 0x0L, T221);}
  val_t T223;
  { T223 = TERNARY(T13, 0x0L, T222);}
  val_t T224;
  { T224 = TERNARY(T15, 0x0L, T223);}
  val_t T225;
  { T225 = TERNARY(T17, 0x0L, T224);}
  val_t T226;
  { T226 = TERNARY(T19, 0x0L, T225);}
  val_t T227;
  { T227 = TERNARY(T21, 0x0L, T226);}
  val_t T228;
  { T228 = TERNARY(T23, 0x0L, T227);}
  val_t T229;
  { T229 = TERNARY(T25, 0x0L, T228);}
  val_t T230;
  { T230 = TERNARY(T27, 0x0L, T229);}
  val_t T231;
  { T231 = TERNARY(T29, 0x0L, T230);}
  val_t T232;
  { T232 = TERNARY(T31, 0x0L, T231);}
  val_t T233;
  { T233 = TERNARY(T33, 0x0L, T232);}
  val_t T234;
  { T234 = TERNARY(T35, 0x0L, T233);}
  val_t T235;
  { T235 = TERNARY(T37, 0x0L, T234);}
  val_t SOC_cpu_cpath__reg_we_src;
  { SOC_cpu_cpath__reg_we_src = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T235);}
  { SOC_cpu_cpath__io_ctrl_reg_we_src.values[0] = SOC_cpu_cpath__reg_we_src;}
  { SOC_cpu_dpath__io_reg_we_src.values[0] = SOC_cpu_cpath__io_ctrl_reg_we_src.values[0];}
  val_t T236;
  T236 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x3L;
  val_t T237;
  { T237 = TERNARY(T236, T209, 0x0L);}
  val_t T238;
  { T238 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T238 = T238 & 0xffffffffL;
  val_t T239;
  { T239 = T238 | 0x0L << 32;}
  val_t T240;
  T240 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x2L;
  val_t T241;
  { T241 = TERNARY_1(T240, T239, T237);}
  val_t T242;
  { T242 = SOC_dev_bus__io_from_cpu_addr.values[0];}
  T242 = T242 & 0xfffffffL;
  val_t T243;
  { T243 = T242 | 0x0L << 28;}
  { SOC_dev_bus__io_ram_slave_addr.values[0] = T243;}
  { SOC_dev_ram_dev__io_bus_addr.values[0] = SOC_dev_bus__io_ram_slave_addr.values[0];}
  val_t T244;
  { T244 = SOC_dev_ram_dev__io_bus_addr.values[0] >> 2;}
  T244 = T244 & 0x3ffL;
  { SOC_dev_ram_dev__io_ram_addra.values[0] = T244;}
  { SOC_dev_ram__io_addra.values[0] = SOC_dev_ram_dev__io_ram_addra.values[0];}
  val_t T245;
  T245 = SOC_dev_ram__io_addra.values[0] == 0xbL;
  val_t T246;
  { T246 = TERNARY(T245, 0xac820000L, 0x0L);}
  val_t T247;
  T247 = SOC_dev_ram__io_addra.values[0] == 0xaL;
  val_t T248;
  { T248 = TERNARY(T247, 0x20420001L, T246);}
  val_t T249;
  T249 = SOC_dev_ram__io_addra.values[0] == 0x9L;
  val_t T250;
  { T250 = TERNARY(T249, 0x200008L, T248);}
  val_t T251;
  T251 = SOC_dev_ram__io_addra.values[0] == 0x8L;
  val_t T252;
  { T252 = TERNARY(T251, 0x2001002cL, T250);}
  val_t T253;
  T253 = SOC_dev_ram__io_addra.values[0] == 0x7L;
  val_t T254;
  { T254 = TERNARY(T253, 0xac830000L, T252);}
  val_t T255;
  T255 = SOC_dev_ram__io_addra.values[0] == 0x6L;
  val_t T256;
  { T256 = TERNARY(T255, 0x411806L, T254);}
  val_t T257;
  T257 = SOC_dev_ram__io_addra.values[0] == 0x5L;
  val_t T258;
  { T258 = TERNARY(T257, 0x20020010L, T256);}
  val_t T259;
  T259 = SOC_dev_ram__io_addra.values[0] == 0x4L;
  val_t T260;
  { T260 = TERNARY(T259, 0xac830000L, T258);}
  val_t T261;
  T261 = SOC_dev_ram__io_addra.values[0] == 0x3L;
  val_t T262;
  { T262 = TERNARY(T261, 0x3c04a000L, T260);}
  val_t T263;
  T263 = SOC_dev_ram__io_addra.values[0] == 0x2L;
  val_t T264;
  { T264 = TERNARY(T263, 0x22182aL, T262);}
  val_t T265;
  T265 = SOC_dev_ram__io_addra.values[0] == 0x1L;
  val_t T266;
  { T266 = TERNARY(T265, 0x20020002L, T264);}
  val_t T267;
  T267 = SOC_dev_ram__io_addra.values[0] == 0x0L;
  val_t T268;
  { T268 = TERNARY(T267, 0x20010001L, T266);}
  { SOC_dev_ram__io_douta.values[0] = T268;}
  { SOC_dev_ram_dev__io_ram_douta.values[0] = SOC_dev_ram__io_douta.values[0];}
  val_t T269;
  { T269 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 24;}
  T269 = T269 & 0xffL;
  val_t T270;
  { T270 = T269 | 0x0L << 8;}
  val_t T271;
  { T271 = SOC_dev_ram_dev__io_bus_addr.values[0];}
  T271 = T271 & 0x3L;
  val_t T272;
  T272 = T271 == 0x3L;
  val_t T273;
  { T273 = TERNARY_1(T272, T270, SOC_dev_ram_dev__io_ram_douta.values[0]);}
  val_t T274;
  { T274 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 16;}
  T274 = T274 & 0xffffL;
  val_t T275;
  { T275 = T274 | 0x0L << 16;}
  val_t T276;
  T276 = T271 == 0x2L;
  val_t T277;
  { T277 = TERNARY_1(T276, T275, T273);}
  val_t T278;
  { T278 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 8;}
  T278 = T278 & 0xffffffL;
  val_t T279;
  { T279 = T278 | 0x0L << 24;}
  val_t T280;
  T280 = T271 == 0x1L;
  val_t T281;
  { T281 = TERNARY_1(T280, T279, T277);}
  val_t T282;
  T282 = T271 == 0x0L;
  val_t T283;
  { T283 = TERNARY_1(T282, SOC_dev_ram_dev__io_ram_douta.values[0], T281);}
  { SOC_dev_ram_dev__io_bus_dat4.values[0] = T283;}
  { SOC_dev_bus__io_ram_slave_dat4.values[0] = SOC_dev_ram_dev__io_bus_dat4.values[0];}
  val_t T284;
  T284 = SOC_dev_bus__ram_op == 0x1L;
  val_t T285;
  { T285 = TERNARY(T284, SOC_dev_bus__io_ram_slave_dat4.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_2__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_7_dat4.values[0] = SOC_dev_WB_Empty_Dev_2__io_bus_dat4.values[0];}
  val_t T286;
  T286 = SOC_dev_bus__current_slave == 0x7L;
  val_t T287;
  { T287 = TERNARY(T286, SOC_dev_bus__io_slaves_7_dat4.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_1__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_6_dat4.values[0] = SOC_dev_WB_Empty_Dev_1__io_bus_dat4.values[0];}
  val_t T288;
  T288 = SOC_dev_bus__current_slave == 0x6L;
  val_t T289;
  { T289 = TERNARY(T288, SOC_dev_bus__io_slaves_6_dat4.values[0], T287);}
  { SOC_dev_WB_Empty_Dev__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_5_dat4.values[0] = SOC_dev_WB_Empty_Dev__io_bus_dat4.values[0];}
  val_t T290;
  T290 = SOC_dev_bus__current_slave == 0x5L;
  val_t T291;
  { T291 = TERNARY(T290, SOC_dev_bus__io_slaves_5_dat4.values[0], T289);}
  { SOC_dev_seven_seg__io_bus_dat4.values[0] = SOC_dev_seven_seg__data_out.values[0];}
  { SOC_dev_bus__io_slaves_4_dat4.values[0] = SOC_dev_seven_seg__io_bus_dat4.values[0];}
  val_t T292;
  T292 = SOC_dev_bus__current_slave == 0x4L;
  val_t T293;
  { T293 = TERNARY_1(T292, SOC_dev_bus__io_slaves_4_dat4.values[0], T291);}
  { SOC_dev_counter__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_3_dat4.values[0] = SOC_dev_counter__io_bus_dat4.values[0];}
  val_t T294;
  T294 = SOC_dev_bus__current_slave == 0x3L;
  val_t T295;
  { T295 = TERNARY(T294, SOC_dev_bus__io_slaves_3_dat4.values[0], T293);}
  { SOC_dev_led__io_bus_dat4.values[0] = SOC_dev_led__data_out.values[0];}
  { SOC_dev_bus__io_slaves_2_dat4.values[0] = SOC_dev_led__io_bus_dat4.values[0];}
  val_t T296;
  T296 = SOC_dev_bus__current_slave == 0x2L;
  val_t T297;
  { T297 = TERNARY_1(T296, SOC_dev_bus__io_slaves_2_dat4.values[0], T295);}
  { SOC_dev__io_devices_BTN.values[0] = SOC__io_devices_BTN.values[0];}
  { SOC_dev_btn__io_BTN.values[0] = SOC_dev__io_devices_BTN.values[0];}
  val_t T298;
  { T298 = SOC_dev_btn__io_BTN.values[0] | 0x0L << 5;}
  { SOC_dev_btn__io_bus_dat4.values[0] = T298;}
  { SOC_dev_bus__io_slaves_1_dat4.values[0] = SOC_dev_btn__io_bus_dat4.values[0];}
  val_t T299;
  T299 = SOC_dev_bus__current_slave == 0x1L;
  val_t T300;
  { T300 = TERNARY_1(T299, SOC_dev_bus__io_slaves_1_dat4.values[0], T297);}
  { SOC_dev__io_devices_SW.values[0] = SOC__io_devices_SW.values[0];}
  { SOC_dev_sw__io_SW.values[0] = SOC_dev__io_devices_SW.values[0];}
  val_t T301;
  { T301 = SOC_dev_sw__io_SW.values[0] | 0x0L << 8;}
  { SOC_dev_sw__io_bus_dat4.values[0] = T301;}
  { SOC_dev_bus__io_slaves_0_dat4.values[0] = SOC_dev_sw__io_bus_dat4.values[0];}
  val_t T302;
  T302 = SOC_dev_bus__current_slave == 0x0L;
  val_t T303;
  { T303 = TERNARY_1(T302, SOC_dev_bus__io_slaves_0_dat4.values[0], T300);}
  val_t T304;
  T304 = SOC_dev_bus__ram_op == 0x0L;
  val_t T305;
  { T305 = TERNARY_1(T304, T303, T285);}
  { SOC_dev_bus__io_from_cpu_dat4.values[0] = T305;}
  { SOC_dev__io_bus_dat4.values[0] = SOC_dev_bus__io_from_cpu_dat4.values[0];}
  { SOC_cpu__io_bus_dat4.values[0] = SOC_dev__io_bus_dat4.values[0];}
  { SOC_cpu_cpath__io_bus_dat4.values[0] = SOC_cpu__io_bus_dat4.values[0];}
  { SOC_cpu_cpath__io_ctrl_bus_data.values[0] = SOC_cpu_cpath__io_bus_dat4.values[0];}
  { SOC_cpu_dpath__io_bus_data.values[0] = SOC_cpu_cpath__io_ctrl_bus_data.values[0];}
  val_t T306;
  { T306 = SOC_cpu_dpath__io_bus_data.values[0] | 0x0L << 32;}
  val_t T307;
  T307 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x1L;
  val_t T308;
  { T308 = TERNARY_1(T307, T306, T241);}
  val_t T309;
  { T309 = SOC_cpu_dpath_alu__io_out.values[0] | 0x0L << 32;}
  val_t T310;
  T310 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x0L;
  val_t T311;
  { T311 = TERNARY_1(T310, T309, T308);}
  val_t T312;
  { T312 = T311;}
  T312 = T312 & 0xffffffffL;
  { SOC_cpu_dpath_regfile__io_wtdata.values[0] = T312;}
  val_t T313;
  { T313 = TERNARY(T210, 0x2L, 0x0L);}
  val_t T314;
  { T314 = TERNARY(T212, 0x0L, T313);}
  val_t T315;
  { T315 = TERNARY(T42, 0x1L, T314);}
  val_t T316;
  { T316 = TERNARY(T44, 0x0L, T315);}
  val_t T317;
  { T317 = TERNARY(T46, 0x0L, T316);}
  val_t T318;
  { T318 = TERNARY(T2, 0x0L, T317);}
  val_t T319;
  { T319 = TERNARY(T3, 0x1L, T318);}
  val_t T320;
  { T320 = TERNARY(T5, 0x1L, T319);}
  val_t T321;
  { T321 = TERNARY(T7, 0x1L, T320);}
  val_t T322;
  { T322 = TERNARY(T9, 0x1L, T321);}
  val_t T323;
  { T323 = TERNARY(T11, 0x1L, T322);}
  val_t T324;
  { T324 = TERNARY(T13, 0x1L, T323);}
  val_t T325;
  { T325 = TERNARY(T15, 0x1L, T324);}
  val_t T326;
  { T326 = TERNARY(T17, 0x0L, T325);}
  val_t T327;
  { T327 = TERNARY(T19, 0x0L, T326);}
  val_t T328;
  { T328 = TERNARY(T21, 0x0L, T327);}
  val_t T329;
  { T329 = TERNARY(T23, 0x0L, T328);}
  val_t T330;
  { T330 = TERNARY(T25, 0x0L, T329);}
  val_t T331;
  { T331 = TERNARY(T27, 0x0L, T330);}
  val_t T332;
  { T332 = TERNARY(T29, 0x0L, T331);}
  val_t T333;
  { T333 = TERNARY(T31, 0x0L, T332);}
  val_t T334;
  { T334 = TERNARY(T33, 0x0L, T333);}
  val_t T335;
  { T335 = TERNARY(T35, 0x0L, T334);}
  val_t T336;
  { T336 = TERNARY(T37, 0x0L, T335);}
  val_t SOC_cpu_cpath__reg_we_dst;
  { SOC_cpu_cpath__reg_we_dst = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T336);}
  { SOC_cpu_cpath__io_ctrl_reg_we_dst.values[0] = SOC_cpu_cpath__reg_we_dst;}
  { SOC_cpu_dpath__io_reg_we_dst.values[0] = SOC_cpu_cpath__io_ctrl_reg_we_dst.values[0];}
  val_t T337;
  T337 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x2L;
  val_t T338;
  { T338 = TERNARY(T337, 0x1fL, 0x0L);}
  val_t T339;
  { T339 = SOC_cpu_dpath__inst_reg.values[0] >> 16;}
  T339 = T339 & 0x1fL;
  val_t T340;
  T340 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x1L;
  val_t T341;
  { T341 = TERNARY_1(T340, T339, T338);}
  val_t T342;
  { T342 = SOC_cpu_dpath__inst_reg.values[0] >> 11;}
  T342 = T342 & 0x1fL;
  val_t T343;
  T343 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x0L;
  val_t T344;
  { T344 = TERNARY_1(T343, T342, T341);}
  { SOC_cpu_dpath_regfile__io_wtaddr.values[0] = T344;}
  val_t T345;
  T345 = SOC_cpu_dpath_regfile__io_wtaddr.values[0] != 0x0L;
  val_t T346;
  { T346 = TERNARY(T212, 0x0L, T210);}
  val_t T347;
  { T347 = TERNARY(T42, 0x1L, T346);}
  val_t T348;
  { T348 = TERNARY(T44, 0x0L, T347);}
  val_t T349;
  { T349 = TERNARY(T46, 0x0L, T348);}
  val_t T350;
  { T350 = TERNARY(T2, 0x0L, T349);}
  val_t T351;
  { T351 = TERNARY(T3, 0x1L, T350);}
  val_t T352;
  { T352 = TERNARY(T5, 0x1L, T351);}
  val_t T353;
  { T353 = TERNARY(T7, 0x1L, T352);}
  val_t T354;
  { T354 = TERNARY(T9, 0x1L, T353);}
  val_t T355;
  { T355 = TERNARY(T11, 0x1L, T354);}
  val_t T356;
  { T356 = TERNARY(T13, 0x1L, T355);}
  val_t T357;
  { T357 = TERNARY(T15, 0x1L, T356);}
  val_t T358;
  { T358 = TERNARY(T17, 0x0L, T357);}
  val_t T359;
  { T359 = TERNARY(T19, 0x1L, T358);}
  val_t T360;
  { T360 = TERNARY(T21, 0x1L, T359);}
  val_t T361;
  { T361 = TERNARY(T23, 0x1L, T360);}
  val_t T362;
  { T362 = TERNARY(T25, 0x1L, T361);}
  val_t T363;
  { T363 = TERNARY(T27, 0x1L, T362);}
  val_t T364;
  { T364 = TERNARY(T29, 0x1L, T363);}
  val_t T365;
  { T365 = TERNARY(T31, 0x1L, T364);}
  val_t T366;
  { T366 = TERNARY(T33, 0x1L, T365);}
  val_t T367;
  { T367 = TERNARY(T35, 0x1L, T366);}
  val_t T368;
  { T368 = TERNARY(T37, 0x1L, T367);}
  val_t SOC_cpu_cpath__reg_we;
  { SOC_cpu_cpath__reg_we = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T368);}
  { SOC_cpu_cpath__io_ctrl_reg_we.values[0] = SOC_cpu_cpath__reg_we;}
  { SOC_cpu_dpath__io_reg_we.values[0] = SOC_cpu_cpath__io_ctrl_reg_we.values[0];}
  { SOC_cpu_dpath_regfile__io_we.values[0] = SOC_cpu_dpath__io_reg_we.values[0];}
  { T369.values[0] = SOC_cpu_dpath_regfile__io_we.values[0] & T345;}
  { SOC_cpu_cpath__io_ctrl_inst_we.values[0] = SOC_cpu_cpath__inst_we;}
  { SOC_cpu_dpath__io_inst_we.values[0] = SOC_cpu_cpath__io_ctrl_inst_we.values[0];}
  val_t T370;
  { T370 = TERNARY_1(SOC_cpu_dpath__io_inst_we.values[0], SOC_cpu_dpath__io_bus_data.values[0], SOC_cpu_dpath__inst_reg.values[0]);}
  { SOC_cpu__reset.values[0] = reset.values[0];}
  { SOC_cpu_dpath__reset.values[0] = SOC_cpu__reset.values[0];}
  { T371.values[0] = TERNARY(SOC_cpu_dpath__reset.values[0], 0x0L, T370);}
  val_t T372;
  { T372 = SOC_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T373;
  { T373 = TERNARY(T210, 0x2L, 0x0L);}
  val_t T374;
  { T374 = TERNARY(T212, 0x2L, T373);}
  val_t T375;
  { T375 = TERNARY(T42, 0x0L, T374);}
  val_t T376;
  { T376 = TERNARY(T44, 0x1L, T375);}
  val_t T377;
  { T377 = TERNARY(T46, 0x1L, T376);}
  val_t T378;
  { T378 = TERNARY(T2, 0x0L, T377);}
  val_t T379;
  { T379 = TERNARY(T3, 0x0L, T378);}
  val_t T380;
  { T380 = TERNARY(T5, 0x0L, T379);}
  val_t T381;
  { T381 = TERNARY(T7, 0x0L, T380);}
  val_t T382;
  { T382 = TERNARY(T9, 0x0L, T381);}
  val_t T383;
  { T383 = TERNARY(T11, 0x0L, T382);}
  val_t T384;
  { T384 = TERNARY(T13, 0x0L, T383);}
  val_t T385;
  { T385 = TERNARY(T15, 0x0L, T384);}
  val_t T386;
  { T386 = TERNARY(T17, 0x3L, T385);}
  val_t T387;
  { T387 = TERNARY(T19, 0x0L, T386);}
  val_t T388;
  { T388 = TERNARY(T21, 0x0L, T387);}
  val_t T389;
  { T389 = TERNARY(T23, 0x0L, T388);}
  val_t T390;
  { T390 = TERNARY(T25, 0x0L, T389);}
  val_t T391;
  { T391 = TERNARY(T27, 0x0L, T390);}
  val_t T392;
  { T392 = TERNARY(T29, 0x0L, T391);}
  val_t T393;
  { T393 = TERNARY(T31, 0x0L, T392);}
  val_t T394;
  { T394 = TERNARY(T33, 0x0L, T393);}
  val_t T395;
  { T395 = TERNARY(T35, 0x0L, T394);}
  val_t T396;
  { T396 = TERNARY(T37, 0x0L, T395);}
  val_t SOC_cpu_cpath__pc_next_sel;
  { SOC_cpu_cpath__pc_next_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T396);}
  { SOC_cpu_cpath__io_ctrl_pc_next_sel.values[0] = SOC_cpu_cpath__pc_next_sel;}
  { SOC_cpu_dpath__io_pc_next_sel.values[0] = SOC_cpu_cpath__io_ctrl_pc_next_sel.values[0];}
  val_t T397;
  T397 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x3L;
  val_t T398;
  { T398 = TERNARY(T397, SOC_cpu_dpath_regfile__io_douta.values[0], 0x0L);}
  val_t T399;
  { T399 = SOC_cpu_dpath__inst_reg.values[0];}
  T399 = T399 & 0x3ffffffL;
  val_t T400;
  T400 = T399 << 0x2L;
  T400 = T400 & 0xfffffffL;
  val_t T401;
  { T401 = SOC_cpu_dpath__pc.values[0] >> 28;}
  T401 = T401 & 0xfL;
  val_t T402;
  { T402 = T401 | 0x0L << 4;}
  val_t T403;
  { T403 = T402 | T400;}
  val_t T404;
  { T404 = T403 | 0x0L << 28;}
  val_t T405;
  T405 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x2L;
  val_t T406;
  { T406 = TERNARY_1(T405, T404, T398);}
  val_t T407;
  { T407 = T406 | 0x0L << 32;}
  val_t T408;
  { T408 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T408 = T408 & 0xffffffffL;
  val_t T409;
  T409 = SOC_cpu_dpath_alu__io_out.values[0] != 0x0L;
  val_t T410;
  { T410 = T409 ^ 0x1L;}
  { SOC_cpu_dpath_alu__io_zero.values[0] = T410;}
  val_t T411;
  T411 = SOC_cpu_dpath_alu__io_zero.values[0] == 0x0L;
  val_t T412;
  { T412 = TERNARY(T411, T408, 0x0L);}
  val_t T413;
  { T413 = T412 | 0x0L << 32;}
  val_t T414;
  { T414 = SOC_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T415;
  { T415 = SOC_cpu_dpath__inst_reg.values[0];}
  T415 = T415 & 0xffffL;
  val_t T416;
  T416 = T415 << 0x2L;
  T416 = T416 & 0x3ffffL;
  val_t T417;
  T417 = (T416 >> 17) & 1;
  val_t T418;
  { T418 = TERNARY(T417, 0x7fffL, 0x0L);}
  val_t T419;
  { T419 = T416 | T418 << 18;}
  val_t T420;
  { T420 = T419+T414;}
  T420 = T420 & 0x1ffffffffL;
  val_t T421;
  T421 = SOC_cpu_dpath_alu__io_zero.values[0] == 0x1L;
  val_t T422;
  { T422 = TERNARY_1(T421, T420, T413);}
  val_t T423;
  T423 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x1L;
  val_t T424;
  { T424 = TERNARY_1(T423, T422, T407);}
  val_t T425;
  { T425 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T425 = T425 & 0xffffffffL;
  val_t T426;
  { T426 = T425 | 0x0L << 32;}
  val_t T427;
  T427 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x0L;
  val_t SOC_cpu_dpath__pc_next;
  { SOC_cpu_dpath__pc_next = TERNARY_1(T427, T426, T424);}
  val_t SOC_cpu_cpath__pc_we;
  SOC_cpu_cpath__pc_we = SOC_cpu_cpath__inst_we == 0x0L;
  { SOC_cpu_cpath__io_ctrl_pc_we.values[0] = SOC_cpu_cpath__pc_we;}
  { SOC_cpu_dpath__io_pc_we.values[0] = SOC_cpu_cpath__io_ctrl_pc_we.values[0];}
  val_t T428;
  { T428 = TERNARY_1(SOC_cpu_dpath__io_pc_we.values[0], SOC_cpu_dpath__pc_next, T372);}
  val_t T429;
  { T429 = TERNARY(SOC_cpu_dpath__reset.values[0], 0x0L, T428);}
  { T430.values[0] = T429;}
  T430.values[0] = T430.values[0] & 0xffffffffL;
  { SOC_cpu_dpath__io_inst.values[0] = SOC_cpu_dpath__inst_reg.values[0];}
  { SOC_cpu_cpath__io_ctrl_inst.values[0] = SOC_cpu_dpath__io_inst.values[0];}
  val_t T431;
  T431 = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t SOC_cpu_cpath__inst;
  { SOC_cpu_cpath__inst = TERNARY_1(T431, SOC_cpu_cpath__io_bus_dat4.values[0], SOC_cpu_cpath__io_ctrl_inst.values[0]);}
  val_t SOC_cpu_cpath__inst_op;
  { SOC_cpu_cpath__inst_op = SOC_cpu_cpath__inst >> 26;}
  SOC_cpu_cpath__inst_op = SOC_cpu_cpath__inst_op & 0x3fL;
  val_t T432;
  T432 = SOC_cpu_cpath__inst_op == 0x3L;
  val_t T433;
  { T433 = TERNARY(T432, 0x18L, 0x0L);}
  val_t T434;
  T434 = SOC_cpu_cpath__inst_op == 0x2L;
  val_t T435;
  { T435 = TERNARY(T434, 0x17L, T433);}
  val_t T436;
  T436 = SOC_cpu_cpath__inst_op == 0xaL;
  val_t T437;
  { T437 = TERNARY(T436, 0x16L, T435);}
  val_t T438;
  T438 = SOC_cpu_cpath__inst_op == 0x5L;
  val_t T439;
  { T439 = TERNARY(T438, 0x15L, T437);}
  val_t T440;
  T440 = SOC_cpu_cpath__inst_op == 0x4L;
  val_t T441;
  { T441 = TERNARY(T440, 0x14L, T439);}
  val_t T442;
  T442 = SOC_cpu_cpath__inst_op == 0x2bL;
  val_t T443;
  { T443 = TERNARY(T442, 0x13L, T441);}
  val_t T444;
  T444 = SOC_cpu_cpath__inst_op == 0x23L;
  val_t T445;
  { T445 = TERNARY(T444, 0x12L, T443);}
  val_t T446;
  T446 = SOC_cpu_cpath__inst_op == 0xfL;
  val_t T447;
  { T447 = TERNARY(T446, 0x11L, T445);}
  val_t T448;
  T448 = SOC_cpu_cpath__inst_op == 0xeL;
  val_t T449;
  { T449 = TERNARY(T448, 0x10L, T447);}
  val_t T450;
  T450 = SOC_cpu_cpath__inst_op == 0xdL;
  val_t T451;
  { T451 = TERNARY(T450, 0xfL, T449);}
  val_t T452;
  T452 = SOC_cpu_cpath__inst_op == 0xcL;
  val_t T453;
  { T453 = TERNARY(T452, 0xeL, T451);}
  val_t T454;
  T454 = SOC_cpu_cpath__inst_op == 0x9L;
  val_t T455;
  { T455 = TERNARY(T454, 0xdL, T453);}
  val_t T456;
  T456 = SOC_cpu_cpath__inst_op == 0x8L;
  val_t T457;
  { T457 = TERNARY(T456, 0xcL, T455);}
  val_t SOC_cpu_cpath__inst_func;
  { SOC_cpu_cpath__inst_func = SOC_cpu_cpath__inst;}
  SOC_cpu_cpath__inst_func = SOC_cpu_cpath__inst_func & 0x3fL;
  val_t T458;
  T458 = SOC_cpu_cpath__inst_func == 0x8L;
  val_t T459;
  { T459 = TERNARY(T458, 0xbL, 0x0L);}
  val_t T460;
  T460 = SOC_cpu_cpath__inst_func == 0x6L;
  val_t T461;
  { T461 = TERNARY(T460, 0xaL, T459);}
  val_t T462;
  T462 = SOC_cpu_cpath__inst_func == 0x2aL;
  val_t T463;
  { T463 = TERNARY(T462, 0x9L, T461);}
  val_t T464;
  T464 = SOC_cpu_cpath__inst_func == 0x27L;
  val_t T465;
  { T465 = TERNARY(T464, 0x8L, T463);}
  val_t T466;
  T466 = SOC_cpu_cpath__inst_func == 0x26L;
  val_t T467;
  { T467 = TERNARY(T466, 0x7L, T465);}
  val_t T468;
  T468 = SOC_cpu_cpath__inst_func == 0x25L;
  val_t T469;
  { T469 = TERNARY(T468, 0x6L, T467);}
  val_t T470;
  T470 = SOC_cpu_cpath__inst_func == 0x24L;
  val_t T471;
  { T471 = TERNARY(T470, 0x5L, T469);}
  val_t T472;
  T472 = SOC_cpu_cpath__inst_func == 0x23L;
  val_t T473;
  { T473 = TERNARY(T472, 0x4L, T471);}
  val_t T474;
  T474 = SOC_cpu_cpath__inst_func == 0x22L;
  val_t T475;
  { T475 = TERNARY(T474, 0x3L, T473);}
  val_t T476;
  T476 = SOC_cpu_cpath__inst_func == 0x21L;
  val_t T477;
  { T477 = TERNARY(T476, 0x2L, T475);}
  val_t T478;
  T478 = SOC_cpu_cpath__inst_func == 0x20L;
  val_t T479;
  { T479 = TERNARY(T478, 0x1L, T477);}
  val_t T480;
  T480 = SOC_cpu_cpath__inst_op == 0x0L;
  val_t T481;
  { T481 = TERNARY_1(T480, T479, T457);}
  val_t T482;
  T482 = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t T483;
  { T483 = TERNARY(T482, T481, 0x0L);}
  { SOC_dev_ram_dev__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_ram_slave_ack.values[0] = SOC_dev_ram_dev__io_bus_ack.values[0];}
  val_t T484;
  T484 = SOC_dev_bus__ram_op == 0x1L;
  val_t T485;
  { T485 = TERNARY(T484, SOC_dev_bus__io_ram_slave_ack.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_2__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_7_ack.values[0] = SOC_dev_WB_Empty_Dev_2__io_bus_ack.values[0];}
  val_t T486;
  T486 = SOC_dev_bus__current_slave == 0x7L;
  val_t T487;
  { T487 = TERNARY(T486, SOC_dev_bus__io_slaves_7_ack.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_1__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_6_ack.values[0] = SOC_dev_WB_Empty_Dev_1__io_bus_ack.values[0];}
  val_t T488;
  T488 = SOC_dev_bus__current_slave == 0x6L;
  val_t T489;
  { T489 = TERNARY(T488, SOC_dev_bus__io_slaves_6_ack.values[0], T487);}
  { SOC_dev_WB_Empty_Dev__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_5_ack.values[0] = SOC_dev_WB_Empty_Dev__io_bus_ack.values[0];}
  val_t T490;
  T490 = SOC_dev_bus__current_slave == 0x5L;
  val_t T491;
  { T491 = TERNARY(T490, SOC_dev_bus__io_slaves_5_ack.values[0], T489);}
  { SOC_dev_seven_seg__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_4_ack.values[0] = SOC_dev_seven_seg__io_bus_ack.values[0];}
  val_t T492;
  T492 = SOC_dev_bus__current_slave == 0x4L;
  val_t T493;
  { T493 = TERNARY(T492, SOC_dev_bus__io_slaves_4_ack.values[0], T491);}
  { SOC_dev_counter__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_3_ack.values[0] = SOC_dev_counter__io_bus_ack.values[0];}
  val_t T494;
  T494 = SOC_dev_bus__current_slave == 0x3L;
  val_t T495;
  { T495 = TERNARY(T494, SOC_dev_bus__io_slaves_3_ack.values[0], T493);}
  { SOC_dev_led__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_2_ack.values[0] = SOC_dev_led__io_bus_ack.values[0];}
  val_t T496;
  T496 = SOC_dev_bus__current_slave == 0x2L;
  val_t T497;
  { T497 = TERNARY(T496, SOC_dev_bus__io_slaves_2_ack.values[0], T495);}
  { SOC_dev_btn__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_1_ack.values[0] = SOC_dev_btn__io_bus_ack.values[0];}
  val_t T498;
  T498 = SOC_dev_bus__current_slave == 0x1L;
  val_t T499;
  { T499 = TERNARY(T498, SOC_dev_bus__io_slaves_1_ack.values[0], T497);}
  { SOC_dev_sw__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_0_ack.values[0] = SOC_dev_sw__io_bus_ack.values[0];}
  val_t T500;
  T500 = SOC_dev_bus__current_slave == 0x0L;
  val_t T501;
  { T501 = TERNARY(T500, SOC_dev_bus__io_slaves_0_ack.values[0], T499);}
  val_t T502;
  T502 = SOC_dev_bus__ram_op == 0x0L;
  val_t T503;
  { T503 = TERNARY_1(T502, T501, T485);}
  { SOC_dev_bus__io_from_cpu_ack.values[0] = T503;}
  { SOC_dev__io_bus_ack.values[0] = SOC_dev_bus__io_from_cpu_ack.values[0];}
  { SOC_cpu__io_bus_ack.values[0] = SOC_dev__io_bus_ack.values[0];}
  { SOC_cpu_cpath__io_bus_ack.values[0] = SOC_cpu__io_bus_ack.values[0];}
  val_t T504;
  { T504 = TERNARY_1(SOC_cpu_cpath__io_bus_ack.values[0], T483, SOC_cpu_cpath__state.values[0]);}
  { SOC_cpu_cpath__reset.values[0] = SOC_cpu__reset.values[0];}
  { T505.values[0] = TERNARY(SOC_cpu_cpath__reset.values[0], 0x0L, T504);}
  { SOC_dev_led__io_LED.values[0] = SOC_dev_led__led_data.values[0];}
  { SOC_dev__io_devices_LED.values[0] = SOC_dev_led__io_LED.values[0];}
  { SOC__io_devices_LED.values[0] = SOC_dev__io_devices_LED.values[0];}
  { SOC_dev__io_devices_SEGMENT.values[0] = 0x0L;}
  { SOC__io_devices_SEGMENT.values[0] = SOC_dev__io_devices_SEGMENT.values[0];}
  { SOC_dev__io_devices_AN.values[0] = 0x0L;}
  { SOC__io_devices_AN.values[0] = SOC_dev__io_devices_AN.values[0];}
  { SOC_cpu_cpath__io_debug_inst_out.values[0] = SOC_cpu_cpath__inst;}
  { SOC_cpu__io_debug_inst_out.values[0] = SOC_cpu_cpath__io_debug_inst_out.values[0];}
  { SOC__io_debug_inst_out.values[0] = SOC_cpu__io_debug_inst_out.values[0];}
  { SOC_cpu_cpath__io_debug_bus_addr.values[0] = SOC_cpu_cpath__io_bus_addr.values[0];}
  { SOC_cpu__io_debug_bus_addr.values[0] = SOC_cpu_cpath__io_debug_bus_addr.values[0];}
  { SOC__io_debug_bus_addr.values[0] = SOC_cpu__io_debug_bus_addr.values[0];}
  { SOC_cpu_cpath__io_debug_bus_dat2.values[0] = SOC_cpu_cpath__io_bus_dat2.values[0];}
  { SOC_cpu__io_debug_bus_dat2.values[0] = SOC_cpu_cpath__io_debug_bus_dat2.values[0];}
  { SOC__io_debug_bus_dat2.values[0] = SOC_cpu__io_debug_bus_dat2.values[0];}
  { SOC_cpu_cpath__io_debug_bus_dat4.values[0] = SOC_cpu_cpath__io_bus_dat4.values[0];}
  { SOC_cpu__io_debug_bus_dat4.values[0] = SOC_cpu_cpath__io_debug_bus_dat4.values[0];}
  { SOC__io_debug_bus_dat4.values[0] = SOC_cpu__io_debug_bus_dat4.values[0];}
  { SOC_cpu_cpath__io_debug_pc_out.values[0] = SOC_cpu_cpath__io_ctrl_pc_out.values[0];}
  { SOC_cpu__io_debug_pc_out.values[0] = SOC_cpu_cpath__io_debug_pc_out.values[0];}
  { SOC__io_debug_pc_out.values[0] = SOC_cpu__io_debug_pc_out.values[0];}
  val_t T506;
  { T506 = SOC_dev_led__reset.values[0] ^ 0x1L;}
  { T507.values[0] = T194 & T506;}
  { T508.values[0] = SOC_dev_led__io_bus_dat2.values[0];}
  val_t T509;
  { T509 = SOC_dev_led__reset.values[0] ^ 0x1L;}
  { T510.values[0] = T194 & T509;}
  { T511.values[0] = SOC_dev_led__io_bus_we.values[0];}
  val_t T512;
  { T512 = SOC_dev_led__reset.values[0] ^ 0x1L;}
  { T513.values[0] = T194 & T512;}
  { T514.values[0] = SOC_dev_led__io_bus_sel.values[0];}
  val_t T515;
  { T515 = SOC_dev_bus__reset.values[0] ^ 0x1L;}
  { T516.values[0] = SOC_dev_bus__ack_out.values[0] & T515;}
  { T517.values[0] = SOC_dev_bus__io_slaves_2_we.values[0];}
  val_t T518;
  { T518 = SOC_dev_bus__reset.values[0] ^ 0x1L;}
  { T519.values[0] = SOC_dev_bus__ack_out.values[0] & T518;}
  { T520.values[0] = SOC_dev_bus__io_slaves_2_sel.values[0];}
  val_t T521;
  { T521 = SOC_dev_bus__reset.values[0] ^ 0x1L;}
  { T522.values[0] = SOC_dev_bus__ack_out.values[0] & T521;}
  { T523.values[0] = SOC_dev_bus__ram_op;}
  val_t T524;
  { T524 = SOC_dev_bus__reset.values[0] ^ 0x1L;}
  { T525.values[0] = SOC_dev_bus__ack_out.values[0] & T524;}
  { T526.values[0] = SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T527;
  { T527 = SOC_dev_bus__reset.values[0] ^ 0x1L;}
  { T528.values[0] = SOC_dev_bus__ack_out.values[0] & T527;}
  { T529.values[0] = SOC_dev_bus__current_slave;}
  val_t T530;
  { T530 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T531.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T530;}
  val_t T532;
  { T532 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T533.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T532;}
  { T534.values[0] = SOC_cpu_cpath__io_ctrl_alu_out.values[0];}
  val_t T535;
  { T535 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T536.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T535;}
  { T537.values[0] = SOC_cpu_cpath__io_bus_dat4.values[0];}
  val_t T538;
  { T538 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T539.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T538;}
  { T540.values[0] = SOC_cpu_cpath__io_bus_dat2.values[0];}
  val_t T541;
  { T541 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T542.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T541;}
  { T543.values[0] = SOC_cpu_cpath__io_bus_addr.values[0];}
  val_t T544;
  { T544 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T545.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T544;}
  { T546.values[0] = T483;}
  val_t T547;
  { T547 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T548.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T547;}
  { T549.values[0] = SOC_cpu_cpath__io_ctrl_inst.values[0];}
  val_t T550;
  { T550 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T551.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T550;}
  { T552.values[0] = SOC_cpu_cpath__inst;}
  val_t T553;
  { T553 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T554.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T553;}
  { T555.values[0] = SOC_cpu_cpath__bus_addr_src;}
  { T556.values[0] = SOC_cpu_cpath__bus_we;}
  { T557.values[0] = SOC_cpu_cpath__bus_sel;}
  { T558.values[0] = SOC_cpu_cpath__alu_b_sel;}
  { T559.values[0] = SOC_cpu_cpath__alu_op;}
  { T560.values[0] = SOC_cpu_cpath__reg_we_dst;}
  { T561.values[0] = SOC_cpu_cpath__reg_we_src;}
  { T562.values[0] = SOC_cpu_cpath__reg_we;}
  { T563.values[0] = SOC_cpu_cpath__pc_next_sel;}
  { T564.values[0] = SOC_cpu_cpath__pc_we;}
  { T565.values[0] = SOC_cpu_cpath__inst_we;}
  val_t T566;
  { T566 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T567.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T566;}
  { T568.values[0] = SOC_cpu_cpath__state.values[0];}
}


void SOC_t::clock_hi ( dat_t<1> reset ) {
  dat_t<32> SOC_dev_seven_seg__data_out__shadow = T183;
  dat_t<32> SOC_dev_seven_seg__disp_data__shadow = T185;
  dat_t<32> SOC_dev_led__data_out__shadow = T203;
  dat_t<8> SOC_dev_led__led_data__shadow = T207;
  dat_t<1> SOC_dev_bus__ack_out__shadow = T208;
  { if (T369.values[0]) SOC_cpu_dpath_regfile__rf.put(SOC_cpu_dpath_regfile__io_wtaddr.values[0], 0, SOC_cpu_dpath_regfile__io_wtdata.values[0]);}
  dat_t<32> SOC_cpu_dpath__inst_reg__shadow = T371;
  dat_t<32> SOC_cpu_dpath__pc__shadow = T430;
  dat_t<32> SOC_cpu_cpath__state__shadow = T505;
  SOC_dev_seven_seg__data_out = T183;
  SOC_dev_seven_seg__disp_data = T185;
  SOC_dev_led__data_out = T203;
  SOC_dev_led__led_data = T207;
  SOC_dev_bus__ack_out = T208;
  SOC_cpu_dpath__inst_reg = T371;
  SOC_cpu_dpath__pc = T430;
  SOC_cpu_cpath__state = T505;
}


void SOC_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  SOC_t* mod_typed = dynamic_cast<SOC_t*>(module);
  assert(mod_typed);
  dat_table["SOC.cpu.dpath.regfile.io_addrb"] = new dat_api<5>(&mod_typed->SOC_cpu_dpath_regfile__io_addrb, "SOC.cpu.dpath.regfile.io_addrb", "");
  dat_table["SOC.cpu.dpath.regfile.io_doutb"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_regfile__io_doutb, "SOC.cpu.dpath.regfile.io_doutb", "");
  dat_table["SOC.cpu.dpath.io_data_out"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_data_out, "SOC.cpu.dpath.io_data_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_data_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_data_out, "SOC.cpu.cpath.io_ctrl_data_out", "");
  dat_table["SOC.cpu.cpath.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_bus_dat2, "SOC.cpu.cpath.io_bus_dat2", "");
  dat_table["SOC.cpu.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu__io_bus_dat2, "SOC.cpu.io_bus_dat2", "");
  dat_table["SOC.dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev__io_bus_dat2, "SOC.dev.io_bus_dat2", "");
  dat_table["SOC.dev.bus.io_from_cpu_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_from_cpu_dat2, "SOC.dev.bus.io_from_cpu_dat2", "");
  dat_table["SOC.dev.bus.io_slaves_4_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_4_dat2, "SOC.dev.bus.io_slaves_4_dat2", "");
  dat_table["SOC.dev.seven_seg.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__io_bus_dat2, "SOC.dev.seven_seg.io_bus_dat2", "");
  dat_table["SOC.cpu.dpath.io_pc_out"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_pc_out, "SOC.cpu.dpath.io_pc_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_pc_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_pc_out, "SOC.cpu.cpath.io_ctrl_pc_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_alu_b_sel"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_ctrl_alu_b_sel, "SOC.cpu.cpath.io_ctrl_alu_b_sel", "");
  dat_table["SOC.cpu.dpath.io_alu_b_sel"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath__io_alu_b_sel, "SOC.cpu.dpath.io_alu_b_sel", "");
  dat_table["SOC.cpu.dpath.alu.io_in_b"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_alu__io_in_b, "SOC.cpu.dpath.alu.io_in_b", "");
  dat_table["SOC.cpu.dpath.regfile.io_addra"] = new dat_api<5>(&mod_typed->SOC_cpu_dpath_regfile__io_addra, "SOC.cpu.dpath.regfile.io_addra", "");
  dat_table["SOC.cpu.dpath.regfile.io_douta"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_regfile__io_douta, "SOC.cpu.dpath.regfile.io_douta", "");
  dat_table["SOC.cpu.dpath.alu.io_in_a"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_alu__io_in_a, "SOC.cpu.dpath.alu.io_in_a", "");
  dat_table["SOC.cpu.cpath.io_ctrl_alu_op"] = new dat_api<3>(&mod_typed->SOC_cpu_cpath__io_ctrl_alu_op, "SOC.cpu.cpath.io_ctrl_alu_op", "");
  dat_table["SOC.cpu.dpath.io_alu_op"] = new dat_api<3>(&mod_typed->SOC_cpu_dpath__io_alu_op, "SOC.cpu.dpath.io_alu_op", "");
  dat_table["SOC.cpu.dpath.alu.io_alu_op"] = new dat_api<3>(&mod_typed->SOC_cpu_dpath_alu__io_alu_op, "SOC.cpu.dpath.alu.io_alu_op", "");
  dat_table["SOC.cpu.dpath.alu.io_out"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_alu__io_out, "SOC.cpu.dpath.alu.io_out", "");
  dat_table["SOC.cpu.dpath.io_alu_out"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_alu_out, "SOC.cpu.dpath.io_alu_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_alu_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_alu_out, "SOC.cpu.cpath.io_ctrl_alu_out", "");
  dat_table["SOC.cpu.cpath.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_bus_addr, "SOC.cpu.cpath.io_bus_addr", "");
  dat_table["SOC.cpu.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_cpu__io_bus_addr, "SOC.cpu.io_bus_addr", "");
  dat_table["SOC.dev.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_dev__io_bus_addr, "SOC.dev.io_bus_addr", "");
  dat_table["SOC.dev.bus.io_from_cpu_addr"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_from_cpu_addr, "SOC.dev.bus.io_from_cpu_addr", "");
  dat_table["SOC.cpu.cpath.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_bus_we, "SOC.cpu.cpath.io_bus_we", "");
  dat_table["SOC.cpu.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_cpu__io_bus_we, "SOC.cpu.io_bus_we", "");
  dat_table["SOC.dev.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev__io_bus_we, "SOC.dev.io_bus_we", "");
  dat_table["SOC.dev.bus.io_from_cpu_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_from_cpu_we, "SOC.dev.bus.io_from_cpu_we", "");
  dat_table["SOC.dev.bus.io_slaves_4_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_4_we, "SOC.dev.bus.io_slaves_4_we", "");
  dat_table["SOC.dev.seven_seg.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_seven_seg__io_bus_we, "SOC.dev.seven_seg.io_bus_we", "");
  dat_table["SOC.cpu.cpath.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_bus_sel, "SOC.cpu.cpath.io_bus_sel", "");
  dat_table["SOC.cpu.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_cpu__io_bus_sel, "SOC.cpu.io_bus_sel", "");
  dat_table["SOC.dev.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev__io_bus_sel, "SOC.dev.io_bus_sel", "");
  dat_table["SOC.dev.bus.io_from_cpu_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_from_cpu_sel, "SOC.dev.bus.io_from_cpu_sel", "");
  dat_table["SOC.dev.bus.io_slaves_4_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_4_sel, "SOC.dev.bus.io_slaves_4_sel", "");
  dat_table["SOC.dev.seven_seg.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_seven_seg__io_bus_sel, "SOC.dev.seven_seg.io_bus_sel", "");
  dat_table["SOC.dev.seven_seg.data_out"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__data_out, "SOC.dev.seven_seg.data_out", "");
  dat_table["SOC.dev.seven_seg.disp_data"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__disp_data, "SOC.dev.seven_seg.disp_data", "");
  dat_table["SOC.dev.seven_seg.io_DISP_NUM"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__io_DISP_NUM, "SOC.dev.seven_seg.io_DISP_NUM", "");
  dat_table["SOC.dev.bus.io_slaves_2_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_2_dat2, "SOC.dev.bus.io_slaves_2_dat2", "");
  dat_table["SOC.dev.led.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_led__io_bus_dat2, "SOC.dev.led.io_bus_dat2", "");
  dat_table["SOC.dev.bus.io_slaves_2_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_2_we, "SOC.dev.bus.io_slaves_2_we", "");
  dat_table["SOC.dev.led.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_led__io_bus_we, "SOC.dev.led.io_bus_we", "");
  dat_table["SOC.dev.bus.io_slaves_2_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_2_sel, "SOC.dev.bus.io_slaves_2_sel", "");
  dat_table["SOC.dev.led.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_led__io_bus_sel, "SOC.dev.led.io_bus_sel", "");
  dat_table["SOC.dev.led.data_out"] = new dat_api<32>(&mod_typed->SOC_dev_led__data_out, "SOC.dev.led.data_out", "");
  dat_table["SOC.dev.led.led_data"] = new dat_api<8>(&mod_typed->SOC_dev_led__led_data, "SOC.dev.led.led_data", "");
  dat_table["SOC.dev.bus.ack_out"] = new dat_api<1>(&mod_typed->SOC_dev_bus__ack_out, "SOC.dev.bus.ack_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_reg_we_src"] = new dat_api<2>(&mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_src, "SOC.cpu.cpath.io_ctrl_reg_we_src", "");
  dat_table["SOC.cpu.dpath.io_reg_we_src"] = new dat_api<2>(&mod_typed->SOC_cpu_dpath__io_reg_we_src, "SOC.cpu.dpath.io_reg_we_src", "");
  dat_table["SOC.dev.bus.io_ram_slave_addr"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_ram_slave_addr, "SOC.dev.bus.io_ram_slave_addr", "");
  dat_table["SOC.dev.ram_dev.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_bus_addr, "SOC.dev.ram_dev.io_bus_addr", "");
  dat_table["SOC.dev.ram_dev.io_ram_addra"] = new dat_api<10>(&mod_typed->SOC_dev_ram_dev__io_ram_addra, "SOC.dev.ram_dev.io_ram_addra", "");
  dat_table["SOC.dev.ram.io_addra"] = new dat_api<10>(&mod_typed->SOC_dev_ram__io_addra, "SOC.dev.ram.io_addra", "");
  dat_table["SOC.dev.ram.io_douta"] = new dat_api<32>(&mod_typed->SOC_dev_ram__io_douta, "SOC.dev.ram.io_douta", "");
  dat_table["SOC.dev.ram_dev.io_ram_douta"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_ram_douta, "SOC.dev.ram_dev.io_ram_douta", "");
  dat_table["SOC.dev.ram_dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_bus_dat4, "SOC.dev.ram_dev.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_ram_slave_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_ram_slave_dat4, "SOC.dev.bus.io_ram_slave_dat4", "");
  dat_table["SOC.dev.WB_Empty_Dev_2.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_WB_Empty_Dev_2__io_bus_dat4, "SOC.dev.WB_Empty_Dev_2.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_7_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_7_dat4, "SOC.dev.bus.io_slaves_7_dat4", "");
  dat_table["SOC.dev.WB_Empty_Dev_1.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_dat4, "SOC.dev.WB_Empty_Dev_1.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_6_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_6_dat4, "SOC.dev.bus.io_slaves_6_dat4", "");
  dat_table["SOC.dev.WB_Empty_Dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_WB_Empty_Dev__io_bus_dat4, "SOC.dev.WB_Empty_Dev.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_5_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_5_dat4, "SOC.dev.bus.io_slaves_5_dat4", "");
  dat_table["SOC.dev.seven_seg.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__io_bus_dat4, "SOC.dev.seven_seg.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_4_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_4_dat4, "SOC.dev.bus.io_slaves_4_dat4", "");
  dat_table["SOC.dev.counter.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_counter__io_bus_dat4, "SOC.dev.counter.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_3_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_3_dat4, "SOC.dev.bus.io_slaves_3_dat4", "");
  dat_table["SOC.dev.led.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_led__io_bus_dat4, "SOC.dev.led.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_2_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_2_dat4, "SOC.dev.bus.io_slaves_2_dat4", "");
  dat_table["SOC.io_devices_BTN"] = new dat_api<5>(&mod_typed->SOC__io_devices_BTN, "SOC.io_devices_BTN", "");
  dat_table["SOC.dev.io_devices_BTN"] = new dat_api<5>(&mod_typed->SOC_dev__io_devices_BTN, "SOC.dev.io_devices_BTN", "");
  dat_table["SOC.dev.btn.io_BTN"] = new dat_api<5>(&mod_typed->SOC_dev_btn__io_BTN, "SOC.dev.btn.io_BTN", "");
  dat_table["SOC.dev.btn.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_btn__io_bus_dat4, "SOC.dev.btn.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_1_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_1_dat4, "SOC.dev.bus.io_slaves_1_dat4", "");
  dat_table["SOC.io_devices_SW"] = new dat_api<8>(&mod_typed->SOC__io_devices_SW, "SOC.io_devices_SW", "");
  dat_table["SOC.dev.io_devices_SW"] = new dat_api<8>(&mod_typed->SOC_dev__io_devices_SW, "SOC.dev.io_devices_SW", "");
  dat_table["SOC.dev.sw.io_SW"] = new dat_api<8>(&mod_typed->SOC_dev_sw__io_SW, "SOC.dev.sw.io_SW", "");
  dat_table["SOC.dev.sw.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_sw__io_bus_dat4, "SOC.dev.sw.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_0_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_0_dat4, "SOC.dev.bus.io_slaves_0_dat4", "");
  dat_table["SOC.dev.bus.io_from_cpu_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_from_cpu_dat4, "SOC.dev.bus.io_from_cpu_dat4", "");
  dat_table["SOC.dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev__io_bus_dat4, "SOC.dev.io_bus_dat4", "");
  dat_table["SOC.cpu.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_cpu__io_bus_dat4, "SOC.cpu.io_bus_dat4", "");
  dat_table["SOC.cpu.cpath.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_bus_dat4, "SOC.cpu.cpath.io_bus_dat4", "");
  dat_table["SOC.cpu.cpath.io_ctrl_bus_data"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_bus_data, "SOC.cpu.cpath.io_ctrl_bus_data", "");
  dat_table["SOC.cpu.dpath.io_bus_data"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_bus_data, "SOC.cpu.dpath.io_bus_data", "");
  dat_table["SOC.cpu.dpath.regfile.io_wtdata"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_regfile__io_wtdata, "SOC.cpu.dpath.regfile.io_wtdata", "");
  dat_table["SOC.cpu.cpath.io_ctrl_reg_we_dst"] = new dat_api<2>(&mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_dst, "SOC.cpu.cpath.io_ctrl_reg_we_dst", "");
  dat_table["SOC.cpu.dpath.io_reg_we_dst"] = new dat_api<2>(&mod_typed->SOC_cpu_dpath__io_reg_we_dst, "SOC.cpu.dpath.io_reg_we_dst", "");
  dat_table["SOC.cpu.dpath.regfile.io_wtaddr"] = new dat_api<5>(&mod_typed->SOC_cpu_dpath_regfile__io_wtaddr, "SOC.cpu.dpath.regfile.io_wtaddr", "");
  dat_table["SOC.cpu.cpath.io_ctrl_reg_we"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_ctrl_reg_we, "SOC.cpu.cpath.io_ctrl_reg_we", "");
  dat_table["SOC.cpu.dpath.io_reg_we"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath__io_reg_we, "SOC.cpu.dpath.io_reg_we", "");
  dat_table["SOC.cpu.dpath.regfile.io_we"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath_regfile__io_we, "SOC.cpu.dpath.regfile.io_we", "");
  mem_table["SOC.cpu.dpath.regfile.rf"] = new mem_api<32, 32>(&mod_typed->SOC_cpu_dpath_regfile__rf, "SOC.cpu.dpath.regfile.rf", "");
  dat_table["SOC.cpu.cpath.io_ctrl_inst_we"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_ctrl_inst_we, "SOC.cpu.cpath.io_ctrl_inst_we", "");
  dat_table["SOC.cpu.dpath.io_inst_we"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath__io_inst_we, "SOC.cpu.dpath.io_inst_we", "");
  dat_table["SOC.cpu.dpath.inst_reg"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__inst_reg, "SOC.cpu.dpath.inst_reg", "");
  dat_table["SOC.cpu.cpath.io_ctrl_pc_next_sel"] = new dat_api<2>(&mod_typed->SOC_cpu_cpath__io_ctrl_pc_next_sel, "SOC.cpu.cpath.io_ctrl_pc_next_sel", "");
  dat_table["SOC.cpu.dpath.io_pc_next_sel"] = new dat_api<2>(&mod_typed->SOC_cpu_dpath__io_pc_next_sel, "SOC.cpu.dpath.io_pc_next_sel", "");
  dat_table["SOC.cpu.dpath.alu.io_zero"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath_alu__io_zero, "SOC.cpu.dpath.alu.io_zero", "");
  dat_table["SOC.cpu.cpath.io_ctrl_pc_we"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_ctrl_pc_we, "SOC.cpu.cpath.io_ctrl_pc_we", "");
  dat_table["SOC.cpu.dpath.io_pc_we"] = new dat_api<1>(&mod_typed->SOC_cpu_dpath__io_pc_we, "SOC.cpu.dpath.io_pc_we", "");
  dat_table["SOC.cpu.dpath.pc"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__pc, "SOC.cpu.dpath.pc", "");
  dat_table["SOC.cpu.dpath.io_inst"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_inst, "SOC.cpu.dpath.io_inst", "");
  dat_table["SOC.cpu.cpath.io_ctrl_inst"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_inst, "SOC.cpu.cpath.io_ctrl_inst", "");
  dat_table["SOC.dev.ram_dev.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_ram_dev__io_bus_ack, "SOC.dev.ram_dev.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_ram_slave_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_ram_slave_ack, "SOC.dev.bus.io_ram_slave_ack", "");
  dat_table["SOC.dev.WB_Empty_Dev_2.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_WB_Empty_Dev_2__io_bus_ack, "SOC.dev.WB_Empty_Dev_2.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_7_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_7_ack, "SOC.dev.bus.io_slaves_7_ack", "");
  dat_table["SOC.dev.WB_Empty_Dev_1.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_ack, "SOC.dev.WB_Empty_Dev_1.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_6_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_6_ack, "SOC.dev.bus.io_slaves_6_ack", "");
  dat_table["SOC.dev.WB_Empty_Dev.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_WB_Empty_Dev__io_bus_ack, "SOC.dev.WB_Empty_Dev.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_5_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_5_ack, "SOC.dev.bus.io_slaves_5_ack", "");
  dat_table["SOC.dev.seven_seg.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_seven_seg__io_bus_ack, "SOC.dev.seven_seg.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_4_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_4_ack, "SOC.dev.bus.io_slaves_4_ack", "");
  dat_table["SOC.dev.counter.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_counter__io_bus_ack, "SOC.dev.counter.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_3_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_3_ack, "SOC.dev.bus.io_slaves_3_ack", "");
  dat_table["SOC.dev.led.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_led__io_bus_ack, "SOC.dev.led.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_2_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_2_ack, "SOC.dev.bus.io_slaves_2_ack", "");
  dat_table["SOC.dev.btn.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_btn__io_bus_ack, "SOC.dev.btn.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_1_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_1_ack, "SOC.dev.bus.io_slaves_1_ack", "");
  dat_table["SOC.dev.sw.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_sw__io_bus_ack, "SOC.dev.sw.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_0_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_0_ack, "SOC.dev.bus.io_slaves_0_ack", "");
  dat_table["SOC.dev.bus.io_from_cpu_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_from_cpu_ack, "SOC.dev.bus.io_from_cpu_ack", "");
  dat_table["SOC.dev.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev__io_bus_ack, "SOC.dev.io_bus_ack", "");
  dat_table["SOC.cpu.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_cpu__io_bus_ack, "SOC.cpu.io_bus_ack", "");
  dat_table["SOC.cpu.cpath.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_bus_ack, "SOC.cpu.cpath.io_bus_ack", "");
  dat_table["SOC.cpu.cpath.state"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__state, "SOC.cpu.cpath.state", "");
  dat_table["SOC.dev.led.io_LED"] = new dat_api<8>(&mod_typed->SOC_dev_led__io_LED, "SOC.dev.led.io_LED", "");
  dat_table["SOC.dev.io_devices_LED"] = new dat_api<8>(&mod_typed->SOC_dev__io_devices_LED, "SOC.dev.io_devices_LED", "");
  dat_table["SOC.io_devices_LED"] = new dat_api<8>(&mod_typed->SOC__io_devices_LED, "SOC.io_devices_LED", "");
  dat_table["SOC.dev.io_devices_SEGMENT"] = new dat_api<8>(&mod_typed->SOC_dev__io_devices_SEGMENT, "SOC.dev.io_devices_SEGMENT", "");
  dat_table["SOC.io_devices_SEGMENT"] = new dat_api<8>(&mod_typed->SOC__io_devices_SEGMENT, "SOC.io_devices_SEGMENT", "");
  dat_table["SOC.dev.io_devices_AN"] = new dat_api<4>(&mod_typed->SOC_dev__io_devices_AN, "SOC.dev.io_devices_AN", "");
  dat_table["SOC.io_devices_AN"] = new dat_api<4>(&mod_typed->SOC__io_devices_AN, "SOC.io_devices_AN", "");
  dat_table["SOC.cpu.cpath.io_debug_inst_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_debug_inst_out, "SOC.cpu.cpath.io_debug_inst_out", "");
  dat_table["SOC.cpu.io_debug_inst_out"] = new dat_api<32>(&mod_typed->SOC_cpu__io_debug_inst_out, "SOC.cpu.io_debug_inst_out", "");
  dat_table["SOC.io_debug_inst_out"] = new dat_api<32>(&mod_typed->SOC__io_debug_inst_out, "SOC.io_debug_inst_out", "");
  dat_table["SOC.cpu.cpath.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_debug_bus_addr, "SOC.cpu.cpath.io_debug_bus_addr", "");
  dat_table["SOC.cpu.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->SOC_cpu__io_debug_bus_addr, "SOC.cpu.io_debug_bus_addr", "");
  dat_table["SOC.io_debug_bus_addr"] = new dat_api<32>(&mod_typed->SOC__io_debug_bus_addr, "SOC.io_debug_bus_addr", "");
  dat_table["SOC.cpu.cpath.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_debug_bus_dat2, "SOC.cpu.cpath.io_debug_bus_dat2", "");
  dat_table["SOC.cpu.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu__io_debug_bus_dat2, "SOC.cpu.io_debug_bus_dat2", "");
  dat_table["SOC.io_debug_bus_dat2"] = new dat_api<32>(&mod_typed->SOC__io_debug_bus_dat2, "SOC.io_debug_bus_dat2", "");
  dat_table["SOC.cpu.cpath.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_debug_bus_dat4, "SOC.cpu.cpath.io_debug_bus_dat4", "");
  dat_table["SOC.cpu.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_cpu__io_debug_bus_dat4, "SOC.cpu.io_debug_bus_dat4", "");
  dat_table["SOC.io_debug_bus_dat4"] = new dat_api<32>(&mod_typed->SOC__io_debug_bus_dat4, "SOC.io_debug_bus_dat4", "");
  dat_table["SOC.cpu.cpath.io_debug_pc_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_debug_pc_out, "SOC.cpu.cpath.io_debug_pc_out", "");
  dat_table["SOC.cpu.io_debug_pc_out"] = new dat_api<32>(&mod_typed->SOC_cpu__io_debug_pc_out, "SOC.cpu.io_debug_pc_out", "");
  dat_table["SOC.io_debug_pc_out"] = new dat_api<32>(&mod_typed->SOC__io_debug_pc_out, "SOC.io_debug_pc_out", "");
}
