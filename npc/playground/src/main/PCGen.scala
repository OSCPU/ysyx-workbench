package core

import chisel3._
import chisel3.util.RegEnable

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
  val npc           = Output(UInt(xlen.W))
  val en            = Input(Bool())
}

class PCGen(xlen: Int) extends Module {
  val io = IO(new PCGenIO(xlen))

  //val pc = RegInit("x80000000".U(xlen.W))
  val pc_in = Wire(UInt(xlen.W)) 
  val pc    = RegEnable(pc_in, "x80000000".U(xlen.W), io.en)

  when(io.exception) {
    pc_in := io.evec
  }.elsewhen(io.eret) {
    pc_in := io.epc
  }.elsewhen(io.branch) {
    pc_in := io.branch_target
  }.elsewhen(io.jal) {
    pc_in := io.jal_target
  }.elsewhen(io.jalr) {
    pc_in := io.jalr_target
  }.otherwise {
    pc_in := pc + 4.U(xlen.W)
  }

  io.npc := pc
}
