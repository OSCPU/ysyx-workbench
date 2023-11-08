import "DPI-C" function void paddr_read(
  input int raddr, output int rdata
);

import "DPI-C" function void paddr_write(
  input int waddr, input int wdata, input byte wmask
);

module MemUnit (
  input         valid,
  input  [31:0] raddr,
  output reg [31:0] rdata,
  input  [31:0] waddr,
  input  [31:0] wdata,
  input  [ 7:0] wmask,
  input         wen
);


always @(*) begin
  if(valid) begin
    paddr_read(raddr, rdata);
    if(wen) begin
      paddr_write(waddr, wdata, wmask);
    end
  end else begin
    rdata = 0;
  end
end

endmodule
