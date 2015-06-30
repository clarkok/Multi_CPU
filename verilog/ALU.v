module ALU(
    input [2:0] io_alu_op,
    input [31:0] io_in_a,
    input [31:0] io_in_b,
    output[31:0] io_out,
    output io_zero
);

  wire T0;
  wire T1;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire[31:0] T7;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T36;
  wire T10;
  wire T11;
  wire T12;
  wire[31:0] T13;
  wire[31:0] T14;
  wire T15;
  wire[31:0] T16;
  wire[31:0] T17;
  wire[4:0] T18;
  wire T19;
  wire[31:0] T20;
  wire[31:0] T21;
  wire[31:0] T22;
  wire T23;
  wire[31:0] T24;
  wire[31:0] T25;
  wire T26;
  wire[31:0] T27;
  wire[31:0] T28;
  wire T29;
  wire[31:0] T30;
  wire[31:0] T31;
  wire T32;
  wire[31:0] T33;
  wire[31:0] T34;
  wire T35;


  assign io_zero = T0;
  assign T0 = T1 ^ 1'h1;
  assign T1 = io_out != 32'h0;
  assign io_out = T2;
  assign T2 = T35 ? T33 : T3;
  assign T3 = T32 ? T30 : T4;
  assign T4 = T29 ? T27 : T5;
  assign T5 = T26 ? T24 : T6;
  assign T6 = T23 ? T20 : T7;
  assign T7 = T19 ? T16 : T8;
  assign T8 = T15 ? T13 : T9;
  assign T9 = T12 ? T36 : 32'h0;
  assign T36 = {31'h0, T10};
  assign T10 = T11;
  assign T11 = io_in_a < io_in_b;
  assign T12 = io_alu_op == 3'h7;
  assign T13 = T14;
  assign T14 = io_in_a - io_in_b;
  assign T15 = io_alu_op == 3'h6;
  assign T16 = T17;
  assign T17 = io_in_a >> T18;
  assign T18 = io_in_b[3'h4:1'h0];
  assign T19 = io_alu_op == 3'h5;
  assign T20 = T21;
  assign T21 = ~ T22;
  assign T22 = io_in_a | io_in_b;
  assign T23 = io_alu_op == 3'h4;
  assign T24 = T25;
  assign T25 = io_in_a ^ io_in_b;
  assign T26 = io_alu_op == 3'h3;
  assign T27 = T28;
  assign T28 = io_in_a + io_in_b;
  assign T29 = io_alu_op == 3'h2;
  assign T30 = T31;
  assign T31 = io_in_a | io_in_b;
  assign T32 = io_alu_op == 3'h1;
  assign T33 = T34;
  assign T34 = io_in_a & io_in_b;
  assign T35 = io_alu_op == 3'h0;
endmodule

