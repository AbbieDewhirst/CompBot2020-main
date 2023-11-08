/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/LightCurtainCounterCommand.h"
#include "subsystems/ShooterSubsystemPID.h"
#include <frc/smartdashboard/smartdashboard.h>
#include "subsystems/ConveyorSubsystem.h"
#include "subsystems/OrganizerSubsystem.h"

int countedballcountdown =25;
bool alreadysawball = false;

LightCurtainCounterCommand::LightCurtainCounterCommand(ShooterSubsystemPID* shootersubsystemPID, ConveyorSubsystem* conveyorsubsystem, OrganizerSubsystem* organizersubsystem, TurretSubsystem* turretsubsystem, HoodSubsystem* hoodsubsystem, int lookforball) : m_shootersubsystemPID(shootersubsystemPID), m_conveyorsubsystem(conveyorsubsystem), m_organizersubsystem(organizersubsystem), m_turretsubsystem(turretsubsystem), m_hoodsubsystem(hoodsubsystem){
  // Use addRequirements() here to declare subsystem dependencies.
  l_lookforball = lookforball;
  
}

// Called when the command is initially scheduled.
void LightCurtainCounterCommand::Initialize() {
  countedballcountdown = l_lookforball;
  frc::SmartDashboard::PutBoolean("Shooting?",true);
  alreadysawball = false;
  l_conveyorInverted = false;
  l_organizerInverted = false;
  l_conveyorSpeed = 0.75;
  l_conveyorOGSpeed = l_conveyorSpeed;
  l_organizerSpeed = -0.5;
  l_organizerOGSpeed = l_organizerSpeed;
  l_intakeSpeed = -0.5;
  l_intakeOGSpeed = l_intakeSpeed;
  l_intakeInverted = false;
  conveyortime.Start();
  organizertime.Start();
  intaketime.Start();

  frc::SmartDashboard::PutNumber("CBC", countedballcountdown);
  frc::SmartDashboard::PutNumber("LFB", l_lookforball);

    frc::SmartDashboard::PutString("Light cutrian", "Init");

    // m_shootersubsystemPID->FlywheelMove(14000);
    m_conveyorsubsystem->TopIndexMove(-1);
    m_conveyorsubsystem->ConveyorMove(0.5);
    m_organizersubsystem->OrganizerMove(-0.3);
    m_conveyorsubsystem->IntakeMove(-0.5);

}

// Called repeatedly when this Command is scheduled to run
void LightCurtainCounterCommand::Execute() {

    m_conveyorsubsystem->IntakeMove(-0.5);
  m_conveyorsubsystem->TopIndexMove(-1);

  //Conveyor Anti Jam Code
  if(conveyortime.Get() > 0.5 && m_conveyorsubsystem->GetConveyorCurrent() > 30 && !l_conveyorInverted)
  {
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
  if(organizertime.Get() > 0.5 && m_organizersubsystem->GetOrganizerCurrent() > 15 && !l_organizerInverted)
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


    frc::SmartDashboard::PutString("Light cutrian", "Exe");
  if (!alreadysawball && m_shootersubsystemPID->LookForNextBall()) { 
  frc::SmartDashboard::PutString("Status", "SAW Ball");
  // countedballcountdown--;
  alreadysawball = true;
  frc::SmartDashboard::PutNumber("CBC", countedballcountdown);
  frc::SmartDashboard::PutNumber("LFB", l_lookforball);
  std::cout<<"counted ball countdown "<< countedballcountdown<<std::endl;
}
else if (alreadysawball && m_shootersubsystemPID->LookForNextBall())
{
frc::SmartDashboard::PutString("Status", "Looking This is the same Ball");
  frc::SmartDashboard::PutNumber("CBC", countedballcountdown);
  frc::SmartDashboard::PutNumber("LFB", l_lookforball);

}
else if (alreadysawball && !m_shootersubsystemPID->LookForNextBall())
{ 
  frc::SmartDashboard::PutString("Status", "Looking for Counted Ball");
  alreadysawball = false;
  countedballcountdown--;
  frc::SmartDashboard::PutNumber("CBC", countedballcountdown);
  frc::SmartDashboard::PutNumber("LFB", l_lookforball);
}



}


// Called once the command ends or is interrupted.
void LightCurtainCounterCommand::End(bool interrupted) {
  frc::SmartDashboard::PutString("Status", "FOUND Counted Ball End");
  frc::SmartDashboard::PutString("Light cutrian", "End");
  frc::SmartDashboard::PutNumber("CBC", countedballcountdown);
  frc::SmartDashboard::PutNumber("LFB", l_lookforball);
  frc::SmartDashboard::PutBoolean("Shooting?",false);
  m_shootersubsystemPID->FlywheelSTOP();
  m_conveyorsubsystem->ConveyorStop();
  m_organizersubsystem->OrganizerStop();
  m_conveyorsubsystem->IntakeStop();
  m_conveyorsubsystem->TopIndexStop();
  l_conveyorSpeed = l_conveyorOGSpeed;
  l_organizerSpeed = l_organizerOGSpeed;
  conveyortime.Stop();
  conveyortime.Reset();
  organizertime.Stop();
  organizertime.Reset();
  intaketime.Stop();
  intaketime.Reset();


  //Turns limelight off when command is finished.
  //m_turretsubsystem->LimelightOff();
  //m_hoodsubsystem->GoToHoodPos(0);
  //m_turretsubsystem->SetTurret(0);
  
}

// Returns true when the command should end.
bool LightCurtainCounterCommand::IsFinished() { 
  if (countedballcountdown == 0) return true;
  else return false;
 }
