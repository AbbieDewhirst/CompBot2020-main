/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeSolInCommand.h"
#include "subsystems/ConveyorSubsystem.h"

IntakeSolInCommand::IntakeSolInCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void IntakeSolInCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeSolInCommand::Execute() {
  m_conveyorsubsystem->IntakeIn();
}

// Called once the command ends or is interrupted.
void IntakeSolInCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool IntakeSolInCommand::IsFinished() { return true; }
