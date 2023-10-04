// import Mill dependency
import mill._
import mill.scalalib._
import mill.scalalib.scalafmt.ScalafmtModule
import mill.scalalib.TestModule.Utest
// support BSP
import mill.bsp._

object playground extends ScalaModule with ScalafmtModule { m =>
  val useChisel5 = true
  override def scalaVersion = "2.13.10"
  override def scalacOptions = Seq(
    "-language:reflectiveCalls",
    "-deprecation",
    "-feature",
    "-Xcheckinit"
  )
  override def ivyDeps = Agg(
    if (useChisel5) ivy"org.chipsalliance::chisel:5.0.0" else
    ivy"edu.berkeley.cs::chisel3:3.6.0",
  )
  override def scalacPluginIvyDeps = Agg(
    if (useChisel5) ivy"org.chipsalliance:::chisel-plugin:5.0.0" else
    ivy"edu.berkeley.cs:::chisel3-plugin:3.6.0",
  )
  object test extends Tests with Utest {
    override def ivyDeps = m.ivyDeps() ++ Agg(
      ivy"com.lihaoyi::utest:0.8.1",
      if (useChisel5) ivy"edu.berkeley.cs::chiseltest:5.0.0" else
      ivy"edu.berkeley.cs::chiseltest:0.6.0",
    )
  }
  def repositoriesTask = T.task { Seq(
    coursier.MavenRepository("https://maven.aliyun.com/repository/central"),
    coursier.MavenRepository("https://repo.scala-sbt.org/scalasbt/maven-releases"),
  ) ++ super.repositoriesTask() }
}
