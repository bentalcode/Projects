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
    std::vector<IIndexedParameterMetadataSharedPtr> indexedParametersMetadata;
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
    std::vector<INamedParameterMetadataSharedPtr> namedParametersMetadata;
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

    /*




    IParameterSet parameterSet = new ParameterSet(
            this.parameterSetIndex,
            this.metadata,
            parameters);

    return ParsingResult.successfulResult(parameterSet);*/
}

/**
 * Parses indexed parameters of a parameter-set.
 */
IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> ParameterSetParser::ParseIndexedParameters(
    const std::vector<IIndexedParameterMetadataSharedPtr>& parametersMetadata,
    const std::vector<std::wstring>& indexedParameters) {

    /*
if (indexedParameters.size() != parametersMetadata.size()) {
String errorMessage =
        "The input parameters for ParameterSet " + this.parameterSetIndex +
        " of command: " + this.commandName +
        " includes " + indexedParameters.size() + " indexed parameters," +
        " while it's metadata includes " + parametersMetadata.size() +
        "; Exactly " + parametersMetadata.size() + " are required.";

return ParsingResult.failureResult(errorMessage);
}

List<IParameter> parameters = new ArrayList<>();

int size = indexedParameters.size();
for (int i = 0; i < size; ++i) {
String parameterValue = indexedParameters.get(i);
IIndexedParameterMetadata parameterMetadata = parametersMetadata.get(i);

IParameter parameter = new Parameter(parameterMetadata, parameterValue);
parameters.add(parameter);
}

return ParsingResult.successfulResult(parameters);
     */

    return nullptr;
}

/**
 * Parses named parameters of a parameter-set.
 */
IParsingResultSharedPtr<std::vector<IParameterSharedPtr>> ParameterSetParser::ParseNamedParameters(
    const std::vector<INamedParameterMetadataSharedPtr>& parametersMetadata,
    const std::map<std::wstring, std::wstring>& namedParameters) {

    /*
List<IParameter> parameters = new ArrayList<>();

for (INamedParameterMetadata parameterMetadata : parametersMetadata) {
String parameterValue;

if (namedParameters.containsKey(parameterMetadata.getShortName())) {
parameterValue = namedParameters.get(parameterMetadata.getShortName());
}
else if (namedParameters.containsKey(parameterMetadata.getLongName())) {
parameterValue = namedParameters.get(parameterMetadata.getLongName());
}
else if (parameterMetadata.optional()) {
parameterValue = parameterMetadata.getDefaultValue();
}
else {
String errorMessage =
        "The input parameters for ParameterSet " + this.parameterSetIndex +
        " of command: " + this.commandName +
        " missing the following named parameter: " + parameterMetadata;

return ParsingResult.failureResult(errorMessage);
}

IParameter parameter = new Parameter(parameterMetadata, parameterValue);
parameters.add(parameter);
}

return ParsingResult.successfulResult(parameters);
     */
    return nullptr;
}