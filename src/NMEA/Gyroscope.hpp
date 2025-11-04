// SPDX-License-Identifier: GPL-2.0-or-later
// Copyright The XCSoar Project

#pragma once

/**
 * State of turn rates of aircraft
 */
struct GyroscopeState
{
  /**
   * Is turn rate information available?
   */
  bool available;

  /**
   * Is the turn rate information coming from a connected device (true) or
   * was it calculated by XCSoar (false)
   */
  bool real;

  /**
   * turn rate information of external device (if available)
   * or estimated
   * In units of degrees per sec
   * In glider frame
   */
  double turnRateX; // roll, lifting the left wing is positive
  double turnRateY; // pitch, lifting the nose is positive
  double turnRateZ; // yaw, right turn is positive

  void Reset() {
    available = false;
  }

  void ProvideTurnRates(double _turnRateX,
                        double _turnRateY,
                        double _turnRateZ,
                        bool _real=true) noexcept {
    turnRateX = _turnRateX;
    turnRateY = _turnRateY;
    turnRateZ = _turnRateZ;
    real = _real;
    available = true;
  }

  /**
   * Adds data from the specified object, unless already present in
   * this one.
   */
  void Complement(const GyroscopeState &add);
};
