package core

import chisel3._
import chisel3.util._

object Alu {
  val ALU_ADD  = 0.U(4.W)
  val ALU_SUB  = 1.U(4.W)
  val ALU_SLL  = 2.U(4.W)
  val ALU_SLT  = 3.U(4.W)
  val ALU_SLTU = 4.U(4.W)
  val ALU_XOR  = 5.U(4.W)
  val ALU_SRL  = 6.U(4.W)
  val ALU_SRA  = 7.U(4.W)
  val ALU_OR   = 8.U(4.W)
  val ALU_AND  = 9.U(4.W)
  val ALU_COPY_A = 10.U(4.W)
  val ALU_COPY_B = 11.U(4.W)
  val ALU_XXX  = 15.U(4.W)
}

class AluIO(xlen: Int) extends Bundle {
    val src1    = Input(UInt(xlen.W))
    val src2    = Input(UInt(xlen.W))
    val opcode  = Input(UInt(4.W))
    val out     = Output(UInt(xlen.W))
}

import core.Alu._

class Alu(xlen: Int) extends Module {
  val io = IO(new AluIO(xlen))

  val shamt = io.src2(4,0).asUInt

  io.out := MuxLookup(io.opcode, io.src1)(
    Seq(
      ALU_ADD  -> (io.src1 + io.src2),
      ALU_SUB  -> (io.src1 - io.src2),
      ALU_SLL  -> (io.src1 << shamt),
      ALU_SLT  -> (io.src1.asSInt < io.src2.asSInt),
      ALU_SLTU -> (io.src1.asUInt < io.src2.asUInt),
      ALU_XOR  -> (io.src1 ^ io.src2),
      ALU_SRL  -> (io.src1 >> shamt),
      ALU_SRA  -> (io.src1.asSInt >> shamt).asUInt,
      ALU_OR   -> (io.src1 | io.src2),
      ALU_AND  -> (io.src1 & io.src2),
      ALU_COPY_A -> io.src1,
      ALU_COPY_B -> io.src2
    )
  )
}
