/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class ClimberSubsystem : public frc2::SubsystemBase {
 public:
  ClimberSubsystem();
  void ClimberMove(double speed);
  void ClimberStop();
  void ArmMove(double speed);
  void ClimberArmStop();
  double GetArmEncoder();
  void GoToArmPos(double position);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX climberMotor {13};
  WPI_TalonFX climberArmMotor {10};//Arm Deployment
};
