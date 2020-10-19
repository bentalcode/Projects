#include "PreCompiled.h"
#include "JitterMessageData.h"
#include "JitterMessageHandlerException.h"

using namespace controllerareanetwork::messagegenerator;

const std::string JitterMessageData::transmittingTimeText = "TransmittingTime:";
const std::string JitterMessageData::deviationText = "Deviation:";
const std::string JitterMessageData::numberOfMessagesSentText = "numberOfMessagesSent:";
const std::string JitterMessageData::numberOfMessagesReceivedText = "numberOfMessagesReceived:";

/**
 * The JitterMessageData constructor.
 */
JitterMessageData::JitterMessageData(base::DurationPtr transmittingTime) :
    m_transmittingTime(transmittingTime),
    m_numberOfMessagesSent(0),
    m_numberOfMessagesReceived(0),
    m_deviation(0.0)
{
    if (!transmittingTime)
    {
        std::string errorMessage = "The transmitting time is not defined.";
        throw JitterMessageHandlerException(errorMessage);
    }
}

/**
 * The JitterMessageData destructor.
 */
JitterMessageData::~JitterMessageData()
{
}

/**
 * Gets the transmitting time.
 */
base::DurationPtr JitterMessageData::getTransmittingTime() const
{
    return m_transmittingTime;
}

/**
 * Gets the last sending time of a message.
 */
base::DateTimePtr JitterMessageData::getMessageLastSendingTime() const
{
    return m_lastSendingTime;
}

/**
 * Sets the last sending time of a message.
 */
void JitterMessageData::setMessageLastSendingTime(base::DateTimePtr time)
{
    if (!time)
    {
        std::string errorMessage = "The sending time of the message is not defined.";
        throw JitterMessageHandlerException(errorMessage);
    }

    m_lastSendingTime = time;
}

/**
 * Gets the number of messages sent.
 */
size_t JitterMessageData::getNumberOfMessagesSent() const
{
    return m_numberOfMessagesSent;
}

/**
 * Gets the number of messages received.
 */
size_t JitterMessageData::getNumberOfMessagesReceived() const
{
    return m_numberOfMessagesReceived;
}

/**
 * Increments the number of messages sent.
 */
void JitterMessageData::incrementNumberOfMessagesSent()
{
    ++m_numberOfMessagesSent;
}

/**
 * Increments the number of messages received.
 */
void JitterMessageData::incrementNumberOfMessagesReceived()
{
    ++m_numberOfMessagesReceived;
}

/**
 * Gets the Jitter deviation.
 */
double JitterMessageData::getDeviation() const
{
    return m_deviation;
}

/**
 * Sets the Jitter deviation.
 */
void JitterMessageData::setDeviation(double deviation)
{
    m_deviation = deviation;
}

/**
 * Gets the string representation of this instance.
 */
std::string JitterMessageData::toString() const
{
    std::stringstream stream;

    stream
        << transmittingTimeText << " " << m_transmittingTime
        << ", "
        << deviationText << " " << m_deviation
        << ", "
        << numberOfMessagesSentText << " " << m_numberOfMessagesSent
        << ", "
        << numberOfMessagesReceivedText << " " << m_numberOfMessagesReceived;

    return stream.str();
}
