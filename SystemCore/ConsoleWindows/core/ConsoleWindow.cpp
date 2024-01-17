#include "ConsoleWindow.h"

using namespace console_windows;

/**
 * Creates a ConsoleWindow.
 */
IConsoleSharedPtr ConsoleWindow::Make()
{
    return std::make_shared<ConsoleWindow>();
}

/**
 * The ConsoleWindow constructor.
 */
ConsoleWindow::ConsoleWindow()
{
}

/**
 * The ConsoleWindow destructor.
 */
ConsoleWindow::~ConsoleWindow()
{
}
