module ysyx_25030077_PC(
  input         clk,
  input         reset,
  input  [31:0] io_next_pc,
  output [31:0] io_Pc_count
);
// export "DPI-C" function pc_read_data;
// function int pc_read_data();
//   return {io_Pc_count};
// endfunction
  reg [31:0] state; // @[module.scala 11:22]
  assign io_Pc_count = state; // @[module.scala 14:15]
  always @(posedge clk) begin
    if (reset) begin // @[module.scala 11:22]
      state <= 32'h80000000; // @[module.scala 11:22]
    end else begin
      state <= io_next_pc; // @[module.scala 13:9]
    end
  end
endmodule