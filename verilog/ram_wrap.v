`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:55:27 06/29/2015 
// Design Name: 
// Module Name:    ram_wrap 
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
module Ram_Wrap(
    input io_clk,
    input io_reset,
    input io_we,
    input [9:0] io_addra,
    input [31:0] io_dina,
    output [31:0] io_douta
    );

  Ram ram(
    .clka(~io_clk),
    .addra(io_addra),
    .dina(io_dina),
    .wea(io_we),
    .douta(io_douta)
  );

endmodule
