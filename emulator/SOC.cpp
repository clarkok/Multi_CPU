#include "SOC.h"

void SOC_t::init ( val_t rand_init ) {
  this->__srand(rand_init);
  SOC_dev_vga_dev_vga__p_counter.randomize(&__rand_seed);
  SOC_dev_vga_dev_vga__h_counter.randomize(&__rand_seed);
  SOC_dev_vga_dev_vga__v_counter.randomize(&__rand_seed);
  SOC_dev_vga_dev__vmem.randomize(&__rand_seed);
  SOC_dev_seven_seg__data_out.randomize(&__rand_seed);
  SOC_dev_seven_seg__disp_data.randomize(&__rand_seed);
  SOC_dev_led__data_out.randomize(&__rand_seed);
  SOC_dev_led__led_data.randomize(&__rand_seed);
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
  SOC_dev__reset = mod_typed->SOC_dev__reset;
  SOC_dev_vga_dev__reset = mod_typed->SOC_dev_vga_dev__reset;
  SOC_dev_vga_dev_vga__reset = mod_typed->SOC_dev_vga_dev_vga__reset;
  T4 = mod_typed->T4;
  SOC_dev_vga_dev_vga__p_counter = mod_typed->SOC_dev_vga_dev_vga__p_counter;
  T13 = mod_typed->T13;
  SOC_dev_vga_dev_vga__h_counter = mod_typed->SOC_dev_vga_dev_vga__h_counter;
  T21 = mod_typed->T21;
  SOC_dev_vga_dev_vga__v_counter = mod_typed->SOC_dev_vga_dev_vga__v_counter;
  SOC_cpu_dpath_regfile__io_addrb = mod_typed->SOC_cpu_dpath_regfile__io_addrb;
  SOC_cpu_dpath_regfile__io_doutb = mod_typed->SOC_cpu_dpath_regfile__io_doutb;
  SOC_cpu_dpath__io_data_out = mod_typed->SOC_cpu_dpath__io_data_out;
  SOC_cpu_cpath__io_ctrl_data_out = mod_typed->SOC_cpu_cpath__io_ctrl_data_out;
  SOC_cpu_cpath__io_bus_dat2 = mod_typed->SOC_cpu_cpath__io_bus_dat2;
  SOC_cpu__io_bus_dat2 = mod_typed->SOC_cpu__io_bus_dat2;
  SOC_dev__io_bus_dat2 = mod_typed->SOC_dev__io_bus_dat2;
  SOC_dev_bus__io_from_cpu_dat2 = mod_typed->SOC_dev_bus__io_from_cpu_dat2;
  SOC_dev_bus__io_slaves_5_dat2 = mod_typed->SOC_dev_bus__io_slaves_5_dat2;
  SOC_dev_vga_dev__io_bus_dat2 = mod_typed->SOC_dev_vga_dev__io_bus_dat2;
  T24 = mod_typed->T24;
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
  SOC_dev_bus__io_slaves_5_addr = mod_typed->SOC_dev_bus__io_slaves_5_addr;
  SOC_dev_vga_dev__io_bus_addr = mod_typed->SOC_dev_vga_dev__io_bus_addr;
  SOC_cpu_cpath__io_bus_we = mod_typed->SOC_cpu_cpath__io_bus_we;
  SOC_cpu__io_bus_we = mod_typed->SOC_cpu__io_bus_we;
  SOC_dev__io_bus_we = mod_typed->SOC_dev__io_bus_we;
  SOC_dev_bus__io_from_cpu_we = mod_typed->SOC_dev_bus__io_from_cpu_we;
  SOC_dev_bus__io_slaves_5_we = mod_typed->SOC_dev_bus__io_slaves_5_we;
  SOC_dev_vga_dev__io_bus_we = mod_typed->SOC_dev_vga_dev__io_bus_we;
  SOC_cpu_cpath__io_bus_sel = mod_typed->SOC_cpu_cpath__io_bus_sel;
  SOC_cpu__io_bus_sel = mod_typed->SOC_cpu__io_bus_sel;
  SOC_dev__io_bus_sel = mod_typed->SOC_dev__io_bus_sel;
  SOC_dev_bus__io_from_cpu_sel = mod_typed->SOC_dev_bus__io_from_cpu_sel;
  SOC_dev_bus__io_slaves_5_sel = mod_typed->SOC_dev_bus__io_slaves_5_sel;
  SOC_dev_vga_dev__io_bus_sel = mod_typed->SOC_dev_vga_dev__io_bus_sel;
  T203 = mod_typed->T203;
  T204 = mod_typed->T204;
  SOC_dev_vga_dev__vmem = mod_typed->SOC_dev_vga_dev__vmem;
  SOC_dev_bus__io_slaves_4_dat2 = mod_typed->SOC_dev_bus__io_slaves_4_dat2;
  SOC_dev_seven_seg__io_bus_dat2 = mod_typed->SOC_dev_seven_seg__io_bus_dat2;
  SOC_dev_bus__io_slaves_4_we = mod_typed->SOC_dev_bus__io_slaves_4_we;
  SOC_dev_seven_seg__io_bus_we = mod_typed->SOC_dev_seven_seg__io_bus_we;
  SOC_dev_bus__io_slaves_4_sel = mod_typed->SOC_dev_bus__io_slaves_4_sel;
  SOC_dev_seven_seg__io_bus_sel = mod_typed->SOC_dev_seven_seg__io_bus_sel;
  SOC_dev_seven_seg__reset = mod_typed->SOC_dev_seven_seg__reset;
  T221 = mod_typed->T221;
  SOC_dev_seven_seg__data_out = mod_typed->SOC_dev_seven_seg__data_out;
  T223 = mod_typed->T223;
  SOC_dev_seven_seg__disp_data = mod_typed->SOC_dev_seven_seg__disp_data;
  SOC_dev_bus__io_slaves_2_dat2 = mod_typed->SOC_dev_bus__io_slaves_2_dat2;
  SOC_dev_led__io_bus_dat2 = mod_typed->SOC_dev_led__io_bus_dat2;
  SOC_dev_bus__io_slaves_2_we = mod_typed->SOC_dev_bus__io_slaves_2_we;
  SOC_dev_led__io_bus_we = mod_typed->SOC_dev_led__io_bus_we;
  SOC_dev_bus__io_slaves_2_sel = mod_typed->SOC_dev_bus__io_slaves_2_sel;
  SOC_dev_led__io_bus_sel = mod_typed->SOC_dev_led__io_bus_sel;
  SOC_dev_led__reset = mod_typed->SOC_dev_led__reset;
  T241 = mod_typed->T241;
  SOC_dev_led__data_out = mod_typed->SOC_dev_led__data_out;
  T245 = mod_typed->T245;
  SOC_dev_led__led_data = mod_typed->SOC_dev_led__led_data;
  SOC_cpu__reset = mod_typed->SOC_cpu__reset;
  SOC_cpu_dpath__reset = mod_typed->SOC_cpu_dpath__reset;
  SOC_cpu_dpath_regfile__reset = mod_typed->SOC_cpu_dpath_regfile__reset;
  SOC_cpu_cpath__io_ctrl_reg_we_src = mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_src;
  SOC_cpu_dpath__io_reg_we_src = mod_typed->SOC_cpu_dpath__io_reg_we_src;
  SOC__io_devices_RAM_douta = mod_typed->SOC__io_devices_RAM_douta;
  SOC_dev__io_devices_RAM_douta = mod_typed->SOC_dev__io_devices_RAM_douta;
  SOC_dev_ram_dev__io_ram_douta = mod_typed->SOC_dev_ram_dev__io_ram_douta;
  SOC_dev_bus__io_ram_slave_addr = mod_typed->SOC_dev_bus__io_ram_slave_addr;
  SOC_dev_ram_dev__io_bus_addr = mod_typed->SOC_dev_ram_dev__io_bus_addr;
  SOC_dev_ram_dev__io_bus_dat4 = mod_typed->SOC_dev_ram_dev__io_bus_dat4;
  SOC_dev_bus__io_ram_slave_dat4 = mod_typed->SOC_dev_bus__io_ram_slave_dat4;
  SOC_dev_WB_Empty_Dev_1__io_bus_dat4 = mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_dat4;
  SOC_dev_bus__io_slaves_7_dat4 = mod_typed->SOC_dev_bus__io_slaves_7_dat4;
  SOC_dev_WB_Empty_Dev__io_bus_dat4 = mod_typed->SOC_dev_WB_Empty_Dev__io_bus_dat4;
  SOC_dev_bus__io_slaves_6_dat4 = mod_typed->SOC_dev_bus__io_slaves_6_dat4;
  SOC_dev_vga_dev__io_bus_dat4 = mod_typed->SOC_dev_vga_dev__io_bus_dat4;
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
  T384 = mod_typed->T384;
  SOC_cpu_dpath_regfile__rf = mod_typed->SOC_cpu_dpath_regfile__rf;
  SOC_cpu_cpath__io_ctrl_inst_we = mod_typed->SOC_cpu_cpath__io_ctrl_inst_we;
  SOC_cpu_dpath__io_inst_we = mod_typed->SOC_cpu_dpath__io_inst_we;
  T386 = mod_typed->T386;
  SOC_cpu_dpath__inst_reg = mod_typed->SOC_cpu_dpath__inst_reg;
  SOC_cpu_cpath__io_ctrl_pc_next_sel = mod_typed->SOC_cpu_cpath__io_ctrl_pc_next_sel;
  SOC_cpu_dpath__io_pc_next_sel = mod_typed->SOC_cpu_dpath__io_pc_next_sel;
  SOC_cpu_dpath_alu__io_zero = mod_typed->SOC_cpu_dpath_alu__io_zero;
  SOC_cpu_cpath__io_ctrl_pc_we = mod_typed->SOC_cpu_cpath__io_ctrl_pc_we;
  SOC_cpu_dpath__io_pc_we = mod_typed->SOC_cpu_dpath__io_pc_we;
  T445 = mod_typed->T445;
  SOC_cpu_dpath__pc = mod_typed->SOC_cpu_dpath__pc;
  SOC_cpu_dpath__io_inst = mod_typed->SOC_cpu_dpath__io_inst;
  SOC_cpu_cpath__io_ctrl_inst = mod_typed->SOC_cpu_cpath__io_ctrl_inst;
  SOC_dev_ram_dev__io_bus_ack = mod_typed->SOC_dev_ram_dev__io_bus_ack;
  SOC_dev_bus__io_ram_slave_ack = mod_typed->SOC_dev_bus__io_ram_slave_ack;
  SOC_dev_WB_Empty_Dev_1__io_bus_ack = mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_ack;
  SOC_dev_bus__io_slaves_7_ack = mod_typed->SOC_dev_bus__io_slaves_7_ack;
  SOC_dev_WB_Empty_Dev__io_bus_ack = mod_typed->SOC_dev_WB_Empty_Dev__io_bus_ack;
  SOC_dev_bus__io_slaves_6_ack = mod_typed->SOC_dev_bus__io_slaves_6_ack;
  SOC_dev_vga_dev__io_bus_ack = mod_typed->SOC_dev_vga_dev__io_bus_ack;
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
  T520 = mod_typed->T520;
  SOC_cpu_cpath__state = mod_typed->SOC_cpu_cpath__state;
  SOC_dev_led__io_LED = mod_typed->SOC_dev_led__io_LED;
  SOC_dev__io_devices_LED = mod_typed->SOC_dev__io_devices_LED;
  SOC__io_devices_LED = mod_typed->SOC__io_devices_LED;
  SOC_dev_seven_seg__io_DISP_NUM = mod_typed->SOC_dev_seven_seg__io_DISP_NUM;
  SOC_dev__io_devices_DISP_NUM = mod_typed->SOC_dev__io_devices_DISP_NUM;
  SOC__io_devices_DISP_NUM = mod_typed->SOC__io_devices_DISP_NUM;
  SOC_dev_vga_dev_vga__io_ctrl_x = mod_typed->SOC_dev_vga_dev_vga__io_ctrl_x;
  SOC_dev_vga_dev_vga__io_ctrl_y = mod_typed->SOC_dev_vga_dev_vga__io_ctrl_y;
  SOC_dev_vga_dev_font__io_addr = mod_typed->SOC_dev_vga_dev_font__io_addr;
  SOC_dev_vga_dev_font__io_data = mod_typed->SOC_dev_vga_dev_font__io_data;
  SOC_dev_vga_dev_vga__io_ctrl_color = mod_typed->SOC_dev_vga_dev_vga__io_ctrl_color;
  SOC_dev_vga_dev_vga__io_vga_red = mod_typed->SOC_dev_vga_dev_vga__io_vga_red;
  SOC_dev_vga_dev__io_vga_red = mod_typed->SOC_dev_vga_dev__io_vga_red;
  SOC_dev__io_devices_VGA_red = mod_typed->SOC_dev__io_devices_VGA_red;
  SOC__io_devices_VGA_red = mod_typed->SOC__io_devices_VGA_red;
  SOC_dev_vga_dev_vga__io_vga_green = mod_typed->SOC_dev_vga_dev_vga__io_vga_green;
  SOC_dev_vga_dev__io_vga_green = mod_typed->SOC_dev_vga_dev__io_vga_green;
  SOC_dev__io_devices_VGA_green = mod_typed->SOC_dev__io_devices_VGA_green;
  SOC__io_devices_VGA_green = mod_typed->SOC__io_devices_VGA_green;
  SOC_dev_vga_dev_vga__io_vga_blue = mod_typed->SOC_dev_vga_dev_vga__io_vga_blue;
  SOC_dev_vga_dev__io_vga_blue = mod_typed->SOC_dev_vga_dev__io_vga_blue;
  SOC_dev__io_devices_VGA_blue = mod_typed->SOC_dev__io_devices_VGA_blue;
  SOC__io_devices_VGA_blue = mod_typed->SOC__io_devices_VGA_blue;
  SOC_dev_vga_dev_vga__io_vga_hsync = mod_typed->SOC_dev_vga_dev_vga__io_vga_hsync;
  SOC_dev_vga_dev__io_vga_hsync = mod_typed->SOC_dev_vga_dev__io_vga_hsync;
  SOC_dev__io_devices_VGA_hsync = mod_typed->SOC_dev__io_devices_VGA_hsync;
  SOC__io_devices_VGA_hsync = mod_typed->SOC__io_devices_VGA_hsync;
  SOC_dev_vga_dev_vga__io_vga_vsync = mod_typed->SOC_dev_vga_dev_vga__io_vga_vsync;
  SOC_dev_vga_dev__io_vga_vsync = mod_typed->SOC_dev_vga_dev__io_vga_vsync;
  SOC_dev__io_devices_VGA_vsync = mod_typed->SOC_dev__io_devices_VGA_vsync;
  SOC__io_devices_VGA_vsync = mod_typed->SOC__io_devices_VGA_vsync;
  SOC_dev_ram_dev__io_ram_addra = mod_typed->SOC_dev_ram_dev__io_ram_addra;
  SOC_dev__io_devices_RAM_addra = mod_typed->SOC_dev__io_devices_RAM_addra;
  SOC__io_devices_RAM_addra = mod_typed->SOC__io_devices_RAM_addra;
  SOC_dev_bus__io_ram_slave_dat2 = mod_typed->SOC_dev_bus__io_ram_slave_dat2;
  SOC_dev_ram_dev__io_bus_dat2 = mod_typed->SOC_dev_ram_dev__io_bus_dat2;
  SOC_dev_ram_dev__io_ram_dina = mod_typed->SOC_dev_ram_dev__io_ram_dina;
  SOC_dev__io_devices_RAM_dina = mod_typed->SOC_dev__io_devices_RAM_dina;
  SOC__io_devices_RAM_dina = mod_typed->SOC__io_devices_RAM_dina;
  SOC_dev_bus__io_ram_slave_we = mod_typed->SOC_dev_bus__io_ram_slave_we;
  SOC_dev_ram_dev__io_bus_we = mod_typed->SOC_dev_ram_dev__io_bus_we;
  SOC_dev_bus__io_ram_slave_sel = mod_typed->SOC_dev_bus__io_ram_slave_sel;
  SOC_dev_ram_dev__io_bus_sel = mod_typed->SOC_dev_ram_dev__io_bus_sel;
  SOC_dev_ram_dev__io_ram_we = mod_typed->SOC_dev_ram_dev__io_ram_we;
  SOC_dev__io_devices_RAM_we = mod_typed->SOC_dev__io_devices_RAM_we;
  SOC__io_devices_RAM_we = mod_typed->SOC__io_devices_RAM_we;
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
  T668 = mod_typed->T668;
  T669 = mod_typed->T669;
  T670 = mod_typed->T670;
  clk = mod_typed->clk;
  clk_cnt = mod_typed->clk_cnt;
  return true;
}


