module WB_Bus(input clk, input reset,
    input [31:0] io_from_cpu_addr,
    input [31:0] io_from_cpu_dat2,
    output[31:0] io_from_cpu_dat4,
    input  io_from_cpu_sel,
    input  io_from_cpu_we,
    output io_from_cpu_ack,
    output[31:0] io_slaves_7_addr,
    output[31:0] io_slaves_7_dat2,
    input [31:0] io_slaves_7_dat4,
    output io_slaves_7_sel,
    output io_slaves_7_we,
    input  io_slaves_7_ack,
    output[31:0] io_slaves_6_addr,
    output[31:0] io_slaves_6_dat2,
    input [31:0] io_slaves_6_dat4,
    output io_slaves_6_sel,
    output io_slaves_6_we,
    input  io_slaves_6_ack,
    output[31:0] io_slaves_5_addr,
    output[31:0] io_slaves_5_dat2,
    input [31:0] io_slaves_5_dat4,
    output io_slaves_5_sel,
    output io_slaves_5_we,
    input  io_slaves_5_ack,
    output[31:0] io_slaves_4_addr,
    output[31:0] io_slaves_4_dat2,
    input [31:0] io_slaves_4_dat4,
    output io_slaves_4_sel,
    output io_slaves_4_we,
    input  io_slaves_4_ack,
    output[31:0] io_slaves_3_addr,
    output[31:0] io_slaves_3_dat2,
    input [31:0] io_slaves_3_dat4,
    output io_slaves_3_sel,
    output io_slaves_3_we,
    input  io_slaves_3_ack,
    output[31:0] io_slaves_2_addr,
    output[31:0] io_slaves_2_dat2,
    input [31:0] io_slaves_2_dat4,
    output io_slaves_2_sel,
    output io_slaves_2_we,
    input  io_slaves_2_ack,
    output[31:0] io_slaves_1_addr,
    output[31:0] io_slaves_1_dat2,
    input [31:0] io_slaves_1_dat4,
    output io_slaves_1_sel,
    output io_slaves_1_we,
    input  io_slaves_1_ack,
    output[31:0] io_slaves_0_addr,
    output[31:0] io_slaves_0_dat2,
    input [31:0] io_slaves_0_dat4,
    output io_slaves_0_sel,
    output io_slaves_0_we,
    input  io_slaves_0_ack,
    output[31:0] io_ram_slave_addr,
    output[31:0] io_ram_slave_dat2,
    input [31:0] io_ram_slave_dat4,
    output io_ram_slave_sel,
    output io_ram_slave_we,
    input  io_ram_slave_ack
);

  wire T0;
  wire T1;
  wire ram_op;
  wire T2;
  wire T3;
  reg  ack_out;
  wire T123;
  wire[31:0] T124;
  wire[27:0] T4;
  reg  slave_we_0;
  wire T125;
  wire T5;
  wire T6;
  wire T7;
  wire T8;
  wire[7:0] T9;
  wire[2:0] T10;
  wire[2:0] current_slave;
  wire T11;
  wire T12;
  reg  slave_sel_0;
  wire T126;
  wire T13;
  wire T14;
  wire T15;
  wire T16;
  wire[7:0] T17;
  wire[2:0] T18;
  wire[31:0] T127;
  wire[27:0] T19;
  reg  slave_we_1;
  wire T128;
  wire T20;
  wire T21;
  wire T22;
  wire T23;
  reg  slave_sel_1;
  wire T129;
  wire T24;
  wire T25;
  wire T26;
  wire T27;
  wire[31:0] T130;
  wire[27:0] T28;
  reg  slave_we_2;
  wire T131;
  wire T29;
  wire T30;
  wire T31;
  wire T32;
  reg  slave_sel_2;
  wire T132;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire[31:0] T133;
  wire[27:0] T37;
  reg  slave_we_3;
  wire T134;
  wire T38;
  wire T39;
  wire T40;
  wire T41;
  reg  slave_sel_3;
  wire T135;
  wire T42;
  wire T43;
  wire T44;
  wire T45;
  wire[31:0] T136;
  wire[27:0] T46;
  reg  slave_we_4;
  wire T137;
  wire T47;
  wire T48;
  wire T49;
  wire T50;
  reg  slave_sel_4;
  wire T138;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire[31:0] T139;
  wire[27:0] T55;
  reg  slave_we_5;
  wire T140;
  wire T56;
  wire T57;
  wire T58;
  wire T59;
  reg  slave_sel_5;
  wire T141;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire[31:0] T142;
  wire[27:0] T64;
  reg  slave_we_6;
  wire T143;
  wire T65;
  wire T66;
  wire T67;
  wire T68;
  reg  slave_sel_6;
  wire T144;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire[31:0] T145;
  wire[27:0] T73;
  reg  slave_we_7;
  wire T146;
  wire T74;
  wire T75;
  wire T76;
  wire T77;
  reg  slave_sel_7;
  wire T147;
  wire T78;
  wire T79;
  wire T80;
  wire T81;
  wire[31:0] T148;
  wire[27:0] T82;
  wire T83;
  wire T84;
  wire T85;
  wire T86;
  wire T87;
  wire T88;
  wire T89;
  wire T90;
  wire T91;
  wire T92;
  wire T93;
  wire T94;
  wire T95;
  wire T96;
  wire T97;
  wire T98;
  wire T99;
  wire T100;
  wire T101;
  wire T102;
  wire[31:0] T103;
  wire[31:0] T104;
  wire T105;
  wire[31:0] T106;
  wire[31:0] T107;
  wire[31:0] T108;
  wire[31:0] T109;
  wire[31:0] T110;
  wire[31:0] T111;
  wire[31:0] T112;
  wire[31:0] T113;
  wire T114;
  wire T115;
  wire T116;
  wire T117;
  wire T118;
  wire T119;
  wire T120;
  wire T121;
  wire T122;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    ack_out = {1{$random}};
    slave_we_0 = {1{$random}};
    slave_sel_0 = {1{$random}};
    slave_we_1 = {1{$random}};
    slave_sel_1 = {1{$random}};
    slave_we_2 = {1{$random}};
    slave_sel_2 = {1{$random}};
    slave_we_3 = {1{$random}};
    slave_sel_3 = {1{$random}};
    slave_we_4 = {1{$random}};
    slave_sel_4 = {1{$random}};
    slave_we_5 = {1{$random}};
    slave_sel_5 = {1{$random}};
    slave_we_6 = {1{$random}};
    slave_sel_6 = {1{$random}};
    slave_we_7 = {1{$random}};
    slave_sel_7 = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_ram_slave_we = T0;
  assign T0 = T1 ? io_from_cpu_we : 1'h0;
  assign T1 = T3 & ram_op;
  assign ram_op = ~ T2;
  assign T2 = io_from_cpu_addr[5'h1f:5'h1f];
  assign T3 = ack_out & io_from_cpu_sel;
  assign T123 = reset ? 1'h1 : ack_out;
  assign io_ram_slave_sel = T1;
  assign io_ram_slave_dat2 = io_from_cpu_dat2;
  assign io_ram_slave_addr = T124;
  assign T124 = {4'h0, T4};
  assign T4 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_0_we = slave_we_0;
  assign T125 = reset ? 1'h0 : T5;
  assign T5 = T7 ? io_from_cpu_we : T6;
  assign T6 = ack_out ? 1'h0 : slave_we_0;
  assign T7 = T11 & T8;
  assign T8 = T9[1'h0:1'h0];
  assign T9 = 1'h1 << T10;
  assign T10 = current_slave;
  assign current_slave = io_from_cpu_addr[5'h1e:5'h1c];
  assign T11 = T3 & T12;
  assign T12 = ram_op ^ 1'h1;
  assign io_slaves_0_sel = slave_sel_0;
  assign T126 = reset ? 1'h0 : T13;
  assign T13 = T15 ? 1'h1 : T14;
  assign T14 = ack_out ? 1'h0 : slave_sel_0;
  assign T15 = T11 & T16;
  assign T16 = T17[1'h0:1'h0];
  assign T17 = 1'h1 << T18;
  assign T18 = current_slave;
  assign io_slaves_0_dat2 = io_from_cpu_dat2;
  assign io_slaves_0_addr = T127;
  assign T127 = {4'h0, T19};
  assign T19 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_1_we = slave_we_1;
  assign T128 = reset ? 1'h0 : T20;
  assign T20 = T22 ? io_from_cpu_we : T21;
  assign T21 = ack_out ? 1'h0 : slave_we_1;
  assign T22 = T11 & T23;
  assign T23 = T9[1'h1:1'h1];
  assign io_slaves_1_sel = slave_sel_1;
  assign T129 = reset ? 1'h0 : T24;
  assign T24 = T26 ? 1'h1 : T25;
  assign T25 = ack_out ? 1'h0 : slave_sel_1;
  assign T26 = T11 & T27;
  assign T27 = T17[1'h1:1'h1];
  assign io_slaves_1_dat2 = io_from_cpu_dat2;
  assign io_slaves_1_addr = T130;
  assign T130 = {4'h0, T28};
  assign T28 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_2_we = slave_we_2;
  assign T131 = reset ? 1'h0 : T29;
  assign T29 = T31 ? io_from_cpu_we : T30;
  assign T30 = ack_out ? 1'h0 : slave_we_2;
  assign T31 = T11 & T32;
  assign T32 = T9[2'h2:2'h2];
  assign io_slaves_2_sel = slave_sel_2;
  assign T132 = reset ? 1'h0 : T33;
  assign T33 = T35 ? 1'h1 : T34;
  assign T34 = ack_out ? 1'h0 : slave_sel_2;
  assign T35 = T11 & T36;
  assign T36 = T17[2'h2:2'h2];
  assign io_slaves_2_dat2 = io_from_cpu_dat2;
  assign io_slaves_2_addr = T133;
  assign T133 = {4'h0, T37};
  assign T37 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_3_we = slave_we_3;
  assign T134 = reset ? 1'h0 : T38;
  assign T38 = T40 ? io_from_cpu_we : T39;
  assign T39 = ack_out ? 1'h0 : slave_we_3;
  assign T40 = T11 & T41;
  assign T41 = T9[2'h3:2'h3];
  assign io_slaves_3_sel = slave_sel_3;
  assign T135 = reset ? 1'h0 : T42;
  assign T42 = T44 ? 1'h1 : T43;
  assign T43 = ack_out ? 1'h0 : slave_sel_3;
  assign T44 = T11 & T45;
  assign T45 = T17[2'h3:2'h3];
  assign io_slaves_3_dat2 = io_from_cpu_dat2;
  assign io_slaves_3_addr = T136;
  assign T136 = {4'h0, T46};
  assign T46 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_4_we = slave_we_4;
  assign T137 = reset ? 1'h0 : T47;
  assign T47 = T49 ? io_from_cpu_we : T48;
  assign T48 = ack_out ? 1'h0 : slave_we_4;
  assign T49 = T11 & T50;
  assign T50 = T9[3'h4:3'h4];
  assign io_slaves_4_sel = slave_sel_4;
  assign T138 = reset ? 1'h0 : T51;
  assign T51 = T53 ? 1'h1 : T52;
  assign T52 = ack_out ? 1'h0 : slave_sel_4;
  assign T53 = T11 & T54;
  assign T54 = T17[3'h4:3'h4];
  assign io_slaves_4_dat2 = io_from_cpu_dat2;
  assign io_slaves_4_addr = T139;
  assign T139 = {4'h0, T55};
  assign T55 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_5_we = slave_we_5;
  assign T140 = reset ? 1'h0 : T56;
  assign T56 = T58 ? io_from_cpu_we : T57;
  assign T57 = ack_out ? 1'h0 : slave_we_5;
  assign T58 = T11 & T59;
  assign T59 = T9[3'h5:3'h5];
  assign io_slaves_5_sel = slave_sel_5;
  assign T141 = reset ? 1'h0 : T60;
  assign T60 = T62 ? 1'h1 : T61;
  assign T61 = ack_out ? 1'h0 : slave_sel_5;
  assign T62 = T11 & T63;
  assign T63 = T17[3'h5:3'h5];
  assign io_slaves_5_dat2 = io_from_cpu_dat2;
  assign io_slaves_5_addr = T142;
  assign T142 = {4'h0, T64};
  assign T64 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_6_we = slave_we_6;
  assign T143 = reset ? 1'h0 : T65;
  assign T65 = T67 ? io_from_cpu_we : T66;
  assign T66 = ack_out ? 1'h0 : slave_we_6;
  assign T67 = T11 & T68;
  assign T68 = T9[3'h6:3'h6];
  assign io_slaves_6_sel = slave_sel_6;
  assign T144 = reset ? 1'h0 : T69;
  assign T69 = T71 ? 1'h1 : T70;
  assign T70 = ack_out ? 1'h0 : slave_sel_6;
  assign T71 = T11 & T72;
  assign T72 = T17[3'h6:3'h6];
  assign io_slaves_6_dat2 = io_from_cpu_dat2;
  assign io_slaves_6_addr = T145;
  assign T145 = {4'h0, T73};
  assign T73 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_7_we = slave_we_7;
  assign T146 = reset ? 1'h0 : T74;
  assign T74 = T76 ? io_from_cpu_we : T75;
  assign T75 = ack_out ? 1'h0 : slave_we_7;
  assign T76 = T11 & T77;
  assign T77 = T9[3'h7:3'h7];
  assign io_slaves_7_sel = slave_sel_7;
  assign T147 = reset ? 1'h0 : T78;
  assign T78 = T80 ? 1'h1 : T79;
  assign T79 = ack_out ? 1'h0 : slave_sel_7;
  assign T80 = T11 & T81;
  assign T81 = T17[3'h7:3'h7];
  assign io_slaves_7_dat2 = io_from_cpu_dat2;
  assign io_slaves_7_addr = T148;
  assign T148 = {4'h0, T82};
  assign T82 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_from_cpu_ack = T83;
  assign T83 = T102 ? T86 : T84;
  assign T84 = T85 ? io_ram_slave_ack : 1'h0;
  assign T85 = ram_op == 1'h1;
  assign T86 = T101 ? io_slaves_0_ack : T87;
  assign T87 = T100 ? io_slaves_1_ack : T88;
  assign T88 = T99 ? io_slaves_2_ack : T89;
  assign T89 = T98 ? io_slaves_3_ack : T90;
  assign T90 = T97 ? io_slaves_4_ack : T91;
  assign T91 = T96 ? io_slaves_5_ack : T92;
  assign T92 = T95 ? io_slaves_6_ack : T93;
  assign T93 = T94 ? io_slaves_7_ack : 1'h0;
  assign T94 = current_slave == 3'h7;
  assign T95 = current_slave == 3'h6;
  assign T96 = current_slave == 3'h5;
  assign T97 = current_slave == 3'h4;
  assign T98 = current_slave == 3'h3;
  assign T99 = current_slave == 3'h2;
  assign T100 = current_slave == 3'h1;
  assign T101 = current_slave == 3'h0;
  assign T102 = ram_op == 1'h0;
  assign io_from_cpu_dat4 = T103;
  assign T103 = T122 ? T106 : T104;
  assign T104 = T105 ? io_ram_slave_dat4 : 32'h0;
  assign T105 = ram_op == 1'h1;
  assign T106 = T121 ? io_slaves_0_dat4 : T107;
  assign T107 = T120 ? io_slaves_1_dat4 : T108;
  assign T108 = T119 ? io_slaves_2_dat4 : T109;
  assign T109 = T118 ? io_slaves_3_dat4 : T110;
  assign T110 = T117 ? io_slaves_4_dat4 : T111;
  assign T111 = T116 ? io_slaves_5_dat4 : T112;
  assign T112 = T115 ? io_slaves_6_dat4 : T113;
  assign T113 = T114 ? io_slaves_7_dat4 : 32'h0;
  assign T114 = current_slave == 3'h7;
  assign T115 = current_slave == 3'h6;
  assign T116 = current_slave == 3'h5;
  assign T117 = current_slave == 3'h4;
  assign T118 = current_slave == 3'h3;
  assign T119 = current_slave == 3'h2;
  assign T120 = current_slave == 3'h1;
  assign T121 = current_slave == 3'h0;
  assign T122 = ram_op == 1'h0;

  always @(posedge clk) begin
    if(reset) begin
      ack_out <= 1'h1;
    end
    if(reset) begin
      slave_we_0 <= 1'h0;
    end else if(T7) begin
      slave_we_0 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_0 <= 1'h0;
    end
    if(reset) begin
      slave_sel_0 <= 1'h0;
    end else if(T15) begin
      slave_sel_0 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_0 <= 1'h0;
    end
    if(reset) begin
      slave_we_1 <= 1'h0;
    end else if(T22) begin
      slave_we_1 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_1 <= 1'h0;
    end
    if(reset) begin
      slave_sel_1 <= 1'h0;
    end else if(T26) begin
      slave_sel_1 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_1 <= 1'h0;
    end
    if(reset) begin
      slave_we_2 <= 1'h0;
    end else if(T31) begin
      slave_we_2 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_2 <= 1'h0;
    end
    if(reset) begin
      slave_sel_2 <= 1'h0;
    end else if(T35) begin
      slave_sel_2 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_2 <= 1'h0;
    end
    if(reset) begin
      slave_we_3 <= 1'h0;
    end else if(T40) begin
      slave_we_3 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_3 <= 1'h0;
    end
    if(reset) begin
      slave_sel_3 <= 1'h0;
    end else if(T44) begin
      slave_sel_3 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_3 <= 1'h0;
    end
    if(reset) begin
      slave_we_4 <= 1'h0;
    end else if(T49) begin
      slave_we_4 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_4 <= 1'h0;
    end
    if(reset) begin
      slave_sel_4 <= 1'h0;
    end else if(T53) begin
      slave_sel_4 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_4 <= 1'h0;
    end
    if(reset) begin
      slave_we_5 <= 1'h0;
    end else if(T58) begin
      slave_we_5 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_5 <= 1'h0;
    end
    if(reset) begin
      slave_sel_5 <= 1'h0;
    end else if(T62) begin
      slave_sel_5 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_5 <= 1'h0;
    end
    if(reset) begin
      slave_we_6 <= 1'h0;
    end else if(T67) begin
      slave_we_6 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_6 <= 1'h0;
    end
    if(reset) begin
      slave_sel_6 <= 1'h0;
    end else if(T71) begin
      slave_sel_6 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_6 <= 1'h0;
    end
    if(reset) begin
      slave_we_7 <= 1'h0;
    end else if(T76) begin
      slave_we_7 <= io_from_cpu_we;
    end else if(ack_out) begin
      slave_we_7 <= 1'h0;
    end
    if(reset) begin
      slave_sel_7 <= 1'h0;
    end else if(T80) begin
      slave_sel_7 <= 1'h1;
    end else if(ack_out) begin
      slave_sel_7 <= 1'h0;
    end
  end
endmodule

