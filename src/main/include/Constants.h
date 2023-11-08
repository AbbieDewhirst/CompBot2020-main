/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/util/color.h>
#include <frc/kinematics/DifferentialDriveKinematics.h>
/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */
namespace OIConstants{
    constexpr int kDriverControllerPort = 0;
    constexpr int kOperatorControllerPort = 1;
    constexpr int kTestController2 = 2;
    constexpr int kTestController3 = 3;
    constexpr int kTestController4 = 4;
}
namespace PIDConstants{
    constexpr int kPIDLoopInd = 0;
    constexpr int kTimeoutMs = 30;
}
namespace DriveConstants {
    constexpr double kWheelCircumference = 19.63;//in inches
    constexpr double kEncoderTicksPerRotation = 2048;//in ticks
    constexpr double kGearRatio = 10;//10:1
    constexpr double kTolerance = 0.5; //in inches
    constexpr double kInchesToTicks = (kEncoderTicksPerRotation * kGearRatio / kWheelCircumference);
    
    constexpr auto ks = 0.208_V;
    constexpr auto kv = 0.0561 * 1_V * 1_s / 1_m;
    constexpr auto ka = 0.00567 * 1_V * 1_s * 1_s / 1_m;

    // Example value only - as above, this must be tuned for your drive!
    constexpr double kPDriveVel = 0.003;//1.06

    constexpr auto kTrackwidth = 0.00_m;
    extern const frc::DifferentialDriveKinematics kDriveKinematics;


    constexpr auto kMaxSpeed = 0.3_mps;//2.07
    constexpr auto kMaxAcceleration = 0.1_mps_sq;//2

    constexpr double kRamseteB = 2;
    constexpr double kRamseteZeta = 0.7;
    
}
namespace ShooterConstants{
}
namespace SHPIDConstants{
    constexpr int kPIDLoopInd = 0;
    constexpr int kTimeoutMs = 30;
    constexpr int kCruiseVel = 8000;
    constexpr int kCruiseAccl = 50;
}
namespace Measurement {
    constexpr int INCHES = 0;
    constexpr int CM = 1;
    constexpr int MM = 2; 
}
namespace ColourWheelConstants {
 static constexpr frc::Color kBlueTarget = frc::Color(0.37, 0.427, 0.20); // mdd record player 
 static constexpr frc::Color kGreenTarget = frc::Color(0.43, 0.48, 0.08); // mdd record player 
 static constexpr frc::Color kRedTarget = frc::Color(0.61, 0.31, 0.06); // mdd record player 
 static constexpr frc::Color kYellowTarget = frc::Color(0.53, 0.40, 0.05); // mdd record player 
 
 //static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429); Orig
// static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240); Orig
// static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114); // orig
// static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113); //orig
}



