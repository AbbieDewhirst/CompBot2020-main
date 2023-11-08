/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/IntakeInCommand.h"
#include "subsystems/ConveyorSubsystem.h"
#include "frc/smartdashboard/SmartDashboard.h"

IntakeInCommand::IntakeInCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void IntakeInCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void IntakeInCommand::Execute() {
  m_conveyorsubsystem->IntakeMove(-1);

  bool index1 = frc::SmartDashboard::GetBoolean("index1", true);
  bool index2 = frc::SmartDashboard::GetBoolean("index2", true);
  bool index3 = frc::SmartDashboard::GetBoolean("index3", true);
  bool shooting = frc::SmartDashboard::GetBoolean("Shooting?",false);

  if(shooting){
     m_conveyorsubsystem->ConveyorMove(1.0);
     m_conveyorsubsystem->TopIndexMove(-1.0);
   }
   else
   {
      if (index1 == false && index2 == false && index3 == false) {
        m_conveyorsubsystem->ConveyorMove(0.5);
        m_conveyorsubsystem->TopIndexMove(-0.2);
      }
      else if (index1 == true && index2 == false && index3 == false){
        m_conveyorsubsystem->ConveyorMove(0.5);
        m_conveyorsubsystem->TopIndexMove(-0.2);
      } else if (index1 == false && index2 == false && index3 == true){
        m_conveyorsubsystem->ConveyorMove(0.5);
        m_conveyorsubsystem->TopIndexStop();
      } else if (index1 == false && index2 == true && index3 == true){
        m_conveyorsubsystem->ConveyorStop();
        m_conveyorsubsystem->TopIndexStop();
      } else if (index1 == true && index2 == true && index3== true){
        m_conveyorsubsystem->ConveyorStop();
        m_conveyorsubsystem->TopIndexStop();
      }
   }
  frc::SmartDashboard::PutString("Intake In", "Exe");
}

// Called once the command ends or is interrupted.
void IntakeInCommand::End(bool interrupted) {
  m_conveyorsubsystem->IntakeStop();
  m_conveyorsubsystem->ConveyorStop();
  m_conveyorsubsystem->TopIndexStop();
    frc::SmartDashboard::PutString("Intake In", "End");
}

// Returns true when the command should end.
bool IntakeInCommand::IsFinished() { return false; }
