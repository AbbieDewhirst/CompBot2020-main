/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveStraightUsingGyroCommandV2.h"
#include "Constants.h"
#include "frc/smartdashboard/SmartDashboard.h"
#include <cmath>


DriveStraightUsingGyroCommandV2::DriveStraightUsingGyroCommandV2(DriveSubsystem* driveSubsystem, double distanceToDrive, double maxSpeed, bool override, double slowDownAngle)
:m_drivesubsystem(driveSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivesubsystem);
  
  l_override = override;
  l_distanceToDrive = distanceToDrive;
  l_maxSpeed = maxSpeed;
  l_slowDownAngle = slowDownAngle;
  // if(l_distanceToDrive < 0){ l_direction = -1.0;}
  // else {l_direction = 1.0;}
}

// Called when the command is initially scheduled.
void DriveStraightUsingGyroCommandV2::Initialize() {
  if(!l_override){
    l_heading = m_drivesubsystem->GetGyroAngle();
  }else{
    l_heading = frc::SmartDashboard::GetNumber("Gyro Heading", 0.0);
  }
  l_leftEncoder = m_drivesubsystem->GetLeftEnc();
  l_rightEncoder = m_drivesubsystem->GetRightEnc();

  // l_rightEncoder = m_drivesubsystem->GetRightEnc();
  // l_leftEncoder = m_drivesubsystem->GetLeftEnc();
  // // l_currentspeed = 0.0;

  //convert to ticks( distance in inches * enc tick per rotation * motor rotation per 1 wheel rotation / wheel circumfrance)
  targetPosLeft = l_leftEncoder + (l_distanceToDrive * DriveConstants::kInchesToTicks);
  targetPosRight = l_rightEncoder + (l_distanceToDrive * DriveConstants::kInchesToTicks);
  targetDistanceToTravelLeft = (targetPosLeft - l_leftEncoder);
  targetDistanceToTravelRight = (targetPosRight - l_rightEncoder);


}

// Called repeatedly when this Command is scheduled to run
void DriveStraightUsingGyroCommandV2::Execute() {


  l_distanceRemainingToTravelLeft = targetPosLeft - m_drivesubsystem->GetLeftEnc();
  l_distanceRemainingToTravelRight = targetPosRight - m_drivesubsystem->GetRightEnc();

    if(l_distanceRemainingToTravelLeft < 0){ l_direction = -1.0;}
    else {l_direction = 1.0;}
  // if (std::abs(l_distanceRemainingToTravelLeft) > 24)
  // {
  //   l_outputSpeed = 0.7;
  // }
  // else{

  //range between 0.4 and maxSpeed

  if (std::abs(l_distanceToDrive) > 36){
    x = std::abs((l_distanceRemainingToTravelLeft/targetDistanceToTravelLeft));
  }
  else{
    x = std::abs((l_distanceRemainingToTravelLeft/(l_distanceToDrive*4* DriveConstants::kInchesToTicks)));
  }
    fx = ((-1.15*x)/(-1.15-x+1));
  //l_outputSpeed = std::max(std::min(l_maxSpeed, std::abs((l_distanceRemainingToTravelLeft/targetDistanceToTravelLeft))*l_maxSpeed),0.4);
  
  l_outputSpeed = std::max(std::min(l_maxSpeed, fx),0.4);

  // }
  m_drivesubsystem->DriveWithRampUpOnly(l_outputSpeed * l_direction, (m_drivesubsystem->GetGyroAngle() - l_heading)*-.12*fx);//*l_direction); // I think this should work for forwards and backwards
     frc::SmartDashboard::PutNumber("Drive fx", fx);
}

// Called once the command ends or is interrupted.
void DriveStraightUsingGyroCommandV2::End(bool interrupted) {
  std::cout<<"FINISHED"<<std::endl;
  m_drivesubsystem->DriveRampReset();
  m_drivesubsystem->DriveStop();
}

// Returns true when the command should end.
bool DriveStraightUsingGyroCommandV2::IsFinished() { 
   frc::SmartDashboard::PutNumber("Target Pos", targetPosLeft );
   frc::SmartDashboard::PutNumber("Target Distance to Travel", std::abs(targetDistanceToTravelLeft - l_leftEncoder) );
   frc::SmartDashboard::PutNumber("Distance Left to Travel", std::abs(targetDistanceToTravelLeft - m_drivesubsystem->GetLeftEnc()));
   frc::SmartDashboard::PutNumber("Output Speed", l_outputSpeed);

   frc::SmartDashboard::PutNumber("Current Encoder",m_drivesubsystem->GetLeftEnc());

  return (std::abs(targetPosLeft - m_drivesubsystem->GetLeftEnc()) < 1000);
 }
