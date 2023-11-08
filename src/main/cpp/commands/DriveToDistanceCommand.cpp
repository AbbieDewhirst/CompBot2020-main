/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveToDistanceCommand.h"
#include "Robot.h"
#include "math.h"
#include "Constants.h"
#include <iostream>
#include <frc2/command/WaitCommand.h>
using namespace DriveConstants;

DriveToDistanceCommand::DriveToDistanceCommand(DriveSubsystem* driveSubsystem, double distanceToDrive, bool useUltrasonic, double ultraDistance)
:m_drivesubsystem(driveSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivesubsystem);
  l_distanceToDrive = distanceToDrive;
  l_ultraDistance = ultraDistance;
  l_useUltrasonic = useUltrasonic;
}

// Called when the command is initially scheduled.
void DriveToDistanceCommand::Initialize() {
  // m_drivesubsystem->UsePIDProfile(1);

  m_drivesubsystem->ZeroDriveEncoders();
  m_drivesubsystem->InvertRightDriveMotor(false);
  l_rightEncoder = m_drivesubsystem->GetRightEnc();
  l_leftEncoder = m_drivesubsystem->GetLeftEnc();

  //convert to ticks( distance in inches * enc tick per rotation * motor rotation per 1 wheel rotation / wheel circumfrance)
  targetPosLeft = (l_leftEncoder + (l_distanceToDrive * kInchesToTicks));
  targetPosRight = (l_rightEncoder - (l_distanceToDrive * kInchesToTicks));
  m_drivesubsystem->SetTargetPosition(targetPosLeft, targetPosRight);
   std::cout<<"left Encoder = "<<l_leftEncoder<< " right encoder = " << l_rightEncoder<< std::endl;
  std::cout<<"left target = " <<targetPosLeft<<" right target pos = "<<targetPosRight<<std::endl;
  std::cout<<"\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\"<<std::endl;
  // m_drivesubsystem->Wait(0.005);// wait for a motor update time//not working
  std::cout<<"initialize"<<std::endl;
}

// Called repeatedly when this Command is scheduled to run
void DriveToDistanceCommand::Execute() {
  l_rightEncoder = m_drivesubsystem->GetRightEnc();
  l_leftEncoder = m_drivesubsystem->GetLeftEnc();
  // std::cout<<"left Encoder = "<<l_leftEncoder<< " right encoder = " << l_rightEncoder<< std::endl;
  // std::cout<<"left target = " <<targetPosLeft<<" right target pos = "<<targetPosRight<<std::endl;
  // std::cout<<"exucute"<<std::endl;
  // m_drivesubsystem->SetTargetPosition(targetPosLeft, targetPosRight);
  // m_drivesubsystem->Wait(0.005);// wait for a motor update time//not working

}

// Called once the command ends or is interrupted.
void DriveToDistanceCommand::End(bool interrupted) {
  m_drivesubsystem->SetMotionMagicOFF();
  m_drivesubsystem->InvertRightDriveMotor(false);
  // m_drivesubsystem->UsePIDProfile(0);
  std::cout<<"end"<<std::endl;
}

// Returns true when the command should end.
bool DriveToDistanceCommand::IsFinished() { 
/*
*If the ultrasonic is being used then the command will finish when either,
*the target distance is reached or the ultra sonic distance is reached
*
*If the ultrasonic is NOT being used then the command will finish when
*we have reached the encoder target position
*/
  // if ((abs(targetPosLeft - m_drivesubsystem->GetLeftEnc()) < 1000)
  // || (/*(l_useUltrasonic) &&*/ (m_drivesubsystem->GetUltraSonic() <= l_ultraDistance))){ 
  //   return true;
  // }
  // else return false;
  return (abs(targetPosLeft - m_drivesubsystem->GetLeftEnc()) < 1000);
  std::cout<<"is finished"<<std::endl;
}
