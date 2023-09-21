#include "CommandHandler.h"
#include "CommandException.h"
#include "CommandParser.h"
#include "CommandMessageWriter.h"
#include "CommandConstants.h"
#include "SmartPointers.h"
#include "StringUtils.h"
#include <iostream>

using namespace command;

/**
 * Creates a new Command handler.
 */
ICommandHandlerSharedPtr CommandHandler::Make(ICommandManifestSharedPtr manifest)
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
    base::SmartPointers::Validate<ICommandManifest>(manifest);
    m_commandMessageWriter = CommandMessageWriter::Make(manifest->GetHelpMetadata().GetUsageMessage());
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
int CommandHandler::Run(ICommand& command, int argc, wchar_t* argv[])
{
    int exitStatus = 0;

    try {
        if(!RunCommand(command, argc, argv)) {
            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"The Command: " << m_manifest->GetName() << L" has Failed to Run, Exit Status: -1";

            std::wstring errorMessage = errorMessageStream.str();

            m_commandMessageWriter->GetMessageWriter()->WriteErrorMessage(errorMessage);

            exitStatus = -1;
        }
    }
    catch (base::BaseException& e)
    {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The Command: " << m_manifest->GetName()
            << L" has Failed to Run due to runtime error: " << e.GetErrorMessage()
            << L", Exit Status: -1"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        std::wcout << errorMessage;
        exitStatus = -1;
    }
    catch (std::exception& e)
    {
        long errorCode = base::ErrorCodes::FAIL;

        std::wstringstream errorMessageStream;
        errorMessageStream
            << L"The Command: " << m_manifest->GetName()
            << L" has Failed to Run due to unexpected error: " << base::StringUtils::StringToWideString(e.what())
            << L", Exit Status: -1"
            << base::ErrorMessages::GetErrorCodeMessage(errorCode);

        std::wstring errorMessage = errorMessageStream.str();

        std::wcout << errorMessage;
        exitStatus = -1;
    }

    return exitStatus;
}

/**
 * Runs a command.
 *
 * Returns true if running the Command successfully.
 * Returns false if failing to Run the Command.
 */
bool CommandHandler::RunCommand(ICommand& command, int argc, wchar_t* argv[])
{
    //
    // Parse parameters of the Command...
    //
    IParsingResultSharedPtr<ICommandParametersSharedPtr> parametersResult = ParseParameters(argc, argv);

    if (parametersResult->Failed() || IsHelpCommand(*parametersResult->GetResult())) {

        if (parametersResult->Failed())
        {
            long errorCode = base::ErrorCodes::INVALID_ARG;

            std::wstringstream errorMessageStream;
            errorMessageStream
                << L"he Command: " << m_manifest->GetName()
                << L" has Failed to Parse the parameters due to parsing error: " << parametersResult->GetErrorMessage()
                << ", Exit Status: 0"
                << base::ErrorMessages::GetErrorCodeMessage(errorCode);

            std::wstring errorMessage = errorMessageStream.str();
            m_commandMessageWriter->GetMessageWriter()->WriteErrorMessage(errorMessage);
        }

        m_commandMessageWriter->WriteUsageMessage(parametersResult->GetStatus());

        return parametersResult->GetStatus();
    }

    //
    // Set the information of the Command...
    //
    command.SetParameters(parametersResult->GetResult());

    command.SetMessageWriter(m_commandMessageWriter->GetMessageWriter());

    //
    // Run the logic of the Command...
    //
    command.Run();

    return true;
}

/**
 * Parses the parameters of a command.
 */
IParsingResultSharedPtr<ICommandParametersSharedPtr> CommandHandler::ParseParameters(int argc, wchar_t* argv[])
{
    CommandParser parser;
    IParsingResultSharedPtr<ICommandParametersSharedPtr> result = parser.Parse(argc, argv);
    return result;
}

/**
 * Checks whether this is a help Command.
 */
bool CommandHandler::IsHelpCommand(const ICommandParameters& parameters)
{
    const IParameterSet& parameterSet = parameters.GetParameterSet();
    return parameters.GetParameterSet().GetIndex() == CommandConstants::HELP_PARAMETER_SET_INDEX;
}
