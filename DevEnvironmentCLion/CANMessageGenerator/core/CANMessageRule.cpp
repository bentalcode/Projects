#include "PreCompiled.h"
#include "CANMessageRule.h"
#include "CANMessageGeneratorException.h"

using namespace controllerareanetweok::messagegenerator;

const std::string CANMessageRule::messageSyntax = "BO_";
int CANMessageRule::minimumDataLength = 0;
int CANMessageRule::maximumDataLength = 1785;

/**
 * Creates a new rule.
 */
ICANMessageRulePtr CANMessageRule::make(
    ICANMessageIdPtr id,
    ICANMessageNamePtr name,
    short length,
    const std::string& transmittingNodeName,
    const std::vector<ICANSignalRulePtr>& signalRules)
{
    return std::make_shared<CANMessageRule>(
        id,
        name,
        length,
        transmittingNodeName,
        signalRules);
}

/**
 * The CANSignal constructor.
 */
CANMessageRule::CANMessageRule(
    ICANMessageIdPtr id,
    ICANMessageNamePtr name,
    short length,
    const std::string& transmittingNodeName,
    const std::vector<ICANSignalRulePtr>& signalRules) :
    m_id(id),
    m_name(name),
    m_length(length),
    m_transmittingNodeName(transmittingNodeName),
    m_signalRules(signalRules)
{
    if (!id)
    {
        std::string errorMessage = "The id of the message is not defined.";
        throw CANMessageGeneratorException(errorMessage);
    }

    if (!name)
    {
        std::string errorMessage = "The name of the message is not defined.";
        throw CANMessageGeneratorException(errorMessage);
    }

    if (length < minimumDataLength || length > maximumDataLength)
    {
        std::string errorMessage = "The length of the data is out of range.";
        throw CANMessageGeneratorException(errorMessage);
    }

    if (signalRules.empty())
    {
        std::string errorMessage = "The signal rules are not defined.";
        throw CANMessageGeneratorException(errorMessage);
    }
}

/**
 * The CANMessageRule destructor.
 */
CANMessageRule::~CANMessageRule()
{
}

/**
 * Gets the identifier of the message.
 */
const ICANMessageId& CANMessageRule::getId() const
{
    return *m_id;
}

/**
 * Gets the name of the message.
 */
const ICANMessageName& CANMessageRule::getName() const
{
    return *m_name;
}

/**
 * The length (DLC) must be an integer between 0 and 1785.
 */
unsigned short CANMessageRule::getLength() const
{
    return m_length;
}

/**
 * Gets the name of the transmitting node.
 */
const std::string& CANMessageRule::getTransmittingNodeName() const
{
    return m_transmittingNodeName;
}

/**
 * Gets the signal rules.
 */
const std::vector<ICANSignalRulePtr>& CANMessageRule::getSignalRules() const
{
    return m_signalRules;
}

/**
 * Gets the string representation of this instance.
 */
std::string CANMessageRule::toString() const
{
    std::stringstream stream;

    stream << messageSyntax;
    stream << " ";
    stream << m_id;
    stream << " ";
    stream << m_name;
    stream << ": ";
    stream << m_length;
    stream << " ";
    stream << m_transmittingNodeName;

    return stream.str();
}

/**
 * Writers the content of the rule.
 */
void CANMessageRule::writeRule(std::ostream& output) const
{
    std::string ruleString = toString();
    output << ruleString << std::endl;

    for (ICANSignalRulePtr signalRule : m_signalRules)
    {
        output << "/t";
        signalRule->writeRule(output);
    }
}
