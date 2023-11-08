/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ColourWheelFRDCommand.h"
#include "Robot.h"  //mdd addded this.

 ColourWheelFRDCommand::ColourWheelFRDCommand(ColourWheelSubsystem* colourwheelsubsystem) 
 : m_colourwheelsubsystem(colourwheelsubsystem) {

  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ColourWheelFRDCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void ColourWheelFRDCommand::Execute() {

  m_colourwheelsubsystem->ColourWheelFRD();
}

// Called once the command ends or is interrupted.
void ColourWheelFRDCommand::End(bool interrupted) {
  m_colourwheelsubsystem->ColourWheelSTOP();
}

// Returns true when the command should end.
bool ColourWheelFRDCommand::IsFinished() { return false; }
