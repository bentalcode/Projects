#include "PreCompiled.h"
#include "CANMessageRuleGenerator.h"
#include "CANMessageRule.h"
#include "CANSignalRuleGenerator.h"
#include "Bits.h"

using namespace controllerareanetwork::messagegenerator;

const short CANMessageRuleGenerator::minLength = 0;
const short int CANMessageRuleGenerator::maxLength = 1785;

const size_t CANMessageRuleGenerator::minNumberOfSignalRules = 1;
const size_t CANMessageRuleGenerator::maxNumberOfSignalRules = 10;

/**
 * The CANMessageRuleGenerator constructor.
 */
CANMessageRuleGenerator::CANMessageRuleGenerator() :
    m_signalRuleGenerator(std::make_shared<CANSignalRuleGenerator>())
{
}

/**
 * The CANMessageRuleGenerator destructor.
 */
CANMessageRuleGenerator::~CANMessageRuleGenerator()
{
}

/**
 * Generates a new CAN message rule.
 */
ICANMessageRulePtr CANMessageRuleGenerator::generate(const std::string& name)
{
    //
    // Generate a random message id...
    //
    ICANMessageIdPtr messageId = generateMessageId();

    //
    // Generate a message name...
    //
    std::vector<std::string::value_type> nameCharacter(name.begin(), name.end());
    ICANMessageNamePtr messageName = CANMessageName::make(nameCharacter);

    //
    // Generate a random length...
    //
    short length = generateLength();

    //
    // Generate a random transmitting node...
    //
    std::string transmittingNodeName = generateTransmittingNodeName();

    //
    // Generate random signal rules...
    //
    std::vector<ICANSignalRulePtr> signalRules;
    generateSignalRules(name, signalRules);

    return CANMessageRule::make(
        messageId,
        messageName,
        length,
        transmittingNodeName,
        signalRules);
}

/**
 * Generates a message id.
 */
ICANMessageIdPtr CANMessageRuleGenerator::generateMessageId()
{
    unsigned int mainId = generateId(0, 28);
    unsigned int extendedId = generateId(29, 30);

    return CANMessageId::make(mainId, extendedId);
}

/**
 * Generates a new length.
 */
short CANMessageRuleGenerator::generateLength()
{
    short length = static_cast<short>(randomGenerator().nextInteger(minLength, maxLength));
    return length;
}

/**
 * Generates new signal rules.
 */
void CANMessageRuleGenerator::generateSignalRules(const std::string& name, std::vector<ICANSignalRulePtr>& rules)
{
    size_t numberOfRules = randomGenerator().nextSizeT(
        minNumberOfSignalRules,
        maxNumberOfSignalRules);

    for (size_t i = 0; i < numberOfRules; ++i) {
        ICANSignalRulePtr rule = m_signalRuleGenerator->generate(name);
        rules.push_back(rule);
    }
}

/**
 * Generates an id.
 */
unsigned int CANMessageRuleGenerator::generateId(size_t startBitIndex, size_t endBitEndIndex)
{
    assert(startBitIndex <= endBitEndIndex);

    unsigned int id = 0;

    for (size_t bitIndex = startBitIndex; bitIndex <= endBitEndIndex; ++bitIndex) {
        int bitValue = randomGenerator().nextBoolean() ? 1 : 0;
        id = base::Bits::set(id, bitIndex, bitValue);
    }

    return id;
}
