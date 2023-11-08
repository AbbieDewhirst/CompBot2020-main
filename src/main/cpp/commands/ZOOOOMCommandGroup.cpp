/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ZOOOOMCommandGroup.h"
#include "commands/ZoomTest1Command.h"
#include "subsystems/DriveSubsystemPID.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ZOOOOMCommandGroup::ZOOOOMCommandGroup(DriveSubsystemPID* drivesubsystemPID) {
  AddCommands(
ZoomTest1Command(drivesubsystemPID, 200), ZoomTest1Command(drivesubsystemPID, 199)
  );
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
