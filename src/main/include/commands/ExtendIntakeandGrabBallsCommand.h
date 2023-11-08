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
class ExtendIntakeandGrabBallsCommand
    : public frc2::CommandHelper<frc2::CommandBase, ExtendIntakeandGrabBallsCommand> {
 public:
  ExtendIntakeandGrabBallsCommand(ConveyorSubsystem* conveyorsubsystem);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  ConveyorSubsystem* m_conveyorsubsystem;
  frc::Timer intaketime;
  double l_intakeSpeed;
  double l_intakeOGSpeed;
  bool l_intakeInverted;
  bool l_inIndex1 = false;
  int l_count = 0;
};
