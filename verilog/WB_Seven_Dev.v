module WB_Seven_Dev(input clk, input reset,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    output[31:0] io_DISP_NUM
);

  reg [31:0] disp_data;
  wire[31:0] T9;
  wire[31:0] T0;
  wire T1;
  reg [31:0] data_out;
  wire[31:0] T10;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire T5;
  wire T6;
  wire T7;
  wire T8;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    disp_data = {1{$random}};
    data_out = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_DISP_NUM = disp_data;
  assign T9 = reset ? 32'h0 : T0;
  assign T0 = T1 ? io_bus_dat2 : disp_data;
  assign T1 = io_bus_sel & io_bus_we;
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = data_out;
  assign T10 = reset ? 32'h0 : T2;
  assign T2 = T7 ? 32'h0 : T3;
  assign T3 = T5 ? disp_data : T4;
  assign T4 = T1 ? io_bus_dat2 : data_out;
  assign T5 = T6 & io_bus_sel;
  assign T6 = T1 ^ 1'h1;
  assign T7 = T8 ^ 1'h1;
  assign T8 = T1 | io_bus_sel;

  always @(posedge clk) begin
    if(reset) begin
      disp_data <= 32'h0;
    end else if(T1) begin
      disp_data <= io_bus_dat2;
    end
    if(reset) begin
      data_out <= 32'h0;
    end else if(T7) begin
      data_out <= 32'h0;
    end else if(T5) begin
      data_out <= disp_data;
    end else if(T1) begin
      data_out <= io_bus_dat2;
    end
  end
endmodule

