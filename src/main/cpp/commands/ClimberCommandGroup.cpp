/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ClimberCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/ClimberArmEncoderCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ClimberCommandGroup::ClimberCommandGroup(TurretSubsystem* turretsubsystem, ClimberSubsystem* climbersubsystem) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(TurnTurretSpecificAngleCommand(turretsubsystem,3800),
        ClimberArmEncoderCommand(climbersubsystem, -96000));
}
