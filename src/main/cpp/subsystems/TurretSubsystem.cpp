#include "subsystems/TurretSubsystem.h"
#include "Constants.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "ctre/Phoenix.h"
#include <cmath>
#include "frc/smartdashboard/SmartDashboard.h"

auto inst = nt::NetworkTableInstance::GetDefault();
auto limetable = inst.GetTable("limelight");
double ty;
double ts;
double flywheelSpeed;
double hoodAngle;
double CalcTx;
TurretSubsystem::TurretSubsystem() : PIDSubsystem(
          // The PIDController used by the subsystem
          frc2::PIDController(0, 0, 0)) { 
    
	turretMotor.ConfigFactoryDefault();
	// frc::SmartDashboard::PutNumber("CalcHoodEncoder", 0.0);
	// frc::SmartDashboard::PutNumber("CalcFlywheelSpeed", 0.0);
		


	// /* lets grab the 360 degree position of the MagEncoder's absolute position */

	//int absolutePosition = turretMotor.GetSelectedSensorPosition(0) & 0xFFF; /* mask out the bottom12 bits, we don't care about the wrap arounds */

	// /* use the low level API to set the quad encoder signal */
	turretMotor.ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative, PIDConstants::kPIDLoopInd, PIDConstants::kTimeoutMs);

	// turretMotor.SetSelectedSensorPosition(absolutePosition, PIDConstants::kPIDLoopInd, PIDConstants::kTimeoutMs);
	turretMotor.SetSelectedSensorPosition(0, 0, 10);
	
	turretMotor.SetNeutralMode(NeutralMode::Brake);

	// /* choose the sensor and sensor direction */



	turretMotor.SetSensorPhase(false);
	turretMotor.SetInverted(false);



	/* set the peak and nominal outputs, 12V means full */

	turretMotor.ConfigNominalOutputForward(0, PIDConstants::kTimeoutMs);

	turretMotor.ConfigNominalOutputReverse(0, PIDConstants::kTimeoutMs);

	turretMotor.ConfigPeakOutputForward(1.0, PIDConstants::kTimeoutMs);

	turretMotor.ConfigPeakOutputReverse(-1.0, PIDConstants::kTimeoutMs);



	/* set closed loop gains in slot0 */

	turretMotor.Config_kF(PIDConstants::kPIDLoopInd, 1.0, PIDConstants::kTimeoutMs);

	turretMotor.Config_kP(PIDConstants::kPIDLoopInd, 1.0, PIDConstants::kTimeoutMs);//was 0.4

	turretMotor.Config_kI(PIDConstants::kPIDLoopInd, 0.00, PIDConstants::kTimeoutMs); // was 0.004

	turretMotor.Config_kD(PIDConstants::kPIDLoopInd, 0.0, PIDConstants::kTimeoutMs);

	auto datatable = inst.GetTable("datatable");

	turretMotor.SetSelectedSensorPosition(0); //added by mdd to make sure the power on location is considered zero.
	
	// std::shared_ptr<NetworkTable> limetable = NetworkTable::GetTable("limelight");

	// errXEntry = limetable->GetEntry("tx");
	// taEntry = limetable->GetEntry("ta");
	// tvEntry = limetable->GetEntry("tv");
	turretLEDChannelA = datatable->GetEntry("canifier0ChannelA");
	turretLEDChannelB = datatable->GetEntry("canifier0ChannelB");
	turretLEDChannelC = datatable->GetEntry("canifier0ChannelC");

}

