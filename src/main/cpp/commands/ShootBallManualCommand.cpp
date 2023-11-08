/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootBallManualCommand.h"

ShootBallManualCommand::ShootBallManualCommand(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, int velocity) : m_shootersubsystemPID(shootersubsystemPID), m_conveyorsubsystem(conveyorsubsystem), m_organizersubsystem(organizersubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  l_velocity = velocity;
}

// Called when the command is initially scheduled.
void ShootBallManualCommand::Initialize() {
  m_shootersubsystemPID->FlywheelMove(14000);
  m_conveyorsubsystem->ConveyorMove(0.5);
  m_organizersubsystem->OrganizerMove(-0.5);
  m_conveyorsubsystem->IntakeMove(-0.5);
  m_shootersubsystemPID->shooterFeederSpeed(-1.0);
}

// Called repeatedly when this Command is scheduled to run
void ShootBallManualCommand::Execute() {}

// Called once the command ends or is interrupted.
void ShootBallManualCommand::End(bool interrupted) {
  m_shootersubsystemPID->FlywheelSTOP();
  m_conveyorsubsystem->ConveyorStop();
  m_organizersubsystem->OrganizerStop();
  m_conveyorsubsystem->IntakeStop();
  m_shootersubsystemPID->shooterFeederStop();
}

// Returns true when the command should end.
bool ShootBallManualCommand::IsFinished() { return false; }
