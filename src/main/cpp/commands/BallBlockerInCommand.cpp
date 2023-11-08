/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/BallBlockerInCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>

BallBlockerInCommand::BallBlockerInCommand( ConveyorSubsystem* conveyorSubsystem) : m_conveyorsubsystem(conveyorSubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void BallBlockerInCommand::Initialize() {
  frc::SmartDashboard::PutNumber("init", 1);
  m_conveyorsubsystem->BallBlockerIn();
  frc::SmartDashboard::PutNumber("init after", 1);
}

// Called repeatedly when this Command is scheduled to run
void BallBlockerInCommand::Execute() {
  frc::SmartDashboard::PutNumber("exxxxxxxxx", 1);
}

// Called once the command ends or is interrupted.
void BallBlockerInCommand::End(bool interrupted) {
    frc::SmartDashboard::PutNumber("endddddddddddddddddd", 1);


}

// Returns true when the command should end.
bool BallBlockerInCommand::IsFinished() { 
  frc::SmartDashboard::PutNumber("is finished", 1);

  return true; }
