/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoodCommand.h"
#include "subsystems/HoodSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

HoodCommand::HoodCommand(HoodSubsystem* hoodsubsystem, double speed) : m_hoodsubsystem(hoodsubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  l_speed = speed;
}

// Called when the command is initially scheduled.
void HoodCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HoodCommand::Execute() {
  m_hoodsubsystem->HoodMove(l_speed);
  //frc::SmartDashboard::PutNumber("Hood ENC",m_hoodsubsystem->GetHoodEncoder());
}//0 and 3400

// Called once the command ends or is interrupted.

void HoodCommand::End(bool interrupted) {
  m_hoodsubsystem->HoodStop();
}

// Returns true when the command should end.
bool HoodCommand::IsFinished() { 
  return (m_hoodsubsystem->GetHoodEncoder() > 3400 && l_speed > 0) || (m_hoodsubsystem->GetHoodEncoder() < 0 && l_speed < 0);

}
