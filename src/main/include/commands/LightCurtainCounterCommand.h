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
#include "subsystems/TurretSubsystem.h"
#include "subsystems/HoodSubsystem.h"
#include "frc/Timer.h"

/**
 * An example command.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class LightCurtainCounterCommand
    : public frc2::CommandHelper<frc2::CommandBase, LightCurtainCounterCommand> {
 public:
  LightCurtainCounterCommand(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, TurretSubsystem* turretsubsystem, HoodSubsystem* hoodsubsystem, int lookforball);

  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  ShooterSubsystemPID* m_shootersubsystemPID;
  ConveyorSubsystem* m_conveyorsubsystem;
  OrganizerSubsystem* m_organizersubsystem;
  TurretSubsystem* m_turretsubsystem;
  HoodSubsystem* m_hoodsubsystem;

  private: 
  int l_lookforball;
  double l_conveyorSpeed;
  double l_conveyorOGSpeed;
  double l_organizerSpeed;
  double l_organizerOGSpeed;
  double l_intakeSpeed;
  double l_intakeOGSpeed;
  bool l_conveyorInverted;
  bool l_organizerInverted;
  bool l_intakeInverted;
  frc::Timer conveyortime;
  frc::Timer organizertime;
  frc::Timer intaketime;
  
// int countedballcountdown;
// bool alreadysawball;

};
