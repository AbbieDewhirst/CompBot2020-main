#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TurretSubsystem.h"

class ManualTurretCommand : public frc2::CommandHelper<frc2::CommandBase, ManualTurretCommand> {
    public:
        ManualTurretCommand(TurretSubsystem* manualTurretSubsystem, double speed);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;
    private:
        double m_Speed;
        TurretSubsystem* m_manualTurretSubsystem;
        
};