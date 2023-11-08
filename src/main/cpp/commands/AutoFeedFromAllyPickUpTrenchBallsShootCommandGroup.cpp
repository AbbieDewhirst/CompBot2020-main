/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoFeedFromAllyPickUpTrenchBallsShootCommandGroup.h"
#include "commands/TurretCommand.h"
#include "commands/ShootBallCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/TurnInPlaceCommand.h"
#include "commands/DriveStraightUsingGyroCommand.h"
#include "commands/DriveForwardAndIntakeRaceCommand.h"
#include "commands/IntakeSolInCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoFeedFromAllyPickUpTrenchBallsShootCommandGroup::AutoFeedFromAllyPickUpTrenchBallsShootCommandGroup(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem){

    AddCommands(TurnTurretSpecificAngleCommand(turretSubsystem, -3000),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 6, 14000, true).WithTimeout(5.0_s), // Eventually count balls from ally and have dynamic number of balls so we can remove Timeout.
    TurnInPlaceCommand(drivesubsystem, -90.0),
    IntakeSolInCommand(conveyorsubsystem),
    DriveForwardAndIntakeRaceCommand(drivesubsystem, conveyorsubsystem, 180),

    //Added reverse, 180 turn and shoot balls
    DriveStraightUsingGyroCommand(drivesubsystem, -60, 1.0, false),
    TurnInPlaceCommand(drivesubsystem, 180.0),
    ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 5, 14000, true).WithTimeout(5.0_s)
    
    );  
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());


}



//This command group shoots starting balls, picks up balls fed from ally, and then turns towards trench run to pick up 5 more balls and shoot.
//11 ball autonomous


