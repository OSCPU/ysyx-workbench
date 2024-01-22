package core

import chisel3._

class RegFileIO(xlen: Int) extends Bundle {
  val raddr1 = Input(UInt(5.W))
  val raddr2 = Input(UInt(5.W))
  val rdata1 = Output(UInt(xlen.W))
  val rdata2 = Output(UInt(xlen.W))
  val wen    = Input(Bool())
  val waddr  = Input(UInt(5.W))
  val wdata  = Input(UInt(xlen.W))
  val isExpt = Input(Bool())
}

class RegFile(xlen: Int) extends Module {
  val io = IO(new RegFileIO(xlen))

  //val regfile = Mem(32, UInt(xlen.W))
  val regfile = RegInit(VecInit(Seq.fill(32)(0.U(xlen.W))))
  val mux_raddr1 = Mux(io.isExpt, 0xf.U, io.raddr1)

  // read data
  io.rdata1 := Mux(mux_raddr1.orR, regfile(mux_raddr1), 0.U)
  io.rdata2 := Mux(io.raddr2.orR, regfile(io.raddr2), 0.U)
  
  // write data
  when(io.wen & io.waddr.orR) {
    regfile(io.waddr) := io.wdata
  }
}