void SOC_t::print ( FILE* f ) {
#if __cplusplus >= 201103L
  if (T668.values[0]) dat_fprintf<168>(f, " - state: %d\n", T669);
#endif
fflush(f);
}
void SOC_t::print ( std::ostream& s ) {
#if __cplusplus >= 201103L
  if (T668.values[0]) dat_prints<168>(s, " - state: %d\n", T669);
#endif
s.flush();
}


void SOC_t::dump_init ( FILE* f ) {
}


void SOC_t::dump ( FILE* f, int t ) {
}




void SOC_t::clock_lo ( dat_t<1> reset ) {
  val_t T0;
  { T0 = SOC_dev_vga_dev_vga__p_counter.values[0]+0x1L;}
  T0 = T0 & 0x3L;
  val_t T1;
  T1 = SOC_dev_vga_dev_vga__p_counter.values[0] == 0x3L;
  val_t T2;
  { T2 = T1 ^ 0x1L;}
  val_t T3;
  { T3 = TERNARY(T2, T0, 0x0L);}
  { SOC_dev__reset.values[0] = reset.values[0];}
  { SOC_dev_vga_dev__reset.values[0] = SOC_dev__reset.values[0];}
  { SOC_dev_vga_dev_vga__reset.values[0] = SOC_dev_vga_dev__reset.values[0];}
  { T4.values[0] = TERNARY(SOC_dev_vga_dev_vga__reset.values[0], 0x0L, T3);}
  val_t T5;
  T5 = SOC_dev_vga_dev_vga__h_counter.values[0] == 0x31fL;
  val_t T6;
  T6 = SOC_dev_vga_dev_vga__p_counter.values[0] == 0x0L;
  val_t T7;
  { T7 = T6 & T5;}
  val_t T8;
  { T8 = TERNARY(T7, 0x0L, SOC_dev_vga_dev_vga__h_counter.values[0]);}
  val_t T9;
  { T9 = SOC_dev_vga_dev_vga__h_counter.values[0]+0x1L;}
  T9 = T9 & 0xffffffffL;
  val_t T10;
  { T10 = T5 ^ 0x1L;}
  val_t T11;
  { T11 = T6 & T10;}
  val_t T12;
  { T12 = TERNARY_1(T11, T9, T8);}
  { T13.values[0] = TERNARY(SOC_dev_vga_dev_vga__reset.values[0], 0x0L, T12);}
  val_t T14;
  T14 = SOC_dev_vga_dev_vga__v_counter.values[0] == 0x208L;
  val_t T15;
  { T15 = T7 & T14;}
  val_t T16;
  { T16 = TERNARY(T15, 0x0L, SOC_dev_vga_dev_vga__v_counter.values[0]);}
  val_t T17;
  { T17 = SOC_dev_vga_dev_vga__v_counter.values[0]+0x1L;}
  T17 = T17 & 0xffffffffL;
  val_t T18;
  { T18 = T14 ^ 0x1L;}
  val_t T19;
  { T19 = T7 & T18;}
  val_t T20;
  { T20 = TERNARY_1(T19, T17, T16);}
  { T21.values[0] = TERNARY(SOC_dev_vga_dev_vga__reset.values[0], 0x0L, T20);}
  val_t T22;
  { T22 = SOC_cpu_dpath__inst_reg.values[0] >> 16;}
  T22 = T22 & 0x1fL;
  { SOC_cpu_dpath_regfile__io_addrb.values[0] = T22;}
  val_t T23;
  { T23 = SOC_cpu_dpath_regfile__rf.get(SOC_cpu_dpath_regfile__io_addrb.values[0], 0);}
  { SOC_cpu_dpath_regfile__io_doutb.values[0] = T23;}
  { SOC_cpu_dpath__io_data_out.values[0] = SOC_cpu_dpath_regfile__io_doutb.values[0];}
  { SOC_cpu_cpath__io_ctrl_data_out.values[0] = SOC_cpu_dpath__io_data_out.values[0];}
  { SOC_cpu_cpath__io_bus_dat2.values[0] = SOC_cpu_cpath__io_ctrl_data_out.values[0];}
  { SOC_cpu__io_bus_dat2.values[0] = SOC_cpu_cpath__io_bus_dat2.values[0];}
  { SOC_dev__io_bus_dat2.values[0] = SOC_cpu__io_bus_dat2.values[0];}
  { SOC_dev_bus__io_from_cpu_dat2.values[0] = SOC_dev__io_bus_dat2.values[0];}
  { SOC_dev_bus__io_slaves_5_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_vga_dev__io_bus_dat2.values[0] = SOC_dev_bus__io_slaves_5_dat2.values[0];}
  { T24.values[0] = SOC_dev_vga_dev__io_bus_dat2.values[0];}
  T24.values[0] = T24.values[0] & 0xffffL;
  { SOC_cpu_dpath__io_pc_out.values[0] = SOC_cpu_dpath__pc.values[0];}
  { SOC_cpu_cpath__io_ctrl_pc_out.values[0] = SOC_cpu_dpath__io_pc_out.values[0];}
  val_t T25;
  T25 = SOC_cpu_cpath__state.values[0] == 0x13L;
  val_t T26;
  T26 = SOC_cpu_cpath__state.values[0] == 0x12L;
  val_t T27;
  { T27 = TERNARY(T26, 0x1L, T25);}
  val_t T28;
  T28 = SOC_cpu_cpath__state.values[0] == 0x11L;
  val_t T29;
  { T29 = TERNARY(T28, 0x0L, T27);}
  val_t T30;
  T30 = SOC_cpu_cpath__state.values[0] == 0x10L;
  val_t T31;
  { T31 = TERNARY(T30, 0x0L, T29);}
  val_t T32;
  T32 = SOC_cpu_cpath__state.values[0] == 0xfL;
  val_t T33;
  { T33 = TERNARY(T32, 0x0L, T31);}
  val_t T34;
  T34 = SOC_cpu_cpath__state.values[0] == 0xeL;
  val_t T35;
  { T35 = TERNARY(T34, 0x0L, T33);}
  val_t T36;
  T36 = SOC_cpu_cpath__state.values[0] == 0xdL;
  val_t T37;
  { T37 = TERNARY(T36, 0x0L, T35);}
  val_t T38;
  T38 = SOC_cpu_cpath__state.values[0] == 0xcL;
  val_t T39;
  { T39 = TERNARY(T38, 0x0L, T37);}
  val_t T40;
  T40 = SOC_cpu_cpath__state.values[0] == 0xbL;
  val_t T41;
  { T41 = TERNARY(T40, 0x0L, T39);}
  val_t T42;
  T42 = SOC_cpu_cpath__state.values[0] == 0xaL;
  val_t T43;
  { T43 = TERNARY(T42, 0x0L, T41);}
  val_t T44;
  T44 = SOC_cpu_cpath__state.values[0] == 0x9L;
  val_t T45;
  { T45 = TERNARY(T44, 0x0L, T43);}
  val_t T46;
  T46 = SOC_cpu_cpath__state.values[0] == 0x8L;
  val_t T47;
  { T47 = TERNARY(T46, 0x0L, T45);}
  val_t T48;
  T48 = SOC_cpu_cpath__state.values[0] == 0x7L;
  val_t T49;
  { T49 = TERNARY(T48, 0x0L, T47);}
  val_t T50;
  T50 = SOC_cpu_cpath__state.values[0] == 0x6L;
  val_t T51;
  { T51 = TERNARY(T50, 0x0L, T49);}
  val_t T52;
  T52 = SOC_cpu_cpath__state.values[0] == 0x5L;
  val_t T53;
  { T53 = TERNARY(T52, 0x0L, T51);}
  val_t T54;
  T54 = SOC_cpu_cpath__state.values[0] == 0x4L;
  val_t T55;
  { T55 = TERNARY(T54, 0x0L, T53);}
  val_t T56;
  T56 = SOC_cpu_cpath__state.values[0] == 0x3L;
  val_t T57;
  { T57 = TERNARY(T56, 0x0L, T55);}
  val_t T58;
  T58 = SOC_cpu_cpath__state.values[0] == 0x2L;
  val_t T59;
  { T59 = TERNARY(T58, 0x0L, T57);}
  val_t T60;
  T60 = SOC_cpu_cpath__state.values[0] == 0x1L;
  val_t T61;
  { T61 = TERNARY(T60, 0x0L, T59);}
  val_t SOC_cpu_cpath__inst_we;
  SOC_cpu_cpath__inst_we = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t SOC_cpu_cpath__bus_addr_src;
  { SOC_cpu_cpath__bus_addr_src = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T61);}
  val_t T62;
  T62 = SOC_cpu_cpath__bus_addr_src == 0x0L;
  val_t T63;
  { T63 = TERNARY(T62, SOC_cpu_cpath__io_ctrl_pc_out.values[0], 0x0L);}
  val_t T64;
  { T64 = ~SOC_cpu_dpath_regfile__io_doutb.values[0];}
  T64 = T64 & 0xffffffffL;
  val_t T65;
  T65 = SOC_cpu_cpath__state.values[0] == 0x16L;
  val_t T66;
  { T66 = T65 | 0x0L << 1;}
  val_t T67;
  T67 = SOC_cpu_cpath__state.values[0] == 0x15L;
  val_t T68;
  { T68 = TERNARY(T67, 0x2L, T66);}
  val_t T69;
  T69 = SOC_cpu_cpath__state.values[0] == 0x14L;
  val_t T70;
  { T70 = TERNARY(T69, 0x0L, T68);}
  val_t T71;
  { T71 = TERNARY(T25, 0x1L, T70);}
  val_t T72;
  { T72 = TERNARY(T26, 0x1L, T71);}
  val_t T73;
  { T73 = TERNARY(T28, 0x1L, T72);}
  val_t T74;
  { T74 = TERNARY(T30, 0x1L, T73);}
  val_t T75;
  { T75 = TERNARY(T32, 0x1L, T74);}
  val_t T76;
  { T76 = TERNARY(T34, 0x1L, T75);}
  val_t T77;
  { T77 = TERNARY(T36, 0x1L, T76);}
  val_t T78;
  { T78 = TERNARY(T38, 0x1L, T77);}
  val_t T79;
  { T79 = TERNARY(T40, 0x0L, T78);}
  val_t T80;
  { T80 = TERNARY(T42, 0x0L, T79);}
  val_t T81;
  { T81 = TERNARY(T44, 0x0L, T80);}
  val_t T82;
  { T82 = TERNARY(T46, 0x0L, T81);}
  val_t T83;
  { T83 = TERNARY(T48, 0x0L, T82);}
  val_t T84;
  { T84 = TERNARY(T50, 0x0L, T83);}
  val_t T85;
  { T85 = TERNARY(T52, 0x0L, T84);}
  val_t T86;
  { T86 = TERNARY(T54, 0x0L, T85);}
  val_t T87;
  { T87 = TERNARY(T56, 0x0L, T86);}
  val_t T88;
  { T88 = TERNARY(T58, 0x0L, T87);}
  val_t T89;
  { T89 = TERNARY(T60, 0x0L, T88);}
  val_t SOC_cpu_cpath__alu_b_sel;
  { SOC_cpu_cpath__alu_b_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T89);}
  val_t T90;
  T90 = (SOC_cpu_cpath__alu_b_sel >> 0) & 1;
  { SOC_cpu_cpath__io_ctrl_alu_b_sel.values[0] = T90;}
  { SOC_cpu_dpath__io_alu_b_sel.values[0] = SOC_cpu_cpath__io_ctrl_alu_b_sel.values[0];}
  val_t T91;
  { T91 = SOC_cpu_dpath__io_alu_b_sel.values[0] | 0x0L << 1;}
  val_t T92;
  T92 = T91 == 0x2L;
  val_t T93;
  { T93 = TERNARY(T92, T64, 0x0L);}
  val_t T94;
  { T94 = SOC_cpu_dpath__inst_reg.values[0];}
  T94 = T94 & 0xffffL;
  val_t T95;
  { T95 = T94 | 0x0L << 16;}
  val_t T96;
  T96 = SOC_cpu_dpath__io_alu_b_sel.values[0] == 0x1L;
  val_t T97;
  { T97 = TERNARY_1(T96, T95, T93);}
  val_t T98;
  T98 = SOC_cpu_dpath__io_alu_b_sel.values[0] == 0x0L;
  val_t T99;
  { T99 = TERNARY_1(T98, SOC_cpu_dpath_regfile__io_doutb.values[0], T97);}
  { SOC_cpu_dpath_alu__io_in_b.values[0] = T99;}
  val_t T100;
  { T100 = SOC_cpu_dpath__inst_reg.values[0] >> 21;}
  T100 = T100 & 0x1fL;
  { SOC_cpu_dpath_regfile__io_addra.values[0] = T100;}
  val_t T101;
  { T101 = SOC_cpu_dpath_regfile__rf.get(SOC_cpu_dpath_regfile__io_addra.values[0], 0);}
  { SOC_cpu_dpath_regfile__io_douta.values[0] = T101;}
  { SOC_cpu_dpath_alu__io_in_a.values[0] = SOC_cpu_dpath_regfile__io_douta.values[0];}
  val_t T102;
  T102 = SOC_cpu_dpath_alu__io_in_a.values[0]<SOC_cpu_dpath_alu__io_in_b.values[0];
  val_t T103;
  { T103 = T102 | 0x0L << 1;}
  val_t T104;
  { T104 = TERNARY(T65, 0x7L, 0x0L);}
  val_t T105;
  { T105 = TERNARY(T67, 0x4L, T104);}
  val_t T106;
  { T106 = TERNARY(T69, 0x6L, T105);}
  val_t T107;
  { T107 = TERNARY(T25, 0x2L, T106);}
  val_t T108;
  { T108 = TERNARY(T26, 0x2L, T107);}
  val_t T109;
  { T109 = TERNARY(T28, 0x2L, T108);}
  val_t T110;
  { T110 = TERNARY(T30, 0x3L, T109);}
  val_t T111;
  { T111 = TERNARY(T32, 0x1L, T110);}
  val_t T112;
  { T112 = TERNARY(T34, 0x0L, T111);}
  val_t T113;
  { T113 = TERNARY(T36, 0x2L, T112);}
  val_t T114;
  { T114 = TERNARY(T38, 0x2L, T113);}
  val_t T115;
  { T115 = TERNARY(T40, 0x0L, T114);}
  val_t T116;
  { T116 = TERNARY(T42, 0x5L, T115);}
  val_t T117;
  { T117 = TERNARY(T44, 0x7L, T116);}
  val_t T118;
  { T118 = TERNARY(T46, 0x4L, T117);}
  val_t T119;
  { T119 = TERNARY(T48, 0x3L, T118);}
  val_t T120;
  { T120 = TERNARY(T50, 0x1L, T119);}
  val_t T121;
  { T121 = TERNARY(T52, 0x0L, T120);}
  val_t T122;
  { T122 = TERNARY(T54, 0x6L, T121);}
  val_t T123;
  { T123 = TERNARY(T56, 0x6L, T122);}
  val_t T124;
  { T124 = TERNARY(T58, 0x2L, T123);}
  val_t T125;
  { T125 = TERNARY(T60, 0x2L, T124);}
  val_t SOC_cpu_cpath__alu_op;
  { SOC_cpu_cpath__alu_op = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T125);}
  { SOC_cpu_cpath__io_ctrl_alu_op.values[0] = SOC_cpu_cpath__alu_op;}
  { SOC_cpu_dpath__io_alu_op.values[0] = SOC_cpu_cpath__io_ctrl_alu_op.values[0];}
  { SOC_cpu_dpath_alu__io_alu_op.values[0] = SOC_cpu_dpath__io_alu_op.values[0];}
  val_t T126;
  T126 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x7L;
  val_t T127;
  { T127 = TERNARY(T126, T103, 0x0L);}
  val_t T128;
  { T128 = SOC_cpu_dpath_alu__io_in_a.values[0]-SOC_cpu_dpath_alu__io_in_b.values[0];}
  T128 = T128 & 0xffffffffL;
  val_t T129;
  T129 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x6L;
  val_t T130;
  { T130 = TERNARY_1(T129, T128, T127);}
  val_t T131;
  { T131 = SOC_cpu_dpath_alu__io_in_b.values[0];}
  T131 = T131 & 0x1fL;
  val_t T132;
  T132 = SOC_cpu_dpath_alu__io_in_a.values[0] >> T131;
  val_t T133;
  T133 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x5L;
  val_t T134;
  { T134 = TERNARY_1(T133, T132, T130);}
  val_t T135;
  { T135 = SOC_cpu_dpath_alu__io_in_a.values[0] | SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T136;
  { T136 = ~T135;}
  T136 = T136 & 0xffffffffL;
  val_t T137;
  T137 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x4L;
  val_t T138;
  { T138 = TERNARY_1(T137, T136, T134);}
  val_t T139;
  { T139 = SOC_cpu_dpath_alu__io_in_a.values[0] ^ SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T140;
  T140 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x3L;
  val_t T141;
  { T141 = TERNARY_1(T140, T139, T138);}
  val_t T142;
  { T142 = SOC_cpu_dpath_alu__io_in_a.values[0]+SOC_cpu_dpath_alu__io_in_b.values[0];}
  T142 = T142 & 0xffffffffL;
  val_t T143;
  T143 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x2L;
  val_t T144;
  { T144 = TERNARY_1(T143, T142, T141);}
  val_t T145;
  { T145 = SOC_cpu_dpath_alu__io_in_a.values[0] | SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T146;
  T146 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x1L;
  val_t T147;
  { T147 = TERNARY_1(T146, T145, T144);}
  val_t T148;
  { T148 = SOC_cpu_dpath_alu__io_in_a.values[0] & SOC_cpu_dpath_alu__io_in_b.values[0];}
  val_t T149;
  T149 = SOC_cpu_dpath_alu__io_alu_op.values[0] == 0x0L;
  val_t T150;
  { T150 = TERNARY_1(T149, T148, T147);}
  { SOC_cpu_dpath_alu__io_out.values[0] = T150;}
  { SOC_cpu_dpath__io_alu_out.values[0] = SOC_cpu_dpath_alu__io_out.values[0];}
  { SOC_cpu_cpath__io_ctrl_alu_out.values[0] = SOC_cpu_dpath__io_alu_out.values[0];}
  val_t T151;
  T151 = SOC_cpu_cpath__bus_addr_src == 0x1L;
  val_t T152;
  { T152 = TERNARY_1(T151, SOC_cpu_cpath__io_ctrl_alu_out.values[0], T63);}
  { SOC_cpu_cpath__io_bus_addr.values[0] = T152;}
  { SOC_cpu__io_bus_addr.values[0] = SOC_cpu_cpath__io_bus_addr.values[0];}
  { SOC_dev__io_bus_addr.values[0] = SOC_cpu__io_bus_addr.values[0];}
  { SOC_dev_bus__io_from_cpu_addr.values[0] = SOC_dev__io_bus_addr.values[0];}
  val_t T153;
  { T153 = SOC_dev_bus__io_from_cpu_addr.values[0];}
  T153 = T153 & 0xfffffffL;
  val_t T154;
  { T154 = T153 | 0x0L << 28;}
  { SOC_dev_bus__io_slaves_5_addr.values[0] = T154;}
  { SOC_dev_vga_dev__io_bus_addr.values[0] = SOC_dev_bus__io_slaves_5_addr.values[0];}
  val_t T155;
  { T155 = SOC_dev_vga_dev__io_bus_addr.values[0];}
  T155 = T155 & 0xfffL;
  val_t T156;
  T156 = T155<0x960L;
  val_t SOC_dev_bus__current_slave;
  { SOC_dev_bus__current_slave = SOC_dev_bus__io_from_cpu_addr.values[0] >> 28;}
  SOC_dev_bus__current_slave = SOC_dev_bus__current_slave & 0x7L;
  val_t T157;
  T157 = SOC_dev_bus__current_slave == 0x5L;
  val_t T158;
  { T158 = TERNARY(T26, 0x0L, T25);}
  val_t T159;
  { T159 = TERNARY(T28, 0x0L, T158);}
  val_t T160;
  { T160 = TERNARY(T30, 0x0L, T159);}
  val_t T161;
  { T161 = TERNARY(T32, 0x0L, T160);}
  val_t T162;
  { T162 = TERNARY(T34, 0x0L, T161);}
  val_t T163;
  { T163 = TERNARY(T36, 0x0L, T162);}
  val_t T164;
  { T164 = TERNARY(T38, 0x0L, T163);}
  val_t T165;
  { T165 = TERNARY(T40, 0x0L, T164);}
  val_t T166;
  { T166 = TERNARY(T42, 0x0L, T165);}
  val_t T167;
  { T167 = TERNARY(T44, 0x0L, T166);}
  val_t T168;
  { T168 = TERNARY(T46, 0x0L, T167);}
  val_t T169;
  { T169 = TERNARY(T48, 0x0L, T168);}
  val_t T170;
  { T170 = TERNARY(T50, 0x0L, T169);}
  val_t T171;
  { T171 = TERNARY(T52, 0x0L, T170);}
  val_t T172;
  { T172 = TERNARY(T54, 0x0L, T171);}
  val_t T173;
  { T173 = TERNARY(T56, 0x0L, T172);}
  val_t T174;
  { T174 = TERNARY(T58, 0x0L, T173);}
  val_t T175;
  { T175 = TERNARY(T60, 0x0L, T174);}
  val_t SOC_cpu_cpath__bus_we;
  { SOC_cpu_cpath__bus_we = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T175);}
  { SOC_cpu_cpath__io_bus_we.values[0] = SOC_cpu_cpath__bus_we;}
  { SOC_cpu__io_bus_we.values[0] = SOC_cpu_cpath__io_bus_we.values[0];}
  { SOC_dev__io_bus_we.values[0] = SOC_cpu__io_bus_we.values[0];}
  { SOC_dev_bus__io_from_cpu_we.values[0] = SOC_dev__io_bus_we.values[0];}
  val_t T176;
  T176 = (SOC_dev_bus__io_from_cpu_addr.values[0] >> 31) & 1;
  val_t SOC_dev_bus__ram_op;
  { SOC_dev_bus__ram_op = ~T176;}
  SOC_dev_bus__ram_op = SOC_dev_bus__ram_op & 0x1L;
  val_t T177;
  { T177 = ~SOC_dev_bus__ram_op;}
  T177 = T177 & 0x1L;
  val_t T178;
  { T178 = T177 & SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T179;
  { T179 = T178 & T157;}
  { SOC_dev_bus__io_slaves_5_we.values[0] = T179;}
  { SOC_dev_vga_dev__io_bus_we.values[0] = SOC_dev_bus__io_slaves_5_we.values[0];}
  val_t T180;
  T180 = SOC_dev_bus__current_slave == 0x5L;
  val_t T181;
  { T181 = TERNARY(T26, 0x1L, T25);}
  val_t T182;
  { T182 = TERNARY(T28, 0x0L, T181);}
  val_t T183;
  { T183 = TERNARY(T30, 0x0L, T182);}
  val_t T184;
  { T184 = TERNARY(T32, 0x0L, T183);}
  val_t T185;
  { T185 = TERNARY(T34, 0x0L, T184);}
  val_t T186;
  { T186 = TERNARY(T36, 0x0L, T185);}
  val_t T187;
  { T187 = TERNARY(T38, 0x0L, T186);}
  val_t T188;
  { T188 = TERNARY(T40, 0x0L, T187);}
  val_t T189;
  { T189 = TERNARY(T42, 0x0L, T188);}
  val_t T190;
  { T190 = TERNARY(T44, 0x0L, T189);}
  val_t T191;
  { T191 = TERNARY(T46, 0x0L, T190);}
  val_t T192;
  { T192 = TERNARY(T48, 0x0L, T191);}
  val_t T193;
  { T193 = TERNARY(T50, 0x0L, T192);}
  val_t T194;
  { T194 = TERNARY(T52, 0x0L, T193);}
  val_t T195;
  { T195 = TERNARY(T54, 0x0L, T194);}
  val_t T196;
  { T196 = TERNARY(T56, 0x0L, T195);}
  val_t T197;
  { T197 = TERNARY(T58, 0x0L, T196);}
  val_t T198;
  { T198 = TERNARY(T60, 0x0L, T197);}
  val_t SOC_cpu_cpath__bus_sel;
  { SOC_cpu_cpath__bus_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x1L, T198);}
  { SOC_cpu_cpath__io_bus_sel.values[0] = SOC_cpu_cpath__bus_sel;}
  { SOC_cpu__io_bus_sel.values[0] = SOC_cpu_cpath__io_bus_sel.values[0];}
  { SOC_dev__io_bus_sel.values[0] = SOC_cpu__io_bus_sel.values[0];}
  { SOC_dev_bus__io_from_cpu_sel.values[0] = SOC_dev__io_bus_sel.values[0];}
  val_t T199;
  { T199 = ~SOC_dev_bus__ram_op;}
  T199 = T199 & 0x1L;
  val_t T200;
  { T200 = T199 & SOC_dev_bus__io_from_cpu_sel.values[0];}
  val_t T201;
  { T201 = T200 & T180;}
  { SOC_dev_bus__io_slaves_5_sel.values[0] = T201;}
  { SOC_dev_vga_dev__io_bus_sel.values[0] = SOC_dev_bus__io_slaves_5_sel.values[0];}
  val_t T202;
  { T202 = SOC_dev_vga_dev__io_bus_sel.values[0] & SOC_dev_vga_dev__io_bus_we.values[0];}
  { T203.values[0] = T202 & T156;}
  { T204.values[0] = SOC_dev_vga_dev__io_bus_addr.values[0];}
  T204.values[0] = T204.values[0] & 0xfffL;
  { SOC_dev_bus__io_slaves_4_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_seven_seg__io_bus_dat2.values[0] = SOC_dev_bus__io_slaves_4_dat2.values[0];}
  val_t T205;
  T205 = SOC_dev_bus__current_slave == 0x4L;
  val_t T206;
  { T206 = ~SOC_dev_bus__ram_op;}
  T206 = T206 & 0x1L;
  val_t T207;
  { T207 = T206 & SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T208;
  { T208 = T207 & T205;}
  { SOC_dev_bus__io_slaves_4_we.values[0] = T208;}
  { SOC_dev_seven_seg__io_bus_we.values[0] = SOC_dev_bus__io_slaves_4_we.values[0];}
  val_t T209;
  T209 = SOC_dev_bus__current_slave == 0x4L;
  val_t T210;
  { T210 = ~SOC_dev_bus__ram_op;}
  T210 = T210 & 0x1L;
  val_t T211;
  { T211 = T210 & SOC_dev_bus__io_from_cpu_sel.values[0];}
  val_t T212;
  { T212 = T211 & T209;}
  { SOC_dev_bus__io_slaves_4_sel.values[0] = T212;}
  { SOC_dev_seven_seg__io_bus_sel.values[0] = SOC_dev_bus__io_slaves_4_sel.values[0];}
  val_t T213;
  { T213 = SOC_dev_seven_seg__io_bus_sel.values[0] & SOC_dev_seven_seg__io_bus_we.values[0];}
  val_t T214;
  { T214 = TERNARY_1(T213, SOC_dev_seven_seg__io_bus_dat2.values[0], SOC_dev_seven_seg__data_out.values[0]);}
  val_t T215;
  { T215 = T213 ^ 0x1L;}
  val_t T216;
  { T216 = T215 & SOC_dev_seven_seg__io_bus_sel.values[0];}
  val_t T217;
  { T217 = TERNARY_1(T216, SOC_dev_seven_seg__disp_data.values[0], T214);}
  val_t T218;
  { T218 = T213 | SOC_dev_seven_seg__io_bus_sel.values[0];}
  val_t T219;
  { T219 = T218 ^ 0x1L;}
  val_t T220;
  { T220 = TERNARY(T219, 0x0L, T217);}
  { SOC_dev_seven_seg__reset.values[0] = SOC_dev__reset.values[0];}
  { T221.values[0] = TERNARY(SOC_dev_seven_seg__reset.values[0], 0x0L, T220);}
  val_t T222;
  { T222 = TERNARY_1(T213, SOC_dev_seven_seg__io_bus_dat2.values[0], SOC_dev_seven_seg__disp_data.values[0]);}
  { T223.values[0] = TERNARY(SOC_dev_seven_seg__reset.values[0], 0x0L, T222);}
  { SOC_dev_bus__io_slaves_2_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_led__io_bus_dat2.values[0] = SOC_dev_bus__io_slaves_2_dat2.values[0];}
  val_t T224;
  T224 = SOC_dev_bus__current_slave == 0x2L;
  val_t T225;
  { T225 = ~SOC_dev_bus__ram_op;}
  T225 = T225 & 0x1L;
  val_t T226;
  { T226 = T225 & SOC_dev_bus__io_from_cpu_we.values[0];}
  val_t T227;
  { T227 = T226 & T224;}
  { SOC_dev_bus__io_slaves_2_we.values[0] = T227;}
  { SOC_dev_led__io_bus_we.values[0] = SOC_dev_bus__io_slaves_2_we.values[0];}
  val_t T228;
  T228 = SOC_dev_bus__current_slave == 0x2L;
  val_t T229;
  { T229 = ~SOC_dev_bus__ram_op;}
  T229 = T229 & 0x1L;
  val_t T230;
  { T230 = T229 & SOC_dev_bus__io_from_cpu_sel.values[0];}
  val_t T231;
  { T231 = T230 & T228;}
  { SOC_dev_bus__io_slaves_2_sel.values[0] = T231;}
  { SOC_dev_led__io_bus_sel.values[0] = SOC_dev_bus__io_slaves_2_sel.values[0];}
  val_t T232;
  { T232 = SOC_dev_led__io_bus_sel.values[0] & SOC_dev_led__io_bus_we.values[0];}
  val_t T233;
  { T233 = TERNARY_1(T232, SOC_dev_led__io_bus_dat2.values[0], SOC_dev_led__data_out.values[0]);}
  val_t T234;
  { T234 = SOC_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T235;
  { T235 = T232 ^ 0x1L;}
  val_t T236;
  { T236 = T235 & SOC_dev_led__io_bus_sel.values[0];}
  val_t T237;
  { T237 = TERNARY_1(T236, T234, T233);}
  val_t T238;
  { T238 = T232 | SOC_dev_led__io_bus_sel.values[0];}
  val_t T239;
  { T239 = T238 ^ 0x1L;}
  val_t T240;
  { T240 = TERNARY(T239, 0x0L, T237);}
  { SOC_dev_led__reset.values[0] = SOC_dev__reset.values[0];}
  { T241.values[0] = TERNARY(SOC_dev_led__reset.values[0], 0x0L, T240);}
  val_t T242;
  { T242 = SOC_dev_led__led_data.values[0] | 0x0L << 8;}
  val_t T243;
  { T243 = TERNARY_1(T232, SOC_dev_led__io_bus_dat2.values[0], T242);}
  val_t T244;
  { T244 = TERNARY(SOC_dev_led__reset.values[0], 0x0L, T243);}
  { T245.values[0] = T244;}
  T245.values[0] = T245.values[0] & 0xffL;
  { SOC_cpu__reset.values[0] = reset.values[0];}
  { SOC_cpu_dpath__reset.values[0] = SOC_cpu__reset.values[0];}
  { SOC_cpu_dpath_regfile__reset.values[0] = SOC_cpu_dpath__reset.values[0];}
  val_t T246;
  T246 = SOC_cpu_dpath_alu__io_out.values[0] << 0x10L;
  T246 = T246 & 0xffffffffffffL;
  val_t T247;
  T247 = SOC_cpu_cpath__state.values[0] == 0x18L;
  val_t T248;
  { T248 = TERNARY(T247, 0x2L, 0x0L);}
  val_t T249;
  T249 = SOC_cpu_cpath__state.values[0] == 0x17L;
  val_t T250;
  { T250 = TERNARY(T249, 0x0L, T248);}
  val_t T251;
  { T251 = TERNARY(T65, 0x0L, T250);}
  val_t T252;
  { T252 = TERNARY(T67, 0x0L, T251);}
  val_t T253;
  { T253 = TERNARY(T69, 0x0L, T252);}
  val_t T254;
  { T254 = TERNARY(T25, 0x0L, T253);}
  val_t T255;
  { T255 = TERNARY(T26, 0x1L, T254);}
  val_t T256;
  { T256 = TERNARY(T28, 0x3L, T255);}
  val_t T257;
  { T257 = TERNARY(T30, 0x0L, T256);}
  val_t T258;
  { T258 = TERNARY(T32, 0x0L, T257);}
  val_t T259;
  { T259 = TERNARY(T34, 0x0L, T258);}
  val_t T260;
  { T260 = TERNARY(T36, 0x0L, T259);}
  val_t T261;
  { T261 = TERNARY(T38, 0x0L, T260);}
  val_t T262;
  { T262 = TERNARY(T40, 0x0L, T261);}
  val_t T263;
  { T263 = TERNARY(T42, 0x0L, T262);}
  val_t T264;
  { T264 = TERNARY(T44, 0x0L, T263);}
  val_t T265;
  { T265 = TERNARY(T46, 0x0L, T264);}
  val_t T266;
  { T266 = TERNARY(T48, 0x0L, T265);}
  val_t T267;
  { T267 = TERNARY(T50, 0x0L, T266);}
  val_t T268;
  { T268 = TERNARY(T52, 0x0L, T267);}
  val_t T269;
  { T269 = TERNARY(T54, 0x0L, T268);}
  val_t T270;
  { T270 = TERNARY(T56, 0x0L, T269);}
  val_t T271;
  { T271 = TERNARY(T58, 0x0L, T270);}
  val_t T272;
  { T272 = TERNARY(T60, 0x0L, T271);}
  val_t SOC_cpu_cpath__reg_we_src;
  { SOC_cpu_cpath__reg_we_src = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T272);}
  { SOC_cpu_cpath__io_ctrl_reg_we_src.values[0] = SOC_cpu_cpath__reg_we_src;}
  { SOC_cpu_dpath__io_reg_we_src.values[0] = SOC_cpu_cpath__io_ctrl_reg_we_src.values[0];}
  val_t T273;
  T273 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x3L;
  val_t T274;
  { T274 = TERNARY(T273, T246, 0x0L);}
  val_t T275;
  { T275 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T275 = T275 & 0xffffffffL;
  val_t T276;
  { T276 = T275 | 0x0L << 32;}
  val_t T277;
  T277 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x2L;
  val_t T278;
  { T278 = TERNARY_1(T277, T276, T274);}
  { SOC_dev__io_devices_RAM_douta.values[0] = SOC__io_devices_RAM_douta.values[0];}
  { SOC_dev_ram_dev__io_ram_douta.values[0] = SOC_dev__io_devices_RAM_douta.values[0];}
  val_t T279;
  { T279 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 24;}
  T279 = T279 & 0xffL;
  val_t T280;
  { T280 = T279 | 0x0L << 8;}
  val_t T281;
  { T281 = SOC_dev_bus__io_from_cpu_addr.values[0];}
  T281 = T281 & 0xfffffffL;
  val_t T282;
  { T282 = T281 | 0x0L << 28;}
  { SOC_dev_bus__io_ram_slave_addr.values[0] = T282;}
  { SOC_dev_ram_dev__io_bus_addr.values[0] = SOC_dev_bus__io_ram_slave_addr.values[0];}
  val_t T283;
  { T283 = SOC_dev_ram_dev__io_bus_addr.values[0];}
  T283 = T283 & 0x3L;
  val_t T284;
  T284 = T283 == 0x3L;
  val_t T285;
  { T285 = TERNARY_1(T284, T280, SOC_dev_ram_dev__io_ram_douta.values[0]);}
  val_t T286;
  { T286 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 16;}
  T286 = T286 & 0xffffL;
  val_t T287;
  { T287 = T286 | 0x0L << 16;}
  val_t T288;
  T288 = T283 == 0x2L;
  val_t T289;
  { T289 = TERNARY_1(T288, T287, T285);}
  val_t T290;
  { T290 = SOC_dev_ram_dev__io_ram_douta.values[0] >> 8;}
  T290 = T290 & 0xffffffL;
  val_t T291;
  { T291 = T290 | 0x0L << 24;}
  val_t T292;
  T292 = T283 == 0x1L;
  val_t T293;
  { T293 = TERNARY_1(T292, T291, T289);}
  val_t T294;
  T294 = T283 == 0x0L;
  val_t T295;
  { T295 = TERNARY_1(T294, SOC_dev_ram_dev__io_ram_douta.values[0], T293);}
  { SOC_dev_ram_dev__io_bus_dat4.values[0] = T295;}
  { SOC_dev_bus__io_ram_slave_dat4.values[0] = SOC_dev_ram_dev__io_bus_dat4.values[0];}
  val_t T296;
  T296 = SOC_dev_bus__ram_op == 0x1L;
  val_t T297;
  { T297 = TERNARY(T296, SOC_dev_bus__io_ram_slave_dat4.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_1__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_7_dat4.values[0] = SOC_dev_WB_Empty_Dev_1__io_bus_dat4.values[0];}
  val_t T298;
  T298 = SOC_dev_bus__current_slave == 0x7L;
  val_t T299;
  { T299 = TERNARY(T298, SOC_dev_bus__io_slaves_7_dat4.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_6_dat4.values[0] = SOC_dev_WB_Empty_Dev__io_bus_dat4.values[0];}
  val_t T300;
  T300 = SOC_dev_bus__current_slave == 0x6L;
  val_t T301;
  { T301 = TERNARY(T300, SOC_dev_bus__io_slaves_6_dat4.values[0], T299);}
  val_t T302;
  { T302 = SOC_dev_vga_dev__io_bus_addr.values[0];}
  T302 = T302 & 0xfffL;
  val_t T303;
  { T303 = SOC_dev_vga_dev__vmem.get(T302, 0);}
  val_t T304;
  { T304 = T303 | 0x0L << 16;}
  { SOC_dev_vga_dev__io_bus_dat4.values[0] = T304;}
  { SOC_dev_bus__io_slaves_5_dat4.values[0] = SOC_dev_vga_dev__io_bus_dat4.values[0];}
  val_t T305;
  T305 = SOC_dev_bus__current_slave == 0x5L;
  val_t T306;
  { T306 = TERNARY_1(T305, SOC_dev_bus__io_slaves_5_dat4.values[0], T301);}
  { SOC_dev_seven_seg__io_bus_dat4.values[0] = SOC_dev_seven_seg__data_out.values[0];}
  { SOC_dev_bus__io_slaves_4_dat4.values[0] = SOC_dev_seven_seg__io_bus_dat4.values[0];}
  val_t T307;
  T307 = SOC_dev_bus__current_slave == 0x4L;
  val_t T308;
  { T308 = TERNARY_1(T307, SOC_dev_bus__io_slaves_4_dat4.values[0], T306);}
  { SOC_dev_counter__io_bus_dat4.values[0] = 0x0L;}
  { SOC_dev_bus__io_slaves_3_dat4.values[0] = SOC_dev_counter__io_bus_dat4.values[0];}
  val_t T309;
  T309 = SOC_dev_bus__current_slave == 0x3L;
  val_t T310;
  { T310 = TERNARY(T309, SOC_dev_bus__io_slaves_3_dat4.values[0], T308);}
  { SOC_dev_led__io_bus_dat4.values[0] = SOC_dev_led__data_out.values[0];}
  { SOC_dev_bus__io_slaves_2_dat4.values[0] = SOC_dev_led__io_bus_dat4.values[0];}
  val_t T311;
  T311 = SOC_dev_bus__current_slave == 0x2L;
  val_t T312;
  { T312 = TERNARY_1(T311, SOC_dev_bus__io_slaves_2_dat4.values[0], T310);}
  { SOC_dev__io_devices_BTN.values[0] = SOC__io_devices_BTN.values[0];}
  { SOC_dev_btn__io_BTN.values[0] = SOC_dev__io_devices_BTN.values[0];}
  val_t T313;
  { T313 = SOC_dev_btn__io_BTN.values[0] | 0x0L << 5;}
  { SOC_dev_btn__io_bus_dat4.values[0] = T313;}
  { SOC_dev_bus__io_slaves_1_dat4.values[0] = SOC_dev_btn__io_bus_dat4.values[0];}
  val_t T314;
  T314 = SOC_dev_bus__current_slave == 0x1L;
  val_t T315;
  { T315 = TERNARY_1(T314, SOC_dev_bus__io_slaves_1_dat4.values[0], T312);}
  { SOC_dev__io_devices_SW.values[0] = SOC__io_devices_SW.values[0];}
  { SOC_dev_sw__io_SW.values[0] = SOC_dev__io_devices_SW.values[0];}
  val_t T316;
  { T316 = SOC_dev_sw__io_SW.values[0] | 0x0L << 8;}
  { SOC_dev_sw__io_bus_dat4.values[0] = T316;}
  { SOC_dev_bus__io_slaves_0_dat4.values[0] = SOC_dev_sw__io_bus_dat4.values[0];}
  val_t T317;
  T317 = SOC_dev_bus__current_slave == 0x0L;
  val_t T318;
  { T318 = TERNARY_1(T317, SOC_dev_bus__io_slaves_0_dat4.values[0], T315);}
  val_t T319;
  T319 = SOC_dev_bus__ram_op == 0x0L;
  val_t T320;
  { T320 = TERNARY_1(T319, T318, T297);}
  { SOC_dev_bus__io_from_cpu_dat4.values[0] = T320;}
  { SOC_dev__io_bus_dat4.values[0] = SOC_dev_bus__io_from_cpu_dat4.values[0];}
  { SOC_cpu__io_bus_dat4.values[0] = SOC_dev__io_bus_dat4.values[0];}
  { SOC_cpu_cpath__io_bus_dat4.values[0] = SOC_cpu__io_bus_dat4.values[0];}
  { SOC_cpu_cpath__io_ctrl_bus_data.values[0] = SOC_cpu_cpath__io_bus_dat4.values[0];}
  { SOC_cpu_dpath__io_bus_data.values[0] = SOC_cpu_cpath__io_ctrl_bus_data.values[0];}
  val_t T321;
  { T321 = SOC_cpu_dpath__io_bus_data.values[0] | 0x0L << 32;}
  val_t T322;
  T322 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x1L;
  val_t T323;
  { T323 = TERNARY_1(T322, T321, T278);}
  val_t T324;
  { T324 = SOC_cpu_dpath_alu__io_out.values[0] | 0x0L << 32;}
  val_t T325;
  T325 = SOC_cpu_dpath__io_reg_we_src.values[0] == 0x0L;
  val_t T326;
  { T326 = TERNARY_1(T325, T324, T323);}
  val_t T327;
  { T327 = T326;}
  T327 = T327 & 0xffffffffL;
  { SOC_cpu_dpath_regfile__io_wtdata.values[0] = T327;}
  val_t T328;
  { T328 = TERNARY(T247, 0x2L, 0x0L);}
  val_t T329;
  { T329 = TERNARY(T249, 0x0L, T328);}
  val_t T330;
  { T330 = TERNARY(T65, 0x1L, T329);}
  val_t T331;
  { T331 = TERNARY(T67, 0x0L, T330);}
  val_t T332;
  { T332 = TERNARY(T69, 0x0L, T331);}
  val_t T333;
  { T333 = TERNARY(T25, 0x0L, T332);}
  val_t T334;
  { T334 = TERNARY(T26, 0x1L, T333);}
  val_t T335;
  { T335 = TERNARY(T28, 0x1L, T334);}
  val_t T336;
  { T336 = TERNARY(T30, 0x1L, T335);}
  val_t T337;
  { T337 = TERNARY(T32, 0x1L, T336);}
  val_t T338;
  { T338 = TERNARY(T34, 0x1L, T337);}
  val_t T339;
  { T339 = TERNARY(T36, 0x1L, T338);}
  val_t T340;
  { T340 = TERNARY(T38, 0x1L, T339);}
  val_t T341;
  { T341 = TERNARY(T40, 0x0L, T340);}
  val_t T342;
  { T342 = TERNARY(T42, 0x0L, T341);}
  val_t T343;
  { T343 = TERNARY(T44, 0x0L, T342);}
  val_t T344;
  { T344 = TERNARY(T46, 0x0L, T343);}
  val_t T345;
  { T345 = TERNARY(T48, 0x0L, T344);}
  val_t T346;
  { T346 = TERNARY(T50, 0x0L, T345);}
  val_t T347;
  { T347 = TERNARY(T52, 0x0L, T346);}
  val_t T348;
  { T348 = TERNARY(T54, 0x0L, T347);}
  val_t T349;
  { T349 = TERNARY(T56, 0x0L, T348);}
  val_t T350;
  { T350 = TERNARY(T58, 0x0L, T349);}
  val_t T351;
  { T351 = TERNARY(T60, 0x0L, T350);}
  val_t SOC_cpu_cpath__reg_we_dst;
  { SOC_cpu_cpath__reg_we_dst = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T351);}
  { SOC_cpu_cpath__io_ctrl_reg_we_dst.values[0] = SOC_cpu_cpath__reg_we_dst;}
  { SOC_cpu_dpath__io_reg_we_dst.values[0] = SOC_cpu_cpath__io_ctrl_reg_we_dst.values[0];}
  val_t T352;
  T352 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x2L;
  val_t T353;
  { T353 = TERNARY(T352, 0x1fL, 0x0L);}
  val_t T354;
  { T354 = SOC_cpu_dpath__inst_reg.values[0] >> 16;}
  T354 = T354 & 0x1fL;
  val_t T355;
  T355 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x1L;
  val_t T356;
  { T356 = TERNARY_1(T355, T354, T353);}
  val_t T357;
  { T357 = SOC_cpu_dpath__inst_reg.values[0] >> 11;}
  T357 = T357 & 0x1fL;
  val_t T358;
  T358 = SOC_cpu_dpath__io_reg_we_dst.values[0] == 0x0L;
  val_t T359;
  { T359 = TERNARY_1(T358, T357, T356);}
  { SOC_cpu_dpath_regfile__io_wtaddr.values[0] = T359;}
  val_t T360;
  T360 = SOC_cpu_dpath_regfile__io_wtaddr.values[0] != 0x0L;
  val_t T361;
  { T361 = TERNARY(T249, 0x0L, T247);}
  val_t T362;
  { T362 = TERNARY(T65, 0x1L, T361);}
  val_t T363;
  { T363 = TERNARY(T67, 0x0L, T362);}
  val_t T364;
  { T364 = TERNARY(T69, 0x0L, T363);}
  val_t T365;
  { T365 = TERNARY(T25, 0x0L, T364);}
  val_t T366;
  { T366 = TERNARY(T26, 0x1L, T365);}
  val_t T367;
  { T367 = TERNARY(T28, 0x1L, T366);}
  val_t T368;
  { T368 = TERNARY(T30, 0x1L, T367);}
  val_t T369;
  { T369 = TERNARY(T32, 0x1L, T368);}
  val_t T370;
  { T370 = TERNARY(T34, 0x1L, T369);}
  val_t T371;
  { T371 = TERNARY(T36, 0x1L, T370);}
  val_t T372;
  { T372 = TERNARY(T38, 0x1L, T371);}
  val_t T373;
  { T373 = TERNARY(T40, 0x0L, T372);}
  val_t T374;
  { T374 = TERNARY(T42, 0x1L, T373);}
  val_t T375;
  { T375 = TERNARY(T44, 0x1L, T374);}
  val_t T376;
  { T376 = TERNARY(T46, 0x1L, T375);}
  val_t T377;
  { T377 = TERNARY(T48, 0x1L, T376);}
  val_t T378;
  { T378 = TERNARY(T50, 0x1L, T377);}
  val_t T379;
  { T379 = TERNARY(T52, 0x1L, T378);}
  val_t T380;
  { T380 = TERNARY(T54, 0x1L, T379);}
  val_t T381;
  { T381 = TERNARY(T56, 0x1L, T380);}
  val_t T382;
  { T382 = TERNARY(T58, 0x1L, T381);}
  val_t T383;
  { T383 = TERNARY(T60, 0x1L, T382);}
  val_t SOC_cpu_cpath__reg_we;
  { SOC_cpu_cpath__reg_we = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T383);}
  { SOC_cpu_cpath__io_ctrl_reg_we.values[0] = SOC_cpu_cpath__reg_we;}
  { SOC_cpu_dpath__io_reg_we.values[0] = SOC_cpu_cpath__io_ctrl_reg_we.values[0];}
  { SOC_cpu_dpath_regfile__io_we.values[0] = SOC_cpu_dpath__io_reg_we.values[0];}
  { T384.values[0] = SOC_cpu_dpath_regfile__io_we.values[0] & T360;}
  { SOC_cpu_cpath__io_ctrl_inst_we.values[0] = SOC_cpu_cpath__inst_we;}
  { SOC_cpu_dpath__io_inst_we.values[0] = SOC_cpu_cpath__io_ctrl_inst_we.values[0];}
  val_t T385;
  { T385 = TERNARY_1(SOC_cpu_dpath__io_inst_we.values[0], SOC_cpu_dpath__io_bus_data.values[0], SOC_cpu_dpath__inst_reg.values[0]);}
  { T386.values[0] = TERNARY(SOC_cpu_dpath__reset.values[0], 0x0L, T385);}
  val_t T387;
  { T387 = SOC_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T388;
  { T388 = TERNARY(T247, 0x2L, 0x0L);}
  val_t T389;
  { T389 = TERNARY(T249, 0x2L, T388);}
  val_t T390;
  { T390 = TERNARY(T65, 0x0L, T389);}
  val_t T391;
  { T391 = TERNARY(T67, 0x1L, T390);}
  val_t T392;
  { T392 = TERNARY(T69, 0x1L, T391);}
  val_t T393;
  { T393 = TERNARY(T25, 0x0L, T392);}
  val_t T394;
  { T394 = TERNARY(T26, 0x0L, T393);}
  val_t T395;
  { T395 = TERNARY(T28, 0x0L, T394);}
  val_t T396;
  { T396 = TERNARY(T30, 0x0L, T395);}
  val_t T397;
  { T397 = TERNARY(T32, 0x0L, T396);}
  val_t T398;
  { T398 = TERNARY(T34, 0x0L, T397);}
  val_t T399;
  { T399 = TERNARY(T36, 0x0L, T398);}
  val_t T400;
  { T400 = TERNARY(T38, 0x0L, T399);}
  val_t T401;
  { T401 = TERNARY(T40, 0x3L, T400);}
  val_t T402;
  { T402 = TERNARY(T42, 0x0L, T401);}
  val_t T403;
  { T403 = TERNARY(T44, 0x0L, T402);}
  val_t T404;
  { T404 = TERNARY(T46, 0x0L, T403);}
  val_t T405;
  { T405 = TERNARY(T48, 0x0L, T404);}
  val_t T406;
  { T406 = TERNARY(T50, 0x0L, T405);}
  val_t T407;
  { T407 = TERNARY(T52, 0x0L, T406);}
  val_t T408;
  { T408 = TERNARY(T54, 0x0L, T407);}
  val_t T409;
  { T409 = TERNARY(T56, 0x0L, T408);}
  val_t T410;
  { T410 = TERNARY(T58, 0x0L, T409);}
  val_t T411;
  { T411 = TERNARY(T60, 0x0L, T410);}
  val_t SOC_cpu_cpath__pc_next_sel;
  { SOC_cpu_cpath__pc_next_sel = TERNARY(SOC_cpu_cpath__inst_we, 0x0L, T411);}
  { SOC_cpu_cpath__io_ctrl_pc_next_sel.values[0] = SOC_cpu_cpath__pc_next_sel;}
  { SOC_cpu_dpath__io_pc_next_sel.values[0] = SOC_cpu_cpath__io_ctrl_pc_next_sel.values[0];}
  val_t T412;
  T412 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x3L;
  val_t T413;
  { T413 = TERNARY(T412, SOC_cpu_dpath_regfile__io_douta.values[0], 0x0L);}
  val_t T414;
  { T414 = SOC_cpu_dpath__inst_reg.values[0];}
  T414 = T414 & 0x3ffffffL;
  val_t T415;
  T415 = T414 << 0x2L;
  T415 = T415 & 0xfffffffL;
  val_t T416;
  { T416 = SOC_cpu_dpath__pc.values[0] >> 28;}
  T416 = T416 & 0xfL;
  val_t T417;
  { T417 = T416 | 0x0L << 4;}
  val_t T418;
  { T418 = T417 | T415;}
  val_t T419;
  { T419 = T418 | 0x0L << 28;}
  val_t T420;
  T420 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x2L;
  val_t T421;
  { T421 = TERNARY_1(T420, T419, T413);}
  val_t T422;
  { T422 = T421 | 0x0L << 32;}
  val_t T423;
  { T423 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T423 = T423 & 0xffffffffL;
  val_t T424;
  T424 = SOC_cpu_dpath_alu__io_out.values[0] != 0x0L;
  val_t T425;
  { T425 = T424 ^ 0x1L;}
  { SOC_cpu_dpath_alu__io_zero.values[0] = T425;}
  val_t T426;
  T426 = SOC_cpu_dpath_alu__io_zero.values[0] == 0x0L;
  val_t T427;
  { T427 = TERNARY(T426, T423, 0x0L);}
  val_t T428;
  { T428 = T427 | 0x0L << 32;}
  val_t T429;
  { T429 = SOC_cpu_dpath__pc.values[0] | 0x0L << 32;}
  val_t T430;
  { T430 = SOC_cpu_dpath__inst_reg.values[0];}
  T430 = T430 & 0xffffL;
  val_t T431;
  T431 = T430 << 0x2L;
  T431 = T431 & 0x3ffffL;
  val_t T432;
  T432 = (T431 >> 17) & 1;
  val_t T433;
  { T433 = TERNARY(T432, 0x7fffL, 0x0L);}
  val_t T434;
  { T434 = T431 | T433 << 18;}
  val_t T435;
  { T435 = T434+T429;}
  T435 = T435 & 0x1ffffffffL;
  val_t T436;
  T436 = SOC_cpu_dpath_alu__io_zero.values[0] == 0x1L;
  val_t T437;
  { T437 = TERNARY_1(T436, T435, T428);}
  val_t T438;
  T438 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x1L;
  val_t T439;
  { T439 = TERNARY_1(T438, T437, T422);}
  val_t T440;
  { T440 = SOC_cpu_dpath__pc.values[0]+0x4L;}
  T440 = T440 & 0xffffffffL;
  val_t T441;
  { T441 = T440 | 0x0L << 32;}
  val_t T442;
  T442 = SOC_cpu_dpath__io_pc_next_sel.values[0] == 0x0L;
  val_t SOC_cpu_dpath__pc_next;
  { SOC_cpu_dpath__pc_next = TERNARY_1(T442, T441, T439);}
  val_t SOC_cpu_cpath__pc_we;
  SOC_cpu_cpath__pc_we = SOC_cpu_cpath__inst_we == 0x0L;
  { SOC_cpu_cpath__io_ctrl_pc_we.values[0] = SOC_cpu_cpath__pc_we;}
  { SOC_cpu_dpath__io_pc_we.values[0] = SOC_cpu_cpath__io_ctrl_pc_we.values[0];}
  val_t T443;
  { T443 = TERNARY_1(SOC_cpu_dpath__io_pc_we.values[0], SOC_cpu_dpath__pc_next, T387);}
  val_t T444;
  { T444 = TERNARY(SOC_cpu_dpath__reset.values[0], 0x0L, T443);}
  { T445.values[0] = T444;}
  T445.values[0] = T445.values[0] & 0xffffffffL;
  { SOC_cpu_dpath__io_inst.values[0] = SOC_cpu_dpath__inst_reg.values[0];}
  { SOC_cpu_cpath__io_ctrl_inst.values[0] = SOC_cpu_dpath__io_inst.values[0];}
  val_t T446;
  T446 = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t SOC_cpu_cpath__inst;
  { SOC_cpu_cpath__inst = TERNARY_1(T446, SOC_cpu_cpath__io_bus_dat4.values[0], SOC_cpu_cpath__io_ctrl_inst.values[0]);}
  val_t SOC_cpu_cpath__inst_op;
  { SOC_cpu_cpath__inst_op = SOC_cpu_cpath__inst >> 26;}
  SOC_cpu_cpath__inst_op = SOC_cpu_cpath__inst_op & 0x3fL;
  val_t T447;
  T447 = SOC_cpu_cpath__inst_op == 0x3L;
  val_t T448;
  { T448 = TERNARY(T447, 0x18L, 0x0L);}
  val_t T449;
  T449 = SOC_cpu_cpath__inst_op == 0x2L;
  val_t T450;
  { T450 = TERNARY(T449, 0x17L, T448);}
  val_t T451;
  T451 = SOC_cpu_cpath__inst_op == 0xaL;
  val_t T452;
  { T452 = TERNARY(T451, 0x16L, T450);}
  val_t T453;
  T453 = SOC_cpu_cpath__inst_op == 0x5L;
  val_t T454;
  { T454 = TERNARY(T453, 0x15L, T452);}
  val_t T455;
  T455 = SOC_cpu_cpath__inst_op == 0x4L;
  val_t T456;
  { T456 = TERNARY(T455, 0x14L, T454);}
  val_t T457;
  T457 = SOC_cpu_cpath__inst_op == 0x2bL;
  val_t T458;
  { T458 = TERNARY(T457, 0x13L, T456);}
  val_t T459;
  T459 = SOC_cpu_cpath__inst_op == 0x23L;
  val_t T460;
  { T460 = TERNARY(T459, 0x12L, T458);}
  val_t T461;
  T461 = SOC_cpu_cpath__inst_op == 0xfL;
  val_t T462;
  { T462 = TERNARY(T461, 0x11L, T460);}
  val_t T463;
  T463 = SOC_cpu_cpath__inst_op == 0xeL;
  val_t T464;
  { T464 = TERNARY(T463, 0x10L, T462);}
  val_t T465;
  T465 = SOC_cpu_cpath__inst_op == 0xdL;
  val_t T466;
  { T466 = TERNARY(T465, 0xfL, T464);}
  val_t T467;
  T467 = SOC_cpu_cpath__inst_op == 0xcL;
  val_t T468;
  { T468 = TERNARY(T467, 0xeL, T466);}
  val_t T469;
  T469 = SOC_cpu_cpath__inst_op == 0x9L;
  val_t T470;
  { T470 = TERNARY(T469, 0xdL, T468);}
  val_t T471;
  T471 = SOC_cpu_cpath__inst_op == 0x8L;
  val_t T472;
  { T472 = TERNARY(T471, 0xcL, T470);}
  val_t SOC_cpu_cpath__inst_func;
  { SOC_cpu_cpath__inst_func = SOC_cpu_cpath__inst;}
  SOC_cpu_cpath__inst_func = SOC_cpu_cpath__inst_func & 0x3fL;
  val_t T473;
  T473 = SOC_cpu_cpath__inst_func == 0x8L;
  val_t T474;
  { T474 = TERNARY(T473, 0xbL, 0x0L);}
  val_t T475;
  T475 = SOC_cpu_cpath__inst_func == 0x6L;
  val_t T476;
  { T476 = TERNARY(T475, 0xaL, T474);}
  val_t T477;
  T477 = SOC_cpu_cpath__inst_func == 0x2aL;
  val_t T478;
  { T478 = TERNARY(T477, 0x9L, T476);}
  val_t T479;
  T479 = SOC_cpu_cpath__inst_func == 0x27L;
  val_t T480;
  { T480 = TERNARY(T479, 0x8L, T478);}
  val_t T481;
  T481 = SOC_cpu_cpath__inst_func == 0x26L;
  val_t T482;
  { T482 = TERNARY(T481, 0x7L, T480);}
  val_t T483;
  T483 = SOC_cpu_cpath__inst_func == 0x25L;
  val_t T484;
  { T484 = TERNARY(T483, 0x6L, T482);}
  val_t T485;
  T485 = SOC_cpu_cpath__inst_func == 0x24L;
  val_t T486;
  { T486 = TERNARY(T485, 0x5L, T484);}
  val_t T487;
  T487 = SOC_cpu_cpath__inst_func == 0x23L;
  val_t T488;
  { T488 = TERNARY(T487, 0x4L, T486);}
  val_t T489;
  T489 = SOC_cpu_cpath__inst_func == 0x22L;
  val_t T490;
  { T490 = TERNARY(T489, 0x3L, T488);}
  val_t T491;
  T491 = SOC_cpu_cpath__inst_func == 0x21L;
  val_t T492;
  { T492 = TERNARY(T491, 0x2L, T490);}
  val_t T493;
  T493 = SOC_cpu_cpath__inst_func == 0x20L;
  val_t T494;
  { T494 = TERNARY(T493, 0x1L, T492);}
  val_t T495;
  T495 = SOC_cpu_cpath__inst_op == 0x0L;
  val_t T496;
  { T496 = TERNARY_1(T495, T494, T472);}
  val_t T497;
  T497 = SOC_cpu_cpath__state.values[0] == 0x0L;
  val_t T498;
  { T498 = TERNARY(T497, T496, 0x0L);}
  { SOC_dev_ram_dev__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_ram_slave_ack.values[0] = SOC_dev_ram_dev__io_bus_ack.values[0];}
  val_t T499;
  T499 = SOC_dev_bus__ram_op == 0x1L;
  val_t T500;
  { T500 = TERNARY(T499, SOC_dev_bus__io_ram_slave_ack.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev_1__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_7_ack.values[0] = SOC_dev_WB_Empty_Dev_1__io_bus_ack.values[0];}
  val_t T501;
  T501 = SOC_dev_bus__current_slave == 0x7L;
  val_t T502;
  { T502 = TERNARY(T501, SOC_dev_bus__io_slaves_7_ack.values[0], 0x0L);}
  { SOC_dev_WB_Empty_Dev__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_6_ack.values[0] = SOC_dev_WB_Empty_Dev__io_bus_ack.values[0];}
  val_t T503;
  T503 = SOC_dev_bus__current_slave == 0x6L;
  val_t T504;
  { T504 = TERNARY(T503, SOC_dev_bus__io_slaves_6_ack.values[0], T502);}
  { SOC_dev_vga_dev__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_5_ack.values[0] = SOC_dev_vga_dev__io_bus_ack.values[0];}
  val_t T505;
  T505 = SOC_dev_bus__current_slave == 0x5L;
  val_t T506;
  { T506 = TERNARY(T505, SOC_dev_bus__io_slaves_5_ack.values[0], T504);}
  { SOC_dev_seven_seg__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_4_ack.values[0] = SOC_dev_seven_seg__io_bus_ack.values[0];}
  val_t T507;
  T507 = SOC_dev_bus__current_slave == 0x4L;
  val_t T508;
  { T508 = TERNARY(T507, SOC_dev_bus__io_slaves_4_ack.values[0], T506);}
  { SOC_dev_counter__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_3_ack.values[0] = SOC_dev_counter__io_bus_ack.values[0];}
  val_t T509;
  T509 = SOC_dev_bus__current_slave == 0x3L;
  val_t T510;
  { T510 = TERNARY(T509, SOC_dev_bus__io_slaves_3_ack.values[0], T508);}
  { SOC_dev_led__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_2_ack.values[0] = SOC_dev_led__io_bus_ack.values[0];}
  val_t T511;
  T511 = SOC_dev_bus__current_slave == 0x2L;
  val_t T512;
  { T512 = TERNARY(T511, SOC_dev_bus__io_slaves_2_ack.values[0], T510);}
  { SOC_dev_btn__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_1_ack.values[0] = SOC_dev_btn__io_bus_ack.values[0];}
  val_t T513;
  T513 = SOC_dev_bus__current_slave == 0x1L;
  val_t T514;
  { T514 = TERNARY(T513, SOC_dev_bus__io_slaves_1_ack.values[0], T512);}
  { SOC_dev_sw__io_bus_ack.values[0] = 0x1L;}
  { SOC_dev_bus__io_slaves_0_ack.values[0] = SOC_dev_sw__io_bus_ack.values[0];}
  val_t T515;
  T515 = SOC_dev_bus__current_slave == 0x0L;
  val_t T516;
  { T516 = TERNARY(T515, SOC_dev_bus__io_slaves_0_ack.values[0], T514);}
  val_t T517;
  T517 = SOC_dev_bus__ram_op == 0x0L;
  val_t T518;
  { T518 = TERNARY_1(T517, T516, T500);}
  { SOC_dev_bus__io_from_cpu_ack.values[0] = T518;}
  { SOC_dev__io_bus_ack.values[0] = SOC_dev_bus__io_from_cpu_ack.values[0];}
  { SOC_cpu__io_bus_ack.values[0] = SOC_dev__io_bus_ack.values[0];}
  { SOC_cpu_cpath__io_bus_ack.values[0] = SOC_cpu__io_bus_ack.values[0];}
  val_t T519;
  { T519 = TERNARY_1(SOC_cpu_cpath__io_bus_ack.values[0], T498, SOC_cpu_cpath__state.values[0]);}
  { SOC_cpu_cpath__reset.values[0] = SOC_cpu__reset.values[0];}
  { T520.values[0] = TERNARY(SOC_cpu_cpath__reset.values[0], 0x0L, T519);}
  { SOC_dev_led__io_LED.values[0] = SOC_dev_led__led_data.values[0];}
  { SOC_dev__io_devices_LED.values[0] = SOC_dev_led__io_LED.values[0];}
  { SOC__io_devices_LED.values[0] = SOC_dev__io_devices_LED.values[0];}
  { SOC_dev_seven_seg__io_DISP_NUM.values[0] = SOC_dev_seven_seg__disp_data.values[0];}
  { SOC_dev__io_devices_DISP_NUM.values[0] = SOC_dev_seven_seg__io_DISP_NUM.values[0];}
  { SOC__io_devices_DISP_NUM.values[0] = SOC_dev__io_devices_DISP_NUM.values[0];}
  val_t T521;
  { T521 = SOC_dev_vga_dev_vga__h_counter.values[0]-0x90L;}
  T521 = T521 & 0xffffffffL;
  val_t T522;
  T522 = SOC_dev_vga_dev_vga__h_counter.values[0]<0x320L;
  val_t T523;
  T523 = 0x310L<=SOC_dev_vga_dev_vga__h_counter.values[0];
  val_t T524;
  { T524 = T523 & T522;}
  val_t T525;
  { T525 = TERNARY(T524, 0x3L, 0x0L);}
  val_t T526;
  T526 = SOC_dev_vga_dev_vga__h_counter.values[0]<0x310L;
  val_t T527;
  T527 = 0x90L<=SOC_dev_vga_dev_vga__h_counter.values[0];
  val_t T528;
  { T528 = T527 & T526;}
  val_t T529;
  { T529 = TERNARY(T528, 0x2L, T525);}
  val_t T530;
  T530 = SOC_dev_vga_dev_vga__h_counter.values[0]<0x90L;
  val_t T531;
  T531 = 0x60L<=SOC_dev_vga_dev_vga__h_counter.values[0];
  val_t T532;
  { T532 = T531 & T530;}
  val_t T533;
  { T533 = TERNARY(T532, 0x1L, T529);}
  val_t T534;
  T534 = SOC_dev_vga_dev_vga__h_counter.values[0]<0x60L;
  val_t T535;
  T535 = 0x0L<=SOC_dev_vga_dev_vga__h_counter.values[0];
  val_t T536;
  { T536 = T535 & T534;}
  val_t SOC_dev_vga_dev_vga__h_state;
  { SOC_dev_vga_dev_vga__h_state = TERNARY(T536, 0x0L, T533);}
  val_t T537;
  T537 = SOC_dev_vga_dev_vga__h_state == 0x2L;
  val_t T538;
  { T538 = TERNARY(T537, T521, 0x0L);}
  { SOC_dev_vga_dev_vga__io_ctrl_x.values[0] = T538;}
  val_t T539;
  { T539 = SOC_dev_vga_dev_vga__io_ctrl_x.values[0] >> 3;}
  T539 = T539 & 0x1fffffffL;
  val_t T540;
  { T540 = T539 | 0x0L << 29;}
  val_t T541;
  { T541 = SOC_dev_vga_dev_vga__v_counter.values[0]-0x1fL;}
  T541 = T541 & 0xffffffffL;
  val_t T542;
  T542 = SOC_dev_vga_dev_vga__v_counter.values[0]<0x209L;
  val_t T543;
  T543 = 0x1ffL<=SOC_dev_vga_dev_vga__v_counter.values[0];
  val_t T544;
  { T544 = T543 & T542;}
  val_t T545;
  { T545 = TERNARY(T544, 0x3L, 0x0L);}
  val_t T546;
  T546 = SOC_dev_vga_dev_vga__v_counter.values[0]<0x1ffL;
  val_t T547;
  T547 = 0x1fL<=SOC_dev_vga_dev_vga__v_counter.values[0];
  val_t T548;
  { T548 = T547 & T546;}
  val_t T549;
  { T549 = TERNARY(T548, 0x2L, T545);}
  val_t T550;
  T550 = SOC_dev_vga_dev_vga__v_counter.values[0]<0x1fL;
  val_t T551;
  T551 = 0x2L<=SOC_dev_vga_dev_vga__v_counter.values[0];
  val_t T552;
  { T552 = T551 & T550;}
  val_t T553;
  { T553 = TERNARY(T552, 0x1L, T549);}
  val_t T554;
  T554 = SOC_dev_vga_dev_vga__v_counter.values[0]<0x2L;
  val_t T555;
  T555 = 0x0L<=SOC_dev_vga_dev_vga__v_counter.values[0];
  val_t T556;
  { T556 = T555 & T554;}
  val_t SOC_dev_vga_dev_vga__v_state;
  { SOC_dev_vga_dev_vga__v_state = TERNARY(T556, 0x0L, T553);}
  val_t T557;
  T557 = SOC_dev_vga_dev_vga__v_state == 0x2L;
  val_t T558;
  { T558 = TERNARY(T557, T541, 0x0L);}
  { SOC_dev_vga_dev_vga__io_ctrl_y.values[0] = T558;}
  val_t T559;
  { T559 = SOC_dev_vga_dev_vga__io_ctrl_y.values[0] >> 4;}
  T559 = T559 & 0xfffffffL;
  val_t T560;
  T560 = T559 * 0x50L;
  val_t T561;
  { T561 = T560+T540;}
  T561 = T561 & 0x7ffffffffL;
  val_t T562;
  { T562 = T561;}
  T562 = T562 & 0xfffL;
  val_t SOC_dev_vga_dev__data;
  { SOC_dev_vga_dev__data = SOC_dev_vga_dev__vmem.get(T562, 0);}
  val_t SOC_dev_vga_dev__color;
  { SOC_dev_vga_dev__color = SOC_dev_vga_dev__data >> 8;}
  SOC_dev_vga_dev__color = SOC_dev_vga_dev__color & 0xffL;
  val_t T563;
  T563 = (SOC_dev_vga_dev__color >> 0) & 1;
  val_t T564;
  T564 = (SOC_dev_vga_dev__color >> 0) & 1;
  val_t T565;
  T565 = (SOC_dev_vga_dev__color >> 1) & 1;
  val_t T566;
  T566 = (SOC_dev_vga_dev__color >> 1) & 1;
  val_t T567;
  T567 = (SOC_dev_vga_dev__color >> 1) & 1;
  val_t T568;
  T568 = (SOC_dev_vga_dev__color >> 2) & 1;
  val_t T569;
  T569 = (SOC_dev_vga_dev__color >> 2) & 1;
  val_t T570;
  T570 = (SOC_dev_vga_dev__color >> 2) & 1;
  val_t T571;
  { T571 = T569 | T570 << 1;}
  val_t T572;
  { T572 = T568 | T571 << 1;}
  val_t T573;
  { T573 = T567 | T572 << 1;}
  val_t T574;
  { T574 = T566 | T573 << 1;}
  val_t T575;
  { T575 = T565 | T574 << 1;}
  val_t T576;
  { T576 = T564 | T575 << 1;}
  val_t SOC_dev_vga_dev__front_color;
  { SOC_dev_vga_dev__front_color = T563 | T576 << 1;}
  val_t T577;
  { T577 = SOC_dev_vga_dev_vga__io_ctrl_x.values[0];}
  T577 = T577 & 0x7L;
  val_t T578;
  { T578 = T577-T577;}
  T578 = T578 & 0x7L;
  val_t T579;
  { T579 = T578+0x1L;}
  T579 = T579 & 0x7L;
  val_t T580;
  T580 = 0x1L << T579;
  T580 = T580 & 0x1L;
  val_t T581;
  { T581 = T580-0x1L;}
  T581 = T581 & 0x1L;
  val_t T582;
  { T582 = SOC_dev_vga_dev_vga__io_ctrl_y.values[0];}
  T582 = T582 & 0xfL;
  val_t T583;
  { T583 = T582 | 0x0L << 4;}
  val_t SOC_dev_vga_dev__char;
  { SOC_dev_vga_dev__char = SOC_dev_vga_dev__data;}
  SOC_dev_vga_dev__char = SOC_dev_vga_dev__char & 0xffL;
  val_t T584;
  T584 = SOC_dev_vga_dev__char * 0x10L;
  val_t T585;
  { T585 = T584+T583;}
  T585 = T585 & 0x1fffL;
  val_t T586;
  { T586 = T585;}
  T586 = T586 & 0xfffL;
  { SOC_dev_vga_dev_font__io_addr.values[0] = T586;}
  val_t T587;
  T587 = SOC_dev_vga_dev_font__io_addr.values[0] == 0xbL;
  val_t T588;
  { T588 = TERNARY(T587, 0xc6L, 0x0L);}
  val_t T589;
  T589 = SOC_dev_vga_dev_font__io_addr.values[0] == 0xaL;
  val_t T590;
  { T590 = TERNARY(T589, 0xc6L, T588);}
  val_t T591;
  T591 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x9L;
  val_t T592;
  { T592 = TERNARY(T591, 0xc6L, T590);}
  val_t T593;
  T593 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x8L;
  val_t T594;
  { T594 = TERNARY(T593, 0xc6L, T592);}
  val_t T595;
  T595 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x7L;
  val_t T596;
  { T596 = TERNARY(T595, 0xc6L, T594);}
  val_t T597;
  T597 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x6L;
  val_t T598;
  { T598 = TERNARY(T597, 0xfeL, T596);}
  val_t T599;
  T599 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x5L;
  val_t T600;
  { T600 = TERNARY(T599, 0xc6L, T598);}
  val_t T601;
  T601 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x4L;
  val_t T602;
  { T602 = TERNARY(T601, 0xc6L, T600);}
  val_t T603;
  T603 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x3L;
  val_t T604;
  { T604 = TERNARY(T603, 0xc6L, T602);}
  val_t T605;
  T605 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x2L;
  val_t T606;
  { T606 = TERNARY(T605, 0xc6L, T604);}
  val_t T607;
  T607 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x1L;
  val_t T608;
  { T608 = TERNARY(T607, 0x55L, T606);}
  val_t T609;
  T609 = SOC_dev_vga_dev_font__io_addr.values[0] == 0x0L;
  val_t T610;
  { T610 = TERNARY(T609, 0xaaL, T608);}
  { SOC_dev_vga_dev_font__io_data.values[0] = T610;}
  val_t T611;
  T611 = SOC_dev_vga_dev_font__io_data.values[0] >> T577;
  val_t T612;
  { T612 = T611 & T581;}
  val_t T613;
  T613 = T612 == 0x1L;
  val_t T614;
  { T614 = TERNARY(T613, SOC_dev_vga_dev__front_color, 0x0L);}
  val_t T615;
  T615 = (SOC_dev_vga_dev__color >> 4) & 1;
  val_t T616;
  T616 = (SOC_dev_vga_dev__color >> 4) & 1;
  val_t T617;
  T617 = (SOC_dev_vga_dev__color >> 5) & 1;
  val_t T618;
  T618 = (SOC_dev_vga_dev__color >> 5) & 1;
  val_t T619;
  T619 = (SOC_dev_vga_dev__color >> 5) & 1;
  val_t T620;
  T620 = (SOC_dev_vga_dev__color >> 6) & 1;
  val_t T621;
  T621 = (SOC_dev_vga_dev__color >> 6) & 1;
  val_t T622;
  T622 = (SOC_dev_vga_dev__color >> 6) & 1;
  val_t T623;
  { T623 = T621 | T622 << 1;}
  val_t T624;
  { T624 = T620 | T623 << 1;}
  val_t T625;
  { T625 = T619 | T624 << 1;}
  val_t T626;
  { T626 = T618 | T625 << 1;}
  val_t T627;
  { T627 = T617 | T626 << 1;}
  val_t T628;
  { T628 = T616 | T627 << 1;}
  val_t SOC_dev_vga_dev__back_color;
  { SOC_dev_vga_dev__back_color = T615 | T628 << 1;}
  val_t T629;
  { T629 = SOC_dev_vga_dev_vga__io_ctrl_x.values[0];}
  T629 = T629 & 0x7L;
  val_t T630;
  { T630 = T629-T629;}
  T630 = T630 & 0x7L;
  val_t T631;
  { T631 = T630+0x1L;}
  T631 = T631 & 0x7L;
  val_t T632;
  T632 = 0x1L << T631;
  T632 = T632 & 0x1L;
  val_t T633;
  { T633 = T632-0x1L;}
  T633 = T633 & 0x1L;
  val_t T634;
  T634 = SOC_dev_vga_dev_font__io_data.values[0] >> T629;
  val_t T635;
  { T635 = T634 & T633;}
  val_t T636;
  T636 = T635 == 0x0L;
  val_t T637;
  { T637 = TERNARY_1(T636, SOC_dev_vga_dev__back_color, T614);}
  { SOC_dev_vga_dev_vga__io_ctrl_color.values[0] = T637;}
  val_t T638;
  { T638 = SOC_dev_vga_dev_vga__io_ctrl_color.values[0] >> 5;}
  T638 = T638 & 0x7L;
  val_t T639;
  T639 = SOC_dev_vga_dev_vga__v_state == 0x2L;
  val_t T640;
  T640 = SOC_dev_vga_dev_vga__h_state == 0x2L;
  val_t SOC_dev_vga_dev_vga__output_en;
  { SOC_dev_vga_dev_vga__output_en = T640 & T639;}
  val_t T641;
  T641 = SOC_dev_vga_dev_vga__output_en == 0x1L;
  val_t T642;
  { T642 = TERNARY(T641, T638, 0x0L);}
  { SOC_dev_vga_dev_vga__io_vga_red.values[0] = T642;}
  { SOC_dev_vga_dev__io_vga_red.values[0] = SOC_dev_vga_dev_vga__io_vga_red.values[0];}
  { SOC_dev__io_devices_VGA_red.values[0] = SOC_dev_vga_dev__io_vga_red.values[0];}
  { SOC__io_devices_VGA_red.values[0] = SOC_dev__io_devices_VGA_red.values[0];}
  val_t T643;
  { T643 = SOC_dev_vga_dev_vga__io_ctrl_color.values[0] >> 2;}
  T643 = T643 & 0x7L;
  val_t T644;
  T644 = SOC_dev_vga_dev_vga__output_en == 0x1L;
  val_t T645;
  { T645 = TERNARY(T644, T643, 0x0L);}
  { SOC_dev_vga_dev_vga__io_vga_green.values[0] = T645;}
  { SOC_dev_vga_dev__io_vga_green.values[0] = SOC_dev_vga_dev_vga__io_vga_green.values[0];}
  { SOC_dev__io_devices_VGA_green.values[0] = SOC_dev_vga_dev__io_vga_green.values[0];}
  { SOC__io_devices_VGA_green.values[0] = SOC_dev__io_devices_VGA_green.values[0];}
  val_t T646;
  { T646 = SOC_dev_vga_dev_vga__io_ctrl_color.values[0];}
  T646 = T646 & 0x3L;
  val_t T647;
  T647 = SOC_dev_vga_dev_vga__output_en == 0x1L;
  val_t T648;
  { T648 = TERNARY(T647, T646, 0x0L);}
  { SOC_dev_vga_dev_vga__io_vga_blue.values[0] = T648;}
  { SOC_dev_vga_dev__io_vga_blue.values[0] = SOC_dev_vga_dev_vga__io_vga_blue.values[0];}
  { SOC_dev__io_devices_VGA_blue.values[0] = SOC_dev_vga_dev__io_vga_blue.values[0];}
  { SOC__io_devices_VGA_blue.values[0] = SOC_dev__io_devices_VGA_blue.values[0];}
  val_t T649;
  T649 = SOC_dev_vga_dev_vga__h_state == 0x3L;
  val_t T650;
  T650 = SOC_dev_vga_dev_vga__h_state == 0x2L;
  val_t T651;
  { T651 = TERNARY(T650, 0x1L, T649);}
  val_t T652;
  T652 = SOC_dev_vga_dev_vga__h_state == 0x1L;
  val_t T653;
  { T653 = TERNARY(T652, 0x1L, T651);}
  val_t T654;
  T654 = SOC_dev_vga_dev_vga__h_state == 0x0L;
  val_t T655;
  { T655 = TERNARY(T654, 0x0L, T653);}
  { SOC_dev_vga_dev_vga__io_vga_hsync.values[0] = T655;}
  { SOC_dev_vga_dev__io_vga_hsync.values[0] = SOC_dev_vga_dev_vga__io_vga_hsync.values[0];}
  { SOC_dev__io_devices_VGA_hsync.values[0] = SOC_dev_vga_dev__io_vga_hsync.values[0];}
  { SOC__io_devices_VGA_hsync.values[0] = SOC_dev__io_devices_VGA_hsync.values[0];}
  val_t T656;
  T656 = SOC_dev_vga_dev_vga__v_state == 0x3L;
  val_t T657;
  T657 = SOC_dev_vga_dev_vga__v_state == 0x2L;
  val_t T658;
  { T658 = TERNARY(T657, 0x1L, T656);}
  val_t T659;
  T659 = SOC_dev_vga_dev_vga__v_state == 0x1L;
  val_t T660;
  { T660 = TERNARY(T659, 0x1L, T658);}
  val_t T661;
  T661 = SOC_dev_vga_dev_vga__v_state == 0x0L;
  val_t T662;
  { T662 = TERNARY(T661, 0x0L, T660);}
  { SOC_dev_vga_dev_vga__io_vga_vsync.values[0] = T662;}
  { SOC_dev_vga_dev__io_vga_vsync.values[0] = SOC_dev_vga_dev_vga__io_vga_vsync.values[0];}
  { SOC_dev__io_devices_VGA_vsync.values[0] = SOC_dev_vga_dev__io_vga_vsync.values[0];}
  { SOC__io_devices_VGA_vsync.values[0] = SOC_dev__io_devices_VGA_vsync.values[0];}
  val_t T663;
  { T663 = SOC_dev_ram_dev__io_bus_addr.values[0] >> 2;}
  T663 = T663 & 0x3ffL;
  { SOC_dev_ram_dev__io_ram_addra.values[0] = T663;}
  { SOC_dev__io_devices_RAM_addra.values[0] = SOC_dev_ram_dev__io_ram_addra.values[0];}
  { SOC__io_devices_RAM_addra.values[0] = SOC_dev__io_devices_RAM_addra.values[0];}
  { SOC_dev_bus__io_ram_slave_dat2.values[0] = SOC_dev_bus__io_from_cpu_dat2.values[0];}
  { SOC_dev_ram_dev__io_bus_dat2.values[0] = SOC_dev_bus__io_ram_slave_dat2.values[0];}
  { SOC_dev_ram_dev__io_ram_dina.values[0] = SOC_dev_ram_dev__io_bus_dat2.values[0];}
  { SOC_dev__io_devices_RAM_dina.values[0] = SOC_dev_ram_dev__io_ram_dina.values[0];}
  { SOC__io_devices_RAM_dina.values[0] = SOC_dev__io_devices_RAM_dina.values[0];}
  val_t T664;
  { T664 = SOC_dev_bus__ram_op & SOC_dev_bus__io_from_cpu_we.values[0];}
  { SOC_dev_bus__io_ram_slave_we.values[0] = T664;}
  { SOC_dev_ram_dev__io_bus_we.values[0] = SOC_dev_bus__io_ram_slave_we.values[0];}
  val_t T665;
  { T665 = SOC_dev_bus__ram_op & SOC_dev_bus__io_from_cpu_sel.values[0];}
  { SOC_dev_bus__io_ram_slave_sel.values[0] = T665;}
  { SOC_dev_ram_dev__io_bus_sel.values[0] = SOC_dev_bus__io_ram_slave_sel.values[0];}
  val_t T666;
  { T666 = SOC_dev_ram_dev__io_bus_sel.values[0] & SOC_dev_ram_dev__io_bus_we.values[0];}
  { SOC_dev_ram_dev__io_ram_we.values[0] = T666;}
  { SOC_dev__io_devices_RAM_we.values[0] = SOC_dev_ram_dev__io_ram_we.values[0];}
  { SOC__io_devices_RAM_we.values[0] = SOC_dev__io_devices_RAM_we.values[0];}
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
  val_t T667;
  { T667 = SOC_cpu_cpath__reset.values[0] ^ 0x1L;}
  { T668.values[0] = SOC_cpu_cpath__io_bus_ack.values[0] & T667;}
  { T669.values[0] = SOC_cpu_cpath__state.values[0];}
}


void SOC_t::clock_hi ( dat_t<1> reset ) {
  dat_t<2> SOC_dev_vga_dev_vga__p_counter__shadow = T4;
  dat_t<32> SOC_dev_vga_dev_vga__h_counter__shadow = T13;
  dat_t<32> SOC_dev_vga_dev_vga__v_counter__shadow = T21;
  { if (T203.values[0]) SOC_dev_vga_dev__vmem.put(T204.values[0], 0, T24.values[0]);}
  dat_t<32> SOC_dev_seven_seg__data_out__shadow = T221;
  dat_t<32> SOC_dev_seven_seg__disp_data__shadow = T223;
  dat_t<32> SOC_dev_led__data_out__shadow = T241;
  dat_t<8> SOC_dev_led__led_data__shadow = T245;
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1fL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1eL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1dL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1cL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1bL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1aL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x19L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x18L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x17L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x16L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x15L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x14L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x13L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x12L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x11L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x10L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xfL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xeL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xdL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xcL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xbL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0xaL, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x9L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x8L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x7L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x6L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x5L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x4L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x3L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x2L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x1L, 0, 0x0L);}
  { if (SOC_cpu_dpath_regfile__reset.values[0]) SOC_cpu_dpath_regfile__rf.put(0x0L, 0, 0x0L);}
  { if (T384.values[0]) SOC_cpu_dpath_regfile__rf.put(SOC_cpu_dpath_regfile__io_wtaddr.values[0], 0, SOC_cpu_dpath_regfile__io_wtdata.values[0]);}
  dat_t<32> SOC_cpu_dpath__inst_reg__shadow = T386;
  dat_t<32> SOC_cpu_dpath__pc__shadow = T445;
  dat_t<32> SOC_cpu_cpath__state__shadow = T520;
  SOC_dev_vga_dev_vga__p_counter = T4;
  SOC_dev_vga_dev_vga__h_counter = T13;
  SOC_dev_vga_dev_vga__v_counter = T21;
  SOC_dev_seven_seg__data_out = T221;
  SOC_dev_seven_seg__disp_data = T223;
  SOC_dev_led__data_out = T241;
  SOC_dev_led__led_data = T245;
  SOC_cpu_dpath__inst_reg = T386;
  SOC_cpu_dpath__pc = T445;
  SOC_cpu_cpath__state = T520;
}


void SOC_api_t::init_mapping_table (  ) {
  dat_table.clear();
  mem_table.clear();
  SOC_t* mod_typed = dynamic_cast<SOC_t*>(module);
  assert(mod_typed);
  dat_table["SOC.dev.vga_dev.vga.p_counter"] = new dat_api<2>(&mod_typed->SOC_dev_vga_dev_vga__p_counter, "SOC.dev.vga_dev.vga.p_counter", "");
  dat_table["SOC.dev.vga_dev.vga.h_counter"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev_vga__h_counter, "SOC.dev.vga_dev.vga.h_counter", "");
  dat_table["SOC.dev.vga_dev.vga.v_counter"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev_vga__v_counter, "SOC.dev.vga_dev.vga.v_counter", "");
  dat_table["SOC.cpu.dpath.regfile.io_addrb"] = new dat_api<5>(&mod_typed->SOC_cpu_dpath_regfile__io_addrb, "SOC.cpu.dpath.regfile.io_addrb", "");
  dat_table["SOC.cpu.dpath.regfile.io_doutb"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath_regfile__io_doutb, "SOC.cpu.dpath.regfile.io_doutb", "");
  dat_table["SOC.cpu.dpath.io_data_out"] = new dat_api<32>(&mod_typed->SOC_cpu_dpath__io_data_out, "SOC.cpu.dpath.io_data_out", "");
  dat_table["SOC.cpu.cpath.io_ctrl_data_out"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_ctrl_data_out, "SOC.cpu.cpath.io_ctrl_data_out", "");
  dat_table["SOC.cpu.cpath.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu_cpath__io_bus_dat2, "SOC.cpu.cpath.io_bus_dat2", "");
  dat_table["SOC.cpu.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_cpu__io_bus_dat2, "SOC.cpu.io_bus_dat2", "");
  dat_table["SOC.dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev__io_bus_dat2, "SOC.dev.io_bus_dat2", "");
  dat_table["SOC.dev.bus.io_from_cpu_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_from_cpu_dat2, "SOC.dev.bus.io_from_cpu_dat2", "");
  dat_table["SOC.dev.bus.io_slaves_5_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_5_dat2, "SOC.dev.bus.io_slaves_5_dat2", "");
  dat_table["SOC.dev.vga_dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev__io_bus_dat2, "SOC.dev.vga_dev.io_bus_dat2", "");
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
  dat_table["SOC.dev.bus.io_slaves_5_addr"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_5_addr, "SOC.dev.bus.io_slaves_5_addr", "");
  dat_table["SOC.dev.vga_dev.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev__io_bus_addr, "SOC.dev.vga_dev.io_bus_addr", "");
  dat_table["SOC.cpu.cpath.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_bus_we, "SOC.cpu.cpath.io_bus_we", "");
  dat_table["SOC.cpu.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_cpu__io_bus_we, "SOC.cpu.io_bus_we", "");
  dat_table["SOC.dev.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev__io_bus_we, "SOC.dev.io_bus_we", "");
  dat_table["SOC.dev.bus.io_from_cpu_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_from_cpu_we, "SOC.dev.bus.io_from_cpu_we", "");
  dat_table["SOC.dev.bus.io_slaves_5_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_5_we, "SOC.dev.bus.io_slaves_5_we", "");
  dat_table["SOC.dev.vga_dev.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev__io_bus_we, "SOC.dev.vga_dev.io_bus_we", "");
  dat_table["SOC.cpu.cpath.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_cpu_cpath__io_bus_sel, "SOC.cpu.cpath.io_bus_sel", "");
  dat_table["SOC.cpu.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_cpu__io_bus_sel, "SOC.cpu.io_bus_sel", "");
  dat_table["SOC.dev.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev__io_bus_sel, "SOC.dev.io_bus_sel", "");
  dat_table["SOC.dev.bus.io_from_cpu_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_from_cpu_sel, "SOC.dev.bus.io_from_cpu_sel", "");
  dat_table["SOC.dev.bus.io_slaves_5_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_5_sel, "SOC.dev.bus.io_slaves_5_sel", "");
  dat_table["SOC.dev.vga_dev.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev__io_bus_sel, "SOC.dev.vga_dev.io_bus_sel", "");
  mem_table["SOC.dev.vga_dev.vmem"] = new mem_api<16, 2400>(&mod_typed->SOC_dev_vga_dev__vmem, "SOC.dev.vga_dev.vmem", "");
  dat_table["SOC.dev.bus.io_slaves_4_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_4_dat2, "SOC.dev.bus.io_slaves_4_dat2", "");
  dat_table["SOC.dev.seven_seg.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__io_bus_dat2, "SOC.dev.seven_seg.io_bus_dat2", "");
  dat_table["SOC.dev.bus.io_slaves_4_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_4_we, "SOC.dev.bus.io_slaves_4_we", "");
  dat_table["SOC.dev.seven_seg.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_seven_seg__io_bus_we, "SOC.dev.seven_seg.io_bus_we", "");
  dat_table["SOC.dev.bus.io_slaves_4_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_4_sel, "SOC.dev.bus.io_slaves_4_sel", "");
  dat_table["SOC.dev.seven_seg.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_seven_seg__io_bus_sel, "SOC.dev.seven_seg.io_bus_sel", "");
  dat_table["SOC.dev.seven_seg.data_out"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__data_out, "SOC.dev.seven_seg.data_out", "");
  dat_table["SOC.dev.seven_seg.disp_data"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__disp_data, "SOC.dev.seven_seg.disp_data", "");
  dat_table["SOC.dev.bus.io_slaves_2_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_2_dat2, "SOC.dev.bus.io_slaves_2_dat2", "");
  dat_table["SOC.dev.led.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_led__io_bus_dat2, "SOC.dev.led.io_bus_dat2", "");
  dat_table["SOC.dev.bus.io_slaves_2_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_2_we, "SOC.dev.bus.io_slaves_2_we", "");
  dat_table["SOC.dev.led.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_led__io_bus_we, "SOC.dev.led.io_bus_we", "");
  dat_table["SOC.dev.bus.io_slaves_2_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_2_sel, "SOC.dev.bus.io_slaves_2_sel", "");
  dat_table["SOC.dev.led.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_led__io_bus_sel, "SOC.dev.led.io_bus_sel", "");
  dat_table["SOC.dev.led.data_out"] = new dat_api<32>(&mod_typed->SOC_dev_led__data_out, "SOC.dev.led.data_out", "");
  dat_table["SOC.dev.led.led_data"] = new dat_api<8>(&mod_typed->SOC_dev_led__led_data, "SOC.dev.led.led_data", "");
  dat_table["SOC.cpu.cpath.io_ctrl_reg_we_src"] = new dat_api<2>(&mod_typed->SOC_cpu_cpath__io_ctrl_reg_we_src, "SOC.cpu.cpath.io_ctrl_reg_we_src", "");
  dat_table["SOC.cpu.dpath.io_reg_we_src"] = new dat_api<2>(&mod_typed->SOC_cpu_dpath__io_reg_we_src, "SOC.cpu.dpath.io_reg_we_src", "");
  dat_table["SOC.io_devices_RAM_douta"] = new dat_api<32>(&mod_typed->SOC__io_devices_RAM_douta, "SOC.io_devices_RAM_douta", "");
  dat_table["SOC.dev.io_devices_RAM_douta"] = new dat_api<32>(&mod_typed->SOC_dev__io_devices_RAM_douta, "SOC.dev.io_devices_RAM_douta", "");
  dat_table["SOC.dev.ram_dev.io_ram_douta"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_ram_douta, "SOC.dev.ram_dev.io_ram_douta", "");
  dat_table["SOC.dev.bus.io_ram_slave_addr"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_ram_slave_addr, "SOC.dev.bus.io_ram_slave_addr", "");
  dat_table["SOC.dev.ram_dev.io_bus_addr"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_bus_addr, "SOC.dev.ram_dev.io_bus_addr", "");
  dat_table["SOC.dev.ram_dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_bus_dat4, "SOC.dev.ram_dev.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_ram_slave_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_ram_slave_dat4, "SOC.dev.bus.io_ram_slave_dat4", "");
  dat_table["SOC.dev.WB_Empty_Dev_1.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_dat4, "SOC.dev.WB_Empty_Dev_1.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_7_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_7_dat4, "SOC.dev.bus.io_slaves_7_dat4", "");
  dat_table["SOC.dev.WB_Empty_Dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_WB_Empty_Dev__io_bus_dat4, "SOC.dev.WB_Empty_Dev.io_bus_dat4", "");
  dat_table["SOC.dev.bus.io_slaves_6_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_slaves_6_dat4, "SOC.dev.bus.io_slaves_6_dat4", "");
  dat_table["SOC.dev.vga_dev.io_bus_dat4"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev__io_bus_dat4, "SOC.dev.vga_dev.io_bus_dat4", "");
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
  dat_table["SOC.dev.WB_Empty_Dev_1.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_WB_Empty_Dev_1__io_bus_ack, "SOC.dev.WB_Empty_Dev_1.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_7_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_7_ack, "SOC.dev.bus.io_slaves_7_ack", "");
  dat_table["SOC.dev.WB_Empty_Dev.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_WB_Empty_Dev__io_bus_ack, "SOC.dev.WB_Empty_Dev.io_bus_ack", "");
  dat_table["SOC.dev.bus.io_slaves_6_ack"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_slaves_6_ack, "SOC.dev.bus.io_slaves_6_ack", "");
  dat_table["SOC.dev.vga_dev.io_bus_ack"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev__io_bus_ack, "SOC.dev.vga_dev.io_bus_ack", "");
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
  dat_table["SOC.dev.seven_seg.io_DISP_NUM"] = new dat_api<32>(&mod_typed->SOC_dev_seven_seg__io_DISP_NUM, "SOC.dev.seven_seg.io_DISP_NUM", "");
  dat_table["SOC.dev.io_devices_DISP_NUM"] = new dat_api<32>(&mod_typed->SOC_dev__io_devices_DISP_NUM, "SOC.dev.io_devices_DISP_NUM", "");
  dat_table["SOC.io_devices_DISP_NUM"] = new dat_api<32>(&mod_typed->SOC__io_devices_DISP_NUM, "SOC.io_devices_DISP_NUM", "");
  dat_table["SOC.dev.vga_dev.vga.io_ctrl_x"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev_vga__io_ctrl_x, "SOC.dev.vga_dev.vga.io_ctrl_x", "");
  dat_table["SOC.dev.vga_dev.vga.io_ctrl_y"] = new dat_api<32>(&mod_typed->SOC_dev_vga_dev_vga__io_ctrl_y, "SOC.dev.vga_dev.vga.io_ctrl_y", "");
  dat_table["SOC.dev.vga_dev.font.io_addr"] = new dat_api<12>(&mod_typed->SOC_dev_vga_dev_font__io_addr, "SOC.dev.vga_dev.font.io_addr", "");
  dat_table["SOC.dev.vga_dev.font.io_data"] = new dat_api<8>(&mod_typed->SOC_dev_vga_dev_font__io_data, "SOC.dev.vga_dev.font.io_data", "");
  dat_table["SOC.dev.vga_dev.vga.io_ctrl_color"] = new dat_api<8>(&mod_typed->SOC_dev_vga_dev_vga__io_ctrl_color, "SOC.dev.vga_dev.vga.io_ctrl_color", "");
  dat_table["SOC.dev.vga_dev.vga.io_vga_red"] = new dat_api<3>(&mod_typed->SOC_dev_vga_dev_vga__io_vga_red, "SOC.dev.vga_dev.vga.io_vga_red", "");
  dat_table["SOC.dev.vga_dev.io_vga_red"] = new dat_api<3>(&mod_typed->SOC_dev_vga_dev__io_vga_red, "SOC.dev.vga_dev.io_vga_red", "");
  dat_table["SOC.dev.io_devices_VGA_red"] = new dat_api<3>(&mod_typed->SOC_dev__io_devices_VGA_red, "SOC.dev.io_devices_VGA_red", "");
  dat_table["SOC.io_devices_VGA_red"] = new dat_api<3>(&mod_typed->SOC__io_devices_VGA_red, "SOC.io_devices_VGA_red", "");
  dat_table["SOC.dev.vga_dev.vga.io_vga_green"] = new dat_api<3>(&mod_typed->SOC_dev_vga_dev_vga__io_vga_green, "SOC.dev.vga_dev.vga.io_vga_green", "");
  dat_table["SOC.dev.vga_dev.io_vga_green"] = new dat_api<3>(&mod_typed->SOC_dev_vga_dev__io_vga_green, "SOC.dev.vga_dev.io_vga_green", "");
  dat_table["SOC.dev.io_devices_VGA_green"] = new dat_api<3>(&mod_typed->SOC_dev__io_devices_VGA_green, "SOC.dev.io_devices_VGA_green", "");
  dat_table["SOC.io_devices_VGA_green"] = new dat_api<3>(&mod_typed->SOC__io_devices_VGA_green, "SOC.io_devices_VGA_green", "");
  dat_table["SOC.dev.vga_dev.vga.io_vga_blue"] = new dat_api<2>(&mod_typed->SOC_dev_vga_dev_vga__io_vga_blue, "SOC.dev.vga_dev.vga.io_vga_blue", "");
  dat_table["SOC.dev.vga_dev.io_vga_blue"] = new dat_api<2>(&mod_typed->SOC_dev_vga_dev__io_vga_blue, "SOC.dev.vga_dev.io_vga_blue", "");
  dat_table["SOC.dev.io_devices_VGA_blue"] = new dat_api<2>(&mod_typed->SOC_dev__io_devices_VGA_blue, "SOC.dev.io_devices_VGA_blue", "");
  dat_table["SOC.io_devices_VGA_blue"] = new dat_api<2>(&mod_typed->SOC__io_devices_VGA_blue, "SOC.io_devices_VGA_blue", "");
  dat_table["SOC.dev.vga_dev.vga.io_vga_hsync"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev_vga__io_vga_hsync, "SOC.dev.vga_dev.vga.io_vga_hsync", "");
  dat_table["SOC.dev.vga_dev.io_vga_hsync"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev__io_vga_hsync, "SOC.dev.vga_dev.io_vga_hsync", "");
  dat_table["SOC.dev.io_devices_VGA_hsync"] = new dat_api<1>(&mod_typed->SOC_dev__io_devices_VGA_hsync, "SOC.dev.io_devices_VGA_hsync", "");
  dat_table["SOC.io_devices_VGA_hsync"] = new dat_api<1>(&mod_typed->SOC__io_devices_VGA_hsync, "SOC.io_devices_VGA_hsync", "");
  dat_table["SOC.dev.vga_dev.vga.io_vga_vsync"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev_vga__io_vga_vsync, "SOC.dev.vga_dev.vga.io_vga_vsync", "");
  dat_table["SOC.dev.vga_dev.io_vga_vsync"] = new dat_api<1>(&mod_typed->SOC_dev_vga_dev__io_vga_vsync, "SOC.dev.vga_dev.io_vga_vsync", "");
  dat_table["SOC.dev.io_devices_VGA_vsync"] = new dat_api<1>(&mod_typed->SOC_dev__io_devices_VGA_vsync, "SOC.dev.io_devices_VGA_vsync", "");
  dat_table["SOC.io_devices_VGA_vsync"] = new dat_api<1>(&mod_typed->SOC__io_devices_VGA_vsync, "SOC.io_devices_VGA_vsync", "");
  dat_table["SOC.dev.ram_dev.io_ram_addra"] = new dat_api<10>(&mod_typed->SOC_dev_ram_dev__io_ram_addra, "SOC.dev.ram_dev.io_ram_addra", "");
  dat_table["SOC.dev.io_devices_RAM_addra"] = new dat_api<10>(&mod_typed->SOC_dev__io_devices_RAM_addra, "SOC.dev.io_devices_RAM_addra", "");
  dat_table["SOC.io_devices_RAM_addra"] = new dat_api<10>(&mod_typed->SOC__io_devices_RAM_addra, "SOC.io_devices_RAM_addra", "");
  dat_table["SOC.dev.bus.io_ram_slave_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_bus__io_ram_slave_dat2, "SOC.dev.bus.io_ram_slave_dat2", "");
  dat_table["SOC.dev.ram_dev.io_bus_dat2"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_bus_dat2, "SOC.dev.ram_dev.io_bus_dat2", "");
  dat_table["SOC.dev.ram_dev.io_ram_dina"] = new dat_api<32>(&mod_typed->SOC_dev_ram_dev__io_ram_dina, "SOC.dev.ram_dev.io_ram_dina", "");
  dat_table["SOC.dev.io_devices_RAM_dina"] = new dat_api<32>(&mod_typed->SOC_dev__io_devices_RAM_dina, "SOC.dev.io_devices_RAM_dina", "");
  dat_table["SOC.io_devices_RAM_dina"] = new dat_api<32>(&mod_typed->SOC__io_devices_RAM_dina, "SOC.io_devices_RAM_dina", "");
  dat_table["SOC.dev.bus.io_ram_slave_we"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_ram_slave_we, "SOC.dev.bus.io_ram_slave_we", "");
  dat_table["SOC.dev.ram_dev.io_bus_we"] = new dat_api<1>(&mod_typed->SOC_dev_ram_dev__io_bus_we, "SOC.dev.ram_dev.io_bus_we", "");
  dat_table["SOC.dev.bus.io_ram_slave_sel"] = new dat_api<1>(&mod_typed->SOC_dev_bus__io_ram_slave_sel, "SOC.dev.bus.io_ram_slave_sel", "");
  dat_table["SOC.dev.ram_dev.io_bus_sel"] = new dat_api<1>(&mod_typed->SOC_dev_ram_dev__io_bus_sel, "SOC.dev.ram_dev.io_bus_sel", "");
  dat_table["SOC.dev.ram_dev.io_ram_we"] = new dat_api<1>(&mod_typed->SOC_dev_ram_dev__io_ram_we, "SOC.dev.ram_dev.io_ram_we", "");
  dat_table["SOC.dev.io_devices_RAM_we"] = new dat_api<1>(&mod_typed->SOC_dev__io_devices_RAM_we, "SOC.dev.io_devices_RAM_we", "");
  dat_table["SOC.io_devices_RAM_we"] = new dat_api<1>(&mod_typed->SOC__io_devices_RAM_we, "SOC.io_devices_RAM_we", "");
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
