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

