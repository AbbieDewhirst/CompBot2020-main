/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoGoPickupMoreIndexing.h"
#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
#include "commands/IntakeInCommand.h"
#include "commands/AutoTrench8BallCommandGroup.h"
#include "commands/AutoSteal2Shoot5BallCommandGroup.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
AutoGoPickupMoreIndexing::AutoGoPickupMoreIndexing(
    TurretSubsystem* turretSubsystem, 
    ShooterSubsystemPID* shootersubsystemPID, 
    ConveyorSubsystem* conveyorsubsystem, 
    OrganizerSubsystem* organizersubsystem, 
    HoodSubsystem* hoodsubsystem,
    DriveSubsystem* drivesubsystem) {

  AddCommands(IntakeInCommand(conveyorsubsystem), AutoShootGoPickUpMoreShootCommandGroup(turretSubsystem, shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem, drivesubsystem ));
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
}
