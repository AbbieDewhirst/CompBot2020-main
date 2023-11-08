/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/HoodSubsystem.h"
#include <frc/smartdashboard/smartdashboard.h>
#include "Constants.h"

HoodSubsystem::HoodSubsystem() {
    hoodMotor.SetNeutralMode(NeutralMode::Brake);
    hoodMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, 0, 30);
    hoodMotor.SetSelectedSensorPosition(0, 0, 10);
    hoodMotor.SetSafetyEnabled(false);
    hoodMotor.Config_kP(PIDConstants::kPIDLoopInd, 1.0, PIDConstants::kTimeoutMs);
}

// This method will be called once per scheduler run
void HoodSubsystem::Periodic() {
    frc::SmartDashboard::PutNumber("Hood ENC", GetHoodEncoder());
}

void HoodSubsystem::HoodMove(double speed) {
    hoodMotor.Set(ControlMode::PercentOutput, speed);
}
double HoodSubsystem::GetHoodEncoder() {
    return hoodMotor.GetSelectedSensorPosition();
}
void HoodSubsystem::GoToHoodPos(double position) {
    hoodMotor.Set(ControlMode::Position, position); 
    // hoodMotor.Set
    // hoodMotor.SetSelectedSensorPosition(position);
}
void HoodSubsystem::HoodStop() {
    hoodMotor.Set(ControlMode::PercentOutput, 0.0);
}
void HoodSubsystem::GoToHoodPosCalc(){
    double angle = frc::SmartDashboard::GetNumber("CalcHoodEncoder", 0);
    frc::SmartDashboard::PutNumber("Angle", angle);
    hoodMotor.Set(ControlMode::Position, angle);
}
void HoodSubsystem::ZeroHood(){
    hoodMotor.SetSelectedSensorPosition(0,0,10);
}