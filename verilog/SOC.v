module Ctrlpath(input clk, input reset,
    output[31:0] io_ctrl_bus_data,
    input [31:0] io_ctrl_inst,
    output io_ctrl_inst_we,
    output io_ctrl_pc_we,
    output[1:0] io_ctrl_pc_next_sel,
    input [31:0] io_ctrl_pc_out,
    output io_ctrl_reg_we,
    output[1:0] io_ctrl_reg_we_src,
    output[1:0] io_ctrl_reg_we_dst,
    output[2:0] io_ctrl_alu_op,
    output[1:0] io_ctrl_alu_b_sel,
    input [31:0] io_ctrl_alu_out,
    input [31:0] io_ctrl_data_out,
    output[31:0] io_bus_addr,
    output[31:0] io_bus_dat2,
    input [31:0] io_bus_dat4,
    output io_bus_sel,
    output io_bus_we,
    input  io_bus_ack,
    output[31:0] io_debug_inst_out,
    output[31:0] io_debug_bus_addr,
    output[31:0] io_debug_bus_dat2,
    output[31:0] io_debug_bus_dat4,
    output[31:0] io_debug_pc_out
);

  wire[31:0] inst;
  wire T0;
  reg [31:0] state;
  wire[31:0] T274;
  wire[31:0] T1;
  wire[31:0] next_state;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire[31:0] T7;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire[31:0] T11;
  wire[31:0] T12;
  wire[31:0] T13;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire T17;
  wire[5:0] inst_op;
  wire T18;
  wire T19;
  wire T20;
  wire T21;
  wire T22;
  wire T23;
  wire T24;
  wire T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire[31:0] T30;
  wire[31:0] T31;
  wire[31:0] T32;
  wire[31:0] T33;
  wire[31:0] T34;
  wire[31:0] T35;
  wire[31:0] T36;
  wire[31:0] T37;
  wire[31:0] T38;
  wire[31:0] T39;
  wire[31:0] T40;
  wire T41;
  wire[5:0] inst_func;
  wire T42;
  wire T43;
  wire T44;
  wire T45;
  wire T46;
  wire T47;
  wire T48;
  wire T49;
  wire T50;
  wire T51;
  wire T52;
  wire T53;
  wire bus_we;
  wire T54;
  wire T55;
  wire T56;
  wire T57;
  wire T58;
  wire T59;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire T66;
  wire T67;
  wire T68;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire T73;
  wire T74;
  wire T75;
  wire T76;
  wire T77;
  wire T78;
  wire T79;
  wire T80;
  wire T81;
  wire T82;
  wire T83;
  wire T84;
  wire T85;
  wire T86;
  wire T87;
  wire T88;
  wire T89;
  wire T90;
  wire inst_we;
  wire bus_sel;
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
  wire T103;
  wire T104;
  wire T105;
  wire T106;
  wire T107;
  wire T108;
  wire[31:0] T109;
  wire[31:0] T110;
  wire T111;
  wire bus_addr_src;
  wire T112;
  wire T113;
  wire T114;
  wire T115;
  wire T116;
  wire T117;
  wire T118;
  wire T119;
  wire T120;
  wire T121;
  wire T122;
  wire T123;
  wire T124;
  wire T125;
  wire T126;
  wire T127;
  wire T128;
  wire T129;
  wire T130;
  wire[1:0] alu_b_sel;
  wire[1:0] T131;
  wire[1:0] T132;
  wire[1:0] T133;
  wire[1:0] T134;
  wire[1:0] T135;
  wire[1:0] T136;
  wire[1:0] T137;
  wire[1:0] T138;
  wire[1:0] T139;
  wire[1:0] T140;
  wire[1:0] T141;
  wire[1:0] T142;
  wire[1:0] T143;
  wire[1:0] T144;
  wire[1:0] T145;
  wire[1:0] T146;
  wire[1:0] T147;
  wire[1:0] T148;
  wire[1:0] T149;
  wire[1:0] T150;
  wire[1:0] T151;
  wire[1:0] T275;
  wire T152;
  wire T153;
  wire T154;
  wire[2:0] alu_op;
  wire[2:0] T155;
  wire[2:0] T156;
  wire[2:0] T157;
  wire[2:0] T158;
  wire[2:0] T159;
  wire[2:0] T160;
  wire[2:0] T161;
  wire[2:0] T162;
  wire[2:0] T163;
  wire[2:0] T164;
  wire[2:0] T165;
  wire[2:0] T166;
  wire[2:0] T167;
  wire[2:0] T168;
  wire[2:0] T169;
  wire[2:0] T170;
  wire[2:0] T171;
  wire[2:0] T172;
  wire[2:0] T173;
  wire[2:0] T174;
  wire[2:0] T175;
  wire[2:0] T176;
  wire[1:0] reg_we_dst;
  wire[1:0] T177;
  wire[1:0] T178;
  wire[1:0] T179;
  wire[1:0] T180;
  wire[1:0] T181;
  wire[1:0] T182;
  wire[1:0] T183;
  wire[1:0] T184;
  wire[1:0] T185;
  wire[1:0] T186;
  wire[1:0] T187;
  wire[1:0] T188;
  wire[1:0] T189;
  wire[1:0] T190;
  wire[1:0] T191;
  wire[1:0] T192;
  wire[1:0] T193;
  wire[1:0] T194;
  wire[1:0] T195;
  wire[1:0] T196;
  wire[1:0] T197;
  wire[1:0] T198;
  wire[1:0] T199;
  wire[1:0] T200;
  wire T201;
  wire T202;
  wire[1:0] reg_we_src;
  wire[1:0] T203;
  wire[1:0] T204;
  wire[1:0] T205;
  wire[1:0] T206;
  wire[1:0] T207;
  wire[1:0] T208;
  wire[1:0] T209;
  wire[1:0] T210;
  wire[1:0] T211;
  wire[1:0] T212;
  wire[1:0] T213;
  wire[1:0] T214;
  wire[1:0] T215;
  wire[1:0] T216;
  wire[1:0] T217;
  wire[1:0] T218;
  wire[1:0] T219;
  wire[1:0] T220;
  wire[1:0] T221;
  wire[1:0] T222;
  wire[1:0] T223;
  wire[1:0] T224;
  wire[1:0] T225;
  wire[1:0] T226;
  wire reg_we;
  wire T227;
  wire T228;
  wire T229;
  wire T230;
  wire T231;
  wire T232;
  wire T233;
  wire T234;
  wire T235;
  wire T236;
  wire T237;
  wire T238;
  wire T239;
  wire T240;
  wire T241;
  wire T242;
  wire T243;
  wire T244;
  wire T245;
  wire T246;
  wire T247;
  wire T248;
  wire T249;
  wire[1:0] pc_next_sel;
  wire[1:0] T250;
  wire[1:0] T251;
  wire[1:0] T252;
  wire[1:0] T253;
  wire[1:0] T254;
  wire[1:0] T255;
  wire[1:0] T256;
  wire[1:0] T257;
  wire[1:0] T258;
  wire[1:0] T259;
  wire[1:0] T260;
  wire[1:0] T261;
  wire[1:0] T262;
  wire[1:0] T263;
  wire[1:0] T264;
  wire[1:0] T265;
  wire[1:0] T266;
  wire[1:0] T267;
  wire[1:0] T268;
  wire[1:0] T269;
  wire[1:0] T270;
  wire[1:0] T271;
  wire[1:0] T272;
  wire[1:0] T273;
  wire pc_we;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    state = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_debug_pc_out = io_ctrl_pc_out;
  assign io_debug_bus_dat4 = io_bus_dat4;
  assign io_debug_bus_dat2 = io_bus_dat2;
  assign io_debug_bus_addr = io_bus_addr;
  assign io_debug_inst_out = inst;
  assign inst = T0 ? io_bus_dat4 : io_ctrl_inst;
  assign T0 = state == 32'h0;
  assign T274 = reset ? 32'h0 : T1;
  assign T1 = io_bus_ack ? next_state : state;
  assign next_state = T2;
  assign T2 = T53 ? T3 : 32'h0;
  assign T3 = T52 ? T30 : T4;
  assign T4 = T29 ? 32'hc : T5;
  assign T5 = T28 ? 32'hd : T6;
  assign T6 = T27 ? 32'he : T7;
  assign T7 = T26 ? 32'hf : T8;
  assign T8 = T25 ? 32'h10 : T9;
  assign T9 = T24 ? 32'h11 : T10;
  assign T10 = T23 ? 32'h12 : T11;
  assign T11 = T22 ? 32'h13 : T12;
  assign T12 = T21 ? 32'h14 : T13;
  assign T13 = T20 ? 32'h15 : T14;
  assign T14 = T19 ? 32'h16 : T15;
  assign T15 = T18 ? 32'h17 : T16;
  assign T16 = T17 ? 32'h18 : 32'h0;
  assign T17 = inst_op == 6'h3;
  assign inst_op = inst[5'h1f:5'h1a];
  assign T18 = inst_op == 6'h2;
  assign T19 = inst_op == 6'ha;
  assign T20 = inst_op == 6'h5;
  assign T21 = inst_op == 6'h4;
  assign T22 = inst_op == 6'h2b;
  assign T23 = inst_op == 6'h23;
  assign T24 = inst_op == 6'hf;
  assign T25 = inst_op == 6'he;
  assign T26 = inst_op == 6'hd;
  assign T27 = inst_op == 6'hc;
  assign T28 = inst_op == 6'h9;
  assign T29 = inst_op == 6'h8;
  assign T30 = T51 ? 32'h1 : T31;
  assign T31 = T50 ? 32'h2 : T32;
  assign T32 = T49 ? 32'h3 : T33;
  assign T33 = T48 ? 32'h4 : T34;
  assign T34 = T47 ? 32'h5 : T35;
  assign T35 = T46 ? 32'h6 : T36;
  assign T36 = T45 ? 32'h7 : T37;
  assign T37 = T44 ? 32'h8 : T38;
  assign T38 = T43 ? 32'h9 : T39;
  assign T39 = T42 ? 32'ha : T40;
  assign T40 = T41 ? 32'hb : 32'h0;
  assign T41 = inst_func == 6'h8;
  assign inst_func = inst[3'h5:1'h0];
  assign T42 = inst_func == 6'h6;
  assign T43 = inst_func == 6'h2a;
  assign T44 = inst_func == 6'h27;
  assign T45 = inst_func == 6'h26;
  assign T46 = inst_func == 6'h25;
  assign T47 = inst_func == 6'h24;
  assign T48 = inst_func == 6'h23;
  assign T49 = inst_func == 6'h22;
  assign T50 = inst_func == 6'h21;
  assign T51 = inst_func == 6'h20;
  assign T52 = inst_op == 6'h0;
  assign T53 = state == 32'h0;
  assign io_bus_we = bus_we;
  assign bus_we = inst_we ? 1'h0 : T54;
  assign T54 = T90 ? 1'h0 : T55;
  assign T55 = T89 ? 1'h0 : T56;
  assign T56 = T88 ? 1'h0 : T57;
  assign T57 = T87 ? 1'h0 : T58;
  assign T58 = T86 ? 1'h0 : T59;
  assign T59 = T85 ? 1'h0 : T60;
  assign T60 = T84 ? 1'h0 : T61;
  assign T61 = T83 ? 1'h0 : T62;
  assign T62 = T82 ? 1'h0 : T63;
  assign T63 = T81 ? 1'h0 : T64;
  assign T64 = T80 ? 1'h0 : T65;
  assign T65 = T79 ? 1'h0 : T66;
  assign T66 = T78 ? 1'h0 : T67;
  assign T67 = T77 ? 1'h0 : T68;
  assign T68 = T76 ? 1'h0 : T69;
  assign T69 = T75 ? 1'h0 : T70;
  assign T70 = T74 ? 1'h0 : T71;
  assign T71 = T73 ? 1'h0 : T72;
  assign T72 = state == 32'h13;
  assign T73 = state == 32'h12;
  assign T74 = state == 32'h11;
  assign T75 = state == 32'h10;
  assign T76 = state == 32'hf;
  assign T77 = state == 32'he;
  assign T78 = state == 32'hd;
  assign T79 = state == 32'hc;
  assign T80 = state == 32'hb;
  assign T81 = state == 32'ha;
  assign T82 = state == 32'h9;
  assign T83 = state == 32'h8;
  assign T84 = state == 32'h7;
  assign T85 = state == 32'h6;
  assign T86 = state == 32'h5;
  assign T87 = state == 32'h4;
  assign T88 = state == 32'h3;
  assign T89 = state == 32'h2;
  assign T90 = state == 32'h1;
  assign inst_we = state == 32'h0;
  assign io_bus_sel = bus_sel;
  assign bus_sel = inst_we ? 1'h1 : T91;
  assign T91 = T90 ? 1'h0 : T92;
  assign T92 = T89 ? 1'h0 : T93;
  assign T93 = T88 ? 1'h0 : T94;
  assign T94 = T87 ? 1'h0 : T95;
  assign T95 = T86 ? 1'h0 : T96;
  assign T96 = T85 ? 1'h0 : T97;
  assign T97 = T84 ? 1'h0 : T98;
  assign T98 = T83 ? 1'h0 : T99;
  assign T99 = T82 ? 1'h0 : T100;
  assign T100 = T81 ? 1'h0 : T101;
  assign T101 = T80 ? 1'h0 : T102;
  assign T102 = T79 ? 1'h0 : T103;
  assign T103 = T78 ? 1'h0 : T104;
  assign T104 = T77 ? 1'h0 : T105;
  assign T105 = T76 ? 1'h0 : T106;
  assign T106 = T75 ? 1'h0 : T107;
  assign T107 = T74 ? 1'h0 : T108;
  assign T108 = T73 ? 1'h1 : T72;
  assign io_bus_dat2 = io_ctrl_data_out;
  assign io_bus_addr = T109;
  assign T109 = T130 ? io_ctrl_alu_out : T110;
  assign T110 = T111 ? io_ctrl_pc_out : 32'h0;
  assign T111 = bus_addr_src == 1'h0;
  assign bus_addr_src = inst_we ? 1'h0 : T112;
  assign T112 = T90 ? 1'h0 : T113;
  assign T113 = T89 ? 1'h0 : T114;
  assign T114 = T88 ? 1'h0 : T115;
  assign T115 = T87 ? 1'h0 : T116;
  assign T116 = T86 ? 1'h0 : T117;
  assign T117 = T85 ? 1'h0 : T118;
  assign T118 = T84 ? 1'h0 : T119;
  assign T119 = T83 ? 1'h0 : T120;
  assign T120 = T82 ? 1'h0 : T121;
  assign T121 = T81 ? 1'h0 : T122;
  assign T122 = T80 ? 1'h0 : T123;
  assign T123 = T79 ? 1'h0 : T124;
  assign T124 = T78 ? 1'h0 : T125;
  assign T125 = T77 ? 1'h0 : T126;
  assign T126 = T76 ? 1'h0 : T127;
  assign T127 = T75 ? 1'h0 : T128;
  assign T128 = T74 ? 1'h0 : T129;
  assign T129 = T73 ? 1'h1 : T72;
  assign T130 = bus_addr_src == 1'h1;
  assign io_ctrl_alu_b_sel = alu_b_sel;
  assign alu_b_sel = inst_we ? 2'h0 : T131;
  assign T131 = T90 ? 2'h0 : T132;
  assign T132 = T89 ? 2'h0 : T133;
  assign T133 = T88 ? 2'h0 : T134;
  assign T134 = T87 ? 2'h0 : T135;
  assign T135 = T86 ? 2'h0 : T136;
  assign T136 = T85 ? 2'h0 : T137;
  assign T137 = T84 ? 2'h0 : T138;
  assign T138 = T83 ? 2'h0 : T139;
  assign T139 = T82 ? 2'h0 : T140;
  assign T140 = T81 ? 2'h0 : T141;
  assign T141 = T80 ? 2'h0 : T142;
  assign T142 = T79 ? 2'h1 : T143;
  assign T143 = T78 ? 2'h1 : T144;
  assign T144 = T77 ? 2'h1 : T145;
  assign T145 = T76 ? 2'h1 : T146;
  assign T146 = T75 ? 2'h1 : T147;
  assign T147 = T74 ? 2'h1 : T148;
  assign T148 = T73 ? 2'h1 : T149;
  assign T149 = T72 ? 2'h1 : T150;
  assign T150 = T154 ? 2'h0 : T151;
  assign T151 = T153 ? 2'h2 : T275;
  assign T275 = {1'h0, T152};
  assign T152 = state == 32'h16;
  assign T153 = state == 32'h15;
  assign T154 = state == 32'h14;
  assign io_ctrl_alu_op = alu_op;
  assign alu_op = inst_we ? 3'h0 : T155;
  assign T155 = T90 ? 3'h2 : T156;
  assign T156 = T89 ? 3'h2 : T157;
  assign T157 = T88 ? 3'h6 : T158;
  assign T158 = T87 ? 3'h6 : T159;
  assign T159 = T86 ? 3'h0 : T160;
  assign T160 = T85 ? 3'h1 : T161;
  assign T161 = T84 ? 3'h3 : T162;
  assign T162 = T83 ? 3'h4 : T163;
  assign T163 = T82 ? 3'h7 : T164;
  assign T164 = T81 ? 3'h5 : T165;
  assign T165 = T80 ? 3'h0 : T166;
  assign T166 = T79 ? 3'h2 : T167;
  assign T167 = T78 ? 3'h2 : T168;
  assign T168 = T77 ? 3'h0 : T169;
  assign T169 = T76 ? 3'h1 : T170;
  assign T170 = T75 ? 3'h3 : T171;
  assign T171 = T74 ? 3'h2 : T172;
  assign T172 = T73 ? 3'h2 : T173;
  assign T173 = T72 ? 3'h2 : T174;
  assign T174 = T154 ? 3'h6 : T175;
  assign T175 = T153 ? 3'h6 : T176;
  assign T176 = T152 ? 3'h7 : 3'h0;
  assign io_ctrl_reg_we_dst = reg_we_dst;
  assign reg_we_dst = inst_we ? 2'h0 : T177;
  assign T177 = T90 ? 2'h0 : T178;
  assign T178 = T89 ? 2'h0 : T179;
  assign T179 = T88 ? 2'h0 : T180;
  assign T180 = T87 ? 2'h0 : T181;
  assign T181 = T86 ? 2'h0 : T182;
  assign T182 = T85 ? 2'h0 : T183;
  assign T183 = T84 ? 2'h0 : T184;
  assign T184 = T83 ? 2'h0 : T185;
  assign T185 = T82 ? 2'h0 : T186;
  assign T186 = T81 ? 2'h0 : T187;
  assign T187 = T80 ? 2'h0 : T188;
  assign T188 = T79 ? 2'h1 : T189;
  assign T189 = T78 ? 2'h1 : T190;
  assign T190 = T77 ? 2'h1 : T191;
  assign T191 = T76 ? 2'h1 : T192;
  assign T192 = T75 ? 2'h1 : T193;
  assign T193 = T74 ? 2'h1 : T194;
  assign T194 = T73 ? 2'h1 : T195;
  assign T195 = T72 ? 2'h0 : T196;
  assign T196 = T154 ? 2'h0 : T197;
  assign T197 = T153 ? 2'h0 : T198;
  assign T198 = T152 ? 2'h1 : T199;
  assign T199 = T202 ? 2'h0 : T200;
  assign T200 = T201 ? 2'h2 : 2'h0;
  assign T201 = state == 32'h18;
  assign T202 = state == 32'h17;
  assign io_ctrl_reg_we_src = reg_we_src;
  assign reg_we_src = inst_we ? 2'h0 : T203;
  assign T203 = T90 ? 2'h0 : T204;
  assign T204 = T89 ? 2'h0 : T205;
  assign T205 = T88 ? 2'h0 : T206;
  assign T206 = T87 ? 2'h0 : T207;
  assign T207 = T86 ? 2'h0 : T208;
  assign T208 = T85 ? 2'h0 : T209;
  assign T209 = T84 ? 2'h0 : T210;
  assign T210 = T83 ? 2'h0 : T211;
  assign T211 = T82 ? 2'h0 : T212;
  assign T212 = T81 ? 2'h0 : T213;
  assign T213 = T80 ? 2'h0 : T214;
  assign T214 = T79 ? 2'h0 : T215;
  assign T215 = T78 ? 2'h0 : T216;
  assign T216 = T77 ? 2'h0 : T217;
  assign T217 = T76 ? 2'h0 : T218;
  assign T218 = T75 ? 2'h0 : T219;
  assign T219 = T74 ? 2'h3 : T220;
  assign T220 = T73 ? 2'h1 : T221;
  assign T221 = T72 ? 2'h0 : T222;
  assign T222 = T154 ? 2'h0 : T223;
  assign T223 = T153 ? 2'h0 : T224;
  assign T224 = T152 ? 2'h0 : T225;
  assign T225 = T202 ? 2'h0 : T226;
  assign T226 = T201 ? 2'h2 : 2'h0;
  assign io_ctrl_reg_we = reg_we;
  assign reg_we = inst_we ? 1'h0 : T227;
  assign T227 = T90 ? 1'h1 : T228;
  assign T228 = T89 ? 1'h1 : T229;
  assign T229 = T88 ? 1'h1 : T230;
  assign T230 = T87 ? 1'h1 : T231;
  assign T231 = T86 ? 1'h1 : T232;
  assign T232 = T85 ? 1'h1 : T233;
  assign T233 = T84 ? 1'h1 : T234;
  assign T234 = T83 ? 1'h1 : T235;
  assign T235 = T82 ? 1'h1 : T236;
  assign T236 = T81 ? 1'h1 : T237;
  assign T237 = T80 ? 1'h0 : T238;
  assign T238 = T79 ? 1'h1 : T239;
  assign T239 = T78 ? 1'h1 : T240;
  assign T240 = T77 ? 1'h1 : T241;
  assign T241 = T76 ? 1'h1 : T242;
  assign T242 = T75 ? 1'h1 : T243;
  assign T243 = T74 ? 1'h1 : T244;
  assign T244 = T73 ? 1'h1 : T245;
  assign T245 = T72 ? 1'h0 : T246;
  assign T246 = T154 ? 1'h0 : T247;
  assign T247 = T153 ? 1'h0 : T248;
  assign T248 = T152 ? 1'h1 : T249;
  assign T249 = T202 ? 1'h0 : T201;
  assign io_ctrl_pc_next_sel = pc_next_sel;
  assign pc_next_sel = inst_we ? 2'h0 : T250;
  assign T250 = T90 ? 2'h0 : T251;
  assign T251 = T89 ? 2'h0 : T252;
  assign T252 = T88 ? 2'h0 : T253;
  assign T253 = T87 ? 2'h0 : T254;
  assign T254 = T86 ? 2'h0 : T255;
  assign T255 = T85 ? 2'h0 : T256;
  assign T256 = T84 ? 2'h0 : T257;
  assign T257 = T83 ? 2'h0 : T258;
  assign T258 = T82 ? 2'h0 : T259;
  assign T259 = T81 ? 2'h0 : T260;
  assign T260 = T80 ? 2'h3 : T261;
  assign T261 = T79 ? 2'h0 : T262;
  assign T262 = T78 ? 2'h0 : T263;
  assign T263 = T77 ? 2'h0 : T264;
  assign T264 = T76 ? 2'h0 : T265;
  assign T265 = T75 ? 2'h0 : T266;
  assign T266 = T74 ? 2'h0 : T267;
  assign T267 = T73 ? 2'h0 : T268;
  assign T268 = T72 ? 2'h0 : T269;
  assign T269 = T154 ? 2'h1 : T270;
  assign T270 = T153 ? 2'h1 : T271;
  assign T271 = T152 ? 2'h0 : T272;
  assign T272 = T202 ? 2'h2 : T273;
  assign T273 = T201 ? 2'h2 : 2'h0;
  assign io_ctrl_pc_we = pc_we;
  assign pc_we = inst_we == 1'h0;
  assign io_ctrl_inst_we = inst_we;
  assign io_ctrl_bus_data = io_bus_dat4;

  always @(posedge clk) begin
    if(reset) begin
      state <= 32'h0;
    end else if(io_bus_ack) begin
      state <= next_state;
    end
  end
endmodule

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

module Register_File(input clk, input reset,
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
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire[31:0] T7;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire[31:0] T11;
  wire[31:0] T12;
  wire[31:0] T13;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire[31:0] T17;
  wire[31:0] T18;
  wire[31:0] T19;
  wire[31:0] T20;
  wire[31:0] T21;
  wire[31:0] T22;
  wire[31:0] T23;
  wire[31:0] T24;
  wire[31:0] T25;
  wire[31:0] T26;
  wire[31:0] T27;
  wire[31:0] T28;
  wire[31:0] T29;
  wire[31:0] T30;
  wire[31:0] T31;
  wire[31:0] T32;
  wire[31:0] T33;
  wire T34;
  wire T35;
  wire[31:0] T36;

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
  assign T34 = io_we & T35;
  assign T35 = io_wtaddr != 5'h0;
  assign io_douta = T36;
  assign T36 = rf[io_addra];

  always @(posedge clk) begin
    if (reset)
      rf[5'h1f] <= 32'h0;
    if (reset)
      rf[5'h1e] <= 32'h0;
    if (reset)
      rf[5'h1d] <= 32'h0;
    if (reset)
      rf[5'h1c] <= 32'h0;
    if (reset)
      rf[5'h1b] <= 32'h0;
    if (reset)
      rf[5'h1a] <= 32'h0;
    if (reset)
      rf[5'h19] <= 32'h0;
    if (reset)
      rf[5'h18] <= 32'h0;
    if (reset)
      rf[5'h17] <= 32'h0;
    if (reset)
      rf[5'h16] <= 32'h0;
    if (reset)
      rf[5'h15] <= 32'h0;
    if (reset)
      rf[5'h14] <= 32'h0;
    if (reset)
      rf[5'h13] <= 32'h0;
    if (reset)
      rf[5'h12] <= 32'h0;
    if (reset)
      rf[5'h11] <= 32'h0;
    if (reset)
      rf[5'h10] <= 32'h0;
    if (reset)
      rf[5'hf] <= 32'h0;
    if (reset)
      rf[5'he] <= 32'h0;
    if (reset)
      rf[5'hd] <= 32'h0;
    if (reset)
      rf[5'hc] <= 32'h0;
    if (reset)
      rf[5'hb] <= 32'h0;
    if (reset)
      rf[5'ha] <= 32'h0;
    if (reset)
      rf[5'h9] <= 32'h0;
    if (reset)
      rf[5'h8] <= 32'h0;
    if (reset)
      rf[5'h7] <= 32'h0;
    if (reset)
      rf[5'h6] <= 32'h0;
    if (reset)
      rf[5'h5] <= 32'h0;
    if (reset)
      rf[5'h4] <= 32'h0;
    if (reset)
      rf[5'h3] <= 32'h0;
    if (reset)
      rf[5'h2] <= 32'h0;
    if (reset)
      rf[5'h1] <= 32'h0;
    if (reset)
      rf[5'h0] <= 32'h0;
    if (T34)
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
    input [1:0] io_alu_b_sel,
    output[31:0] io_alu_out,
    output[31:0] io_data_out
);

  wire[31:0] T57;
  wire[47:0] T0;
  wire[47:0] T1;
  wire[47:0] T2;
  wire[47:0] T3;
  wire[47:0] T4;
  wire T5;
  wire[47:0] T58;
  wire[31:0] T6;
  reg [31:0] pc;
  wire[31:0] T59;
  wire[32:0] T60;
  wire[32:0] T7;
  wire[32:0] T61;
  wire[32:0] pc_next;
  wire[32:0] T8;
  wire[32:0] T62;
  wire[31:0] T9;
  wire[31:0] T10;
  wire T11;
  wire[31:0] T63;
  wire[27:0] T12;
  wire[27:0] T13;
  wire[25:0] T14;
  reg [31:0] inst_reg;
  wire[31:0] T64;
  wire[31:0] T15;
  wire[27:0] T65;
  wire[3:0] T16;
  wire T17;
  wire[32:0] T18;
  wire[32:0] T66;
  wire[31:0] T19;
  wire[31:0] T20;
  wire T21;
  wire T22;
  wire T23;
  wire[32:0] T24;
  wire[32:0] T25;
  wire[32:0] T67;
  wire[17:0] T26;
  wire[17:0] T27;
  wire[15:0] T28;
  wire[14:0] T68;
  wire T69;
  wire[32:0] T29;
  wire[32:0] T30;
  wire[32:0] T31;
  wire T32;
  wire T33;
  wire T34;
  wire[32:0] T70;
  wire[31:0] T35;
  wire T36;
  wire T37;
  wire[47:0] T71;
  wire T38;
  wire[47:0] T72;
  wire T39;
  wire[4:0] T40;
  wire[4:0] T41;
  wire[4:0] T42;
  wire T43;
  wire[4:0] T44;
  wire T45;
  wire[4:0] T46;
  wire T47;
  wire[4:0] T48;
  wire[4:0] T49;
  wire[31:0] T50;
  wire[31:0] T51;
  wire[31:0] T52;
  wire T53;
  wire[31:0] T73;
  wire[15:0] T54;
  wire T55;
  wire T56;
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

  assign T57 = T0[5'h1f:1'h0];
  assign T0 = T39 ? T72 : T1;
  assign T1 = T38 ? T71 : T2;
  assign T2 = T37 ? T58 : T3;
  assign T3 = T5 ? T4 : 48'h0;
  assign T4 = alu_io_out << 5'h10;
  assign T5 = io_reg_we_src == 2'h3;
  assign T58 = {16'h0, T6};
  assign T6 = pc + 32'h4;
  assign T59 = T60[5'h1f:1'h0];
  assign T60 = reset ? 33'h0 : T7;
  assign T7 = io_pc_we ? pc_next : T61;
  assign T61 = {1'h0, pc};
  assign pc_next = T36 ? T70 : T8;
  assign T8 = T34 ? T18 : T62;
  assign T62 = {1'h0, T9};
  assign T9 = T17 ? T63 : T10;
  assign T10 = T11 ? regfile_io_douta : 32'h0;
  assign T11 = io_pc_next_sel == 2'h3;
  assign T63 = {4'h0, T12};
  assign T12 = T65 | T13;
  assign T13 = T14 << 2'h2;
  assign T14 = inst_reg[5'h19:1'h0];
  assign T64 = reset ? 32'h0 : T15;
  assign T15 = io_inst_we ? io_bus_data : inst_reg;
  assign T65 = {24'h0, T16};
  assign T16 = pc[5'h1f:5'h1c];
  assign T17 = io_pc_next_sel == 2'h2;
  assign T18 = T32 ? T24 : T66;
  assign T66 = {1'h0, T19};
  assign T19 = T21 ? T20 : 32'h0;
  assign T20 = pc + 32'h4;
  assign T21 = ~ T22;
  assign T22 = alu_io_zero ^ T23;
  assign T23 = io_alu_b_sel == 2'h2;
  assign T24 = T25;
  assign T25 = T29 + T67;
  assign T67 = {T68, T26};
  assign T26 = T27;
  assign T27 = T28 << 2'h2;
  assign T28 = inst_reg[4'hf:1'h0];
  assign T68 = T69 ? 15'h7fff : 15'h0;
  assign T69 = T26[5'h11:5'h11];
  assign T29 = 33'h4 + T30;
  assign T30 = T31;
  assign T31 = {1'h0, pc};
  assign T32 = alu_io_zero ^ T33;
  assign T33 = io_alu_b_sel == 2'h2;
  assign T34 = io_pc_next_sel == 2'h1;
  assign T70 = {1'h0, T35};
  assign T35 = pc + 32'h4;
  assign T36 = io_pc_next_sel == 2'h0;
  assign T37 = io_reg_we_src == 2'h2;
  assign T71 = {16'h0, io_bus_data};
  assign T38 = io_reg_we_src == 2'h1;
  assign T72 = {16'h0, alu_io_out};
  assign T39 = io_reg_we_src == 2'h0;
  assign T40 = T47 ? T46 : T41;
  assign T41 = T45 ? T44 : T42;
  assign T42 = T43 ? 5'h1f : 5'h0;
  assign T43 = io_reg_we_dst == 2'h2;
  assign T44 = inst_reg[5'h14:5'h10];
  assign T45 = io_reg_we_dst == 2'h1;
  assign T46 = inst_reg[4'hf:4'hb];
  assign T47 = io_reg_we_dst == 2'h0;
  assign T48 = inst_reg[5'h14:5'h10];
  assign T49 = inst_reg[5'h19:5'h15];
  assign T50 = T56 ? regfile_io_doutb : T51;
  assign T51 = T55 ? T73 : T52;
  assign T52 = T53 ? regfile_io_doutb : 32'h0;
  assign T53 = io_alu_b_sel == 2'h2;
  assign T73 = {16'h0, T54};
  assign T54 = inst_reg[4'hf:1'h0];
  assign T55 = io_alu_b_sel == 2'h1;
  assign T56 = io_alu_b_sel == 2'h0;
  assign io_data_out = regfile_io_doutb;
  assign io_alu_out = alu_io_out;
  assign io_pc_out = pc;
  assign io_inst = inst_reg;
  ALU alu(
       .io_alu_op( io_alu_op ),
       .io_in_a( regfile_io_douta ),
       .io_in_b( T50 ),
       .io_out( alu_io_out ),
       .io_zero( alu_io_zero )
  );
  Register_File regfile(.clk(clk), .reset(reset),
       .io_addra( T49 ),
       .io_douta( regfile_io_douta ),
       .io_addrb( T48 ),
       .io_doutb( regfile_io_doutb ),
       .io_wtaddr( T40 ),
       .io_wtdata( T57 ),
       .io_we( io_reg_we )
  );

  always @(posedge clk) begin
    pc <= T59;
    if(reset) begin
      inst_reg <= 32'h0;
    end else if(io_inst_we) begin
      inst_reg <= io_bus_data;
    end
  end
endmodule

module Core(input clk, input reset,
    output[31:0] io_bus_addr,
    output[31:0] io_bus_dat2,
    input [31:0] io_bus_dat4,
    output io_bus_sel,
    output io_bus_we,
    input  io_bus_ack,
    output[31:0] io_debug_inst_out,
    output[31:0] io_debug_bus_addr,
    output[31:0] io_debug_bus_dat2,
    output[31:0] io_debug_bus_dat4,
    output[31:0] io_debug_pc_out
);

  wire[31:0] cpath_io_ctrl_bus_data;
  wire cpath_io_ctrl_inst_we;
  wire cpath_io_ctrl_pc_we;
  wire[1:0] cpath_io_ctrl_pc_next_sel;
  wire cpath_io_ctrl_reg_we;
  wire[1:0] cpath_io_ctrl_reg_we_src;
  wire[1:0] cpath_io_ctrl_reg_we_dst;
  wire[2:0] cpath_io_ctrl_alu_op;
  wire[1:0] cpath_io_ctrl_alu_b_sel;
  wire[31:0] cpath_io_bus_addr;
  wire[31:0] cpath_io_bus_dat2;
  wire cpath_io_bus_sel;
  wire cpath_io_bus_we;
  wire[31:0] cpath_io_debug_inst_out;
  wire[31:0] cpath_io_debug_bus_addr;
  wire[31:0] cpath_io_debug_bus_dat2;
  wire[31:0] cpath_io_debug_bus_dat4;
  wire[31:0] cpath_io_debug_pc_out;
  wire[31:0] dpath_io_inst;
  wire[31:0] dpath_io_pc_out;
  wire[31:0] dpath_io_alu_out;
  wire[31:0] dpath_io_data_out;


  assign io_debug_pc_out = cpath_io_debug_pc_out;
  assign io_debug_bus_dat4 = cpath_io_debug_bus_dat4;
  assign io_debug_bus_dat2 = cpath_io_debug_bus_dat2;
  assign io_debug_bus_addr = cpath_io_debug_bus_addr;
  assign io_debug_inst_out = cpath_io_debug_inst_out;
  assign io_bus_we = cpath_io_bus_we;
  assign io_bus_sel = cpath_io_bus_sel;
  assign io_bus_dat2 = cpath_io_bus_dat2;
  assign io_bus_addr = cpath_io_bus_addr;
  Ctrlpath cpath(.clk(clk), .reset(reset),
       .io_ctrl_bus_data( cpath_io_ctrl_bus_data ),
       .io_ctrl_inst( dpath_io_inst ),
       .io_ctrl_inst_we( cpath_io_ctrl_inst_we ),
       .io_ctrl_pc_we( cpath_io_ctrl_pc_we ),
       .io_ctrl_pc_next_sel( cpath_io_ctrl_pc_next_sel ),
       .io_ctrl_pc_out( dpath_io_pc_out ),
       .io_ctrl_reg_we( cpath_io_ctrl_reg_we ),
       .io_ctrl_reg_we_src( cpath_io_ctrl_reg_we_src ),
       .io_ctrl_reg_we_dst( cpath_io_ctrl_reg_we_dst ),
       .io_ctrl_alu_op( cpath_io_ctrl_alu_op ),
       .io_ctrl_alu_b_sel( cpath_io_ctrl_alu_b_sel ),
       .io_ctrl_alu_out( dpath_io_alu_out ),
       .io_ctrl_data_out( dpath_io_data_out ),
       .io_bus_addr( cpath_io_bus_addr ),
       .io_bus_dat2( cpath_io_bus_dat2 ),
       .io_bus_dat4( io_bus_dat4 ),
       .io_bus_sel( cpath_io_bus_sel ),
       .io_bus_we( cpath_io_bus_we ),
       .io_bus_ack( io_bus_ack ),
       .io_debug_inst_out( cpath_io_debug_inst_out ),
       .io_debug_bus_addr( cpath_io_debug_bus_addr ),
       .io_debug_bus_dat2( cpath_io_debug_bus_dat2 ),
       .io_debug_bus_dat4( cpath_io_debug_bus_dat4 ),
       .io_debug_pc_out( cpath_io_debug_pc_out )
  );
  Datapath dpath(.clk(clk), .reset(reset),
       .io_bus_data( cpath_io_ctrl_bus_data ),
       .io_inst( dpath_io_inst ),
       .io_inst_we( cpath_io_ctrl_inst_we ),
       .io_pc_we( cpath_io_ctrl_pc_we ),
       .io_pc_next_sel( cpath_io_ctrl_pc_next_sel ),
       .io_pc_out( dpath_io_pc_out ),
       .io_reg_we( cpath_io_ctrl_reg_we ),
       .io_reg_we_src( cpath_io_ctrl_reg_we_src ),
       .io_reg_we_dst( cpath_io_ctrl_reg_we_dst ),
       .io_alu_op( cpath_io_ctrl_alu_op ),
       .io_alu_b_sel( cpath_io_ctrl_alu_b_sel ),
       .io_alu_out( dpath_io_alu_out ),
       .io_data_out( dpath_io_data_out )
  );
endmodule

module WB_Bus(
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
  wire ram_op;
  wire T1;
  wire T2;
  wire[31:0] T116;
  wire[27:0] T3;
  wire T4;
  wire T5;
  wire[2:0] current_slave;
  wire T6;
  wire T7;
  wire T8;
  wire T9;
  wire T10;
  wire T11;
  wire[31:0] T117;
  wire[27:0] T12;
  wire T13;
  wire T14;
  wire T15;
  wire T16;
  wire T17;
  wire T18;
  wire T19;
  wire T20;
  wire[31:0] T118;
  wire[27:0] T21;
  wire T22;
  wire T23;
  wire T24;
  wire T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire[31:0] T119;
  wire[27:0] T30;
  wire T31;
  wire T32;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire T37;
  wire T38;
  wire[31:0] T120;
  wire[27:0] T39;
  wire T40;
  wire T41;
  wire T42;
  wire T43;
  wire T44;
  wire T45;
  wire T46;
  wire T47;
  wire[31:0] T121;
  wire[27:0] T48;
  wire T49;
  wire T50;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire T55;
  wire T56;
  wire[31:0] T122;
  wire[27:0] T57;
  wire T58;
  wire T59;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire[31:0] T123;
  wire[27:0] T66;
  wire T67;
  wire T68;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire T73;
  wire T74;
  wire[31:0] T124;
  wire[27:0] T75;
  wire T76;
  wire T77;
  wire T78;
  wire T79;
  wire T80;
  wire T81;
  wire T82;
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
  wire[31:0] T96;
  wire[31:0] T97;
  wire T98;
  wire[31:0] T99;
  wire[31:0] T100;
  wire[31:0] T101;
  wire[31:0] T102;
  wire[31:0] T103;
  wire[31:0] T104;
  wire[31:0] T105;
  wire[31:0] T106;
  wire T107;
  wire T108;
  wire T109;
  wire T110;
  wire T111;
  wire T112;
  wire T113;
  wire T114;
  wire T115;


  assign io_ram_slave_we = T0;
  assign T0 = ram_op & io_from_cpu_we;
  assign ram_op = ~ T1;
  assign T1 = io_from_cpu_addr[5'h1f:5'h1f];
  assign io_ram_slave_sel = T2;
  assign T2 = ram_op & io_from_cpu_sel;
  assign io_ram_slave_dat2 = io_from_cpu_dat2;
  assign io_ram_slave_addr = T116;
  assign T116 = {4'h0, T3};
  assign T3 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_0_we = T4;
  assign T4 = T6 & T5;
  assign T5 = current_slave == 3'h0;
  assign current_slave = io_from_cpu_addr[5'h1e:5'h1c];
  assign T6 = T7 & io_from_cpu_we;
  assign T7 = ~ ram_op;
  assign io_slaves_0_sel = T8;
  assign T8 = T10 & T9;
  assign T9 = current_slave == 3'h0;
  assign T10 = T11 & io_from_cpu_sel;
  assign T11 = ~ ram_op;
  assign io_slaves_0_dat2 = io_from_cpu_dat2;
  assign io_slaves_0_addr = T117;
  assign T117 = {4'h0, T12};
  assign T12 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_1_we = T13;
  assign T13 = T15 & T14;
  assign T14 = current_slave == 3'h1;
  assign T15 = T16 & io_from_cpu_we;
  assign T16 = ~ ram_op;
  assign io_slaves_1_sel = T17;
  assign T17 = T19 & T18;
  assign T18 = current_slave == 3'h1;
  assign T19 = T20 & io_from_cpu_sel;
  assign T20 = ~ ram_op;
  assign io_slaves_1_dat2 = io_from_cpu_dat2;
  assign io_slaves_1_addr = T118;
  assign T118 = {4'h0, T21};
  assign T21 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_2_we = T22;
  assign T22 = T24 & T23;
  assign T23 = current_slave == 3'h2;
  assign T24 = T25 & io_from_cpu_we;
  assign T25 = ~ ram_op;
  assign io_slaves_2_sel = T26;
  assign T26 = T28 & T27;
  assign T27 = current_slave == 3'h2;
  assign T28 = T29 & io_from_cpu_sel;
  assign T29 = ~ ram_op;
  assign io_slaves_2_dat2 = io_from_cpu_dat2;
  assign io_slaves_2_addr = T119;
  assign T119 = {4'h0, T30};
  assign T30 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_3_we = T31;
  assign T31 = T33 & T32;
  assign T32 = current_slave == 3'h3;
  assign T33 = T34 & io_from_cpu_we;
  assign T34 = ~ ram_op;
  assign io_slaves_3_sel = T35;
  assign T35 = T37 & T36;
  assign T36 = current_slave == 3'h3;
  assign T37 = T38 & io_from_cpu_sel;
  assign T38 = ~ ram_op;
  assign io_slaves_3_dat2 = io_from_cpu_dat2;
  assign io_slaves_3_addr = T120;
  assign T120 = {4'h0, T39};
  assign T39 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_4_we = T40;
  assign T40 = T42 & T41;
  assign T41 = current_slave == 3'h4;
  assign T42 = T43 & io_from_cpu_we;
  assign T43 = ~ ram_op;
  assign io_slaves_4_sel = T44;
  assign T44 = T46 & T45;
  assign T45 = current_slave == 3'h4;
  assign T46 = T47 & io_from_cpu_sel;
  assign T47 = ~ ram_op;
  assign io_slaves_4_dat2 = io_from_cpu_dat2;
  assign io_slaves_4_addr = T121;
  assign T121 = {4'h0, T48};
  assign T48 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_5_we = T49;
  assign T49 = T51 & T50;
  assign T50 = current_slave == 3'h5;
  assign T51 = T52 & io_from_cpu_we;
  assign T52 = ~ ram_op;
  assign io_slaves_5_sel = T53;
  assign T53 = T55 & T54;
  assign T54 = current_slave == 3'h5;
  assign T55 = T56 & io_from_cpu_sel;
  assign T56 = ~ ram_op;
  assign io_slaves_5_dat2 = io_from_cpu_dat2;
  assign io_slaves_5_addr = T122;
  assign T122 = {4'h0, T57};
  assign T57 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_6_we = T58;
  assign T58 = T60 & T59;
  assign T59 = current_slave == 3'h6;
  assign T60 = T61 & io_from_cpu_we;
  assign T61 = ~ ram_op;
  assign io_slaves_6_sel = T62;
  assign T62 = T64 & T63;
  assign T63 = current_slave == 3'h6;
  assign T64 = T65 & io_from_cpu_sel;
  assign T65 = ~ ram_op;
  assign io_slaves_6_dat2 = io_from_cpu_dat2;
  assign io_slaves_6_addr = T123;
  assign T123 = {4'h0, T66};
  assign T66 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_7_we = T67;
  assign T67 = T69 & T68;
  assign T68 = current_slave == 3'h7;
  assign T69 = T70 & io_from_cpu_we;
  assign T70 = ~ ram_op;
  assign io_slaves_7_sel = T71;
  assign T71 = T73 & T72;
  assign T72 = current_slave == 3'h7;
  assign T73 = T74 & io_from_cpu_sel;
  assign T74 = ~ ram_op;
  assign io_slaves_7_dat2 = io_from_cpu_dat2;
  assign io_slaves_7_addr = T124;
  assign T124 = {4'h0, T75};
  assign T75 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_from_cpu_ack = T76;
  assign T76 = T95 ? T79 : T77;
  assign T77 = T78 ? io_ram_slave_ack : 1'h0;
  assign T78 = ram_op == 1'h1;
  assign T79 = T94 ? io_slaves_0_ack : T80;
  assign T80 = T93 ? io_slaves_1_ack : T81;
  assign T81 = T92 ? io_slaves_2_ack : T82;
  assign T82 = T91 ? io_slaves_3_ack : T83;
  assign T83 = T90 ? io_slaves_4_ack : T84;
  assign T84 = T89 ? io_slaves_5_ack : T85;
  assign T85 = T88 ? io_slaves_6_ack : T86;
  assign T86 = T87 ? io_slaves_7_ack : 1'h0;
  assign T87 = current_slave == 3'h7;
  assign T88 = current_slave == 3'h6;
  assign T89 = current_slave == 3'h5;
  assign T90 = current_slave == 3'h4;
  assign T91 = current_slave == 3'h3;
  assign T92 = current_slave == 3'h2;
  assign T93 = current_slave == 3'h1;
  assign T94 = current_slave == 3'h0;
  assign T95 = ram_op == 1'h0;
  assign io_from_cpu_dat4 = T96;
  assign T96 = T115 ? T99 : T97;
  assign T97 = T98 ? io_ram_slave_dat4 : 32'h0;
  assign T98 = ram_op == 1'h1;
  assign T99 = T114 ? io_slaves_0_dat4 : T100;
  assign T100 = T113 ? io_slaves_1_dat4 : T101;
  assign T101 = T112 ? io_slaves_2_dat4 : T102;
  assign T102 = T111 ? io_slaves_3_dat4 : T103;
  assign T103 = T110 ? io_slaves_4_dat4 : T104;
  assign T104 = T109 ? io_slaves_5_dat4 : T105;
  assign T105 = T108 ? io_slaves_6_dat4 : T106;
  assign T106 = T107 ? io_slaves_7_dat4 : 32'h0;
  assign T107 = current_slave == 3'h7;
  assign T108 = current_slave == 3'h6;
  assign T109 = current_slave == 3'h5;
  assign T110 = current_slave == 3'h4;
  assign T111 = current_slave == 3'h3;
  assign T112 = current_slave == 3'h2;
  assign T113 = current_slave == 3'h1;
  assign T114 = current_slave == 3'h0;
  assign T115 = ram_op == 1'h0;
endmodule

module WB_Sw_Dev(
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    input [7:0] io_SW
);

  wire[31:0] T0;


  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T0;
  assign T0 = {24'h0, io_SW};
endmodule

module WB_Button_Dev(
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    input [4:0] io_BTN
);

  wire[31:0] T0;


  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T0;
  assign T0 = {27'h0, io_BTN};
endmodule

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
  wire[7:0] T2;
  wire[31:0] T3;
  wire[31:0] T0;
  wire[31:0] T4;
  wire T1;
  wire[31:0] T5;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    led_data = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_LED = led_data;
  assign T2 = T3[3'h7:1'h0];
  assign T3 = reset ? 32'h0 : T0;
  assign T0 = T1 ? io_bus_dat2 : T4;
  assign T4 = {24'h0, led_data};
  assign T1 = io_bus_sel & io_bus_we;
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T5;
  assign T5 = {24'h0, led_data};

  always @(posedge clk) begin
    led_data <= T2;
  end
endmodule

module WB_Counter_Dev(input clk, input reset,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack
);

  reg [31:0] counter;
  wire[31:0] T1;
  wire[31:0] counter_next;
  wire[31:0] T0;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    counter = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = counter;
  assign T1 = reset ? 32'h0 : counter_next;
  assign counter_next = T0;
  assign T0 = counter + 32'h1;

  always @(posedge clk) begin
    if(reset) begin
      counter <= 32'h0;
    end else begin
      counter <= counter_next;
    end
  end
endmodule

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

module WB_Ram_Dev(
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    output[9:0] io_ram_addra,
    output[31:0] io_ram_dina,
    output io_ram_we,
    input [31:0] io_ram_douta
);

  wire T0;
  wire[9:0] T1;
  wire[31:0] T2;
  wire[31:0] T3;
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T14;
  wire[7:0] T6;
  wire T7;
  wire[1:0] T8;
  wire[31:0] T15;
  wire[15:0] T9;
  wire T10;
  wire[31:0] T16;
  wire[23:0] T11;
  wire T12;
  wire T13;


  assign io_ram_we = T0;
  assign T0 = io_bus_sel & io_bus_we;
  assign io_ram_dina = io_bus_dat2;
  assign io_ram_addra = T1;
  assign T1 = io_bus_addr[4'hb:2'h2];
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T2;
  assign T2 = T13 ? io_ram_douta : T3;
  assign T3 = T12 ? T16 : T4;
  assign T4 = T10 ? T15 : T5;
  assign T5 = T7 ? T14 : io_ram_douta;
  assign T14 = {24'h0, T6};
  assign T6 = io_ram_douta[5'h1f:5'h18];
  assign T7 = T8 == 2'h3;
  assign T8 = io_bus_addr[1'h1:1'h0];
  assign T15 = {16'h0, T9};
  assign T9 = io_ram_douta[5'h1f:5'h10];
  assign T10 = T8 == 2'h2;
  assign T16 = {8'h0, T11};
  assign T11 = io_ram_douta[5'h1f:4'h8];
  assign T12 = T8 == 2'h1;
  assign T13 = T8 == 2'h0;
endmodule

module VGA_Ctrl(input clk, input reset,
    output[2:0] io_vga_red,
    output[2:0] io_vga_green,
    output[1:0] io_vga_blue,
    output io_vga_hsync,
    output io_vga_vsync,
    output[31:0] io_ctrl_x,
    output[31:0] io_ctrl_y,
    input [7:0] io_ctrl_color
);

  wire[31:0] T0;
  wire[31:0] T1;
  reg [31:0] v_counter;
  wire[31:0] T80;
  wire[31:0] T2;
  wire[31:0] T3;
  wire T4;
  wire T5;
  wire T6;
  wire T7;
  reg [31:0] h_counter;
  wire[31:0] T81;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire T11;
  wire T12;
  wire T13;
  reg [1:0] p_counter;
  wire[1:0] T82;
  wire[1:0] T14;
  wire[1:0] T15;
  wire T16;
  wire T17;
  wire[31:0] T18;
  wire T19;
  wire T20;
  wire T21;
  wire[1:0] v_state;
  wire[1:0] T22;
  wire[1:0] T23;
  wire[1:0] T24;
  wire T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire T30;
  wire T31;
  wire T32;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire[31:0] T37;
  wire[31:0] T38;
  wire T39;
  wire[1:0] h_state;
  wire[1:0] T40;
  wire[1:0] T41;
  wire[1:0] T42;
  wire T43;
  wire T44;
  wire T45;
  wire T46;
  wire T47;
  wire T48;
  wire T49;
  wire T50;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire T55;
  wire T56;
  wire T57;
  wire T58;
  wire T59;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire T66;
  wire T67;
  wire T68;
  wire[1:0] T69;
  wire[1:0] T70;
  wire T71;
  wire output_en;
  wire T72;
  wire T73;
  wire[2:0] T74;
  wire[2:0] T75;
  wire T76;
  wire[2:0] T77;
  wire[2:0] T78;
  wire T79;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    v_counter = {1{$random}};
    h_counter = {1{$random}};
    p_counter = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_ctrl_y = T0;
  assign T0 = T21 ? T1 : 32'h0;
  assign T1 = v_counter - 32'h1f;
  assign T80 = reset ? 32'h0 : T2;
  assign T2 = T19 ? T18 : T3;
  assign T3 = T4 ? 32'h0 : v_counter;
  assign T4 = T6 & T5;
  assign T5 = v_counter == 32'h208;
  assign T6 = T13 & T7;
  assign T7 = h_counter == 32'h31f;
  assign T81 = reset ? 32'h0 : T8;
  assign T8 = T11 ? T10 : T9;
  assign T9 = T6 ? 32'h0 : h_counter;
  assign T10 = h_counter + 32'h1;
  assign T11 = T13 & T12;
  assign T12 = T7 ^ 1'h1;
  assign T13 = p_counter == 2'h0;
  assign T82 = reset ? 2'h0 : T14;
  assign T14 = T16 ? T15 : 2'h0;
  assign T15 = p_counter + 2'h1;
  assign T16 = T17 ^ 1'h1;
  assign T17 = p_counter == 2'h3;
  assign T18 = v_counter + 32'h1;
  assign T19 = T6 & T20;
  assign T20 = T5 ^ 1'h1;
  assign T21 = v_state == 2'h2;
  assign v_state = T34 ? 2'h0 : T22;
  assign T22 = T31 ? 2'h1 : T23;
  assign T23 = T28 ? 2'h2 : T24;
  assign T24 = T25 ? 2'h3 : 2'h0;
  assign T25 = T27 & T26;
  assign T26 = v_counter < 32'h209;
  assign T27 = 32'h1ff <= v_counter;
  assign T28 = T30 & T29;
  assign T29 = v_counter < 32'h1ff;
  assign T30 = 32'h1f <= v_counter;
  assign T31 = T33 & T32;
  assign T32 = v_counter < 32'h1f;
  assign T33 = 32'h2 <= v_counter;
  assign T34 = T36 & T35;
  assign T35 = v_counter < 32'h2;
  assign T36 = 32'h0 <= v_counter;
  assign io_ctrl_x = T37;
  assign T37 = T39 ? T38 : 32'h0;
  assign T38 = h_counter - 32'h90;
  assign T39 = h_state == 2'h2;
  assign h_state = T52 ? 2'h0 : T40;
  assign T40 = T49 ? 2'h1 : T41;
  assign T41 = T46 ? 2'h2 : T42;
  assign T42 = T43 ? 2'h3 : 2'h0;
  assign T43 = T45 & T44;
  assign T44 = h_counter < 32'h320;
  assign T45 = 32'h310 <= h_counter;
  assign T46 = T48 & T47;
  assign T47 = h_counter < 32'h310;
  assign T48 = 32'h90 <= h_counter;
  assign T49 = T51 & T50;
  assign T50 = h_counter < 32'h90;
  assign T51 = 32'h60 <= h_counter;
  assign T52 = T54 & T53;
  assign T53 = h_counter < 32'h60;
  assign T54 = 32'h0 <= h_counter;
  assign io_vga_vsync = T55;
  assign T55 = T61 ? 1'h0 : T56;
  assign T56 = T60 ? 1'h1 : T57;
  assign T57 = T59 ? 1'h1 : T58;
  assign T58 = v_state == 2'h3;
  assign T59 = v_state == 2'h2;
  assign T60 = v_state == 2'h1;
  assign T61 = v_state == 2'h0;
  assign io_vga_hsync = T62;
  assign T62 = T68 ? 1'h0 : T63;
  assign T63 = T67 ? 1'h1 : T64;
  assign T64 = T66 ? 1'h1 : T65;
  assign T65 = h_state == 2'h3;
  assign T66 = h_state == 2'h2;
  assign T67 = h_state == 2'h1;
  assign T68 = h_state == 2'h0;
  assign io_vga_blue = T69;
  assign T69 = T71 ? T70 : 2'h0;
  assign T70 = io_ctrl_color[1'h1:1'h0];
  assign T71 = output_en == 1'h1;
  assign output_en = T73 & T72;
  assign T72 = v_state == 2'h2;
  assign T73 = h_state == 2'h2;
  assign io_vga_green = T74;
  assign T74 = T76 ? T75 : 3'h0;
  assign T75 = io_ctrl_color[3'h4:2'h2];
  assign T76 = output_en == 1'h1;
  assign io_vga_red = T77;
  assign T77 = T79 ? T78 : 3'h0;
  assign T78 = io_ctrl_color[3'h7:3'h5];
  assign T79 = output_en == 1'h1;

  always @(posedge clk) begin
    if(reset) begin
      v_counter <= 32'h0;
    end else if(T19) begin
      v_counter <= T18;
    end else if(T4) begin
      v_counter <= 32'h0;
    end
    if(reset) begin
      h_counter <= 32'h0;
    end else if(T11) begin
      h_counter <= T10;
    end else if(T6) begin
      h_counter <= 32'h0;
    end
    if(reset) begin
      p_counter <= 2'h0;
    end else if(T16) begin
      p_counter <= T15;
    end else begin
      p_counter <= 2'h0;
    end
  end
endmodule

module WB_VGA_Dev(input clk, input reset,
    output[2:0] io_vga_red,
    output[2:0] io_vga_green,
    output[1:0] io_vga_blue,
    output io_vga_hsync,
    output io_vga_vsync,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack
);

  wire[11:0] T0;
  wire[11:0] T62;
  wire[3:0] T1;
  wire[11:0] T2;
  wire[7:0] char;
  wire[15:0] data;
  reg [15:0] vmem [2399:0];
  wire[15:0] T3;
  wire[15:0] T63;
  wire T4;
  wire T5;
  wire[11:0] T6;
  wire T7;
  wire[11:0] T8;
  wire[11:0] T64;
  wire[34:0] T9;
  wire[34:0] T65;
  wire[28:0] T10;
  wire[34:0] T11;
  wire[27:0] T12;
  wire[7:0] T13;
  wire[7:0] T14;
  wire[7:0] front_color;
  wire T15;
  wire[7:0] color;
  wire[6:0] T16;
  wire T17;
  wire[5:0] T18;
  wire T19;
  wire[4:0] T20;
  wire T21;
  wire[3:0] T22;
  wire T23;
  wire[2:0] T24;
  wire T25;
  wire[1:0] T26;
  wire T27;
  wire T28;
  wire T29;
  wire T30;
  wire T31;
  wire T32;
  wire[2:0] T33;
  wire[2:0] T34;
  wire[2:0] T35;
  wire[2:0] T36;
  wire T37;
  wire[7:0] back_color;
  wire T38;
  wire[6:0] T39;
  wire T40;
  wire[5:0] T41;
  wire T42;
  wire[4:0] T43;
  wire T44;
  wire[3:0] T45;
  wire T46;
  wire[2:0] T47;
  wire T48;
  wire[1:0] T49;
  wire T50;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire T55;
  wire[2:0] T56;
  wire[2:0] T57;
  wire[2:0] T58;
  wire[2:0] T59;
  wire T60;
  wire[31:0] T66;
  wire[15:0] T61;
  wire[11:0] T67;
  wire[2:0] vga_io_vga_red;
  wire[2:0] vga_io_vga_green;
  wire[1:0] vga_io_vga_blue;
  wire vga_io_vga_hsync;
  wire vga_io_vga_vsync;
  wire[31:0] vga_io_ctrl_x;
  wire[31:0] vga_io_ctrl_y;
  wire[7:0] font_io_data;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    for (initvar = 0; initvar < 2400; initvar = initvar+1)
      vmem[initvar] = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = T2 + T62;
  assign T62 = {8'h0, T1};
  assign T1 = vga_io_ctrl_y[2'h3:1'h0];
  assign T2 = char << 3'h4;
  assign char = data[3'h7:1'h0];
  assign data = vmem[T64];
  assign T63 = io_bus_dat2[4'hf:1'h0];
  assign T4 = T7 & T5;
  assign T5 = T6 < 12'h960;
  assign T6 = T8[4'hb:1'h0];
  assign T7 = io_bus_sel & io_bus_we;
  assign T8 = io_bus_addr[4'hb:1'h0];
  assign T64 = T9[4'hb:1'h0];
  assign T9 = T11 + T65;
  assign T65 = {6'h0, T10};
  assign T10 = vga_io_ctrl_x[5'h1f:2'h3];
  assign T11 = T12 * 7'h50;
  assign T12 = vga_io_ctrl_y[5'h1f:3'h4];
  assign T13 = T52 ? back_color : T14;
  assign T14 = T29 ? front_color : 8'h0;
  assign front_color = {T16, T15};
  assign T15 = color[1'h0:1'h0];
  assign color = data[4'hf:4'h8];
  assign T16 = {T18, T17};
  assign T17 = color[1'h0:1'h0];
  assign T18 = {T20, T19};
  assign T19 = color[1'h1:1'h1];
  assign T20 = {T22, T21};
  assign T21 = color[1'h1:1'h1];
  assign T22 = {T24, T23};
  assign T23 = color[1'h1:1'h1];
  assign T24 = {T26, T25};
  assign T25 = color[2'h2:2'h2];
  assign T26 = {T28, T27};
  assign T27 = color[2'h2:2'h2];
  assign T28 = color[2'h2:2'h2];
  assign T29 = T30 == 1'h1;
  assign T30 = T37 & T31;
  assign T31 = T32 - 1'h1;
  assign T32 = 1'h1 << T33;
  assign T33 = T34 + 3'h1;
  assign T34 = T35 - T35;
  assign T35 = 3'h7 - T36;
  assign T36 = vga_io_ctrl_x[2'h2:1'h0];
  assign T37 = font_io_data >> T35;
  assign back_color = {T39, T38};
  assign T38 = color[3'h4:3'h4];
  assign T39 = {T41, T40};
  assign T40 = color[3'h4:3'h4];
  assign T41 = {T43, T42};
  assign T42 = color[3'h5:3'h5];
  assign T43 = {T45, T44};
  assign T44 = color[3'h5:3'h5];
  assign T45 = {T47, T46};
  assign T46 = color[3'h5:3'h5];
  assign T47 = {T49, T48};
  assign T48 = color[3'h6:3'h6];
  assign T49 = {T51, T50};
  assign T50 = color[3'h6:3'h6];
  assign T51 = color[3'h6:3'h6];
  assign T52 = T53 == 1'h0;
  assign T53 = T60 & T54;
  assign T54 = T55 - 1'h1;
  assign T55 = 1'h1 << T56;
  assign T56 = T57 + 3'h1;
  assign T57 = T58 - T58;
  assign T58 = 3'h7 - T59;
  assign T59 = vga_io_ctrl_x[2'h2:1'h0];
  assign T60 = font_io_data >> T58;
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T66;
  assign T66 = {16'h0, T61};
  assign T61 = vmem[T67];
  assign T67 = io_bus_addr[4'hb:1'h0];
  assign io_vga_vsync = vga_io_vga_vsync;
  assign io_vga_hsync = vga_io_vga_hsync;
  assign io_vga_blue = vga_io_vga_blue;
  assign io_vga_green = vga_io_vga_green;
  assign io_vga_red = vga_io_vga_red;
  VGA_Ctrl vga(.clk(clk), .reset(reset),
       .io_vga_red( vga_io_vga_red ),
       .io_vga_green( vga_io_vga_green ),
       .io_vga_blue( vga_io_vga_blue ),
       .io_vga_hsync( vga_io_vga_hsync ),
       .io_vga_vsync( vga_io_vga_vsync ),
       .io_ctrl_x( vga_io_ctrl_x ),
       .io_ctrl_y( vga_io_ctrl_y ),
       .io_ctrl_color( T13 )
  );
  Font_Rom_Wrapper font(
       .io_addr( T0 ),
       .io_data( font_io_data )
  );

  always @(posedge clk) begin
    if (T4)
      vmem[T8] <= T63;
  end
endmodule

module WB_Keyboard_Dev(input clk, input reset,
    input  io_keyboard_kb_clk,
    input  io_keyboard_kb_data,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack
);

  wire[31:0] T0;
  wire[31:0] T1;
  wire[31:0] T2;
  wire[31:0] T3;
  reg [31:0] c_count;
  wire[31:0] T46;
  wire[31:0] T4;
  wire[31:0] T5;
  wire T6;
  wire T7;
  wire T8;
  wire T9;
  wire[1:0] T10;
  wire[31:0] T47;
  reg [15:0] cooked;
  wire[15:0] T48;
  wire[15:0] T11;
  wire[15:0] T49;
  wire[8:0] T12;
  wire[8:0] T13;
  reg  p_f0;
  wire T50;
  wire T14;
  wire T15;
  wire T16;
  wire[8:0] T51;
  wire[5:0] cooked_next;
  wire[5:0] T17;
  wire[5:0] T18;
  wire[5:0] T19;
  wire[5:0] T20;
  wire[5:0] T21;
  wire[5:0] T22;
  wire[5:0] T23;
  wire[5:0] T24;
  wire[5:0] T25;
  wire[5:0] T52;
  wire[3:0] T26;
  wire[3:0] T27;
  wire T28;
  wire T29;
  wire T30;
  wire T31;
  wire T32;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire T37;
  wire T38;
  wire T39;
  wire T40;
  reg [31:0] r_count;
  wire[31:0] T53;
  wire[31:0] T41;
  wire[31:0] T42;
  wire T43;
  wire[31:0] T54;
  reg [7:0] raw;
  wire[7:0] T55;
  wire[7:0] T44;
  wire T45;
  wire[7:0] kb_io_ctrl_data;
  wire kb_io_ctrl_interrupt;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    c_count = {1{$random}};
    cooked = {1{$random}};
    p_f0 = {1{$random}};
    r_count = {1{$random}};
    raw = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = T0;
  assign T0 = T45 ? T54 : T1;
  assign T1 = T43 ? r_count : T2;
  assign T2 = T40 ? T47 : T3;
  assign T3 = T9 ? c_count : 32'h0;
  assign T46 = reset ? 32'h0 : T4;
  assign T4 = T6 ? T5 : c_count;
  assign T5 = c_count + 32'h1;
  assign T6 = kb_io_ctrl_interrupt & T7;
  assign T7 = T8 ^ 1'h1;
  assign T8 = kb_io_ctrl_data == 8'hf0;
  assign T9 = T10 == 2'h3;
  assign T10 = io_bus_addr[1'h1:1'h0];
  assign T47 = {16'h0, cooked};
  assign T48 = reset ? 16'h0 : T11;
  assign T11 = T6 ? T49 : cooked;
  assign T49 = {7'h0, T12};
  assign T12 = T51 + T13;
  assign T13 = p_f0 << 4'h8;
  assign T50 = reset ? 1'h0 : T14;
  assign T14 = T6 ? 1'h0 : T15;
  assign T15 = T16 ? 1'h1 : p_f0;
  assign T16 = kb_io_ctrl_interrupt & T8;
  assign T51 = {3'h0, cooked_next};
  assign cooked_next = T39 ? 6'h31 : T17;
  assign T17 = T38 ? 6'h32 : T18;
  assign T18 = T37 ? 6'h33 : T19;
  assign T19 = T36 ? 6'h34 : T20;
  assign T20 = T35 ? 6'h35 : T21;
  assign T21 = T34 ? 6'h36 : T22;
  assign T22 = T33 ? 6'h37 : T23;
  assign T23 = T32 ? 6'h38 : T24;
  assign T24 = T31 ? 6'h39 : T25;
  assign T25 = T30 ? 6'h30 : T52;
  assign T52 = {2'h0, T26};
  assign T26 = T29 ? 4'h8 : T27;
  assign T27 = T28 ? 4'hd : 4'h0;
  assign T28 = kb_io_ctrl_data == 8'h5a;
  assign T29 = kb_io_ctrl_data == 8'h66;
  assign T30 = kb_io_ctrl_data == 8'h45;
  assign T31 = kb_io_ctrl_data == 8'h46;
  assign T32 = kb_io_ctrl_data == 8'h3e;
  assign T33 = kb_io_ctrl_data == 8'h3d;
  assign T34 = kb_io_ctrl_data == 8'h36;
  assign T35 = kb_io_ctrl_data == 8'h2e;
  assign T36 = kb_io_ctrl_data == 8'h25;
  assign T37 = kb_io_ctrl_data == 8'h26;
  assign T38 = kb_io_ctrl_data == 8'h1e;
  assign T39 = kb_io_ctrl_data == 8'h16;
  assign T40 = T10 == 2'h2;
  assign T53 = reset ? 32'h0 : T41;
  assign T41 = kb_io_ctrl_interrupt ? T42 : r_count;
  assign T42 = r_count + 32'h1;
  assign T43 = T10 == 2'h1;
  assign T54 = {24'h0, raw};
  assign T55 = reset ? 8'h0 : T44;
  assign T44 = kb_io_ctrl_interrupt ? kb_io_ctrl_data : raw;
  assign T45 = T10 == 2'h0;
  Keyboard_Ctrl kb(.clk(clk),
       .io_keyboard_kb_clk( io_keyboard_kb_clk ),
       .io_keyboard_kb_data( io_keyboard_kb_data ),
       .io_ctrl_data( kb_io_ctrl_data ),
       .io_ctrl_interrupt( kb_io_ctrl_interrupt )
  );

  always @(posedge clk) begin
    if(reset) begin
      c_count <= 32'h0;
    end else if(T6) begin
      c_count <= T5;
    end
    if(reset) begin
      cooked <= 16'h0;
    end else if(T6) begin
      cooked <= T49;
    end
    if(reset) begin
      p_f0 <= 1'h0;
    end else if(T6) begin
      p_f0 <= 1'h0;
    end else if(T16) begin
      p_f0 <= 1'h1;
    end
    if(reset) begin
      r_count <= 32'h0;
    end else if(kb_io_ctrl_interrupt) begin
      r_count <= T42;
    end
    if(reset) begin
      raw <= 8'h0;
    end else if(kb_io_ctrl_interrupt) begin
      raw <= kb_io_ctrl_data;
    end
  end
endmodule

module WB_Empty_Dev(
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack
);



  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = 32'h0;
endmodule

module Devices(input clk, input reset,
    input [31:0] io_bus_addr,
    input [31:0] io_bus_dat2,
    output[31:0] io_bus_dat4,
    input  io_bus_sel,
    input  io_bus_we,
    output io_bus_ack,
    input [7:0] io_devices_SW,
    output[7:0] io_devices_LED,
    input [4:0] io_devices_BTN,
    output[31:0] io_devices_DISP_NUM,
    output[2:0] io_devices_VGA_red,
    output[2:0] io_devices_VGA_green,
    output[1:0] io_devices_VGA_blue,
    output io_devices_VGA_hsync,
    output io_devices_VGA_vsync,
    output[9:0] io_devices_RAM_addra,
    output[31:0] io_devices_RAM_dina,
    output io_devices_RAM_we,
    input [31:0] io_devices_RAM_douta,
    input  io_devices_KEYBOARD_kb_clk,
    input  io_devices_KEYBOARD_kb_data
);

  wire[31:0] bus_io_from_cpu_dat4;
  wire bus_io_from_cpu_ack;
  wire[31:0] bus_io_slaves_7_addr;
  wire[31:0] bus_io_slaves_7_dat2;
  wire bus_io_slaves_7_sel;
  wire bus_io_slaves_7_we;
  wire[31:0] bus_io_slaves_6_addr;
  wire[31:0] bus_io_slaves_6_dat2;
  wire bus_io_slaves_6_sel;
  wire bus_io_slaves_6_we;
  wire[31:0] bus_io_slaves_5_addr;
  wire[31:0] bus_io_slaves_5_dat2;
  wire bus_io_slaves_5_sel;
  wire bus_io_slaves_5_we;
  wire[31:0] bus_io_slaves_4_addr;
  wire[31:0] bus_io_slaves_4_dat2;
  wire bus_io_slaves_4_sel;
  wire bus_io_slaves_4_we;
  wire[31:0] bus_io_slaves_3_addr;
  wire[31:0] bus_io_slaves_3_dat2;
  wire bus_io_slaves_3_sel;
  wire bus_io_slaves_3_we;
  wire[31:0] bus_io_slaves_2_addr;
  wire[31:0] bus_io_slaves_2_dat2;
  wire bus_io_slaves_2_sel;
  wire bus_io_slaves_2_we;
  wire[31:0] bus_io_slaves_1_addr;
  wire[31:0] bus_io_slaves_1_dat2;
  wire bus_io_slaves_1_sel;
  wire bus_io_slaves_1_we;
  wire[31:0] bus_io_slaves_0_addr;
  wire[31:0] bus_io_slaves_0_dat2;
  wire bus_io_slaves_0_sel;
  wire bus_io_slaves_0_we;
  wire[31:0] bus_io_ram_slave_addr;
  wire[31:0] bus_io_ram_slave_dat2;
  wire bus_io_ram_slave_sel;
  wire bus_io_ram_slave_we;
  wire[31:0] sw_io_bus_dat4;
  wire sw_io_bus_ack;
  wire[31:0] btn_io_bus_dat4;
  wire btn_io_bus_ack;
  wire[31:0] led_io_bus_dat4;
  wire led_io_bus_ack;
  wire[7:0] led_io_LED;
  wire[31:0] counter_io_bus_dat4;
  wire counter_io_bus_ack;
  wire[31:0] seven_seg_io_bus_dat4;
  wire seven_seg_io_bus_ack;
  wire[31:0] seven_seg_io_DISP_NUM;
  wire[31:0] ram_dev_io_bus_dat4;
  wire ram_dev_io_bus_ack;
  wire[9:0] ram_dev_io_ram_addra;
  wire[31:0] ram_dev_io_ram_dina;
  wire ram_dev_io_ram_we;
  wire[31:0] WB_Empty_Dev_io_bus_dat4;
  wire WB_Empty_Dev_io_bus_ack;
  wire[2:0] vga_dev_io_vga_red;
  wire[2:0] vga_dev_io_vga_green;
  wire[1:0] vga_dev_io_vga_blue;
  wire vga_dev_io_vga_hsync;
  wire vga_dev_io_vga_vsync;
  wire[31:0] vga_dev_io_bus_dat4;
  wire vga_dev_io_bus_ack;
  wire[31:0] kb_dev_io_bus_dat4;
  wire kb_dev_io_bus_ack;


  assign io_devices_RAM_we = ram_dev_io_ram_we;
  assign io_devices_RAM_dina = ram_dev_io_ram_dina;
  assign io_devices_RAM_addra = ram_dev_io_ram_addra;
  assign io_devices_VGA_vsync = vga_dev_io_vga_vsync;
  assign io_devices_VGA_hsync = vga_dev_io_vga_hsync;
  assign io_devices_VGA_blue = vga_dev_io_vga_blue;
  assign io_devices_VGA_green = vga_dev_io_vga_green;
  assign io_devices_VGA_red = vga_dev_io_vga_red;
  assign io_devices_DISP_NUM = seven_seg_io_DISP_NUM;
  assign io_devices_LED = led_io_LED;
  assign io_bus_ack = bus_io_from_cpu_ack;
  assign io_bus_dat4 = bus_io_from_cpu_dat4;
  WB_Bus bus(
       .io_from_cpu_addr( io_bus_addr ),
       .io_from_cpu_dat2( io_bus_dat2 ),
       .io_from_cpu_dat4( bus_io_from_cpu_dat4 ),
       .io_from_cpu_sel( io_bus_sel ),
       .io_from_cpu_we( io_bus_we ),
       .io_from_cpu_ack( bus_io_from_cpu_ack ),
       .io_slaves_7_addr( bus_io_slaves_7_addr ),
       .io_slaves_7_dat2( bus_io_slaves_7_dat2 ),
       .io_slaves_7_dat4( WB_Empty_Dev_io_bus_dat4 ),
       .io_slaves_7_sel( bus_io_slaves_7_sel ),
       .io_slaves_7_we( bus_io_slaves_7_we ),
       .io_slaves_7_ack( WB_Empty_Dev_io_bus_ack ),
       .io_slaves_6_addr( bus_io_slaves_6_addr ),
       .io_slaves_6_dat2( bus_io_slaves_6_dat2 ),
       .io_slaves_6_dat4( kb_dev_io_bus_dat4 ),
       .io_slaves_6_sel( bus_io_slaves_6_sel ),
       .io_slaves_6_we( bus_io_slaves_6_we ),
       .io_slaves_6_ack( kb_dev_io_bus_ack ),
       .io_slaves_5_addr( bus_io_slaves_5_addr ),
       .io_slaves_5_dat2( bus_io_slaves_5_dat2 ),
       .io_slaves_5_dat4( vga_dev_io_bus_dat4 ),
       .io_slaves_5_sel( bus_io_slaves_5_sel ),
       .io_slaves_5_we( bus_io_slaves_5_we ),
       .io_slaves_5_ack( vga_dev_io_bus_ack ),
       .io_slaves_4_addr( bus_io_slaves_4_addr ),
       .io_slaves_4_dat2( bus_io_slaves_4_dat2 ),
       .io_slaves_4_dat4( seven_seg_io_bus_dat4 ),
       .io_slaves_4_sel( bus_io_slaves_4_sel ),
       .io_slaves_4_we( bus_io_slaves_4_we ),
       .io_slaves_4_ack( seven_seg_io_bus_ack ),
       .io_slaves_3_addr( bus_io_slaves_3_addr ),
       .io_slaves_3_dat2( bus_io_slaves_3_dat2 ),
       .io_slaves_3_dat4( counter_io_bus_dat4 ),
       .io_slaves_3_sel( bus_io_slaves_3_sel ),
       .io_slaves_3_we( bus_io_slaves_3_we ),
       .io_slaves_3_ack( counter_io_bus_ack ),
       .io_slaves_2_addr( bus_io_slaves_2_addr ),
       .io_slaves_2_dat2( bus_io_slaves_2_dat2 ),
       .io_slaves_2_dat4( led_io_bus_dat4 ),
       .io_slaves_2_sel( bus_io_slaves_2_sel ),
       .io_slaves_2_we( bus_io_slaves_2_we ),
       .io_slaves_2_ack( led_io_bus_ack ),
       .io_slaves_1_addr( bus_io_slaves_1_addr ),
       .io_slaves_1_dat2( bus_io_slaves_1_dat2 ),
       .io_slaves_1_dat4( btn_io_bus_dat4 ),
       .io_slaves_1_sel( bus_io_slaves_1_sel ),
       .io_slaves_1_we( bus_io_slaves_1_we ),
       .io_slaves_1_ack( btn_io_bus_ack ),
       .io_slaves_0_addr( bus_io_slaves_0_addr ),
       .io_slaves_0_dat2( bus_io_slaves_0_dat2 ),
       .io_slaves_0_dat4( sw_io_bus_dat4 ),
       .io_slaves_0_sel( bus_io_slaves_0_sel ),
       .io_slaves_0_we( bus_io_slaves_0_we ),
       .io_slaves_0_ack( sw_io_bus_ack ),
       .io_ram_slave_addr( bus_io_ram_slave_addr ),
       .io_ram_slave_dat2( bus_io_ram_slave_dat2 ),
       .io_ram_slave_dat4( ram_dev_io_bus_dat4 ),
       .io_ram_slave_sel( bus_io_ram_slave_sel ),
       .io_ram_slave_we( bus_io_ram_slave_we ),
       .io_ram_slave_ack( ram_dev_io_bus_ack )
  );
  WB_Sw_Dev sw(
       .io_bus_addr( bus_io_slaves_0_addr ),
       .io_bus_dat2( bus_io_slaves_0_dat2 ),
       .io_bus_dat4( sw_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_0_sel ),
       .io_bus_we( bus_io_slaves_0_we ),
       .io_bus_ack( sw_io_bus_ack ),
       .io_SW( io_devices_SW )
  );
  WB_Button_Dev btn(
       .io_bus_addr( bus_io_slaves_1_addr ),
       .io_bus_dat2( bus_io_slaves_1_dat2 ),
       .io_bus_dat4( btn_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_1_sel ),
       .io_bus_we( bus_io_slaves_1_we ),
       .io_bus_ack( btn_io_bus_ack ),
       .io_BTN( io_devices_BTN )
  );
  WB_Led_Dev led(.clk(clk), .reset(reset),
       .io_bus_addr( bus_io_slaves_2_addr ),
       .io_bus_dat2( bus_io_slaves_2_dat2 ),
       .io_bus_dat4( led_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_2_sel ),
       .io_bus_we( bus_io_slaves_2_we ),
       .io_bus_ack( led_io_bus_ack ),
       .io_LED( led_io_LED )
  );
  WB_Counter_Dev counter(.clk(clk), .reset(reset),
       .io_bus_addr( bus_io_slaves_3_addr ),
       .io_bus_dat2( bus_io_slaves_3_dat2 ),
       .io_bus_dat4( counter_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_3_sel ),
       .io_bus_we( bus_io_slaves_3_we ),
       .io_bus_ack( counter_io_bus_ack )
  );
  WB_Seven_Dev seven_seg(.clk(clk), .reset(reset),
       .io_bus_addr( bus_io_slaves_4_addr ),
       .io_bus_dat2( bus_io_slaves_4_dat2 ),
       .io_bus_dat4( seven_seg_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_4_sel ),
       .io_bus_we( bus_io_slaves_4_we ),
       .io_bus_ack( seven_seg_io_bus_ack ),
       .io_DISP_NUM( seven_seg_io_DISP_NUM )
  );
  WB_Ram_Dev ram_dev(
       .io_bus_addr( bus_io_ram_slave_addr ),
       .io_bus_dat2( bus_io_ram_slave_dat2 ),
       .io_bus_dat4( ram_dev_io_bus_dat4 ),
       .io_bus_sel( bus_io_ram_slave_sel ),
       .io_bus_we( bus_io_ram_slave_we ),
       .io_bus_ack( ram_dev_io_bus_ack ),
       .io_ram_addra( ram_dev_io_ram_addra ),
       .io_ram_dina( ram_dev_io_ram_dina ),
       .io_ram_we( ram_dev_io_ram_we ),
       .io_ram_douta( io_devices_RAM_douta )
  );
  WB_VGA_Dev vga_dev(.clk(clk), .reset(reset),
       .io_vga_red( vga_dev_io_vga_red ),
       .io_vga_green( vga_dev_io_vga_green ),
       .io_vga_blue( vga_dev_io_vga_blue ),
       .io_vga_hsync( vga_dev_io_vga_hsync ),
       .io_vga_vsync( vga_dev_io_vga_vsync ),
       .io_bus_addr( bus_io_slaves_5_addr ),
       .io_bus_dat2( bus_io_slaves_5_dat2 ),
       .io_bus_dat4( vga_dev_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_5_sel ),
       .io_bus_we( bus_io_slaves_5_we ),
       .io_bus_ack( vga_dev_io_bus_ack )
  );
  WB_Keyboard_Dev kb_dev(.clk(clk), .reset(reset),
       .io_keyboard_kb_clk( io_devices_KEYBOARD_kb_clk ),
       .io_keyboard_kb_data( io_devices_KEYBOARD_kb_data ),
       .io_bus_addr( bus_io_slaves_6_addr ),
       .io_bus_dat2( bus_io_slaves_6_dat2 ),
       .io_bus_dat4( kb_dev_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_6_sel ),
       .io_bus_we( bus_io_slaves_6_we ),
       .io_bus_ack( kb_dev_io_bus_ack )
  );
  WB_Empty_Dev WB_Empty_Dev(
       .io_bus_addr( bus_io_slaves_7_addr ),
       .io_bus_dat2( bus_io_slaves_7_dat2 ),
       .io_bus_dat4( WB_Empty_Dev_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_7_sel ),
       .io_bus_we( bus_io_slaves_7_we ),
       .io_bus_ack( WB_Empty_Dev_io_bus_ack )
  );
endmodule

module SOC(input clk, input reset,
    input [7:0] io_devices_SW,
    output[7:0] io_devices_LED,
    input [4:0] io_devices_BTN,
    output[31:0] io_devices_DISP_NUM,
    output[2:0] io_devices_VGA_red,
    output[2:0] io_devices_VGA_green,
    output[1:0] io_devices_VGA_blue,
    output io_devices_VGA_hsync,
    output io_devices_VGA_vsync,
    output[9:0] io_devices_RAM_addra,
    output[31:0] io_devices_RAM_dina,
    output io_devices_RAM_we,
    input [31:0] io_devices_RAM_douta,
    input  io_devices_KEYBOARD_kb_clk,
    input  io_devices_KEYBOARD_kb_data,
    output[31:0] io_debug_inst_out,
    output[31:0] io_debug_bus_addr,
    output[31:0] io_debug_bus_dat2,
    output[31:0] io_debug_bus_dat4,
    output[31:0] io_debug_pc_out
);

  wire[31:0] cpu_io_bus_addr;
  wire[31:0] cpu_io_bus_dat2;
  wire cpu_io_bus_sel;
  wire cpu_io_bus_we;
  wire[31:0] cpu_io_debug_inst_out;
  wire[31:0] cpu_io_debug_bus_addr;
  wire[31:0] cpu_io_debug_bus_dat2;
  wire[31:0] cpu_io_debug_bus_dat4;
  wire[31:0] cpu_io_debug_pc_out;
  wire[31:0] dev_io_bus_dat4;
  wire dev_io_bus_ack;
  wire[7:0] dev_io_devices_LED;
  wire[31:0] dev_io_devices_DISP_NUM;
  wire[2:0] dev_io_devices_VGA_red;
  wire[2:0] dev_io_devices_VGA_green;
  wire[1:0] dev_io_devices_VGA_blue;
  wire dev_io_devices_VGA_hsync;
  wire dev_io_devices_VGA_vsync;
  wire[9:0] dev_io_devices_RAM_addra;
  wire[31:0] dev_io_devices_RAM_dina;
  wire dev_io_devices_RAM_we;


  assign io_debug_pc_out = cpu_io_debug_pc_out;
  assign io_debug_bus_dat4 = cpu_io_debug_bus_dat4;
  assign io_debug_bus_dat2 = cpu_io_debug_bus_dat2;
  assign io_debug_bus_addr = cpu_io_debug_bus_addr;
  assign io_debug_inst_out = cpu_io_debug_inst_out;
  assign io_devices_RAM_we = dev_io_devices_RAM_we;
  assign io_devices_RAM_dina = dev_io_devices_RAM_dina;
  assign io_devices_RAM_addra = dev_io_devices_RAM_addra;
  assign io_devices_VGA_vsync = dev_io_devices_VGA_vsync;
  assign io_devices_VGA_hsync = dev_io_devices_VGA_hsync;
  assign io_devices_VGA_blue = dev_io_devices_VGA_blue;
  assign io_devices_VGA_green = dev_io_devices_VGA_green;
  assign io_devices_VGA_red = dev_io_devices_VGA_red;
  assign io_devices_DISP_NUM = dev_io_devices_DISP_NUM;
  assign io_devices_LED = dev_io_devices_LED;
  Core cpu(.clk(clk), .reset(reset),
       .io_bus_addr( cpu_io_bus_addr ),
       .io_bus_dat2( cpu_io_bus_dat2 ),
       .io_bus_dat4( dev_io_bus_dat4 ),
       .io_bus_sel( cpu_io_bus_sel ),
       .io_bus_we( cpu_io_bus_we ),
       .io_bus_ack( dev_io_bus_ack ),
       .io_debug_inst_out( cpu_io_debug_inst_out ),
       .io_debug_bus_addr( cpu_io_debug_bus_addr ),
       .io_debug_bus_dat2( cpu_io_debug_bus_dat2 ),
       .io_debug_bus_dat4( cpu_io_debug_bus_dat4 ),
       .io_debug_pc_out( cpu_io_debug_pc_out )
  );
  Devices dev(.clk(clk), .reset(reset),
       .io_bus_addr( cpu_io_bus_addr ),
       .io_bus_dat2( cpu_io_bus_dat2 ),
       .io_bus_dat4( dev_io_bus_dat4 ),
       .io_bus_sel( cpu_io_bus_sel ),
       .io_bus_we( cpu_io_bus_we ),
       .io_bus_ack( dev_io_bus_ack ),
       .io_devices_SW( io_devices_SW ),
       .io_devices_LED( dev_io_devices_LED ),
       .io_devices_BTN( io_devices_BTN ),
       .io_devices_DISP_NUM( dev_io_devices_DISP_NUM ),
       .io_devices_VGA_red( dev_io_devices_VGA_red ),
       .io_devices_VGA_green( dev_io_devices_VGA_green ),
       .io_devices_VGA_blue( dev_io_devices_VGA_blue ),
       .io_devices_VGA_hsync( dev_io_devices_VGA_hsync ),
       .io_devices_VGA_vsync( dev_io_devices_VGA_vsync ),
       .io_devices_RAM_addra( dev_io_devices_RAM_addra ),
       .io_devices_RAM_dina( dev_io_devices_RAM_dina ),
       .io_devices_RAM_we( dev_io_devices_RAM_we ),
       .io_devices_RAM_douta( io_devices_RAM_douta ),
       .io_devices_KEYBOARD_kb_clk( io_devices_KEYBOARD_kb_clk ),
       .io_devices_KEYBOARD_kb_data( io_devices_KEYBOARD_kb_data )
  );
endmodule

