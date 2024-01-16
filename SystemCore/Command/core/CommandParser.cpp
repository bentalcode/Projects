#include "CommandParser.h"
#include "CommandParameters.h"
#include "ParsingResult.h"
#include "NamedParameterParser.h"
#include "CommandConstants.h"
#include "InputParameters.h"
#include "Parameter.h"
#include "ParameterSet.h"
#include "ParameterSetMetadata.h"
#include "ParameterSetParser.h"
#include "CommandHelpMetadata.h"
#include "SmartPointers.h"
#include "ErrorCodes.h"

using namespace command;

/**
 * The CommandParser constructor.
 */
CommandParser::CommandParser(ICommandManifestSharedPtr manifest)
{
    base::SmartPointers::Validate(manifest);
    m_manifest = manifest;
}

/**
 * The CommandParser destructor.
 */
CommandParser::~CommandParser()
{
}

/**
 * Parses the parameters of the command.
 */
IParsingResultSharedPtr<ICommandParametersSharedPtr> CommandParser::Parse(int argc, wchar_t* argv[])
{
    //
    // Parse the parameters of the command...
    //
    IParsingResultSharedPtr<IInputParametersSharedPtr> inputParametersResult = ParseInputParameters(argc, argv);

    if (inputParametersResult->Failed()) {
        return ParsingResult<ICommandParametersSharedPtr>::FailureResult(inputParametersResult);
    }

    IInputParametersSharedPtr inputParameters = inputParametersResult->GetResult();

    //
    // Return if this is a help command...
    //
    if (IsHelpCommand(*inputParameters))
    {
        return CreateHelpCommandResult();
    }

    //
    // Parse the parameter-sets of the command...
    //
    IParsingResultSharedPtr<IParameterSetSharedPtr> parameterSetResult = ParseParameterSets(*inputParameters);

    if (parameterSetResult->Failed()) {
        return ParsingResult<ICommandParametersSharedPtr>::FailureResult(parameterSetResult);
    }

    ICommandParametersSharedPtr commandParameters = CommandParameters::Make(parameterSetResult->GetResult());

    return ParsingResult<ICommandParametersSharedPtr>::SuccessfulResult(commandParameters);
}

/**
 * Parses input parameters of a command.
 */
IParsingResultSharedPtr<IInputParametersSharedPtr> CommandParser::ParseInputParameters(int argc, wchar_t* argv[])
{
    std::vector<std::wstring> indexedParameters;
    std::map<std::wstring, std::wstring> namedParameters;

    NamedParameterParser namedParameterParser;

    for (size_t index = 1; index < argc; ++index) {
        std::wstring arg(argv[index]);

        if (NamedParameterParser::IsNamedParameter(arg)) {
            IParsingResultSharedPtr<base::PairSharedPtr<std::wstring, std::wstring>> namedParameterResult =
                namedParameterParser.Parse(arg);

            if (namedParameterResult->Failed())
            {
                return ParsingResult<IInputParametersSharedPtr>::FailureResult(namedParameterResult);
            }

            const std::wstring& name = namedParameterResult->GetResult()->GetFirst();
            const std::wstring& value = namedParameterResult->GetResult()->GetSecond();

            if (namedParameters.find(name) != namedParameters.end()) {
                long errorCode = base::ErrorCodes::INVALID_ARG;

                std::wstringstream errorMessageStream;
                errorMessageStream
                    << L"The named parameter: " << name << L" already exists in command line"
                    << base::ErrorMessages::GetErrorCodeMessage(errorCode);

                std::wstring errorMessage = errorMessageStream.str();

                return ParsingResult<IInputParametersSharedPtr>::FailureResult(errorMessage);
            }

            namedParameters.insert(std::make_pair(name, value));
        }
        else
        {
            indexedParameters.push_back(arg);
        }
    }

    IInputParametersSharedPtr inputParameters = InputParameters::Make(
        indexedParameters,
        namedParameters);

    return ParsingResult<IInputParametersSharedPtr>::SuccessfulResult(inputParameters);
}

/**
 * Parses parameter-sets of a command.
 */
IParsingResultSharedPtr<IParameterSetSharedPtr> CommandParser::ParseParameterSets(const IInputParameters& inputParameters)
{
    int parameterSetIndex = 0;

    std::vector<IParameterSetMetadataSharedPtr> parameterSetsMetadata;
    m_manifest->GetParameterSetsMetadata(parameterSetsMetadata);

    for (const IParameterSetMetadataSharedPtr& parameterSetMetadata : parameterSetsMetadata) {
        IParameterSetParserSharedPtr parameterSetParser = ParameterSetParser::Make(
            m_manifest->GetName(),
            parameterSetIndex,
            parameterSetMetadata);

        IParsingResultSharedPtr<IParameterSetSharedPtr> parameterSetResult = parameterSetParser->Parse(
            inputParameters);

        if (parameterSetResult->Succeeded()) {
            return parameterSetResult;
        }

        ++parameterSetIndex;
    }

    std::wstringstream errorMessageStream;
    errorMessageStream
        << L"The input parameters of command: " << m_manifest->GetName()
        << L" do not match any of the defined parameter sets in the manifest of the command.";

    std::wstring errorMessage = errorMessageStream.str();
    return ParsingResult<IParameterSetSharedPtr>::FailureResult(errorMessage);
}

/**
 * Checks whether this is a help command.
 */
bool CommandParser::IsHelpCommand(const IInputParameters& inputParameters)
{
    const IInputParameters::NamedParameters& namedParameters = inputParameters.GetNamedParameters();

    return
        namedParameters.size() == 1 &&
        (namedParameters.find(CommandConstants::HELP_SHORT_NAME) != namedParameters.end() ||
         namedParameters.find(CommandConstants::HELP_LONG_NAME) != namedParameters.end());
}

/**
 * Creates a result of a help command.
 */
IParsingResultSharedPtr<ICommandParametersSharedPtr> CommandParser::CreateHelpCommandResult()
{
    int index = CommandConstants::HELP_PARAMETER_SET_INDEX;
    IParameterSetMetadataSharedPtr metadata = ParameterSetMetadata::CreateHelpMetadata();

    std::vector<IParameterSharedPtr> parameters;
    parameters.push_back(CommandHelpMetadata::CreateHelpParameter());

    IParameterSetSharedPtr parameterSet = ParameterSet::Make(
        index,
        metadata,
        parameters);

    ICommandParametersSharedPtr commandParameters = CommandParameters::Make(parameterSet);
    return ParsingResult<ICommandParametersSharedPtr>::SuccessfulResult(commandParameters);
}
