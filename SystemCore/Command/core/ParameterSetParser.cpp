#include "ParameterSetParser.h"
#include "IInputParameters.h"
#include "ParameterSet.h"
#include "Parameter.h"
#include "ParsingResult.h"
#include "SmartPointers.h"
#include <sstream>

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

    const IInputParameters::IndexedParameters& indexedParameters =
        inputParameters.GetIndexedParameters();

    IParsingResultSharedPtr<ParameterSetParser::ParameterVectorSharedPtr> indexedParametersResult = ParseIndexedParameters(
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

    IParsingResultSharedPtr<ParameterVectorSharedPtr> namedParametersResult = ParseNamedParameters(
        namedParametersMetadata,
        namedParameters);

    if (namedParametersResult->Failed()) {
        return ParsingResult<IParameterSetSharedPtr>::FailureResult(namedParametersResult);
    }

    //
    // Create resultant parameter set...
    //
    std::vector<IParameterSharedPtr> parameters(
        indexedParametersResult->GetResult()->begin(),
        indexedParametersResult->GetResult()->end());

    parameters.insert(
        parameters.end(),
        namedParametersResult->GetResult()->begin(),
        namedParametersResult->GetResult()->end());

    IParameterSetSharedPtr parameterSet = ParameterSet::Make(
        m_parameterSetIndex,
        m_metadata,
        parameters);

    return ParsingResult<IParameterSetSharedPtr>::SuccessfulResult(parameterSet);
}

/**
 * Parses indexed parameters of a parameter-set.
 */
IParsingResultSharedPtr<ParameterSetParser::ParameterVectorSharedPtr> ParameterSetParser::ParseIndexedParameters(
    const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
    const std::vector<std::wstring>& indexedParameters) {

    //
    // Validate parameters size with metadata definition...
    //
    if (indexedParameters.size() != parametersMetadata.size()) {
        std::wstringstream errorMessageStream;

        errorMessageStream
            << L"The input parameters for ParameterSet " << m_parameterSetIndex
            << L" of command: " << m_commandName
            << L" includes " << indexedParameters.size() << L" indexed parameters,"
            << L" while it's metadata includes " + parametersMetadata.size()
            << L"; Exactly " << parametersMetadata.size() << L" are required.";

        std::wstring errorMessage = errorMessageStream.str();
        return ParsingResult<ParameterSetParser::ParameterVectorSharedPtr>::FailureResult(errorMessage);
    }

    //
    // Create parameters...
    //
    size_t numOfParameters = indexedParameters.size();
    std::vector<IParameterSharedPtr> parameters;
    parameters.reserve(numOfParameters);

    for (size_t index = 0; index < numOfParameters; ++index) {
        std::wstring parameterValue = indexedParameters.at(index);
        IParameterMetadataSharedPtr parameterMetadata = parametersMetadata.at(index);

        IParameterSharedPtr parameter = Parameter::Make(
            parameterMetadata,
            parameterValue);

        parameters.push_back(parameter);
    }

    ParameterVectorSharedPtr parametersSharedPtr = std::make_shared<ParameterVector>(parameters);
    return ParsingResult<ParameterVectorSharedPtr>::SuccessfulResult(parametersSharedPtr);
}

/**
 * Parses named parameters of a parameter-set.
 */
IParsingResultSharedPtr<ParameterSetParser::ParameterVectorSharedPtr> ParameterSetParser::ParseNamedParameters(
    const std::vector<IParameterMetadataSharedPtr>& parametersMetadata,
    const std::map<std::wstring, std::wstring>& namedParameters) {

    return nullptr;
}
