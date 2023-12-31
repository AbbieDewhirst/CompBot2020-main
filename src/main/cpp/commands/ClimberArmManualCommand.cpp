/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimberArmManualCommand.h"
#include "subsystems/ClimberSubsystem.h"

ClimberArmManualCommand::ClimberArmManualCommand(ClimberSubsystem* climbersubsystem, double speed) : m_climbersubsystem(climbersubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_speed = speed;
  
}

// Called when the command is initially scheduled.
void ClimberArmManualCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ClimberArmManualCommand::Execute() {
  m_climbersubsystem->ArmMove(l_speed);
}

// Called once the command ends or is interrupted.
void ClimberArmManualCommand::End(bool interrupted) {
  m_climbersubsystem->ClimberArmStop();
}

// Returns true when the command should end.
bool ClimberArmManualCommand::IsFinished() {
 return (m_climbersubsystem->GetArmEncoder() < -137000 && l_speed < 0);
}
