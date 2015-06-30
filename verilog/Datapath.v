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

module Register_File(input clk,
    input [4:0] io_addra,
    output[31:0] io_douta,
    input [4:0] io_addrb,
    output[31:0] io_doutb,
    input [4:0] io_wtaddr,
    input [31:0] io_wtdata,
    input  io_we
);

  wire[31:0] T0;
  reg [31:0] rf [31:0];
  wire[31:0] T1;
  wire T2;
  wire T3;
  wire[31:0] T4;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    for (initvar = 0; initvar < 32; initvar = initvar+1)
      rf[initvar] = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_doutb = T0;
  assign T0 = rf[io_addrb];
  assign T2 = io_we & T3;
  assign T3 = io_wtaddr != 5'h0;
  assign io_douta = T4;
  assign T4 = rf[io_addra];

  always @(posedge clk) begin
    if (T2)
      rf[io_wtaddr] <= io_wtdata;
  end
endmodule

module Datapath(input clk, input reset,
    input [31:0] io_bus_data,
    output[31:0] io_inst,
    input  io_inst_we,
    input  io_pc_we,
    input [1:0] io_pc_next_sel,
    output[31:0] io_pc_out,
    input  io_reg_we,
    input [1:0] io_reg_we_src,
    input [1:0] io_reg_we_dst,
    input [2:0] io_alu_op,
    input  io_alu_b_sel,
    output[31:0] io_alu_out,
    output[31:0] io_data_out
);

  wire[31:0] T0;
  wire[31:0] T1;
  wire[31:0] T2;
  wire[31:0] T3;
  reg [31:0] pc;
  wire[31:0] T48;
  wire[32:0] T49;
  wire[32:0] T4;
  wire[32:0] T50;
  wire[32:0] pc_next;
  wire[32:0] T5;
  wire[32:0] T51;
  wire[31:0] T6;
  wire[31:0] T7;
  wire T8;
  wire[31:0] T52;
  wire[27:0] T9;
  wire[27:0] T10;
  wire[25:0] T11;
  reg [31:0] inst_reg;
  wire[31:0] T53;
  wire[31:0] T12;
  wire[27:0] T54;
  wire[3:0] T13;
  wire T14;
  wire[32:0] T15;
  wire[32:0] T55;
  wire[31:0] T16;
  wire[31:0] T17;
  wire T18;
  wire[32:0] T19;
  wire[32:0] T20;
  wire[32:0] T21;
  wire[32:0] T22;
  wire[32:0] T56;
  wire[17:0] T23;
  wire[15:0] T24;
  wire[15:0] T25;
  wire[14:0] T57;
  wire T58;
  wire T26;
  wire T27;
  wire[32:0] T59;
  wire[31:0] T28;
  wire T29;
  wire T30;
  wire T31;
  wire T32;
  wire[4:0] T33;
  wire[4:0] T34;
  wire[4:0] T35;
  wire T36;
  wire[4:0] T37;
  wire T38;
  wire[4:0] T39;
  wire T40;
  wire[4:0] T41;
  wire[4:0] T42;
  wire[31:0] T43;
  wire[31:0] T44;
  wire[31:0] T60;
  wire[15:0] T45;
  wire T46;
  wire T47;
  wire[31:0] alu_io_out;
  wire alu_io_zero;
  wire[31:0] regfile_io_douta;
  wire[31:0] regfile_io_doutb;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    pc = {1{$random}};
    inst_reg = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = T32 ? alu_io_out : T1;
  assign T1 = T31 ? io_bus_data : T2;
  assign T2 = T30 ? T3 : 32'h0;
  assign T3 = pc + 32'h4;
  assign T48 = T49[5'h1f:1'h0];
  assign T49 = reset ? 33'h0 : T4;
  assign T4 = io_pc_we ? pc_next : T50;
  assign T50 = {1'h0, pc};
  assign pc_next = T29 ? T59 : T5;
  assign T5 = T27 ? T15 : T51;
  assign T51 = {1'h0, T6};
  assign T6 = T14 ? T52 : T7;
  assign T7 = T8 ? regfile_io_douta : 32'h0;
  assign T8 = io_pc_next_sel == 2'h3;
  assign T52 = {4'h0, T9};
  assign T9 = T54 | T10;
  assign T10 = T11 << 2'h2;
  assign T11 = inst_reg[5'h19:1'h0];
  assign T53 = reset ? 32'h0 : T12;
  assign T12 = io_inst_we ? io_bus_data : inst_reg;
  assign T54 = {24'h0, T13};
  assign T13 = pc[5'h1f:5'h1c];
  assign T14 = io_pc_next_sel == 2'h2;
  assign T15 = T26 ? T19 : T55;
  assign T55 = {1'h0, T16};
  assign T16 = T18 ? T17 : 32'h0;
  assign T17 = pc + 32'h4;
  assign T18 = alu_io_zero == 1'h0;
  assign T19 = T20;
  assign T20 = T56 + T21;
  assign T21 = T22;
  assign T22 = {1'h0, pc};
  assign T56 = {T57, T23};
  assign T23 = T24 << 2'h2;
  assign T24 = T25;
  assign T25 = inst_reg[4'hf:1'h0];
  assign T57 = T58 ? 15'h7fff : 15'h0;
  assign T58 = T23[5'h11:5'h11];
  assign T26 = alu_io_zero == 1'h1;
  assign T27 = io_pc_next_sel == 2'h1;
  assign T59 = {1'h0, T28};
  assign T28 = pc + 32'h4;
  assign T29 = io_pc_next_sel == 2'h0;
  assign T30 = io_reg_we_src == 2'h2;
  assign T31 = io_reg_we_src == 2'h1;
  assign T32 = io_reg_we_src == 2'h0;
  assign T33 = T40 ? T39 : T34;
  assign T34 = T38 ? T37 : T35;
  assign T35 = T36 ? 5'h1f : 5'h0;
  assign T36 = io_reg_we_dst == 2'h2;
  assign T37 = inst_reg[5'h14:5'h10];
  assign T38 = io_reg_we_dst == 2'h1;
  assign T39 = inst_reg[4'hf:4'hb];
  assign T40 = io_reg_we_dst == 2'h0;
  assign T41 = inst_reg[5'h14:5'h10];
  assign T42 = inst_reg[5'h19:5'h15];
  assign T43 = T47 ? regfile_io_doutb : T44;
  assign T44 = T46 ? T60 : 32'h0;
  assign T60 = {16'h0, T45};
  assign T45 = inst_reg[4'hf:1'h0];
  assign T46 = io_alu_b_sel == 1'h1;
  assign T47 = io_alu_b_sel == 1'h0;
  assign io_data_out = regfile_io_doutb;
  assign io_alu_out = alu_io_out;
  assign io_pc_out = pc;
  assign io_inst = inst_reg;
  ALU alu(
       .io_alu_op( io_alu_op ),
       .io_in_a( regfile_io_douta ),
       .io_in_b( T43 ),
       .io_out( alu_io_out ),
       .io_zero( alu_io_zero )
  );
  Register_File regfile(.clk(clk),
       .io_addra( T42 ),
       .io_douta( regfile_io_douta ),
       .io_addrb( T41 ),
       .io_doutb( regfile_io_doutb ),
       .io_wtaddr( T33 ),
       .io_wtdata( T0 ),
       .io_we( io_reg_we )
  );

  always @(posedge clk) begin
    pc <= T48;
    if(reset) begin
      inst_reg <= 32'h0;
    end else if(io_inst_we) begin
      inst_reg <= io_bus_data;
    end
  end
endmodule

