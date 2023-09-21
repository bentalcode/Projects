#include "CommandManifest.h"
#include "SmartPointers.h"
#include "CommandHelpMetadata.h"

using namespace command;

/**
 * Creates a new manifest.
 */
ICommandManifestSharedPtr CommandManifest::Make(
    const std::wstring& name,
    const std::wstring& description,
    const std::wstring& usageMessage)
{
    ICommandHelpMetadataSharedPtr helpMetadata = CommandHelpMetadata::Make(usageMessage);
    std::vector<IParameterSetMetadataSharedPtr> parameterSetMetadata;

    return std::make_shared<CommandManifest>(
        name,
        description,
        usageMessage,
        helpMetadata,
        parameterSetMetadata);
}

/**
 * Creates a new manifest.
 */
ICommandManifestSharedPtr CommandManifest::Make(
    const std::wstring& name,
    const std::wstring& description,
    const std::wstring& usageMessage,
    const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata)
{
    ICommandHelpMetadataSharedPtr helpMetadata = CommandHelpMetadata::Make(usageMessage);
    return std::make_shared<CommandManifest>(
        name,
        description,
        usageMessage,
        helpMetadata,
        parameterSetMetadata);
}

/**
 * The CommandManifest constructor.
 */
CommandManifest::CommandManifest(
    const std::wstring& name,
    const std::wstring& description,
    const std::wstring& usageMessage,
    ICommandHelpMetadataSharedPtr helpMetadata,
    const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata) :
    m_name(name),
    m_description(description),
    m_usageMessage(usageMessage),
    m_helpMetadata(helpMetadata),
    m_parameterSetMetadata(parameterSetMetadata)
{
    base::SmartPointers::Validate(helpMetadata);
}

/**
 * The CommandManifest destructor.
 */
CommandManifest::~CommandManifest()
{
}

/**
 * Gets name of a command.
 */
const std::wstring& CommandManifest::GetName() const
{
    return m_name;
}

/**
 * Gets description of a command.
 */
const std::wstring& CommandManifest::GetDescription() const
{
    return m_description;
}

/**
 * Gets help metadata of a command.
 */
const ICommandHelpMetadata& CommandManifest::GetHelpMetadata() const
{
    return *m_helpMetadata;
}

/**
 * Gets parameter-sets metadata of a command.
 */
void CommandManifest::GetParameterSets(std::vector<IParameterSetMetadataSharedPtr>& parameterSets) const
{
    parameterSets.insert(parameterSets.end(), m_parameterSetMetadata.begin(), m_parameterSetMetadata.end());
}
