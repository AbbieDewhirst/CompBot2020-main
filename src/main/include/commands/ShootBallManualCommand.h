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
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/OrganizerSubsystem.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class ShootBallManualCommand
    : public frc2::CommandHelper<frc2::CommandBase, ShootBallManualCommand> {
 public:
  ShootBallManualCommand(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, int velocity);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  ShooterSubsystemPID* m_shootersubsystemPID;
  ConveyorSubsystem* m_conveyorsubsystem;
  OrganizerSubsystem* m_organizersubsystem;
  private:
  int l_velocity;
};
