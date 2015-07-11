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
    output io_ctrl_ack,
    output[31:0] io_bus_addr,
    output[31:0] io_bus_dat2,
    input [31:0] io_bus_dat4,
    output io_bus_sel,
    output io_bus_we,
    input  io_bus_ack
);

  wire bus_we;
  wire T0;
  wire T1;
  wire T2;
  wire T3;
  wire T4;
  wire T5;
  wire T6;
  wire T7;
  wire T8;
  wire T9;
  wire T10;
  wire T11;
  wire T12;
  wire T13;
  wire T14;
  wire T15;
  wire T16;
  wire T17;
  wire T18;
  wire T19;
  wire T20;
  wire T21;
  wire T22;
  wire T23;
  wire T24;
  wire T25;
  wire T26;
  reg [31:0] state;
  wire[31:0] T461;
  wire[31:0] T27;
  wire[31:0] next_state;
  wire[31:0] T462;
  wire[7:0] T28;
  wire[7:0] T29;
  wire[7:0] T30;
  wire[7:0] T31;
  wire[7:0] T32;
  wire[7:0] T33;
  wire[7:0] T34;
  wire[7:0] T35;
  wire[7:0] T36;
  wire[7:0] T37;
  wire[7:0] T38;
  wire[7:0] T39;
  wire[7:0] T40;
  wire[7:0] T41;
  wire[7:0] T42;
  wire[7:0] T43;
  wire[7:0] T44;
  wire[7:0] T45;
  wire[7:0] T46;
  wire[7:0] T47;
  wire[7:0] T48;
  wire[7:0] T49;
  wire[7:0] T50;
  wire[7:0] T51;
  wire[7:0] T52;
  wire[7:0] T53;
  wire[7:0] T54;
  wire[7:0] T55;
  wire[7:0] T56;
  wire[7:0] T57;
  wire[7:0] T58;
  wire[7:0] T59;
  wire[7:0] T463;
  wire[4:0] T60;
  wire[4:0] T61;
  wire[4:0] T62;
  wire[4:0] T63;
  wire[4:0] T64;
  wire[4:0] T65;
  wire[4:0] T66;
  wire[4:0] T67;
  wire[4:0] T68;
  wire[4:0] T69;
  wire[4:0] T70;
  wire[4:0] T71;
  wire[4:0] T72;
  wire[4:0] T73;
  wire[4:0] T74;
  wire T75;
  wire[5:0] inst_op;
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
  wire[4:0] T464;
  wire[3:0] T88;
  wire[3:0] T89;
  wire[3:0] T90;
  wire[3:0] T91;
  wire[3:0] T92;
  wire[3:0] T93;
  wire[3:0] T94;
  wire[3:0] T95;
  wire[3:0] T96;
  wire[3:0] T97;
  wire[3:0] T98;
  wire T99;
  wire[5:0] inst_func;
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
  wire T125;
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
  wire T163;
  wire T164;
  wire T165;
  wire T166;
  wire T167;
  wire T168;
  wire T169;
  wire inst_we;
  wire bus_sel;
  wire T170;
  wire T171;
  wire T172;
  wire T173;
  wire T174;
  wire T175;
  wire T176;
  wire T177;
  wire T178;
  wire T179;
  wire T180;
  wire T181;
  wire T182;
  wire T183;
  wire T184;
  wire T185;
  wire T186;
  wire T187;
  wire T188;
  wire T189;
  wire T190;
  wire T191;
  wire T192;
  wire T193;
  wire T194;
  wire T195;
  wire[31:0] T196;
  wire T197;
  wire bus_addr_src;
  wire T198;
  wire T199;
  wire T200;
  wire T201;
  wire T202;
  wire T203;
  wire T204;
  wire T205;
  wire T206;
  wire T207;
  wire T208;
  wire T209;
  wire T210;
  wire T211;
  wire T212;
  wire T213;
  wire T214;
  wire T215;
  wire T216;
  wire T217;
  wire T218;
  wire T219;
  wire T220;
  wire T221;
  wire T222;
  wire T223;
  wire[1:0] alu_b_sel;
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
  wire[1:0] T236;
  wire[1:0] T237;
  wire[1:0] T238;
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
  wire T256;
  wire T257;
  wire T258;
  wire T259;
  wire T260;
  wire[2:0] alu_op;
  wire[2:0] T261;
  wire[2:0] T262;
  wire[2:0] T263;
  wire[2:0] T264;
  wire[2:0] T265;
  wire[2:0] T266;
  wire[2:0] T267;
  wire[2:0] T268;
  wire[2:0] T269;
  wire[2:0] T270;
  wire[2:0] T271;
  wire[2:0] T272;
  wire[2:0] T273;
  wire[2:0] T274;
  wire[2:0] T275;
  wire[2:0] T276;
  wire[2:0] T277;
  wire[2:0] T278;
  wire[2:0] T279;
  wire[2:0] T280;
  wire[2:0] T281;
  wire[2:0] T282;
  wire[2:0] T283;
  wire[2:0] T284;
  wire[2:0] T285;
  wire[2:0] T286;
  wire[2:0] T287;
  wire[2:0] T288;
  wire[2:0] T289;
  wire[2:0] T290;
  wire[2:0] T291;
  wire[2:0] T292;
  wire[1:0] reg_we_dst;
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
  wire[1:0] T312;
  wire[1:0] T313;
  wire[1:0] T314;
  wire[1:0] T315;
  wire[1:0] T316;
  wire[1:0] T317;
  wire[1:0] T318;
  wire[1:0] T319;
  wire[1:0] T320;
  wire[1:0] T321;
  wire[1:0] T322;
  wire[1:0] T323;
  wire[1:0] T324;
  wire[1:0] T325;
  wire[1:0] T326;
  wire T327;
  wire T328;
  wire[1:0] reg_we_src;
  wire[1:0] T329;
  wire[1:0] T330;
  wire[1:0] T331;
  wire[1:0] T332;
  wire[1:0] T333;
  wire[1:0] T334;
  wire[1:0] T335;
  wire[1:0] T336;
  wire[1:0] T337;
  wire[1:0] T338;
  wire[1:0] T339;
  wire[1:0] T340;
  wire[1:0] T341;
  wire[1:0] T342;
  wire[1:0] T343;
  wire[1:0] T344;
  wire[1:0] T345;
  wire[1:0] T346;
  wire[1:0] T347;
  wire[1:0] T348;
  wire[1:0] T349;
  wire[1:0] T350;
  wire[1:0] T351;
  wire[1:0] T352;
  wire[1:0] T353;
  wire[1:0] T354;
  wire[1:0] T355;
  wire[1:0] T356;
  wire[1:0] T357;
  wire[1:0] T358;
  wire[1:0] T359;
  wire[1:0] T360;
  wire[1:0] T361;
  wire[1:0] T362;
  wire reg_we;
  wire T363;
  wire T364;
  wire T365;
  wire T366;
  wire T367;
  wire T368;
  wire T369;
  wire T370;
  wire T371;
  wire T372;
  wire T373;
  wire T374;
  wire T375;
  wire T376;
  wire T377;
  wire T378;
  wire T379;
  wire T380;
  wire T381;
  wire T382;
  wire T383;
  wire T384;
  wire T385;
  wire T386;
  wire T387;
  wire T388;
  wire T389;
  wire T390;
  wire T391;
  wire T392;
  wire T393;
  wire T394;
  wire T395;
  wire[1:0] pc_next_sel;
  wire[1:0] T396;
  wire[1:0] T397;
  wire[1:0] T398;
  wire[1:0] T399;
  wire[1:0] T400;
  wire[1:0] T401;
  wire[1:0] T402;
  wire[1:0] T403;
  wire[1:0] T404;
  wire[1:0] T405;
  wire[1:0] T406;
  wire[1:0] T407;
  wire[1:0] T408;
  wire[1:0] T409;
  wire[1:0] T410;
  wire[1:0] T411;
  wire[1:0] T412;
  wire[1:0] T413;
  wire[1:0] T414;
  wire[1:0] T415;
  wire[1:0] T416;
  wire[1:0] T417;
  wire[1:0] T418;
  wire[1:0] T419;
  wire[1:0] T420;
  wire[1:0] T421;
  wire[1:0] T422;
  wire[1:0] T423;
  wire[1:0] T424;
  wire[1:0] T425;
  wire[1:0] T426;
  wire[1:0] T427;
  wire[1:0] T428;
  wire[1:0] T429;
  wire pc_we;
  wire T430;
  wire T431;
  wire T432;
  wire T433;
  wire T434;
  wire T435;
  wire T436;
  wire T437;
  wire T438;
  wire T439;
  wire T440;
  wire T441;
  wire T442;
  wire T443;
  wire T444;
  wire T445;
  wire T446;
  wire T447;
  wire T448;
  wire T449;
  wire T450;
  wire T451;
  wire T452;
  wire T453;
  wire T454;
  wire T455;
  wire T456;
  wire T457;
  wire T458;
  wire T459;
  wire T460;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    state = {1{$random}};
  end
