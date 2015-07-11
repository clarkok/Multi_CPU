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

