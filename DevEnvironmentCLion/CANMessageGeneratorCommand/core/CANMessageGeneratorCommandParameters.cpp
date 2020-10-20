#include "PreCompiled.h"
#include "CANMessageGeneratorCommandParameters.h"
#include "Strings.h"
#include "CANMessageGeneratorCommandException.h"

using namespace controllerareanetwork::messagegeneratorcommand;

const size_t CANMessageGeneratorCommandParameters::defaultSessionDurationInSeconds = 10 * 60;

/**
 * The CANMessageGeneratorCommandParameters constructor.
 */
CANMessageGeneratorCommandParameters::CANMessageGeneratorCommandParameters(
    const command::ICommandParameters& parameters)
{
    const command::IParameterSet& p = parameters.getParameterSet();

    command::IParameterPtr driveSessionDurationParameter = parameters.getParameterSet().getParameter("driveSessionTime");
    size_t driveSessionInSeconds = driveSessionDurationParameter != nullptr && driveSessionDurationParameter->isDefined() ?
        driveSessionDurationParameter->getSizeTValue() :
        defaultSessionDurationInSeconds;

    m_duration = base::Duration::fromSeconds(driveSessionInSeconds);

    command::IParameterPtr messagesFrequenciesParameter = parameters.getParameterSet().getParameter("messagesFrequencies");
    std::vector<std::string> messagesFrequenciesStrings;

    if (messagesFrequenciesParameter != nullptr && messagesFrequenciesParameter->isDefined())
    {
        messagesFrequenciesParameter->getStringArrayValue(messagesFrequenciesStrings);
    }

    parseMessageFrequencies(
        messagesFrequenciesStrings,
        m_messagesFrequencies);
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

/**
 * Parses the message frequencies.
 */
void CANMessageGeneratorCommandParameters::parseMessageFrequencies(
    const std::vector<std::string>& messagesFrequencies,
    std::vector<std::pair<std::string, size_t>>& result)
{
    for (const std::string& messagesFrequency : messagesFrequencies)
    {
        std::vector<std::string> messageFrequencyTokens;
        base::Strings::splitString(messagesFrequency, ":", messageFrequencyTokens);

        if (messageFrequencyTokens.size() != 2)
        {
            std::string errorMessage = "The message frequency token is invalid. Format: '<name>:<size>'";
            throw CANMessageGeneratorCommandException(errorMessage);
        }

        std::string messageName = base::Strings::trimCopy(messageFrequencyTokens.at(0));
        size_t frequencyInHertz = std::stoi(messageFrequencyTokens.at(1));

        result.push_back(std::make_pair(messageName, frequencyInHertz));
    }
}
