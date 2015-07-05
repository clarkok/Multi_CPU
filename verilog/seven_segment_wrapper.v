`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    16:53:02 06/30/2015 
// Design Name: 
// Module Name:    seven_segment_wrapper 
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
module Seven_Segment_Wrapper(
    input clk,
    input high_degree,
    input [2:0] sel,
    input [31:0] disp_num,
    input [31:0] test1,
    input [31:0] test2,
    input [31:0] test3,
    input [31:0] test4,
    input [31:0] test5,
    input [31:0] test6,
    input [31:0] test7,
    output [7:0] SEGMENT,
    output [3:0] AN
    );

  reg [31:0] disp_for_dev = 0;
  always @* begin
    case (sel)
      0 : disp_for_dev <= disp_num;
      1 : disp_for_dev <= test1;
      2 : disp_for_dev <= test2;
      3 : disp_for_dev <= test3;
      4 : disp_for_dev <= test4;
      5 : disp_for_dev <= test5;
      6 : disp_for_dev <= test6;
      7 : disp_for_dev <= test7;
    endcase
  end

  reg [31:0] counter;
  always @(posedge clk) begin
    counter <= counter + 1;
  end

  Seven_Seg_Dev seven_seg(
    .flash_clk(counter[25]),
    .disp_num(disp_for_dev),
    .graph(1'b0),
    .high_degree(high_degree),
    .scanning(counter[20:19]),
    .pointing(2'b0),
    .blinking(2'b0),
    .AN(AN),
    .SEGMENT(SEGMENT)
  );
endmodule
