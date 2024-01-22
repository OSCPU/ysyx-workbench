package core

import chisel3._
import chisel3.util._

object ControlUnit {
  val Y = true.B
  val N = false.B

  // alu_src1_sel
  val A_XXX = 0.U(1.W)
  val A_PC  = 0.U(1.W)
  val A_RS1 = 1.U(1.W)

  // alu_src2_sel
  val B_XXX = 0.U(1.W)
  val B_IMM = 0.U(1.W)
  val B_RS2 = 1.U(1.W)

  // imm_type
  val IMM_XXX = 0.U(3.W)
  val IMM_I   = 1.U(3.W)
  val IMM_S   = 2.U(3.W)
  val IMM_B   = 3.U(3.W)
  val IMM_U   = 4.U(3.W)
  val IMM_J   = 5.U(3.W)

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
  val WB_CSR = 3.U(2.W)

  // csr_sel
  val CSR_XXX= 0.U(1.W)
  val CSR_R  = 0.U(1.W)
  val CSR_IMM= 1.U(1.W)

  import Alu._
  import Instructions._

  //            exception eret                                                       wb_en  
  //              halt  |  | jal jalr A_sel   B_sel imm_type   alu_op     br_type  st_type ld_type wb_sel  |  csr_sel
  //                 |  |  |  |  |    |       |       |        |           |          |    |       |     |     |
  val default = List(N, N, N, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX)

  val map = Array(
    LUI      -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_U,   ALU_COPY_B, BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    AUIPC    -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_U,   ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    JAL      -> List(N, N, N, Y, N, A_PC,   B_IMM, IMM_J,   ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_PC4, Y, CSR_XXX),
    JALR     -> List(N, N, N, N, Y, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_PC4, Y, CSR_XXX),
    BEQ      -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_EQ ,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    BNE      -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_NE ,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    BLT      -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_LT ,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    BGE      -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_GE ,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    BLTU     -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_LTU,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    BGEU     -> List(N, N, N, N, N, A_PC,   B_IMM, IMM_B,   ALU_ADD   , BR_GEU,  ST_XXX, LD_XXX, WB_ALU, N, CSR_XXX),
    LB       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_LB , WB_MEM, Y, CSR_XXX),
    LH       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_LH , WB_MEM, Y, CSR_XXX),
    LW       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_LW , WB_MEM, Y, CSR_XXX),
    LBU      -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_LBU, WB_MEM, Y, CSR_XXX),
    LHU      -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_LHU, WB_MEM, Y, CSR_XXX),
    SB       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_S,   ALU_ADD   , BR_XXX,  ST_SB , LD_XXX, WB_ALU, N, CSR_XXX),
    SH       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_S,   ALU_ADD   , BR_XXX,  ST_SH , LD_XXX, WB_ALU, N, CSR_XXX),
    SW       -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_S,   ALU_ADD   , BR_XXX,  ST_SW , LD_XXX, WB_ALU, N, CSR_XXX),
    ADDI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLTI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_SLT   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLTIU    -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_SLTU  , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    XORI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_XOR   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    ORI      -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_OR    , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    ANDI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_AND   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLLI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_SLL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SRLI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_SRL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SRAI     -> List(N, N, N, N, N, A_RS1,  B_IMM, IMM_I,   ALU_SRA   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    ADD      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_ADD   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SUB      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SUB   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLL      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SLL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLT      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SLT   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SLTU     -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SLTU  , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    XOR      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_XOR   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SRL      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SRL   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    SRA      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_SRA   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    OR       -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_OR    , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    AND      -> List(N, N, N, N, N, A_RS1,  B_RS2, IMM_XXX, ALU_AND   , BR_XXX,  ST_XXX, LD_XXX, WB_ALU, Y, CSR_XXX),
    CSRRW    -> List(N, N, N, N, N, A_RS1,  B_XXX, IMM_XXX, ALU_COPY_A, BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_R  ),
    CSRRS    -> List(N, N, N, N, N, A_RS1,  B_XXX, IMM_XXX, ALU_COPY_A, BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_R  ),
    CSRRC    -> List(N, N, N, N, N, A_RS1,  B_XXX, IMM_XXX, ALU_COPY_A, BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_R  ),
    CSRRWI   -> List(N, N, N, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_IMM),
    CSRRSI   -> List(N, N, N, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_IMM),
    CSRRCI   -> List(N, N, N, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, Y, CSR_IMM),
    ECALL    -> List(N, Y, N, N, N, A_RS1,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, N, CSR_XXX),
    EBREAK   -> List(Y, N, N, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, N, CSR_XXX),
    MRET     -> List(N, N, Y, N, N, A_XXX,  B_XXX, IMM_XXX, ALU_XXX   , BR_XXX,  ST_XXX, LD_XXX, WB_CSR, N, CSR_XXX)
  )   
}

class CtrlSignals(xlen: Int) extends Bundle {
  val halt      = Output(Bool())
  val exception = Output(Bool())
  val eret      = Output(Bool())
  val jal       = Output(Bool())
  val jalr      = Output(Bool())
  val A_sel     = Output(UInt(1.W))
  val B_sel     = Output(UInt(1.W))
  val imm_type  = Output(UInt(3.W))
  val alu_op    = Output(UInt(4.W))
  val br_type   = Output(UInt(3.W))
  val st_type   = Output(UInt(2.W))
  val ld_type   = Output(UInt(3.W))
  val wb_sel    = Output(UInt(2.W))
  val wb_en     = Output(Bool())
  val csr_sel   = Output(UInt(1.W))
}

class ControlUnitIO(xlen: Int) extends Bundle {
  val inst = Input(UInt(xlen.W))
  val ctrl = new CtrlSignals(xlen)
}

class ControlUnit(xlen: Int) extends Module {
  val io = IO(new ControlUnitIO(xlen))
  
  val ctrlSignals = ListLookup(io.inst, ControlUnit.default, ControlUnit.map)

  // Control signals for exception
  io.ctrl.halt      := ctrlSignals(0).asBool
  io.ctrl.exception := ctrlSignals(1).asBool
  io.ctrl.eret      := ctrlSignals(2).asBool

  // Control signals for Fetch
  io.ctrl.jal  := ctrlSignals(3).asBool
  io.ctrl.jalr := ctrlSignals(4).asBool

  // Control signals for Execute
  io.ctrl.A_sel    := ctrlSignals(5)
  io.ctrl.B_sel    := ctrlSignals(6)
  io.ctrl.imm_type := ctrlSignals(7)
  io.ctrl.alu_op   := ctrlSignals(8)
  io.ctrl.br_type  := ctrlSignals(9)

  // ControlSignals for Memory
  io.ctrl.st_type  := ctrlSignals(10)
  io.ctrl.ld_type  := ctrlSignals(11)

  // Control signals for Write Back
  io.ctrl.wb_sel   := ctrlSignals(12)
  io.ctrl.wb_en    := ctrlSignals(13).asBool

  // Control signals for CSR
  io.ctrl.csr_sel  := ctrlSignals(14)
}
