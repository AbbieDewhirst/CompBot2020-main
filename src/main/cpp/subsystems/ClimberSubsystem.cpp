/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/ClimberSubsystem.h"
#include <frc/smartdashboard/smartdashboard.h>
#include "Constants.h"

ClimberSubsystem::ClimberSubsystem() {
    climberMotor.SetInverted(false);
    climberArmMotor.SetInverted(true);
    climberArmMotor.SetNeutralMode(NeutralMode::Brake);
    climberArmMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 30);
    climberArmMotor.SetSelectedSensorPosition(0, 0, 10);
    climberArmMotor.SetSafetyEnabled(false);
    climberArmMotor.Config_kP(PIDConstants::kPIDLoopInd, 1.0, PIDConstants::kTimeoutMs);
}

// This method will be called once per scheduler run
void ClimberSubsystem::Periodic() {
    frc::SmartDashboard::PutNumber("Arm ENC", GetArmEncoder());
}

void ClimberSubsystem::ClimberMove(double speed) {
    climberMotor.Set(speed);
}
void ClimberSubsystem::ClimberStop() {
    climberMotor.Set(0.0);
}
void ClimberSubsystem::ArmMove(double speed) {
    climberArmMotor.Set(ControlMode::PercentOutput, speed);
}
double ClimberSubsystem::GetArmEncoder() {
    return climberArmMotor.GetSelectedSensorPosition();
}
void ClimberSubsystem::GoToArmPos(double position) {
    climberArmMotor.Set(ControlMode::Position, position);
    // climberArmMotor.Set
    // climberArmMotor.SetSelectedSensorPosition(position);
}
void ClimberSubsystem::ClimberArmStop() {
    climberArmMotor.Set(ControlMode::PercentOutput, 0.0);
}