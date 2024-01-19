package core

import chisel3._
import chisel3.util._

import core.ControlUnit._

object StageConnect {
  def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T]) = {
    // 定义NPC的架构
    val arch = "single"
    // 不同架构下的不同连接方式
    if(arch == "single") { right.bits := left.bits }
  }
}

class NPCIO(xlen: Int) extends Bundle {
  val pc   = Output(UInt(xlen.W))
  val inst = Output(UInt(xlen.W))
  val exception = Output(Bool())
}

class NPC(xlen: Int) extends Module {
  val io = IO(new NPCIO(xlen))

  val ifu = Module(new IFU(xlen))
  val idu = Module(new IDU(xlen))
  val exu = Module(new EXU(xlen))
  val wbu = Module(new WBU(xlen))

  StageConnect(ifu.io.out, idu.io.in)
  StageConnect(idu.io.out, exu.io.in)
  StageConnect(exu.io.out, wbu.io.in)
}

