#include "PreCompiled.h"
#include "NamedParameterMetadata.h"
#include "CommandConstants.h"

using namespace command;

/**
 * Creates a parameter meta-data.
 */
INamedParameterMetadataPtr NamedParameterMetadata::make(
    const std::string& name,
    const std::string& shortName,
    const std::string& longName,
    const std::string& description)
{
    return std::make_shared<NamedParameterMetadata>(
        name,
        shortName,
        longName,
        description,
        false,
        "");
}

/**
 * Creates an optional parameter meta-data.
 */
INamedParameterMetadataPtr NamedParameterMetadata::makeOptional(
    const std::string& name,
    const std::string& shortName,
    const std::string& longName,
    const std::string& description,
    const std::string& defaultValue)
{
    return std::make_shared<NamedParameterMetadata>(
        name,
        shortName,
        longName,
        description,
        true,
        defaultValue);
}

/**
 * The NamedParameterMetadata constructor.
 */
NamedParameterMetadata::NamedParameterMetadata(
    const std::string& name,
    const std::string& shortName,
    const std::string& longName,
    const std::string& description,
    bool optional,
    const std::string& defaultValue) :
    ParameterMetadata(name, description),
    m_shortName(shortName),
    m_longName(longName),
    m_shortNameKey(CommandConstants::shortNamedParameterPrefix + shortName),
    m_longNameKey(CommandConstants::longNamedParameterPrefix + longName),
    m_optional(optional),
    m_defaultValue(defaultValue)
{
}

/**
 * The destructor.
 */
NamedParameterMetadata::~NamedParameterMetadata()
{
}

/**
 * Gets a short name of the parameter.
 */
const std::string& NamedParameterMetadata::getShortName() const
{
    return m_shortName;
}

/**
 * Gets a long name of the parameter.
 */
const std::string& NamedParameterMetadata::getLongName() const
{
    return m_longName;
}

/**
 * Gets a short name key of the parameter.
 */
const std::string& NamedParameterMetadata::getShortNameKey() const
{
    return m_shortNameKey;
}

/**
 * Gets a long name key of the parameter.
 */
const std::string& NamedParameterMetadata::getLongNameKey() const
{
    return m_longNameKey;
}

/**
* Returns whether the parameter is optional.
*/
bool NamedParameterMetadata::optional() const
{
    return m_optional;
}

/**
 * Gets the default value.
 */
const std::string& NamedParameterMetadata::getDefaultValue() const
{
    return m_defaultValue;
}