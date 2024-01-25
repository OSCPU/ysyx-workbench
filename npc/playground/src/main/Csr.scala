package core

import chisel3._
import chisel3.util._

object CSR_INST {
  val csrrw = 1.U
  val csrrs = 2.U
  val csrrc = 3.U
}
object CSR_ADDR {
  val mstatus_addr = 0x300.U(12.W)
  val mtvec_addr   = 0x305.U(12.W)
  val mepc_addr    = 0x341.U(12.W)
  val mcause_addr  = 0x342.U(12.W)

  val regs = List(
    mstatus_addr,
    mtvec_addr,
    mepc_addr,
    mcause_addr
  )
}

class CsrIO(xlen: Int) extends Bundle {
  val pc        = Input(UInt(xlen.W))
  val inst      = Input(UInt(xlen.W))
  val in        = Input(UInt(xlen.W))
  val exception = Input(Bool())
  val out       = Output(UInt(xlen.W))
  val epc       = Output(UInt(xlen.W))
  val evec      = Output(UInt(xlen.W))
}

class Csr(val xlen: Int) extends Module {
  val io = IO(new CsrIO(xlen))

  val csr_addr = io.inst(31, 20)
  
  val mstatus = RegInit(0.U(xlen.W))
  val mtvec   = RegInit(0.U(xlen.W))
  val mepc    = RegInit(0.U(xlen.W))
  val mcause  = RegInit(0.U(xlen.W))

  val csrFile = Seq(
    CSR_ADDR.mstatus_addr -> mstatus,
    CSR_ADDR.mtvec_addr   -> mtvec,
    CSR_ADDR.mepc_addr    -> mepc,
    CSR_ADDR.mcause_addr  -> mcause
  )
  io.out := MuxLookup(csr_addr, 0.U)(csrFile).asUInt

  io.evec := mtvec
  io.epc  := mepc

  val oprand = MuxLookup(io.inst(14), 0.U)(
    Seq(
      0.U -> io.in,
      1.U -> io.inst(19,15)
    )
  )

  val wdata = MuxLookup(io.inst(13,12), 1.U)(
    Seq(
      CSR_INST.csrrw -> oprand,
      CSR_INST.csrrs -> (io.out | oprand),
      CSR_INST.csrrc -> (io.out & ~oprand),
    )
  )
  
  val wen = (io.inst(6,0) === "b1110011".U)

  when(io.exception) {
    mepc := io.pc
    mcause := io.in
  }.elsewhen(wen) {
    when(csr_addr === CSR_ADDR.mepc_addr) {
      mepc := wdata
    }.elsewhen(csr_addr === CSR_ADDR.mcause_addr) {
      mcause := wdata
    }.elsewhen(csr_addr === CSR_ADDR.mstatus_addr) {
      mstatus := wdata
    }.elsewhen(csr_addr === CSR_ADDR.mtvec_addr) {
      mtvec := wdata
    }
  }

}
