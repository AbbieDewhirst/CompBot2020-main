/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WinchInCommand.h"
#include "subsystems/ClimberSubsystem.h"

WinchInCommand::WinchInCommand(ClimberSubsystem* climbersubsystem, double speed) : m_climbersubsystem(climbersubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_speed = speed;
}

// Called when the command is initially scheduled.
void WinchInCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void WinchInCommand::Execute() {
  m_climbersubsystem->ClimberMove(l_speed);
}

// Called once the command ends or is interrupted.
void WinchInCommand::End(bool interrupted) { 
  m_climbersubsystem->ClimberStop();
}

// Returns true when the command should end.
bool WinchInCommand::IsFinished() { return false; }
