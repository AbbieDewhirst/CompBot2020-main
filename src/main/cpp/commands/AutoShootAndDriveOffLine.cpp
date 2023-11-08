/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShootAndDriveOffLine.h"
#include "commands/ShootBallCommandGroup.h"
#include "commands/DriveStraightUsingGyroCommand.h"
#include "commands/LimelightOn.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/TurnInPlaceCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoShootAndDriveOffLine::AutoShootAndDriveOffLine(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem
) {
    AddCommands(LimelightOn(turretSubsystem, true),
    // TurnTurretSpecificAngleCommand(turretSubsystem, -3500),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000, true),
    // TurnInPlaceCommand(drivesubsystem, 90.0),
    DriveStraightUsingGyroCommand(drivesubsystem, 60, 1.0, false)
  );
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
