#include "ParameterSetMetadata.h"
#include "CommandHelpMetadata.h"
#include "VectorIterator.h"

using namespace command;

/**
 * Creates parameter set metadata.
 */
IParameterSetMetadataSharedPtr ParameterSetMetadata::Make(
    const std::vector<IIndexedParameterMetadataSharedPtr> indexedParameters,
    const std::vector<INamedParameterMetadataSharedPtr> namedParameters)
{
    return std::make_shared<ParameterSetMetadata>(indexedParameters, namedParameters);
}

/**
 * Creates help parameter-set.
 */
IParameterSetMetadataSharedPtr ParameterSetMetadata::CreateHelpParameterSet()
{
    std::vector<IIndexedParameterMetadataSharedPtr> indexedParameters;
    std::vector<INamedParameterMetadataSharedPtr> namedParameters;
    namedParameters.push_back(CommandHelpMetadata::CreateHelpParameterMetadata());

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
        m_parameters.push_back(&parameterMetadata->GetParameterMetadata());
    }

    for (INamedParameterMetadataSharedPtr parameterMetadata : m_namedParameters)
    {
        m_parameters.push_back(&parameterMetadata->GetParameterMetadata());
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
void ParameterSetMetadata::GetIndexedParameters(std::vector<IIndexedParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_indexedParameters.begin(), m_indexedParameters.end());
}

/**
 * Gets named parameters of a parameter-set.
 */
void ParameterSetMetadata::GetNamedParameters(std::vector<INamedParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_namedParameters.begin(), m_namedParameters.end());
}

/**
 * Gets the iterator.
 */
base::IIteratorSharedPtr<const IParameterMetadata*> ParameterSetMetadata::GetIterator() const
{
    return base::VectorIterator<const IParameterMetadata*>::Make(m_parameters);
}
