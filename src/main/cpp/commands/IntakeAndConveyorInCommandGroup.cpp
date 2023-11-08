/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeAndConveyorInCommandGroup.h"
#include "frc2/command/SequentialCommandGroup.h"
#include "frc2/command/ParallelCommandGroup.h"
#include "commands/BallBlockerOutCommand.h"
#include "commands/ConveyorMoveCommand.h"
#include "commands/IntakeInCommand.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
IntakeAndConveyorInCommandGroup::IntakeAndConveyorInCommandGroup(ConveyorSubsystem* conveyorSubsystem) {
  // Add your commands here, e.g.
  // AddCommands(FooCommand(), BarCommand());
  AddCommands(BallBlockerOutCommand(conveyorSubsystem), 
  frc2::ParallelCommandGroup{ConveyorMoveCommand(conveyorSubsystem, 0.75), 
  IntakeInCommand(conveyorSubsystem)});
  // frc2::SequentialCommandGroup{BallBlockerOutCommand(conveyorSubsystem), 
  // frc2::ParallelCommandGroup{ConveyorMoveCommand(conveyorSubsystem, 0.75), IntakeInCommand(conveyorSubsystem)}};

}
