module ysyx_22050019_LSU(
  // 读写位宽
  input [5:0]         mem_r_wdth ,
  input [3:0]         mem_w_wdth ,

  // 读写数据
  input [63:0]        ram_wdata_i ,
  input               ram_we_i    ,

  input               ram_re_i    ,
  
  // alu 结果
  input [63:0]        result,
  input  [4:0]        waddr_reg_i ,
  // 向reg的写数据
  output              wen_reg_o   ,
  output [4:0]        waddr_reg_o ,
  output [63:0]       wdata_reg_o ,

  // 分为读写两个通道描述信号
  // 写通道
  output              ram_we      ,

  output  [63:0]      ram_waddr   ,
  //input               m_axi_aw_ready,
  //output reg          m_axi_aw_valid,

  output  [63:0]      ram_wdata   ,
  output  [7:0]       wmask       ,
  //input               m_axi_w_ready,
  //output reg          m_axi_w_valid,

  // 读通道
  output              ram_re      ,

  input [63:0]        ram_rdata_i ,
  //output reg          m_axi_r_ready,
  //input               m_axi_r_valid,

  //input               m_axi_ar_ready,
  //output reg          m_axi_ar_valid,
  output  [63:0]      ram_raddr   

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
assign wen_reg_o    = ram_re_i;
assign waddr_reg_o  = waddr_reg_i;
assign wdata_reg_o  = ram_re_i ? mem_r_data : 64'b0;

//ram_control
assign ram_we    = ram_we_i ;
assign ram_waddr = ram_we_i ? result : 64'b0;
assign ram_wdata = ram_wdata_i;
assign ram_re    = ram_re_i ;
assign ram_raddr = ram_re_i ? result : 64'b0;
assign wmask     = mem_w_mask ;
endmodule

