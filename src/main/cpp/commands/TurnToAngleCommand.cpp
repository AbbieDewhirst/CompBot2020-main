/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

//https://docs.wpilib.org/en/latest/docs/software/commandbased/pid-subsystems-commands.html

#include "commands/TurnToAngleCommand.h"
#include <frc/controller/PIDController.h>
#include "frc/smartdashboard/SmartDashboard.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
TurnToAngleCommand::TurnToAngleCommand(DriveSubsystem* driveSubsystem, units::degree_t target)
    : CommandHelper(frc2::PIDController(0.1, 0.0000, 0),

 // Close loop on heading
                    [driveSubsystem] { 
                      frc::SmartDashboard::PutNumber("Angle to turn", driveSubsystem->GetGyroAngle());
                      return driveSubsystem->GetGyroAngle(); 
                    },
                    // Set reference to target
                    target.to<double>(),
                    // Pipe output to turn robot
                    [driveSubsystem](double output) { 
                      driveSubsystem->Drive(0, -output);
                      frc::SmartDashboard::PutNumber("Speed to turn at", -output);
                    },
                    // Require the drive
                    {driveSubsystem}) {
  // Set the controller to be continuous (because it is an angle controller)
  //m_controller.EnableContinuousInput(-180, 180);
  // Set the controller tolerance - the delta tolerance ensures the robot is
  // stationary at the setpoint before it is considered as having reached the
  // reference
  // m_controller.SetTolerance(kTurnTolerance.to<double>(),
  //                           kTurnRateTolerance.to<double>());

  m_controller.SetTolerance(0.5,//first value position error - within 10 degrees
                            0.0);//second value velocity error near 0 - speed that you want to be at when you are there

  AddRequirements({driveSubsystem});
}
// Returns true when the command should end.
bool TurnToAngleCommand::IsFinished() {

  return m_controller.AtSetpoint();
 }

void TurnToAngleCommand::End(bool interrupted){
      std::cout<<"FINISHED TURN" << std::endl; 
}