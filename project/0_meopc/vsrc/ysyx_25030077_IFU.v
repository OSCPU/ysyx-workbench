module ysyx_25030077_IFU(
  input  [31:0] instruction_in,
  output [31:0] instruction_out
);
import "DPI-C" function bit[31:0] addr_read(input bit[31:0] pc);
assign instruction_out = addr_read(instruction_in);
endmodule