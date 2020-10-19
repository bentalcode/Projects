#include "PreCompiled.h"
#include "CANMessageGeneratorCommandParameters.h"

using namespace controllerareanetwork::messagegeneratorcommand;

/**
 * Creates a new command parameters.
 */
ICANMessageGeneratorCommandParametersPtr CANMessageGeneratorCommandParameters::make(
    base::DurationPtr duration,
    const std::vector<std::pair<std::string, size_t>>& messagesFrequencies)
{
    return std::make_shared<CANMessageGeneratorCommandParameters>(duration, messagesFrequencies);
}

/**
 * The CANMessageGeneratorCommandParameters constructor.
 */
CANMessageGeneratorCommandParameters::CANMessageGeneratorCommandParameters(
    base::DurationPtr duration,
    const std::vector<std::pair<std::string, size_t>>& messagesFrequencies) :
    m_duration(duration),
    m_messagesFrequencies(messagesFrequencies)
{
}

/**
 * The CANMessageGeneratorCommandParameters destructor.
 */
CANMessageGeneratorCommandParameters::~CANMessageGeneratorCommandParameters()
{
}

/**
 * Gets the duration of a drive session.
 */
const base::Duration& CANMessageGeneratorCommandParameters::getDriveSessionDuration() const
{
    return *m_duration;
}

/**
 * Gets the messages frequencies.
 */
const std::vector<std::pair<std::string, size_t>>& CANMessageGeneratorCommandParameters::getMessagesFrequencies() const
{
    return m_messagesFrequencies;
}
