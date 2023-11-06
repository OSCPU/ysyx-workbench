//package core
import core.Top

import circt.stage._

object Elaborate extends App {
  val xlen = 32
  def top = new Top(xlen)
  val generator = Seq(chisel3.stage.ChiselGeneratorAnnotation(() => top))
  (new ChiselStage).execute(args, generator :+ CIRCTTargetAnnotation(CIRCTTarget.Verilog))
}
