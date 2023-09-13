#include "PreCompiled.h"
#include "ParameterSetMetadata.h"
#include "CommandHelpMetadata.h"
#include "VectorIterator.h"

using namespace command;

/**
 * Creates help parameter-set.
 */
IParameterSetMetadataSharedPtr ParameterSetMetadata::createHelpParameterSet()
{
    std::vector<IIndexedParameterMetadataSharedPtr> indexedParameters;
    std::vector<INamedParameterMetadataSharedPtr> namedParameters;
    namedParameters.push_back(CommandHelpMetadata::createHelpParameterMetadata());

    return std::make_shared<ParameterSetMetadata>(
        indexedParameters,
        namedParameters);
}

/**
 * The ParameterSetMetadata constructor.
 */
ParameterSetMetadata::ParameterSetMetadata(
    const std::vector<IIndexedParameterMetadataSharedPtr> indexedParameters,
    const std::vector<INamedParameterMetadataSharedPtr> namedParameters) :
    m_indexedParameters(indexedParameters),
    m_namedParameters(namedParameters)
{
    for (IIndexedParameterMetadataSharedPtr parameterMetadata : m_indexedParameters)
    {
        m_parameters.push_back(parameterMetadata.get());
    }

    for (INamedParameterMetadataSharedPtr parameterMetadata : m_namedParameters)
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
void ParameterSetMetadata::getIndexedParameters(std::vector<IIndexedParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_indexedParameters.begin(), m_indexedParameters.end());
}

/**
 * Gets named parameters of a parameter-set.
 */
void ParameterSetMetadata::getNamedParameters(std::vector<INamedParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_namedParameters.begin(), m_namedParameters.end());
}

/**
 * Gets the iterator.
 */
base::IIteratorSharedPtr<const IParameterMetadata*> ParameterSetMetadata::getIterator() const
{
    return base::VectorIterator<const IParameterMetadata*>::make(m_parameters);
}
