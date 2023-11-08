/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/VisionTurretPID.h"
#include <frc/controller/PIDController.h>
#include <frc/smartdashboard/SmartDashboard.h>

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/latest/docs/software/commandbased/convenience-features.html
VisionTurretPID::VisionTurretPID(TurretSubsystem* turretsubsystem)
    : CommandHelper(frc2::PIDController(0.3, 0.000, 0.0),//0.0035
                    // This should return the measurement
                    [turretsubsystem] { return turretsubsystem->GetErr(); },
                    // This should return the setpoint (can also be a constant)
                    5.5,// frc::SmartDashboard::GetNumber("CalcTx",5.5),//0.0//Going to try custom value depending on other information,
                    // This uses the output
                    [turretsubsystem](double output) { turretsubsystem->TurnTurret(output);},

                    {turretsubsystem                   // Use the output here
                    }) {

                        m_controller.SetTolerance(0.5,0.0);
                        AddRequirements({turretsubsystem});

                    }

// Returns true when the command should end.
bool VisionTurretPID::IsFinished() { 
    //return (m_turretsubsystem->GetEncoders() > 5598) || (m_turretsubsystem->GetEncoders() < -5980) || m_controller.AtSetpoint();
    return m_controller.AtSetpoint();
}


void VisionTurretPID::End(bool interrupted){
    std::cout<<"FINISHED PID TURRET NONSENSE"<<std::endl;
      frc::SmartDashboard::PutString("end2", "THE turret IS FONE");

}
