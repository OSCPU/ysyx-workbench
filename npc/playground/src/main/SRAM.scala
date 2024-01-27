package core

import chisel3._
import chisel3.util._

class SRAM extends BlackBox with HasBlackBoxPath {
  val io = IO(new Bundle {
    val valid       = Input(Bool())
    val rdata_ready = Output(Bool())
    val raddr       = Input(UInt(32.W))
    val rdata       = Output(UInt(32.W))
    val waddr       = Input(UInt(32.W))
    val wdata       = Input(UInt(32.W))
    val wmask       = Input(UInt(8.W))
    val wen         = Input(Bool())
  })
  addPath("/home/wophere/ysyx-workbench/npc/playground/src/main/SRAM.sv")
}
