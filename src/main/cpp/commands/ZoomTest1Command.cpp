/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ZoomTest1Command.h"

ZoomTest1Command::ZoomTest1Command(DriveSubsystemPID* m_drivesubsystemPID, double value) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_value = value;
}

// Called when the command is initially scheduled.
void ZoomTest1Command::Initialize() {
  std::cout<<"random value "<<l_value<<std::endl;
}

// Called repeatedly when this Command is scheduled to run
void ZoomTest1Command::Execute() {
}

// Called once the command ends or is interrupted.
void ZoomTest1Command::End(bool interrupted) {}

// Returns true when the command should end.
bool ZoomTest1Command::IsFinished() { return true; }
