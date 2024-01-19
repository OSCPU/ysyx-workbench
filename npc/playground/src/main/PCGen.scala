package core

import chisel3._

class PCGenIO(xlen: Int) extends Bundle {
  val npc    = Output(UInt(xlen.W))
  val branch = Input(Bool())
  val jal    = Input(Bool())
  val jalr   = Input(Bool())
  val expc   = Input(Bool())
  val eret   = Input(Bool())
  val branch_target = Input(UInt(xlen.W))
  val jal_target    = Input(UInt(xlen.W))
  val jalr_target   = Input(UInt(xlen.W))
  val etvec  = Input(UInt(xlen.W))
  val epc    = Input(UInt(xlen.W))
}

class PCGen(xlen: Int) extends Module {
  val io = IO(new PCGenIO(xlen))

  val pc = RegInit("x80000000".U(xlen.W))

  when(io.expc){
    pc := io.etvec
  }.elsewhen(io.eret){
    pc := io.epc
  }.elsewhen(io.branch) {
    pc := io.branch_target
  }.elsewhen(io.jal) {
    pc:= io.jal_target
  }.elsewhen(io.jalr) {
    pc := io.jalr_target
  }.otherwise {
    pc := pc + 4.U(xlen.W)
  }

  io.npc := pc
}
