package core

import chisel3._
import chisel3.util.MuxLookup

class PCGenIO(xlen: Int) extends Bundle {
  val pc_sel        = Input(UInt(2.W))
  val branch_target = Input(UInt(xlen.W))
  val jal_target    = Input(UInt(xlen.W))
  val jalr_target   = Input(UInt(xlen.W))
  val evec          = Input(UInt(xlen.W))
  val epc           = Input(UInt(xlen.W))
  val npc           = Output(UInt(xlen.W))
}

class PCGen(xlen: Int) extends Module {
  val io = IO(new PCGenIO(xlen))

  val pc = RegInit("x80000000".U(xlen.W))

  pc := MuxLookup(io.pc_sel,pc + 4)(
    Seq(
      PC_4   -> pc + 4,
      PC_ALU -> io.branch_target,
      PC_
    )
  )
  io.npc := pc
}
