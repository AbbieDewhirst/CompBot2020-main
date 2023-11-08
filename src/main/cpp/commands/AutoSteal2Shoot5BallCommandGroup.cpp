/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoSteal2Shoot5BallCommandGroup.h"
#include "commands/TurretCommand.h"
#include "commands/ShootBallCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/TurnInPlaceV2.h"
#include "commands/DriveStraightUsingGyroCommandV2.h"
#include "commands/DriveForwardAndIntakeRaceCommand.h"
#include "commands/IntakeSolInCommand.h"
#include "commands/WaitTimeCommand.h"
#include "commands/AutoIntakeCommand.h"
#include "commands/LimelightOn.h"
#include "commands/ZeroHoodCommand.h"
#include "commands/IntakeInCommand.h"
#include "commands/IntakeSolOutCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoSteal2Shoot5BallCommandGroup::AutoSteal2Shoot5BallCommandGroup(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(IntakeSolInCommand(conveyorsubsystem),
    DriveStraightUsingGyroCommandV2(drivesubsystem, 88, 1.0, false, 24.0),
    DriveStraightUsingGyroCommandV2(drivesubsystem, -24, 1.0, false, 24.0),
    TurnInPlaceV2(drivesubsystem, -90.0, 1.0, 90.0),
    DriveStraightUsingGyroCommandV2(drivesubsystem, 220, 1.0, true, 24.0),
    TurnInPlaceV2(drivesubsystem, -20.0, 1.0, 90.0),
    TurnTurretSpecificAngleCommand(turretSubsystem, 3200),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 5, 14000, true),
    TurnInPlaceV2(drivesubsystem, 20.0, 1.0, 90.0),
    DriveStraightUsingGyroCommandV2(drivesubsystem, -72, 1.0, false, 24.0),
    TurnInPlaceV2(drivesubsystem, 90.0, 1.0, 90.0));

}
