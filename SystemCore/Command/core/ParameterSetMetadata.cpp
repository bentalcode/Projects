#include "ParameterSetMetadata.h"
#include "CommandHelpMetadata.h"
#include "VectorIterator.h"

using namespace command;

/**
 * Creates parameter set metadata.
 */
IParameterSetMetadataSharedPtr ParameterSetMetadata::Make(
    const std::vector<IParameterMetadataSharedPtr> indexedParameters,
    const std::vector<IParameterMetadataSharedPtr> namedParameters)
{
    return std::make_shared<ParameterSetMetadata>(indexedParameters, namedParameters);
}

/**
 * Creates help parameter-set.
 */
IParameterSetMetadataSharedPtr ParameterSetMetadata::CreateHelpMetadata()
{
    std::vector<IParameterMetadataSharedPtr> indexedParametersMetadata;
    std::vector<IParameterMetadataSharedPtr> namedParametersMetadata;
    namedParametersMetadata.push_back(CommandHelpMetadata::CreateHelpParameterMetadata());

    return std::make_shared<ParameterSetMetadata>(
        indexedParametersMetadata,
        namedParametersMetadata);
}

/**
 * The ParameterSetMetadata constructor.
 */
ParameterSetMetadata::ParameterSetMetadata(
    const std::vector<IParameterMetadataSharedPtr> indexedParameters,
    const std::vector<IParameterMetadataSharedPtr> namedParameters) :
    m_indexedParameters(indexedParameters),
    m_namedParameters(namedParameters)
{
    for (IParameterMetadataSharedPtr parameterMetadata : m_indexedParameters)
    {
        m_parameters.push_back(parameterMetadata);
    }

    for (IParameterMetadataSharedPtr parameterMetadata : m_namedParameters)
    {
        m_parameters.push_back(parameterMetadata);
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
void ParameterSetMetadata::GetIndexedParameters(std::vector<IParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_indexedParameters.begin(), m_indexedParameters.end());
}

/**
 * Gets named parameters of a parameter-set.
 */
void ParameterSetMetadata::GetNamedParameters(std::vector<IParameterMetadataSharedPtr>& parameters) const
{
    parameters.insert(parameters.begin(), m_namedParameters.begin(), m_namedParameters.end());
}

/**
 * Gets the iterator.
 */
base::IIteratorSharedPtr<IParameterMetadataSharedPtr> ParameterSetMetadata::GetIterator() const
{
    return base::VectorIterator<IParameterMetadataSharedPtr>::Make(m_parameters);
}
