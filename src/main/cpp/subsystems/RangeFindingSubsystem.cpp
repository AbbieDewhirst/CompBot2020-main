/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/RangeFindingSubsystem.h"
#include <iostream>

RangeFindingSubsystem::RangeFindingSubsystem() {

driveUltrasonic.SetAutomaticMode(true);

}

// This method will be called once per scheduler run
void RangeFindingSubsystem::Periodic() {

   // std::cout << " light " << lightSensor.GetVoltage() << std::endl;
}
