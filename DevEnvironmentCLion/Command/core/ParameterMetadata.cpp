#include "PreCompiled.h"
#include "ParameterMetadata.h"

using namespace command;

/**
 * The ParameterMetadata constructor.
 */
ParameterMetadata::ParameterMetadata(
    const std::string& name,
    const std::string& description) :
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
const std::string& ParameterMetadata::getName() const
{
    return m_name;
}

/**
 * Gets description of a parameter.
 */
const std::string& ParameterMetadata::getDescription() const
{
    return m_description;
}