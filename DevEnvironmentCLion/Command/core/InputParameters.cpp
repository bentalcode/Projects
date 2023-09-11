#include "PreCompiled.h"
#include "InputParameters.h"

using namespace command;

/**
 * Makes new input parameters.
 */
IInputParametersPtr InputParameters::make(
    const std::vector<std::string>& indexedParameters,
    const std::map<std::string, std::string>& namedParameters)
{
    return std::make_shared<InputParameters>(indexedParameters, namedParameters);
}

/**
 * The InputParameters constructor.
 */
InputParameters::InputParameters(
    const std::vector<std::string>& indexedParameters,
    const std::map<std::string, std::string>& namedParameters) :
    m_indexedParameters(indexedParameters),
    m_namedParameters(namedParameters)
{
}

/**
 * The InputParameters destructor.
 */
InputParameters::~InputParameters()
{
}

/**
 * Gets indexed parameters.
 */
const InputParameters::IndexedParameters& InputParameters::getIndexedParameters() const
{
    return m_indexedParameters;
}

/**
 * Gets named parameters.
 */
const InputParameters::NamedParameters& InputParameters::getNamedParameters() const
{
    return m_namedParameters;
}
