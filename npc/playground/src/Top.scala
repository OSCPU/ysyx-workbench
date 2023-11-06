package core

import chisel3._
import chisel3.util._

import core.ControlUnit._

class TopIO(xlen: Int) extends Bundle {
  val inst = Input(UInt(xlen.W))
  val pc   = Output(UInt(xlen.W))
  val halt = Output(Bool())
}

class Top(xlen: Int) extends Module {
  val io = IO(new TopIO(xlen))
  // basic variables definition
  val func7  = io.inst(31,25)
  val rs2    = io.inst(24,20)
  val rs1    = io.inst(19,15)
  val func3  = io.inst(14,12)
  val rd     = io.inst(11,7)
  val opcode = io.inst(6,0)

  // wire definition
  val oprand1 = WireDefault(0.U(xlen.W))
  val oprand2 = WireDefault(0.U(xlen.W))
  val reg_write_data = WireDefault(0.U(xlen.W))
  val branch_target  = WireDefault(0.U(xlen.W))
  val jal_target     = WireDefault(0.U(xlen.W))
  val jalr_target    = WireDefault(0.U(xlen.W))

  // specify module
  // IFU
  val pcGen       = Module(new PCGen(xlen))
  // IDU
  val regFile     = Module(new RegFile(xlen))
  val immUnit     = Module(new ImmUnit(xlen))
  val controlUnit = Module(new ControlUnit(xlen))
  // EXU
  val alu         = Module(new Alu(xlen))
  val branchGen   = Module(new BranchGen(xlen))
  // MEM
  val mem         = BlackBox(new Mem)

  // route modules
  // data path design
  io.halt        := io.inst === ("h00100073".U)

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
  reg_write_data := MuxLookup(controlUnit.io.wb_sel, alu.io.out)(
    Seq(
      WB_ALU -> alu.io.out,
      WB_PC4 -> (pcGen.io.npc + 4.U),
      WB_MEM -> mem.io.rdata
      )
  )
  branch_target  := alu.io.out
  jal_target     := alu.io.out
  jalr_target    := alu.io.out

  io.pc                  := pcGen.io.npc
  pcGen.io.branch_target := branch_target
  pcGen.io.jal_target    := jal_target
  pcGen.io.jalr_target   := jalr_target

  regFile.io.raddr1 := rs1
  regFile.io.raddr2 := rs2
  regFile.io.waddr  := rd
  regFile.io.wdata  := reg_write_data

  immUnit.io.inst := io.inst

  controlUnit.io.inst := io.inst

  alu.io.src1 := oprand1
  alu.io.src2 := oprand2

  branchGen.io.src1 := oprand1
  branchGen.io.src2 := oprand2

  /*mem*/
  mem.io.raddr := alu.io.out
  mem.io.waddr := alu.io.out
  mem.io.wdata := oprand2

  // control logic design
  pcGen.io.branch := branchGen.io.branch
  pcGen.io.jal    := (controlUnit.io.pc_sel === PC_ALU) && (controlUnit.io.imm_type === IMM_J)
  pcGen.io.jalr   := (controlUnit.io.pc_sel === PC_ALU) && (controlUnit.io.imm_type === IMM_I)

  regFile.io.wen  := controlUnit.io.wb_en
  immUnit.io.imm_type := controlUnit.io.imm_type

  alu.io.opcode   := controlUnit.io.alu_op
  branchGen.io.opcode := controlUnit.io.br_type

  mem.io.wen := (controlUnit.io.st_type =/= 0.U)
  mem.io.wmask := MuxLookup(controlUnit.io.st_type, 4.U)(
    Seq(
      ST_SW -> 4.U,
      ST_SH -> 2.U,
      ST_SB -> 1.U
    )
  )
}
