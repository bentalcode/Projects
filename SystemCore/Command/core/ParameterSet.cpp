#include "ParameterSet.h"

using namespace command;

/**
 * Creates a new parameter set.
 */
IParameterSetSharedPtr ParameterSet::Make(
    int index,
    const std::vector<IParameterSharedPtr>& parameters)
{
    return std::make_shared<ParameterSet>(index, parameters);
}

/**
 * The ParameterSet constructor.
 */
ParameterSet::ParameterSet(
    int index,
    const std::vector<IParameterSharedPtr>& parameters) :
    m_index(index)
{
    createParameterMap(parameters);
}

/**
 * The ParameterSet destructor.
 */
ParameterSet::~ParameterSet()
{
}

/**
 * Gets index of a parameter-set.
 */
int ParameterSet::GetIndex() const
{
    return m_index;
}

/**
 * Gets parameters map of a parameter-set.
 */
const ParameterSet::ParameterMap& ParameterSet::GetParameters() const
{
    return m_parameters;
}

/**
 * Gets a parameter by manifest name.
 * The parameter can be null.
 */
IParameterSharedPtr ParameterSet::GetParameter(const std::wstring& name) const
{
    ParameterMap::const_iterator parameterIterator = m_parameters.find(name);

    if (parameterIterator == m_parameters.end())
    {
        return nullptr;
    }

    return parameterIterator->second;
}

/**
 * Checks whether a parameter exists by manifest name.
 */
bool ParameterSet::HasParameter(const std::wstring& name) const
{
    ParameterMap::const_iterator parameterIterator = m_parameters.find(name);
    return parameterIterator != m_parameters.end();
}

/**
 * Creates the parameter map.
 */
void ParameterSet::createParameterMap(const std::vector<IParameterSharedPtr>& parameters)
{
    for (IParameterSharedPtr parameter : parameters)
    {
        m_parameters.insert(std::make_pair(parameter->GetName(), parameter));
    }
}
