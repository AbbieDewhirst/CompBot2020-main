#include "commands/ManualTurretCommand.h"
#include <iostream>

ManualTurretCommand::ManualTurretCommand(TurretSubsystem* manualTurretSubsystem, double speed) : m_Speed(speed), m_manualTurretSubsystem(manualTurretSubsystem) {

}

void ManualTurretCommand::Initialize() {
    // std::cout << m_Speed << std::endl;
}

void ManualTurretCommand::Execute() {
    m_manualTurretSubsystem->TurnTurret(m_Speed);
    // if(!((m_manualTurretSubsystem->GetEncoders() < -5598 && m_Speed < 0) || (m_manualTurretSubsystem->GetEncoders() > 5980 && m_Speed > 0))) m_manualTurretSubsystem->TurnTurret(m_Speed);
    // else m_manualTurretSubsystem->StopTurret();
    // if(m_manualTurretSubsystem->GetErr() < 2 && m_manualTurretSubsystem->GetErr() > -2) m_manualTurretSubsystem->SetLED(0,255,0);
    // else m_manualTurretSubsystem->SetLED(255,0,0);
}

void ManualTurretCommand::End(bool interrupted) {
    m_manualTurretSubsystem->StopTurret();
}

bool ManualTurretCommand::IsFinished() {
    // return false;
    // return true;
    return (m_manualTurretSubsystem->GetEncoders() > 5600 && m_Speed > 0) || (m_manualTurretSubsystem->GetEncoders() < -6000 && m_Speed < 0);
}