module ysyx_25030077_reg_delay(
  input         clock,
  input         reset,
  input  [4:0] addr,
  input  [31:0] data,
  output [4:0] addr_delay,
  output [31:0] data_delay
);
reg [4:0] addr_Reg; // @[top.scala 10:25]
reg [31:0]data_Reg; // @[top.scala 10:25]
  always @(posedge clock) begin
    if (reset) begin // @[top.scala 10:25]
      addr_Reg <= 5'h0; // @[top.scala 10:25]
      data_Reg <= 32'h0; // @[top.scala 10:25]
    end 
    else begin // @[top.scala 11:19]
      addr_Reg <= addr;
      data_Reg <= data;
    end
  end
assign addr_delay = addr_Reg; // @[top.scala 12:15]
assign data_delay = data_Reg; // @[top.scala 12:15]
endmodule