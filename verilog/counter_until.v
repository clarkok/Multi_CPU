`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:52:33 06/25/2015 
// Design Name: 
// Module Name:    counter_until 
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
module Counter_Until(
    input clk,
    input rst,
    input [31:0] until,
    output reg [31:0] counter
    );

  initial counter = 0;

  always @ (posedge clk or posedge rst) begin
    if (rst)
      counter <= 0;
    else begin
      counter <= (counter == until) ? 0 : counter + 1;
    end
  end

endmodule
