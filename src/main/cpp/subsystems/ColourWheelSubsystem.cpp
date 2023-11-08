/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ColourWheelSubsystem.h"

#include "Constants.h"
#include "Robot.h"
#include <iostream>

#include <frc/smartdashboard/smartdashboard.h>

std::string colorString;
frc::Color colourDetected;



ColourWheelSubsystem::ColourWheelSubsystem() {

    /**
   * Note: Any example colors should be calibrated as the user needs, these
   * are here as a basic example.
   */
 
    m_colorMatcher.AddColorMatch(ColourWheelConstants::kBlueTarget);
    m_colorMatcher.AddColorMatch(ColourWheelConstants::kGreenTarget);
    m_colorMatcher.AddColorMatch(ColourWheelConstants::kRedTarget);
    m_colorMatcher.AddColorMatch(ColourWheelConstants::kYellowTarget);

    colourwheelmotor.SetNeutralMode(NeutralMode::Brake);
    colourwheelmotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
    colourwheelmotor.SetSelectedSensorPosition(0);

}


     

// This method will be called once per scheduler run
void ColourWheelSubsystem::Periodic() {
//std::cout << "Magencoder POS " <<   colourwheelmotor.GetSelectedSensorPosition() << std::endl;




}

bool ColourWheelSubsystem::LookforNextColour(frc::Color lookforColour) {

frc::Color detectedColor = m_colorSensor.GetColor();
std::string LookingForColourString;


    /**
     * Run the color match algorithm on our detected color
     */
    
    double confidence = 0.0;
    frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    colourDetected = matchedColor;
    if (matchedColor == ColourWheelConstants::kBlueTarget) {
      colorString = "Blue";
    } else if (matchedColor == ColourWheelConstants::kRedTarget) {
      colorString = "Red";
    } else if (matchedColor == ColourWheelConstants::kGreenTarget) {
      colorString = "Green";
    } else if (matchedColor == ColourWheelConstants::kYellowTarget) {
      colorString = "Yellow";
    } else {
      colorString = "Unknown";
    }

    if (lookforColour == ColourWheelConstants::kBlueTarget) {
      LookingForColourString = "Blue";
    } else if (lookforColour == ColourWheelConstants::kRedTarget) {
      LookingForColourString = "Red";
    } else if (lookforColour== ColourWheelConstants::kGreenTarget) {
      LookingForColourString = "Green";
    } else if (lookforColour == ColourWheelConstants::kYellowTarget) {
      LookingForColourString = "Yellow";
    } else {
      LookingForColourString = "Unknown";
    }

    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
    frc::SmartDashboard::PutString("Looking For Color", LookingForColourString);


  if (lookforColour == colourDetected ) 
    return true;
  else return  false;
}


void ColourWheelSubsystem::ColourWheelFRD() {

 colourwheelmotor.Set(ControlMode::PercentOutput,0.1);

}

void ColourWheelSubsystem::ColourWheelREV() {
colourwheelmotor.Set(ControlMode::PercentOutput,-0.1);

}

void ColourWheelSubsystem::ColourWheelSTOP() {
colourwheelmotor.Set(ControlMode::PercentOutput,0.0);
}

// Game Data

// The Data
// Timing
// Color assignment data is sent to both alliances simultaneously once the first alliance 
//in a match has reached Capacity on Stage 3 of the Shield Generator (see the Game Manual 
//for more complete details). Between the beginning of the match and this point, the Game 
//Data will be an empty string.

// Data format
// The selected color for an alliance will be provided as a 
//single character representing the color (i.e. ‘R’ = red, ‘G’ = green, ‘B’ = blue, ‘Y’ = yellow). 
//This color indicates the color that must be placed underneath the Control Panel’s color sensor in order to complete the Position Control objective (see the Game Manual for information about the location of the Control Panel sensor).

// Accessing the Data
// The data is accessed using the Game Data methods or 
//VIs in each language. 
//Below are descriptions and examples of how to access the data from each of
// the three languages. As the data is provided to the Robot during the Teleop period, 
//teams will likely want to query the data in Teleop periodic code, or trigger 
//reading it off a button press or other action after they have reached Stage 3 capacity.

// #include <frc/DriverStation.h>

// std::string gameData;
// gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
// if(gameData.length() > 0)
// {
//   switch (gameData[0])
//   {
//     case 'B' :
//       //Blue case code
//       break;
//     case 'G' :
//       //Green case code
//       break;
//     case 'R' :
//       //Red case code
//       break;
//     case 'Y' :
//       //Yellow case code
//       break;
//     default :
//       //This is corrupt data
//       break;
//   }
// } else {
//   //Code for no data received yet
// }