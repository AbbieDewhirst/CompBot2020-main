/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurretVisionV2.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <iostream>
#include <cmath>

TurretVisionV2::TurretVisionV2(TurretSubsystem* turretsubsystem) : m_turretsubsystem(turretsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void TurretVisionV2::Initialize() {

  targetAngle = 2.0;
  l_startingAngle = m_turretsubsystem->GetErr();
  targetAngleToTravel = targetAngle - l_startingAngle;
  // if(targetAngleToTravel < 0){ l_direction = -1.0;}
  // else {l_direction = 1.0;}
}

// Called repeatedly when this Command is scheduled to run
void TurretVisionV2::Execute() {

  l_error = targetAngle - m_turretsubsystem->GetErr();
    if(l_error < 0){ l_direction = -1.0;}
  else {l_direction = 1.0;}
  // if (std::abs(l_error) > 8){
  //   l_turnSpeed = 0.6;
  // }
  // else{
    if (std::abs(targetAngleToTravel) > 8){
      x = std::abs((l_error/targetAngleToTravel));
    }
    else{
      x = std::abs((l_error/8.0));
    }
    
    fx = ((-3.2*x)/(-3.2-x+1));

   l_turnSpeed = std::max(std::min(1.0, fx),0.4);

  
  //}

  if (m_turretsubsystem->isTarget()){
  m_turretsubsystem->TurnTurret(l_turnSpeed*l_direction);
  }
  else{
    l_error = 0.0;
  }
}

// Called once the command ends or is interrupted.
void TurretVisionV2::End(bool interrupted) {

  m_turretsubsystem->StopTurret();
}

// Returns true when the command should end.
bool TurretVisionV2::IsFinished() { 
  
   frc::SmartDashboard::PutNumber("tx to turn", l_error);
   frc::SmartDashboard::PutNumber("tx Speed", l_turnSpeed);
   frc::SmartDashboard::PutNumber("current tx", m_turretsubsystem->GetErr());
   frc::SmartDashboard::PutNumber("turret fx", fx);
  return (std::abs(l_error) < 0.4) && fx < 0.05; }
