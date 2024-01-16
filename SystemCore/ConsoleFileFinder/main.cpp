#include "ConsoleFileFinderCommand.h"
#include "ConsoleFileFinderCommandManifest.h"
#include "CommandHandler.h"
#include "BaseException.h"
#include "StringUtils.h"
#include <algorithm>

namespace consolefilefinder {

    /**
     * Runs the command.
     */
    static void RunCommand(int argc, wchar_t** argv)
    {
        IConsoleFileFinderCommandSharedPtr consoleFileFinderCommand = ConsoleFileFinderCommand::Make();
        command::ICommand& command = consoleFileFinderCommand->GetCommand();
        command::ICommandManifestSharedPtr manifest = ConsoleFileFinderCommandManifest::Make();
        command::ICommandHandlerSharedPtr commandHandler = command::CommandHandler::Make(manifest);
        commandHandler->Run(command, argc, argv);
    }
}

int main(int argc, char *argv[])
{
    int exitCode = 0;

    std::vector<std::wstring> parameters;
    parameters.reserve(argc);

    for (int index = 0; index < argc; ++index) {
        char* arg = argv[index];
        std::wstring parameter = base::StringUtils::StringToWideString(arg);
        parameters.push_back(parameter);
    }

    std::vector<const wchar_t*> wcharParameters;
    std::transform(
        parameters.begin(),
        parameters.end(),
        std::back_inserter(wcharParameters),
        [](const std::wstring& str) -> const wchar_t*
        {
            return str.c_str();
        }
    );

    try {
        consolefilefinder::RunCommand(
            wcharParameters.size(),
            const_cast<wchar_t**>(&wcharParameters[0]));
    }
    catch (base::BaseException& e) {
        exitCode = e.GetStatusCode();
    }

    return exitCode;
}
