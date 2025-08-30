module ysyx_25030077_EXIT(
  input        clk,
  input        reset,
  input [31:0] io_Pc_count,
  input        is_break_out,
  input        is_unknown_instruction
);

  always @(posedge clk) begin
    if (is_break_out && (!reset)) begin
      $display("检测到break指令, 仿真退出! 当前PC = 0x%08x", io_Pc_count);
      $finish;
      $finish;
    end
  end

  always @(posedge clk) begin
    if (is_unknown_instruction && (!reset)) begin
      $display("检测到未知指令, 仿真退出! 当前PC = 0x%08x", io_Pc_count);
      $finish;
      $finish;
    end
  end

endmodule