// synthesis translate_on
`endif

  assign io_bus_we = bus_we;
  assign bus_we = inst_we ? 1'h0 : T0;
  assign T0 = T169 ? 1'h0 : T1;
  assign T1 = T168 ? 1'h0 : T2;
  assign T2 = T167 ? 1'h0 : T3;
  assign T3 = T166 ? 1'h0 : T4;
  assign T4 = T165 ? 1'h0 : T5;
  assign T5 = T164 ? 1'h0 : T6;
  assign T6 = T163 ? 1'h0 : T7;
  assign T7 = T162 ? 1'h0 : T8;
  assign T8 = T161 ? 1'h0 : T9;
  assign T9 = T160 ? 1'h0 : T10;
  assign T10 = T159 ? 1'h0 : T11;
  assign T11 = T158 ? 1'h0 : T12;
  assign T12 = T157 ? 1'h0 : T13;
  assign T13 = T156 ? 1'h0 : T14;
  assign T14 = T155 ? 1'h0 : T15;
  assign T15 = T154 ? 1'h0 : T16;
  assign T16 = T153 ? 1'h0 : T17;
  assign T17 = T152 ? 1'h0 : T18;
  assign T18 = T151 ? 1'h0 : T19;
  assign T19 = T150 ? 1'h0 : T20;
  assign T20 = T149 ? 1'h0 : T21;
  assign T21 = T148 ? 1'h0 : T22;
  assign T22 = T147 ? 1'h0 : T23;
  assign T23 = T146 ? 1'h0 : T24;
  assign T24 = T145 ? 1'h0 : T25;
  assign T25 = T144 ? 1'h0 : T26;
  assign T26 = state == 32'h7a;
  assign T461 = reset ? 32'h0 : T27;
  assign T27 = io_bus_ack ? next_state : state;
  assign next_state = T462;
  assign T462 = {24'h0, T28};
  assign T28 = T143 ? 8'h64 : T29;
  assign T29 = T142 ? 8'h64 : T30;
  assign T30 = T141 ? 8'h64 : T31;
  assign T31 = T140 ? 8'h64 : T32;
  assign T32 = T139 ? 8'h64 : T33;
  assign T33 = T138 ? 8'h64 : T34;
  assign T34 = T137 ? 8'h64 : T35;
  assign T35 = T136 ? 8'h64 : T36;
  assign T36 = T135 ? 8'h64 : T37;
  assign T37 = T134 ? 8'h64 : T38;
  assign T38 = T133 ? 8'h65 : T39;
  assign T39 = T132 ? 8'h65 : T40;
  assign T40 = T131 ? 8'h65 : T41;
  assign T41 = T130 ? 8'h65 : T42;
  assign T42 = T129 ? 8'h65 : T43;
  assign T43 = T128 ? 8'h65 : T44;
  assign T44 = T127 ? 8'h66 : T45;
  assign T45 = T126 ? 8'h78 : T46;
  assign T46 = T125 ? 8'h79 : T47;
  assign T47 = T124 ? 8'h6e : T48;
  assign T48 = T123 ? 8'h7a : T49;
  assign T49 = T122 ? 8'h6e : T50;
  assign T50 = T121 ? 8'h96 : T51;
  assign T51 = T120 ? 8'h97 : T52;
  assign T52 = T119 ? 8'h6e : T53;
  assign T53 = T118 ? 8'h6e : T54;
  assign T54 = T117 ? 8'h6e : T55;
  assign T55 = T116 ? 8'h0 : T56;
  assign T56 = T115 ? 8'h0 : T57;
  assign T57 = T114 ? 8'h0 : T58;
  assign T58 = T113 ? 8'h0 : T59;
  assign T59 = T112 ? 8'hc8 : T463;
  assign T463 = {3'h0, T60};
  assign T60 = T111 ? T61 : 5'h0;
  assign T61 = T110 ? T464 : T62;
  assign T62 = T87 ? 5'hc : T63;
  assign T63 = T86 ? 5'hd : T64;
  assign T64 = T85 ? 5'he : T65;
  assign T65 = T84 ? 5'hf : T66;
  assign T66 = T83 ? 5'h10 : T67;
  assign T67 = T82 ? 5'h11 : T68;
  assign T68 = T81 ? 5'h12 : T69;
  assign T69 = T80 ? 5'h13 : T70;
  assign T70 = T79 ? 5'h14 : T71;
  assign T71 = T78 ? 5'h15 : T72;
  assign T72 = T77 ? 5'h16 : T73;
  assign T73 = T76 ? 5'h17 : T74;
  assign T74 = T75 ? 5'h18 : 5'h0;
  assign T75 = inst_op == 6'h3;
  assign inst_op = io_ctrl_inst[5'h1f:5'h1a];
  assign T76 = inst_op == 6'h2;
  assign T77 = inst_op == 6'ha;
  assign T78 = inst_op == 6'h5;
  assign T79 = inst_op == 6'h4;
  assign T80 = inst_op == 6'h2b;
  assign T81 = inst_op == 6'h23;
  assign T82 = inst_op == 6'hf;
  assign T83 = inst_op == 6'he;
  assign T84 = inst_op == 6'hd;
  assign T85 = inst_op == 6'hc;
  assign T86 = inst_op == 6'h9;
  assign T87 = inst_op == 6'h8;
  assign T464 = {1'h0, T88};
  assign T88 = T109 ? 4'h1 : T89;
  assign T89 = T108 ? 4'h2 : T90;
  assign T90 = T107 ? 4'h3 : T91;
  assign T91 = T106 ? 4'h4 : T92;
  assign T92 = T105 ? 4'h5 : T93;
  assign T93 = T104 ? 4'h6 : T94;
  assign T94 = T103 ? 4'h7 : T95;
  assign T95 = T102 ? 4'h8 : T96;
  assign T96 = T101 ? 4'h9 : T97;
  assign T97 = T100 ? 4'ha : T98;
  assign T98 = T99 ? 4'hb : 4'h0;
  assign T99 = inst_func == 6'h8;
  assign inst_func = io_ctrl_inst[3'h5:1'h0];
  assign T100 = inst_func == 6'h6;
  assign T101 = inst_func == 6'h2a;
  assign T102 = inst_func == 6'h27;
  assign T103 = inst_func == 6'h26;
  assign T104 = inst_func == 6'h25;
  assign T105 = inst_func == 6'h24;
  assign T106 = inst_func == 6'h23;
  assign T107 = inst_func == 6'h22;
  assign T108 = inst_func == 6'h21;
  assign T109 = inst_func == 6'h20;
  assign T110 = inst_op == 6'h0;
  assign T111 = state == 32'hc8;
  assign T112 = state == 32'h0;
  assign T113 = state == 32'h18;
  assign T114 = state == 32'h97;
  assign T115 = state == 32'h96;
  assign T116 = state == 32'h6e;
  assign T117 = state == 32'h66;
  assign T118 = state == 32'h65;
  assign T119 = state == 32'h64;
  assign T120 = state == 32'h15;
  assign T121 = state == 32'h14;
  assign T122 = state == 32'h7a;
  assign T123 = state == 32'h13;
  assign T124 = state == 32'h79;
  assign T125 = state == 32'h78;
  assign T126 = state == 32'h12;
  assign T127 = state == 32'h11;
  assign T128 = state == 32'h16;
  assign T129 = state == 32'h10;
  assign T130 = state == 32'hf;
  assign T131 = state == 32'he;
  assign T132 = state == 32'hd;
  assign T133 = state == 32'hc;
  assign T134 = state == 32'ha;
  assign T135 = state == 32'h9;
  assign T136 = state == 32'h8;
  assign T137 = state == 32'h7;
  assign T138 = state == 32'h6;
  assign T139 = state == 32'h5;
  assign T140 = state == 32'h4;
  assign T141 = state == 32'h3;
  assign T142 = state == 32'h2;
  assign T143 = state == 32'h1;
  assign T144 = state == 32'h79;
  assign T145 = state == 32'h78;
  assign T146 = state == 32'h13;
  assign T147 = state == 32'h12;
  assign T148 = state == 32'h66;
  assign T149 = state == 32'h11;
  assign T150 = state == 32'h65;
  assign T151 = state == 32'h16;
  assign T152 = state == 32'h10;
  assign T153 = state == 32'hf;
  assign T154 = state == 32'he;
  assign T155 = state == 32'hd;
  assign T156 = state == 32'hc;
  assign T157 = state == 32'h64;
  assign T158 = state == 32'hb;
  assign T159 = state == 32'ha;
  assign T160 = state == 32'h9;
  assign T161 = state == 32'h8;
  assign T162 = state == 32'h7;
  assign T163 = state == 32'h6;
  assign T164 = state == 32'h5;
  assign T165 = state == 32'h4;
  assign T166 = state == 32'h3;
  assign T167 = state == 32'h2;
  assign T168 = state == 32'h1;
  assign T169 = state == 32'hc8;
  assign inst_we = state == 32'h0;
  assign io_bus_sel = bus_sel;
  assign bus_sel = inst_we ? 1'h1 : T170;
  assign T170 = T169 ? 1'h0 : T171;
  assign T171 = T168 ? 1'h0 : T172;
  assign T172 = T167 ? 1'h0 : T173;
  assign T173 = T166 ? 1'h0 : T174;
  assign T174 = T165 ? 1'h0 : T175;
  assign T175 = T164 ? 1'h0 : T176;
  assign T176 = T163 ? 1'h0 : T177;
  assign T177 = T162 ? 1'h0 : T178;
  assign T178 = T161 ? 1'h0 : T179;
  assign T179 = T160 ? 1'h0 : T180;
  assign T180 = T159 ? 1'h0 : T181;
  assign T181 = T158 ? 1'h0 : T182;
  assign T182 = T157 ? 1'h0 : T183;
  assign T183 = T156 ? 1'h0 : T184;
  assign T184 = T155 ? 1'h0 : T185;
  assign T185 = T154 ? 1'h0 : T186;
  assign T186 = T153 ? 1'h0 : T187;
  assign T187 = T152 ? 1'h0 : T188;
  assign T188 = T151 ? 1'h0 : T189;
  assign T189 = T150 ? 1'h0 : T190;
  assign T190 = T149 ? 1'h0 : T191;
  assign T191 = T148 ? 1'h0 : T192;
  assign T192 = T147 ? 1'h0 : T193;
  assign T193 = T146 ? 1'h0 : T194;
  assign T194 = T145 ? 1'h1 : T195;
  assign T195 = T144 ? 1'h0 : T26;
  assign io_bus_dat2 = io_ctrl_data_out;
  assign io_bus_addr = T196;
  assign T196 = T197 ? io_ctrl_alu_out : io_ctrl_pc_out;
  assign T197 = bus_addr_src;
  assign bus_addr_src = inst_we ? 1'h0 : T198;
  assign T198 = T169 ? 1'h0 : T199;
  assign T199 = T168 ? 1'h0 : T200;
  assign T200 = T167 ? 1'h0 : T201;
  assign T201 = T166 ? 1'h0 : T202;
  assign T202 = T165 ? 1'h0 : T203;
  assign T203 = T164 ? 1'h0 : T204;
  assign T204 = T163 ? 1'h0 : T205;
  assign T205 = T162 ? 1'h0 : T206;
  assign T206 = T161 ? 1'h0 : T207;
  assign T207 = T160 ? 1'h0 : T208;
  assign T208 = T159 ? 1'h0 : T209;
  assign T209 = T158 ? 1'h0 : T210;
  assign T210 = T157 ? 1'h0 : T211;
  assign T211 = T156 ? 1'h0 : T212;
  assign T212 = T155 ? 1'h0 : T213;
  assign T213 = T154 ? 1'h0 : T214;
  assign T214 = T153 ? 1'h0 : T215;
  assign T215 = T152 ? 1'h0 : T216;
  assign T216 = T151 ? 1'h0 : T217;
  assign T217 = T150 ? 1'h0 : T218;
  assign T218 = T149 ? 1'h0 : T219;
  assign T219 = T148 ? 1'h0 : T220;
  assign T220 = T147 ? 1'h1 : T221;
  assign T221 = T146 ? 1'h1 : T222;
  assign T222 = T145 ? 1'h1 : T223;
  assign T223 = T144 ? 1'h1 : T26;
  assign io_ctrl_ack = io_bus_ack;
  assign io_ctrl_alu_b_sel = alu_b_sel;
  assign alu_b_sel = inst_we ? 2'h0 : T224;
  assign T224 = T169 ? 2'h0 : T225;
  assign T225 = T168 ? 2'h0 : T226;
  assign T226 = T167 ? 2'h0 : T227;
  assign T227 = T166 ? 2'h0 : T228;
  assign T228 = T165 ? 2'h0 : T229;
  assign T229 = T164 ? 2'h0 : T230;
  assign T230 = T163 ? 2'h0 : T231;
  assign T231 = T162 ? 2'h0 : T232;
  assign T232 = T161 ? 2'h0 : T233;
  assign T233 = T160 ? 2'h0 : T234;
  assign T234 = T159 ? 2'h0 : T235;
  assign T235 = T158 ? 2'h0 : T236;
  assign T236 = T157 ? 2'h0 : T237;
  assign T237 = T156 ? 2'h1 : T238;
  assign T238 = T155 ? 2'h1 : T239;
  assign T239 = T154 ? 2'h1 : T240;
  assign T240 = T153 ? 2'h1 : T241;
  assign T241 = T152 ? 2'h1 : T242;
  assign T242 = T151 ? 2'h1 : T243;
  assign T243 = T150 ? 2'h0 : T244;
  assign T244 = T149 ? 2'h1 : T245;
  assign T245 = T148 ? 2'h1 : T246;
  assign T246 = T147 ? 2'h1 : T247;
  assign T247 = T146 ? 2'h1 : T248;
  assign T248 = T145 ? 2'h1 : T249;
  assign T249 = T144 ? 2'h1 : T250;
  assign T250 = T26 ? 2'h1 : T251;
  assign T251 = T260 ? 2'h1 : T252;
  assign T252 = T259 ? 2'h0 : T253;
  assign T253 = T258 ? 2'h0 : T254;
  assign T254 = T257 ? 2'h2 : T255;
  assign T255 = T256 ? 2'h2 : 2'h0;
  assign T256 = state == 32'h97;
  assign T257 = state == 32'h15;
  assign T258 = state == 32'h96;
  assign T259 = state == 32'h14;
  assign T260 = state == 32'h6e;
  assign io_ctrl_alu_op = alu_op;
  assign alu_op = inst_we ? 3'h0 : T261;
  assign T261 = T169 ? 3'h0 : T262;
  assign T262 = T168 ? 3'h2 : T263;
  assign T263 = T167 ? 3'h2 : T264;
  assign T264 = T166 ? 3'h6 : T265;
  assign T265 = T165 ? 3'h6 : T266;
  assign T266 = T164 ? 3'h0 : T267;
  assign T267 = T163 ? 3'h1 : T268;
  assign T268 = T162 ? 3'h3 : T269;
  assign T269 = T161 ? 3'h4 : T270;
  assign T270 = T160 ? 3'h7 : T271;
  assign T271 = T159 ? 3'h5 : T272;
  assign T272 = T158 ? 3'h0 : T273;
  assign T273 = T157 ? 3'h0 : T274;
  assign T274 = T156 ? 3'h2 : T275;
  assign T275 = T155 ? 3'h2 : T276;
  assign T276 = T154 ? 3'h0 : T277;
  assign T277 = T153 ? 3'h1 : T278;
  assign T278 = T152 ? 3'h3 : T279;
  assign T279 = T151 ? 3'h7 : T280;
  assign T280 = T150 ? 3'h0 : T281;
  assign T281 = T149 ? 3'h2 : T282;
  assign T282 = T148 ? 3'h2 : T283;
  assign T283 = T147 ? 3'h2 : T284;
  assign T284 = T146 ? 3'h2 : T285;
  assign T285 = T145 ? 3'h2 : T286;
  assign T286 = T144 ? 3'h2 : T287;
  assign T287 = T26 ? 3'h2 : T288;
  assign T288 = T260 ? 3'h2 : T289;
  assign T289 = T259 ? 3'h6 : T290;
  assign T290 = T258 ? 3'h6 : T291;
  assign T291 = T257 ? 3'h6 : T292;
  assign T292 = T256 ? 3'h6 : 3'h0;
  assign io_ctrl_reg_we_dst = reg_we_dst;
  assign reg_we_dst = inst_we ? 2'h0 : T293;
  assign T293 = T169 ? 2'h0 : T294;
  assign T294 = T168 ? 2'h0 : T295;
  assign T295 = T167 ? 2'h0 : T296;
  assign T296 = T166 ? 2'h0 : T297;
  assign T297 = T165 ? 2'h0 : T298;
  assign T298 = T164 ? 2'h0 : T299;
  assign T299 = T163 ? 2'h0 : T300;
  assign T300 = T162 ? 2'h0 : T301;
  assign T301 = T161 ? 2'h0 : T302;
  assign T302 = T160 ? 2'h0 : T303;
  assign T303 = T159 ? 2'h0 : T304;
  assign T304 = T158 ? 2'h0 : T305;
  assign T305 = T157 ? 2'h0 : T306;
  assign T306 = T156 ? 2'h1 : T307;
  assign T307 = T155 ? 2'h1 : T308;
  assign T308 = T154 ? 2'h1 : T309;
  assign T309 = T153 ? 2'h1 : T310;
  assign T310 = T152 ? 2'h1 : T311;
  assign T311 = T151 ? 2'h1 : T312;
  assign T312 = T150 ? 2'h1 : T313;
  assign T313 = T149 ? 2'h1 : T314;
  assign T314 = T148 ? 2'h1 : T315;
  assign T315 = T147 ? 2'h1 : T316;
  assign T316 = T146 ? 2'h0 : T317;
  assign T317 = T145 ? 2'h1 : T318;
  assign T318 = T144 ? 2'h1 : T319;
  assign T319 = T26 ? 2'h0 : T320;
  assign T320 = T260 ? 2'h0 : T321;
  assign T321 = T259 ? 2'h0 : T322;
  assign T322 = T258 ? 2'h0 : T323;
  assign T323 = T257 ? 2'h0 : T324;
  assign T324 = T256 ? 2'h0 : T325;
  assign T325 = T328 ? 2'h0 : T326;
  assign T326 = T327 ? 2'h2 : 2'h0;
  assign T327 = state == 32'h18;
  assign T328 = state == 32'h17;
  assign io_ctrl_reg_we_src = reg_we_src;
  assign reg_we_src = inst_we ? 2'h0 : T329;
  assign T329 = T169 ? 2'h0 : T330;
  assign T330 = T168 ? 2'h0 : T331;
  assign T331 = T167 ? 2'h0 : T332;
  assign T332 = T166 ? 2'h0 : T333;
  assign T333 = T165 ? 2'h0 : T334;
  assign T334 = T164 ? 2'h0 : T335;
  assign T335 = T163 ? 2'h0 : T336;
  assign T336 = T162 ? 2'h0 : T337;
  assign T337 = T161 ? 2'h0 : T338;
  assign T338 = T160 ? 2'h0 : T339;
  assign T339 = T159 ? 2'h0 : T340;
  assign T340 = T158 ? 2'h0 : T341;
  assign T341 = T157 ? 2'h0 : T342;
  assign T342 = T156 ? 2'h0 : T343;
  assign T343 = T155 ? 2'h0 : T344;
  assign T344 = T154 ? 2'h0 : T345;
  assign T345 = T153 ? 2'h0 : T346;
  assign T346 = T152 ? 2'h0 : T347;
  assign T347 = T151 ? 2'h0 : T348;
  assign T348 = T150 ? 2'h0 : T349;
  assign T349 = T149 ? 2'h3 : T350;
  assign T350 = T148 ? 2'h3 : T351;
  assign T351 = T147 ? 2'h1 : T352;
  assign T352 = T146 ? 2'h0 : T353;
  assign T353 = T145 ? 2'h1 : T354;
  assign T354 = T144 ? 2'h1 : T355;
  assign T355 = T26 ? 2'h0 : T356;
  assign T356 = T260 ? 2'h0 : T357;
  assign T357 = T259 ? 2'h0 : T358;
  assign T358 = T258 ? 2'h0 : T359;
  assign T359 = T257 ? 2'h0 : T360;
  assign T360 = T256 ? 2'h0 : T361;
  assign T361 = T328 ? 2'h0 : T362;
  assign T362 = T327 ? 2'h2 : 2'h0;
  assign io_ctrl_reg_we = reg_we;
  assign reg_we = inst_we ? 1'h0 : T363;
  assign T363 = T169 ? 1'h0 : T364;
  assign T364 = T168 ? 1'h0 : T365;
  assign T365 = T167 ? 1'h0 : T366;
  assign T366 = T166 ? 1'h0 : T367;
  assign T367 = T165 ? 1'h0 : T368;
  assign T368 = T164 ? 1'h0 : T369;
  assign T369 = T163 ? 1'h0 : T370;
  assign T370 = T162 ? 1'h0 : T371;
  assign T371 = T161 ? 1'h0 : T372;
  assign T372 = T160 ? 1'h0 : T373;
  assign T373 = T159 ? 1'h0 : T374;
  assign T374 = T158 ? 1'h0 : T375;
  assign T375 = T157 ? 1'h1 : T376;
  assign T376 = T156 ? 1'h0 : T377;
  assign T377 = T155 ? 1'h0 : T378;
  assign T378 = T154 ? 1'h0 : T379;
  assign T379 = T153 ? 1'h0 : T380;
  assign T380 = T152 ? 1'h0 : T381;
  assign T381 = T151 ? 1'h0 : T382;
  assign T382 = T150 ? 1'h1 : T383;
  assign T383 = T149 ? 1'h0 : T384;
  assign T384 = T148 ? 1'h1 : T385;
  assign T385 = T147 ? 1'h0 : T386;
  assign T386 = T146 ? 1'h0 : T387;
  assign T387 = T145 ? 1'h0 : T388;
  assign T388 = T144 ? 1'h1 : T389;
  assign T389 = T26 ? 1'h0 : T390;
  assign T390 = T260 ? 1'h0 : T391;
  assign T391 = T259 ? 1'h0 : T392;
  assign T392 = T258 ? 1'h0 : T393;
  assign T393 = T257 ? 1'h0 : T394;
  assign T394 = T256 ? 1'h0 : T395;
  assign T395 = T328 ? 1'h0 : T327;
  assign io_ctrl_pc_next_sel = pc_next_sel;
  assign pc_next_sel = inst_we ? 2'h0 : T396;
  assign T396 = T169 ? 2'h0 : T397;
  assign T397 = T168 ? 2'h0 : T398;
  assign T398 = T167 ? 2'h0 : T399;
  assign T399 = T166 ? 2'h0 : T400;
  assign T400 = T165 ? 2'h0 : T401;
  assign T401 = T164 ? 2'h0 : T402;
  assign T402 = T163 ? 2'h0 : T403;
  assign T403 = T162 ? 2'h0 : T404;
  assign T404 = T161 ? 2'h0 : T405;
  assign T405 = T160 ? 2'h0 : T406;
  assign T406 = T159 ? 2'h0 : T407;
  assign T407 = T158 ? 2'h3 : T408;
  assign T408 = T157 ? 2'h0 : T409;
  assign T409 = T156 ? 2'h0 : T410;
  assign T410 = T155 ? 2'h0 : T411;
  assign T411 = T154 ? 2'h0 : T412;
  assign T412 = T153 ? 2'h0 : T413;
  assign T413 = T152 ? 2'h0 : T414;
  assign T414 = T151 ? 2'h0 : T415;
  assign T415 = T150 ? 2'h0 : T416;
  assign T416 = T149 ? 2'h0 : T417;
  assign T417 = T148 ? 2'h0 : T418;
  assign T418 = T147 ? 2'h0 : T419;
  assign T419 = T146 ? 2'h0 : T420;
  assign T420 = T145 ? 2'h0 : T421;
  assign T421 = T144 ? 2'h0 : T422;
  assign T422 = T26 ? 2'h0 : T423;
  assign T423 = T260 ? 2'h0 : T424;
  assign T424 = T259 ? 2'h1 : T425;
  assign T425 = T258 ? 2'h1 : T426;
  assign T426 = T257 ? 2'h1 : T427;
  assign T427 = T256 ? 2'h1 : T428;
  assign T428 = T328 ? 2'h2 : T429;
  assign T429 = T327 ? 2'h2 : 2'h0;
  assign io_ctrl_pc_we = pc_we;
  assign pc_we = inst_we ? 1'h0 : T430;
  assign T430 = T169 ? 1'h0 : T431;
  assign T431 = T168 ? 1'h0 : T432;
  assign T432 = T167 ? 1'h0 : T433;
  assign T433 = T166 ? 1'h0 : T434;
  assign T434 = T165 ? 1'h0 : T435;
  assign T435 = T164 ? 1'h0 : T436;
  assign T436 = T163 ? 1'h0 : T437;
  assign T437 = T162 ? 1'h0 : T438;
  assign T438 = T161 ? 1'h0 : T439;
  assign T439 = T160 ? 1'h0 : T440;
  assign T440 = T159 ? 1'h0 : T441;
  assign T441 = T158 ? 1'h1 : T442;
  assign T442 = T157 ? 1'h0 : T443;
  assign T443 = T156 ? 1'h0 : T444;
  assign T444 = T155 ? 1'h0 : T445;
  assign T445 = T154 ? 1'h0 : T446;
  assign T446 = T153 ? 1'h0 : T447;
  assign T447 = T152 ? 1'h0 : T448;
  assign T448 = T151 ? 1'h0 : T449;
  assign T449 = T150 ? 1'h0 : T450;
  assign T450 = T149 ? 1'h0 : T451;
  assign T451 = T148 ? 1'h0 : T452;
  assign T452 = T147 ? 1'h0 : T453;
  assign T453 = T146 ? 1'h0 : T454;
  assign T454 = T145 ? 1'h0 : T455;
  assign T455 = T144 ? 1'h0 : T456;
  assign T456 = T26 ? 1'h0 : T457;
  assign T457 = T260 ? 1'h1 : T458;
  assign T458 = T259 ? 1'h0 : T459;
  assign T459 = T258 ? 1'h1 : T460;
  assign T460 = T257 == 1'h0;
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
  wire T7;
  wire[2:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire[31:0] T11;
  wire T12;
  wire T13;
  wire[31:0] T14;
  wire[31:0] T15;
  wire[31:0] T16;
  wire[31:0] T17;
  wire[31:0] T18;
  wire[4:0] T19;
  wire T20;
  wire[31:0] T21;
  wire[31:0] T22;
  wire[31:0] T27;
  wire T23;
  wire T24;
  wire T25;
  wire T26;


  assign io_zero = T0;
  assign T0 = T1 ^ 1'h1;
  assign T1 = io_out != 32'h0;
  assign io_out = T2;
  assign T2 = T26 ? T14 : T3;
  assign T3 = T13 ? T9 : T4;
  assign T4 = T7 ? T6 : T5;
  assign T5 = io_in_a & io_in_b;
  assign T6 = io_in_a | io_in_b;
  assign T7 = T8[1'h0:1'h0];
  assign T8 = io_alu_op;
  assign T9 = T12 ? T11 : T10;
  assign T10 = io_in_a + io_in_b;
  assign T11 = io_in_a ^ io_in_b;
  assign T12 = T8[1'h0:1'h0];
  assign T13 = T8[1'h1:1'h1];
  assign T14 = T25 ? T21 : T15;
  assign T15 = T20 ? T18 : T16;
  assign T16 = ~ T17;
  assign T17 = io_in_a | io_in_b;
  assign T18 = io_in_a >> T19;
  assign T19 = io_in_b[3'h4:1'h0];
  assign T20 = T8[1'h0:1'h0];
  assign T21 = T24 ? T27 : T22;
  assign T22 = io_in_a - io_in_b;
  assign T27 = {31'h0, T23};
  assign T23 = io_in_a < io_in_b;
  assign T24 = T8[1'h0:1'h0];
  assign T25 = T8[1'h1:1'h1];
  assign T26 = T8[2'h2:2'h2];
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
    output[31:0] io_data_out,
    input  io_ack
);

  wire T0;
  wire[31:0] T1;
  wire[31:0] T2;
  reg [31:0] alu_out;
  wire[31:0] T52;
  reg [31:0] bus_buf;
  wire[31:0] T53;
  wire T3;
  wire[1:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  reg [31:0] pc;
  wire[31:0] T54;
  wire[32:0] T55;
  wire[32:0] T7;
  wire[32:0] T56;
  wire[32:0] pc_next;
  wire[32:0] T8;
  wire[32:0] T57;
  wire[31:0] T9;
  wire[32:0] branch_pc;
  wire[32:0] T58;
  wire[31:0] T10;
  wire[32:0] T11;
  wire[32:0] T12;
  wire[32:0] T59;
  wire[17:0] T13;
  wire[17:0] T14;
  wire[15:0] T15;
  reg [31:0] inst_reg;
  wire[31:0] T60;
  wire[31:0] T16;
  wire T17;
  wire[14:0] T61;
  wire T62;
  wire[32:0] T18;
  wire[32:0] T19;
  wire[32:0] T20;
  wire T21;
  wire T22;
  reg  alu_zero;
  wire T63;
  wire T23;
  wire[1:0] T24;
  wire[32:0] T64;
  wire[31:0] T25;
  wire[31:0] T26;
  wire[29:0] T27;
  wire[25:0] T28;
  wire[3:0] T29;
  wire T30;
  wire T31;
  wire T32;
  wire[31:0] T33;
  wire[15:0] T34;
  wire T35;
  wire T36;
  wire[4:0] T37;
  wire[4:0] T38;
  wire[4:0] T39;
  wire[4:0] T40;
  wire T41;
  wire[1:0] T42;
  wire T43;
  wire[4:0] T44;
  wire[4:0] T45;
  wire[31:0] T46;
  wire[31:0] T47;
  wire[31:0] T65;
  wire[15:0] T48;
  wire T49;
  wire[1:0] T50;
  wire T51;
  wire[31:0] alu_io_out;
  wire alu_io_zero;
  wire[31:0] regfile_io_douta;
  wire[31:0] regfile_io_doutb;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    alu_out = {1{$random}};
    bus_buf = {1{$random}};
    pc = {1{$random}};
    inst_reg = {1{$random}};
    alu_zero = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = io_reg_we & io_ack;
  assign T1 = T36 ? T5 : T2;
  assign T2 = T3 ? bus_buf : alu_out;
  assign T52 = reset ? 32'h0 : alu_io_out;
  assign T53 = reset ? 32'h0 : io_bus_data;
  assign T3 = T4[1'h0:1'h0];
  assign T4 = io_reg_we_src;
  assign T5 = T35 ? T33 : T6;
  assign T6 = pc + 32'h4;
  assign T54 = T55[5'h1f:1'h0];
  assign T55 = reset ? 33'h0 : T7;
  assign T7 = T32 ? pc_next : T56;
  assign T56 = {1'h0, pc};
  assign pc_next = T31 ? T64 : T8;
  assign T8 = T23 ? branch_pc : T57;
  assign T57 = {1'h0, T9};
  assign T9 = pc + 32'h4;
  assign branch_pc = T21 ? T11 : T58;
  assign T58 = {1'h0, T10};
  assign T10 = pc + 32'h4;
  assign T11 = T12;
  assign T12 = T18 + T59;
  assign T59 = {T61, T13};
  assign T13 = T14;
  assign T14 = T15 << 2'h2;
  assign T15 = inst_reg[4'hf:1'h0];
  assign T60 = reset ? 32'h0 : T16;
  assign T16 = T17 ? io_bus_data : inst_reg;
  assign T17 = io_inst_we & io_ack;
  assign T61 = T62 ? 15'h7fff : 15'h0;
  assign T62 = T13[5'h11:5'h11];
  assign T18 = 33'h4 + T19;
  assign T19 = T20;
  assign T20 = {1'h0, pc};
  assign T21 = alu_zero ^ T22;
  assign T22 = io_alu_b_sel == 2'h2;
  assign T63 = reset ? 1'h0 : alu_io_zero;
  assign T23 = T24[1'h0:1'h0];
  assign T24 = io_pc_next_sel;
  assign T64 = {1'h0, T25};
  assign T25 = T30 ? regfile_io_douta : T26;
  assign T26 = {T27, 2'h0};
  assign T27 = {T29, T28};
  assign T28 = inst_reg[5'h19:1'h0];
  assign T29 = pc[5'h1f:5'h1c];
  assign T30 = T24[1'h0:1'h0];
  assign T31 = T24[1'h1:1'h1];
  assign T32 = io_pc_we & io_ack;
  assign T33 = {T34, 16'h0};
  assign T34 = alu_out[4'hf:1'h0];
  assign T35 = T4[1'h0:1'h0];
  assign T36 = T4[1'h1:1'h1];
  assign T37 = T43 ? 5'h1f : T38;
  assign T38 = T41 ? T40 : T39;
  assign T39 = inst_reg[4'hf:4'hb];
  assign T40 = inst_reg[5'h14:5'h10];
  assign T41 = T42[1'h0:1'h0];
  assign T42 = io_reg_we_dst;
  assign T43 = T42[1'h1:1'h1];
  assign T44 = inst_reg[5'h14:5'h10];
  assign T45 = inst_reg[5'h19:5'h15];
  assign T46 = T51 ? regfile_io_doutb : T47;
  assign T47 = T49 ? T65 : regfile_io_doutb;
  assign T65 = {16'h0, T48};
  assign T48 = inst_reg[4'hf:1'h0];
  assign T49 = T50[1'h0:1'h0];
  assign T50 = io_alu_b_sel;
  assign T51 = T50[1'h1:1'h1];
  assign io_data_out = regfile_io_doutb;
  assign io_alu_out = alu_out;
  assign io_pc_out = pc;
  assign io_inst = inst_reg;
  ALU alu(
       .io_alu_op( io_alu_op ),
       .io_in_a( regfile_io_douta ),
       .io_in_b( T46 ),
       .io_out( alu_io_out ),
       .io_zero( alu_io_zero )
  );
  Register_File regfile(.clk(clk), .reset(reset),
       .io_addra( T45 ),
       .io_douta( regfile_io_douta ),
       .io_addrb( T44 ),
       .io_doutb( regfile_io_doutb ),
       .io_wtaddr( T37 ),
       .io_wtdata( T1 ),
       .io_we( T0 )
  );

  always @(posedge clk) begin
    if(reset) begin
      alu_out <= 32'h0;
    end else begin
      alu_out <= alu_io_out;
    end
    if(reset) begin
      bus_buf <= 32'h0;
    end else begin
      bus_buf <= io_bus_data;
    end
    pc <= T54;
    if(reset) begin
      inst_reg <= 32'h0;
    end else if(T17) begin
      inst_reg <= io_bus_data;
    end
    if(reset) begin
      alu_zero <= 1'h0;
    end else begin
      alu_zero <= alu_io_zero;
    end
  end
endmodule

module Core(input clk, input reset,
    output[31:0] io_bus_addr,
    output[31:0] io_bus_dat2,
    input [31:0] io_bus_dat4,
    output io_bus_sel,
    output io_bus_we,
    input  io_bus_ack
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
  wire cpath_io_ctrl_ack;
  wire[31:0] cpath_io_bus_addr;
  wire[31:0] cpath_io_bus_dat2;
  wire cpath_io_bus_sel;
  wire cpath_io_bus_we;
  wire[31:0] dpath_io_inst;
  wire[31:0] dpath_io_pc_out;
  wire[31:0] dpath_io_alu_out;
  wire[31:0] dpath_io_data_out;


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
       .io_ctrl_ack( cpath_io_ctrl_ack ),
       .io_bus_addr( cpath_io_bus_addr ),
       .io_bus_dat2( cpath_io_bus_dat2 ),
       .io_bus_dat4( io_bus_dat4 ),
       .io_bus_sel( cpath_io_bus_sel ),
       .io_bus_we( cpath_io_bus_we ),
       .io_bus_ack( io_bus_ack )
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
       .io_data_out( dpath_io_data_out ),
       .io_ack( cpath_io_ctrl_ack )
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
  wire[31:0] T107;
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
  wire[31:0] T108;
  wire[27:0] T12;
  wire T13;
  wire T14;
  wire T15;
  wire T16;
  wire T17;
  wire T18;
  wire T19;
  wire T20;
  wire[31:0] T109;
  wire[27:0] T21;
  wire T22;
  wire T23;
  wire T24;
  wire T25;
  wire T26;
  wire T27;
  wire T28;
  wire T29;
  wire[31:0] T110;
  wire[27:0] T30;
  wire T31;
  wire T32;
  wire T33;
  wire T34;
  wire T35;
  wire T36;
  wire T37;
  wire T38;
  wire[31:0] T111;
  wire[27:0] T39;
  wire T40;
  wire T41;
  wire T42;
  wire T43;
  wire T44;
  wire T45;
  wire T46;
  wire T47;
  wire[31:0] T112;
  wire[27:0] T48;
  wire T49;
  wire T50;
  wire T51;
  wire T52;
  wire T53;
  wire T54;
  wire T55;
  wire T56;
  wire[31:0] T113;
  wire[27:0] T57;
  wire T58;
  wire T59;
  wire T60;
  wire T61;
  wire T62;
  wire T63;
  wire T64;
  wire T65;
  wire[31:0] T114;
  wire[27:0] T66;
  wire T67;
  wire T68;
  wire T69;
  wire T70;
  wire T71;
  wire T72;
  wire T73;
  wire T74;
  wire[31:0] T115;
  wire[27:0] T75;
  wire T76;
  wire T77;
  wire T78;
  wire T79;
  wire T80;
  wire[2:0] T81;
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
  wire[31:0] T92;
  wire[31:0] T93;
  wire[31:0] T94;
  wire[31:0] T95;
  wire T96;
  wire[31:0] T97;
  wire T98;
  wire T99;
  wire[31:0] T100;
  wire[31:0] T101;
  wire T102;
  wire[31:0] T103;
  wire T104;
  wire T105;
  wire T106;


  assign io_ram_slave_we = T0;
  assign T0 = ram_op & io_from_cpu_we;
  assign ram_op = ~ T1;
  assign T1 = io_from_cpu_addr[5'h1f:5'h1f];
  assign io_ram_slave_sel = T2;
  assign T2 = ram_op & io_from_cpu_sel;
  assign io_ram_slave_dat2 = io_from_cpu_dat2;
  assign io_ram_slave_addr = T107;
  assign T107 = {4'h0, T3};
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
  assign io_slaves_0_addr = T108;
  assign T108 = {4'h0, T12};
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
  assign io_slaves_1_addr = T109;
  assign T109 = {4'h0, T21};
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
  assign io_slaves_2_addr = T110;
  assign T110 = {4'h0, T30};
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
  assign io_slaves_3_addr = T111;
  assign T111 = {4'h0, T39};
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
  assign io_slaves_4_addr = T112;
  assign T112 = {4'h0, T48};
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
  assign io_slaves_5_addr = T113;
  assign T113 = {4'h0, T57};
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
  assign io_slaves_6_addr = T114;
  assign T114 = {4'h0, T66};
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
  assign io_slaves_7_addr = T115;
  assign T115 = {4'h0, T75};
  assign T75 = io_from_cpu_addr[5'h1b:1'h0];
  assign io_from_cpu_ack = T76;
  assign T76 = ram_op ? io_ram_slave_ack : T77;
  assign T77 = T91 ? T85 : T78;
  assign T78 = T84 ? T82 : T79;
  assign T79 = T80 ? io_slaves_1_ack : io_slaves_0_ack;
  assign T80 = T81[1'h0:1'h0];
  assign T81 = current_slave;
  assign T82 = T83 ? io_slaves_3_ack : io_slaves_2_ack;
  assign T83 = T81[1'h0:1'h0];
  assign T84 = T81[1'h1:1'h1];
  assign T85 = T90 ? T88 : T86;
  assign T86 = T87 ? io_slaves_5_ack : io_slaves_4_ack;
  assign T87 = T81[1'h0:1'h0];
  assign T88 = T89 ? io_slaves_7_ack : io_slaves_6_ack;
  assign T89 = T81[1'h0:1'h0];
  assign T90 = T81[1'h1:1'h1];
  assign T91 = T81[2'h2:2'h2];
  assign io_from_cpu_dat4 = T92;
  assign T92 = ram_op ? io_ram_slave_dat4 : T93;
  assign T93 = T106 ? T100 : T94;
  assign T94 = T99 ? T97 : T95;
  assign T95 = T96 ? io_slaves_1_dat4 : io_slaves_0_dat4;
  assign T96 = T81[1'h0:1'h0];
  assign T97 = T98 ? io_slaves_3_dat4 : io_slaves_2_dat4;
  assign T98 = T81[1'h0:1'h0];
  assign T99 = T81[1'h1:1'h1];
  assign T100 = T105 ? T103 : T101;
  assign T101 = T102 ? io_slaves_5_dat4 : io_slaves_4_dat4;
  assign T102 = T81[1'h0:1'h0];
  assign T103 = T104 ? io_slaves_7_dat4 : io_slaves_6_dat4;
  assign T104 = T81[1'h0:1'h0];
  assign T105 = T81[1'h1:1'h1];
  assign T106 = T81[2'h2:2'h2];
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
  wire[31:0] T2;
  wire[31:0] counter_next;
  wire[31:0] T0;
  wire[31:0] T1;

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
  assign T2 = reset ? 32'h0 : counter_next;
  assign counter_next = T0;
  assign T0 = io_bus_we ? io_bus_dat2 : T1;
  assign T1 = counter + 32'h1;

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
  wire[31:0] T77;
  wire[31:0] T2;
  wire[31:0] T3;
  wire T4;
  wire T5;
  wire T6;
  wire T7;
  reg [31:0] h_counter;
  wire[31:0] T78;
  wire[31:0] T8;
  wire[31:0] T9;
  wire[31:0] T10;
  wire T11;
  wire T12;
  wire T13;
  reg [1:0] p_counter;
  wire[1:0] T79;
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
  wire output_en;
  wire T71;
  wire T72;
  wire[2:0] T73;
  wire[2:0] T74;
  wire[2:0] T75;
  wire[2:0] T76;

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
  assign T77 = reset ? 32'h0 : T2;
  assign T2 = T19 ? T18 : T3;
  assign T3 = T4 ? 32'h0 : v_counter;
  assign T4 = T6 & T5;
  assign T5 = v_counter == 32'h208;
  assign T6 = T13 & T7;
  assign T7 = h_counter == 32'h31f;
  assign T78 = reset ? 32'h0 : T8;
  assign T8 = T11 ? T10 : T9;
  assign T9 = T6 ? 32'h0 : h_counter;
  assign T10 = h_counter + 32'h1;
  assign T11 = T13 & T12;
  assign T12 = T7 ^ 1'h1;
  assign T13 = p_counter == 2'h0;
  assign T79 = reset ? 2'h0 : T14;
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
  assign T69 = output_en ? T70 : 2'h0;
  assign T70 = io_ctrl_color[1'h1:1'h0];
  assign output_en = T72 & T71;
  assign T71 = v_state == 2'h2;
  assign T72 = h_state == 2'h2;
  assign io_vga_green = T73;
  assign T73 = output_en ? T74 : 3'h0;
  assign T74 = io_ctrl_color[3'h4:2'h2];
  assign io_vga_red = T75;
  assign T75 = output_en ? T76 : 3'h0;
  assign T76 = io_ctrl_color[3'h7:3'h5];

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
  wire[11:0] T61;
  wire[3:0] T1;
  wire[11:0] T2;
  wire[7:0] char;
  wire[15:0] data;
  reg [15:0] vmem [2399:0];
  wire[15:0] T3;
  wire[15:0] T62;
  reg [31:0] data_buf;
  wire[31:0] T63;
  wire[31:0] T4;
  wire T5;
  wire T6;
  wire[11:0] T7;
  reg [31:0] addr_buf;
  wire[31:0] T64;
  wire[31:0] T14;
  wire[31:0] T65;
  wire[11:0] T15;
  wire T8;
  reg  is_writing;
  wire T66;
  wire T9;
  wire T10;
  reg  ack;
  wire T67;
  wire T11;
  wire T12;
  wire T13;
  wire[11:0] T68;
  wire[11:0] T69;
  wire[34:0] T16;
  wire[34:0] T70;
  wire[28:0] T17;
  wire[34:0] T18;
  wire[27:0] T19;
  wire[7:0] T20;
  wire[7:0] back_color;
  wire T21;
  wire[7:0] color;
  wire[6:0] T22;
  wire T23;
  wire[5:0] T24;
  wire T25;
  wire[4:0] T26;
  wire T27;
  wire[3:0] T28;
  wire T29;
  wire[2:0] T30;
  wire T31;
  wire[1:0] T32;
  wire T33;
  wire T34;
  wire[7:0] front_color;
  wire T35;
  wire[6:0] T36;
  wire T37;
  wire[5:0] T38;
  wire T39;
  wire[4:0] T40;
  wire T41;
  wire[3:0] T42;
  wire T43;
  wire[2:0] T44;
  wire T45;
  wire[1:0] T46;
  wire T47;
  wire T48;
  wire T49;
  wire T50;
  wire T51;
  wire[2:0] T52;
  wire[2:0] T53;
  wire[2:0] T54;
  wire[2:0] T55;
  wire T56;
  reg [31:0] out_buf;
  wire[31:0] T71;
  wire[31:0] T57;
  wire[31:0] T72;
  wire[15:0] T58;
  wire[11:0] T73;
  wire T59;
  wire T60;
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
    data_buf = {1{$random}};
    addr_buf = {1{$random}};
    is_writing = {1{$random}};
    ack = {1{$random}};
    out_buf = {1{$random}};
  end
// synthesis translate_on
`endif

  assign T0 = T2 + T61;
  assign T61 = {8'h0, T1};
  assign T1 = vga_io_ctrl_y[2'h3:1'h0];
  assign T2 = char << 3'h4;
  assign char = data[3'h7:1'h0];
  assign data = vmem[T69];
  assign T62 = data_buf[4'hf:1'h0];
  assign T63 = reset ? 32'h0 : T4;
  assign T4 = io_bus_sel ? io_bus_dat2 : data_buf;
  assign T5 = T8 & T6;
  assign T6 = T7 < 12'h960;
  assign T7 = addr_buf[4'hb:1'h0];
  assign T64 = reset ? 32'h0 : T14;
  assign T14 = io_bus_sel ? T65 : addr_buf;
  assign T65 = {20'h0, T15};
  assign T15 = io_bus_addr[4'hb:1'h0];
  assign T8 = T10 & is_writing;
  assign T66 = reset ? 1'h0 : T9;
  assign T9 = io_bus_sel ? io_bus_we : is_writing;
  assign T10 = ~ ack;
  assign T67 = reset ? 1'h1 : T11;
  assign T11 = T13 ? 1'h1 : T12;
  assign T12 = ~ ack;
  assign T13 = io_bus_sel ^ 1'h1;
  assign T68 = addr_buf[4'hb:1'h0];
  assign T69 = T16[4'hb:1'h0];
  assign T16 = T18 + T70;
  assign T70 = {6'h0, T17};
  assign T17 = vga_io_ctrl_x[5'h1f:2'h3];
  assign T18 = T19 * 7'h50;
  assign T19 = vga_io_ctrl_y[5'h1f:3'h4];
  assign T20 = T49 ? front_color : back_color;
  assign back_color = {T22, T21};
  assign T21 = color[3'h4:3'h4];
  assign color = data[4'hf:4'h8];
  assign T22 = {T24, T23};
  assign T23 = color[3'h4:3'h4];
  assign T24 = {T26, T25};
  assign T25 = color[3'h5:3'h5];
  assign T26 = {T28, T27};
  assign T27 = color[3'h5:3'h5];
  assign T28 = {T30, T29};
  assign T29 = color[3'h5:3'h5];
  assign T30 = {T32, T31};
  assign T31 = color[3'h6:3'h6];
  assign T32 = {T34, T33};
  assign T33 = color[3'h6:3'h6];
  assign T34 = color[3'h6:3'h6];
  assign front_color = {T36, T35};
  assign T35 = color[1'h0:1'h0];
  assign T36 = {T38, T37};
  assign T37 = color[1'h0:1'h0];
  assign T38 = {T40, T39};
  assign T39 = color[1'h1:1'h1];
  assign T40 = {T42, T41};
  assign T41 = color[1'h1:1'h1];
  assign T42 = {T44, T43};
  assign T43 = color[1'h1:1'h1];
  assign T44 = {T46, T45};
  assign T45 = color[2'h2:2'h2];
  assign T46 = {T48, T47};
  assign T47 = color[2'h2:2'h2];
  assign T48 = color[2'h2:2'h2];
  assign T49 = T56 & T50;
  assign T50 = T51 - 1'h1;
  assign T51 = 1'h1 << T52;
  assign T52 = T53 + 3'h1;
  assign T53 = T54 - T54;
  assign T54 = 3'h7 - T55;
  assign T55 = vga_io_ctrl_x[2'h2:1'h0];
  assign T56 = font_io_data >> T54;
  assign io_bus_ack = ack;
  assign io_bus_dat4 = out_buf;
  assign T71 = reset ? 32'h0 : T57;
  assign T57 = T59 ? T72 : out_buf;
  assign T72 = {16'h0, T58};
  assign T58 = vmem[T73];
  assign T73 = addr_buf[4'hb:1'h0];
  assign T59 = T10 & T60;
  assign T60 = is_writing ^ 1'h1;
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
       .io_ctrl_color( T20 )
  );
  Font_Rom_Wrapper font(
       .io_addr( T0 ),
       .io_data( font_io_data )
  );

  always @(posedge clk) begin
    if (T5)
      vmem[T68] <= T62;
    if(reset) begin
      data_buf <= 32'h0;
    end else if(io_bus_sel) begin
      data_buf <= io_bus_dat2;
    end
    if(reset) begin
      addr_buf <= 32'h0;
    end else if(io_bus_sel) begin
      addr_buf <= T65;
    end
    if(reset) begin
      is_writing <= 1'h0;
    end else if(io_bus_sel) begin
      is_writing <= io_bus_we;
    end
    if(reset) begin
      ack <= 1'h1;
    end else if(T13) begin
      ack <= 1'h1;
    end else begin
      ack <= T12;
    end
    if(reset) begin
      out_buf <= 32'h0;
    end else if(T59) begin
      out_buf <= T72;
    end
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
  wire[31:0] T4;
  wire[31:0] T5;
  wire[31:0] T6;
  wire[31:0] T7;
  wire T8;
  wire[2:0] T9;
  wire T10;
  wire T11;
  reg [31:0] k_clk_test_reg;
  wire[31:0] T130;
  wire[31:0] T12;
  wire[31:0] T13;
  wire T14;
  reg [31:0] c_count;
  wire[31:0] T131;
  wire[31:0] T15;
  wire[31:0] T16;
  wire T17;
  wire T18;
  wire T19;
  wire[6:0] cooked_next;
  wire[6:0] T20;
  wire[6:0] T21;
  wire[6:0] T22;
  wire[6:0] T23;
  wire[6:0] T24;
  wire[6:0] T25;
  wire[6:0] T26;
  wire[6:0] T27;
  wire[6:0] T28;
  wire[6:0] T29;
  wire[6:0] T30;
  wire[6:0] T31;
  wire[6:0] T32;
  wire[6:0] T33;
  wire[6:0] T34;
  wire[6:0] T35;
  wire[6:0] T36;
  wire[6:0] T37;
  wire[6:0] T38;
  wire[6:0] T39;
  wire[6:0] T40;
  wire[6:0] T41;
  wire[6:0] T42;
  wire[6:0] T43;
  wire[6:0] T44;
  wire[6:0] T45;
  wire[6:0] T46;
  wire[6:0] T47;
  wire[6:0] T48;
  wire[6:0] T49;
  wire[6:0] T50;
  wire[6:0] T51;
  wire[6:0] T52;
  wire[6:0] T53;
  wire[6:0] T54;
  wire[6:0] T55;
  wire[6:0] T56;
  wire[6:0] T57;
  wire[6:0] T58;
  wire[6:0] T59;
  wire[6:0] T60;
  wire[6:0] T132;
  wire[5:0] T61;
  wire[5:0] T62;
  wire[5:0] T63;
  wire[5:0] T64;
  wire[5:0] T133;
  wire[3:0] T65;
  wire[3:0] T66;
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
  wire[31:0] T134;
  reg [15:0] cooked;
  wire[15:0] T135;
  wire[15:0] T118;
  wire[15:0] T136;
  wire[8:0] T119;
  wire[8:0] T120;
  reg  p_f0;
  wire T137;
  wire T121;
  wire T122;
  wire T123;
  wire[8:0] T138;
  wire T124;
  reg [31:0] r_count;
  wire[31:0] T139;
  wire[31:0] T125;
  wire[31:0] T126;
  wire T127;
  wire[31:0] T140;
  reg [7:0] raw;
  wire[7:0] T141;
  wire[7:0] T128;
  wire T129;
  wire[7:0] kb_io_ctrl_data;
  wire kb_io_ctrl_interrupt;

`ifndef SYNTHESIS
// synthesis translate_off
  integer initvar;
  initial begin
    #0.002;
    k_clk_test_reg = {1{$random}};
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
  assign T0 = T129 ? T140 : T1;
  assign T1 = T127 ? r_count : T2;
  assign T2 = T124 ? T134 : T3;
  assign T3 = T117 ? c_count : T4;
  assign T4 = T14 ? k_clk_test_reg : T5;
  assign T5 = T11 ? k_clk_test_reg : T6;
  assign T6 = T10 ? k_clk_test_reg : T7;
  assign T7 = T8 ? k_clk_test_reg : 32'h0;
  assign T8 = T9 == 3'h7;
  assign T9 = io_bus_addr[2'h2:1'h0];
  assign T10 = T9 == 3'h6;
  assign T11 = T9 == 3'h5;
  assign T130 = reset ? 32'h0 : T12;
  assign T12 = io_keyboard_kb_clk ? T13 : k_clk_test_reg;
  assign T13 = k_clk_test_reg + 32'h1;
  assign T14 = T9 == 3'h4;
  assign T131 = reset ? 32'h0 : T15;
  assign T15 = T17 ? T16 : c_count;
  assign T16 = c_count + 32'h1;
  assign T17 = kb_io_ctrl_interrupt & T18;
  assign T18 = T115 & T19;
  assign T19 = cooked_next != 7'h0;
  assign cooked_next = T114 ? 7'h31 : T20;
  assign T20 = T113 ? 7'h32 : T21;
  assign T21 = T112 ? 7'h33 : T22;
  assign T22 = T111 ? 7'h34 : T23;
  assign T23 = T110 ? 7'h35 : T24;
  assign T24 = T109 ? 7'h36 : T25;
  assign T25 = T108 ? 7'h37 : T26;
  assign T26 = T107 ? 7'h38 : T27;
  assign T27 = T106 ? 7'h39 : T28;
  assign T28 = T105 ? 7'h30 : T29;
  assign T29 = T104 ? 7'h2d : T30;
  assign T30 = T103 ? 7'h2b : T31;
  assign T31 = T102 ? 7'h71 : T32;
  assign T32 = T101 ? 7'h77 : T33;
  assign T33 = T100 ? 7'h65 : T34;
  assign T34 = T99 ? 7'h72 : T35;
  assign T35 = T98 ? 7'h74 : T36;
  assign T36 = T97 ? 7'h79 : T37;
  assign T37 = T96 ? 7'h75 : T38;
  assign T38 = T95 ? 7'h69 : T39;
  assign T39 = T94 ? 7'h6f : T40;
  assign T40 = T93 ? 7'h70 : T41;
  assign T41 = T92 ? 7'h5b : T42;
  assign T42 = T91 ? 7'h5d : T43;
  assign T43 = T90 ? 7'h61 : T44;
  assign T44 = T89 ? 7'h73 : T45;
  assign T45 = T88 ? 7'h64 : T46;
  assign T46 = T87 ? 7'h66 : T47;
  assign T47 = T86 ? 7'h67 : T48;
  assign T48 = T85 ? 7'h68 : T49;
  assign T49 = T84 ? 7'h6a : T50;
  assign T50 = T83 ? 7'h6b : T51;
  assign T51 = T82 ? 7'h6c : T52;
  assign T52 = T81 ? 7'h3b : T53;
  assign T53 = T80 ? 7'h27 : T54;
  assign T54 = T79 ? 7'h7a : T55;
  assign T55 = T78 ? 7'h78 : T56;
  assign T56 = T77 ? 7'h63 : T57;
  assign T57 = T76 ? 7'h76 : T58;
  assign T58 = T75 ? 7'h62 : T59;
  assign T59 = T74 ? 7'h6e : T60;
  assign T60 = T73 ? 7'h6d : T132;
  assign T132 = {1'h0, T61};
  assign T61 = T72 ? 6'h2c : T62;
  assign T62 = T71 ? 6'h2e : T63;
  assign T63 = T70 ? 6'h2f : T64;
  assign T64 = T69 ? 6'h20 : T133;
  assign T133 = {2'h0, T65};
  assign T65 = T68 ? 4'h8 : T66;
  assign T66 = T67 ? 4'ha : 4'h0;
  assign T67 = kb_io_ctrl_data == 8'h5a;
  assign T68 = kb_io_ctrl_data == 8'h66;
  assign T69 = kb_io_ctrl_data == 8'h29;
  assign T70 = kb_io_ctrl_data == 8'h4a;
  assign T71 = kb_io_ctrl_data == 8'h49;
  assign T72 = kb_io_ctrl_data == 8'h41;
  assign T73 = kb_io_ctrl_data == 8'h3a;
  assign T74 = kb_io_ctrl_data == 8'h31;
  assign T75 = kb_io_ctrl_data == 8'h32;
  assign T76 = kb_io_ctrl_data == 8'h2a;
  assign T77 = kb_io_ctrl_data == 8'h21;
  assign T78 = kb_io_ctrl_data == 8'h22;
  assign T79 = kb_io_ctrl_data == 8'h1a;
  assign T80 = kb_io_ctrl_data == 8'h52;
  assign T81 = kb_io_ctrl_data == 8'h4c;
  assign T82 = kb_io_ctrl_data == 8'h4b;
  assign T83 = kb_io_ctrl_data == 8'h42;
  assign T84 = kb_io_ctrl_data == 8'h3b;
  assign T85 = kb_io_ctrl_data == 8'h33;
  assign T86 = kb_io_ctrl_data == 8'h34;
  assign T87 = kb_io_ctrl_data == 8'h2b;
  assign T88 = kb_io_ctrl_data == 8'h23;
  assign T89 = kb_io_ctrl_data == 8'h1b;
  assign T90 = kb_io_ctrl_data == 8'h1c;
  assign T91 = kb_io_ctrl_data == 8'h5b;
  assign T92 = kb_io_ctrl_data == 8'h54;
  assign T93 = kb_io_ctrl_data == 8'h4d;
  assign T94 = kb_io_ctrl_data == 8'h44;
  assign T95 = kb_io_ctrl_data == 8'h43;
  assign T96 = kb_io_ctrl_data == 8'h3c;
  assign T97 = kb_io_ctrl_data == 8'h35;
  assign T98 = kb_io_ctrl_data == 8'h2c;
  assign T99 = kb_io_ctrl_data == 8'h2d;
  assign T100 = kb_io_ctrl_data == 8'h24;
  assign T101 = kb_io_ctrl_data == 8'h1d;
  assign T102 = kb_io_ctrl_data == 8'h15;
  assign T103 = kb_io_ctrl_data == 8'h55;
  assign T104 = kb_io_ctrl_data == 8'h4e;
  assign T105 = kb_io_ctrl_data == 8'h45;
  assign T106 = kb_io_ctrl_data == 8'h46;
  assign T107 = kb_io_ctrl_data == 8'h3e;
  assign T108 = kb_io_ctrl_data == 8'h3d;
  assign T109 = kb_io_ctrl_data == 8'h36;
  assign T110 = kb_io_ctrl_data == 8'h2e;
  assign T111 = kb_io_ctrl_data == 8'h25;
  assign T112 = kb_io_ctrl_data == 8'h26;
  assign T113 = kb_io_ctrl_data == 8'h1e;
  assign T114 = kb_io_ctrl_data == 8'h16;
  assign T115 = T116 ^ 1'h1;
  assign T116 = kb_io_ctrl_data == 8'hf0;
  assign T117 = T9 == 3'h3;
  assign T134 = {16'h0, cooked};
  assign T135 = reset ? 16'h0 : T118;
  assign T118 = T17 ? T136 : cooked;
  assign T136 = {7'h0, T119};
  assign T119 = T138 + T120;
  assign T120 = p_f0 << 4'h8;
  assign T137 = reset ? 1'h0 : T121;
  assign T121 = T17 ? 1'h0 : T122;
  assign T122 = T123 ? 1'h1 : p_f0;
  assign T123 = kb_io_ctrl_interrupt & T116;
  assign T138 = {2'h0, cooked_next};
  assign T124 = T9 == 3'h2;
  assign T139 = reset ? 32'h0 : T125;
  assign T125 = kb_io_ctrl_interrupt ? T126 : r_count;
  assign T126 = r_count + 32'h1;
  assign T127 = T9 == 3'h1;
  assign T140 = {24'h0, raw};
  assign T141 = reset ? 8'h0 : T128;
  assign T128 = kb_io_ctrl_interrupt ? kb_io_ctrl_data : raw;
  assign T129 = T9 == 3'h0;
  Keyboard_Ctrl kb(.clk(clk),
       .io_keyboard_kb_clk( io_keyboard_kb_clk ),
       .io_keyboard_kb_data( io_keyboard_kb_data ),
       .io_ctrl_data( kb_io_ctrl_data ),
       .io_ctrl_interrupt( kb_io_ctrl_interrupt )
  );

  always @(posedge clk) begin
    if(reset) begin
      k_clk_test_reg <= 32'h0;
    end else if(io_keyboard_kb_clk) begin
      k_clk_test_reg <= T13;
    end
    if(reset) begin
      c_count <= 32'h0;
    end else if(T17) begin
      c_count <= T16;
    end
    if(reset) begin
      cooked <= 16'h0;
    end else if(T17) begin
      cooked <= T136;
    end
    if(reset) begin
      p_f0 <= 1'h0;
    end else if(T17) begin
      p_f0 <= 1'h0;
    end else if(T123) begin
      p_f0 <= 1'h1;
    end
    if(reset) begin
      r_count <= 32'h0;
    end else if(kb_io_ctrl_interrupt) begin
      r_count <= T126;
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
    input  io_devices_KEYBOARD_kb_data
);

  wire[31:0] cpu_io_bus_addr;
  wire[31:0] cpu_io_bus_dat2;
  wire cpu_io_bus_sel;
  wire cpu_io_bus_we;
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
       .io_bus_ack( dev_io_bus_ack )
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

