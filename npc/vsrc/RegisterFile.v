
module RegisterFile #(ADDR_WIDTH = 5, DATA_WIDTH = 32) (
  input clk,
  input rst,
  input [DATA_WIDTH-1:0] wdata,
  input [ADDR_WIDTH-1:0] waddr,
  output  wen,
  output reg [DATA_WIDTH-1:0] rdata1,
  output reg [DATA_WIDTH-1:0] rdata2,
  input [ADDR_WIDTH-1:0] raddr1,
  input [ADDR_WIDTH-1:0] raddr2,
	output reg [31:0]pc 
// output reg [31:0] ins
);
  reg [DATA_WIDTH-1:0] rf [2**ADDR_WIDTH-1:0];
	reg [31:0]imm;
	reg [31:0] ins;
  // 读寄存器
  assign rdata1 = (raddr1 == 0) ? 0 : rf[raddr1]; // 0号寄存器始终为0
  assign rdata2 = (raddr2 == 0) ? 0 : rf[raddr2]; // 0号寄存器始终为0
	//assign wdata = (waddr == 0)? 0:wdata;
/*
 function void get_regs(output logic [31:0] regs[32]);
        for (int i = 0; i < 32; i++) begin
            regs[i] = rf[i];  // 逐个赋值
        
    endfunction*/
assign ins=mem_read(pc);
  // 写寄存器
  always @(posedge clk) begin
  if(ins[6:0]==7'b1100111)begin
			assign imm = {{20{ins[31]}}, ins[31:20]}; // I 型指令的符号扩展
			
			pc<=(rf[1]+imm)&~1;
		end
    if (rst) begin
      integer i;
      for (i = 0; i < 32; i = i + 1)
        rf[i] <= 0;
    end else if(waddr != 0)  begin // 0号寄存器不能写入
     
      rf[waddr] = wdata;
      
     // $display("final register written: rgister number:rf[%d], wdata=%h, result: %h", waddr,wdata,rf[waddr]);
     	
    end
	
  end


 
endmodule



