#pragma once

#include <frc2/command/SubsystemBase.h>
#include "ctre/Phoenix.h"
#include "frc/Ultrasonic.h"

#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"
#include <frc2/command/PIDSubsystem.h>

class TurretSubsystem : public frc2::PIDSubsystem {
    public:
        TurretSubsystem();
        void Periodic() override;
        void TurnTurret(double speed);
        void StopTurret();
        void SetTurret(double pos);
        void VisionTurret();
        double GetErr();
        double GetEncoders();
        double FindDistance(int measurement);
        void SetLED(float r, float g, float b);
        void LimelightOn();
        void LimelightOff();
        int GetCurrentSpeed();
        bool isTarget();
        nt::NetworkTableEntry turretLEDChannelA;
        nt::NetworkTableEntry turretLEDChannelB;
        nt::NetworkTableEntry turretLEDChannelC;
        void CalculateTx();

    private:
        // std::shared_ptr<NetworkTable> limetable = NetworkTable::GetTable("limelight");
        TalonSRX turretMotor {6};
        // CANifier canifier;
        MovingAverage averageR {20};
        MovingAverage averageG {20};
        MovingAverage averageB {20};
        frc::Ultrasonic ultra{1,0};

    
    protected:
        void UseOutput(double output, double setpoint) override;

        double GetMeasurement() override;
};