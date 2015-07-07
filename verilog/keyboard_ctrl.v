`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    14:26:36 01/08/2015 
// Design Name: 
// Module Name:    keyboard_ctrl 
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
module Keyboard_Ctrl(
    input clk,
    input io_keyboard_kb_data,
    input io_keyboard_kb_clk,
    output [7:0] io_ctrl_data,
    output io_ctrl_interrupt
    );
    
  wire k_clk;
  wire k_data;
  reg [7:0] data;
  
  assign k_clk = io_keyboard_kb_clk;
  assign k_data = io_keyboard_kb_data;
  assign io_ctrl_data = data;

  reg [3:0] counter = 0, last = 0;

  always @ (negedge k_clk) begin
    case (counter)
      0: begin
        counter <= counter + 1;
      end
      1: begin
        counter <= counter + 1;
        data[0] <= k_data;
      end
      2: begin
        counter <= counter + 1;
        data[1] <= k_data;
      end
      3: begin
        counter <= counter + 1;
        data[2] <= k_data;
      end
      4: begin
        counter <= counter + 1;
        data[3] <= k_data;
      end
      5: begin
        counter <= counter + 1;
        data[4] <= k_data;
      end
      6: begin
        counter <= counter + 1;
        data[5] <= k_data;
      end
      7: begin
        counter <= counter + 1;
        data[6] <= k_data;
      end
      8: begin
        counter <= counter + 1;
        data[7] <= k_data;
      end
      9: begin
        counter <= counter + 1;
      end
      10: begin
        counter <= 4'b0;
      end
    endcase
  end
  
  assign io_ctrl_interrupt = (last != 4'd10 && counter == 4'd10);

  always @ (posedge clk) begin
    last <= counter;
  end
endmodule
