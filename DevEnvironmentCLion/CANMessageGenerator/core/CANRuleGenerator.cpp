#include "PreCompiled.h"
#include "CANRuleGenerator.h"

using namespace controllerareanetwork::messagegenerator;

const std::string CANRuleGenerator::defaultNodeName = "Vector__XXX";
const std::string CANRuleGenerator::nodeNamePrefix = "Name";
unsigned int CANRuleGenerator::numberOfNodes = 100;

/**
 * The CANRuleGenerator constructor.
 */
CANRuleGenerator::CANRuleGenerator()
{
}

/**
 * The CANRuleGenerator destructor.
 */
CANRuleGenerator::~CANRuleGenerator()
{
}

/**
 * Generates a new transmitting node name.
 */
const std::string& CANRuleGenerator::generateTransmittingNodeName()
{
    static std::unique_ptr<std::vector<std::string>> nodeNames(getTransmittingNodeNames());
    return generateTransmittingNodeName(*nodeNames);
}

/**
 * Generates a new transmitting node name.
 */
const std::string& CANRuleGenerator::generateTransmittingNodeName(const std::vector<std::string>& transmittingNodeNames)
{
    size_t numberOfNames = transmittingNodeNames.size();
    size_t nameIndex = m_randomGenerator.nextInteger(0, static_cast<int>(numberOfNames - 1));

    const std::string& name = transmittingNodeNames.at(nameIndex);

    return name;
}

/**
 * Gets the transmitting node names.
 */
std::vector<std::string>* CANRuleGenerator::getTransmittingNodeNames()
{
    std::unique_ptr<std::vector<std::string>> result = std::make_unique<std::vector<std::string>>();

    result->push_back(defaultNodeName);

    for (unsigned int i = 0; i < numberOfNodes; ++i) {
        std::string nodeName = nodeNamePrefix + std::to_string(i);
        result->push_back(nodeName);
    }

    return result.release();
}