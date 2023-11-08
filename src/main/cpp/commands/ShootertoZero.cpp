/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootertoZero.h"

ShootertoZero::ShootertoZero(HoodSubsystem* hoodSubsystem, ShooterSubsystemPID* ShooterSubsystem) : m_hoodsubsystem(hoodSubsystem), m_shootersubsystem(ShooterSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ShootertoZero::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ShootertoZero::Execute() {
  
}

// Called once the command ends or is interrupted.
void ShootertoZero::End(bool interrupted) {
  m_hoodsubsystem->GoToHoodPos(0);
  m_shootersubsystem->FlywheelSTOP();
}

// Returns true when the command should end.
bool ShootertoZero::IsFinished() { return true; }
