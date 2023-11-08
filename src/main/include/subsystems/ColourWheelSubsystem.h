/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

#include <frc/util/color.h>
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

class ColourWheelSubsystem : public frc2::SubsystemBase {
 
//  rev::ColorMatch m_colorMatcher;

 
 public:
  ColourWheelSubsystem();
  void ColourWheelFRD();
  void ColourWheelREV();
  void ColourWheelSTOP();
   bool LookforNextColour(frc::Color);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  
 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

  TalonSRX colourwheelmotor {0};
  CANifier canifer1 {9};

    /**
   * Change the I2C port below to match the connection of your color sensor
   */
  static constexpr auto i2cPort = frc::I2C::Port::kOnboard;

  /**
   * A Rev Color Sensor V3 object is constructed with an I2C port as a 
   * parameter. The device will be automatically initialized with default 
   * parameters.
   */
  rev::ColorSensorV3 m_colorSensor{i2cPort};

  /**
   * A Rev Color Match object is used to register and detect known colors. This can 
   * be calibrated ahead of time or during operation.
   * 
   * This object uses a simple euclidian distance to estimate the closest match
   * with given confidence range.
   */
  rev::ColorMatch m_colorMatcher;

};
