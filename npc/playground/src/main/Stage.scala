package core

import chisel3._
import chisel3.util._
import core.ControlUnit._

// IDU产生的控制信号
class CtrlSignals(xlen: Int) extends Bundle {
  val pc_sel   = Output(UInt(2.W))
  val A_sel    = Output(UInt(1.W))
  val B_sel    = Output(UInt(1.W))
  val imm_type = Output(UInt(3.W))
  val alu_op   = Output(UInt(4.W))
  val br_type  = Output(UInt(3.W))
  val st_type  = Output(UInt(2.W))
  val ld_type  = Output(UInt(3.W))
  val wb_sel   = Output(UInt(2.W))
  val wb_en    = Output(Bool())
  val csr_sel  = Output(UInt(1.W))
}

// 各个Stage之间传递的Message
class MessageIFU_IDU(xlen: Int) extends Bundle {
  val inst = Output(UInt(xlen.W))
  val pc   = Output(UInt(xlen.W))
}

class MessageIDU_EXU(xlen: Int) extends Bundle {
  val rdata1 = Output(UInt(xlen.W))
  val rdata2 = Output(UInt(xlen.W))
  val imm    = Output(UInt(xlen.W))
  val inst   = Output(UInt(xlen.W))
  val pc     = Output(UInt(xlen.W))
  val ctrl_signals = new CtrlSignals(xlen)
}

class MessageEXU_WBU(xlen: Int) extends Bundle {
  val alu_out = Output(UInt(xlen.W))
  val mem_out = Output(UInt(xlen.W))
  val csr_out = Output(UInt(xlen.W))
  val pc_4    = Output(UInt(xlen.W))
  val ctrl_signals = new CtrlSignals(xlen)
}

class MessageEXU_IFU(xlen: Int) extends Bundle {
  val alu_out = Output(UInt(xlen.W))
  val epc     = Output(UInt(xlen.W))
  val evec    = Output(UInt(xlen.W))
}

class MessageWBU_IDU(xlen: Int) extends Bundle {
  val wb_data = Output(UInt(xlen.W))
}

// 各个Stage的实现
class IFU(xlen: Int) extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new MessageEXU_IFU(xlen)))
    val out = Decoupled(new MessageIFU_IDU(xlen))
  })

  val pcGen    = Module(new PCGen(xlen))
  val iMemUnit = Module(new MemUnit)

  pcGen.io.branch_target := io.in.bits.alu_out
  pcGen.io.jal_target    := io.in.bits.alu_out
  pcGen.io.jalr_target   := io.in.bits.alu_out
  pcGen.io.epc           := io.in.bits.epc
  pcGen.io.evec          := io.in.bits.evec



}

class IDU(xlen: Int) extends Module {
  val io = IO(new Bundle {
    val in = Flipped(Decoupled(new MessageIFU_IDU(xlen)))
  })

  val regFile     = Module(new RegFile(xlen))
  val immUnit     = Module(new ImmUnit(xlen))
  val controlUnit = Module(new ControlUnit(xlen))
}

class EXU(xlen: Int) extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new MessageIDU_EXU(xlen)))
    val out = Decoupled(new MessageEXU_WBU(xlen))
  })

  val alu       = Module(new Alu(xlen))
  val branchGen = Module(new BranchGen(xlen))
  val dMemUnit  = Module(new MemUnit)
  val dataExt   = Module(new DataExt(xlen))
  val csr       = Module(new Csr(xlen))
}

class WBU(xlen: Int) extends Module {
  val io = IO(new Bundle {
    val in  = Flipped(Decoupled(new MessageEXU_WBU(xlen)))
    val out = Decoupled(new MessageWBU_IDU(xlen))
  })

  io.out.bits.wb_data := MuxLookup(io.in.bits.ctrl_signals.wb_sel, io.in.bits.alu_out)(
    Seq(
      WB_ALU -> io.in.bits.alu_out,
      WB_PC4 -> io.in.bits.pc_4,
      WB_MEM -> io.in.bits.mem_out,
      WB_CSR -> io.in.bits.csr_out
    )
  )

}