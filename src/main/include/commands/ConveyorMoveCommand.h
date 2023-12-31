/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ConveyorSubsystem.h"
#include "frc/Timer.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ConveyorMoveCommand
    : public frc2::CommandHelper<frc2::CommandBase, ConveyorMoveCommand> {
 public:
  ConveyorMoveCommand(ConveyorSubsystem* conveyorsubsystem, double speed);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  ConveyorSubsystem* m_conveyorsubsystem;
  private:
  double l_speed;
  double conveyorOriginalSpeed;
  bool conveyorIsNotInverted;
  frc::Timer time;
};
