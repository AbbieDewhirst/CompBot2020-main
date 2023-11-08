/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoIntakeCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

AutoIntakeCommand::AutoIntakeCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoIntakeCommand::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeCommand::Execute() {
      m_conveyorsubsystem->IntakeMove(-1);
}

// Called once the command ends or is interrupted.
void AutoIntakeCommand::End(bool interrupted) {
}

// Returns true when the command should end.
bool AutoIntakeCommand::IsFinished() { return false; }
