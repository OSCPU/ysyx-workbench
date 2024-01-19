package core

import chisel3._
import chisel3.util._

import core.ControlUnit._

class TopIO(xlen: Int) extends Bundle {
  val pc   = Output(UInt(xlen.W))
  val inst = Output(UInt(xlen.W))
  val halt = Output(Bool())
}

class Top(xlen: Int) extends Module {
  val io = IO(new TopIO(xlen))
  // mux target definition
  val oprand1 = WireDefault(0.U(xlen.W))
  val oprand2 = WireDefault(0.U(xlen.W))
  val wb_data = WireDefault(0.U(xlen.W))
  val csr_in  = WireDefault(0.U(xlen.W))

  // specify module
  // IFU
  val pcGen       = Module(new PCGen(xlen))
  val iMemUnit    = Module(new MemUnit)
  // IDU
  val regFile     = Module(new RegFile(xlen))
  val immUnit     = Module(new ImmUnit(xlen))
  val controlUnit = Module(new ControlUnit(xlen))
  // EXU
  val alu         = Module(new Alu(xlen))
  val branchGen   = Module(new BranchGen(xlen))
  // Mem
  val dMemUnit    = Module(new MemUnit)
  val dataExt     = Module(new DataExt(xlen))
  // CSR
  val csr         = Module(new Csr(xlen))

  // basic variables definition
  val inst   = iMemUnit.io.rdata
  val func7  = inst(31,25)
  val rs2    = inst(24,20)
  val rs1    = inst(19,15)
  val func3  = inst(14,12)
  val rd     = inst(11,7)
  val opcode = inst(6,0)

  iMemUnit.io.raddr := pcGen.io.npc
  iMemUnit.io.valid := true.B
  iMemUnit.io.wen   := 0.U
  iMemUnit.io.waddr := 0.U
  iMemUnit.io.wdata := 0.U
  iMemUnit.io.wmask := 0.U

  io.pc := pcGen.io.npc
  io.inst := iMemUnit.io.rdata
  // route modules
  // data path design
  io.halt        := inst === ("h00100073".U)
  val isExpt      = inst === ("h00000073".U)
  val isEret      = inst === ("h30200073".U)

  oprand1 := MuxLookup(controlUnit.io.A_sel, regFile.io.rdata1)(
    Seq(
      A_PC -> pcGen.io.npc,
      A_RS1 -> regFile.io.rdata1
    )
  )
  oprand2 := MuxLookup(controlUnit.io.B_sel, regFile.io.rdata2)(
    Seq(
      B_IMM -> immUnit.io.out,
      B_RS2 -> regFile.io.rdata2
    )
  )
  wb_data := MuxLookup(controlUnit.io.wb_sel, alu.io.out)(
    Seq(
      WB_ALU -> alu.io.out,
      WB_PC4 -> (pcGen.io.npc + 4.U),
      WB_MEM -> dataExt.io.out,
      WB_CSR -> csr.io.out
    )
  )
  csr_in  := MuxLookup(controlUnit.io.csr_sel, regFile.io.rdata1)(
    Seq(
      CSR_R   -> regFile.io.rdata1,
      CSR_IMM -> immUnit.io.out
    )
  )
  pcGen.io.branch_target := alu.io.out
  pcGen.io.jal_target    := alu.io.out
  pcGen.io.jalr_target   := alu.io.out
  pcGen.io.epc           := csr.io.epc
  pcGen.io.evec         := csr.io.evec

  regFile.io.raddr1 := rs1
  regFile.io.raddr2 := rs2
  regFile.io.waddr  := rd
  regFile.io.wdata  := wb_data

  immUnit.io.inst := inst

  controlUnit.io.inst := inst

  alu.io.src1 := oprand1
  alu.io.src2 := oprand2

  branchGen.io.src1 := regFile.io.rdata1
  branchGen.io.src2 := regFile.io.rdata2

  /*dMemUnit*/
  dMemUnit.io.raddr := alu.io.out
  dMemUnit.io.waddr := alu.io.out
  dMemUnit.io.wdata := regFile.io.rdata2

  dataExt.io.in := dMemUnit.io.rdata

  /*csr*/
  csr.io.inst   := inst
  csr.io.pc     := io.pc
  csr.io.in     := csr_in
  csr.io.isExpt := isExpt

  // control logic design
  pcGen.io.branch := branchGen.io.branch
  pcGen.io.jal    := (controlUnit.io.pc_sel === PC_ALU) && (controlUnit.io.imm_type === IMM_J)
  pcGen.io.jalr   := (controlUnit.io.pc_sel === PC_ALU) && (controlUnit.io.imm_type === IMM_I)
  pcGen.io.eret   := isEret
  pcGen.io.expc   := isExpt
  regFile.io.wen  := controlUnit.io.wb_en
  regFile.io.isExpt := isExpt
  immUnit.io.imm_type := controlUnit.io.imm_type

  alu.io.opcode   := controlUnit.io.alu_op
  branchGen.io.opcode := controlUnit.io.br_type

  dMemUnit.io.valid := (controlUnit.io.st_type =/= 0.U) || (controlUnit.io.ld_type =/= 0.U)
  dMemUnit.io.wen := (controlUnit.io.st_type =/= 0.U)
  dMemUnit.io.wmask := MuxLookup(controlUnit.io.st_type, 0.U)(
    Seq(
      ST_SW -> 15.U,
      ST_SH -> 3.U,
      ST_SB -> 1.U
    )
  )

  dataExt.io.opcode := controlUnit.io.ld_type
}
