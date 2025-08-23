module ysyx_25030077_div_clk(
  input         clock,
  input         reset,
  input         clock1,
  output        clk_div2
);
reg clk_ref;
always @(posedge clock1 or posedge reset) begin
  if (reset) begin
    clk_ref <= 1'b0;
  end else begin
    clk_ref <= ~clk_ref;
  end
end
assign clk_div2 = ~clk_ref;
endmodule
