/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ShooterSubsystemPID.h"

#include <iostream>
#include <frc/smartdashboard/smartdashboard.h>
#include "Constants.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"



bool ballDetected;
bool currentBall;


ShooterSubsystemPID::ShooterSubsystemPID()
    : PIDSubsystem(

          // The PIDController used by the subsystem
          
          frc2::PIDController(0, 0, 0)) { 
            SetName("ShooterMotor");
            // AddChild("Left Shooter Motor", &flywheelShooterMotorL);           
            // AddChild("Right Shooter Motor", &flywheelShooterMotorR);
    flywheelShooterMotorL.SetInverted(false);
    flywheelShooterMotorR.SetInverted(true);

    flywheelShooterMotorL.SetSafetyEnabled(false);
    flywheelShooterMotorR.SetSafetyEnabled(false);

  flywheelShooterMotorL.SelectProfileSlot(0, 0);
	flywheelShooterMotorL.Config_kF(SHPIDConstants::kPIDLoopInd, 0.052, SHPIDConstants::kTimeoutMs);//0.048
	flywheelShooterMotorL.Config_kP(SHPIDConstants::kPIDLoopInd, 0.5, SHPIDConstants::kTimeoutMs);//0.25
	flywheelShooterMotorL.Config_kI(SHPIDConstants::kPIDLoopInd, 0.0, SHPIDConstants::kTimeoutMs);//0.0
  flywheelShooterMotorL.Config_kD(SHPIDConstants::kPIDLoopInd, 0.0, SHPIDConstants::kTimeoutMs);//0.075
  flywheelShooterMotorR.SelectProfileSlot(0, 0);
	flywheelShooterMotorR.Config_kF(SHPIDConstants::kPIDLoopInd, 0.052, SHPIDConstants::kTimeoutMs);
	flywheelShooterMotorR.Config_kP(SHPIDConstants::kPIDLoopInd, 0.5, SHPIDConstants::kTimeoutMs);
	flywheelShooterMotorR.Config_kI(SHPIDConstants::kPIDLoopInd, 0.0, SHPIDConstants::kTimeoutMs);
  flywheelShooterMotorR.Config_kD(SHPIDConstants::kPIDLoopInd, 0.0, SHPIDConstants::kTimeoutMs);
  /* Set acceleration and vcruise velocity - see documentation */
  /*
  flywheelShooterMotorL.ConfigMotionCruiseVelocity(SHPIDConstants::kCruiseVel, 10);//UNITS PER 100 MILLISECOND
  flywheelShooterMotorL.ConfigMotionAcceleration(SHPIDConstants::kCruiseAccl, 10);//units per 100 ms per sec
  flywheelShooterMotorR.ConfigMotionCruiseVelocity(SHPIDConstants::kCruiseVel, 10);
  flywheelShooterMotorR.ConfigMotionAcceleration(SHPIDConstants::kCruiseAccl, 10);
*/

    // flywheelShooterMotorR.Follow(flywheelShooterMotorL);
    
// these commands are CTRE based motor commands. We are using sparks.
      // flywheelShooterMotorL.SetInverted(false);
      // flywheelShooterMotorR.Follow(flywheelShooterMotorL);
      // flywheelShooterMotorR.SetInverted(InvertType::OpposeMaster);
  shooterFeederWheelMotor.SetInverted(true);
  

}

void ShooterSubsystemPID::UseOutput(double output, double setpoint) {
  // Use the output here
}

double ShooterSubsystemPID::GetMeasurement() {
  // Return the process variable measurement here
  return 0;
}
void ShooterSubsystemPID::FlywheelMove(double velocity) {
  // flywheelShooterMotorL.Set(ControlMode::PercentOutput, speed);
  // flywheelShooterMotorR.Set(ControlMode::PercentOutput, speed);
 flywheelShooterMotorL.Set(ControlMode::Velocity, velocity);
 flywheelShooterMotorR.Set(ControlMode::Velocity, velocity);
  frc::SmartDashboard::PutNumber("flywheel v", flywheelShooterMotorL.GetSelectedSensorVelocity() );
}

void ShooterSubsystemPID::FlywheelZoom(){
 flywheelShooterMotorL.Set(ControlMode::PercentOutput, 1.0);
 flywheelShooterMotorR.Set(ControlMode::PercentOutput, 1.0);
}
void ShooterSubsystemPID::FlywheelSTOP() {
  flywheelShooterMotorL.Set(ControlMode::PercentOutput, 0.0);
  flywheelShooterMotorR.Set(ControlMode::PercentOutput, 0.0);
}
double ShooterSubsystemPID::GetVelocity() {
  return flywheelShooterMotorL.GetSelectedSensorVelocity();
}

double ShooterSubsystemPID::GetVelocityDerivative(){
  return flywheelShooterMotorL.GetErrorDerivative();
}
 void ShooterSubsystemPID::HoodAdjustmentSpeed(double speed){
   hoodMotor.Set(ControlMode::PercentOutput, speed);
 }
void ShooterSubsystemPID::HoodAdjustmentStop(){
  hoodMotor.Set(ControlMode::PercentOutput, 0.0);

}
   void ShooterSubsystemPID::shooterFeederSpeed(double speed){
   shooterFeederWheelMotor.Set(ControlMode::PercentOutput, speed);
   }
  void ShooterSubsystemPID::shooterFeederStop(){
  shooterFeederWheelMotor.Set(ControlMode::PercentOutput, 0.0);
  }
bool ShooterSubsystemPID::LookForNextBall() {

  if (lightCurtain1.GetVoltage() > 3.0){
    return true;
  }
  else{
  return false;
  }
    //  return lightCurtain.Get();
    // return lightCurtain1.Get();

    // frc::SmartDashboard::GetBoolean("DIO0", lightCurtain.Get());
    // frc::SmartDashboard::GetBoolean("DIO1", lightCurtain1.Get());

    return frc::SmartDashboard::GetBoolean("fake light curtain", false);
}
void ShooterSubsystemPID::ShooterSpeedCalc(){
  double speed = frc::SmartDashboard::GetNumber("CalcFlywheelSpeed", 0);
  flywheelShooterMotorL.Set(ControlMode::Velocity, speed);
  flywheelShooterMotorR.Set(ControlMode::Velocity, speed);
}
double ShooterSubsystemPID::ShooterCalculatedVelocity(){
  return frc::SmartDashboard::GetNumber("CalcFlywheelSpeed", 0);
}

void ShooterSubsystemPID::Periodic() {
  frc::SmartDashboard::PutNumber("DIO0", lightCurtain.GetVoltage());
  frc::SmartDashboard::PutNumber("DIO1", lightCurtain1.GetVoltage());
}


