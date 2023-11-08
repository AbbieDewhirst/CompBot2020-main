/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "frc/Ultrasonic.h"
#include "frc/DigitalInput.h"
#include "frc/AnalogInput.h"

class RangeFindingSubsystem : public frc2::SubsystemBase {
 public:
  RangeFindingSubsystem();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.

frc::Ultrasonic driveUltrasonic {0,1};
frc::AnalogInput lightSensor {0};

};
