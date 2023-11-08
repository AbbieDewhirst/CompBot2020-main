/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveToUltrasonicCommand.h"
#include "subsystems/DriveSubsystem.h"

DriveToUltrasonicCommand::DriveToUltrasonicCommand(DriveSubsystem* drivesubsystem, double ultradistance) : m_drivesubsystem(drivesubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  l_ultradistance = ultradistance;
}

// Called when the command is initially scheduled.
void DriveToUltrasonicCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveToUltrasonicCommand::Execute() {

  l_distanceLeftToTravel = m_drivesubsystem->GetUltraSonic() - l_ultradistance;
  l_speed = -l_distanceLeftToTravel / l_ultradistance;

		if (l_speed > 1) {
			l_speed = 0.8;
		} else if (l_speed < -1) {
			l_speed = -0.8;
		} else if ((l_speed < 0.75) && l_speed > 0) {
			l_speed = 0.30;
		} else if ((l_speed > -0.75) && l_speed < 0) {
			l_speed = -0.30;
		}
    m_drivesubsystem->Drive(l_speed, 0);
}

// Called once the command ends or is interrupted.
void DriveToUltrasonicCommand::End(bool interrupted) {
  m_drivesubsystem->DriveStop();
}

// Returns true when the command should end.
bool DriveToUltrasonicCommand::IsFinished() {
  if((m_drivesubsystem->GetUltraSonic() - l_ultradistance) <= 5) {
    return true;
  }else{
    return false;
  }
}
