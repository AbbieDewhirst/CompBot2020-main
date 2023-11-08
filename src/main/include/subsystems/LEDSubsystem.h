#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"

class LEDSubsystem : public frc2::SubsystemBase {
    public:
        LEDSubsystem();
        void Periodic() override;
        nt::NetworkTableEntry canifier0ChannelA;
        nt::NetworkTableEntry canifier0ChannelB;
        nt::NetworkTableEntry canifier0ChannelC;
        nt::NetworkTableEntry canifier1ChannelA;
        nt::NetworkTableEntry canifier1ChannelB;
        nt::NetworkTableEntry canifier1ChannelC;
    private:
        CANifier canifier0;
        CANifier canifier1;
};