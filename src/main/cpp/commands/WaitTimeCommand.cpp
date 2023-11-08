/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/WaitTimeCommand.h"
#include "frc/Timer.h"

WaitTimeCommand::WaitTimeCommand(double time) {
  l_time = time;
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void WaitTimeCommand::Initialize() {
  l_timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void WaitTimeCommand::Execute() {

  std::cout<<".";
}

// Called once the command ends or is interrupted.
void WaitTimeCommand::End(bool interrupted) {
  l_timer.Stop();
  l_timer.Reset();
}

// Returns true when the command should end.
bool WaitTimeCommand::IsFinished() { 
  if(l_timer.Get() >= l_time) return true;
  else return false; 
}
