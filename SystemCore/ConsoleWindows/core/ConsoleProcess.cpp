#include "ConsoleProcess.h"

using namespace console_windows;

/**
 * Creates a Console Process.
 */
IConsoleProcessSharedPtr ConsoleProcess::Make()
{
    return std::make_shared<ConsoleProcess>();
}

/**
 * The ConsoleProcess constructor.
 */
ConsoleProcess::ConsoleProcess()
{
}

/**
 * The ConsoleProcess destructor.
 */
ConsoleProcess::~ConsoleProcess()
{
}
