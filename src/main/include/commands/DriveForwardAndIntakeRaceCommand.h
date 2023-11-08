/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelRaceGroup.h>
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ConveyorSubsystem.h"

class DriveForwardAndIntakeRaceCommand
    : public frc2::CommandHelper<frc2::ParallelRaceGroup,
                                 DriveForwardAndIntakeRaceCommand> {
 public:
  DriveForwardAndIntakeRaceCommand(DriveSubsystem* drivesubsystem, ConveyorSubsystem* conveyorsubsystem, double distance);

  private: double l_distance;
};
