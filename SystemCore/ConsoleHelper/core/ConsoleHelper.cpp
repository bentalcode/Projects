#include "ConsoleHelper.h"
#include "ConsoleHelperParameters.h"

using namespace console_helper;

/**
 * Creates a Console Helper command.
 */
IConsoleHelperSharedPtr ConsoleHelper::Make()
{
    return std::make_shared<ConsoleHelper>();
}

/**
 * The ConsoleHelper constructor.
 */
ConsoleHelper::ConsoleHelper()
{
}

/**
 * The ConsoleHelper destructor.
 */
ConsoleHelper::~ConsoleHelper()
{
}

/**
 * Runs the command.
 */
void ConsoleHelper::Run()
{
    //
    // Initialize command...
    //
    Initialize();

    //
    // Update console...
    //
}

/**
 * Gets the command.
 */
command::ICommand& ConsoleHelper::GetCommand()
{
    return *this;
}

/**
 * Initializes the command.
 */
void ConsoleHelper::Initialize()
{
    m_parameters = ConsoleHelperParameters::Make(command::AbstractCommand::GetParameters());
}
