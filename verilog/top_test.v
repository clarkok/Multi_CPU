`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   12:31:46 07/01/2015
// Design Name:   top
// Module Name:   /home/c/Documents/Multi_CPU/top_test.v
// Project Name:  Multi_CPU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: top
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module top_test;

	// Inputs
	reg clk;
	reg [7:0] SW;
	reg [4:0] BTN;

	// Outputs
	wire [7:0] LED;
	wire [7:0] SEG;
	wire [4:0] AN;
  wire [2:0] vgaRed;
  wire [2:0] vgaGreen;
  wire [1:0] vgaBlue;
  wire Hsync;
  wire Vsync;

	// Instantiate the Unit Under Test (UUT)
	top uut (
		.clk(clk), 
		.SW(SW), 
		.BTN(BTN), 
		.LED(LED), 
		.SEG(SEG), 
		.AN(AN),
    .vgaRed(vgaRed),
    .vgaGreen(vgaGreen),
    .vgaBlue(vgaBlue),
    .Hsync(Hsync),
    .Vsync(Vsync)
	);

  initial forever #5 clk = ~clk;

	initial begin
		// Initialize Inputs
		clk = 0;
		SW = 0;
		BTN = 0;

		// Wait 100 ns for global reset to finish
		#100;
    SW = 8'h1;

    #100;
    SW = 8'h2;

	end
      
endmodule

