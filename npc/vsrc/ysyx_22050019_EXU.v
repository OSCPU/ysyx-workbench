module ysyx_22050019_EXU(
  input [`LEN:0]   alu_sel,
  input [5:0]    mem_r_wdth,
  input [3:0]    mem_w_wdth,

  input [63:0]   op1,
  input [63:0]   op2,

  input [63:0]   ram_waddr_i,
  input          ram_we_i,
  input [63:0]   ram_rdata_i,
  input          ram_re_i,
  
  input           reg_we_i,
  input  [4:0]    reg_waddr_i,
  
  output [63:0]   wdata,
  output          reg_we,
  output [4:0]    waddr,

  output              ram_we      ,
  output  [63:0]      ram_waddr   ,
  output  [63:0]      ram_wdata   ,
  output              ram_re      ,
  output  [63:0]      ram_raddr   ,
  output  [7:0]       wmask
);
/* verilator lint_off UNOPTFLAT */wire [63:0] result;
ysyx_22050019_alu alu(
  .op_1(op1),
  .op_2(op2),
  .alu_sel(alu_sel),
  
  .result(result)
);

//mem_r_data_mux
wire [63:0] mem_r_data;
ysyx_22050019_mux #( .NR_KEY(6), .KEY_LEN(6), .DATA_LEN(64)) mem_r_data_mux          //of32,16,8  || 32,16,8
(
  .key         (mem_r_wdth),
  .default_out (ram_rdata_i),
  .lut         ({		 6'b100000,{{32{ram_rdata_i[31]}},ram_rdata_i[31:0]},
                 		 6'b010000,{{48{ram_rdata_i[15]}},ram_rdata_i[15:0]},
				             6'b001000,{{56{ram_rdata_i[7 ]}},ram_rdata_i[7 :0]},
				             6'b000100,{32'b0,ram_rdata_i[31:0]},
				             6'b000010,{48'b0,ram_rdata_i[15:0]},
				             6'b000001,{56'b0,ram_rdata_i[7 :0]}
                    }),        
  .out         (mem_r_data)  
);

//mem_w_wdth_mux
wire [7:0] mem_w_mask;
ysyx_22050019_mux #( .NR_KEY(4), .KEY_LEN(4), .DATA_LEN(8)) mem_w_wdth_mux             //basic-64---8---16---32--
(
  .key         (mem_w_wdth),
  .default_out (8'b11111111),
  .lut         ({		 4'b1000,8'b11111111,
                     4'b0100,8'b00000001,
                 		 4'b0010,8'b00000011,
				             4'b0001,8'b00001111
                    }),        
  .out         (mem_w_mask)  
);

//reg_control
assign wdata  = reg_we_i ?(ram_re_i ? mem_r_data : result) : 64'b0;
assign reg_we = reg_we_i ;
assign waddr  = reg_waddr_i ;

//ram_control
assign ram_we    = ram_we_i ;
assign ram_waddr = ram_we_i?result : 64'b0;
assign ram_wdata = ram_waddr_i;
assign ram_re    = ram_re_i ;
assign ram_raddr = ram_re_i?result : 64'b0;
assign wmask     = mem_w_mask ;
endmodule

