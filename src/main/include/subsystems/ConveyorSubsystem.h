/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "frc/DoubleSolenoid.h"
#include "frc/Ultrasonic.h"
#include <frc/DigitalInput.h>




class ConveyorSubsystem : public frc2::SubsystemBase {
 public:
  ConveyorSubsystem();
  void ConveyorMove(double speed);
  void ConveyorStop();
  void OrganizerMove(double speed);
  void OrganizerStop();
  void BallBlockerIn();
  void BallBlockerOut();
  void IntakeMove(double speed);
  void IntakeStop();
  void IntakeIn();
  void IntakeOut();
  void TopIndexStop();
  void TopIndexMove(double speed);
  double GetIntakeCurrent();
  double GetConveyorCurrent();
  double GetChimneyUltrasonic();
  bool GetChimneyDIO();
  bool GetChimneyDIO2();
  bool GetChimneyDIO3();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  frc::DoubleSolenoid ballBlocker{1,2,3};
  frc::DoubleSolenoid intakeInAndOut{1,0,1};
  WPI_TalonFX conveyorMotor {12};
  WPI_TalonSRX topIndexMotor{8};
  WPI_TalonSRX intakeMotor{4};  
  frc::Ultrasonic chimneyUltrasonic{4,5};
  frc::DigitalInput index1{8};
  frc::DigitalInput index2{6};
  frc::DigitalInput index3{7};
};
