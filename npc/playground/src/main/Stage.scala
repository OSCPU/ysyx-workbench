package core

import chisel3._
import chisel3.util._
import core.ControlUnit._

import core.util._

// Messages between different stages
class MessageIFU_IDU(xlen: Int) extends Bundle {
  val inst = Output(UInt(xlen.W))
  val pc   = Output(UInt(xlen.W))
}

class MessageIDU_EXU(xlen: Int) extends Bundle {
  val rdata1 = Output(UInt(xlen.W))
  val rdata2 = Output(UInt(xlen.W))
  val imm    = Output(UInt(xlen.W))
  val inst   = Output(UInt(xlen.W))
  val pc     = Output(UInt(xlen.W))
  val ctrl    = new CtrlSignals(xlen)
}

class MessageEXU_WBU(xlen: Int) extends Bundle {
  val alu_out = Output(UInt(xlen.W))
  val mem_out = Output(UInt(xlen.W))
  val csr_out = Output(UInt(xlen.W))
  val pc_4    = Output(UInt(xlen.W))
  val ctrl    = new CtrlSignals(xlen)
}

// Stages
class IFU(xlen: Int, arch: String) extends Module {
  val io = IO(new Bundle {
    val out           = Decoupled(new MessageIFU_IDU(xlen))
    val finish        = Input(Bool())
    val branch        = Input(Bool())
    val jal           = Input(Bool())
    val jalr          = Input(Bool())
    val exception     = Input(Bool())
    val eret          = Input(Bool())
    val branch_target = Input(UInt(xlen.W))
    val jal_target    = Input(UInt(xlen.W))
    val jalr_target   = Input(UInt(xlen.W))
    val evec          = Input(UInt(xlen.W))
    val epc           = Input(UInt(xlen.W))
  })

  val pcGen    = Module(new PCGen(xlen))
  val iMemUnit = Module(new SRAM)

  val s_idle :: s_wait_ready :: Nil = Enum(2)
  val state = RegInit(s_idle)
  state := MuxLookup(state, s_idle)(
    Seq(
      s_idle       -> Mux(io.out.valid, s_wait_ready, s_idle),
      s_wait_ready -> Mux(io.out.ready, s_idle, s_wait_ready)
    )
  )
  io.out.valid := iMemUnit.io.rdata_ready

  // PCGen
  pcGen.io.branch := io.branch
  pcGen.io.branch_target := io.branch_target
  pcGen.io.jal := io.jal
  pcGen.io.jal_target := io.jal_target
  pcGen.io.jalr := io.jalr
  pcGen.io.jalr_target := io.jalr_target
  pcGen.io.eret := io.eret
  pcGen.io.epc := io.epc
  pcGen.io.exception := io.exception
  pcGen.io.evec := io.evec
  io.out.bits.pc := pcGen.io.npc

  // IMem
  iMemUnit.io.raddr := pcGen.io.npc
  iMemUnit.io.valid := true.B
  iMemUnit.io.wen   := 0.U
  iMemUnit.io.waddr := 0.U
  iMemUnit.io.wdata := 0.U
  iMemUnit.io.wmask := 0.U
  io.out.bits.inst := iMemUnit.io.rdata
  pcGen.io.en := iMemUnit.io.rdata_ready
  iMemUnit.io.valid := io.finish

}

class IDU(xlen: Int, arch: String) extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new MessageIFU_IDU(xlen)))
    val out = Decoupled(new MessageIDU_EXU(xlen))
    val wdata = Input(UInt(xlen.W))
    val wen   = Input(Bool())
  })

  val regFile     = Module(new RegFile(xlen))
  val immUnit     = Module(new ImmUnit(xlen))
  val controlUnit = Module(new ControlUnit(xlen))

  val inst   = io.in.bits.inst
  val func7  = inst(31,25)
  val rs2    = inst(24,20)
  val rs1    = inst(19,15)
  val func3  = inst(14,12)
  val rd     = inst(11,7)
  val opcode = inst(6,0)

  io.out.valid := true.B
  io.in.ready := true.B

  // RegFile
  regFile.io.raddr1  := rs1
  io.out.bits.rdata1 := regFile.io.rdata1
  regFile.io.raddr2  := rs2
  io.out.bits.rdata2 := regFile.io.rdata2
  regFile.io.waddr   := rd
  regFile.io.wdata   := io.wdata
  regFile.io.wen     := io.wen
  regFile.io.exception := controlUnit.io.ctrl.exception

  // ImmUnit
  immUnit.io.inst := io.in.bits.inst
  immUnit.io.imm_type := controlUnit.io.ctrl.imm_type
  io.out.bits.imm := immUnit.io.out

  // Control Unit
  controlUnit.io.inst := io.in.bits.inst
  io.out.bits.ctrl := controlUnit.io.ctrl

  // passby
  io.out.bits.inst := io.in.bits.inst
  io.out.bits.pc := io.in.bits.pc
}

