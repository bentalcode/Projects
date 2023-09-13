#include "PreCompiled.h"
#include "CommandManifest.h"
#include "SmartPointers.h"
#include "CommandHelpMetadata.h"

using namespace command;

/**
 * Creates a new manifest.
 */
ICommandManifestSharedPtr CommandManifest::make(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage)
{
    ICommandHelpMetadataSharedPtr helpMetadata = CommandHelpMetadata::make(usageMessage);
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
ICommandManifestSharedPtr CommandManifest::make(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage,
    const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata)
{
    ICommandHelpMetadataSharedPtr helpMetadata = CommandHelpMetadata::make(usageMessage);
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
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage,
    ICommandHelpMetadataSharedPtr helpMetadata,
    const std::vector<IParameterSetMetadataSharedPtr>& parameterSetMetadata) :
    m_name(name),
    m_description(description),
    m_usageMessage(usageMessage),
    m_helpMetadata(helpMetadata),
    m_parameterSetMetadata(parameterSetMetadata)
{
    base::SmartPointers::validate(helpMetadata);
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
const std::string& CommandManifest::getName() const
{
    return m_name;
}

/**
 * Gets description of a command.
 */
const std::string& CommandManifest::getDescription() const
{
    return m_description;
}

/**
 * Gets help metadata of a command.
 */
const ICommandHelpMetadata& CommandManifest::getHelpMetadata() const
{
    return *m_helpMetadata;
}

/**
 * Gets parameter-sets metadata of a command.
 */
void CommandManifest::getParameterSets(std::vector<IParameterSetMetadataSharedPtr>& parameterSets) const
{
    parameterSets.insert(parameterSets.end(), m_parameterSetMetadata.begin(), m_parameterSetMetadata.end());
}
