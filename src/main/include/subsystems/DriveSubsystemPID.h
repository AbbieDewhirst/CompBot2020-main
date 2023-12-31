/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/PIDSubsystem.h>

class DriveSubsystemPID : public frc2::PIDSubsystem {
 public:
  DriveSubsystemPID();

 protected:
  void UseOutput(double output, double setpoint) override;

  double GetMeasurement() override;
};
