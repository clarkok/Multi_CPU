`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:28:59 06/05/2015 
// Design Name: 
// Module Name:    seven_seg_dev 
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
module Seven_Seg_Dev(
    input flash_clk,
    input [31:0] disp_num,
    input graph,
    input high_degree,
    input [1:0] scanning,
    input [3:0] pointing,
    input [3:0] blinking,
    output reg [3:0] AN,
    output reg [7:0] SEGMENT
    );

  reg [3:0] disp_part;
  reg disp_point;
  reg disp_blink;

  initial begin
    SEGMENT = 0;
    AN = 0;
  end

  always @ (scanning) begin
    case (scanning)
      0 : AN <= 4'b1110;
      1 : AN <= 4'b1101;
      2 : AN <= 4'b1011;
      3 : AN <= 4'b0111;
    endcase
  end

  always @* begin
    if (graph) begin
    end
    else begin
      case (scanning)
        0 :
          begin
            disp_part = high_degree ? disp_num[19:16] : disp_num[3:0];
            disp_point = pointing[0];
            disp_blink = blinking[0];
          end
        1 :
          begin
            disp_part = high_degree ? disp_num[23:20] : disp_num[7:4];
            disp_point = pointing[1];
            disp_blink = blinking[1];
          end
        2 :
          begin
            disp_part = high_degree ? disp_num[27:24] : disp_num[11:8];
            disp_point = pointing[2];
            disp_blink = blinking[2];
          end
        3 :
          begin
            disp_part = high_degree ? disp_num[31:28] : disp_num[15:12];
            disp_point = pointing[3];
            disp_blink = blinking[3];
          end
      endcase

      case (disp_part)
        0 : SEGMENT = {~disp_point, 7'b1000000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        1 : SEGMENT = {~disp_point, 7'b1111001} | (disp_blink ? {8{flash_clk}} : 8'h00);
        2 : SEGMENT = {~disp_point, 7'b0100100} | (disp_blink ? {8{flash_clk}} : 8'h00);
        3 : SEGMENT = {~disp_point, 7'b0110000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        4 : SEGMENT = {~disp_point, 7'b0011001} | (disp_blink ? {8{flash_clk}} : 8'h00);
        5 : SEGMENT = {~disp_point, 7'b0010010} | (disp_blink ? {8{flash_clk}} : 8'h00);
        6 : SEGMENT = {~disp_point, 7'b0000010} | (disp_blink ? {8{flash_clk}} : 8'h00);
        7 : SEGMENT = {~disp_point, 7'b1111000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        8 : SEGMENT = {~disp_point, 7'b0000000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        9 : SEGMENT = {~disp_point, 7'b0010000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        10 : SEGMENT = {~disp_point, 7'b0001000} | (disp_blink ? {8{flash_clk}} : 8'h00);
        11 : SEGMENT = {~disp_point, 7'b0000011} | (disp_blink ? {8{flash_clk}} : 8'h00);
        12 : SEGMENT = {~disp_point, 7'b1000100} | (disp_blink ? {8{flash_clk}} : 8'h00);
        13 : SEGMENT = {~disp_point, 7'b0100001} | (disp_blink ? {8{flash_clk}} : 8'h00);
        14 : SEGMENT = {~disp_point, 7'b0000110} | (disp_blink ? {8{flash_clk}} : 8'h00);
        15 : SEGMENT = {~disp_point, 7'b0001110} | (disp_blink ? {8{flash_clk}} : 8'h00);
      endcase
    end
  end

endmodule
