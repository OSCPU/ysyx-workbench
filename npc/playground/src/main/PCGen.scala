package core

import chisel3._

class PCGenIO(xlen: Int) extends Bundle {
  val branch        = Input(Bool())
  val jal           = Input(Bool())
  val jalr          = Input(Bool())
  val eret          = Input(Bool())
  val exception     = Input(Bool())
  val branch_target = Input(UInt(xlen.W))
  val jal_target    = Input(UInt(xlen.W))
  val jalr_target   = Input(UInt(xlen.W))
  val evec          = Input(UInt(xlen.W))
  val epc           = Input(UInt(xlen.W))
  val pc_in         = Output(UInt(xlen.W))
}

class PCGen(xlen: Int) extends Module {
  val io = IO(new PCGenIO(xlen))

  val pc = RegInit("x80000000".U(xlen.W))

  when(io.exception) {
    pc := io.evec
  }.elsewhen(io.eret) {
    pc := io.epc
  }.elsewhen(io.branch) {
    pc := io.branch_target
  }.elsewhen(io.jal) {
    pc := io.jal_target
  }.elsewhen(io.jalr) {
    pc := io.jalr_target
  }.otherwise {
    pc := pc + 4.U(xlen.W)
  }

  io.pc_in := pc
}
