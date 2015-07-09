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
module Mux8to1_32bit(
    input [2:0] io_sel,
    input [31:0] io_in0,
    input [31:0] io_in1,
    input [31:0] io_in2,
    input [31:0] io_in3,
    input [31:0] io_in4,
    input [31:0] io_in5,
    input [31:0] io_in6,
    input [31:0] io_in7,
    output reg [31:0] io_out
    );
    
    always @* begin
        case (io_sel)
            0: io_out = io_in0;
            1: io_out = io_in1;
            2: io_out = io_in2;
            3: io_out = io_in3;
            4: io_out = io_in4;
            5: io_out = io_in5;
            6: io_out = io_in6;
            7: io_out = io_in7;
        endcase
    end
endmodule

module Mux8to1_1bit(
    input [2:0] io_sel,
    input [1:0] io_in0,
    input [1:0] io_in1,
    input [1:0] io_in2,
    input [1:0] io_in3,
    input [1:0] io_in4,
    input [1:0] io_in5,
    input [1:0] io_in6,
    input [1:0] io_in7,
    output reg [1:0] io_out
    );
    
    always @* begin
        case (io_sel)
            0: io_out = io_in0;
            1: io_out = io_in1;
            2: io_out = io_in2;
            3: io_out = io_in3;
            4: io_out = io_in4;
            5: io_out = io_in5;
            6: io_out = io_in6;
            7: io_out = io_in7;
        endcase
    end
endmodule