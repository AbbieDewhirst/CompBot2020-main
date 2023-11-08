/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoIntakeStopCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

AutoIntakeStopCommand::AutoIntakeStopCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void AutoIntakeStopCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoIntakeStopCommand::Execute() {
  // m_conveyorsubsystem->IntakeMove(-1);
  frc::SmartDashboard::PutString("Intake In", "Exe");
}

// Called once the command ends or is interrupted.
void AutoIntakeStopCommand::End(bool interrupted) {
  m_conveyorsubsystem->IntakeStop();
}

// Returns true when the command should end.
bool AutoIntakeStopCommand::IsFinished() { return true; }
