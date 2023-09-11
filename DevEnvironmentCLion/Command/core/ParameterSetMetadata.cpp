#include "PreCompiled.h"
#include "ParameterSetMetadata.h"
#include "CommandHelpMetadata.h"
#include "VectorIterator.h"

using namespace command;

/**
 * Creates help parameter-set.
 */
IParameterSetMetadataPtr ParameterSetMetadata::createHelpParameterSet()
{
    std::vector<IIndexedParameterMetadataPtr> indexedParameters;
    std::vector<INamedParameterMetadataPtr> namedParameters;
    namedParameters.push_back(CommandHelpMetadata::createHelpParameterMetadata());

    return std::make_shared<ParameterSetMetadata>(
        indexedParameters,
        namedParameters);
}

/**
 * The ParameterSetMetadata constructor.
 */
ParameterSetMetadata::ParameterSetMetadata(
    const std::vector<IIndexedParameterMetadataPtr> indexedParameters,
    const std::vector<INamedParameterMetadataPtr> namedParameters) :
    m_indexedParameters(indexedParameters),
    m_namedParameters(namedParameters)
{
    for (IIndexedParameterMetadataPtr parameterMetadata : m_indexedParameters)
    {
        m_parameters.push_back(parameterMetadata.get());
    }

    for (INamedParameterMetadataPtr parameterMetadata : m_namedParameters)
    {
        m_parameters.push_back(parameterMetadata.get());
    }
}

/**
 * The ParameterSetMetadata destructor.
 */
ParameterSetMetadata::~ParameterSetMetadata()
{
}

/**
 * Gets indexed parameters of a parameter-set.
 */
void ParameterSetMetadata::getIndexedParameters(std::vector<IIndexedParameterMetadataPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_indexedParameters.begin(), m_indexedParameters.end());
}

/**
 * Gets named parameters of a parameter-set.
 */
void ParameterSetMetadata::getNamedParameters(std::vector<INamedParameterMetadataPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_namedParameters.begin(), m_namedParameters.end());
}

/**
 * Gets the iterator.
 */
base::IIteratorPtr<const IParameterMetadata*> ParameterSetMetadata::getIterator() const
{
    return base::VectorIterator<const IParameterMetadata*>::make(m_parameters);
}
