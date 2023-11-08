/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/ExtendIntakeandGrabBallsCommand.h"
#include "commands/IntakeInCommand.h"
#include "commands/IntakeSolInCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>

//This command will extend the intake and start picking up balls. Meant for a while held commmand for the driver

ExtendIntakeandGrabBallsCommand::ExtendIntakeandGrabBallsCommand(ConveyorSubsystem* conveyorsubsystem) : m_conveyorsubsystem(conveyorsubsystem) {
  // Use addRequirements() here to declare subsystem dependencies.
}

// Called when the command is initially scheduled.
void ExtendIntakeandGrabBallsCommand::Initialize() {

  m_conveyorsubsystem->IntakeIn();
  intaketime.Start();
  l_intakeSpeed = -0.7;
  l_intakeOGSpeed = l_intakeSpeed;
  l_intakeInverted = false;
}

// Called repeatedly when this Command is scheduled to run
void ExtendIntakeandGrabBallsCommand::Execute() {

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
  bool index1 = frc::SmartDashboard::GetBoolean("index1", true);
  bool index2 = frc::SmartDashboard::GetBoolean("index2", true);
  bool index3 = frc::SmartDashboard::GetBoolean("index3", true);
  bool shooting = frc::SmartDashboard::GetBoolean("Shooting?",false);


  /* INDEXING WITH ONLY 1 SENSOR
      if (index2 == true && shooting == false)
      {
        m_conveyorsubsystem->ConveyorMove(0.30);
      }
      else if (index2 == true && shooting == true)
      {
        m_conveyorsubsystem->ConveyorMove(0.75);
      }
      else if (index2 == false && shooting == false)
      {
        m_conveyorsubsystem->ConveyorStop();
      }
      else if (index2 == false && shooting == true)
      {
        m_conveyorsubsystem->ConveyorMove(0.75);
      }
      //index2 is false when there is a ball
      //index 2 is true where there isnt a ball

      //Shooting is true when we are shooting
    
      // If we don't ahve a ball and we're not shooting run conveyor at 30%
      //If we don't have a ball and we're are shooting do nothing run at shooting percentage
      // if we have a ball and we are not shooting, stop conveyor
      //if we have a bvall and are shooting, run at shooting percentage


  */


    /********************************************
    Writing out logic for 3 ball indexing system during teleop

    Sensor 1 at mouth of chimney
    Sensor 2 at base of chimney
    Sensor 3 at top of chimney

    If we are shooting, set conveyor to shooting speed

    If we aren't shooting:


    If No Balls
        If 3 - Stop Top Chimney Motor
        If no 3 - Run Top Chimney Motor

        if 3 and 2 - Stop All Chimney Motors
        If 3 and 2 and 1 and no ball indexed in 1 - turn motor a little

    ******************************************************/

   if(shooting){
     m_conveyorsubsystem->ConveyorMove(1.0);
     m_conveyorsubsystem->TopIndexMove(-1.0);
     l_inIndex1 = false;
     l_count = 0;
   }
   else
   {
      if (index1 == false && index2 == false && index3 == false) {
        m_conveyorsubsystem->ConveyorMove(0.3);
        m_conveyorsubsystem->TopIndexMove(-0.3);
      }
      else if (index1 == true && index2 == false && index3 == false){
        m_conveyorsubsystem->ConveyorMove(0.3);
        m_conveyorsubsystem->TopIndexMove(-0.3);
      } else if (index1 == false && index2 == false && index3 == true){
        m_conveyorsubsystem->ConveyorMove(0.3);
        m_conveyorsubsystem->TopIndexStop();
      } else if (index1 == false && index2 == true && index3 == true){
        m_conveyorsubsystem->ConveyorStop();
        m_conveyorsubsystem->TopIndexStop();
      } else if (index1 == true && index2 == true && index3== true && l_inIndex1 == false){

        // if (l_count >= 10){
        //     m_conveyorsubsystem->ConveyorMove(0.3);
        // }
        // if (l_count > 16){
          l_inIndex1 = true;
        // }
        
        // l_count ++;
        // std::cout<<"l_count =" << l_count << std::endl;
        
       

      } else if (index1 == true && index2 == true && index3== true && l_inIndex1 == true){
        m_conveyorsubsystem->ConveyorStop();
        m_conveyorsubsystem->TopIndexStop();
      }

      

     
   }

   frc::SmartDashboard::PutBoolean("IsIndexed?",l_inIndex1);
   
}
   


    

// Called once the command ends or is interrupted.
void ExtendIntakeandGrabBallsCommand::End(bool interrupted) {

  m_conveyorsubsystem->IntakeStop();
  m_conveyorsubsystem->IntakeOut();
  m_conveyorsubsystem->ConveyorStop();
  intaketime.Stop();
  intaketime.Reset();
}

// Returns true when the command should end.
bool ExtendIntakeandGrabBallsCommand::IsFinished() { return false; }
