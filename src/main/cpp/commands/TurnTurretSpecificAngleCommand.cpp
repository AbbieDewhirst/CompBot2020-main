/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnTurretSpecificAngleCommand.h"
#include "frc/smartdashboard/SmartDashboard.h"

TurnTurretSpecificAngleCommand::TurnTurretSpecificAngleCommand(TurretSubsystem* turretsubsystem, double pos) : m_turretsubsystem(turretsubsystem){
  l_pos = pos;
  l_startingPos = m_turretsubsystem->GetEncoders();
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TurnTurretSpecificAngleCommand::Initialize() {
      frc::SmartDashboard::PutString("Status", "Start Turrett");

  m_turretsubsystem->SetTurret(l_pos);

}

// Called repeatedly when this Command is scheduled to run
void TurnTurretSpecificAngleCommand::Execute() {
}

// Called once the command ends or is interrupted.
void TurnTurretSpecificAngleCommand::End(bool interrupted) {
  m_turretsubsystem->StopTurret();
    frc::SmartDashboard::PutString("Status", "END Turrett");
}

// Returns true when the command should end.
bool TurnTurretSpecificAngleCommand::IsFinished() { 
  return (m_turretsubsystem->GetEncoders() > 5598) || (m_turretsubsystem->GetEncoders() < -5980) || abs((l_pos)- m_turretsubsystem->GetEncoders()) <= 500;
  }
