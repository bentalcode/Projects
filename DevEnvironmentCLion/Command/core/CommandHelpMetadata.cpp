#include "PreCompiled.h"
#include "CommandHelpMetadata.h"
#include "Parameter.h"
#include "NamedParameterMetadata.h"

using namespace command;

/**
 * Creates a help parameter.
 */
IParameterPtr CommandHelpMetadata::createHelpParameter()
{
    return std::make_shared<Parameter>(CommandConstants::helpShortName, "", false);
}

/**
 * Creates meta-data of a help parameter.
 */
INamedParameterMetadataPtr CommandHelpMetadata::createHelpParameterMetadata() {
    return NamedParameterMetadata::make(
        "Help",
        CommandConstants::helpShortName,
        CommandConstants::helpLongName,
        "The help of the command");
}

/**
 * Creates a new command help metadata.
 */
ICommandHelpMetadataPtr CommandHelpMetadata::make(
    const std::string& usageMessage,
    const std::string& shortName,
    const std::string& longName)
{
    return std::make_shared<CommandHelpMetadata>(
        shortName,
        longName,
        usageMessage);
}

/**
 * The CommandHelpMetadata constructor.
 */
CommandHelpMetadata::CommandHelpMetadata(
    const std::string& shortName,
    const std::string& longName,
    const std::string& usageMessage) :
    m_shortName(shortName),
    m_longName(longName),
    m_usageMessage(usageMessage)
{
}

/**
 * The CommandHelpMetadata destructor.
 */
CommandHelpMetadata::~CommandHelpMetadata()
{
}

/**
 * Gets a short name of a help parameter.
 */
const std::string& CommandHelpMetadata::getShortName() const
{
    return m_shortName;
}

/**
 * Gets a long name of a help parameter.
 */
const std::string& CommandHelpMetadata::getLongName() const
{
    return m_longName;
}

/**
 * Gets a usage message of a command.
 */
const std::string& CommandHelpMetadata::getUsageMessage() const
{
    return m_usageMessage;
}
