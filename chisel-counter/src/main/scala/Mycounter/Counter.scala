package Mycounter
import chisel3._
import chisel3.util._
 import chisel3.stage.ChiselGeneratorAnnotation
 import firrtl.options.TargetDirAnnotation
class MyCounter(max:Int = 16) extends Module{
  val io = IO(new Bundle() {
    val tick = Output(Bool())
  })
//  val c= Counter(max)
  val c = RegInit(0.U(32.W))
  when (c === max.U) {
    c := 0.U
  }.otherwise {
    c := c + 1.U
  }

  io.tick := c === max.U
}

class SimTop extends Module{
  val io = IO(new Bundle() {
    val tick = Output(Bool())
  })
  val myCounter = Module(new MyCounter())
    io.tick := myCounter.io.tick
  //val s : String = "hello"
  //println("this "+s)
  }

object SimTop extends App{
  chisel3.emitVerilog( new SimTop() , Array("--target-dir", "build"))}

