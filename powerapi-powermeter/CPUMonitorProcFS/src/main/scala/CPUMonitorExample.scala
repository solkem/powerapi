import scala.concurrent.duration._

import org.powerapi.PowerMeter
import org.powerapi.core.target._
import org.powerapi.module.cpu.simple.ProcFSCpuSimpleModule
import org.powerapi.reporter.ConsoleDisplay

object CPUMonitorExample extends App {
  val cpu = PowerMeter.loadModule(ProcFSCpuSimpleModule())
  val console = new ConsoleDisplay
  val monitoring = cpu.monitor(All).every(1.second) to console

  cpu.waitFor(5.minutes)

  monitoring.cancel()
  cpu.shutdown()
}

