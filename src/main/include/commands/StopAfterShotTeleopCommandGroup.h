/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/ParallelCommandGroup.h>
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/HoodSubsystem.h"
#include "subsystems/TurretSubsystem.h"
#include "subsystems/ShooterSubsystemPID.h"
class StopAfterShotTeleopCommandGroup
    : public frc2::CommandHelper<frc2::ParallelCommandGroup,
                                 StopAfterShotTeleopCommandGroup> {
 public:
  StopAfterShotTeleopCommandGroup(ConveyorSubsystem* conveyorsubsystem, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, ShooterSubsystemPID* shootersubsystem);
};
