/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ConveyorMoveCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

ConveyorMoveCommand::ConveyorMoveCommand(ConveyorSubsystem* conveyorsubsystem, double speed) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_speed = speed;
}

// Called when the command is initially scheduled.
void ConveyorMoveCommand::Initialize() {
  time.Start();
  conveyorIsNotInverted = true;
  conveyorOriginalSpeed = l_speed;
}

// Called repeatedly when this Command is scheduled to run
void ConveyorMoveCommand::Execute() {
  if(time.Get() > 0.5 && m_conveyorsubsystem->GetConveyorCurrent() > 30 && conveyorIsNotInverted) {
    l_speed = -l_speed;
    conveyorIsNotInverted = false;
    time.Reset();
  }
  m_conveyorsubsystem->ConveyorMove(l_speed);
  if(time.HasPeriodPassed(0.5) && conveyorOriginalSpeed != l_speed) {
    l_speed = conveyorOriginalSpeed;
    conveyorIsNotInverted = true;
    time.Reset();
  }
  frc::SmartDashboard::PutString("Conveyor Move", "Exe");
}

// Called once the command ends or is interrupted.
void ConveyorMoveCommand::End(bool interrupted) {
  l_speed = conveyorOriginalSpeed;
  time.Stop();
  time.Reset();
  m_conveyorsubsystem->ConveyorStop();
  frc::SmartDashboard::PutString("Conveyor Move", "End");
}

// Returns true when the command should end.
bool ConveyorMoveCommand::IsFinished() { return false; }
