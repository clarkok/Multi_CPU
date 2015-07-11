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
    output reg [7:0] io_ctrl_data,
    output reg io_ctrl_interrupt
    );

  reg [3:0] counter;
  reg [3:0] last;
  
  initial begin
    io_ctrl_data <= 8'b0;
    io_ctrl_interrupt <= 1'b0;
    counter <= 4'b0;
    last <= 4'b0;
  end

  always @ (negedge io_keyboard_kb_clk) begin
    case (counter)
      0: begin
        counter <= counter + 1;
      end
      1: begin
        counter <= counter + 1;
        io_ctrl_data[0] <= io_keyboard_kb_data;
      end
      2: begin
        counter <= counter + 1;
        io_ctrl_data[1] <= io_keyboard_kb_data;
      end
      3: begin
        counter <= counter + 1;
        io_ctrl_data[2] <= io_keyboard_kb_data;
      end
      4: begin
        counter <= counter + 1;
        io_ctrl_data[3] <= io_keyboard_kb_data;
      end
      5: begin
        counter <= counter + 1;
        io_ctrl_data[4] <= io_keyboard_kb_data;
      end
      6: begin
        counter <= counter + 1;
        io_ctrl_data[5] <= io_keyboard_kb_data;
      end
      7: begin
        counter <= counter + 1;
        io_ctrl_data[6] <= io_keyboard_kb_data;
      end
      8: begin
        counter <= counter + 1;
        io_ctrl_data[7] <= io_keyboard_kb_data;
      end
      9: begin
        counter <= counter + 1;
      end
      10: begin
        counter <= 4'b0;
      end
    endcase
  end

  always @ (posedge clk) begin
    io_ctrl_interrupt = (last != 4'd10 && counter == 4'd10);
    last = counter;
  end
endmodule
