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
class DriveCommand
    : public frc2::CommandHelper<frc2::CommandBase, DriveCommand> {
 public:
  DriveCommand(DriveSubsystem* drivesubsystem, std::function<double()> YY,
             std::function<double()> XX);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private:
  std::function<double()> m_yy;
  std::function<double()> m_xx;
  DriveSubsystem* m_drivesubsystem;
  double YY;
  double XX;
};
