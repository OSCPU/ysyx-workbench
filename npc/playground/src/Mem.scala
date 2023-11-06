package core

import chisel3._
import chisel3.util._

class MemIO extends Bundle {
  val raddr = Input(UInt(32.W))
  val rdata = Output(UInt(32.W))
  val waddr = Input(UInt(32.W))
  val wdata = Input(UInt(xlen.W))
  val wmask = Input(UInt(8.W))
  val wen   = Input(Bool())
}

class Mem extends BlackBox with HasBlackBoxPath {
  val io = IO(new MemIO)

  addPath("/home/wophere/ysyx-workbench/npc/playground/src/memory.v")
}
