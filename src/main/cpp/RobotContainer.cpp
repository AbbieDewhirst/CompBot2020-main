/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
//Maidsindaiohnfa
//need to push to test
#include "RobotContainer.h"
#include "commands/Autonomous.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc2/command/button/JoystickButton.h>
#include "commands/DriveToDistanceCommand.h"
#include "subsystems/DriveSubsystem.h"
#include "subsystems/DriveSubsystemPID.h"
#include "commands/DriveCommand.h"
#include "commands/DriveStraightUsingGyroCommand.h"
#include "commands/TurnInPlaceCommand.h"
#include "Robot.h"
#include "commands/AutoDriveForwardAndTurnCommandGroup.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "commands/ShootBallCommandGroup.h"
#include "commands/ShooterForwardsCommand.h"
#include "commands/ConveyorMoveCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "commands/TurretCommand.h"
#include "commands/ManualTurretCommand.h"
#include "commands/VisionDriveCommand.h"
#include "commands/ColourWheelFRDCommand.h"
#include "commands/LookforNextColourCommand.h"
#include "commands/LookforCountedColourCommand.h"
#include "commands/BallBlockerInCommand.h"
#include "commands/BallBlockerOutCommand.h"
#include "commands/OrganizerMoveCommand.h"
#include "Constants.h"
#include "commands/ClimberArmEncoderCommand.h"
#include "commands/ClimberArmManualCommand.h"
#include "subsystems/ClimberSubsystem.h"
#include "commands/ShooterFeederCommand.h"
#include "commands/IntakeInCommand.h"
#include "commands/IntakeOutCommand.h"
#include "commands/IntakeSolInCommand.h"
#include "commands/IntakeSolOutCommand.h"
#include "commands/IntakeAndConveyorInCommandGroup.h"
#include "commands/IntakeAndConveyorOutCommandGroup.h"
#include "commands/IntakeAndConveyorWhenReleasedCommandGroup.h"
#include "commands/Print22CommandGroup.h"
#include "commands/AutoDriveForwardAndTurnCommandGroup.h"
#include "commands/LightCurtainCounterCommand.h"
#include "commands/TurnInPlaceCommand.h"
#include "commands/DriveStraightUsingGyroCommand.h"
#include "commands/GetToVelocityCommand.h"
#include "commands/HoodPositionCommand.h"
#include "commands/HoodCommand.h"
#include <frc2/command/InstantCommand.h>
#include "commands/DriveToUltrasonicCommand.h"
#include "commands/TurretCommand.h"
#include "commands/WinchInCommand.h"
#include "commands/ShootBallTeleopCommandGroup.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
#include "commands/DriveForwardAndIntakeRaceCommand.h"
#include "commands/AutoShootGoPickUpMoreShootCommandGroup.h"
#include "commands/ExtendIntakeandGrabBallsCommand.h"
#include "commands/LimelightOn.h"
#include "commands/AutoIntakeCommand.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/TurnToAngleCommand.h"
#include "commands/ShootBallTeleopCommandGroup.h"
#include "commands/StopAfterShotTeleopCommandGroup.h"
#include "commands/VisionTurretPID.h"
#include "commands/ClimberCommandGroup.h"
#include "commands/AutoShootAndDriveOffLine.h"
#include "commands/AutoShootFeedGoPickUpMoreShootCommandGroup.h"
#include "commands/DriveToDistancePIDCommand.h"
#include "commands/ZoomTest1Command.h"
#include <frc/trajectory/constraint/DifferentialDriveVoltageConstraint.h>
#include <frc2/command/RamseteCommand.h>
#include <frc/controller/RamseteController.h>
#include <frc/trajectory/Trajectory.h>
#include "commands/ZOOOOMCommandGroup.h"
#include <frc/trajectory/TrajectoryGenerator.h>
#include <frc/Filesystem.h>
#include <frc/trajectory/TrajectoryUtil.h>
#include <wpi/Path.h>
#include <wpi/SmallString.h>
#include "commands/DriveStraightUsingGyroCommandV2.h"
#include "commands/TurnInPlaceV2.h"
#include "commands/TurretVisionV2.h"
/*include all the commands here*/


