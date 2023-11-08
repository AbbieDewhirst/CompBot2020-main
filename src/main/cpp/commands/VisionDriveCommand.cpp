#include "commands/VisionDriveCommand.h"
#include <iostream>

VisionDriveCommand::VisionDriveCommand(VisionDriveSubsystem* visionDriveSubsystem) : m_visiondrivesubsystem(visionDriveSubsystem) {}

void VisionDriveCommand::Initialize() {

}

void VisionDriveCommand::Execute() {
    m_visiondrivesubsystem->DriveWithVision(); 
}

void VisionDriveCommand::End(bool interrupted) {
    m_visiondrivesubsystem->StopDrive();
}

bool VisionDriveCommand::IsFinished() {
    return false;
}
