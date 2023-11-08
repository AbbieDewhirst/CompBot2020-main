/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LookforCountedColourCommand.h"
#include "Robot.h"  //mdd addded this.
#include "Constants.h"
#include <iostream>
#include <frc/smartdashboard/smartdashboard.h>
#include <frc/DriverStation.h>

int countedcolourcountdown;
bool alreadysawcolour;
std::string gameData;
frc::Color gameDataColor;


LookforCountedColourCommand::LookforCountedColourCommand(frc::Color lookforcolour, int countedcolour, ColourWheelSubsystem* colourwheelsubsystem) 
 : m_colourwheelsubsystem(colourwheelsubsystem) {

//l_lookforcolour = lookforcolour;
//l_lookforcolour = gameDataColor;
l_countedcolour = countedcolour;



 }


// Called when the command is initially scheduled.
void LookforCountedColourCommand::Initialize() {

countedcolourcountdown = l_countedcolour;
alreadysawcolour = false;
  frc::SmartDashboard::PutString("Status", "Looking for Counted Colour");
  frc::SmartDashboard::PutNumber("Counted Colour Countdown", countedcolourcountdown);

 //std::cout << "Looking for Counted colour :" << countedcolourcountdown << std::endl;

gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
if(gameData.length() > 0)
{
  switch (gameData[0])
  {
    case 'B' :
      //Blue case code
  gameDataColor = ColourWheelConstants::kBlueTarget;
  l_lookforcolour = gameDataColor;
  frc::SmartDashboard::PutString("gamedata", "B");
      break;
    case 'G' :
      //Green case code
      gameDataColor = ColourWheelConstants::kGreenTarget;
      l_lookforcolour = gameDataColor;
        frc::SmartDashboard::PutString("gamedata", "G");
      break;
    case 'R' :
      //Red case code
      gameDataColor = ColourWheelConstants::kRedTarget;
      l_lookforcolour = gameDataColor;
        frc::SmartDashboard::PutString("gamedata", "R");
      break;
    case 'Y' :
      //Yellow case code
      gameDataColor = ColourWheelConstants::kYellowTarget;
      l_lookforcolour = gameDataColor;
        frc::SmartDashboard::PutString("gamedata", "Y");
      break;
    default :
      //This is corrupt data
      break;
  }
} else {
  //Code for no data received yet
}

}

// Called repeatedly when this Command is scheduled to run
void LookforCountedColourCommand::Execute() {

  m_colourwheelsubsystem->ColourWheelFRD();

if (!alreadysawcolour && m_colourwheelsubsystem->LookforNextColour(l_lookforcolour)) 
{ 
    frc::SmartDashboard::PutString("Status", "SAW Counted Colour");
  countedcolourcountdown--;
alreadysawcolour = true;
}
else if (alreadysawcolour && m_colourwheelsubsystem->LookforNextColour(l_lookforcolour))
{/* don't care to see this same pie shape again} */
frc::SmartDashboard::PutString("Status", "Looking This is the same PIE Slice:");
//std::cout << "Looking This is the same PIE Slice:" << countedcolourcountdown << std::endl;
}
else if (alreadysawcolour && !m_colourwheelsubsystem->LookforNextColour(l_lookforcolour))
{ alreadysawcolour = false;}
  frc::SmartDashboard::PutString("Status", "Looking for Counted Colour");
 //std::cout << "Looking for Counted colour :" << countedcolourcountdown << std::endl;

}

// Called once the command ends or is interrupted.
void LookforCountedColourCommand::End(bool interrupted) {
    frc::SmartDashboard::PutString("Status", "FOUND Counted Colour");
    m_colourwheelsubsystem->ColourWheelSTOP();
 // std::cout << "FOUND Counted colour" << std::endl;
}

// Returns true when the command should end.
bool LookforCountedColourCommand::IsFinished() { 

  if (countedcolourcountdown == 0) return true;
  else return false;
  
  }