RobotContainer::RobotContainer() : 
m_autonomouscommand(&m_drivesubsystem) ,
m_print22autogroup(&m_drivesubsystem),
m_autodriveforwardandturncommandgroup(&m_drivesubsystem),
m_autoshootgopickupmoreshootcommandgroup( 
      &m_turretsubsystem, 
      &m_shootersubsystemPID, 
      &m_conveyorsubsystem, 
      &m_organizersubsystem, 
      &m_hoodsubsystem,
      &m_drivesubsystem),
m_autoshootanddriveofflinecommandgroup(&m_turretsubsystem, 
      &m_shootersubsystemPID, 
      &m_conveyorsubsystem, 
      &m_organizersubsystem, 
      &m_hoodsubsystem,
      &m_drivesubsystem),
m_autoshootfeedgopickupmoreshootcommandgroup( 
      &m_turretsubsystem, 
      &m_shootersubsystemPID, 
      &m_conveyorsubsystem, 
      &m_organizersubsystem, 
      &m_hoodsubsystem,
      &m_drivesubsystem),
m_ZOOOOMCommandGroup(&m_drivesubsystemPID)
{
  // Initialize all of your commands and subsystems here

  /*drive*/
    m_drivesubsystem.SetDefaultCommand(DriveCommand(
    &m_drivesubsystem,
      [this] {
        if (m_joy.GetRawAxis(3) > 0.0 || m_joy.GetRawAxis(2) > 0.0){
          {return ((m_joy.GetRawAxis(3) - m_joy.GetRawAxis(2))*0.4);};
        }else{
          {return (-1*m_joy.GetRawAxis(1)); };
        }
      },
    [this] { return m_joy.GetRawAxis(4)*0.8; }));
//for triggers return (m_joy.GetRawAxis(3) - m_joy.GetRawAxis(2));  //for joystick driving return (-1*m_joy.GetRawAxis(1));

 m_autoChooser.SetDefaultOption("Shoot auto go to trench", &m_autoshootgopickupmoreshootcommandgroup);
   m_autoChooser.AddOption("Auto Drive forward and turn", &m_autodriveforwardandturncommandgroup);
  m_autoChooser.AddOption("Print 22 Group",&m_print22autogroup);
  m_autoChooser.AddOption("Shoot auto go to trench", &m_autoshootgopickupmoreshootcommandgroup);
 m_autoChooser.AddOption("Shoot then drive away", &m_autoshootanddriveofflinecommandgroup);
 m_autoChooser.AddOption("Feeding in balls auto", &m_autoshootfeedgopickupmoreshootcommandgroup);
  //m_autoChooser.AddOption("I LOVE TO DRIVE ZOOOOOM", &m_zoomauto)

  frc::SmartDashboard::PutData("Auto Mode", &m_autoChooser);
  frc::SmartDashboard::PutBoolean("fake light curtain", false);


  // Configure the button bindings
  ConfigureButtonBindings();
}

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
  /*driver controller(joystick 0)*/
  frc2::Button J0B1{[&] {return m_driverController.GetRawButton(1);}};
  frc2::Button J0B2{[&] {return m_driverController.GetRawButton(2);}};
  frc2::Button J0B3{[&] {return m_driverController.GetRawButton(3);}};
  frc2::Button J0B4{[&] {return m_driverController.GetRawButton(4);}};
  frc2::Button J0B5{[&] {return m_driverController.GetRawButton(5);}};
  frc2::Button J0B6{[&] {return m_driverController.GetRawButton(6);}};
  frc2::Button J0B7{[&] {return m_driverController.GetRawButton(7);}};
  frc2::Button J0B8{[&] {return m_driverController.GetRawButton(8);}};
  /*operator controller(joystick 1)*/
  frc2::Button J1B1{[&] {return m_operatorController.GetRawButton(1);}};
  frc2::Button J1B2{[&] {return m_operatorController.GetRawButton(2);}};
  frc2::Button J1B3{[&] {return m_operatorController.GetRawButton(3);}};
  frc2::Button J1B4{[&] {return m_operatorController.GetRawButton(4);}};
  frc2::Button J1B5{[&] {return m_operatorController.GetRawButton(5);}};
  frc2::Button J1B6{[&] {return m_operatorController.GetRawButton(6);}};
  frc2::Button J1B7{[&] {return m_operatorController.GetRawButton(7);}};
  frc2::Button J1B8{[&] {return m_operatorController.GetRawButton(8);}};

  frc2::Button J2B1{[&] {return m_testController2.GetRawButton(1);}};
  frc2::Button J2B2{[&] {return m_testController2.GetRawButton(2);}};
  frc2::Button J2B3{[&] {return m_testController2.GetRawButton(3);}};
  frc2::Button J2B4{[&] {return m_testController2.GetRawButton(4);}};
  frc2::Button J2B5{[&] {return m_testController2.GetRawButton(5);}};
  frc2::Button J2B6{[&] {return m_testController2.GetRawButton(6);}};
  frc2::Button J2B7{[&] {return m_testController2.GetRawButton(7);}};
  frc2::Button J2B8{[&] {return m_testController2.GetRawButton(8);}};

  frc2::Button J3B1{[&] {return m_testController3.GetRawButton(1);}};
  frc2::Button J3B2{[&] {return m_testController3.GetRawButton(2);}};
  frc2::Button J3B3{[&] {return m_testController3.GetRawButton(3);}};
  frc2::Button J3B4{[&] {return m_testController3.GetRawButton(4);}};
  frc2::Button J3B5{[&] {return m_testController3.GetRawButton(5);}};
  frc2::Button J3B6{[&] {return m_testController3.GetRawButton(6);}};
  frc2::Button J3B7{[&] {return m_testController3.GetRawButton(7);}};
  frc2::Button J3B8{[&] {return m_testController3.GetRawButton(8);}};

  frc2::Button J4B1{[&] {return m_testController4.GetRawButton(1);}};
  frc2::Button J4B2{[&] {return m_testController4.GetRawButton(2);}};
  frc2::Button J4B3{[&] {return m_testController4.GetRawButton(3);}};
  frc2::Button J4B4{[&] {return m_testController4.GetRawButton(4);}};
  frc2::Button J4B5{[&] {return m_testController4.GetRawButton(5);}};
  frc2::Button J4B6{[&] {return m_testController4.GetRawButton(6);}};
  frc2::Button J4B7{[&] {return m_testController4.GetRawButton(7);}};
  frc2::Button J4B8{[&] {return m_testController4.GetRawButton(8);}};

  //Current Teleop Controls
    // J0B1.WhenPressed(TurretVisionV2(&m_turretsubsystem));
    J0B1.WhileHeld(ShootBallTeleopCommandGroup(&m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_turretsubsystem, 13500, true));
    J0B1.WhenReleased(StopAfterShotTeleopCommandGroup(&m_conveyorsubsystem, &m_hoodsubsystem, &m_turretsubsystem, &m_shootersubsystemPID));
    J0B5.WhileHeld(ManualTurretCommand(&m_turretsubsystem, 1.0));
    J0B6.WhileHeld(ManualTurretCommand(&m_turretsubsystem, -1.0));
  
    J1B3.ToggleWhenPressed(ExtendIntakeandGrabBallsCommand(&m_conveyorsubsystem));
    J1B5.WhileHeld(HoodCommand(&m_hoodsubsystem, -0.2));
    J1B6.WhileHeld(HoodCommand(&m_hoodsubsystem, 0.2));


    
    // J0B2.WhenPressed(AutoShootGoPickUpMoreShootCommandGroup(&m_turretsubsystem, &m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_drivesubsystem));

     J2B3.WhenPressed(ClimberCommandGroup(&m_turretsubsystem, &m_climbersubsystem));
     J2B1.WhenPressed(BallBlockerInCommand(&m_conveyorsubsystem));
     J2B2.WhenPressed(BallBlockerOutCommand(&m_conveyorsubsystem));
    // J2B1.WhileHeld(WinchInCommand(&m_climbersubsystem, 0.5)); //NEVER NEGATIVEEEEE
     J2B6.WhileHeld(ClimberArmManualCommand(&m_climbersubsystem, 0.5));
     J2B5.WhileHeld(ClimberArmManualCommand(&m_climbersubsystem, -0.5));
    // J2B7.WhenPressed(ClimberArmEncoderCommand(&m_climbersubsystem, 0.0));
   
    // J2B6.WhileHeld(WinchInCommand(&m_climbersubsystem, 1.0)); //NEVER NEGATIVEEEEE



    // J0B3.WhenPressed(TurnInPlaceCommand(&m_drivesubsystem, 90));


    //  J3B1.WhenPressed(TurnInPlaceV2(&m_drivesubsystem, 90, 1.0, 90));
    //  J3B2.WhenPressed(TurnInPlaceV2(&m_drivesubsystem, 120, 1.0, 90));
    //  J3B3.WhenPressed(TurnInPlaceV2(&m_drivesubsystem, -90, 1.0, 90));
    //  J3B4.WhenPressed(TurnInPlaceV2(&m_drivesubsystem, -180, 1.0, 90));
    //  J3B5.WhenPressed(DriveStraightUsingGyroCommandV2(&m_drivesubsystem, -24, 0.75, false, 24.0));
     J3B1.WhenPressed(DriveStraightUsingGyroCommandV2(&m_drivesubsystem, 120, 1.0, false, 24.0));
     J3B2.WhenPressed(DriveStraightUsingGyroCommandV2(&m_drivesubsystem, -120, 0.75, false, 24.0));
    J3B3.WhenPressed(DriveStraightUsingGyroCommandV2(&m_drivesubsystem, 36, 1.0, false, 24.0));
    J3B4.WhenPressed(DriveStraightUsingGyroCommandV2(&m_drivesubsystem, -36, 0.75, false, 24.0));
    // J3B5.WhileHeld(IntakeInCommand(&m_conveyorsubsystem));
  
  
        // J3B1.WhenPressed(AutoShootGoPickUpMoreShootCommandGroup(&m_turretsubsystem, &m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_drivesubsystem));
  // J3B3.WhileHeld(ZoomTest1Command(&m_drivesubsystemPID, 22)); 
  // J3B1.WhileHeld(ClimberArmManualCommand(&m_climbersubsystem, 0.5));




  // J2B1.WhenPressed(DriveStraightUsingGyroCommand(&m_drivesubsystem, 226, 0.50, true));
  // J2B2.WhenPressed(ShootBallCommandGroup(&m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_turretsubsystem, 3, 14000, true));
  // J2B3.WhileHeld(IntakeAndConveyorInCommandGroup(&m_conveyorsubsystem));
  // J2B3.WhenReleased(IntakeAndConveyorWhenReleasedCommandGroup(&m_conveyorsubsystem));
  // //J2B4.WhileHeld(IntakeAndConveyorOutCommandGroup(&m_conveyorsubsystem));
  // //J2B4.WhenReleased(IntakeAndConveyorWhenReleasedCommandGroup(&m_conveyorsubsystem));
  // J2B4.WhileHeld(HoodCommand(&m_hoodsubsystem, 0.5));
  // J2B5.WhileHeld(HoodCommand(&m_hoodsubsystem, -0.5));
  // J2B6.WhileHeld(GetToVelocityCommand(&m_shootersubsystemPID, &m_hoodsubsystem, &m_turretsubsystem, 19500, true));
  // J2B7.WhenPressed(BallBlockerInCommand(&m_conveyorsubsystem));
  // J2B8.WhenPressed(BallBlockerOutCommand(&m_conveyorsubsystem));

  // J3B2.WhileHeld(ZoomTest1Command(&m_drivesubsystemPID, 11));
  // J3B3.WhileHeld(ZoomTest1Command(&m_drivesubsystemPID, 22)); 
  // J3B1.WhileHeld(ClimberArmManualCommand(&m_climbersubsystem, 0.5));
  // J3B2.WhileHeld(ClimberArmManualCommand(&m_climbersubsystem, -0.5));
  // J3B3.WhileHeld(WinchInCommand(&m_climbersubsystem, 0.5)); //NEVER NEGATIVEEEEE
  // J3B4.WhenPressed(DriveStraightUsingGyroCommand(&m_drivesubsystem, 220, 1.0, false));
  // J3B5.WhenPressed(TurnInPlaceCommand(&m_drivesubsystem, 90.0));
  // J3B6.WhenPressed(TurnInPlaceCommand(&m_drivesubsystem, -90.0));
  // // J3B6.WhenPressed(TurretCommand(&m_turretsubsystem));
  // J3B7.WhileHeld(ConveyorMoveCommand(&m_conveyorsubsystem, 0.5));
  // J3B8.WhileHeld(OrganizerMoveCommand(&m_organizersubsystem, -0.5));

  // J4B1.WhileHeld(ShooterFeederCommand(&m_shootersubsystemPID, -1.0));
  // J4B2.WhileHeld(IntakeInCommand(&m_conveyorsubsystem));
  // J4B3.WhileHeld(IntakeOutCommand(&m_conveyorsubsystem));
  // J4B4.WhileHeld(ManualTurretCommand(&m_turretsubsystem, 0.5));
  // J4B5.WhileHeld(ManualTurretCommand(&m_turretsubsystem, -0.5));
  // J4B6.WhenPressed(ShootBallCommandGroup(&m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_turretsubsystem, 3, 14000, true));
  // //J4B7.WhileHeld(ShootBallTeleopCommandGroup(&m_shootersubsystemPID, &m_conveyorsubsystem, &m_organizersubsystem, &m_hoodsubsystem, &m_turretsubsystem, 14000));
  // J4B8.WhenPressed(AutoDriveForwardAndTurnCommandGroup(&m_drivesubsystem));
  J4B1.WhenPressed(AutoShootAndDriveOffLine(&m_turretsubsystem, 
    &m_shootersubsystemPID, 
    &m_conveyorsubsystem, 
    &m_organizersubsystem, 
    &m_hoodsubsystem,
    &m_drivesubsystem));



