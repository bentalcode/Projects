#include "CommandParser.h"
#include "CommandParameters.h"
#include "ParsingResult.h"
#include "NamedParameterParser.h"
#include "CommandConstants.h"
#include "InputParameters.h"
#include "Parameter.h"
#include "ParameterSet.h"
#include "ParameterSetMetadata.h"
#include "CommandHelpMetadata.h"
#include "ErrorCodes.h"

using namespace command;

/**
 * The CommandParser constructor.
 */
CommandParser::CommandParser()
{
}

/**
 * The CommandParser destructor.
 */
CommandParser::~CommandParser()
{
}

/**
 * Parses the parameters of the Command.
 */
IParsingResultSharedPtr<ICommandParametersSharedPtr> CommandParser::Parse(int argc, wchar_t* argv[])
{
    //
    // Parse the parameters of the Command...
    //
    IParsingResultSharedPtr<IInputParametersSharedPtr> inputParametersResult = ParseInputParameters(argc, argv);

    if (inputParametersResult->Failed()) {
        return ParsingResult<ICommandParametersSharedPtr>::FailureResult(inputParametersResult);
    }

    IInputParametersSharedPtr inputParameters = inputParametersResult->GetResult();

    //
    // Return if this is a help Command...
    //
    if (IsHelpCommand(*inputParameters))
    {
        return CreateHelpCommandResult();
    }

    //
    // Parse the parameter-sets of the Command...
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

    for (int i = 1; i < argc; ++i) {
        std::wstring arg(argv[i]);

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
                    << L"The named parameter: " << name << L" already exists in Command line"
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

    IInputParametersSharedPtr inputParameters = InputParameters::Make(indexedParameters, namedParameters);

    return ParsingResult<IInputParametersSharedPtr>::SuccessfulResult(inputParameters);
}

/**
 * Parses parameter-sets of a command.
 */
IParsingResultSharedPtr<IParameterSetSharedPtr> CommandParser::ParseParameterSets(const IInputParameters& inputParameters)
{
    std::vector<IParameterSharedPtr> parameters;

    const IInputParameters::NamedParameters& namedParameters = inputParameters.GetNamedParameters();

    for (IInputParameters::NamedParameters::const_iterator i = namedParameters.begin();
         i != namedParameters.end();
         ++i)
    {
        IParameterSharedPtr parameter = Parameter::Make(i->first, i->second, true);
        parameters.push_back(parameter);
    }

    IParameterSetSharedPtr parameterSet = ParameterSet::Make(0, nullptr, parameters);
    return ParsingResult<IParameterSetSharedPtr>::SuccessfulResult(parameterSet);
}

/**
 * Checks whether this is a help Command.
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
 * Creates a result of a help Command.
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
