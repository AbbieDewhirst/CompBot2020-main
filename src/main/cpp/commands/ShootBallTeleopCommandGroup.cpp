/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ShootBallTeleopCommandGroup.h"
#include "commands/GetToVelocityCommand.h"
#include "commands/ShooterForwardsCommand.h"
#include "commands/OrganizerMoveCommand.h"
#include "commands/ConveyorMoveCommand.h"
#include "subsystems/OrganizerSubsystem.h"
#include "commands/ShooterFeederCommand.h"
#include "commands/BallBlockerInCommand.h"
#include "commands/LightCurtainCounterCommand.h"
#include "commands/IntakeInCommand.h"
#include "frc2/command/ParallelCommandGroup.h"
#include "commands/TurretCommand.h"
#include "commands/TurnTurretSpecificAngleCommand.h"
#include "commands/LimelightOn.h"
#include "commands/IntakeSolInCommand.h"
#include "commands/IntakeSolOutCommand.h"
#include "commands/ShootertoZero.h"
#include "commands/WaitTimeCommand.h"
#include "commands/MoveAllInternalMotorsCommand.h"
#include "commands/VisionTurretPID.h"
#include "commands/IntakeSolOutCommand.h"
#include "commands/TurretVisionV2.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
ShootBallTeleopCommandGroup::ShootBallTeleopCommandGroup(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem, int velocity, bool usingVision) {
  l_velocity = velocity;
  l_usingvision = usingVision;
  AddCommands(
    LimelightOn(turretsubsystem, true),
    WaitTimeCommand(0.75),
    IntakeSolInCommand(conveyorsubsystem),
    GetToVelocityCommand(shootersubsystemPID, hoodsubsystem, turretsubsystem, l_velocity, l_usingvision), //was false but it should be true to adjust hood and flywheel speed
    TurretVisionV2(turretsubsystem),
    //VisionTurretPID(turretsubsystem), 
     MoveAllInternalMotorsCommand(shootersubsystemPID, conveyorsubsystem, organizersubsystem, turretsubsystem, hoodsubsystem)
     );
}