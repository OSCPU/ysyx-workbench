//package core
import core.Top

import circt.stage._

object Elaborate extends App {
  val xlen = 32
  val arch = "single"
  def top = new Top(xlen, arch)
  // val generator = Seq(chisel3.stage.ChiselGeneratorAnnotation(() => top))
  // (new ChiselStage).execute(args, generator :+ CIRCTTargetAnnotation(CIRCTTarget.Verilog))

  val chiselStageOptions = Seq(
    chisel3.stage.ChiselGeneratorAnnotation(() => top),
    CIRCTTargetAnnotation(CIRCTTarget.SystemVerilog)
  )

  val firtoolOptions = Seq(
    FirtoolOption(
      "--lowering-options=disallowLocalVariables,disallowPackedArrays,locationInfoStyle=wrapInAtSquareBracket"
      ),
    FirtoolOption("--split-verilog"),
    FirtoolOption("-o=build/sv-gen"),
    FirtoolOption("--disable-all-randomization")
  )

  val executeOptions = chiselStageOptions ++ firtoolOptions

  val executeArgs = Array("-td", "build")

  (new ChiselStage).execute(executeArgs, executeOptions)
}
