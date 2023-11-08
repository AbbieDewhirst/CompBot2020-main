/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/TurnInPlaceCommand.h"
#include <frc/smartdashboard/smartdashboard.h>
#include <iostream>
#include <cmath>

TurnInPlaceCommand::TurnInPlaceCommand(DriveSubsystem* drivesubsystem, double distanceToTurn) : m_drivesubsystem(drivesubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(m_drivesubsystem);
  l_degreesToTurn = distanceToTurn;
}

// Called when the command is initially scheduled.
void TurnInPlaceCommand::Initialize() {
  // m_drivesubsystem->ZeroGyro();
  l_targetAngle = m_drivesubsystem->GetGyroAngle() - l_degreesToTurn;
  l_kP = 0.02;
  frc::SmartDashboard::PutNumber("Gyro Heading", l_targetAngle);
  frc::SmartDashboard::PutNumber("LCD", l_targetAngle);
  l_minSpeed = 0.35; // Used to be 0.35, going to try reduce tolerance
  l_maxSpeed = 0.75;
  l_minAngle = 0.1;
  l_maxAngle = 100;

}
// Called repeatedly when this Command is scheduled to run
void TurnInPlaceCommand::Execute(){//(0.7 - 0.35)/(100 - 0.1)* -90 + -90/-90 * 0.35
  l_positionError = m_drivesubsystem->GetGyroAngle() - l_targetAngle ;
  frc::SmartDashboard::PutNumber("Pos Err", l_positionError);
  //force rotation speed to max out at +1 or -1
  l_rotationSpeed = std::max(std::min(l_positionError * l_kP,1.0),-1.0);
  //force a minimum speed to overcome drive system friction
  l_outputSpeedwithoutFloor = l_rotationSpeed;
  if ( abs(l_rotationSpeed)< l_minSpeed) {
    frc::SmartDashboard::PutString("isMinSpeed", "yes");
    frc::SmartDashboard::PutNumber("OutputSpeedWithoutFloor", l_outputSpeedwithoutFloor);
    //l_rotationSpeed = l_minSpeed * abs(l_rotationSpeed)/l_rotationSpeed ;
    if (l_rotationSpeed < 0){
      l_rotationSpeed = -l_minSpeed;
    }
    else{
      l_rotationSpeed = l_minSpeed;
    }
  }
  

  frc::SmartDashboard::PutNumber("Rotation speed", l_rotationSpeed);
      m_drivesubsystem->Drive(0, l_rotationSpeed);


    


}

// Called once the command ends or is interrupted.
void TurnInPlaceCommand::End(bool interrupted) {
  m_drivesubsystem->DriveStop();
  frc::SmartDashboard::PutString("Abbie", "ENDDDDDDDDD");

}

// Returns true when the command should end.
bool TurnInPlaceCommand::IsFinished() { 
  //Added a second condition to check and make sure speed is slow enough before ending command. MIGHT JUST BE BETTER TO REDUCE KP, not really sure without testing
   if (std::abs(l_positionError)<2.0 /*&& abs(l_outputSpeedwithoutFloor) < 0.28*/) {
     return true;
   }
   else {
     return false;
   }
// return false;
  }




//below here is the original code before Mr Browne messed with it.

// TurnInPlaceCommand::TurnInPlaceCommand(double distanceToTurn) {
//   // Use addRequirements() here to declare subsystem dependencies.
//   AddRequirements(m_drivesubsystem);
//   l_distanceToTurn = distanceToTurn;
// }

// // Called when the command is initially scheduled.
// void TurnInPlaceCommand::Initialize() {
//   // m_drivesubsystem->ZeroGyro();
//     l_currentDistance = m_drivesubsystem->GetGyroAngle();
//    l_targetDistance = l_currentDistance +  l_distanceToTurn;
//    frc::SmartDashboard::PutNumber("LCD", l_currentDistance);
//    frc::SmartDashboard::PutNumber("LTD", l_distanceToTurn);
//    l_minSpeed = 0.35;
//    l_maxSpeed = 0.70;
//    l_minAngle = 0.1;
//    l_maxAngle = 100;
//      frc::SmartDashboard::PutString("Abbie", "INIT");

// }
// // Called repeatedly when this Command is scheduled to run
// void TurnInPlaceCommand::Execute(){//(0.7 - 0.35)/(100 - 0.1)* -90 + -90/-90 * 0.35
//   	 l_targetDistance = l_distanceToTurn + l_currentDistance - m_drivesubsystem->GetGyroAngle();
//   	// l_rotationSpeed = (l_maxSpeed - l_minSpeed) / (l_maxAngle - l_minAngle) * l_targetDistance + l_targetDistance / l_targetDistance * l_minSpeed;
//     l_rotationSpeed = -0.5;
//     // if(l_distanceToTurn > 0) {
//       // m_drivesubsystem->TankDriveTurn(-l_rotationSpeed, l_rotationSpeed);
//       // if(l_distanceToTurn < 0){
//       //   l_rotationSpeed = -l_rotationSpeed;
//       // }
//       m_drivesubsystem->Drive(0, l_rotationSpeed);
//            frc::SmartDashboard::PutString("Abbie", "Exxxxxxx");

//     // }else{
//     //   m_drivesubsystem->TankDriveTurn(l_rotationSpeed, -l_rotationSpeed);
//     // }
//     // frc::SmartDashboard::PutNumber("Gyro = ", m_drivesubsystem->GetGyroAngle());
//     // frc::SmartDashboard::PutNumber("Rotation Speed", l_rotationSpeed);
//     // frc::SmartDashboard::PutNumber("Target Distance", l_targetDistance);
    


// }

// // Called once the command ends or is interrupted.
// void TurnInPlaceCommand::End(bool interrupted) {
//   m_drivesubsystem->DriveStop();
//   frc::SmartDashboard::PutString("Abbie", "ENDDDDDDDDD");

// }

// // Returns true when the command should end.
// bool TurnInPlaceCommand::IsFinished() { 
// // if (abs((m_drivesubsystem->GetGyroAngle() - (l_currentDistance)) <= l_distanceToTurn + 0.3 && abs(m_drivesubsystem->GetGyroAngle()) - abs(l_currentDistance) >= l_distanceToTurn - 0.3 ) {
// // if (abs((m_drivesubsystem->GetGyroAngle() - (l_currentDistance)) <= l_distanceToTurn + 0.3 && abs(m_drivesubsystem->GetGyroAngle()) - abs(l_currentDistance) >= l_distanceToTurn - 0.3 ) {
// if((abs(m_drivesubsystem->GetGyroAngle()) - abs(l_distanceToTurn)) <= 3.0){
// 	return true;
// } else {
// 	return false;
// }
// // if(m_drivesubsystem->GetGyroAngle() >= 90) {
// //   return true;
// // }else{
// //   return false; 
// // }

// // return false;
//   }
