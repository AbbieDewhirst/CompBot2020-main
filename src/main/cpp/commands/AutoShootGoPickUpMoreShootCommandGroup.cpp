/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
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
AutoShootGoPickUpMoreShootCommandGroup::AutoShootGoPickUpMoreShootCommandGroup(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem) {

    AddCommands(LimelightOn(turretSubsystem, true),
    TurnTurretSpecificAngleCommand(turretSubsystem, -3500),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000, true),
    TurnInPlaceV2(drivesubsystem, -90.0, 1.0, 90.0),
    IntakeSolInCommand(conveyorsubsystem),
    DriveStraightUsingGyroCommandV2(drivesubsystem, 180, 1.0, true, 24.0),
    IntakeSolOutCommand(conveyorsubsystem),
    //DriveForwardAndIntakeRaceCommand(drivesubsystem, conveyorsubsystem, 170),
    //IntakeInCommand(conveyorsubsystem).WithTimeout(0.5_s),
    //AutoIntakeCommand(conveyorsubsystem).WithTimeout(0.5_s),
    TurnInPlaceV2(drivesubsystem, -15.0, 1.0, 90.0),
    //Added reverse, 180 turn and shoot balls
    //WaitTimeCommand(0.5),
    DriveStraightUsingGyroCommandV2(drivesubsystem, -95, 1.0, false, 24.0),
    //WaitTimeCommand(0.5),
    TurnInPlaceV2(drivesubsystem, 135.0, 1.0, 90.0),
    // TurnTurretSpecificAngleCommand(turretSubsystem, -1800),
    // TurnInPlaceCommand(drivesubsystem, 90.0),
    LimelightOn(turretSubsystem, true),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000, true )
    
    );
  //This command group shoots the balls in our robot, (possible picks up more from other team),
  //And shoots those too, the goes and picks up the balls in the trench, and shoots them
}
