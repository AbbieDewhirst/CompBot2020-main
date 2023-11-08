/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveStraightUsingGyroCommand.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <cmath>

using namespace DriveConstants;
DriveStraightUsingGyroCommand::DriveStraightUsingGyroCommand(DriveSubsystem* driveSubsystem, double distanceToDrive, double speed, bool override)
:m_drivesubsystem(driveSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivesubsystem);
  
  l_override = override;
  l_distanceToDrive = distanceToDrive;
  l_speed = speed;
  if(l_distanceToDrive < 0){ l_direction = -1.0;}
  else {l_direction = 1.0;}
}

// Called when the command is initially scheduled.
void DriveStraightUsingGyroCommand::Initialize() {
  if(!l_override){
    l_heading = m_drivesubsystem->GetGyroAngle();
  }else{
    l_heading = frc::SmartDashboard::GetNumber("Gyro Heading", 0.0);
  }
  l_rightEncoder = m_drivesubsystem->GetRightEnc();
  l_leftEncoder = m_drivesubsystem->GetLeftEnc();
  // l_currentspeed = 0.0;

  //convert to ticks( distance in inches * enc tick per rotation * motor rotation per 1 wheel rotation / wheel circumfrance)
  targetPosLeft = (l_leftEncoder + (l_distanceToDrive * kInchesToTicks));
  targetPosRight = (l_rightEncoder + (l_distanceToDrive * kInchesToTicks));
  targetDistanceToTravel = targetPosLeft - l_leftEncoder;
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightUsingGyroCommand::Execute() {
  l_leftEncoder = m_drivesubsystem->GetLeftEnc();
  l_distanceLeftToTravel = abs(targetPosLeft - l_leftEncoder);
 double varr =((m_drivesubsystem->GetGyroAngle() - l_heading)/l_heading);
    std::cout<<"I want to turn at this value  " << varr<<std::endl;

 std::cout<<(l_distanceLeftToTravel/targetDistanceToTravel)<<std::endl;
 frc::SmartDashboard::PutNumber("Turn Speed", varr);
 if(l_distanceToDrive >= 0) l_speed = std::max(.75,l_distanceLeftToTravel/targetDistanceToTravel*.75);//was .6
 else l_speed = std::min(-.75,l_distanceLeftToTravel/targetDistanceToTravel*.75);
  //if(l_currentspeed < l_speed){
    //l_currentspeed = l_currentspeed + std::max(l_speed - l_currentspeed, 0.02);
  // }else{
    //l_currentspeed = l_speed;
  //}
  //m_drivesubsystem->Drive(l_speed, -varr* 1.03);
  frc::SmartDashboard::PutNumber("Zoom", std::abs(l_speed)*l_direction );
  
  m_drivesubsystem->Drive(std::abs(l_speed)*l_direction, (m_drivesubsystem->GetGyroAngle() - l_heading)*.15);

}

// Called once the command ends or is interrupted.
void DriveStraightUsingGyroCommand::End(bool interrupted) {
    m_drivesubsystem->DriveStop();
}

// Returns true when the command should end.
bool DriveStraightUsingGyroCommand::IsFinished() {  
   frc::SmartDashboard::PutNumber("Target POs Left", targetPosLeft );
   frc::SmartDashboard::PutNumber("Current Encoder",m_drivesubsystem->GetAverageEncoderDistance() );
  if (abs(targetPosLeft) - m_drivesubsystem->GetAverageEncoderDistance() < 1000)
  {
    return true;
  }
  else
  {
    return false;
  }
}
