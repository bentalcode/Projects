#include "ConsoleWindow.h"

using namespace console_windows;

/**
 * Creates a ConsoleWindow.
 */
IConsoleSharedPtr ConsoleWindow::Make(const std::wstring name)
{
    return std::make_shared<ConsoleWindow>(name);
}

/**
 * The ConsoleWindow constructor.
 */
ConsoleWindow::ConsoleWindow(const std::wstring name) :
    m_name(name)
{
}

/**
 * The ConsoleWindow destructor.
 */
ConsoleWindow::~ConsoleWindow()
{
}
