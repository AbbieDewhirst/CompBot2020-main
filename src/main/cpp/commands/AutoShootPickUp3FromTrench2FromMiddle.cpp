/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShootPickUp3FromTrench2FromMiddle.h"
#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
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
AutoShootPickUp3FromTrench2FromMiddle::AutoShootPickUp3FromTrench2FromMiddle(
    
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());


    AddCommands(LimelightOn(turretSubsystem, true),
    TurnTurretSpecificAngleCommand(turretSubsystem, -3500),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000, true),
    TurnInPlaceCommand(drivesubsystem, -90.0),
    IntakeSolInCommand(conveyorsubsystem),
    DriveForwardAndIntakeRaceCommand(drivesubsystem, conveyorsubsystem, 180),
    AutoIntakeCommand(conveyorsubsystem).WithTimeout(1.0_s),
    //Added reverse, 180 turn and shoot balls
    DriveStraightUsingGyroCommand(drivesubsystem, -72, 1.0, false),
    WaitTimeCommand(0.5),
    TurnInPlaceCommand(drivesubsystem, 90.0),
    WaitTimeCommand(0.5),
    DriveStraightUsingGyroCommand(drivesubsystem, 40, 1.0, true),
    
    TurnTurretSpecificAngleCommand(turretSubsystem, -3600),
    // TurnInPlaceCommand(drivesubsystem, 90.0),
    LimelightOn(turretSubsystem, true),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 5, 14000, true )
    
      );}