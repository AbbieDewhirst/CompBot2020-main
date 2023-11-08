// /*----------------------------------------------------------------------------*/
// /* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
// /* Open Source Software - may be modified and shared by FRC teams. The code   */
// /* must be accompanied by the FIRST BSD license file in the root directory of */
// /* the project.                                                               */
// /*----------------------------------------------------------------------------*/

// #include "commands/AutoShootBallsAndLeaveLineCommandGroup.h"
// #include "commands/TurretCommand.h"
// #include "subsystems/TurretSubsystem.h"
// #include "commands/ShootBallCommandGroup.h"
// #include "commands/DriveStraightUsingGyroCommand.h"

// // NOTE:  Consider using this command inline, rather than writing a subclass.
// // For more information, see:
// // https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
// AutoShootBallsAndLeaveLineCommandGroup::AutoShootBallsAndLeaveLineCommandGroup(
//     TurretSubsystem* turretSubsystem, 
//     ShooterSubsystemPID* shootersubsystemPID, 
//     ConveyorSubsystem* conveyorsubsystem, 
//     OrganizerSubsystem* organizersubsystem, 
//     HoodSubsystem* hoodsubsystem,
//     DriveSubsystem* drivesubsystem) {
//   //This command group shoots the balls in our robot, and drives off the line
//   AddCommands(
//   // TurretCommand(turretSubsystem),
//   ShootBallCommandGroup(shootersubsystemPID, conveyorsubsystem, organizersubsystem, hoodsubsystem,turretSubsystem, 3, 14000),
//  /* DriveStraightUsingGyroCommand(driveSubsystem, double distanceToDrive, double speed)*/));
// }
