/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimberArmEncoderCommand.h"
#include "subsystems/ClimberSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

ClimberArmEncoderCommand::ClimberArmEncoderCommand(ClimberSubsystem* climbersubsystem, double pos) : m_climbersubsystem(climbersubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_pos = pos;
}

// Called when the command is initially scheduled.
void ClimberArmEncoderCommand::Initialize() {
  frc::SmartDashboard::PutString("ClimberArm", "init");
  l_min = 2.0;
  l_max = 100.0;
  m_climbersubsystem->GoToArmPos(l_pos);
}

// Called repeatedly when this Command is scheduled to run
void ClimberArmEncoderCommand::Execute() {
  frc::SmartDashboard::PutString("ClimberArm", "exe");
  // if ((m_climbersubsystem->GetArmEncoder() == l_min) || (m_climbersubsystem->GetArmEncoder() == l_max)){
    // m_climbersubsystem->ClimberArmStop();
  // }
}

// Called once the command ends or is interrupted.
void ClimberArmEncoderCommand::End(bool interrupted) {
  m_climbersubsystem->ClimberArmStop();
  frc::SmartDashboard::PutString("ClimberArm", "end");
}

// Returns true when the command should end.
bool ClimberArmEncoderCommand::IsFinished() { 
  // if((m_climbersubsystem->GetArmEncoder() - l_pos) <10){return true;}
  return false; 
 }
