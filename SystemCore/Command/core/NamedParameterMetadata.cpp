#include "NamedParameterMetadata.h"
#include "CommandConstants.h"

using namespace command;

/**
 * Creates a parameter meta-data.
 */
IParameterMetadataSharedPtr NamedParameterMetadata::Make(
    const std::wstring& name,
    const std::wstring& shortName,
    const std::wstring& longName,
    const std::wstring& description)
{
    return std::make_shared<NamedParameterMetadata>(
        name,
        shortName,
        longName,
        description,
        false,
        L"");
}

/**
 * Creates an Optional parameter meta-data.
 */
IParameterMetadataSharedPtr NamedParameterMetadata::MakeOptional(
    const std::wstring& name,
    const std::wstring& shortName,
    const std::wstring& longName,
    const std::wstring& description,
    const std::wstring& defaultValue)
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
    const std::wstring& name,
    const std::wstring& shortName,
    const std::wstring& longName,
    const std::wstring& description,
    bool optional,
    const std::wstring& defaultValue) :
    ParameterMetadata(name, description),
    m_shortName(shortName),
    m_longName(longName),
    m_shortNameKey(CommandConstants::SHORT_NAMED_PARAMETER_PREFIX + shortName),
    m_longNameKey(CommandConstants::LONG_NAMED_PARAMETER_PREFIX + longName),
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
 * Gets parameter metadata.
 */
const IParameterMetadata& NamedParameterMetadata::GetParameterMetadata() const
{
    return *this;
}

/**
 * Gets a short name of the parameter.
 */
const std::wstring& NamedParameterMetadata::GetShortName() const
{
    return m_shortName;
}

/**
 * Gets a long name of the parameter.
 */
const std::wstring& NamedParameterMetadata::GetLongName() const
{
    return m_longName;
}

/**
 * Gets a short name key of the parameter.
 */
const std::wstring& NamedParameterMetadata::GetShortNameKey() const
{
    return m_shortNameKey;
}

/**
 * Gets a long name key of the parameter.
 */
const std::wstring& NamedParameterMetadata::GetLongNameKey() const
{
    return m_longNameKey;
}

/**
* Returns whether the parameter is Optional.
*/
bool NamedParameterMetadata::Optional() const
{
    return m_optional;
}

/**
 * Gets the default value.
 */
const std::wstring& NamedParameterMetadata::GetDefaultValue() const
{
    return m_defaultValue;
}

/**
 * Try to parse value.
 */
bool NamedParameterMetadata::TryParseValue(
    const std::map<std::wstring, std::wstring>& parameters,
    std::wstring& value) const
{
    std::map<std::wstring, std::wstring>::const_iterator parameterIterator = parameters.find(GetShortName());

    if (parameterIterator != parameters.end()) {
        value = parameterIterator->second;
        return true;
    }

    parameterIterator = parameters.find(GetLongName());

    if (parameterIterator != parameters.end()) {
        value = parameterIterator->second;
        return true;
    }

    if (Optional()) {
        value = GetDefaultValue();
        return true;
    }

    return false;
}
