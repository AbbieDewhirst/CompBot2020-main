/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


///NOt used, DriveSubsystem is now a PID based system. This is just for initial reference.


#include "subsystems/DriveSubsystemPID.h"

DriveSubsystemPID::DriveSubsystemPID()
    : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(0, 0, 0)) {}

void DriveSubsystemPID::UseOutput(double output, double setpoint) {
  // Use the output here
}

double DriveSubsystemPID::GetMeasurement() {
  // Return the process variable measurement here
  return 0;
}
