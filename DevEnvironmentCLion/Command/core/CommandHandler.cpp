#include "PreCompiled.h"
#include "CommandHandler.h"
#include "CommandException.h"
#include "CommandParser.h"
#include "CommandMessageWriter.h"
#include "CommandConstants.h"

using namespace command;

/**
 * Creates a new command handler.
 */
ICommandHandlerSharedPtr CommandHandler::make(ICommandManifestSharedPtr manifest)
{
    return std::make_shared<CommandHandler>(manifest);
}

/**
 * The CommandHandler constructor.
 */
CommandHandler::CommandHandler(
    ICommandManifestSharedPtr manifest) :
    m_manifest(manifest)
{
    if (!manifest)
    {
        std::string errorMessage = "The manifest of the command is not defined.";
        throw CommandException(errorMessage);
    }

    m_commandMessageWriter = CommandMessageWriter::make(manifest->getHelpMetadata().getUsageMessage());
}

/**
 * The CommandHandler constructor.
 */
CommandHandler::~CommandHandler()
{
}

/**
 * Runs a command and returns the exit status.
 */
int CommandHandler::run(ICommand& command, int argc, char *argv[])
{
    int exitStatus = 0;

    try {
        if(!runCommand(command, argc, argv)) {
            std::string errorMessage =
                "The command: " + m_manifest->getName() +
                " has failed to run, Exit Status: -1";

            m_commandMessageWriter->getMessageWriter()->writeErrorMessage(errorMessage);

            exitStatus = -1;
        }
    }
    catch (base::BaseException& e)
    {
        std::string errorMessage =
            "The command: " + m_manifest->getName() +
            " has failed to run due to runtime error: " + e.what() +
            ", Exit Status: -1";

        exitStatus = -1;
    }
    catch (std::exception& e)
    {
        std::string errorMessage =
            "The command: " + m_manifest->getName() +
            " has failed to run due to unexpected error: " + e.what() +
            ", Exit Status: -1";

        exitStatus = -1;
    }

    return exitStatus;
}

/**
 * Runs a command.
 *
 * Returns true if running the command successfully.
 * Returns false if failing to run the command.
 */
bool CommandHandler::runCommand(ICommand& command, int argc, char *argv[])
{
    //
    // Parse parameters of the command...
    //
    base::IParsingResultSharedPtr<ICommandParametersSharedPtr> parametersResult = parseParameters(argc, argv);

    if (parametersResult->failed() || isHelpCommand(*parametersResult->getResult())) {

        if (parametersResult->failed())
        {
            std::string errorMessage =
                "The command: " + m_manifest->getName() +
                " has failed to parse the parameters due to parsing error: " + parametersResult->getErrorMessage() +
                ", Exit Status: 0";

            m_commandMessageWriter->getMessageWriter()->writeErrorMessage(errorMessage);
        }

        m_commandMessageWriter->writeUsageMessage(parametersResult->getStatus());

        return parametersResult->getStatus();
    }

    //
    // Set the information of the command...
    //
    command.setParameters(parametersResult->getResult());

    command.setMessageWriter(m_commandMessageWriter->getMessageWriter());

    //
    // Run the logic of the command...
    //
    command.run();

    return true;
}

/**
 * Parses the parameters of a command.
 */
base::IParsingResultSharedPtr<ICommandParametersSharedPtr> CommandHandler::parseParameters(int argc, char *argv[])
{
    CommandParser parser;
    base::IParsingResultSharedPtr<ICommandParametersSharedPtr> result = parser.parse(argc, argv);
    return result;
}

/**
 * Checks whether this is a help command.
 */
bool CommandHandler::isHelpCommand(const ICommandParameters& parameters)
{
    const IParameterSet& parameterSet = parameters.getParameterSet();
    return parameters.getParameterSet().getIndex() == CommandConstants::helpParameterSetIndex;
}
