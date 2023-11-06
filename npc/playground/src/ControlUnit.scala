package core

import chisel3._
import chisel3.util._

object ControlUnit {
  val Y = true.B
  val N = false.B

  // pc_sel
  val PC_4 = 0.U(2.W)
  val PC_ALU = 1.U(2.W)

  // alu_src1_sel
  val A_XXX = 0.U(1.W)
  val A_PC  = 0.U(1.W)
  val A_RS1 = 1.U(1.W)

  // alu_src2_sel
  val B_XXX = 0.U(1.W)
  val B_IMM = 0.U(1.W)
  val B_RS2 = 1.U(1.W)

  // imm_type
  val IMM_X = 0.U(3.W)
  val IMM_I = 1.U(3.W)
  val IMM_S = 2.U(3.W)
  val IMM_U = 3.U(3.W)
  val IMM_J = 4.U(3.W)
  val IMM_B = 5.U(3.W)

  // br_type
  val BR_XXX = 0.U(3.W)
  val BR_EQ  = 1.U(3.W)
  val BR_NE  = 2.U(3.W)
  val BR_LT  = 3.U(3.W)
  val BR_GE  = 4.U(3.W)
  val BR_LTU = 5.U(3.W)
  val BR_GEU = 6.U(3.W)

  // st_type
  val ST_XXX = 0.U(2.W)
  val ST_SW  = 1.U(2.W)
  val ST_SH  = 2.U(2.W)
  val ST_SB  = 3.U(2.W)

  // ld_type
  val LD_XXX = 0.U(3.W)
  val LD_LW  = 1.U(3.W)
  val LD_LH  = 2.U(3.W)
  val LD_LB  = 3.U(3.W)
  val LD_LHU = 4.U(3.W)
  val LD_LBU = 5.U(3.W)

  // wb_sel
  val WB_ALU = 0.U(2.W)
  val WB_MEM = 1.U(2.W)
  val WB_PC4 = 2.U(2.W)

  import Alu._
  import Instructions._

  val default =
  //                                                                                      wb_en
  //             pc_sel  A_sel   B_sel  imm_type  alu_op   br_type   st_type ld_type wb_sel  |
  //               |       |       |     |          |          |        |       |       |    |
             List(PC_4  , A_XXX,  B_XXX, IMM_X, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, N)
  val map = Array(
    LUI   -> List(PC_4  , A_PC,   B_IMM, IMM_U, ALU_COPY_B, BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    AUIPC -> List(PC_4  , A_PC,   B_IMM, IMM_U, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    JAL   -> List(PC_ALU, A_PC,   B_IMM, IMM_J, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_PC4, Y),
    JALR  -> List(PC_ALU, A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_PC4, Y),
    BEQ   -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_EQ ,  ST_XXX, LD_XXX, WB_ALU, N),
    BNE   -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_NE ,  ST_XXX, LD_XXX, WB_ALU, N),
    BLT   -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_LT ,  ST_XXX, LD_XXX, WB_ALU, N),
    BGE   -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_GE ,  ST_XXX, LD_XXX, WB_ALU, N),
    BLTU  -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_LTU,  ST_XXX, LD_XXX, WB_ALU, N),
    BGEU  -> List(PC_4  , A_PC,   B_IMM, IMM_B, ALU_ADD   , BR_GEU,  ST_XXX, LD_XXX, WB_ALU, N),
    LB    -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_LB , WB_MEM, Y),
    LH    -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_LH , WB_MEM, Y),
    LW    -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_LW , WB_MEM, Y),
    LBU   -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_LBU, WB_MEM, Y),
    LHU   -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_LHU, WB_MEM, Y),
    SB    -> List(PC_4  , A_RS1,  B_IMM, IMM_S, ALU_ADD   , BR_XXX,  ST_SB , LD_XXX, WB_ALU, N),
    SH    -> List(PC_4  , A_RS1,  B_IMM, IMM_S, ALU_ADD   , BR_XXX,  ST_SH , LD_XXX, WB_ALU, N),
    SW    -> List(PC_4  , A_RS1,  B_IMM, IMM_S, ALU_ADD   , BR_XXX,  ST_SW , LD_XXX, WB_ALU, N),
    ADDI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLTI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_SLT   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLTIU -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_SLTU  , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    XORI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_XOR   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    ORI   -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_OR    , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    ANDI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_AND   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLLI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_SLL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SRLI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_SRL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SRAI  -> List(PC_4  , A_RS1,  B_IMM, IMM_I, ALU_SRA   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    ADD   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SUB   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SUB   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLL   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SLL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLT   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SLT   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SLTU  -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SLTU  , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    XOR   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_XOR   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SRL   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SRL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    SRA   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_SRA   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    OR    -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_OR    , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
    AND   -> List(PC_4  , A_RS1,  B_RS2, IMM_X, ALU_AND   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y),
  )
}

class ControlUnitIO(xlen: Int) extends Bundle {
  val inst     = Input(UInt(xlen.W))
  val pc_sel   = Output(UInt(2.W))
  val A_sel    = Output(UInt(1.W))
  val B_sel    = Output(UInt(1.W))
  val imm_type = Output(UInt(3.W))
  val alu_op   = Output(UInt(4.W))
  val br_type  = Output(UInt(3.W))
  val st_type  = Output(UInt(2.W))
  val ld_type  = Output(UInt(3.W))
  val wb_sel   = Output(UInt(2.W))
  val wb_en    = Output(Bool())
}

class ControlUnit(xlen: Int) extends Module {
  val io = IO(new ControlUnitIO(xlen))
  
  val ctrlSignals = ListLookup(io.inst, ControlUnit.default, ControlUnit.map)

  // Control signals for Fetch
  io.pc_sel   := ctrlSignals(0)

  // Control signals for Execute
  io.A_sel    := ctrlSignals(1)
  io.B_sel    := ctrlSignals(2)
  io.imm_type := ctrlSignals(3)
  io.alu_op   := ctrlSignals(4)
  io.br_type  := ctrlSignals(5)

  // ControlSignals for Memory
  io.st_type  := ctrlSignals(6)
  io.ld_type  := ctrlSignals(7)

  // Control signals for Write Back
  io.wb_sel   := ctrlSignals(8)
  io.wb_en    := ctrlSignals(9).asBool
}
