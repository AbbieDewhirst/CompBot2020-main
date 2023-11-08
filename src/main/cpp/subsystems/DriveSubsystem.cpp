/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveSubsystem.h"
#include <iostream>
#include <frc/Joystick.h>
#include "Constants.h"
#include <frc2/Timer.h>
#include <frc/smartdashboard/smartdashboard.h>
#include <frc/geometry/Rotation2d.h>
#include <frc/kinematics/DifferentialDriveWheelSpeeds.h>
#include <frc/geometry/Pose2d.h>
#include <cmath>

using namespace DriveConstants;

// ShooterSubsystem::ShooterSubsystem()
//     : PIDSubsystem(frc2::PIDController(kP, kI, kD)),
//       m_shooterMotor(kShooterMotorPort),
//       m_feederMotor(kFeederMotorPort),
//       m_shooterEncoder(kEncoderPorts[0], kEncoderPorts[1]),
//       m_shooterFeedforward(kS, kV) {
//   m_controller.SetTolerance(kShooterToleranceRPS.to<double>());
//   m_shooterEncoder.SetDistancePerPulse(kEncoderDistancePerPulse);
//   SetSetpoint(kShooterTargetRPS.to<double>());
// }


DriveSubsystem::DriveSubsystem()
    : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(0.0307, 0, 0)),
          m_odometry{frc::Rotation2d(units::degree_t(GetGyroAngle()))}
          {
          m_controller.SetTolerance(3);
          
          ZeroDriveEncoders();
  

  m_frontLeft.SetSafetyEnabled(false);
  m_frontRight.SetSafetyEnabled(false);
  // m_backLeft.SetSafetyEnabled(false);
  // m_backRight.SetSafetyEnabled(false);
  m_frontLeft.ConfigFactoryDefault();
  m_frontRight.ConfigFactoryDefault();
  m_frontLeft.SetNeutralMode(NeutralMode::Brake);
  m_frontRight.SetNeutralMode(NeutralMode::Brake);
  //invert moptors?
  m_frontLeft.SetInverted(false);
  // m_backLeft.SetInverted(false);
  m_frontLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 30);
  m_frontRight.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 30);
  m_backLeft.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 30);
  m_backRight.ConfigSelectedFeedbackSensor(FeedbackDevice::IntegratedSensor, 0, 30);

  m_frontLeft.SetSensorPhase(true);

  /* set the peak and nominal outputs, 12V means full */

	m_frontLeft.ConfigNominalOutputForward(0, PIDConstants::kTimeoutMs);
	m_frontLeft.ConfigNominalOutputReverse(0, PIDConstants::kTimeoutMs);
	m_frontLeft.ConfigPeakOutputForward(1, PIDConstants::kTimeoutMs);
  m_frontLeft.ConfigPeakOutputReverse(-1, PIDConstants::kTimeoutMs);

	m_frontRight.ConfigNominalOutputForward(0, PIDConstants::kTimeoutMs);
	m_frontRight.ConfigNominalOutputReverse(0, PIDConstants::kTimeoutMs);
	m_frontRight.ConfigPeakOutputForward(1, PIDConstants::kTimeoutMs);
	m_frontRight.ConfigPeakOutputReverse(-1, PIDConstants::kTimeoutMs);
    /* set closed loop gains in slot0 */
  m_frontLeft.SelectProfileSlot(0, 0);
  m_frontLeft.Config_kF(PIDConstants::kPIDLoopInd, 0.048, PIDConstants::kTimeoutMs);  
	m_frontLeft.Config_kP(PIDConstants::kPIDLoopInd, 0.25, PIDConstants::kTimeoutMs);
	m_frontLeft.Config_kI(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);
	m_frontLeft.Config_kD(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);
  m_frontLeft.ConfigAllowableClosedloopError(0,1000);

  m_frontRight.SelectProfileSlot(0, 0);
	m_frontRight.Config_kF(PIDConstants::kPIDLoopInd, 0.048, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kP(PIDConstants::kPIDLoopInd, 0.25, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kI(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kD(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);



  m_frontLeft.SelectProfileSlot(1, 0);
  m_frontLeft.Config_kF(PIDConstants::kPIDLoopInd, 0.048, PIDConstants::kTimeoutMs);  
	m_frontLeft.Config_kP(PIDConstants::kPIDLoopInd, 0.25, PIDConstants::kTimeoutMs);
	m_frontLeft.Config_kI(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);
	m_frontLeft.Config_kD(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);

  m_frontRight.SelectProfileSlot(1, 0);
	m_frontRight.Config_kF(PIDConstants::kPIDLoopInd, 0.048, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kP(PIDConstants::kPIDLoopInd, 0.25, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kI(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);
	m_frontRight.Config_kD(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);




  /* Set acceleration and vcruise velocity - see documentation */
  m_frontLeft.ConfigMotionCruiseVelocity(14000, 10);//UNITS PER 100 MILLISECOND
  m_frontLeft.ConfigMotionAcceleration(14000, 10);//units per 100 ms per sec
  m_frontRight.ConfigMotionCruiseVelocity(14000, 10);
  m_frontRight.ConfigMotionAcceleration(14000, 10);
  /* Zero the sensor */
  m_frontLeft.SetSelectedSensorPosition(0, 0, 10);
  m_frontRight.SetSelectedSensorPosition(0, 0, 10);
  m_backRight.SetSelectedSensorPosition(0, 0, 10);
  m_backLeft.SetSelectedSensorPosition(0, 0, 10);
  l_ramprate = 0.025;
  l_prevthrottle = 0.0;
//disable the safteyt for the drive(motor safety disabled earlier)
  m_robotDrive.SetSafetyEnabled(false);
   //Makes the compressor
  compressor.Enabled();
}

//PID Core Functions ********************************************
void DriveSubsystem::UseOutput(double output, double setpoint) {
  // Use the output here
  m_RightGroup.Set(output);
}

double DriveSubsystem::GetMeasurement() {
  // Return the process variable measurement here
  return GetRightEnc();
}

bool DriveSubsystem::AtSetpoint() { return m_controller.AtSetpoint(); }
//PID Core Functions ********************************************end

void DriveSubsystem::Drive(double yy, double xx){
  m_robotDrive.ArcadeDrive(yy, xx, true);
  //m_robotDrive.CurvatureDrive(yy,xx*xx*xx,true);
  
}

void DriveSubsystem::DriveWithRamp(double yy, double xx){
  double newthrottle = 0.0;
  if (yy > l_prevthrottle)
  {
      if (yy - l_prevthrottle > l_ramprate){
        newthrottle = l_prevthrottle + l_ramprate;
      }
      else{
        newthrottle = yy;
      }
        
  }
  else if (yy < l_prevthrottle)
  {
    if (yy-l_prevthrottle < -l_ramprate)
    {
      newthrottle = l_prevthrottle - l_ramprate;
    }
    else{
      newthrottle = yy;
    }

  }
  else{
    newthrottle = yy;
  }

  frc::SmartDashboard::PutNumber("Prev Throttle", l_prevthrottle);
  frc::SmartDashboard::PutNumber("New Throttle", newthrottle);
  m_robotDrive.ArcadeDrive(newthrottle,xx);
  l_prevthrottle = newthrottle;
  }

  void DriveSubsystem::DriveWithRampUpOnly(double yy, double xx){
  double newthrottle = 0.0;
  if (yy > l_prevthrottleup && l_prevthrottleup > 0)
  {
      if (yy - l_prevthrottleup > l_ramprate){
        newthrottle = l_prevthrottleup + l_ramprate;
      }
      else{
        newthrottle = yy;
      }
        
  }
  else if (yy < l_prevthrottleup && l_prevthrottleup < 0)
  {
    if (yy-l_prevthrottleup < -l_ramprate)
    {
      newthrottle = l_prevthrottle - l_ramprate;
    }
    else{
      newthrottle = yy;
    }

  }
  else{
    newthrottle = yy;
  }

  frc::SmartDashboard::PutNumber("Prev Throttle", l_prevthrottle);
  frc::SmartDashboard::PutNumber("New Throttle", newthrottle);
  m_robotDrive.ArcadeDrive(newthrottle,xx);
  l_prevthrottle = newthrottle;
  }
void DriveSubsystem::DriveStop(){
    m_robotDrive.ArcadeDrive(0.0, 0.0);
}
double DriveSubsystem::GetDistance(){
    return (m_frontLeft.GetSelectedSensorPosition() + m_frontRight.GetSelectedSensorPosition())/ 2.0;
}
double DriveSubsystem::GetRightEnc() {
  // std::cout<<"front right encoder "<< m_frontRight.GetSelectedSensorPosition()<<std::endl;
  return (-1*m_backRight.GetSelectedSensorPosition());
}

double DriveSubsystem::GetLeftEnc() {
  return (m_backLeft.GetSelectedSensorPosition());
}
void DriveSubsystem::SetTargetPosition(double targetPositionLeft, double targetPositionRight){
    // std::cout<<"target Pos left "<<targetPositionLeft<<std::endl;
    // std::cout<<"target Pos right "<<targetPositionRight<<std::endl;
    m_frontLeft.Set(ControlMode::Position, targetPositionLeft);
    m_frontRight.Set(ControlMode::Position, targetPositionRight); 
}
void DriveSubsystem::SetMotionMagicOFF(){
 m_frontLeft.Set(ControlMode::PercentOutput,0);
 m_frontRight.Set(ControlMode::PercentOutput,0);
}
void DriveSubsystem::Wait(double seconds){
  
}
void DriveSubsystem::InvertRightDriveMotor(bool isInverted){
  m_frontRight.SetInverted(isInverted);

}

void DriveSubsystem::ZeroDriveEncoders() {

m_frontRight.SetSelectedSensorPosition(0,0,1000);
m_frontLeft.SetSelectedSensorPosition(0,0,1000);
m_backRight.SetSelectedSensorPosition(0,0,1000);
m_backLeft.SetSelectedSensorPosition(0,0,1000);

}

double DriveSubsystem::GetTurnRate(){
  return m_gyro.GetRate();
}

double DriveSubsystem::GetGyroAngle() {
  return -(m_gyro.GetAngle());
}
void DriveSubsystem::StartCompressor() {
    compressor.Start();
}

double DriveSubsystem::GetUltraSonic(){
  return ultrasonic.GetRangeInches();
}
void DriveSubsystem::TankDriveTurn(double l, double r) {
  m_robotDrive.TankDrive(l, r);
}
void DriveSubsystem::ZeroGyro() {
  m_gyro.Reset();
}

void DriveSubsystem::UsePIDProfile(int profile){
    m_frontLeft.SelectProfileSlot(profile, 0);
    m_frontRight.SelectProfileSlot(profile, 0);
}

// This method will be called once per scheduler run
void DriveSubsystem::Periodic() {
  frc::SmartDashboard::PutNumber("Gyro = ", GetGyroAngle());
  frc::SmartDashboard::PutNumber("AverageEncoder = ", GetAverageEncoderDistance());
  // frc::SmartDashboard::PutNumber("LeftENC", m_frontLeft.GetSelectedSensorPosition());
  // frc::SmartDashboard::PutNumber("RightENC", m_frontRight.GetSelectedSensorPosition());
  // frc::SmartDashboard::PutNumber("BackLeft", m_backLeft.GetSelectedSensorPosition());
  // frc::SmartDashboard::PutNumber("BackRight", m_backRight.GetSelectedSensorPosition());
  frc::SmartDashboard::PutNumber("Left Encoders", GetLeftEnc());
  frc::SmartDashboard::PutNumber("Right Encoders", GetRightEnc());



  m_odometry.Update(frc::Rotation2d(units::degree_t(GetGyroAngle())),
                    units::meter_t(m_frontLeft.GetSelectedSensorPosition()),
                    units::meter_t(m_frontRight.GetSelectedSensorPosition()));
}

double DriveSubsystem::GetAverageEncoderDistance() {
  return (GetRightEnc() + GetLeftEnc()) / 2.0;
}

frc::Pose2d DriveSubsystem::GetPose() { return m_odometry.GetPose(); }

frc::DifferentialDriveWheelSpeeds DriveSubsystem::GetWheelSpeeds() {
  return {units::meters_per_second_t(m_frontLeft.GetSelectedSensorVelocity()),
          units::meters_per_second_t(m_frontRight.GetSelectedSensorVelocity())};
}

void DriveSubsystem::ResetOdometry(frc::Pose2d pose) {
  ZeroDriveEncoders();
  m_odometry.ResetPosition(pose,
                           frc::Rotation2d(units::degree_t(GetGyroAngle())));

}

void DriveSubsystem::TankDriveVolts(units::volt_t left, units::volt_t right) {
  m_LeftGroup.SetVoltage(left);
  m_RightGroup.SetVoltage(-right);
  m_robotDrive.Feed();
}

void DriveSubsystem::DriveRampReset(){
  l_prevthrottle = 0;
  l_prevthrottleup = 0;
}