class EXU(xlen: Int, arch: String) extends Module {
  val io = IO(new Bundle {
    val in     = Flipped(Decoupled(new MessageIDU_EXU(xlen)))
    val out    = Decoupled(new MessageEXU_WBU(xlen))
    val branch = Output(Bool())
    val epc    = Output(UInt(xlen.W))
    val evec   = Output(UInt(xlen.W))
  })

  val alu       = Module(new Alu(xlen))
  val branchGen = Module(new BranchGen(xlen))
  val dMemUnit  = Module(new MemUnit)
  val dataExt   = Module(new DataExt(xlen))
  val csr       = Module(new Csr(xlen))

  val oprand1 = WireDefault(0.U(xlen.W))
  val oprand2 = WireDefault(0.U(xlen.W))

  io.out.valid := io.in.valid
  io.in.ready := true.B

  // Mux
  oprand1 := MuxLookup(io.in.bits.ctrl.A_sel, io.in.bits.rdata1)(
    Seq(
      A_PC  -> io.in.bits.pc,
      A_RS1 -> io.in.bits.rdata1
    )
  )
  oprand2 := MuxLookup(io.in.bits.ctrl.B_sel, io.in.bits.rdata2)(
    Seq(
      B_IMM -> io.in.bits.imm,
      B_RS2 -> io.in.bits.rdata2
    )
  )

  // Alu
  alu.io.src1 := oprand1
  alu.io.src2 := oprand2
  alu.io.opcode := io.in.bits.ctrl.alu_op
  io.out.bits.alu_out := alu.io.out

  // BranchGen
  branchGen.io.src1 := io.in.bits.rdata1
  branchGen.io.src2 := io.in.bits.rdata2
  branchGen.io.opcode := io.in.bits.ctrl.br_type
  io.branch := branchGen.io.branch

  // DMem
  dMemUnit.io.raddr := alu.io.out
  dMemUnit.io.waddr := alu.io.out
  dMemUnit.io.wdata := io.in.bits.rdata2
  dMemUnit.io.valid := (io.in.bits.ctrl.st_type =/= 0.U) || (io.in.bits.ctrl.ld_type =/= 0.U)
  dMemUnit.io.wen   := (io.in.bits.ctrl.st_type =/= 0.U)
  dMemUnit.io.wmask := MuxLookup(io.in.bits.ctrl.st_type, 0.U)(
    Seq(
      ST_SW -> 15.U,
      ST_SH -> 3.U,
      ST_SB -> 1.U
    )
  )

  // DataExt
  dataExt.io.in := dMemUnit.io.rdata
  dataExt.io.opcode := io.in.bits.ctrl.ld_type
  io.out.bits.mem_out := dataExt.io.out

  // Csr
  csr.io.pc := io.in.bits.pc
  csr.io.inst := io.in.bits.inst
  csr.io.in := io.in.bits.rdata1
  csr.io.exception := io.in.bits.ctrl.exception
  io.out.bits.csr_out := csr.io.out
  io.epc := csr.io.epc
  io.evec := csr.io.evec

  // ctrol signals
  io.out.bits.ctrl := io.in.bits.ctrl

  io.out.bits.pc_4 := io.in.bits.pc + 4.U
}

class WBU(xlen: Int, arch: String) extends Module {
  val io = IO(new Bundle {
    val in      = Flipped(Decoupled(new MessageEXU_WBU(xlen)))
    val wb_data = Output(UInt(xlen.W))
    val wb_en   = Output(Bool())
    val finish  = Output(Bool())
  })

  io.in.ready := true.B

  io.wb_data := MuxLookup(io.in.bits.ctrl.wb_sel, io.in.bits.alu_out)(
    Seq(
      WB_ALU -> io.in.bits.alu_out,
      WB_PC4 -> io.in.bits.pc_4,
      WB_MEM -> io.in.bits.mem_out,
      WB_CSR -> io.in.bits.csr_out
    )
  )
  io.wb_en  := io.in.bits.ctrl.wb_en

  //val wb_over = RegNext(Mux(io.wb_en && io.wb_data.orR, true.B, false.B))
  //io.finish := wb_over || (~io.wb_en && io.in.valid)
  io.finish := squareWave(2.U)
}