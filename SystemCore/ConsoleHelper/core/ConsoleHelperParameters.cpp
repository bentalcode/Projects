#include "ConsoleHelperParameters.h"
#include "ConsoleHelperConstants.h"

using namespace console_helper;

/**
 * Creates a console helper command parameters.
 */
IConsoleHelperParametersSharedPtr ConsoleHelperParameters::Make(
    const command::ICommandParameters& parameters)
{
    return std::make_shared<ConsoleHelperParameters>(parameters);
}

/**
 * The ConsoleHelperParameters constructor.
 */
ConsoleHelperParameters::ConsoleHelperParameters(const command::ICommandParameters& parameters)
{
    const command::IParameterSet& parameterSet = parameters.GetParameterSet();
    command::IParameterSharedPtr consoleTitleParameter = parameterSet.GetParameter(ConsoleHelperConstants::CONSOLE_TITLE);
    m_consoleTitle = consoleTitleParameter->GetStringValue();

    command::IParameterSharedPtr pipeNameParameter = parameterSet.GetParameter(ConsoleHelperConstants::PIPE_NAME);
    m_pipeName = pipeNameParameter->GetStringValue();
}

/**
 * The ConsoleHelperParameters destructor.
 */
ConsoleHelperParameters::~ConsoleHelperParameters()
{
}

/**
 * Gets title of console.
 */
const std::wstring& ConsoleHelperParameters::GetConsoleTile() const
{
    return m_consoleTitle;
}

/**
 * Gets name of pipe.
 */
const std::wstring& ConsoleHelperParameters::GetPipeName() const
{
    return m_pipeName;
}
