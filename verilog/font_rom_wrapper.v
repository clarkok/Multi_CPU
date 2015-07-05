`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:55:58 07/04/2015 
// Design Name: 
// Module Name:    font_rom_wrapper 
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
module Font_Rom_Wrapper(
    input [11:0] io_addr,
    output [7:0] io_data
    );

  font_rom font(
    .a(io_addr),
    .spo(io_data)
  );

endmodule
