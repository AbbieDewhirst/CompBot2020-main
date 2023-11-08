/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/OrganizerMoveCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

OrganizerMoveCommand::OrganizerMoveCommand(OrganizerSubsystem* organizersubsystem, double speed) : m_organizersubsystem(organizersubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  l_speed = speed;
}

// Called when the command is initially scheduled.
void OrganizerMoveCommand::Initialize() {
  time.Start();
  organizerOriginalSpeed = l_speed;
  organizerIsNotInverted = true;
}

// Called repeatedly when this Command is scheduled to run
void OrganizerMoveCommand::Execute() {
  frc::SmartDashboard::PutString("OrganizerMove", "Exe");
  if(time.Get() > 0.5 && m_organizersubsystem->GetOrganizerCurrent() > 15 && organizerIsNotInverted) {
    l_speed = -l_speed;
    organizerIsNotInverted = false;
    time.Reset();
  }
  m_organizersubsystem->OrganizerMove(l_speed);
  if(time.HasPeriodPassed(2) && organizerOriginalSpeed != l_speed) {
    l_speed = organizerOriginalSpeed;
    organizerIsNotInverted = true;
    time.Reset();
  }
}

// Called once the command ends or is interrupted.
void OrganizerMoveCommand::End(bool interrupted) {
  l_speed = organizerOriginalSpeed;
  time.Stop();
  time.Reset();
  m_organizersubsystem->OrganizerStop();
  frc::SmartDashboard::PutString("OrganizerMove", "End");
}

// Returns true when the command should end.
bool OrganizerMoveCommand::IsFinished() { return false; }
