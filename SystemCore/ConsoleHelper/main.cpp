#include "ConsoleHelper.h"
#include "ConsoleHelperManifest.h"
#include "CommandHandler.h"
#include "BaseException.h"
#include "StringUtils.h"
#include <algorithm>

namespace console_helper {

    /**
     * Runs the command.
     */
    static void RunCommand(int argc, wchar_t** argv)
    {
        IConsoleHelperSharedPtr consoleHelperCommand = ConsoleHelper::Make();
        command::ICommand& command = consoleHelperCommand->GetCommand();
        command::ICommandManifestSharedPtr manifest = ConsoleHelperManifest::Make();
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
        console_helper::RunCommand(
            wcharParameters.size(),
            const_cast<wchar_t**>(&wcharParameters[0]));
    }
    catch (base::BaseException& e) {
        exitCode = e.GetStatusCode();
    }

    return exitCode;
}
