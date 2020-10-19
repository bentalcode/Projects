#include "PreCompiled.h"
#include "CommandManifest.h"

using namespace command;

/**
 * Creates a new manifest.
 */
ICommandManifestPtr CommandManifest::make(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage)
{
    return std::make_shared<CommandManifest>(
        name,
        description,
        usageMessage);
}

/**
 * The CommandManifest constructor.
 */
CommandManifest::CommandManifest(
    const std::string& name,
    const std::string& description,
    const std::string& usageMessage) :
    m_name(name),
    m_description(description),
    m_usageMessage(usageMessage)
{
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
 * Gets usage message of a command.
 */
const std::string& CommandManifest::getUsageMessage() const
{
    return m_usageMessage;
}
