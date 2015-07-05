`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   11:37:46 07/05/2015
// Design Name:   WB_VGA_Dev
// Module Name:   /home/c/Documents/Multi_CPU/vga-dev_test.v
// Project Name:  Multi_CPU
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: WB_VGA_Dev
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module vga_dev_test;

	// Inputs
	reg clk;
	reg reset;
	reg [31:0] io_bus_addr;
	reg [31:0] io_bus_dat2;
	reg io_bus_sel;
	reg io_bus_we;

	// Outputs
	wire [2:0] io_vga_red;
	wire [2:0] io_vga_green;
	wire [1:0] io_vga_blue;
	wire io_vga_hsync;
	wire io_vga_vsync;
	wire [31:0] io_bus_dat4;
	wire io_bus_ack;

	// Instantiate the Unit Under Test (UUT)
	WB_VGA_Dev uut (
		.clk(clk), 
		.reset(reset), 
		.io_vga_red(io_vga_red), 
		.io_vga_green(io_vga_green), 
		.io_vga_blue(io_vga_blue), 
		.io_vga_hsync(io_vga_hsync), 
		.io_vga_vsync(io_vga_vsync), 
		.io_bus_addr(io_bus_addr), 
		.io_bus_dat2(io_bus_dat2), 
		.io_bus_dat4(io_bus_dat4), 
		.io_bus_sel(io_bus_sel), 
		.io_bus_we(io_bus_we), 
		.io_bus_ack(io_bus_ack)
	);

  initial forever #5 clk = ~clk;

	initial begin
		// Initialize Inputs
		clk = 0;
		reset = 1;
		io_bus_addr = 0;
		io_bus_dat2 = 0;
		io_bus_sel = 0;
		io_bus_we = 0;

		// Wait 100 ns for global reset to finish
		#10;
    reset = 0;
        
		// Add stimulus here

	end
      
endmodule

