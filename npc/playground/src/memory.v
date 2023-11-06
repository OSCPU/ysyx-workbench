import "DPI-C" function void pmem_read(
  input int raddr, output int rdata
);

import "DPI-C" function void pmem_write(
  input int waddr, input int wdata, input byte wmask
);

module memory (
  input  [31:0] raddr,
  output [31:0] rdata,
  input  [31:0] waddr,
  input  [31:0] wdata,
  input  [ 7:0] wmask,
  input         wen
);

always @(*) begin
  pmem_read(raddr, rdata);
  if(wen) begin
    pmem_write(waddr, wdata, wmask);
  end
end

endmodule
