/**
 * This software is licensed under the GNU Affero General Public License, quoted below.
 *
 * This file is a part of PowerAPI.
 *
 * Copyright (C) 2011-2014 Inria, University of Lille 1.
 *
 * PowerAPI is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * PowerAPI is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with PowerAPI.

 * If not, please consult http://www.gnu.org/licenses/agpl-3.0.html.
 */

package org.powerapi.sensors.procfs.cpu.dvfs

import java.util.UUID

import akka.actor.{Actor, ActorRef, ActorSystem, Props}
import akka.testkit.{TestActorRef, TestKit}
import akka.util.Timeout
import org.powerapi.UnitTest
import org.powerapi.core.MonitorChannel.{MonitorSubscription, MonitorTicks}
import org.powerapi.core.{Application, MessageBus, OSHelper, Process, Thread}
import org.powerapi.sensors.procfs.cpu.CpuSensorChannel.{CacheKey, CpuSensorReport, TimeInStates, subscribeCpuProcSensor}

import scala.concurrent.duration.DurationInt

trait DvfsCpuSensorConfigurationMock extends Configuration {
  val basepath = getClass.getResource("/").getPath

  override lazy val cores = 4
  override lazy val timeInStatePath = s"$basepath/sys/devices/system/cpu/cpu%?index/cpufreq/stats/time_in_state"
}

class DvfsCpuSensorMock(messageBus: MessageBus, osHelper: OSHelper)
  extends CpuSensor(messageBus, osHelper)
  with DvfsCpuSensorConfigurationMock

class OSHelperMock extends OSHelper {
  def getProcesses(application: Application): List[Process] = List(Process(2), Process(3))

  def getThreads(process: Process): List[Thread] = List()
}

class MockSubscriber(eventBus: MessageBus, actorRef: ActorRef) extends Actor {
  override def preStart() = {
    subscribeCpuProcSensor(eventBus)(self)
  }

  def receive = {
    case msg: CpuSensorReport => actorRef ! msg
  }
}

/**
 * DvfsCpuSensorSuite
 *
 * @author abourdon
 * @author mcolmant
 */
class DvfsCpuSensorSuite(system: ActorSystem) extends UnitTest(system) {

  implicit val timeout = Timeout(1.seconds)

  def this() = this(ActorSystem("DvfsCpuSensorSuite"))

  override def afterAll() = {
    TestKit.shutdownActorSystem(system)
  }

  val eventBus = new MessageBus

  val cpuSensor = TestActorRef(Props(classOf[DvfsCpuSensorMock], eventBus, new OSHelperMock()), "dvfs-CpuSensor")(system)

  "A TimeInStates case class" should "compute the difference with another one" in {
    val timesLeft = TimeInStates(Map(1 -> 10, 2 -> 20, 3 -> 30, 4 -> 15))
    val timesRight = TimeInStates(Map(1 -> 1, 2 -> 2, 3 -> 3, 100 -> 100))

    (timesLeft - timesRight) should equal(TimeInStates(Map(1 -> 9, 2 -> 18, 3 -> 27, 4 -> 15)))
  }

  "Frequencies' time in states" should "be correctly read from the dedicated system file" in {
    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.timeInStates should equal(Map(
      4000000 -> 16,
      3000000 -> 12,
      2000000 -> 8,
      1000000 -> 4
    ))
  }

  "Frequencies' cache" should "be correctly updated during process phase" in {
    val muid = UUID.randomUUID()
    val target = Process(1)
    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.cache should have size 0
    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.handleTarget(muid, target)
    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.cache should equal(
      Map(CacheKey(muid, target) -> TimeInStates(Map(4000000 -> 16, 3000000 -> 12, 2000000 -> 8, 1000000 -> 4)))
    )
  }

  "A dvfs CpuSensor" should "process a MonitorTicks message and then publish a CpuSensorReport" in {
    TestActorRef(Props(classOf[MockSubscriber], eventBus, testActor), "subscriber")(system)
    val muid = UUID.randomUUID()
    val timeInStates = TimeInStates(Map(4000000 -> 6, 3000000 -> 2, 2000000 -> 2, 1000000 -> 2))
    val monitorTicks = MonitorTicks("test", MonitorSubscription(muid, 25.milliseconds, List(Process(1), Application("app"))), System.currentTimeMillis)

    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.refreshCache(CacheKey(muid, Process(1)),
      TimeInStates(Map(4000000 -> 10, 3000000 -> 10, 2000000 -> 6, 1000000 -> 2))
    )

    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].frequencies.refreshCache(CacheKey(muid, Application("app")),
      TimeInStates(Map(4000000 -> 10, 3000000 -> 10, 2000000 -> 6, 1000000 -> 2))
    )

    cpuSensor.underlyingActor.asInstanceOf[CpuSensor].sense(monitorTicks)
    expectMsgClass(classOf[CpuSensorReport]) match {
      case CpuSensorReport(_, m, Process(1), _, t ,_) if m == muid && t == timeInStates => assert(true)
      case CpuSensorReport(_, m, Application("app"), _, t ,_) if m == muid && t == timeInStates => assert(true)
      case _ => assert(false)
    }
    expectMsgClass(classOf[CpuSensorReport]) match {
      case CpuSensorReport(_, m, Process(1), _, t ,_) if m == muid && t == timeInStates => assert(true)
      case CpuSensorReport(_, m, Application("app"), _, t ,_) if m == muid && t == timeInStates => assert(true)
      case _ => assert(false)
    }
  }
}
