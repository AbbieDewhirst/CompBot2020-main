/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShooterForwardsCommand.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "frc/smartdashboard/SmartDashboard.h"

ShooterForwardsCommand::ShooterForwardsCommand(ShooterSubsystemPID* shootersubsystemPID, double velocity) : m_shootersubsystemPID(shootersubsystemPID) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_velocity = velocity;
}

// Called when the command is initially scheduled.
void ShooterForwardsCommand::Initialize() {
    m_shootersubsystemPID->FlywheelMove(l_velocity);
}

// Called repeatedly when this Command is scheduled to run
void ShooterForwardsCommand::Execute() {
  frc::SmartDashboard::PutString("Shooter Forwards", "Exe");
}

// Called once the command ends or is interrupted.
void ShooterForwardsCommand::End(bool interrupted) {
  m_shootersubsystemPID->FlywheelSTOP();   
  frc::SmartDashboard::PutString("Shooter Forwards", "End");

}

// Returns true when the command should end.
bool ShooterForwardsCommand::IsFinished() { return false; }
