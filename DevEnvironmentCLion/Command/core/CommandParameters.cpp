#include "PreCompiled.h"
#include "CommandParameters.h"
#include "CommandException.h"

using namespace command;

/**
 * Creates a new command parameters.
 */
ICommandParametersSharedPtr CommandParameters::make(IParameterSetSharedPtr parameterSet)
{
    return std::make_shared<CommandParameters>(parameterSet);
}

/**
 * The CommandParameters constructor.
 */
CommandParameters::CommandParameters(IParameterSetSharedPtr parameterSet) :
    m_parameterSet(parameterSet)
{
    if (!parameterSet)
    {
        std::string errorMessage = "The parameters set of the command is not defined.";
        throw CommandException(errorMessage);
    }
}

/**
 * The CommandParameters destructor.
 */
CommandParameters::~CommandParameters()
{
}

/**
 * Gets the parameter-set of the command.
 */
const IParameterSet& CommandParameters::getParameterSet() const
{
    return *m_parameterSet;
}