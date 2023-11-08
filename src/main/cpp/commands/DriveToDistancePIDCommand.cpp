/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveToDistancePIDCommand.h"
#include <frc/controller/PIDController.h>
#include "Constants.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
DriveToDistancePIDCommand::DriveToDistancePIDCommand(DriveSubsystem* driveSubsystem ,double distance)
    : CommandHelper(frc2::PIDController(1, 0, 0),
    // Close loop on heading
                    [driveSubsystem] { return driveSubsystem->GetAverageEncoderDistance(); },
                    // Set reference to target
                    driveSubsystem->GetAverageEncoderDistance() + distance* DriveConstants::kInchesToTicks,
                    // Pipe output to turn robot
                    [driveSubsystem](double output) { driveSubsystem->Drive(output, 0); },
                    // Require the drive
                    {driveSubsystem}) {

  m_controller.SetTolerance(1000.0,
                            100.0);

  AddRequirements({driveSubsystem});
}

// Returns true when the command should end.
bool DriveToDistancePIDCommand::IsFinished() { return GetController().AtSetpoint(); }
