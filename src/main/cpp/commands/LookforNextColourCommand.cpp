/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LookforNextColourCommand.h"
#include "Robot.h"  //mdd addded this.
#include <frc/DriverStation.h>

#include <iostream>



LookforNextColourCommand::LookforNextColourCommand(frc::Color lookforcolour, ColourWheelSubsystem* colourwheelsubsystem) 
 : m_colourwheelsubsystem(colourwheelsubsystem) {

  l_lookforcolour = lookforcolour;
 //l_lookforcolour = gameDataColor;

 }


// Called when the command is initially scheduled.
void LookforNextColourCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void LookforNextColourCommand::Execute() {

m_colourwheelsubsystem->LookforNextColour(l_lookforcolour);
 std::cout << "Looking for Next colour" << std::endl;

}

// Called once the command ends or is interrupted.
void LookforNextColourCommand::End(bool interrupted) {
  std::cout << "FOUND Next colour" << std::endl;
}

// Returns true when the command should end.
bool LookforNextColourCommand::IsFinished() { 
  return (m_colourwheelsubsystem->LookforNextColour(l_lookforcolour));
  
  }
