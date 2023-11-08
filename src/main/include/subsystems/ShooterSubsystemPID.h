/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/PIDSubsystem.h>
#include "subsystems/ShooterSubsystemPID.h"
#include "ctre/Phoenix.h"
#include "rev/CANSparkMax.h"
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>

class ShooterSubsystemPID : public frc2::PIDSubsystem {
 public:
  ShooterSubsystemPID();
  void FlywheelMove(double velocity);
  void FlywheelSTOP();
  double GetVelocity();
  void HoodAdjustmentSpeed(double speed);
  void HoodAdjustmentStop();
  void shooterFeederSpeed(double speed);
  void shooterFeederStop();
  double GetVelocityDerivative();
  bool LookForNextBall();
  void ShooterSpeedCalc();
  void FlywheelZoom();
  double ShooterCalculatedVelocity();
  void Periodic();


 protected:
  void UseOutput(double output, double setpoint) override;

  double GetMeasurement() override;

  private:
  //The shooter subsystem has 2 falcons on flywheel ,
  // 1 talon srx for hood and 1 talon srx for feeder roller 
  //WPI_TalonFX feederShooterMotor {4};
  //WPI_TalonSRX hoodShooterMotor {5};
  WPI_TalonFX flywheelShooterMotorR {14}; //0
  WPI_TalonFX flywheelShooterMotorL {15}; //1
  WPI_TalonSRX shooterFeederWheelMotor{18};///used to be 8
  WPI_TalonSRX hoodMotor {9};
  frc::AnalogInput lightCurtain {0};
  frc::AnalogInput lightCurtain1 {1};
};

