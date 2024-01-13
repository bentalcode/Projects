#include "ParameterMetadata.h"

using namespace command;

/**
 * The ParameterMetadata constructor.
 */
ParameterMetadata::ParameterMetadata(
    const std::wstring& name,
    const std::wstring& description) :
    m_name(name),
    m_description(description)
{
}

/**
 * The ParameterMetadata destructor.
 */
ParameterMetadata::~ParameterMetadata()
{
}

/**
 * Gets name of a parameter.
 */
const std::wstring& ParameterMetadata::GetName() const
{
    return m_name;
}

/**
 * Gets description of a parameter.
 */
const std::wstring& ParameterMetadata::GetDescription() const
{
    return m_description;
}

/**
 * Try to parse value.
 */
bool ParameterMetadata::TryParseValue(
    const std::map<std::wstring, std::wstring>& parameters,
    std::wstring& value) const
{
    return false;
}