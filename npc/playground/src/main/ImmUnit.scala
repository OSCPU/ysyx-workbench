package core

import chisel3._
import chisel3.util._
import core.ControlUnit._

class ImmUnitIO(xlen: Int) extends Bundle {
  val inst = Input(UInt(xlen.W))
  val imm_type = Input(UInt(3.W))
  val out  = Output(UInt(xlen.W))
}

class ImmUnit(val xlen: Int) extends Module {
  val io = IO(new ImmUnitIO(xlen))
  // imm definition
  val imm_i = Cat(Fill(21, io.inst(31)), io.inst(30,20))
  val imm_s = Cat(Fill(21, io.inst(31)), io.inst(30,25), io.inst(11,7))
  val imm_b = Cat(Fill(20, io.inst(31)), io.inst(7), io.inst(30,25), io.inst(11,8), 0.U(1.W))
  val imm_j = Cat(Fill(12, io.inst(31)), io.inst(19,12), io.inst(20), io.inst(30,21), 0.U(1.W))
  val imm_u = Cat(io.inst(31,12), 0.U(12.W))
  // imm look up table
  io.out := MuxLookup(io.imm_type, 0.U)(
    Seq(
      IMM_I -> imm_i,
      IMM_S -> imm_s,
      IMM_B -> imm_b,
      IMM_J -> imm_j,
      IMM_U -> imm_u,
      )
    ).asUInt
}
