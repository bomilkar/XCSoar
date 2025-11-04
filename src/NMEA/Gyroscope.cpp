// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#include "NMEA/Gyroscope.hpp"

void
GyroscopeState::Complement(const GyroscopeState &add)
{
  if (add.available && (!available || (add.real && !real))) {
    real = add.real;
    turnRateX = add.turnRateX;
    turnRateY = add.turnRateY;
    turnRateZ = add.turnRateZ;
    available = add.available;
  }
}
