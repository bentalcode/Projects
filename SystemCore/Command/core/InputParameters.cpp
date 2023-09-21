#include "InputParameters.h"

using namespace command;

/**
 * Makes new input parameters.
 */
IInputParametersSharedPtr InputParameters::Make(
        const std::vector<std::wstring> &indexedParameters,
        const std::map<std::wstring, std::wstring> &namedParameters)
{
    return std::make_shared<InputParameters>(indexedParameters, namedParameters);
}

/**
 * The InputParameters constructor.
 */
InputParameters::InputParameters(
    const std::vector<std::wstring>& indexedParameters,
    const std::map<std::wstring, std::wstring>& namedParameters) :
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
const InputParameters::IndexedParameters& InputParameters::GetIndexedParameters() const
{
    return m_indexedParameters;
}

/**
 * Gets named parameters.
 */
const InputParameters::NamedParameters& InputParameters::GetNamedParameters() const
{
    return m_namedParameters;
}