// I LOVE PROGRAMMING!!

//16000 is full power
//8000 is half power

// J2B1.WhileHeld(ShooterForwardsCommand(&m_shootersubsystemPID, 16000)); //100%
// J2B2.WhileHeld(ShooterForwardsCommand(&m_shootersubsystemPID, 4800)); //30%
// J2B3.WhileHeld(ShooterForwardsCommand(&m_shootersubsystemPID, 8000)); //50%
// J2B4.WhileHeld(ShooterForwardsCommand(&m_shootersubsystemPID, 12800)); //80%
// J2B5.WhileHeld(ConveyorMoveCommand(&m_conveyorsubsystem, 1.0)); //80%

//John's buttons section start
 // Configure your button bindings here
  // frc2::Button J3B1{[&] {return m_testController3.GetRawButton(1);}};
  // frc2::Button J3B2{[&] {return m_testController3.GetRawButton(2);}};
  // frc2::Button J3B3{[&] {return m_testController3.GetRawButton(3);}};
  // frc2::Button J3B4{[&] {return m_testController3.GetRawButton(4);}};
  // frc2::Button J3B5{[&] {return m_testController3.GetRawButton(5);}};


  // J3B2.WhileHeld(ManualTurretCommand(&m_turretsubsystem, 0.8));
  // J3B3.WhileHeld(ManualTurretCommand(&m_turretsubsystem, -0.8));
  // J3B1.WhileHeld(TurretCommand(&m_turretsubsystem)); //Vision
  // J3B4.WhileHeld(VisionDriveCommand(&m_visiondrivesubsystem)); //Also Vision
  // J3B5.WhenPressed(frc2::InstantCommand([&]{}, {&m_LEDsubsystem}));
  /*Mr D's buttons start
   XB2b2.WhileHeld(ColourWheelFRDCommand(&m_colourwheelsubsystem));
  XB2b3.WhenPressed(LookforCountedColourCommand(ColourWheelConstants::kBlueTarget, 1, &m_colourwheelsubsystem));
  XB2b4.WhenPressed(LookforCountedColourCommand(ColourWheelConstants::kBlueTarget, 4, &m_colourwheelsubsystem));
  Mr D's buttons end*/
}

