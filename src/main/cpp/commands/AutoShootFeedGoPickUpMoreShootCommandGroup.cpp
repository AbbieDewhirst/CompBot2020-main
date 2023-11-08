/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShootFeedGoPickUpMoreShootCommandGroup.h"
#include "commands/TurretCommand.h"
#include "commands/ShootBallCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/TurnInPlaceCommand.h"
#include "commands/DriveStraightUsingGyroCommand.h"
#include "commands/DriveForwardAndIntakeRaceCommand.h"
#include "commands/IntakeSolInCommand.h"
#include "commands/WaitTimeCommand.h"
#include "commands/AutoIntakeCommand.h"
#include "commands/LimelightOn.h"
#include "commands/ZeroHoodCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoShootFeedGoPickUpMoreShootCommandGroup::AutoShootFeedGoPickUpMoreShootCommandGroup(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem) {

     AddCommands(LimelightOn(turretSubsystem, true),
    TurnTurretSpecificAngleCommand(turretSubsystem, -3500),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 6, 14000, true),
    // DriveStraightUsingGyroCommand(drivesubsystem, -36, 1.0, false),
    // WaitTimeCommand(0.5),
    TurnInPlaceCommand(drivesubsystem, -90.0),
    IntakeSolInCommand(conveyorsubsystem),
    DriveForwardAndIntakeRaceCommand(drivesubsystem, conveyorsubsystem, 160),
    // AutoIntakeCommand(conveyorsubsystem).WithTimeout(1.0_s),
    //Added reverse, 180 turn and shoot balls
    WaitTimeCommand(0.5),
    DriveStraightUsingGyroCommand(drivesubsystem, -36, 1.0, false),
    WaitTimeCommand(0.5),
    TurnInPlaceCommand(drivesubsystem, 120.0),
    TurnTurretSpecificAngleCommand(turretSubsystem, -1800),
    // TurnInPlaceCommand(drivesubsystem, 90.0),
    LimelightOn(turretSubsystem, true),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000, true )
    
    );
  //This command group shoots the balls in our robot, (possible picks up more from other team),
  //And shoots those too, the goes and picks up the balls in the trench, and shoots them
}
