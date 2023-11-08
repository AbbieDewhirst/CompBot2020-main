/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterFeederCommand.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <iostream>

ShooterFeederCommand::ShooterFeederCommand(ShooterSubsystemPID* shootersubsystemPID, double speed) : m_shootersubsystemPID(shootersubsystemPID) {
  // Use addRequirements() here to declare subsystem dependencies.
  m_speed = speed;
}

// Called when the command is initially scheduled.
void ShooterFeederCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void ShooterFeederCommand::Execute() {
  frc::SmartDashboard::PutString("ShooterFeeder", "EXE");
  m_shootersubsystemPID->shooterFeederSpeed(m_speed);
  std::cout<<"exx endddddd"<<std::endl;
}

// Called once the command ends or is interrupted.
void ShooterFeederCommand::End(bool interrupted) {
  frc::SmartDashboard::PutString("ShooterFeeder", "End");
m_shootersubsystemPID->shooterFeederStop();
}

// Returns true when the command should end.
bool ShooterFeederCommand::IsFinished() { return false; }
