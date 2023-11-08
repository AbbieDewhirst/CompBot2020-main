/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeOutCommand.h"
#include "subsystems/ConveyorSubsystem.h"

IntakeOutCommand::IntakeOutCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void IntakeOutCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeOutCommand::Execute() {
  m_conveyorsubsystem->IntakeMove(0.50);
}

// Called once the command ends or is interrupted.
void IntakeOutCommand::End(bool interrupted) {
  m_conveyorsubsystem->IntakeStop();
}

// Returns true when the command should end.
bool IntakeOutCommand::IsFinished() { return false; }
