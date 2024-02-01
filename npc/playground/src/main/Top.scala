package core

import chisel3._
import chisel3.util._

import core.ControlUnit._

object StageConnect {
  def apply[T <: Data](left: DecoupledIO[T], right: DecoupledIO[T]) = {
    // 定义NPC的架构
    val arch = "multi"
    // 不同架构下的不同连接方式
    if (arch == "single") {
      right.bits  := left.bits
      left.ready  := right.ready
      right.valid := left.valid
    } else if(arch == "multi") {
      right.bits  := RegNext(left.bits)
      left.ready  := RegNext(right.ready)
      right.valid := RegNext(left.valid)
    }
  }
}

class TopIO(xlen: Int) extends Bundle {
  val pc   = Output(UInt(xlen.W))
  val inst = Output(UInt(xlen.W))
  val halt = Output(Bool())
}

class Top(xlen: Int, arch: String) extends Module {

  val io = IO(new TopIO(xlen))

  val ifu = Module(new IFU(xlen, arch))
  val idu = Module(new IDU(xlen, arch))
  val exu = Module(new EXU(xlen, arch))
  val wbu = Module(new WBU(xlen, arch))

  StageConnect(ifu.io.out, idu.io.in)
  StageConnect(idu.io.out, exu.io.in)
  StageConnect(exu.io.out, wbu.io.in)

  ifu.io.branch        := exu.io.branch
  ifu.io.branch_target := exu.io.out.bits.alu_out
  ifu.io.jal           := idu.io.out.bits.ctrl.jal
  ifu.io.jal_target    := exu.io.out.bits.alu_out
  ifu.io.jalr          := idu.io.out.bits.ctrl.jalr
  ifu.io.jalr_target   := exu.io.out.bits.alu_out
  ifu.io.exception     := idu.io.out.bits.ctrl.exception
  ifu.io.evec          := exu.io.evec
  ifu.io.eret          := idu.io.out.bits.ctrl.eret
  ifu.io.epc           := exu.io.epc
  ifu.io.finish        := wbu.io.finish

  idu.io.wdata := wbu.io.wb_data
  idu.io.wen   := wbu.io.wb_en

  // Top output
  io.halt := idu.io.out.bits.ctrl.halt
  io.pc   := ifu.io.out.bits.pc
  io.inst := ifu.io.out.bits.inst

}
