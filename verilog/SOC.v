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
    output io_ctrl_alu_b_sel,
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

  wire T0;
  wire T1;
  wire[7:0] T2;
  wire T3;
  wire T4;
  wire[31:0] T5;
  wire[175:0] T6;
  wire T7;
  wire T8;
  wire[31:0] T9;
  wire[183:0] T10;
  wire T11;
  wire T12;
  wire[31:0] T13;
  wire[183:0] T14;
  wire T15;
  wire T16;
  wire[31:0] T17;
  wire[183:0] T18;
  wire T19;
  wire T20;
  wire[31:0] T21;
  wire[31:0] next_state;
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
  wire[31:0] T34;
  wire[31:0] T35;
  wire[31:0] T36;
  wire T37;
  wire[5:0] inst_op;
  wire[31:0] inst;
  wire T38;
  reg [31:0] state;
  wire[31:0] T323;
  wire[31:0] T39;
  wire T40;
  wire T41;
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
  wire[31:0] T52;
  wire[31:0] T53;
  wire[31:0] T54;
  wire[31:0] T55;
  wire[31:0] T56;
  wire[31:0] T57;
  wire[31:0] T58;
  wire[31:0] T59;
  wire[31:0] T60;
  wire[31:0] T61;
  wire[31:0] T62;
  wire T63;
  wire[5:0] inst_func;
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
  wire[207:0] T76;
  wire T77;
  wire T78;
  wire[31:0] T79;
  wire[175:0] T80;
  wire T81;
  wire T82;
  wire[31:0] T83;
  wire[143:0] T84;
  wire T85;
  wire T86;
  wire T87;
  wire bus_addr_src;
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
  wire T103;
  wire T104;
  wire T105;
  wire T106;
  wire T107;
  wire T108;
  wire T109;
  wire T110;
  wire T111;
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
  wire inst_we;
  wire T125;
  wire bus_we;
  wire T126;
  wire T127;
  wire T128;
  wire T129;
  wire T130;
  wire T131;
  wire T132;
  wire T133;
  wire T134;
  wire T135;
  wire T136;
  wire T137;
  wire T138;
  wire T139;
  wire T140;
  wire T141;
  wire T142;
  wire T143;
  wire T144;
  wire bus_sel;
  wire T145;
  wire T146;
  wire T147;
  wire T148;
  wire T149;
  wire T150;
  wire T151;
  wire T152;
  wire T153;
  wire T154;
  wire T155;
  wire T156;
  wire T157;
  wire T158;
  wire T159;
  wire T160;
  wire T161;
  wire T162;
  wire[1:0] T163;
  wire[1:0] alu_b_sel;
  wire[1:0] T164;
  wire[1:0] T165;
  wire[1:0] T166;
  wire[1:0] T167;
  wire[1:0] T168;
  wire[1:0] T169;
  wire[1:0] T170;
  wire[1:0] T171;
  wire[1:0] T172;
  wire[1:0] T173;
  wire[1:0] T174;
  wire[1:0] T175;
  wire[1:0] T176;
  wire[1:0] T177;
  wire[1:0] T178;
  wire[1:0] T179;
  wire[1:0] T180;
  wire[1:0] T181;
  wire[1:0] T182;
  wire[1:0] T183;
  wire[1:0] T184;
  wire[1:0] T324;
  wire T185;
  wire T186;
  wire T187;
  wire[2:0] T188;
  wire[2:0] alu_op;
  wire[2:0] T189;
  wire[2:0] T190;
  wire[2:0] T191;
  wire[2:0] T192;
  wire[2:0] T193;
  wire[2:0] T194;
  wire[2:0] T195;
  wire[2:0] T196;
  wire[2:0] T197;
  wire[2:0] T198;
  wire[2:0] T199;
  wire[2:0] T200;
  wire[2:0] T201;
  wire[2:0] T202;
  wire[2:0] T203;
  wire[2:0] T204;
  wire[2:0] T205;
  wire[2:0] T206;
  wire[2:0] T207;
  wire[2:0] T208;
  wire[2:0] T209;
  wire[2:0] T210;
  wire[1:0] T211;
  wire[1:0] reg_we_dst;
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
  wire[1:0] T227;
  wire[1:0] T228;
  wire[1:0] T229;
  wire[1:0] T230;
  wire[1:0] T231;
  wire[1:0] T232;
  wire[1:0] T233;
  wire[1:0] T234;
  wire[1:0] T235;
  wire T236;
  wire T237;
  wire[1:0] T238;
  wire[1:0] reg_we_src;
  wire[1:0] T239;
  wire[1:0] T240;
  wire[1:0] T241;
  wire[1:0] T242;
  wire[1:0] T243;
  wire[1:0] T244;
  wire[1:0] T245;
  wire[1:0] T246;
  wire[1:0] T247;
  wire[1:0] T248;
  wire[1:0] T249;
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
  wire T263;
  wire reg_we;
  wire T264;
  wire T265;
  wire T266;
  wire T267;
  wire T268;
  wire T269;
  wire T270;
  wire T271;
  wire T272;
  wire T273;
  wire T274;
  wire T275;
  wire T276;
  wire T277;
  wire T278;
  wire T279;
  wire T280;
  wire T281;
  wire T282;
  wire T283;
  wire T284;
  wire T285;
  wire T286;
  wire[1:0] T287;
  wire[1:0] pc_next_sel;
  wire[1:0] T288;
  wire[1:0] T289;
  wire[1:0] T290;
  wire[1:0] T291;
  wire[1:0] T292;
  wire[1:0] T293;
  wire[1:0] T294;
  wire[1:0] T295;
  wire[1:0] T296;
  wire[1:0] T297;
  wire[1:0] T298;
  wire[1:0] T299;
  wire[1:0] T300;
  wire[1:0] T301;
  wire[1:0] T302;
  wire[1:0] T303;
  wire[1:0] T304;
  wire[1:0] T305;
  wire[1:0] T306;
  wire[1:0] T307;
  wire[1:0] T308;
  wire[1:0] T309;
  wire[1:0] T310;
  wire[1:0] T311;
  wire T312;
  wire pc_we;
  wire T313;
  wire[335:0] T314;
  wire T315;
  wire T316;
  wire[31:0] T317;
  wire[167:0] T318;
  wire[31:0] T319;
  wire[31:0] T320;
  wire T321;
  wire T322;
  wire T325;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    state = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = io_bus_ack & T1;
  assign T1 = reset ^ 1'h1;
  assign T3 = io_bus_ack & T4;
  assign T4 = reset ^ 1'h1;
  assign T5 = io_ctrl_alu_out;
  assign T7 = io_bus_ack & T8;
  assign T8 = reset ^ 1'h1;
  assign T9 = io_bus_dat4;
  assign T11 = io_bus_ack & T12;
  assign T12 = reset ^ 1'h1;
  assign T13 = io_bus_dat2;
  assign T15 = io_bus_ack & T16;
  assign T16 = reset ^ 1'h1;
  assign T17 = io_bus_addr;
  assign T19 = io_bus_ack & T20;
  assign T20 = reset ^ 1'h1;
  assign T21 = next_state;
  assign next_state = T22;
  assign T22 = T75 ? T23 : 32'h0;
  assign T23 = T74 ? T52 : T24;
  assign T24 = T51 ? 32'hc : T25;
  assign T25 = T50 ? 32'hd : T26;
  assign T26 = T49 ? 32'he : T27;
  assign T27 = T48 ? 32'hf : T28;
  assign T28 = T47 ? 32'h10 : T29;
  assign T29 = T46 ? 32'h11 : T30;
  assign T30 = T45 ? 32'h12 : T31;
  assign T31 = T44 ? 32'h13 : T32;
  assign T32 = T43 ? 32'h14 : T33;
  assign T33 = T42 ? 32'h15 : T34;
  assign T34 = T41 ? 32'h16 : T35;
  assign T35 = T40 ? 32'h17 : T36;
  assign T36 = T37 ? 32'h18 : 32'h0;
  assign T37 = inst_op == 6'h3;
  assign inst_op = inst[5'h1f:5'h1a];
  assign inst = T38 ? io_bus_dat4 : io_ctrl_inst;
  assign T38 = state == 32'h0;
  assign T323 = reset ? 32'h0 : T39;
  assign T39 = io_bus_ack ? next_state : state;
  assign T40 = inst_op == 6'h2;
  assign T41 = inst_op == 6'ha;
  assign T42 = inst_op == 6'h5;
  assign T43 = inst_op == 6'h4;
  assign T44 = inst_op == 6'h2b;
  assign T45 = inst_op == 6'h23;
  assign T46 = inst_op == 6'hf;
  assign T47 = inst_op == 6'he;
  assign T48 = inst_op == 6'hd;
  assign T49 = inst_op == 6'hc;
  assign T50 = inst_op == 6'h9;
  assign T51 = inst_op == 6'h8;
  assign T52 = T73 ? 32'h1 : T53;
  assign T53 = T72 ? 32'h2 : T54;
  assign T54 = T71 ? 32'h3 : T55;
  assign T55 = T70 ? 32'h4 : T56;
  assign T56 = T69 ? 32'h5 : T57;
  assign T57 = T68 ? 32'h6 : T58;
  assign T58 = T67 ? 32'h7 : T59;
  assign T59 = T66 ? 32'h8 : T60;
  assign T60 = T65 ? 32'h9 : T61;
  assign T61 = T64 ? 32'ha : T62;
  assign T62 = T63 ? 32'hb : 32'h0;
  assign T63 = inst_func == 6'h8;
  assign inst_func = inst[3'h5:1'h0];
  assign T64 = inst_func == 6'h6;
  assign T65 = inst_func == 6'h2a;
  assign T66 = inst_func == 6'h27;
  assign T67 = inst_func == 6'h26;
  assign T68 = inst_func == 6'h25;
  assign T69 = inst_func == 6'h24;
  assign T70 = inst_func == 6'h23;
  assign T71 = inst_func == 6'h22;
  assign T72 = inst_func == 6'h21;
  assign T73 = inst_func == 6'h20;
  assign T74 = inst_op == 6'h0;
  assign T75 = state == 32'h0;
  assign T77 = io_bus_ack & T78;
  assign T78 = reset ^ 1'h1;
  assign T79 = io_ctrl_inst;
  assign T81 = io_bus_ack & T82;
  assign T82 = reset ^ 1'h1;
  assign T83 = inst;
  assign T85 = io_bus_ack & T86;
  assign T86 = reset ^ 1'h1;
  assign T87 = bus_addr_src;
  assign bus_addr_src = inst_we ? 1'h0 : T88;
  assign T88 = T124 ? 1'h0 : T89;
  assign T89 = T123 ? 1'h0 : T90;
  assign T90 = T122 ? 1'h0 : T91;
  assign T91 = T121 ? 1'h0 : T92;
  assign T92 = T120 ? 1'h0 : T93;
  assign T93 = T119 ? 1'h0 : T94;
  assign T94 = T118 ? 1'h0 : T95;
  assign T95 = T117 ? 1'h0 : T96;
  assign T96 = T116 ? 1'h0 : T97;
  assign T97 = T115 ? 1'h0 : T98;
  assign T98 = T114 ? 1'h0 : T99;
  assign T99 = T113 ? 1'h0 : T100;
  assign T100 = T112 ? 1'h0 : T101;
  assign T101 = T111 ? 1'h0 : T102;
  assign T102 = T110 ? 1'h0 : T103;
  assign T103 = T109 ? 1'h0 : T104;
  assign T104 = T108 ? 1'h0 : T105;
  assign T105 = T107 ? 1'h1 : T106;
  assign T106 = state == 32'h13;
  assign T107 = state == 32'h12;
  assign T108 = state == 32'h11;
  assign T109 = state == 32'h10;
  assign T110 = state == 32'hf;
  assign T111 = state == 32'he;
  assign T112 = state == 32'hd;
  assign T113 = state == 32'hc;
  assign T114 = state == 32'hb;
  assign T115 = state == 32'ha;
  assign T116 = state == 32'h9;
  assign T117 = state == 32'h8;
  assign T118 = state == 32'h7;
  assign T119 = state == 32'h6;
  assign T120 = state == 32'h5;
  assign T121 = state == 32'h4;
  assign T122 = state == 32'h3;
  assign T123 = state == 32'h2;
  assign T124 = state == 32'h1;
  assign inst_we = state == 32'h0;
  assign T125 = bus_we;
  assign bus_we = inst_we ? 1'h0 : T126;
  assign T126 = T124 ? 1'h0 : T127;
  assign T127 = T123 ? 1'h0 : T128;
  assign T128 = T122 ? 1'h0 : T129;
  assign T129 = T121 ? 1'h0 : T130;
  assign T130 = T120 ? 1'h0 : T131;
  assign T131 = T119 ? 1'h0 : T132;
  assign T132 = T118 ? 1'h0 : T133;
  assign T133 = T117 ? 1'h0 : T134;
  assign T134 = T116 ? 1'h0 : T135;
  assign T135 = T115 ? 1'h0 : T136;
  assign T136 = T114 ? 1'h0 : T137;
  assign T137 = T113 ? 1'h0 : T138;
  assign T138 = T112 ? 1'h0 : T139;
  assign T139 = T111 ? 1'h0 : T140;
  assign T140 = T110 ? 1'h0 : T141;
  assign T141 = T109 ? 1'h0 : T142;
  assign T142 = T108 ? 1'h0 : T143;
  assign T143 = T107 ? 1'h0 : T106;
  assign T144 = bus_sel;
  assign bus_sel = inst_we ? 1'h1 : T145;
  assign T145 = T124 ? 1'h0 : T146;
  assign T146 = T123 ? 1'h0 : T147;
  assign T147 = T122 ? 1'h0 : T148;
  assign T148 = T121 ? 1'h0 : T149;
  assign T149 = T120 ? 1'h0 : T150;
  assign T150 = T119 ? 1'h0 : T151;
  assign T151 = T118 ? 1'h0 : T152;
  assign T152 = T117 ? 1'h0 : T153;
  assign T153 = T116 ? 1'h0 : T154;
  assign T154 = T115 ? 1'h0 : T155;
  assign T155 = T114 ? 1'h0 : T156;
  assign T156 = T113 ? 1'h0 : T157;
  assign T157 = T112 ? 1'h0 : T158;
  assign T158 = T111 ? 1'h0 : T159;
  assign T159 = T110 ? 1'h0 : T160;
  assign T160 = T109 ? 1'h0 : T161;
  assign T161 = T108 ? 1'h0 : T162;
  assign T162 = T107 ? 1'h1 : T106;
  assign T163 = alu_b_sel;
  assign alu_b_sel = inst_we ? 2'h0 : T164;
  assign T164 = T124 ? 2'h0 : T165;
  assign T165 = T123 ? 2'h0 : T166;
  assign T166 = T122 ? 2'h0 : T167;
  assign T167 = T121 ? 2'h0 : T168;
  assign T168 = T120 ? 2'h0 : T169;
  assign T169 = T119 ? 2'h0 : T170;
  assign T170 = T118 ? 2'h0 : T171;
  assign T171 = T117 ? 2'h0 : T172;
  assign T172 = T116 ? 2'h0 : T173;
  assign T173 = T115 ? 2'h0 : T174;
  assign T174 = T114 ? 2'h0 : T175;
  assign T175 = T113 ? 2'h1 : T176;
  assign T176 = T112 ? 2'h1 : T177;
  assign T177 = T111 ? 2'h1 : T178;
  assign T178 = T110 ? 2'h1 : T179;
  assign T179 = T109 ? 2'h1 : T180;
  assign T180 = T108 ? 2'h1 : T181;
  assign T181 = T107 ? 2'h1 : T182;
  assign T182 = T106 ? 2'h1 : T183;
  assign T183 = T187 ? 2'h0 : T184;
  assign T184 = T186 ? 2'h2 : T324;
  assign T324 = {1'h0, T185};
  assign T185 = state == 32'h16;
  assign T186 = state == 32'h15;
  assign T187 = state == 32'h14;
  assign T188 = alu_op;
  assign alu_op = inst_we ? 3'h0 : T189;
  assign T189 = T124 ? 3'h2 : T190;
  assign T190 = T123 ? 3'h2 : T191;
  assign T191 = T122 ? 3'h6 : T192;
  assign T192 = T121 ? 3'h6 : T193;
  assign T193 = T120 ? 3'h0 : T194;
  assign T194 = T119 ? 3'h1 : T195;
  assign T195 = T118 ? 3'h3 : T196;
  assign T196 = T117 ? 3'h4 : T197;
  assign T197 = T116 ? 3'h7 : T198;
  assign T198 = T115 ? 3'h5 : T199;
  assign T199 = T114 ? 3'h0 : T200;
  assign T200 = T113 ? 3'h2 : T201;
  assign T201 = T112 ? 3'h2 : T202;
  assign T202 = T111 ? 3'h0 : T203;
  assign T203 = T110 ? 3'h1 : T204;
  assign T204 = T109 ? 3'h3 : T205;
  assign T205 = T108 ? 3'h2 : T206;
  assign T206 = T107 ? 3'h2 : T207;
  assign T207 = T106 ? 3'h2 : T208;
  assign T208 = T187 ? 3'h6 : T209;
  assign T209 = T186 ? 3'h4 : T210;
  assign T210 = T185 ? 3'h7 : 3'h0;
  assign T211 = reg_we_dst;
  assign reg_we_dst = inst_we ? 2'h0 : T212;
  assign T212 = T124 ? 2'h0 : T213;
  assign T213 = T123 ? 2'h0 : T214;
  assign T214 = T122 ? 2'h0 : T215;
  assign T215 = T121 ? 2'h0 : T216;
  assign T216 = T120 ? 2'h0 : T217;
  assign T217 = T119 ? 2'h0 : T218;
  assign T218 = T118 ? 2'h0 : T219;
  assign T219 = T117 ? 2'h0 : T220;
  assign T220 = T116 ? 2'h0 : T221;
  assign T221 = T115 ? 2'h0 : T222;
  assign T222 = T114 ? 2'h0 : T223;
  assign T223 = T113 ? 2'h1 : T224;
  assign T224 = T112 ? 2'h1 : T225;
  assign T225 = T111 ? 2'h1 : T226;
  assign T226 = T110 ? 2'h1 : T227;
  assign T227 = T109 ? 2'h1 : T228;
  assign T228 = T108 ? 2'h1 : T229;
  assign T229 = T107 ? 2'h1 : T230;
  assign T230 = T106 ? 2'h0 : T231;
  assign T231 = T187 ? 2'h0 : T232;
  assign T232 = T186 ? 2'h0 : T233;
  assign T233 = T185 ? 2'h1 : T234;
  assign T234 = T237 ? 2'h0 : T235;
  assign T235 = T236 ? 2'h2 : 2'h0;
  assign T236 = state == 32'h18;
  assign T237 = state == 32'h17;
  assign T238 = reg_we_src;
  assign reg_we_src = inst_we ? 2'h0 : T239;
  assign T239 = T124 ? 2'h0 : T240;
  assign T240 = T123 ? 2'h0 : T241;
  assign T241 = T122 ? 2'h0 : T242;
  assign T242 = T121 ? 2'h0 : T243;
  assign T243 = T120 ? 2'h0 : T244;
  assign T244 = T119 ? 2'h0 : T245;
  assign T245 = T118 ? 2'h0 : T246;
  assign T246 = T117 ? 2'h0 : T247;
  assign T247 = T116 ? 2'h0 : T248;
  assign T248 = T115 ? 2'h0 : T249;
  assign T249 = T114 ? 2'h0 : T250;
  assign T250 = T113 ? 2'h0 : T251;
  assign T251 = T112 ? 2'h0 : T252;
  assign T252 = T111 ? 2'h0 : T253;
  assign T253 = T110 ? 2'h0 : T254;
  assign T254 = T109 ? 2'h0 : T255;
  assign T255 = T108 ? 2'h3 : T256;
  assign T256 = T107 ? 2'h1 : T257;
  assign T257 = T106 ? 2'h0 : T258;
  assign T258 = T187 ? 2'h0 : T259;
  assign T259 = T186 ? 2'h0 : T260;
  assign T260 = T185 ? 2'h0 : T261;
  assign T261 = T237 ? 2'h0 : T262;
  assign T262 = T236 ? 2'h2 : 2'h0;
  assign T263 = reg_we;
  assign reg_we = inst_we ? 1'h0 : T264;
  assign T264 = T124 ? 1'h1 : T265;
  assign T265 = T123 ? 1'h1 : T266;
  assign T266 = T122 ? 1'h1 : T267;
  assign T267 = T121 ? 1'h1 : T268;
  assign T268 = T120 ? 1'h1 : T269;
  assign T269 = T119 ? 1'h1 : T270;
  assign T270 = T118 ? 1'h1 : T271;
  assign T271 = T117 ? 1'h1 : T272;
  assign T272 = T116 ? 1'h1 : T273;
  assign T273 = T115 ? 1'h1 : T274;
  assign T274 = T114 ? 1'h0 : T275;
  assign T275 = T113 ? 1'h1 : T276;
  assign T276 = T112 ? 1'h1 : T277;
  assign T277 = T111 ? 1'h1 : T278;
  assign T278 = T110 ? 1'h1 : T279;
  assign T279 = T109 ? 1'h1 : T280;
  assign T280 = T108 ? 1'h1 : T281;
  assign T281 = T107 ? 1'h1 : T282;
  assign T282 = T106 ? 1'h0 : T283;
  assign T283 = T187 ? 1'h0 : T284;
  assign T284 = T186 ? 1'h0 : T285;
  assign T285 = T185 ? 1'h1 : T286;
  assign T286 = T237 ? 1'h0 : T236;
  assign T287 = pc_next_sel;
  assign pc_next_sel = inst_we ? 2'h0 : T288;
  assign T288 = T124 ? 2'h0 : T289;
  assign T289 = T123 ? 2'h0 : T290;
  assign T290 = T122 ? 2'h0 : T291;
  assign T291 = T121 ? 2'h0 : T292;
  assign T292 = T120 ? 2'h0 : T293;
  assign T293 = T119 ? 2'h0 : T294;
  assign T294 = T118 ? 2'h0 : T295;
  assign T295 = T117 ? 2'h0 : T296;
  assign T296 = T116 ? 2'h0 : T297;
  assign T297 = T115 ? 2'h0 : T298;
  assign T298 = T114 ? 2'h3 : T299;
  assign T299 = T113 ? 2'h0 : T300;
  assign T300 = T112 ? 2'h0 : T301;
  assign T301 = T111 ? 2'h0 : T302;
  assign T302 = T110 ? 2'h0 : T303;
  assign T303 = T109 ? 2'h0 : T304;
  assign T304 = T108 ? 2'h0 : T305;
  assign T305 = T107 ? 2'h0 : T306;
  assign T306 = T106 ? 2'h0 : T307;
  assign T307 = T187 ? 2'h1 : T308;
  assign T308 = T186 ? 2'h1 : T309;
  assign T309 = T185 ? 2'h0 : T310;
  assign T310 = T237 ? 2'h2 : T311;
  assign T311 = T236 ? 2'h2 : 2'h0;
  assign T312 = pc_we;
  assign pc_we = inst_we == 1'h0;
  assign T313 = inst_we;
  assign T315 = io_bus_ack & T316;
  assign T316 = reset ^ 1'h1;
  assign T317 = state;
  assign io_debug_pc_out = io_ctrl_pc_out;
  assign io_debug_bus_dat4 = io_bus_dat4;
  assign io_debug_bus_dat2 = io_bus_dat2;
  assign io_debug_bus_addr = io_bus_addr;
  assign io_debug_inst_out = inst;
  assign io_bus_we = bus_we;
  assign io_bus_sel = bus_sel;
  assign io_bus_dat2 = io_ctrl_data_out;
  assign io_bus_addr = T319;
  assign T319 = T322 ? io_ctrl_alu_out : T320;
  assign T320 = T321 ? io_ctrl_pc_out : 32'h0;
  assign T321 = bus_addr_src == 1'h0;
  assign T322 = bus_addr_src == 1'h1;
  assign io_ctrl_alu_b_sel = T325;
  assign T325 = alu_b_sel[1'h0:1'h0];
  assign io_ctrl_alu_op = alu_op;
  assign io_ctrl_reg_we_dst = reg_we_dst;
  assign io_ctrl_reg_we_src = reg_we_src;
  assign io_ctrl_reg_we = reg_we;
  assign io_ctrl_pc_next_sel = pc_next_sel;
  assign io_ctrl_pc_we = pc_we;
  assign io_ctrl_inst_we = inst_we;
  assign io_ctrl_bus_data = io_bus_dat4;

  always @(posedge clk) begin
    if(reset) begin
      state <= 32'h0;
    end else if(io_bus_ack) begin
      state <= next_state;
    end
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T315)
        $fwrite(32'h80000002, " - state: %d\n", T317);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T85)
        $fwrite(32'h80000002, " - ctrls: %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n", T313, T312, T287, T263, T238, T211, T188, T163, T144, T125, T87);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T81)
        $fwrite(32'h80000002, " - inst: %h\n", T83);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T77)
        $fwrite(32'h80000002, " - inst_reg: %h\n", T79);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T19)
        $fwrite(32'h80000002, " - next_state: %d\n", T21);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T15)
        $fwrite(32'h80000002, " -- bus_addr: %h\n", T17);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T11)
        $fwrite(32'h80000002, " -- bus_dat2: %h\n", T13);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T7)
        $fwrite(32'h80000002, " -- bus_dat4: %h\n", T9);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T3)
        $fwrite(32'h80000002, " -- alu_out: %h\n", T5);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T0)
        $fwrite(32'h80000002, "\n");
// synthesis translate_on
`endif
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

  wire[31:0] T54;
  wire[47:0] T0;
  wire[47:0] T1;
  wire[47:0] T2;
  wire[47:0] T3;
  wire[47:0] T4;
  wire T5;
  wire[47:0] T55;
  wire[31:0] T6;
  reg [31:0] pc;
  wire[31:0] T56;
  wire[32:0] T57;
  wire[32:0] T7;
  wire[32:0] T58;
  wire[32:0] pc_next;
  wire[32:0] T8;
  wire[32:0] T59;
  wire[31:0] T9;
  wire[31:0] T10;
  wire T11;
  wire[31:0] T60;
  wire[27:0] T12;
  wire[27:0] T13;
  wire[25:0] T14;
  reg [31:0] inst_reg;
  wire[31:0] T61;
  wire[31:0] T15;
  wire[27:0] T62;
  wire[3:0] T16;
  wire T17;
  wire[32:0] T18;
  wire[32:0] T63;
  wire[31:0] T19;
  wire[31:0] T20;
  wire T21;
  wire[32:0] T22;
  wire[32:0] T23;
  wire[32:0] T24;
  wire[32:0] T25;
  wire[32:0] T64;
  wire[17:0] T26;
  wire[15:0] T27;
  wire[15:0] T28;
  wire[14:0] T65;
  wire T66;
  wire T29;
  wire T30;
  wire[32:0] T67;
  wire[31:0] T31;
  wire T32;
  wire T33;
  wire[47:0] T68;
  wire T34;
  wire[47:0] T69;
  wire T35;
  wire[4:0] T36;
  wire[4:0] T37;
  wire[4:0] T38;
  wire T39;
  wire[4:0] T40;
  wire T41;
  wire[4:0] T42;
  wire T43;
  wire[4:0] T44;
  wire[4:0] T45;
  wire[31:0] T46;
  wire[31:0] T47;
  wire[31:0] T48;
  wire[31:0] T49;
  wire T50;
  wire[1:0] T70;
  wire[31:0] T71;
  wire[15:0] T51;
  wire T52;
  wire T53;
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

  assign T54 = T0[5'h1f:1'h0];
  assign T0 = T35 ? T69 : T1;
  assign T1 = T34 ? T68 : T2;
  assign T2 = T33 ? T55 : T3;
  assign T3 = T5 ? T4 : 48'h0;
  assign T4 = alu_io_out << 5'h10;
  assign T5 = io_reg_we_src == 2'h3;
  assign T55 = {16'h0, T6};
  assign T6 = pc + 32'h4;
  assign T56 = T57[5'h1f:1'h0];
  assign T57 = reset ? 33'h0 : T7;
  assign T7 = io_pc_we ? pc_next : T58;
  assign T58 = {1'h0, pc};
  assign pc_next = T32 ? T67 : T8;
  assign T8 = T30 ? T18 : T59;
  assign T59 = {1'h0, T9};
  assign T9 = T17 ? T60 : T10;
  assign T10 = T11 ? regfile_io_douta : 32'h0;
  assign T11 = io_pc_next_sel == 2'h3;
  assign T60 = {4'h0, T12};
  assign T12 = T62 | T13;
  assign T13 = T14 << 2'h2;
  assign T14 = inst_reg[5'h19:1'h0];
  assign T61 = reset ? 32'h0 : T15;
  assign T15 = io_inst_we ? io_bus_data : inst_reg;
  assign T62 = {24'h0, T16};
  assign T16 = pc[5'h1f:5'h1c];
  assign T17 = io_pc_next_sel == 2'h2;
  assign T18 = T29 ? T22 : T63;
  assign T63 = {1'h0, T19};
  assign T19 = T21 ? T20 : 32'h0;
  assign T20 = pc + 32'h4;
  assign T21 = alu_io_zero == 1'h0;
  assign T22 = T23;
  assign T23 = T64 + T24;
  assign T24 = T25;
  assign T25 = {1'h0, pc};
  assign T64 = {T65, T26};
  assign T26 = T27 << 2'h2;
  assign T27 = T28;
  assign T28 = inst_reg[4'hf:1'h0];
  assign T65 = T66 ? 15'h7fff : 15'h0;
  assign T66 = T26[5'h11:5'h11];
  assign T29 = alu_io_zero == 1'h1;
  assign T30 = io_pc_next_sel == 2'h1;
  assign T67 = {1'h0, T31};
  assign T31 = pc + 32'h4;
  assign T32 = io_pc_next_sel == 2'h0;
  assign T33 = io_reg_we_src == 2'h2;
  assign T68 = {16'h0, io_bus_data};
  assign T34 = io_reg_we_src == 2'h1;
  assign T69 = {16'h0, alu_io_out};
  assign T35 = io_reg_we_src == 2'h0;
  assign T36 = T43 ? T42 : T37;
  assign T37 = T41 ? T40 : T38;
  assign T38 = T39 ? 5'h1f : 5'h0;
  assign T39 = io_reg_we_dst == 2'h2;
  assign T40 = inst_reg[5'h14:5'h10];
  assign T41 = io_reg_we_dst == 2'h1;
  assign T42 = inst_reg[4'hf:4'hb];
  assign T43 = io_reg_we_dst == 2'h0;
  assign T44 = inst_reg[5'h14:5'h10];
  assign T45 = inst_reg[5'h19:5'h15];
  assign T46 = T53 ? regfile_io_doutb : T47;
  assign T47 = T52 ? T71 : T48;
  assign T48 = T50 ? T49 : 32'h0;
  assign T49 = ~ regfile_io_doutb;
  assign T50 = T70 == 2'h2;
  assign T70 = {1'h0, io_alu_b_sel};
  assign T71 = {16'h0, T51};
  assign T51 = inst_reg[4'hf:1'h0];
  assign T52 = io_alu_b_sel == 1'h1;
  assign T53 = io_alu_b_sel == 1'h0;
  assign io_data_out = regfile_io_doutb;
  assign io_alu_out = alu_io_out;
  assign io_pc_out = pc;
  assign io_inst = inst_reg;
  ALU alu(
       .io_alu_op( io_alu_op ),
       .io_in_a( regfile_io_douta ),
       .io_in_b( T46 ),
       .io_out( alu_io_out ),
       .io_zero( alu_io_zero )
  );
  Register_File regfile(.clk(clk),
       .io_addra( T45 ),
       .io_douta( regfile_io_douta ),
       .io_addrb( T44 ),
       .io_doutb( regfile_io_doutb ),
       .io_wtaddr( T36 ),
       .io_wtdata( T54 ),
       .io_we( io_reg_we )
  );

  always @(posedge clk) begin
    pc <= T56;
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
  wire cpath_io_ctrl_alu_b_sel;
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
  reg  ack_out;
  wire T136;
  wire T2;
  wire[119:0] T3;
  wire T4;
  wire T5;
  wire T6;
  wire[127:0] T7;
  wire T8;
  wire T9;
  wire T10;
  wire ram_op;
  wire T11;
  wire[119:0] T12;
  wire T13;
  wire T14;
  wire T15;
  wire[119:0] T16;
  wire T17;
  wire T18;
  wire[2:0] T19;
  wire[2:0] current_slave;
  wire[175:0] T20;
  wire T21;
  wire T22;
  wire[31:0] T137;
  wire[27:0] T23;
  wire T24;
  wire T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire T30;
  wire T31;
  wire[31:0] T138;
  wire[27:0] T32;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire T37;
  wire T38;
  wire T39;
  wire T40;
  wire[31:0] T139;
  wire[27:0] T41;
  wire T42;
  wire T43;
  wire T44;
  wire T45;
  wire T46;
  wire T47;
  wire T48;
  wire T49;
  wire[31:0] T140;
  wire[27:0] T50;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire T55;
  wire T56;
  wire T57;
  wire T58;
  wire[31:0] T141;
  wire[27:0] T59;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire T66;
  wire T67;
  wire[31:0] T142;
  wire[27:0] T68;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire T73;
  wire T74;
  wire T75;
  wire T76;
  wire[31:0] T143;
  wire[27:0] T77;
  wire T78;
  wire T79;
  wire T80;
  wire T81;
  wire T82;
  wire T83;
  wire T84;
  wire T85;
  wire[31:0] T144;
  wire[27:0] T86;
  wire T87;
  wire T88;
  wire T89;
  wire T90;
  wire T91;
  wire T92;
  wire T93;
  wire T94;
  wire[31:0] T145;
  wire[27:0] T95;
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
  wire T109;
  wire T110;
  wire T111;
  wire T112;
  wire T113;
  wire T114;
  wire T115;
  wire[31:0] T116;
  wire[31:0] T117;
  wire T118;
  wire[31:0] T119;
  wire[31:0] T120;
  wire[31:0] T121;
  wire[31:0] T122;
  wire[31:0] T123;
  wire[31:0] T124;
  wire[31:0] T125;
  wire[31:0] T126;
  wire T127;
  wire T128;
  wire T129;
  wire T130;
  wire T131;
  wire T132;
  wire T133;
  wire T134;
  wire T135;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    ack_out = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = ack_out & T1;
  assign T1 = reset ^ 1'h1;
  assign T136 = reset ? 1'h1 : ack_out;
  assign T2 = io_slaves_2_we;
  assign T4 = ack_out & T5;
  assign T5 = reset ^ 1'h1;
  assign T6 = io_slaves_2_sel;
  assign T8 = ack_out & T9;
  assign T9 = reset ^ 1'h1;
  assign T10 = ram_op;
  assign ram_op = ~ T11;
  assign T11 = io_from_cpu_addr[5'h1f:5'h1f];
  assign T13 = ack_out & T14;
  assign T14 = reset ^ 1'h1;
  assign T15 = io_from_cpu_we;
  assign T17 = ack_out & T18;
  assign T18 = reset ^ 1'h1;
  assign T19 = current_slave;
  assign current_slave = io_from_cpu_addr[5'h1e:5'h1c];
  assign io_ram_slave_we = T21;
  assign T21 = ram_op & io_from_cpu_we;
  assign io_ram_slave_sel = T22;
  assign T22 = ram_op & io_from_cpu_sel;
  assign io_ram_slave_dat2 = io_from_cpu_dat2;
  assign io_ram_slave_addr = T137;
  assign T137 = {4'h0, T23};
  assign T23 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_0_we = T24;
  assign T24 = T26 & T25;
  assign T25 = current_slave == 3'h0;
  assign T26 = T27 & io_from_cpu_we;
  assign T27 = ~ ram_op;
  assign io_slaves_0_sel = T28;
  assign T28 = T30 & T29;
  assign T29 = current_slave == 3'h0;
  assign T30 = T31 & io_from_cpu_sel;
  assign T31 = ~ ram_op;
  assign io_slaves_0_dat2 = io_from_cpu_dat2;
  assign io_slaves_0_addr = T138;
  assign T138 = {4'h0, T32};
  assign T32 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_1_we = T33;
  assign T33 = T35 & T34;
  assign T34 = current_slave == 3'h1;
  assign T35 = T36 & io_from_cpu_we;
  assign T36 = ~ ram_op;
  assign io_slaves_1_sel = T37;
  assign T37 = T39 & T38;
  assign T38 = current_slave == 3'h1;
  assign T39 = T40 & io_from_cpu_sel;
  assign T40 = ~ ram_op;
  assign io_slaves_1_dat2 = io_from_cpu_dat2;
  assign io_slaves_1_addr = T139;
  assign T139 = {4'h0, T41};
  assign T41 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_2_we = T42;
  assign T42 = T44 & T43;
  assign T43 = current_slave == 3'h2;
  assign T44 = T45 & io_from_cpu_we;
  assign T45 = ~ ram_op;
  assign io_slaves_2_sel = T46;
  assign T46 = T48 & T47;
  assign T47 = current_slave == 3'h2;
  assign T48 = T49 & io_from_cpu_sel;
  assign T49 = ~ ram_op;
  assign io_slaves_2_dat2 = io_from_cpu_dat2;
  assign io_slaves_2_addr = T140;
  assign T140 = {4'h0, T50};
  assign T50 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_3_we = T51;
  assign T51 = T53 & T52;
  assign T52 = current_slave == 3'h3;
  assign T53 = T54 & io_from_cpu_we;
  assign T54 = ~ ram_op;
  assign io_slaves_3_sel = T55;
  assign T55 = T57 & T56;
  assign T56 = current_slave == 3'h3;
  assign T57 = T58 & io_from_cpu_sel;
  assign T58 = ~ ram_op;
  assign io_slaves_3_dat2 = io_from_cpu_dat2;
  assign io_slaves_3_addr = T141;
  assign T141 = {4'h0, T59};
  assign T59 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_4_we = T60;
  assign T60 = T62 & T61;
  assign T61 = current_slave == 3'h4;
  assign T62 = T63 & io_from_cpu_we;
  assign T63 = ~ ram_op;
  assign io_slaves_4_sel = T64;
  assign T64 = T66 & T65;
  assign T65 = current_slave == 3'h4;
  assign T66 = T67 & io_from_cpu_sel;
  assign T67 = ~ ram_op;
  assign io_slaves_4_dat2 = io_from_cpu_dat2;
  assign io_slaves_4_addr = T142;
  assign T142 = {4'h0, T68};
  assign T68 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_5_we = T69;
  assign T69 = T71 & T70;
  assign T70 = current_slave == 3'h5;
  assign T71 = T72 & io_from_cpu_we;
  assign T72 = ~ ram_op;
  assign io_slaves_5_sel = T73;
  assign T73 = T75 & T74;
  assign T74 = current_slave == 3'h5;
  assign T75 = T76 & io_from_cpu_sel;
  assign T76 = ~ ram_op;
  assign io_slaves_5_dat2 = io_from_cpu_dat2;
  assign io_slaves_5_addr = T143;
  assign T143 = {4'h0, T77};
  assign T77 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_6_we = T78;
  assign T78 = T80 & T79;
  assign T79 = current_slave == 3'h6;
  assign T80 = T81 & io_from_cpu_we;
  assign T81 = ~ ram_op;
  assign io_slaves_6_sel = T82;
  assign T82 = T84 & T83;
  assign T83 = current_slave == 3'h6;
  assign T84 = T85 & io_from_cpu_sel;
  assign T85 = ~ ram_op;
  assign io_slaves_6_dat2 = io_from_cpu_dat2;
  assign io_slaves_6_addr = T144;
  assign T144 = {4'h0, T86};
  assign T86 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_slaves_7_we = T87;
  assign T87 = T89 & T88;
  assign T88 = current_slave == 3'h7;
  assign T89 = T90 & io_from_cpu_we;
  assign T90 = ~ ram_op;
  assign io_slaves_7_sel = T91;
  assign T91 = T93 & T92;
  assign T92 = current_slave == 3'h7;
  assign T93 = T94 & io_from_cpu_sel;
  assign T94 = ~ ram_op;
  assign io_slaves_7_dat2 = io_from_cpu_dat2;
  assign io_slaves_7_addr = T145;
  assign T145 = {4'h0, T95};
  assign T95 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_from_cpu_ack = T96;
  assign T96 = T115 ? T99 : T97;
  assign T97 = T98 ? io_ram_slave_ack : 1'h0;
  assign T98 = ram_op == 1'h1;
  assign T99 = T114 ? io_slaves_0_ack : T100;
  assign T100 = T113 ? io_slaves_1_ack : T101;
  assign T101 = T112 ? io_slaves_2_ack : T102;
  assign T102 = T111 ? io_slaves_3_ack : T103;
  assign T103 = T110 ? io_slaves_4_ack : T104;
  assign T104 = T109 ? io_slaves_5_ack : T105;
  assign T105 = T108 ? io_slaves_6_ack : T106;
  assign T106 = T107 ? io_slaves_7_ack : 1'h0;
  assign T107 = current_slave == 3'h7;
  assign T108 = current_slave == 3'h6;
  assign T109 = current_slave == 3'h5;
  assign T110 = current_slave == 3'h4;
  assign T111 = current_slave == 3'h3;
  assign T112 = current_slave == 3'h2;
  assign T113 = current_slave == 3'h1;
  assign T114 = current_slave == 3'h0;
  assign T115 = ram_op == 1'h0;
  assign io_from_cpu_dat4 = T116;
  assign T116 = T135 ? T119 : T117;
  assign T117 = T118 ? io_ram_slave_dat4 : 32'h0;
  assign T118 = ram_op == 1'h1;
  assign T119 = T134 ? io_slaves_0_dat4 : T120;
  assign T120 = T133 ? io_slaves_1_dat4 : T121;
  assign T121 = T132 ? io_slaves_2_dat4 : T122;
  assign T122 = T131 ? io_slaves_3_dat4 : T123;
  assign T123 = T130 ? io_slaves_4_dat4 : T124;
  assign T124 = T129 ? io_slaves_5_dat4 : T125;
  assign T125 = T128 ? io_slaves_6_dat4 : T126;
  assign T126 = T127 ? io_slaves_7_dat4 : 32'h0;
  assign T127 = current_slave == 3'h7;
  assign T128 = current_slave == 3'h6;
  assign T129 = current_slave == 3'h5;
  assign T130 = current_slave == 3'h4;
  assign T131 = current_slave == 3'h3;
  assign T132 = current_slave == 3'h2;
  assign T133 = current_slave == 3'h1;
  assign T134 = current_slave == 3'h0;
  assign T135 = ram_op == 1'h0;

  always @(posedge clk) begin
    if(reset) begin
      ack_out <= 1'h1;
    end
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T17)
        $fwrite(32'h80000002, " --- current_slave: %d\n", T19);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T13)
        $fwrite(32'h80000002, " --- cpu_we: %d\n", T15);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T8)
        $fwrite(32'h80000002, " --- ram_op: %d\n", T10);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T4)
        $fwrite(32'h80000002, " --- led_sel: %d\n", T6);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T0)
        $fwrite(32'h80000002, " --- led_we: %d\n", T2);
// synthesis translate_on
`endif
  end
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

  wire T0;
  wire T1;
  wire T2;
  wire[31:0] T3;
  wire[183:0] T4;
  wire T5;
  wire T6;
  wire T7;
  wire[95:0] T8;
  wire T9;
  wire T10;
  wire T11;
  wire[103:0] T12;
  reg [7:0] led_data;
  wire[7:0] T21;
  wire[31:0] T22;
  wire[31:0] T13;
  wire[31:0] T23;
  reg [31:0] data_out;
  wire[31:0] T24;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire[31:0] T25;
  wire T17;
  wire T18;
  wire T19;
  wire T20;

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

  assign T0 = T2 & T1;
  assign T1 = reset ^ 1'h1;
  assign T2 = io_bus_sel & io_bus_we;
  assign T3 = io_bus_dat2;
  assign T5 = T2 & T6;
  assign T6 = reset ^ 1'h1;
  assign T7 = io_bus_we;
  assign T9 = T2 & T10;
  assign T10 = reset ^ 1'h1;
  assign T11 = io_bus_sel;
  assign io_LED = led_data;
  assign T21 = T22[3'h7:1'h0];
  assign T22 = reset ? 32'h0 : T13;
  assign T13 = T2 ? io_bus_dat2 : T23;
  assign T23 = {24'h0, led_data};
  assign io_bus_ack = 1'h1;
  assign io_bus_dat4 = data_out;
  assign T24 = reset ? 32'h0 : T14;
  assign T14 = T19 ? 32'h0 : T15;
  assign T15 = T17 ? T25 : T16;
  assign T16 = T2 ? io_bus_dat2 : data_out;
  assign T25 = {24'h0, led_data};
  assign T17 = T18 & io_bus_sel;
  assign T18 = T2 ^ 1'h1;
  assign T19 = T20 ^ 1'h1;
  assign T20 = T2 | io_bus_sel;

  always @(posedge clk) begin
    led_data <= T21;
    if(reset) begin
      data_out <= 32'h0;
    end else if(T19) begin
      data_out <= 32'h0;
    end else if(T17) begin
      data_out <= T25;
    end else if(T2) begin
      data_out <= io_bus_dat2;
    end
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T9)
        $fwrite(32'h80000002, " ---- sel: %d\n", T11);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T5)
        $fwrite(32'h80000002, " ---- we: %d\n", T7);
// synthesis translate_on
`endif
`ifndef SYNTHESIS
// synthesis translate_off
`ifdef PRINTF_COND
    if (`PRINTF_COND)
`endif
      if (T0)
        $fwrite(32'h80000002, " ---- data: %d\n", T3);
// synthesis translate_on
`endif
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
    output[31:0] io_devices_DISP_NUM
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
  wire[31:0] ram_io_douta;
  wire[31:0] WB_Empty_Dev_io_bus_dat4;
  wire WB_Empty_Dev_io_bus_ack;
  wire[31:0] WB_Empty_Dev_1_io_bus_dat4;
  wire WB_Empty_Dev_1_io_bus_ack;
  wire[31:0] WB_Empty_Dev_2_io_bus_dat4;
  wire WB_Empty_Dev_2_io_bus_ack;


  assign io_devices_DISP_NUM = seven_seg_io_DISP_NUM;
  assign io_devices_LED = led_io_LED;
  assign io_bus_ack = bus_io_from_cpu_ack;
  assign io_bus_dat4 = bus_io_from_cpu_dat4;
  WB_Bus bus(.clk(clk), .reset(reset),
       .io_from_cpu_addr( io_bus_addr ),
       .io_from_cpu_dat2( io_bus_dat2 ),
       .io_from_cpu_dat4( bus_io_from_cpu_dat4 ),
       .io_from_cpu_sel( io_bus_sel ),
       .io_from_cpu_we( io_bus_we ),
       .io_from_cpu_ack( bus_io_from_cpu_ack ),
       .io_slaves_7_addr( bus_io_slaves_7_addr ),
       .io_slaves_7_dat2( bus_io_slaves_7_dat2 ),
       .io_slaves_7_dat4( WB_Empty_Dev_2_io_bus_dat4 ),
       .io_slaves_7_sel( bus_io_slaves_7_sel ),
       .io_slaves_7_we( bus_io_slaves_7_we ),
       .io_slaves_7_ack( WB_Empty_Dev_2_io_bus_ack ),
       .io_slaves_6_addr( bus_io_slaves_6_addr ),
       .io_slaves_6_dat2( bus_io_slaves_6_dat2 ),
       .io_slaves_6_dat4( WB_Empty_Dev_1_io_bus_dat4 ),
       .io_slaves_6_sel( bus_io_slaves_6_sel ),
       .io_slaves_6_we( bus_io_slaves_6_we ),
       .io_slaves_6_ack( WB_Empty_Dev_1_io_bus_ack ),
       .io_slaves_5_addr( bus_io_slaves_5_addr ),
       .io_slaves_5_dat2( bus_io_slaves_5_dat2 ),
       .io_slaves_5_dat4( WB_Empty_Dev_io_bus_dat4 ),
       .io_slaves_5_sel( bus_io_slaves_5_sel ),
       .io_slaves_5_we( bus_io_slaves_5_we ),
       .io_slaves_5_ack( WB_Empty_Dev_io_bus_ack ),
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
  WB_Empty_Dev counter(
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
       .io_ram_douta( ram_io_douta )
  );
  Ram_Wrap ram(
       .io_addra( ram_dev_io_ram_addra ),
       .io_dina( ram_dev_io_ram_dina ),
       .io_we( ram_dev_io_ram_we ),
       .io_douta( ram_io_douta )
  );
  WB_Empty_Dev WB_Empty_Dev(
       .io_bus_addr( bus_io_slaves_5_addr ),
       .io_bus_dat2( bus_io_slaves_5_dat2 ),
       .io_bus_dat4( WB_Empty_Dev_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_5_sel ),
       .io_bus_we( bus_io_slaves_5_we ),
       .io_bus_ack( WB_Empty_Dev_io_bus_ack )
  );
  WB_Empty_Dev WB_Empty_Dev_1(
       .io_bus_addr( bus_io_slaves_6_addr ),
       .io_bus_dat2( bus_io_slaves_6_dat2 ),
       .io_bus_dat4( WB_Empty_Dev_1_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_6_sel ),
       .io_bus_we( bus_io_slaves_6_we ),
       .io_bus_ack( WB_Empty_Dev_1_io_bus_ack )
  );
  WB_Empty_Dev WB_Empty_Dev_2(
       .io_bus_addr( bus_io_slaves_7_addr ),
       .io_bus_dat2( bus_io_slaves_7_dat2 ),
       .io_bus_dat4( WB_Empty_Dev_2_io_bus_dat4 ),
       .io_bus_sel( bus_io_slaves_7_sel ),
       .io_bus_we( bus_io_slaves_7_we ),
       .io_bus_ack( WB_Empty_Dev_2_io_bus_ack )
  );
endmodule

module SOC(input clk, input reset,
    input [7:0] io_devices_SW,
    output[7:0] io_devices_LED,
    input [4:0] io_devices_BTN,
    output[31:0] io_devices_DISP_NUM,
    output[31:0] io_debug_inst_out,
    output[31:0] io_debug_bus_addr,
    output[31:0] io_debug_bus_dat2,
    output[31:0] io_debug_bus_dat4,
    output[31:0] io_debug_pc_out
);

  wire[31:0] dev_io_bus_dat4;
  wire dev_io_bus_ack;
  wire[7:0] dev_io_devices_LED;
  wire[31:0] dev_io_devices_DISP_NUM;
  wire[31:0] cpu_io_bus_addr;
  wire[31:0] cpu_io_bus_dat2;
  wire cpu_io_bus_sel;
  wire cpu_io_bus_we;
  wire[31:0] cpu_io_debug_inst_out;
  wire[31:0] cpu_io_debug_bus_addr;
  wire[31:0] cpu_io_debug_bus_dat2;
  wire[31:0] cpu_io_debug_bus_dat4;
  wire[31:0] cpu_io_debug_pc_out;


  assign io_debug_pc_out = cpu_io_debug_pc_out;
  assign io_debug_bus_dat4 = cpu_io_debug_bus_dat4;
  assign io_debug_bus_dat2 = cpu_io_debug_bus_dat2;
  assign io_debug_bus_addr = cpu_io_debug_bus_addr;
  assign io_debug_inst_out = cpu_io_debug_inst_out;
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
       .io_devices_DISP_NUM( dev_io_devices_DISP_NUM )
  );
endmodule

