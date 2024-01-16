#include "ConsoleWindow.h"

using namespace ConsoleWindows;

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
