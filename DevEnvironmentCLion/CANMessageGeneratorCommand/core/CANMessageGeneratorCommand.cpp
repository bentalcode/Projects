#include "PreCompiled.h"
#include "CANMessageGeneratorCommand.h"

using namespace controllerareanetwork::messagegeneratorcommand;

/**
 * Creates a new command.
 */
command::ICommandPtr CANMessageGeneratorCommand::make()
{
    return std::make_shared<CANMessageGeneratorCommand>();
}

/**
 * The CANMessageGeneratorCommand constructor.
 */
CANMessageGeneratorCommand::CANMessageGeneratorCommand()
{
}

/**
 * The CANMessageGeneratorCommand destructor.
 */
CANMessageGeneratorCommand::~CANMessageGeneratorCommand()
{
}

/**
 * Runs the logic of a command.
 */
void CANMessageGeneratorCommand::run()
{
}
