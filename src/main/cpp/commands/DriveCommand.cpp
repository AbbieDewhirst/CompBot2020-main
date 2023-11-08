/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCommand.h"
#include "Robot.h"
#include <iostream>

DriveCommand::DriveCommand(DriveSubsystem* driveSubsystem,
                     std::function<double()> YY,
                     std::function<double()> XX)
                     :m_yy(YY), m_xx(XX), m_drivesubsystem(driveSubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements({m_drivesubsystem});
}

// Called when the command is initially scheduled.
void DriveCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() {
  YY = m_yy();
  XX = m_xx();
  // if(abs(m_yy()) < 0.09) YY = 0; //must determine what this is still
  // if(abs(m_xx()) < 0.2) XX = 0;
  //m_drivesubsystem->Drive(YY, XX);
  m_drivesubsystem->DriveWithRamp(YY,XX);
    // std::cout << "Arc Drive " << YY << " " << XX << std::endl;
}

// Called once the command ends or is interrupted.
void DriveCommand::End(bool interrupted) {
  //m_drivesubsystem->Drive(0, 0);
  std::cout << "Drive Stop" << std::endl;
}

// Returns true when the command should end.
bool DriveCommand::IsFinished() { return false; }
