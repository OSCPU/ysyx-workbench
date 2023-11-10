package core

import chisel3._
import chisel3.util._
import core.ControlUnit._

class DataExtIO(xlen: Int) extends Bundle {
  val in = Input(UInt(xlen.W))
  val opcode = Input(UInt(3.W))
  val out = Output(UInt(xlen.W))
}

class DataExt(xlen: Int) extends Module {
  val io  = IO(new DataExtIO(xlen))
  val lw  = io.in
  val lh  = Cat(Fill(16, io.in(15)), io.in(15,0))
  val lb  = Cat(Fill(24, io.in(7)),  io.in(7,0))
  val lhu = Cat(0.U(16.W), io.in(15,0))
  val lbu = Cat(0.U(24.W), io.in(7,0))

  io.out := MuxLookup(io.opcode, 0.U)(
    Seq(
      LD_LW  -> lw,
      LD_LH  -> lh,
      LD_LB  -> lb,
      LD_LHU -> lhu,
      LD_LBU -> lbu
    )
  ).asUInt
}