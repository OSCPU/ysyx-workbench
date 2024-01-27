package core

import chisel3._
import chisel3.util._

object util {

  def counter(max: UInt) = {
    val x = RegInit(0.asUInt(max.getWidth.W))
    x := Mux(x === max, 0.U, x + 1.U)
    x
  }

  def toggle(p: Bool) = {
    val x = RegInit(false.B)
    x := Mux(p, !x, x)
    x
  }

  def pulse(n: UInt) = counter(n - 1.U) === 0.U

  def squareWave(period: UInt) = toggle(pulse(period >> 1))

}
