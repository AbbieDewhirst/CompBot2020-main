#include "subsystems/LEDSubsystem.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableInstance.h"

LEDSubsystem::LEDSubsystem() : canifier0{0}, canifier1{1} {
    auto dataInst = nt::NetworkTableInstance::GetDefault();
    auto LEDtable = dataInst.GetTable("datatable");
    canifier0ChannelA = LEDtable->GetEntry("canifier0ChannelA");
    canifier0ChannelB = LEDtable->GetEntry("canifier0ChannelB");
    canifier0ChannelC = LEDtable->GetEntry("canifier0ChannelC");
    canifier1ChannelA = LEDtable->GetEntry("canifier1ChannelA");
    canifier1ChannelB = LEDtable->GetEntry("canifier1ChannelB");
    canifier1ChannelC = LEDtable->GetEntry("canifier1ChannelC");
}

void LEDSubsystem::Periodic() {
    canifier0.SetLEDOutput(canifier0ChannelA.GetDouble(0),CANifier::LEDChannel::LEDChannelA);
    canifier0.SetLEDOutput(canifier0ChannelB.GetDouble(0),CANifier::LEDChannel::LEDChannelB);
    canifier0.SetLEDOutput(canifier0ChannelC.GetDouble(0),CANifier::LEDChannel::LEDChannelC);
    canifier1.SetLEDOutput(canifier1ChannelA.GetDouble(0),CANifier::LEDChannel::LEDChannelA);
    canifier1.SetLEDOutput(canifier1ChannelB.GetDouble(0),CANifier::LEDChannel::LEDChannelB);
    canifier1.SetLEDOutput(canifier1ChannelC.GetDouble(0),CANifier::LEDChannel::LEDChannelC);
}
