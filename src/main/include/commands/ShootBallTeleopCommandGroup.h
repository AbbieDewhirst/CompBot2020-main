/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/TurretSubsystem.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/OrganizerSubsystem.h"
#include "subsystems./HoodSubsystem.h"

class ShootBallTeleopCommandGroup
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 ShootBallTeleopCommandGroup> {
  public:
    ShootBallTeleopCommandGroup(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, int velocity, bool usingVision);
  private: 
    int l_velocity;
    bool l_usingvision;
};
