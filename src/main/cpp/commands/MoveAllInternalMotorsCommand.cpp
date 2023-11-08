/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/MoveAllInternalMotorsCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>

MoveAllInternalMotorsCommand::MoveAllInternalMotorsCommand(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, TurretSubsystem* turretsubsystem, HoodSubsystem* hoodsubsystem) : m_shootersubsystemPID(shootersubsystemPID), m_conveyorsubsystem(conveyorsubsystem), m_organizersubsystem(organizersubsystem), m_turretsubsystem(turretsubsystem), m_hoodsubsystem(hoodsubsystem){
  // Use addRequirements() here to declare subsystem dependencies.

}

// Called when the command is initially scheduled.
void MoveAllInternalMotorsCommand::Initialize() {
  l_inShooting = true;
  frc::SmartDashboard::PutBoolean("Shooting?",l_inShooting);
  l_conveyorInverted = false;
  l_organizerInverted = false;
  l_conveyorSpeed = 0.5;
  l_conveyorOGSpeed = l_conveyorSpeed;
  l_organizerSpeed = 0.5;
  l_organizerOGSpeed = l_organizerSpeed;
  l_intakeSpeed = -0.5;
  l_intakeOGSpeed = l_intakeSpeed;
  l_intakeInverted = false;
  conveyortime.Start();
  organizertime.Start();
  intaketime.Start();
  m_turretsubsystem->StopTurret();
}

// Called repeatedly when this Command is scheduled to run
void MoveAllInternalMotorsCommand::Execute() {
  //  m_shootersubsystemPID->shooterFeederSpeed(-1.0);
  m_conveyorsubsystem->TopIndexMove(-1);
   m_turretsubsystem->StopTurret();
  


  //Conveyor Anti Jam Code

  if(conveyortime.Get() > 0.5 && m_conveyorsubsystem->GetConveyorCurrent() > 52 && !l_conveyorInverted)
  {
    frc::SmartDashboard::PutNumber("conveyor current", m_conveyorsubsystem->GetConveyorCurrent());
    std::cout<<"WE ARE TRYING TO INVERT THE CONVEYOR "<<std::endl;
    l_conveyorInverted = true;
    conveyortime.Reset();
    l_conveyorSpeed = -l_conveyorSpeed;
  }

  m_conveyorsubsystem->ConveyorMove(l_conveyorSpeed);

  if(conveyortime.HasPeriodPassed(0.5) && l_conveyorOGSpeed != l_conveyorSpeed)
  {
    l_conveyorSpeed = l_conveyorOGSpeed;
    l_conveyorInverted = false;
    conveyortime.Reset();
  }

  //Organizer Anti Jam Code
  if(organizertime.Get() > 0.5 && m_organizersubsystem->GetOrganizerCurrent() > 10 && !l_organizerInverted)
  {
    
    l_organizerInverted = true;
    organizertime.Reset();
    l_organizerSpeed = -l_organizerSpeed;
  }

  m_organizersubsystem->OrganizerMove(l_organizerSpeed);

  if(organizertime.HasPeriodPassed(0.5) && l_organizerOGSpeed != l_organizerSpeed)
  {
    l_organizerSpeed = l_organizerOGSpeed;
    l_organizerInverted = false;
    organizertime.Reset();
  }

  //Intake Anti Jam Code

   if(intaketime.Get() > 0.5 && m_conveyorsubsystem->GetIntakeCurrent() > 25 && !l_intakeInverted)
  {
    l_intakeInverted = true;
    intaketime.Reset();
    l_intakeSpeed = -l_intakeSpeed;
  }

  m_conveyorsubsystem->IntakeMove(l_intakeSpeed);

  if(intaketime.HasPeriodPassed(0.5) && l_intakeOGSpeed != l_intakeSpeed)
  {
    l_intakeSpeed = l_intakeOGSpeed;
    l_intakeInverted = false;
    intaketime.Reset();
  }
}

// Called once the command ends or is interrupted.
void MoveAllInternalMotorsCommand::End(bool interrupted) {
  l_inShooting = false;
  frc::SmartDashboard::PutBoolean("Shooting?",l_inShooting);
  m_shootersubsystemPID->FlywheelSTOP();
  m_organizersubsystem->OrganizerStop();
  m_conveyorsubsystem->ConveyorStop();
  // m_shootersubsystemPID->shooterFeederStop();
  m_conveyorsubsystem->TopIndexStop();
  l_conveyorSpeed = l_conveyorOGSpeed;
  l_organizerSpeed = l_organizerOGSpeed;
  conveyortime.Stop();
  conveyortime.Reset();
  organizertime.Stop();
  organizertime.Reset();
  intaketime.Stop();
  intaketime.Reset();
}

// Returns true when the command should end.
bool MoveAllInternalMotorsCommand::IsFinished() { return false; }
