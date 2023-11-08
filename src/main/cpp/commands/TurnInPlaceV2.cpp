/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnInPlaceV2.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <iostream>
#include <cmath>

TurnInPlaceV2::TurnInPlaceV2(DriveSubsystem* drivesubsystem, double distanceToTurn, double maxSpeed, double slowDownAngle) : m_drivesubsystem(drivesubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.

  AddRequirements(m_drivesubsystem);
  l_degreesToTurn = distanceToTurn;
  l_slowDownAngle = slowDownAngle;
  //l_startingAngle = m_drivesubsystem->GetGyroAngle();
  l_maxSpeed =  maxSpeed;
  if(l_degreesToTurn < 0){ l_direction = -1.0;}
  else {l_direction = 1.0;}
}

// Called when the command is initially scheduled.
void TurnInPlaceV2::Initialize() {
    // m_drivesubsystem->ZeroGyro();
  targetAngle = m_drivesubsystem->GetGyroAngle() + l_degreesToTurn;
  l_startingAngle = m_drivesubsystem->GetGyroAngle();
  frc::SmartDashboard::PutNumber("Gyro Heading", targetAngle);
  targetAngleToTravel = targetAngle - l_startingAngle;
}

// Called repeatedly when this Command is scheduled to run
void TurnInPlaceV2::Execute() {

  l_angleRemainingToTravel = targetAngle - m_drivesubsystem->GetGyroAngle(); 
  if(l_angleRemainingToTravel < 0){
    l_direction = -1.0;
  }
  else
  {
    l_direction = 1.0;
  }

  // if(std::abs(l_angleRemainingToTravel) > l_slowDownAngle){
  //   l_turnSpeed = 1.0;
  // }
  // else
  // {
  //   double x = std::abs((l_angleRemainingToTravel/l_slowDownAngle))*l_maxSpeed;
  //   //double x = l_angleRemainingToTravel;
  //   double fx = ((-0.2*x)/(-0.2-x+1))*l_maxSpeed;
  //   frc::SmartDashboard::PutNumber("X", x);
  //   frc::SmartDashboard::PutNumber("Fx", fx);
  
  // l_turnSpeed = std::max(std::min(l_maxSpeed, fx),0.4);
  // }

  if(std::abs(targetAngleToTravel) > 90)
  {
    x = std::abs((l_angleRemainingToTravel/targetAngleToTravel));
  }
  else
  {
    x = std::abs((l_angleRemainingToTravel/l_degreesToTurn));
  }

  fx = ((-1.4*x)/(-1.4-x+1));

  l_turnSpeed = std::max(std::min(l_maxSpeed, fx),0.5);
  
  
/*
  double x = std::abs((l_angleRemainingToTravel/targetAngleToTravel))*l_maxSpeed;
  //double x = l_angleRemainingToTravel;
  double fx = ((-0.4*x)/(-0.4-x+1))*l_maxSpeed;
  frc::SmartDashboard::PutNumber("X", x);
  frc::SmartDashboard::PutNumber("Fx", fx);
  
  l_turnSpeed = std::max(std::min(l_maxSpeed, fx),0.4);
  */

  m_drivesubsystem->Drive(0, l_turnSpeed*l_direction);
   
}

// Called once the command ends or is interrupted.
void TurnInPlaceV2::End(bool interrupted) {
    std::cout<<"FINISHED"<<std::endl;
    m_drivesubsystem->DriveStop();
}

// Returns true when the command should end.
bool TurnInPlaceV2::IsFinished() { 
  //Added a second condition to check and make sure speed is slow enough before ending command. MIGHT JUST BE BETTER TO REDUCE KP, not really sure without testing

   frc::SmartDashboard::PutNumber("Target Angle", targetAngle );
   frc::SmartDashboard::PutNumber("Angle Left to Turn", l_angleRemainingToTravel);
   frc::SmartDashboard::PutNumber("Output Speed", l_turnSpeed);
   frc::SmartDashboard::PutNumber("Current Angle", m_drivesubsystem->GetGyroAngle());
  return (std::abs(targetAngle - m_drivesubsystem->GetGyroAngle()) < 2);
}
// return false;
