#include "commands/TurretCommand.h"
#include <iostream>
#include "Constants.h"

TurretCommand::TurretCommand(TurretSubsystem* turretSubsystem) : m_turretsubsystem(turretSubsystem) {}

void TurretCommand::Initialize() {
    //Turns limelight on when targetting with vision
    //m_turretsubsystem->LimelightOn();

}

void TurretCommand::Execute() {
    m_turretsubsystem->VisionTurret();
    m_turretsubsystem->SetLED(255,0,0);
    // m_turretsubsystem->SetLED(180,100,100);
    // std::cout << m_turretsubsystem->FindDistance(Measurement::INCHES) << std::endl;
}

void TurretCommand::End(bool interrupted) {
    m_turretsubsystem->StopTurret(); 
    m_turretsubsystem->SetLED(0,255,0);
    std::cout <<"ENDDDDDDDDDDD" << std::endl;
}

bool TurretCommand::IsFinished() {
    //return ((m_turretsubsystem->GetEncoders() > 5598 && m_turretsubsystem->GetErr() < 0) || (m_turretsubsystem->GetEncoders() < -5980 && m_turretsubsystem->GetErr() > 0)); //|| (m_turretsubsystem->GetErr() < 0.5 && m_turretsubsystem->GetErr() > -0.5);
    // return m_turretsubsystem->GetEncoders() > 5598 || m_turretsubsystem->GetEncoders() < -5980;
    //Adding Comment
    if (m_turretsubsystem->GetCurrentSpeed() == 0 && m_turretsubsystem->GetErr() > -1.0 && m_turretsubsystem->GetErr() < 1.0){
    //if((m_turretsubsystem->GetEncoders() > 5598 || m_turretsubsystem->GetEncoders() < -5980) || ((m_turretsubsystem->GetCurrentSpeed() == 0) && ((m_turretsubsystem->GetErr() > -0.6) && (m_turretsubsystem->GetErr() < 0.6)))) {
        return true;
    }else{
        return false;
    }
}