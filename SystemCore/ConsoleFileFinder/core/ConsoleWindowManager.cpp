#include "ConsoleWindowManager.h"
#include "ConsoleWindowManagerConfiguration.h"
#include "ConsoleWindow.h"
#include <iomanip>

using namespace consolefilefinder;

/**
 * Creates a file finder.
 */
IConsoleWindowManagerSharedPtr ConsoleWindowManager::Make()
{
    return std::make_shared<ConsoleWindowManager>();
}

/**
 * The ConsoleWindowManager constructor.
 */
ConsoleWindowManager::ConsoleWindowManager() :
    m_configuration(ConsoleWindowManagerConfiguration::Make())
{
}

/**
 * The ConsoleWindowManager destructor.
 */
ConsoleWindowManager::~ConsoleWindowManager()
{
}

/**
 * Creates a window.
 */
void ConsoleWindowManager::CreateWindow(const std::wstring& name)
{
    console_windows::IConsoleWindowSharedPtr consoleWindow = console_windows::ConsoleWindow::Make(
        name,
        m_configuration->GetConsoleHelperPath());

    std::wostream& consoleStream = consoleWindow->GetConsoleStream();
    consoleStream << L"debug console" << std::endl;
    consoleStream << std::hex << std::setfill(L'0') << std::setw(8) << 123456 << "\nflush!\n" << std::flush;
}
