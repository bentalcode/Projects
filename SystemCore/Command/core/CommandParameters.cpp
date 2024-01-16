#include "CommandParameters.h"
#include "CommandException.h"
#include "SmartPointers.h"

using namespace command;

/**
 * Creates a new command parameters.
 */
ICommandParametersSharedPtr CommandParameters::Make(IParameterSetSharedPtr parameterSet)
{
    return std::make_shared<CommandParameters>(parameterSet);
}

/**
 * The CommandParameters constructor.
 */
CommandParameters::CommandParameters(IParameterSetSharedPtr parameterSet)
{
    base::SmartPointers::Validate<IParameterSet>(parameterSet);
    m_parameterSet = parameterSet;
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
const IParameterSet& CommandParameters::GetParameterSet() const
{
    return *m_parameterSet;
}