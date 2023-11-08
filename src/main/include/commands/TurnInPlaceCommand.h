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
class TurnInPlaceCommand
    : public frc2::CommandHelper<frc2::CommandBase, TurnInPlaceCommand> {
 public:
  TurnInPlaceCommand(DriveSubsystem* drivesubsystem, double distanceToTurn);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  DriveSubsystem* m_drivesubsystem;
  double l_degreesToTurn = 0.0;
  double l_targetAngle = 0.0;
  double l_positionError = 0.0;
  double l_kP;
  double l_currentDistance = 0.0;
  double l_targetDistance = 0.0;
  double l_rotationSpeed = 0.0;
  double l_minSpeed = 0.0;
  double l_maxSpeed = 0.0;
  double l_minAngle= 0.0;
  double l_maxAngle  = 0.0;
  double l_outputSpeedwithoutFloor = 0.0;

};
