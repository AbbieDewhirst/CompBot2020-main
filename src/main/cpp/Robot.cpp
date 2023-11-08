/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2019 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//making a change so I can push the branch

#include "Robot.h"
#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/CommandScheduler.h>
#include "subsystems/TurretSubsystem.h"
#include "RobotContainer.h"
#include "subsystems/TurretSubsystem.h"
#include "commands/LimelightOn.h"
#include "subsystems/HoodSubsystem.h"

 frc::Compressor *m_compressor = new frc::Compressor(1); //Comppressor is on PCM ID 1
 TurretSubsystem m_robotTurretSubsystem;
 HoodSubsystem m_hoodsubsystem;
void Robot::RobotInit() {
m_compressor->SetClosedLoopControl(true);
m_compressor->Start();
// m_robotTurretSubsystem.LimelightOn();
}




/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want to run during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() { frc2::CommandScheduler::GetInstance().Run(); }

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {

  
  // m_turretsubsystem.OffLED();
}

void Robot::DisabledPeriodic() {
  // m_robotTurretSubsystem.LimelightOff();
}

/**
 * This autonomous runs the autonomous command selected by your {@link
 * RobotContainer} class.
 */
void Robot::AutonomousInit() {
  m_autonomouscommand = m_container.GetAutonomousCommand();


  if (m_autonomouscommand != nullptr) {
    m_autonomouscommand->Schedule();
  }
}

void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {
  // This makes sure that the autonomous stops running when
  // teleop starts running. If you want the autonomous to
  // continue until interrupted by another command, remove
  // this line or comment it out.
  if (m_autonomouscommand != nullptr) {
    m_autonomouscommand->Cancel();
    m_autonomouscommand = nullptr;
  }
}

/**
 * This function is called periodically during operator control.
 */
void Robot::TeleopPeriodic() {
    // frc::SmartDashboard::PutNumber("ultra sonic", m_drivesubsystem->GetUltraSonic());
}

/**
 * This function is called periodically during test mode.
 */
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
