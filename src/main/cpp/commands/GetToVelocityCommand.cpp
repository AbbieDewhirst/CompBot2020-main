/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/GetToVelocityCommand.h"
#include "subsystems/ShooterSubsystemPID.h"
#include "subsystems/HoodSubsystem.h"
#include "subsystems/TurretSubsystem.h"
#include <frc/smartdashboard/SmartDashboard.h>

GetToVelocityCommand::GetToVelocityCommand(ShooterSubsystemPID* shootersubsystemPID, HoodSubsystem* hoodsubsystem, TurretSubsystem* turretsubsystem,  double velocity, bool usingVision) : m_shootersubsystem(shootersubsystemPID),m_hoodsubsystem(hoodsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
  l_velocity = velocity;
  l_usingvision = usingVision;
}

// Called when the command is initially scheduled.
void GetToVelocityCommand::Initialize() {
  if(l_usingvision){
    //m_hoodsubsystem->GoToHoodPosCalc();
  }
}

// Called repeatedly when this Command is scheduled to run
void GetToVelocityCommand::Execute() {
  if(!l_usingvision){
    m_shootersubsystem->FlywheelMove(l_velocity);
  } else{
    m_hoodsubsystem->GoToHoodPosCalc();
    //m_shootersubsystem->FlywheelZoom();
    m_shootersubsystem->ShooterSpeedCalc();
    m_turretsubsystem->CalculateTx();
  }
}

// Called once the command ends or is interrupted.
void GetToVelocityCommand::End(bool interrupted) {
  // m_shootersubsystem->FlywheelSTOP();
  frc::SmartDashboard::PutString("end", "THE VEOLCOTIY IS FONE");}

// Returns true when the command should end.
bool GetToVelocityCommand::IsFinished() { 
  if (m_shootersubsystem->GetVelocityDerivative() < 1200 && m_shootersubsystem->GetVelocity() > 8000){
  //if(m_shootersubsystem->GetVelocity() > (m_shootersubsystem->ShooterCalculatedVelocity()-200)) {
  //if(m_shootersubsystem->GetVelocity() > l_velocity - 200){
      return true;
  }else{
    return false;
  }
}
