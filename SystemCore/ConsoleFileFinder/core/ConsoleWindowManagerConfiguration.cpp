#include "ConsoleWindowManagerConfiguration.h"

using namespace consolefilefinder;

const std::wstring ConsoleWindowManagerConfiguration::CONSOLE_HELPER_PATH =
    L"C:\\git\\repositories\\Projects\\SystemCore\\ConsoleHelper\\cmake-build-debug\\ConsoleHelper.exe";

/**
 * Creates a console file finder configuration.
 */
IConsoleWindowManagerConfigurationSharedPtr ConsoleWindowManagerConfiguration::Make()
{
    return std::make_shared<ConsoleWindowManagerConfiguration>(CONSOLE_HELPER_PATH);
}

/**
 * The ConsoleWindowManagerConfiguration constructor.
 */
ConsoleWindowManagerConfiguration::ConsoleWindowManagerConfiguration(const std::wstring& consoleHelperPath) :
    m_consoleHelperPath(consoleHelperPath)
{
}

/**
 * The ConsoleWindowManagerConfiguration destructor.
 */
ConsoleWindowManagerConfiguration::~ConsoleWindowManagerConfiguration()
{
}

/**
 * Gets path of console helper.
 */
const std::wstring& ConsoleWindowManagerConfiguration::GetConsoleHelperPath() const
{
    return m_consoleHelperPath;
}
