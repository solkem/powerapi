/*
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
 *
 * If not, please consult http://www.gnu.org/licenses/agpl-3.0.html.
 */
package org.powerapi.module.powerspy;

public class PowerSpyEvent {
  private final Double currentRMS;
  private final Float uScale;
  private final Float iScale;

  public PowerSpyEvent(Double currentRMS, Float uScale, Float iScale) {
    this.currentRMS = currentRMS;
    this.uScale = uScale;
    this.iScale = iScale;
  }

  public Double getCurrentRMS() {
    return currentRMS;
  }

  public Float getUScale() {
    return uScale;
  }

  public Float getIScale() {
    return iScale;
  }
}
