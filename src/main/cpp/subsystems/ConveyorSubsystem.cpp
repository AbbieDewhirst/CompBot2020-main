/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ConveyorSubsystem.h"
#include <frc/smartdashboard/smartdashboard.h>
ConveyorSubsystem::ConveyorSubsystem() {
    conveyorMotor.SetInverted(true);
    intakeMotor.SetInverted(false);
    topIndexMotor.SetInverted(false);
}

// This method will be called once per scheduler ru 
void ConveyorSubsystem::Periodic() {
  frc::SmartDashboard::PutNumber("Chimney Ultrasonic = ", GetChimneyUltrasonic());
  
  frc::SmartDashboard::PutBoolean("index1", GetChimneyDIO());
  frc::SmartDashboard::PutBoolean("index2", GetChimneyDIO2());
  frc::SmartDashboard::PutBoolean("index3", GetChimneyDIO3());
}

void ConveyorSubsystem::ConveyorMove(double speed) {
    conveyorMotor.Set(ControlMode::PercentOutput, speed);
}
void ConveyorSubsystem::ConveyorStop() {
    conveyorMotor.Set(ControlMode::PercentOutput, 0.0);
}
void ConveyorSubsystem::IntakeMove(double speed){
    intakeMotor.Set(ControlMode::PercentOutput, speed);
}
void ConveyorSubsystem::IntakeStop(){
    intakeMotor.Set(ControlMode::PercentOutput, 0.0);
}
void ConveyorSubsystem::BallBlockerIn(){
      ballBlocker.Set(frc::DoubleSolenoid::Value::kForward);
}
void ConveyorSubsystem::BallBlockerOut(){
      ballBlocker.Set(frc::DoubleSolenoid::Value::kReverse);
}
void ConveyorSubsystem::IntakeIn(){
      intakeInAndOut.Set(frc::DoubleSolenoid::Value::kForward);
}
void ConveyorSubsystem::IntakeOut(){
      intakeInAndOut.Set(frc::DoubleSolenoid::Value::kReverse);
}
void ConveyorSubsystem::TopIndexStop(){
    topIndexMotor.Set(ControlMode::PercentOutput, 0.0);
}
void ConveyorSubsystem::TopIndexMove(double speed){
    topIndexMotor.Set(ControlMode::PercentOutput, speed);
}

double ConveyorSubsystem::GetConveyorCurrent() {
    return conveyorMotor.GetOutputCurrent();
}

double ConveyorSubsystem::GetIntakeCurrent() {
    return intakeMotor.GetOutputCurrent();
}
double ConveyorSubsystem::GetChimneyUltrasonic(){
  return chimneyUltrasonic.GetRangeInches();
}
bool ConveyorSubsystem::GetChimneyDIO(){
    return !index1.Get();
}
bool ConveyorSubsystem::GetChimneyDIO2(){
    return !index2.Get();
}
bool ConveyorSubsystem::GetChimneyDIO3(){
    return !index3.Get();
}