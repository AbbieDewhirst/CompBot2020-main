/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveForwardAndIntakeRaceCommand.h"
#include "commands/DriveStraightUsingGyroCommandV2.h"
#include "commands/IntakeInCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
DriveForwardAndIntakeRaceCommand::DriveForwardAndIntakeRaceCommand(DriveSubsystem* drivesubsystem, ConveyorSubsystem* conveyorsubsystem, double distance) {

  l_distance = distance;
  // Add your commands here, e.g.
  AddCommands(DriveStraightUsingGyroCommandV2(drivesubsystem, distance, 0.75, true, 24.0), IntakeInCommand(conveyorsubsystem));
  // AddCommands(FooCommand(), BarCommand());
}
