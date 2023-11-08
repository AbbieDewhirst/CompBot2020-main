/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/OrganizerSubsystem.h"

OrganizerSubsystem::OrganizerSubsystem() {}

// This method will be called once per scheduler run
void OrganizerSubsystem::Periodic() {}

void OrganizerSubsystem::OrganizerMove(double speed) {
    // organizerMotorL.Set(ControlMode::PercentOutput, speed);
    organizerMotorR.Set(ControlMode::PercentOutput, speed);
}
void OrganizerSubsystem::OrganizerStop() {
    // organizerMotorL.Set(ControlMode::PercentOutput, 0.0);
    organizerMotorR.Set(ControlMode::PercentOutput, 0.0);
}

double OrganizerSubsystem::GetOrganizerCurrent() {
    return organizerMotorR.GetOutputCurrent();
}