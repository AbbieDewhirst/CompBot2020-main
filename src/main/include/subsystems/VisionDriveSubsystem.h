#pragma once

#include "frc2/command/SubsystemBase.h"
#include "frc/drive/DifferentialDrive.h"
#include "frc/SpeedControllerGroup.h"
#include "ctre/Phoenix.h"
#include "frc/Ultrasonic.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

class VisionDriveSubsystem : public frc2::SubsystemBase {
    public:
        VisionDriveSubsystem();
        void Periodic() override;
        void DriveWithVision();
        void StopDrive();
    private:
        WPI_TalonFX dFrontLeft;
        // WPI_TalonFX dBackLeft;
        WPI_TalonFX dFrontRight;
        // WPI_TalonFX dBackRight;
        frc::SpeedControllerGroup leftMotors;
        frc::SpeedControllerGroup rightMotors;
        frc::DifferentialDrive drive;
        // std::shared_ptr<NetworkTable> tableForDrive = NetworkTable::GetTable("limelight");
};