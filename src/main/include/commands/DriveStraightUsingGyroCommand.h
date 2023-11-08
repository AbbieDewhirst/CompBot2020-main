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
class DriveStraightUsingGyroCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveStraightUsingGyroCommand> {
 public:
  DriveStraightUsingGyroCommand(DriveSubsystem* driveSubsystem, double distanceToDrive, double speed, bool override);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
private:
  DriveSubsystem* m_drivesubsystem;
  bool l_override;
  double l_heading = 1.0;
  double l_leftEncoder;
  double l_rightEncoder;
  double l_distanceToDrive;
  double targetPosLeft;
  double targetPosRight;
  double l_speed;
  double l_distanceLeftToTravel;
  double targetDistanceToTravel;
  double l_currentspeed;
  double l_direction;
};
