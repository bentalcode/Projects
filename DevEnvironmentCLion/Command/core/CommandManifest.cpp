#include "PreCompiled.h"
#include "CommandManifest.h"
#include "SmartPointers.h"
#include "CommandHelpMetadata.h"

using namespace command;

/**
 * Creates a new manifest.
 */
ICommandManifestPtr CommandManifest::make(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage)
{
    ICommandHelpMetadataPtr helpMetadata = CommandHelpMetadata::make(usageMessage);
    std::vector<IParameterSetMetadataPtr> parameterSetMetadata;

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
ICommandManifestPtr CommandManifest::make(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage,
    const std::vector<IParameterSetMetadataPtr>& parameterSetMetadata)
{
    ICommandHelpMetadataPtr helpMetadata = CommandHelpMetadata::make(usageMessage);
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
    ICommandHelpMetadataPtr helpMetadata,
    const std::vector<IParameterSetMetadataPtr>& parameterSetMetadata) :
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
void CommandManifest::getParameterSets(std::vector<IParameterSetMetadataPtr>& parameterSets) const
{
    parameterSets.insert(parameterSets.end(), m_parameterSetMetadata.begin(), m_parameterSetMetadata.end());
}
