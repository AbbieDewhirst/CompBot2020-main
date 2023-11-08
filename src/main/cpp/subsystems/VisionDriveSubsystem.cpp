#include "subsystems/VisionDriveSubsystem.h"
#include "networktables/NetworkTable.h"
#include <iostream>

auto driveInst = nt::NetworkTableInstance::GetDefault();
auto driveLimeTable = driveInst.GetTable("limelight");

VisionDriveSubsystem::VisionDriveSubsystem() :
    dFrontLeft{4}, dFrontRight{8},
    leftMotors{dFrontLeft}, rightMotors{dFrontRight},
    drive{leftMotors,rightMotors} {
        
    dFrontLeft.SetInverted(false);
}

void VisionDriveSubsystem::Periodic() {
    // std::cout << driveUltrasonic.GetRangeInches() << std::endl;
}

void VisionDriveSubsystem::DriveWithVision() {
    double deadBand = 0.04;
    auto Limiter = [](double num, double maxNum, double minNum) 
    { return num < minNum ? minNum : num > maxNum ? maxNum : num; };    
    double turnErr = driveLimeTable->GetNumber("tx",0) * 0.2;
    double driveErr = (20 - driveLimeTable->GetNumber("ta",0)) * 0.2; 
    double numOfTargets = driveLimeTable->GetNumber("tv",0);

    if(abs(turnErr) < deadBand) turnErr = 0;
    if(abs(driveErr) < deadBand) driveErr = 0; 
    turnErr = Limiter(turnErr,0.4,-0.4);
    driveErr = Limiter(driveErr,0.4,-0.4);

    //Turning and driving
    if(numOfTargets) drive.ArcadeDrive(driveErr,turnErr);
    else drive.ArcadeDrive(0,0);
}

void VisionDriveSubsystem::StopDrive() {
    drive.ArcadeDrive(0,0);
}
