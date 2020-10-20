#include "PreCompiled.h"
#include "CANMessageGeneratorCommand.h"
#include "CANMessageGeneratorCommandParameters.h"
#include "CANMessageRuleGenerator.h"
#include "JitterMessageHandler.h"
#include "Threads.h"

using namespace controllerareanetwork::messagegeneratorcommand;

static const std::string messagesDeviationText = "Controller Area Network Message Generator Summary:";
static const std::string messageNameText = "messageName:";

/**
 * Creates a new command.
 */
command::ICommandPtr CANMessageGeneratorCommand::make()
{
    return std::make_shared<CANMessageGeneratorCommand>();
}

/**
 * The CANMessageGeneratorCommand constructor.
 */
CANMessageGeneratorCommand::CANMessageGeneratorCommand() :
    m_messageRuleGenerator(std::make_unique<CANMessageRuleGenerator>()),
    m_messageHandler(std::make_unique<JitterMessageHandler>())
{
}

/**
 * The CANMessageGeneratorCommand destructor.
 */
CANMessageGeneratorCommand::~CANMessageGeneratorCommand()
{
}

/**
 * Runs the logic of a command.
 */
void CANMessageGeneratorCommand::run()
{
    initialize();

    generateMessages(
        m_parameters->getDriveSessionDuration(),
        m_parameters->getMessagesFrequencies());
}

/**
 * Generates the specified messages.
 */
void CANMessageGeneratorCommand::generateMessages(
    const base::Duration& driveSessionDuration,
    const std::vector<std::pair<std::string, size_t>>& messages)
{
    registerMessagesWithJitter(messages);

    base::DateTimePtr startTime = base::DateTime::now();

    bool processSession = true;

    while (processSession)
    {
        for (const std::pair<std::string, size_t>& messageFrequency : messages) {
            processSession = sessionActive(*startTime, driveSessionDuration);

            if (!processSession) {
                break;
            }

            const std::string& messageName = messageFrequency.first;
            size_t frequency = messageFrequency.second;

            base::DurationPtr timeout = base::Duration::fromSeconds(1);

            processMessages(
                messageName,
                frequency,
                *timeout,
                getMessageWriter());
        }
    }
}

/**
 * Processes the messages.
 */
bool CANMessageGeneratorCommand::processMessages(
    const std::string& messageName,
    size_t numberOfMessages,
    const base::Duration& timeout,
    command::IMessageWriter& messageWriter)
{
    size_t messageIndex = 0;

    base::DateTimePtr startTime = base::DateTime::now();

    size_t delayInMilliseconds = 1000 / numberOfMessages;

    while (messageIndex < numberOfMessages && sessionActive(*startTime, timeout))
    {
        processMessage(messageName, messageWriter);
        ++messageIndex;

        base::Threads::sleep(delayInMilliseconds);
    }

    return true;
}

/**
 * Processes the message.
 */
void CANMessageGeneratorCommand::processMessage(
    const std::string& messageName,
    command::IMessageWriter& messageWriter)
{
    base::DateTimePtr sendingTime = base::DateTime::now();
    m_messageHandler->setMessageSendingTime(messageName, sendingTime);

    CANMessageRuleGenerator ruleGenerator;
    ICANMessageRulePtr rule = ruleGenerator.generate(messageName);

    messageWriter.writeInformationalMessage(rule->toString());

    for (ICANSignalRulePtr signalRule : rule->getSignalRules())
    {
        messageWriter.writeInformationalMessage("    " + signalRule->toString());
    }

    m_messageHandler->setMessageReceivingTime(messageName, base::DateTime::now());
}

/**
 * Registers the messages with the Jitter.
 */
void CANMessageGeneratorCommand::registerMessagesWithJitter(const std::vector<std::pair<std::string, size_t>>& messages)
{
    for (const std::pair<std::string, size_t>& message : messages)
    {
        const std::string& messageName = message.first;
        size_t frequencyInHz = message.second;

        size_t transmittingTimeInMilliseconds = 1000 / frequencyInHz;
        base::DurationPtr transmittingTime = base::Duration::fromMilliseconds(transmittingTimeInMilliseconds);

        m_messageHandler->registerMessage(messageName, transmittingTime);
    }
}

/**
 * Checks whether the session is active.
 */
bool CANMessageGeneratorCommand::sessionActive(const base::DateTime& startTime, const base::Duration& timeout)
{
    base::DateTimePtr currTime = base::DateTime::now();

    auto t1 = startTime.getTimePoint().time_since_epoch().count();
    auto t2 = currTime->getTimePoint().time_since_epoch().count();

    base::DurationPtr currDuration = base::Duration::between(startTime, *currTime);

    size_t currDurationInMilliseconds = currDuration->toMilliseconds();
    size_t timeOutInMilliseconds = timeout.toMilliseconds();

    return *currDuration < timeout;
}

/**
 * Initializes the command.
 */
void CANMessageGeneratorCommand::initialize()
{
    const command::ICommandParameters& parameters = getParameters();
    m_parameters = std::make_unique<CANMessageGeneratorCommandParameters>(parameters);
}
