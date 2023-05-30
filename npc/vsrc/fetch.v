module fetch(
    input clk,
    input rst,

    input [63:0]  addr,
    output [31:0] data
);
/* verilator lint_off UNUSED */reg [63:0] fetchmem_rdata;
always @(*) begin
  if (~rst) pmem_read(addr, fetchmem_rdata);
  else fetchmem_rdata = 64'b0;
end
assign data = rst ? 32'b0 : fetchmem_rdata[31:0];
endmodule