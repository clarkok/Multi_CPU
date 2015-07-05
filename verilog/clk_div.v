`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    15:27:50 06/05/2015 
// Design Name: 
// Module Name:    clk_div 
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

`define FREQUENCY_COUNT 100_000_000

module Clk_Div(
    input clk,
    input rst,
    input fast,
    output reg [31:0] clkdiv,
    output Clk_CPU
    );

  wire [31:0] counter;
  Counter_Until Counter(
    ~clk,
    rst,
    `FREQUENCY_COUNT,
    counter
  );

  initial clkdiv = 0;

  wire slow_clk = (counter == `FREQUENCY_COUNT) & clk;
  assign Clk_CPU = fast ? clk : slow_clk;

  always @ (posedge clk or posedge rst) begin
    clkdiv <= rst ? 0 : clkdiv + 1;
  end

endmodule
