/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc2/command/PIDSubsystem.h>

#include <frc2/command/SubsystemBase.h>
#include <frc/SpeedControllerGroup.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/ADXRS450_Gyro.h>
#include "ctre/Phoenix.h"
#include "frc/Ultrasonic.h"
#include "frc/Compressor.h"
#include <frc/geometry/Pose2d.h>
#include <frc/kinematics/DifferentialDriveOdometry.h>
#include "Constants.h"


class DriveSubsystem : public frc2::PIDSubsystem {
 public:
  DriveSubsystem();

  void Drive(double yy, double xx);
  void DriveWithRamp(double yy, double xx);
  void DriveWithRampUpOnly(double yy, double xx);
  void DriveStop();
  double GetDistance();
  double GetRightEnc();
  double GetLeftEnc();
  void SetTargetPosition(double targetPositionLeft, double tarfgetPositionRight);
  void SetMotionMagicOFF();
  void Wait(double seconds);
  void Periodic();
  void InvertRightDriveMotor(bool isInverted);
  void ZeroDriveEncoders();
  double GetGyroAngle();
  void StartCompressor();
  double GetUltraSonic();
  void TankDriveTurn(double l, double r);
  void ZeroGyro();
  void UsePIDProfile(int profile);
  void ResetEncoders();
  double GetAverageEncoderDistance();

  void SetMaxOutput(double maxOutput);

  double GetHeading();
  double GetTurnRate();
  void DriveRampReset();

  frc::Pose2d GetPose();

  frc::DifferentialDriveWheelSpeeds GetWheelSpeeds();

  void ResetOdometry(frc::Pose2d pose);
  void TankDriveVolts(units::volt_t left, units::volt_t right);



protected:
  void UseOutput(double output, double setpoint) override;
  double GetMeasurement() override;
  bool AtSetpoint();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  WPI_TalonFX m_frontLeft{0};
  WPI_TalonFX m_backLeft{1};
  frc::SpeedControllerGroup m_LeftGroup{ m_frontLeft, m_backLeft};
  WPI_TalonFX m_frontRight{2};
  WPI_TalonFX m_backRight{3};
  frc::SpeedControllerGroup m_RightGroup{ m_frontRight, m_backRight};
  frc::DifferentialDrive m_robotDrive{m_LeftGroup, m_RightGroup};
  double l_prevthrottle;
  double l_prevthrottleup;
  double l_ramprate;
  frc::ADXRS450_Gyro m_gyro;
  frc::Compressor compressor;
  frc::Ultrasonic ultrasonic{0,1};

  frc::DifferentialDriveOdometry m_odometry;
};
