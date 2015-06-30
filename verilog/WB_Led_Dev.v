module WB_Led_Dev(input clk, input reset,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    output[7:0] io_LED
);

  reg [7:0] led_data;
  wire[7:0] T9;
  wire[31:0] T10;
  wire[31:0] T0;
  wire[31:0] T11;
  wire T1;
  reg [31:0] data_out;
  wire[31:0] T12;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T13;
  wire T5;
  wire T6;
  wire T7;
  wire T8;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    led_data = {1{$random}};
    data_out = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_LED = led_data;
  assign T9 = T10[3'h7:1'h0];
  assign T10 = reset ? 32'h0 : T0;
  assign T0 = T1 ? io_bus_dat2 : T11;
  assign T11 = {24'h0, led_data};
  assign T1 = io_bus_sel & io_bus_we;
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = data_out;
  assign T12 = reset ? 32'h0 : T2;
  assign T2 = T7 ? 32'h0 : T3;
  assign T3 = T5 ? T13 : T4;
  assign T4 = T1 ? io_bus_dat2 : data_out;
  assign T13 = {24'h0, led_data};
  assign T5 = T6 & io_bus_sel;
  assign T6 = T1 ^ 1'h1;
  assign T7 = T8 ^ 1'h1;
  assign T8 = T1 | io_bus_sel;

  always @(posedge clk) begin
    led_data <= T9;
    if(reset) begin
      data_out <= 32'h0;
    end else if(T7) begin
      data_out <= 32'h0;
    end else if(T5) begin
      data_out <= T13;
    end else if(T1) begin
      data_out <= io_bus_dat2;
    end
  end
endmodule

