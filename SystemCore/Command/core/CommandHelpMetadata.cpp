#include "CommandHelpMetadata.h"
#include "Parameter.h"
#include "NamedParameterMetadata.h"

using namespace command;

/**
 * Creates a help parameter.
 */
IParameterSharedPtr CommandHelpMetadata::CreateHelpParameter()
{
    return std::make_shared<Parameter>(
        CommandConstants::HELP_SHORT_NAME,
        CommandConstants::HELP_LONG_NAME,
        false);
}

/**
 * Creates meta-data of a help parameter.
 */
INamedParameterMetadataSharedPtr CommandHelpMetadata::CreateHelpParameterMetadata() {
    return NamedParameterMetadata::Make(
        L"Help",
        CommandConstants::HELP_SHORT_NAME,
        CommandConstants::HELP_LONG_NAME,
        L"The help of the Command");
}

/**
 * Creates a new Command help metadata.
 */
ICommandHelpMetadataSharedPtr CommandHelpMetadata::Make(
    const std::wstring& usageMessage,
    const std::wstring& shortName,
    const std::wstring& longName)
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
    const std::wstring& shortName,
    const std::wstring& longName,
    const std::wstring& usageMessage) :
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
const std::wstring& CommandHelpMetadata::GetShortName() const
{
    return m_shortName;
}

/**
 * Gets a long name of a help parameter.
 */
const std::wstring& CommandHelpMetadata::GetLongName() const
{
    return m_longName;
}

/**
 * Gets a usage message of a command.
 */
const std::wstring& CommandHelpMetadata::GetUsageMessage() const
{
    return m_usageMessage;
}
