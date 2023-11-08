#pragma once

#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

#include "subsystems/TurretSubsystem.h"

/**
 * An example command that uses an example subsystem.
 *
 * <p>Note that this extends CommandHelper, rather extending CommandBase
 * directly; this is crucially important, or else the decorator functions in
 * Command will *not* work!
 */
class TurretCommand
    : public frc2::CommandHelper<frc2::CommandBase, TurretCommand> {
 public:

  TurretCommand(TurretSubsystem* turretSubsystem);
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End(bool interrupted) override;

 private:
  TurretSubsystem* m_turretsubsystem;
};
