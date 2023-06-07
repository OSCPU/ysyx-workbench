import "DPI-C" function void ebreak();
module ysyx_22050019_IDU(
  input [63:0]   inst_addr_pc,
  input [31:0]   inst_i,
  input [63:0]   rdata1,
  input [63:0]   rdata2,

  output[63:0]   snpc,
  output         inst_j,

  output         ram_we,
  output[63:0]   ram_wdata,
  output         ram_re,

  output[4:0]    raddr1,
  output[4:0]    raddr2,
  output[63:0]   op1   ,
  output[63:0]   op2   ,

  output[5:0]    mem_r_wdth,
  output[3:0]    mem_w_wdth,

  output[7:0]    csr_inst_type,
  output         csr_wen,
  output[11:0]   csr_addr,

  output         reg_we_o,
  output[4:0]    reg_waddr_o,
  output[`LEN:0] alu_sel

);
wire  [6:0]	opcode = inst_i[6:0]    ;
wire  [4:0]	rd     = inst_i[11:7]   ;
wire  [2:0]	funct3 = inst_i[14:12]  ;
wire  [4:0]	rs1    = inst_i[19:15]  ;
wire  [4:0]	rs2    = inst_i[24:20]  ;
wire  [6:0]	funct7 = inst_i[31:25]  ;

//i型指令信号制作
wire  [11:0] imm_12_I = {funct7,rs2};
wire  [63:0] imm_12_I_64 = { {52{imm_12_I[11]}}, imm_12_I};
//u型指令信号制作
wire  [19:0] imm_20 = {funct7,rs2,rs1,funct3};
wire  [63:0] imm_20_U_64 = {{32{imm_20[19]}},imm_20, 12'b0}; 
//j型指令信号制作
wire  [19:0] imm_20_j = {inst_i[31], inst_i[19:12], inst_i[20], inst_i[30:21]};
wire  [63:0] imm_20_j_64 ={{43{imm_20_j[19]}},imm_20_j,1'b0};
//b型指令信号制作
wire  [11:0] imm_12_b = {inst_i[31], inst_i[7],inst_i[30:25], inst_i[11:8]};
wire  [63:0] imm_12_b_64 = {{51{imm_12_b[11]}}, imm_12_b, 1'b0};
//s型指令信号制作
wire  [11:0] imm_12_s = { inst_i[31:25], inst_i[11:7] } ;
wire  [63:0] imm_12_s_64 = { {52{imm_12_s[11]}}, imm_12_s } ;

wire  [4:0]  imm_sel ={(inst_auipc||inst_lui),(inst_jal),(op_i||inst_jalr||inst_addiw||inst_l),(op_b),(op_s)};
wire  [63:0] imm64;
ysyx_22050019_mux #( .NR_KEY(5), .KEY_LEN(5), .DATA_LEN(64)) mux_imm
(
  .key         (imm_sel), //键
  .default_out ({64{1'b0}}),
  .lut         ({		 
                 		 5'b010000,imm_20_U_64,
				             5'b001000,imm_20_j_64,
				             5'b000100,imm_12_I_64,
				             5'b000010,imm_12_b_64,
				             5'b000001,imm_12_s_64}), //键和输出的表           
  .out         (imm64)  //输出
);
// 根据opcode的值分选指令类型
wire op_i       = ( opcode == `ysyx_22050019_INST_TYPE_I  )                ;//00100
wire op_b       = ( opcode == `ysyx_22050019_INST_TYPE_B  )                ;//11000
wire op_s       = ( opcode == `ysyx_22050019_INST_TYPE_S  )                ;//01000
wire op_r       = ( opcode == `ysyx_22050019_INST_TYPE_R  )                ;//01100
wire inst_l     = ( opcode == `ysyx_22050019_INST_L       )                ;//00000
wire op_csr     = ( opcode == `ysyx_22050019_INST_CSR     )                ;//11100

wire inst_addiw = ( opcode == `ysyx_22050019_INST_ADDIW   )                ;//00110
wire inst_auipc = ( opcode == `ysyx_22050019_INST_AUIPC   )                ;//00101
wire inst_lui   = ( opcode == `ysyx_22050019_INST_LUI     )                ;//01101
wire inst_jal   = ( opcode == `ysyx_22050019_INST_JAL     )                ;//11011
wire inst_jalr  = ( opcode == `ysyx_22050019_INST_JALR    )                ;//11001
wire inst_w     = ( opcode == `ysyx_22050019_INST_ADDW    )                ;//01110

// 根据funct3的值细分出
wire rv32_funct3_000    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_000 )     ;
wire rv32_funct3_001    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_001 )     ;
wire rv32_funct3_010    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_010 )     ;
wire rv32_funct3_011    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_011 )     ;
wire rv32_funct3_100    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_100 )     ;
wire rv32_funct3_101    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_101 )     ;
wire rv32_funct3_110    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_110 )     ;
wire rv32_funct3_111    = ( funct3 == `ysyx_22050019_RV32_FUNCT3_111 )     ;
// 根据funct7的值细分出
wire rv32_funct7_000_0000 = ( funct7 == `ysyx_22050019_RV32_FUNCT7_0000000) ;
wire rv32_funct7_000_0001 = ( funct7 == `ysyx_22050019_RV32_FUNCT7_0000001) ;
wire rv32_funct7_010_0000 = ( funct7 == `ysyx_22050019_RV32_FUNCT7_0100000) ; 


//识别指令的译码模块，要注意可能多条指令间用为的方式可能会导致不兼容需要注意。
//会在每一条指令后面插入相应的行为方便调试debug以及正确性验证
//各个指令的使能信号声明（不言自明)（忽略了伪指令的部分只记录实际部分）
//=====================================================================
// 在alu中运行的指令
// 一些加法和减法指令，通过加法器接受根据指令来源的输入来实现
wire add  = op_r&&rv32_funct3_000&&rv32_funct7_000_0000;
wire addi = op_i&&rv32_funct3_000;
wire addiw= inst_addiw&&rv32_funct3_000;
wire addw = inst_w&&rv32_funct3_000&&(~rv32_funct7_000_0001)&&(~rv32_funct7_010_0000);

wire sub  = op_r&&rv32_funct3_000&&rv32_funct7_010_0000;
wire subw = inst_w&&rv32_funct3_000&&rv32_funct7_010_0000;

// 比较指令
wire slt  = op_r&&rv32_funct3_010&&rv32_funct7_000_0000;
wire slti = op_i&&rv32_funct3_010;
wire sltiu= op_i&&rv32_funct3_011;
wire sltu = op_r&&rv32_funct3_011;

// 与非异或指令的实现，通过与门或门等门电路实现
wire AND  = op_r&&rv32_funct3_111&&(~rv32_funct7_000_0001);
wire andi = op_i&&rv32_funct3_111;
wire OR   = op_r&&rv32_funct3_110;
wire ori  = op_i&&rv32_funct3_110;
wire xor0 = op_r&&rv32_funct3_100&&rv32_funct7_000_0000;
wire xori = op_i&&rv32_funct3_100;

// 逻辑左移指令，对数据进行移位
wire sll  = op_r&&rv32_funct3_001&&rv32_funct7_000_0000;
wire slli = op_i&&rv32_funct3_001&&(inst_i[31:26] == 6'b0);
wire slliw= inst_addiw&&rv32_funct3_001&&rv32_funct7_000_0000;
wire sllw = inst_w&&rv32_funct3_001;

// 逻辑右移指令，对数据进行移位
wire srl  = op_r&&rv32_funct3_101&&rv32_funct7_000_0000;//sdb测试程序menu-》小鸟游戏bug，调试定点开启diff和gtkwave，删调diff在进入页面后会报错
wire srli = op_i&&rv32_funct3_101&&(inst_i[31:26] == 6'b0);
wire srliw= inst_addiw&&rv32_funct3_101&&rv32_funct7_000_0000;
wire srlw = inst_w&&rv32_funct3_101&&rv32_funct7_000_0000;

// 算术右移指令，对数据进行移位
wire sra  = op_r&&rv32_funct3_101&&rv32_funct7_010_0000;
wire srai = op_i&&rv32_funct3_101&&(inst_i[31:26] == 6'b010000);
wire sraiw= inst_addiw&&rv32_funct3_101&&rv32_funct7_010_0000;
wire sraw = inst_w&&rv32_funct3_101&&rv32_funct7_010_0000;

// 除法指令，使用除法器进行运算
wire div  = op_r&&rv32_funct3_100&&rv32_funct7_000_0001;
wire divu = op_r&&rv32_funct3_101&&rv32_funct7_000_0001;
wire divuw= inst_w&&rv32_funct3_101&&rv32_funct7_000_0001;
wire divw = inst_w&&rv32_funct3_100&&rv32_funct7_000_0001;

// 取余指令，使用取余器进行运算（除法器）
wire rem  = op_r&&rv32_funct3_110&&rv32_funct7_000_0001;
wire remu = op_r&&rv32_funct3_111&&rv32_funct7_000_0001;
wire remuw= inst_w&&rv32_funct3_111&&rv32_funct7_000_0001;
wire remw = inst_w&&rv32_funct3_110&&rv32_funct7_000_0001;

// 乘法指令，使用乘法器进行运算
wire mul  = op_r&&rv32_funct3_000&&rv32_funct7_000_0001;
wire mulw = inst_w&&rv32_funct3_000&&rv32_funct7_000_0001;

// 加载指令，从内存中获取相应的数据
wire lb   = inst_l&&rv32_funct3_000;
wire lbu  = inst_l&&rv32_funct3_100;
/* verilator lint_off UNUSED */wire ld   = inst_l&&rv32_funct3_011;//读双字就已经默认了全读，exu在default中个设定控制,方便调试用的
wire lh   = inst_l&&rv32_funct3_001;
wire lhu  = inst_l&&rv32_funct3_101;
wire lw   = inst_l&&rv32_funct3_010;
wire lwu  = inst_l&&rv32_funct3_110;

// 存储指令，向内存中写入相应的数据
wire sb   = op_s&&rv32_funct3_000;
wire sd   = op_s&&rv32_funct3_011;
wire sh   = op_s&&rv32_funct3_001;
wire sw   = op_s&&rv32_funct3_010;

// 一些不经过alu运行的跳转指令
// 分支跳转指令，这一部分在idu中进行跳转在idu阶段就可以输出跳转信号
wire beq  = op_b&&rv32_funct3_000;
wire bge  = op_b&&rv32_funct3_101;
wire bgeu = op_b&&rv32_funct3_111;
wire blt  = op_b&&rv32_funct3_100;
wire bltu = op_b&&rv32_funct3_110;
wire bne  = op_b&&rv32_funct3_001;
/*******************************csr指令的控制处理**************************/
wire csrrw = op_csr&&rv32_funct3_001;// csr写入x[rd]，x[rs1]写入csr
wire ecall = op_csr&&(inst_i[31:7] == 25'b0);//snpc->mtvec,把当前pc保存给mepc，把异常号0xb给mcause
wire csrrs = op_csr&&rv32_funct3_010;//读csr和x[rs1]按位或结果再写回csr，原本csr值写回x[rd]
wire mret  = inst_i[31:0] == 32'b0011000_00010_00000_000_00000_1110011;//处理mstatus，跳转回发生异常时的地址

//csr控制信号生成
assign csr_inst_type = {4'b0,mret,csrrs,ecall,csrrw};
assign csr_wen       = csrrw||ecall||csrrs;
assign csr_addr      = op_csr?imm_12_I:12'b0;


//***********************************************************************
//这里的控制模块把输出位宽的控制集成到了单根线中，在alu中根据控制信号线来分辨相应的正确输出
//***********************************************************************
// 带i的是立即数操作在选择,带w的是字操作，带u的是无符号数，对于算术移位乘法除法取余不带u需要考虑符号，加法采用的补码加所以可以忽略
// alu部分制作
// =====================
// 使用加法器的控制信号划分
wire alu_add    = add||addi||inst_auipc||inst_lui||inst_jal||inst_jalr||op_s||inst_l;
wire alu_add_32 = addiw||addw;
// 减法
wire alu_sub    = sub;
wire alu_sub_32 = subw;
// 比较
wire alu_slt    = slt||slti;
wire alu_sltu   = sltiu||sltu;
// =====================
// 对操作数进行与或等操作的控制信号划分
wire alu_and    = andi||AND;
wire alu_or     = OR||ori;
wire alu_xor    = xori||xor0;
// =====================
// 一些alu移位指令控制信号
// =====================
// 逻辑左移
wire alu_sll_64 = sll;
wire alu_slli_64= slli;
wire alu_slli_32= slliw;
wire alu_sll_32 = sllw;
// 逻辑右移
wire alu_srl_64 = srl;
wire alu_srli_64= srli;
wire alu_srli_32= srliw;
wire alu_srl_32 = srlw;
// 算术右移
wire alu_sra_64 = sra;
wire alu_srai_64= srai;
wire alu_srai_32= sraiw;
wire alu_sra_32 = sraw;
// =====================
// 一些alu除法器指令控制信号
// =====================
// 取余
wire alu_rem_64 = rem;
wire alu_remu_64= remu;
wire alu_remu_32= remuw;
wire alu_rem_32 = remw;
// 除法
wire alu_div_64 = div;
wire alu_divu_64= divu;
wire alu_divu_32= divuw;
wire alu_div_32 = divw;
// =====================
// 一些alu乘法器指令控制信号
// =====================
wire alu_mul    = mul;
wire alu_mul_32 = mulw;







assign alu_sel  =  {alu_mul_32,alu_mul,alu_div_32,alu_divu_32,alu_divu_64,alu_div_64,alu_rem_32,alu_remu_32,alu_remu_64,alu_rem_64,alu_sra_32,alu_srai_32,alu_srai_64,alu_sra_64,alu_srl_32,alu_srli_32,alu_srli_64,alu_srl_64,alu_sll_32,alu_slli_32,alu_slli_64,alu_sll_64,alu_xor,alu_or,alu_and,alu_sltu,alu_slt,alu_sub_32,alu_sub,alu_add_32,alu_add};


//=====================================================================
/*
SLLIW、SRLIW、SRAIW是RV64I仅有的指令，与其定义相类似，但是它们对32位数值进
行操作，并产生有符号的32位结果。如果imm[5]≠0，SLLIW、SRLIW、SRAIW指令将会产生
一个异常。
对于这一个问题采用的解决方法是指令译码时强制imm[5]=0,但在一些关键的控制信号中使用inst_w可能会导致无效指令被更新出错误的值，
我的解决措施是将写使能inst_w拆分为对应的有效指令，这可以让无效指令无法写入reg。
*/
//=====================================================================
//对于reg和mem的控制信号的信号配置处理
//reg_control
assign reg_we_o    =  op_i||inst_auipc||inst_lui||inst_jal||inst_jalr||op_r||(addiw|slliw|sraiw|srliw)||(inst_w)||(csrrw||csrrs);//使能
assign reg_waddr_o =  reg_we_o|inst_l ? rd : 5'b0;
assign raddr1      =  (op_i||inst_jalr||op_s||op_r||inst_l||inst_addiw||(inst_w)||op_b)||(csrrw||csrrs)?rs1:5'b0;//数据
assign raddr2      =  (op_b||op_s||op_r||(inst_w))?rs2:5'b0;

//mem_control
assign ram_we      = op_s;
assign ram_wdata   = op_s ? rdata2 : 64'b0;//write
assign ram_re      = inst_l;
//mem_r_wdth
assign mem_r_wdth = {lw,lh,lb,lwu,lhu,lbu};               //of32,16,8  || 32,16,8   
//mem_w_wdth
assign mem_w_wdth = {sd,sb,sh,sw};                        //else(64)---8---16---32--


//=====================================================================
//操作数op1/op2的通过指令类型来选择处理
//op1_sel
wire [1:0]op1_en   = {(inst_auipc||inst_jal||inst_jalr) ,(op_i||op_s||op_r||inst_addiw||inst_l||(inst_w))};
ysyx_22050019_mux #( .NR_KEY(2), .KEY_LEN(2), .DATA_LEN(64) ) mux_op1
(
  .key         (op1_en), //键
  .default_out (64'b0),
  .lut         ({2'b10,inst_addr_pc,
                 2'b01,rdata1
                 }), //键和输出的表           
  .out         (op1)  //输出
);

//op2_sel
wire [2:0]op2_en   =  {(op_i||inst_auipc||inst_lui||op_s||inst_addiw||inst_l) ,op_r||(inst_w),(inst_jal||inst_jalr)};
ysyx_22050019_mux #( .NR_KEY(3), .KEY_LEN(3), .DATA_LEN(64)) mux_op2
(
  .key         (op2_en), //键
  .default_out (64'b0),
  .lut         ({
                 3'b100,imm64,
                 3'b010,rdata2,
                 3'b001,64'd4}),         
  .out         (op2)  //输出
);


//=====================================================================
//对于要进行pc跳转的指令信号进行控制
//pc_branch
assign inst_j      = inst_jal||inst_jalr||beq&&beq_y||bne&&(~beq_y)||bge&&(~b_ab_1_s)||blt&&b_ab_1_s||bltu&&b_ab_1_u||bgeu&&(~b_ab_1_u)||(ecall||mret); //跳转信号制作处
wire [1:0]branch   = {(inst_jal||op_b),inst_jalr};
ysyx_22050019_mux #( .NR_KEY(2), .KEY_LEN(2), .DATA_LEN(64)) mux_branch
(
  .key         (branch), //键
  .default_out (64'd0),
  .lut         ({2'b10,inst_addr_pc+imm64,
                 2'b01,(rdata1+imm_12_I_64)&(~64'b1)}),           
  .out         (snpc)  //输出
);


//=====================================================================
//b型指令结果处理
wire [63:0]b_ab_s = rdata1 + (~rdata2 + 64'b1);//补码-法，进行判断运算
wire beq_y = b_ab_s == 64'b0;                  //ab->equal
wire b_ab_1_s       = ( ( ( rdata1[63] == 1'b1 ) && ( rdata2[63] == 1'b0 ) ) 
                        | ( (rdata1[63] == rdata2[63] ) && ( b_ab_s[63] == 1'b1 ) ) );//有符号小于<
wire b_ab_1_u      = ( ( ( rdata1[63] == 1'b0 ) && ( rdata2[63] == 1'b1 ) ) 
                        | ( (rdata1[63] == rdata2[63] ) && ( b_ab_s[63] == 1'b1 ) ) );//无符号小于<





endmodule
