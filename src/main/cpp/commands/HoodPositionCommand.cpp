/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/HoodPositionCommand.h"
#include "subsystems/HoodSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"

HoodPositionCommand::HoodPositionCommand(HoodSubsystem* hoodsubsystem, double pos) : m_hoodsubsystem(hoodsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_pos = pos;
}

// Called when the command is initially scheduled.
void HoodPositionCommand::Initialize() {
  frc::SmartDashboard::PutString("ClimberArm", "init");
  l_min = 2.0;
  l_max = 100.0;
  m_hoodsubsystem->GoToHoodPos(l_pos);
}

// Called repeatedly when this Command is scheduled to run
void HoodPositionCommand::Execute() {
  frc::SmartDashboard::PutString("ClimberArm", "exe");
 
}

// Called once the command ends or is interrupted.
void HoodPositionCommand::End(bool interrupted) {
  m_hoodsubsystem->HoodStop();
  frc::SmartDashboard::PutString("ClimberArm", "end");
}

// Returns true when the command should end.
bool HoodPositionCommand::IsFinished() { 
  return false; 
 }
