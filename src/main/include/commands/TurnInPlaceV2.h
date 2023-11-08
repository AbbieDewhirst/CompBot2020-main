/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/DriveSubsystem.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurnInPlaceV2
    : public frc2::CommandHelper<frc2::CommandBase, TurnInPlaceV2> {
 public:
  TurnInPlaceV2(DriveSubsystem* drivesubsystem, double distanceToTurn, double maxSpeed, double slowDownAngle);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  DriveSubsystem* m_drivesubsystem;

  double l_degreesToTurn;
  double l_startingAngle;
  double targetAngle;
  double targetAngleToTravel;
  double l_angleRemainingToTravel;
  double l_turnSpeed;
  double l_direction;
  double l_maxSpeed;
  double l_slowDownAngle;
  double fx;
  double x;
};
