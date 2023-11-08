/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/ShooterSubsystemPID.h"
#include "subsystems/HoodSubsystem.h"
#include "subsystems/TurretSubsystem.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class GetToVelocityCommand
    : public frc2::CommandHelper<frc2::CommandBase, GetToVelocityCommand> {
 public:
  GetToVelocityCommand(ShooterSubsystemPID* shootersubsystemPID, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, double velocity, bool usingVision);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  double l_velocity;
  bool l_usingvision;
  ShooterSubsystemPID* m_shootersubsystem;
  HoodSubsystem* m_hoodsubsystem;
  TurretSubsystem* m_turretsubsystem;
};
