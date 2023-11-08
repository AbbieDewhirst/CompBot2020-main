/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/CommandHelper.h>
#include <frc2/command/SequentialCommandGroup.h>
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "subsystems/OrganizerSubsystem.h"
#include "subsystems/HoodSubsystem.h"
#include "subsystems/TurretSubsystem.h"

class ShootBallCommandGroup
    : public frc2::CommandHelper<frc2::SequentialCommandGroup,
                                 ShootBallCommandGroup> {
public:
  ShootBallCommandGroup(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, int numberOfBalls, int velocity, bool usingVision);
private:
  int l_numberofballs;
  int l_velocity;
  bool l_usingvision;
};
