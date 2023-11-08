/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/TurretSubsystem.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurretVisionV2
    : public frc2::CommandHelper<frc2::CommandBase, TurretVisionV2> {
 public:
  TurretVisionV2(TurretSubsystem* turretsubsystem);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;

  private:
  TurretSubsystem* m_turretsubsystem;
  double targetAngle;
  double l_startingAngle;
  double targetAngleToTravel;
  double l_error;
  double fx;
  double x;
  double l_turnSpeed = 1.0;
  int l_direction = 1.0;
};
