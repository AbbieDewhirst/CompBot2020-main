/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LimelightOn.h"


LimelightOn::LimelightOn(TurretSubsystem* turretSubsystem, bool turnOn) : m_turretsubsystem(turretSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.


l_turnOn = turnOn;
}
// Called when the command is initially scheduled.
void LimelightOn::Initialize() {

if (l_turnOn){
  m_turretsubsystem->LimelightOn();
}
else{
  m_turretsubsystem->LimelightOff();
}


}

// Called repeatedly when this Command is scheduled to run
void LimelightOn::Execute() {}

// Called once the command ends or is interrupted.
void LimelightOn::End(bool interrupted) {}

// Returns true when the command should end.
bool LimelightOn::IsFinished() { return true; }
