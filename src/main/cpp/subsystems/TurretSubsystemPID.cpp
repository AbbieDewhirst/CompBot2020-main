/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/TurretSubsystemPID.h"

TurretSubsystemPID::TurretSubsystemPID()
    : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(0, 0, 0)) {}

void TurretSubsystemPID::UseOutput(double output, double setpoint) {
  // Use the output here
}

double TurretSubsystemPID::GetMeasurement() {
  // Return the process variable measurement here
  return 0;
}