void TurretSubsystem::Periodic() {
    frc::SmartDashboard::PutNumber("Turret Enc", GetEncoders());

	// xEntry.SetDouble(x);
    // yEntry.SetDouble(y);
	// x1Entry.SetDouble(xEntry.GetDouble(0) + 100);
	// y1Entry.SetDouble(yEntry.GetDouble(0) + 100);
    // x += 0.05;
    // y += 0.05;

	ty = limetable->GetNumber("ty",0);
	ts = limetable->GetNumber("ts",0) / 90.0;

	
	if (ty > -5.0)// middle of trench
	{
		hoodAngle = 1400;
	}
	else
	{
		hoodAngle = -66.289 * ty + 0.2;
	}


	//hoodAngle = -988.832 * ty + 1589.21;


	flywheelSpeed = 20300;
	frc::SmartDashboard::PutNumber("CalcFlywheelSpeed", flywheelSpeed);
	frc::SmartDashboard::PutNumber("CalcHoodEncoder", hoodAngle);

	// errX = limetable->GetNumber("tx",0) * -0.2;
	// std::cout << ultra.GetRangeInches() << std::endl;
}

void TurretSubsystem::TurnTurret(double speed) {
    turretMotor.Set(ControlMode::PercentOutput,speed);
}
void TurretSubsystem::SetTurret(double pos) {
	 turretMotor.Set(ControlMode::Position,pos);
	//turretMotor.Set(ControlMode::MotionMagic, pos);
}

void TurretSubsystem::StopTurret() {
    turretMotor.Set(ControlMode::PercentOutput,0.0);
}

void TurretSubsystem::VisionTurret() {
	double errX = limetable->GetNumber("tx",0.01) * -0.13; //was 0.17
	// double ty = table->GetNumber("ty",0);
	// double ta = table->GetNumber("ta",0);
	// double tv = table->GetNumber("tv",0);
	frc::SmartDashboard::PutNumber("Turret Motor Speed", turretMotor.GetSelectedSensorVelocity(0));
	turretMotor.Set(ControlMode::PercentOutput,std::min(0.6,std::max(-0.6,errX)));//.35 before .45 before//was 0.6 and -0.6
}

double TurretSubsystem::GetErr() {
	return limetable->GetNumber("tx",0.0);
}

double TurretSubsystem::GetEncoders() {
	return turretMotor.GetSelectedSensorPosition();
}

double TurretSubsystem::FindDistance(int measurement) {
	return 0.0;
}

void TurretSubsystem::SetLED(float r, float g, float b) {

	// canifier.SetLEDOutput(r,CANifier::LEDChannel::LEDChannelB);
	// canifier.SetLEDOutput(g,CANifier::LEDChannel::LEDChannelA);
	// canifier.SetLEDOutput(b,CANifier::LEDChannel::LEDChannelC);
	turretLEDChannelA.SetDouble(g);
	turretLEDChannelB.SetDouble(r);
	turretLEDChannelC.SetDouble(b);

}

void TurretSubsystem::LimelightOff() {
	limetable->PutNumber("ledMode",1);
}

void TurretSubsystem::LimelightOn() {
	limetable->PutNumber("ledMode",3);
}

int TurretSubsystem::GetCurrentSpeed(){
	return turretMotor.GetSelectedSensorVelocity(0);

}

void TurretSubsystem::UseOutput(double output, double setpoint) {
  // Use the output here
  turretMotor.Set(ControlMode::PercentOutput, output);
}

double TurretSubsystem::GetMeasurement() {
	return limetable->GetNumber("tx",0.0);
  // Return the process variable measurement here
}

void TurretSubsystem::CalculateTx(){

  ts = limetable->GetNumber("ts",0);


	CalcTx = 5.5;
	frc::SmartDashboard::PutNumber("CalcTx", CalcTx);

//   if (ts > -50.0){
//     ts = ts/12.0;
//     CalcTx = -2.6 * ts; //+ .321;
//     frc::SmartDashboard::PutNumber("CalcTx", CalcTx);
//   }
//   else{
//     ts = ts/90.0;
//     CalcTx = -23.160 * ts - 21.92;
//     frc::SmartDashboard::PutNumber("CalcTx", CalcTx);
//   }
}

bool TurretSubsystem::isTarget(){
	return limetable->GetNumber("tv", 0.0);
}

