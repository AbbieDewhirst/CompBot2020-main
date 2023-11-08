#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>
#include "subsystems/VisionDriveSubsystem.h"

class VisionDriveCommand : public frc2::CommandHelper<frc2::CommandBase, VisionDriveCommand> {
    public:
        VisionDriveCommand(VisionDriveSubsystem* visionDriveSubsystem);
        void Initialize() override;
        void Execute() override;
        bool IsFinished() override;
        void End(bool interrupted) override;
    private:
        VisionDriveSubsystem* m_visiondrivesubsystem;
};