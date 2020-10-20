#include "PreCompiled.h"
#include "JitterMessageHandler.h"
#include "JitterMessageHandlerException.h"
#include "JitterMessageData.h"

using namespace controllerareanetwork::messagegenerator;

/**
 * The JitterMessageHandler constructor.
 */
JitterMessageHandler::JitterMessageHandler()
{
}

/**
 * The JitterMessageHandler destructor.
 */
JitterMessageHandler::~JitterMessageHandler()
{
}

/**
 * Registers a message.
 */
void JitterMessageHandler::registerMessage(
    const std::string& messageName,
    base::DurationPtr transmittingTime)
{
    MessageDataMap::const_iterator messageIterator = m_messageDataMap.find(messageName);

    if (messageIterator != m_messageDataMap.end())
    {
        std::string errorMessage =
            "The message type: " + messageName + " has already been registered with the Jitter Handler.";

        throw JitterMessageHandlerException(errorMessage);
    }

    IJitterMessageDataPtr messageData = JitterMessageData::make(transmittingTime);
    m_messageDataMap.insert(std::make_pair(messageName, messageData));
}

/**
 * Unregisters a message.
 *
 * Returns true if the message got unregistered successfully from the Jitter Handler.
 * Returns false if the message is not currently registered with the Jitter Handler.
 */
bool JitterMessageHandler::unregisterMessage(const std::string& messageName)
{
    MessageDataMap::const_iterator messageIterator = m_messageDataMap.find(messageName);

    if (messageIterator == m_messageDataMap.end()) {
        return false;
    }

    m_messageDataMap.erase(messageIterator);

    return true;
}

/**
 * Sets the sending time of a message.
 */
void JitterMessageHandler::setMessageSendingTime(
    const std::string& messageName,
    base::DateTimePtr time)
{
    IJitterMessageDataPtr data = getMessageData(messageName);

    data->setMessageLastSendingTime(time);
    data->incrementNumberOfMessagesSent();
}

/**
 * Sets the receiving time of a message.
 */
void JitterMessageHandler::setMessageReceivingTime(
    const std::string& messageName,
    base::DateTimePtr time)
{
    IJitterMessageDataPtr data = getMessageData(messageName);

    base::DateTimePtr sendingTime = data->getMessageLastSendingTime();

    if (!sendingTime) {
        std::string errorMessage =
            "The sending time of message: " + messageName +
            " was not recorded with the Jitter Handler.";

        throw JitterMessageHandlerException(errorMessage);
    }

    data->incrementNumberOfMessagesReceived();

    //
    // Update the deviation...
    // J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
    //
    double prevDeviation = data->getDeviation();

    base::DurationPtr currDuration = base::Duration::between(*sendingTime, *time);
    long currDeviation = currDuration->toMilliseconds() - data->getTransmittingTime()->toMilliseconds();

    double deviation = prevDeviation + (std::abs(static_cast<double>(currDeviation)) - prevDeviation) / 16.0;

    data->setDeviation(deviation);
}

/**
 * Gets the jitter deviation.
 * J(i) = J(i-1) + (|D(i-1,i)| - J(i-1))/16
 */
double JitterMessageHandler::getDeviation(const std::string& messageName)
{
    IJitterMessageDataPtr data = getMessageData(messageName);
    return data->getDeviation();
}

/**
 * Gets the message data.
 */
IJitterMessageDataPtr JitterMessageHandler::getMessageData(const std::string& messageName)
{
    MessageDataMap::const_iterator messageIterator = m_messageDataMap.find(messageName);

    if (messageIterator == m_messageDataMap.end()) {
        std::string errorMessage =
            "The message: " + messageName + " is not registered with the Jitter Handler.";

        throw JitterMessageHandlerException(errorMessage);
    }

    return messageIterator->second;
}
