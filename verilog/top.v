`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    00:06:57 06/30/2015 
// Design Name: 
// Module Name:    top 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module top(
    input clk,
    input [7:0] SW,
    input [4:0] BTN,
    input k_clk,
    input k_data,
    output [7:0] LED,
    output [7:0] SEG,
    output [3:0] AN,
    output [2:0] vgaRed,
    output [2:0] vgaGreen,
    output [1:0] vgaBlue,
    output Hsync,
    output Vsync
    );

  wire [31:0] disp_num;
  
  reg reset = 1;
  always @(posedge clk) reset <= 0;

  wire ram_we;
  wire [9:0] ram_addr;
  wire [31:0] ram_dina;
  wire [31:0] ram_douta;

  SOC soc(
    .clk(clk),
    .reset(reset),
    .io_devices_SW(SW),
    .io_devices_LED(LED),
    .io_devices_BTN(BTN),
    .io_devices_DISP_NUM(disp_num),
    .io_devices_VGA_red(vgaRed),
    .io_devices_VGA_green(vgaGreen),
    .io_devices_VGA_blue(vgaBlue),
    .io_devices_VGA_hsync(Hsync),
    .io_devices_VGA_vsync(Vsync),
    .io_devices_RAM_we(ram_we),
    .io_devices_RAM_addra(ram_addr),
    .io_devices_RAM_dina(ram_dina),
    .io_devices_RAM_douta(ram_douta),
    .io_devices_KEYBOARD_kb_clk(k_clk),
    .io_devices_KEYBOARD_kb_data(k_data)
  );

  Seven_Segment_Wrapper seven_seg(
    .clk(clk),
    .high_degree(SW[0]),
    .sel(SW[7:5]),
    .disp_num(disp_num),
    .test1(32'b0),
    .test2(32'b0),
    .test3(32'b0),
    .test4(32'b0),
    .test5(32'b0),
    .test6(32'b0),
    .test7(32'b0),
    .SEGMENT(SEG),
    .AN(AN)
  );

  Ram_Wrap ram(
    .io_clk(clk),
    .io_reset(reset),
    .io_we(ram_we),
    .io_addra(ram_addr),
    .io_dina(ram_dina),
    .io_douta(ram_douta)
  );

endmodule
