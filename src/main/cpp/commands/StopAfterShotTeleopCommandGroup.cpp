/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/StopAfterShotTeleopCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/LimelightOn.h"
#include "commands/IntakeSolOutCommand.h"
#include "commands/ShootertoZero.h"
#include "commands/WaitTimeCommand.h"



// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
StopAfterShotTeleopCommandGroup::StopAfterShotTeleopCommandGroup(ConveyorSubsystem* conveyorsubsystem, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, ShooterSubsystemPID* shootersubsystem) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());

  AddCommands(//TurnTurretSpecificAngleCommand(turretsubsystem, 0),
     //LimelightOn(turretsubsystem, false),
    //  IntakeSolOutCommand(conveyorsubsystem),WaitTimeCommand(0),
     ShootertoZero(hoodsubsystem, shootersubsystem));


}
