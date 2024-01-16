#include "AbstractCommand.h"
#include "CommandException.h"
#include "SmartPointers.h"

using namespace Command;

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
void AbstractCommand::SetParameters(ICommandParametersSharedPtr parameters)
{
    base::SmartPointers::Validate<ICommandParameters>(parameters);
    m_parameters = parameters;
}

/**
 * Gets parameters of a command.
 */
const ICommandParameters& AbstractCommand::GetParameters() const
{
    return *m_parameters;
}

/**
 * Sets a message writer of a command.
 */
void AbstractCommand::SetMessageWriter(base::IMessageWriterSharedPtr messageWriter)
{
    base::SmartPointers::Validate<base::IMessageWriter>(messageWriter);
    m_messageWriter = messageWriter;
}

/**
 * Gets a message writer of a command.
 */
base::IMessageWriter& AbstractCommand::GetMessageWriter()
{
    return *m_messageWriter;
}