// frc2::Command* RobotContainer::GetAutonomousCommand() {
//   // An example command will be run in autonomous
//   return &m_autonomouscommand;
// }
frc2::Command* RobotContainer::GetAutonomousCommand() {


  // An example command will be run in autonomous

 return  m_autoChooser.GetSelected();
 // return &m_autonomouscommand;


/*
**********************************
THIS IS PATH FOLLOWING CODE THAT DOESN'T WORK
**********************************


 frc::DifferentialDriveVoltageConstraint autoVoltageConstraint(
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics, 10_V);

      frc::TrajectoryConfig config(DriveConstants::kMaxSpeed,
                               DriveConstants::kMaxAcceleration);
  // Add kinematics to ensure max speed is actually obeyed
  config.SetKinematics(DriveConstants::kDriveKinematics);
  // Apply the voltage constraint
  config.AddConstraint(autoVoltageConstraint);

   auto exampleTrajectory = frc::TrajectoryGenerator::GenerateTrajectory(
      // Start at the origin facing the +X direction
      frc::Pose2d(0_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass through these two interior waypoints, making an 's' curve path
      {frc::Translation2d(1_m, 1_m), frc::Translation2d(2_m, -1_m)},
      // End 3 meters straight ahead of where we started, facing forward
      frc::Pose2d(3_m, 0_m, frc::Rotation2d(0_deg)),
      // Pass the config
      config);

      wpi::SmallString<64> deployDirectory;
      frc::filesystem::GetDeployDirectory(deployDirectory);
      wpi::sys::path::append(deployDirectory, "paths");
      wpi::sys::path::append(deployDirectory, "Zoom2.wpilib.json");

      frc::Trajectory trajectory = frc::TrajectoryUtil::FromPathweaverJson(deployDirectory);

      frc2::RamseteCommand ramseteCommand(
      exampleTrajectory, [this]() { return m_drivesubsystem.GetPose(); },
      frc::RamseteController(DriveConstants::kRamseteB,
                             DriveConstants::kRamseteZeta),
      frc::SimpleMotorFeedforward<units::meters>(
          DriveConstants::ks, DriveConstants::kv, DriveConstants::ka),
      DriveConstants::kDriveKinematics,
      [this] { return m_drivesubsystem.GetWheelSpeeds(); },
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      frc2::PIDController(DriveConstants::kPDriveVel, 0, 0),
      [this](auto left, auto right) { m_drivesubsystem.TankDriveVolts(left, right); },
      {&m_drivesubsystem});
  // no auto
  return new frc2::SequentialCommandGroup(
      std::move(ramseteCommand),
      frc2::InstantCommand([this] { m_drivesubsystem.TankDriveVolts(0_V, 0_V); }, {}));
      */
}

