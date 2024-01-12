#include "ParameterSetParser.h"
#include "IInputParameters.h"
#include "ParameterSet.h"
#include "ParsingResult.h"
#include "SmartPointers.h"

using namespace command;

/**
 * Creates a new parameter set parser.
 */
IParameterSetParserSharedPtr ParameterSetParser::Make(
    const std::wstring& commandName,
    int parameterSetIndex,
    IParameterSetMetadataSharedPtr metadata)
{
    return std::make_shared<ParameterSetParser>(
        commandName,
        parameterSetIndex,
        metadata);
}

/**
 * The ParameterSetParser constructor.
 */
ParameterSetParser::ParameterSetParser(
    const std::wstring& commandName,
    int parameterSetIndex,
    IParameterSetMetadataSharedPtr metadata) :
    m_commandName(commandName),
    m_parameterSetIndex(parameterSetIndex)
{
    base::SmartPointers::Validate(metadata);
    m_metadata = metadata;
}

/**
 * The ParameterSetParser destructor.
 */
ParameterSetParser::~ParameterSetParser()
{
}

/**
 * Parses a parameter-set.
 */
IParsingResultSharedPtr<IParameterSetSharedPtr> ParameterSetParser::Parse(const IInputParameters& inputParameters)
{
    //
    // Parse indexed parameters...
    //
    std::vector<IParameterMetadataSharedPtr> indexedParametersMetadata;
    m_metadata->GetIndexedParameters(indexedParametersMetadata);

    const IInputParameters::IndexedParameters& indexedParameters = inputParameters.GetIndexedParameters();

    IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> indexedParametersResult = ParseIndexedParameters(
        indexedParametersMetadata,
        indexedParameters);

    if (indexedParametersResult->Failed()) {
        return ParsingResult<IParameterSetSharedPtr>::FailureResult(indexedParametersResult);
    }

    //
    // Parse named parameters...
    //
    std::vector<IParameterMetadataSharedPtr> namedParametersMetadata;
    m_metadata->GetNamedParameters(namedParametersMetadata);

    const IInputParameters::NamedParameters& namedParameters = inputParameters.GetNamedParameters();

    IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> namedParametersResult = ParseNamedParameters(
        namedParametersMetadata,
        namedParameters);

    if (namedParametersResult->Failed()) {
        return ParsingResult<IParameterSetSharedPtr>::FailureResult(namedParametersResult);
    }

    //
    // Create resultant parameter set...
    //
    std::vector<IParameterSharedPtr> parameters(
        indexedParametersResult->GetResult().begin(),
        indexedParametersResult->GetResult().end());

    parameters.insert(
        parameters.end(),
        namedParametersResult->GetResult().begin(),
        namedParametersResult->GetResult().end());

    IParameterSetSharedPtr parameterSet = ParameterSet::Make(
        m_parameterSetIndex,
        m_metadata,
        parameters);

    return ParsingResult<IParameterSetSharedPtr>::SuccessfulResult(parameterSet);
}

/**
 * Parses indexed parameters of a parameter-set.
 */
IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> ParameterSetParser::ParseIndexedParameters(
    const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
    const std::vector<std::wstring>& indexedParameters) {

    return nullptr;
}

/**
 * Parses named parameters of a parameter-set.
 */
IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> ParameterSetParser::ParseNamedParameters(
    const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
    const std::map<std::wstring, std::wstring>& namedParameters) {

    return nullptr;
}
