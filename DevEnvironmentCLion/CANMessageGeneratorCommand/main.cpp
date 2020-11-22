#include "PreCompiled.h"

#include "CommandHandler.h"
#include "CommandManifest.h"
#include "CANMessageGeneratorCommand.h"
#include "RandomGenerator.h"
#include "CommandHelpMetadata.h"

using namespace controllerareanetwork::messagegeneratorcommand;

static command::ICommandManifestPtr loadManifest();

int main(int argc, char *argv[])
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    command::ICommandManifestPtr manifest = loadManifest();
    command::ICommandHandlerPtr commandHandler = command::CommandHandler::make(manifest);
    command::ICommandPtr command = CANMessageGeneratorCommand::make();

    int exitCode = commandHandler->run(*command, argc, argv);

    return 0;
}

/**
 * Loads the manifest of the Controller Area Network.
 */
static command::ICommandManifestPtr loadManifest()
{
    std::string name = "Controller Area Network Message Generator Command";
    std::string description = "Controller Area Network Message Generator Command generates CAN messages.";
    std::string usageMessage = "CANMessageGenerator --driveSessionTime:=<600> --messagesFrequencies:=WHEEL_SPEEDS:100,BRAKE_MODULE:10";

    return command::CommandManifest::make(
        name,
        description,
        usageMessage);
}
