package core

import chisel3._
import chisel3.util._

import core.ControlUnit._

class BranchGenIO(xlen: Int) extends Bundle {
  val src1   = Input(UInt(xlen.W))
  val src2   = Input(UInt(xlen.W))
  val opcode = Input(UInt(3.W))
  val branch = Output(Bool())
}

class BranchGen(xlen: Int) extends Module {
  val io = IO(new BranchGenIO(xlen))

  val eq = io.src1 === io.src2
  val ne = !eq
  val lt = io.src1.asSInt < io.src2.asSInt
  val ge = !lt
  val ltu = io.src1.asUInt < io.src2.asUInt
  val geu = !ltu

  io.branch :=
    ((io.opcode === BR_EQ) && eq) ||
    ((io.opcode === BR_NE) && ne) ||
    ((io.opcode === BR_LT) && lt) ||
    ((io.opcode === BR_GE) && ge) ||
    ((io.opcode === BR_LTU) && ltu) ||
    ((io.opcode === BR_GEU) && geu)
}
