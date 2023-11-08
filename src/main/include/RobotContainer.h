/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/Command.h>

#include "commands/ExampleCommand.h"
#include "commands/Autonomous.h"
#include "subsystems/DriveSubsystemPID.h"
#include "subsystems/ExampleSubsystem.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/ClimberSubsystem.h"
#include "subsystems/TurretSubsystem.h"
#include "commands/TurretCommand.h"
#include "subsystems/VisionDriveSubsystem.h"
#include "subsystems/ColourWheelSubsystem.h"
#include "subsystems/RangeFindingSubsystem.h"
#include "commands/AutoDriveForwardAndTurnCommandGroup.h"
#include "commands/Print22CommandGroup.h"
#include "subsystems/HoodSubsystem.h"
#include "subsystems/LEDSubsystem.h"
#include <frc/smartdashboard/SendableChooser.h>
#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
#include "commands/AutoGoPickupMoreIndexing.h"
#include "commands/AutoShootAndDriveOffLine.h"
#include"commands/AutoShootFeedGoPickUpMoreShootCommandGroup.h"
#include "commands/ZOOOOMCommandGroup.h"
#include "commands/DriveToDistancePIDCommand.h"
#include "subsystems/OrganizerSubsystem.h"

#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include "Constants.h"

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();

  frc2::Command* GetAutonomousCommand();

 private:
 //create the joystick
 frc::Joystick m_joy{0};
  // The robot's subsystems and commands are defined here...
 // ExampleSubsystem m_subsystem;
  Autonomous m_autonomouscommand;
  Print22CommandGroup m_print22autogroup;
  AutoDriveForwardAndTurnCommandGroup m_autodriveforwardandturncommandgroup;
  AutoShootAndDriveOffLine m_autoshootanddriveofflinecommandgroup;
  AutoShootFeedGoPickUpMoreShootCommandGroup m_autoshootfeedgopickupmoreshootcommandgroup;
  DriveSubsystem m_drivesubsystem;
  ShooterSubsystemPID m_shootersubsystemPID;
  ConveyorSubsystem m_conveyorsubsystem;
  TurretSubsystem m_turretsubsystem;
  VisionDriveSubsystem m_visiondrivesubsystem;
  ColourWheelSubsystem m_colourwheelsubsystem;
  RangeFindingSubsystem m_rangefindersubsystem;
  OrganizerSubsystem m_organizersubsystem;
  ClimberSubsystem m_climbersubsystem;
  HoodSubsystem m_hoodsubsystem;
  LEDSubsystem m_LEDsubsystem;
  DriveSubsystemPID m_drivesubsystemPID;
  ZOOOOMCommandGroup m_ZOOOOMCommandGroup;

  AutoGoPickupMoreIndexing m_autoshootgopickupmoreshootcommandgroup;

  frc::SendableChooser<frc2::Command*> m_autoChooser;



//  Print1Commmand m_print1auto;
//   Print2Command m_print2auto;
//   Print3Command m_print3auto;

  
//   Print21CommandGroup m_print21autogroup;



  /* create the xbox controllers*/
  frc::XboxController m_driverController{OIConstants::kDriverControllerPort};
  frc::XboxController m_operatorController{OIConstants::kOperatorControllerPort};
  frc::XboxController m_testController2{OIConstants::kTestController2};
  frc::XboxController m_testController3{OIConstants::kTestController3};
  frc::XboxController m_testController4{OIConstants::kTestController4};



  
  void ConfigureButtonBindings();
};
