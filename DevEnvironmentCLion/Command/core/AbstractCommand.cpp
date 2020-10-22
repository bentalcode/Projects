#include "PreCompiled.h"
#include "AbstractCommand.h"
#include "CommandException.h"

using namespace command;

/**
 * The AbstractCommand constructor.
 */
AbstractCommand::AbstractCommand()
{
}

/**
 * The AbstractCommand destructor.
 */
AbstractCommand::~AbstractCommand()
{
}

/**
 * Sets parameters of a command.
 */
void AbstractCommand::setParameters(ICommandParametersPtr parameters)
{
    if (!parameters)
    {
        std::string errorMessage = "The parameters of the command are not defined.";
        throw CommandException(errorMessage);
    }

    m_parameters = parameters;
}

/**
 * Gets parameters of a command.
 */
const ICommandParameters& AbstractCommand::getParameters() const
{
    return *m_parameters;
}

/**
 * Sets a message writer of a command.
 */
void AbstractCommand::setMessageWriter(base::IMessageWriterPtr messageWriter)
{
    if (!messageWriter)
    {
        std::string errorMessage = "The message writer of the command are not defined.";
        throw CommandException(errorMessage);
    }

    m_messageWriter = messageWriter;
}

/**
 * Gets a message writer of a command.
 */
base::IMessageWriter& AbstractCommand::getMessageWriter()
{
    return *m_messageWriter;
}
