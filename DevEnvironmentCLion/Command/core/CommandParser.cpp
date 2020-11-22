#include "PreCompiled.h"
#include "CommandParser.h"
#include "CommandParameters.h"
#include "ParsingResult.h"
#include "NamedParameterParser.h"
#include "CommandConstants.h"
#include "InputParameters.h"
#include "Parameter.h"
#include "CommandHelpMetadata.h"

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
 * Parses the parameters of the command.
 */
base::IParsingResultPtr<ICommandParametersPtr> CommandParser::parse(int argc, char *argv[])
{
    //
    // Parse the parameters of the command...
    //
    base::IParsingResultPtr<IInputParametersPtr> inputParametersResult = parseInputParameters(argc, argv);

    if (inputParametersResult->failed()) {
        return base::ParsingResult<ICommandParametersPtr>::failureResult(inputParametersResult);
    }

    IInputParametersPtr inputParameters = inputParametersResult->getResult();

    //
    // Return if this is a help command...
    //
    if (isHelpCommand(*inputParameters))
    {
        return createHelpCommandResult();
    }

    //
    // Parse the parameter-sets of the command...
    //
    base::IParsingResultPtr<IParameterSetPtr> parameterSetResult = parseParameterSets(*inputParameters);

    if (parameterSetResult->failed()) {
        return base::ParsingResult<ICommandParametersPtr>::failureResult(parameterSetResult);
    }

    ICommandParametersPtr commandParameters = CommandParameters::make(parameterSetResult->getResult());

    return base::ParsingResult<ICommandParametersPtr>::successfulResult(commandParameters);
}

/**
 * Parses input parameters of a command.
 */
base::IParsingResultPtr<IInputParametersPtr> CommandParser::parseInputParameters(int argc, char* argv[])
{
    std::vector<std::string> indexedParameters;
    std::map<std::string, std::string> namedParameters;

    NamedParameterParser namedParameterParser;

    for (int i = 1; i < argc; ++i) {
        std::string arg(argv[i]);

        if (NamedParameterParser::isNamedParameter(arg)) {
            base::IParsingResultPtr<base::PairPtr<std::string, std::string>> namedParameterResult =
                namedParameterParser.parse(arg);

            if (namedParameterResult->failed())
            {
                return base::ParsingResult<IInputParametersPtr>::failureResult(namedParameterResult);
            }

            const std::string& name = namedParameterResult->getResult()->getFirst();
            const std::string& value = namedParameterResult->getResult()->getSecond();

            if (namedParameters.find(name) != namedParameters.end()) {
                std::string errorMessage =
                    "The named parameter: " + name + " + already exists in command line.";

                return base::ParsingResult<IInputParametersPtr>::failureResult(errorMessage);
            }

            namedParameters.insert(std::make_pair(name, value));
        }
        else
        {
            indexedParameters.push_back(arg);
        }
    }

    IInputParametersPtr inputParameters = InputParameters::make(indexedParameters, namedParameters);

    return base::ParsingResult<IInputParametersPtr>::successfulResult(inputParameters);
}

/**
 * Parses parameter-sets of a command.
 */
base::IParsingResultPtr<IParameterSetPtr> CommandParser::parseParameterSets(const IInputParameters& inputParameters)
{
    std::vector<IParameterPtr> parameters;

    const IInputParameters::NamedParameters& namedParameters = inputParameters.getNamedParameters();

    for (IInputParameters::NamedParameters::const_iterator i = namedParameters.begin();
         i != namedParameters.end();
         ++i)
    {
        IParameterPtr parameter = Parameter::make(i->first, i->second, true);
        parameters.push_back(parameter);
    }

    IParameterSetPtr parameterSet = ParameterSet::make(0, parameters);
    return base::ParsingResult<IParameterSetPtr>::successfulResult(parameterSet);
}

/**
 * Checks whether this is a help command.
 */
bool CommandParser::isHelpCommand(const IInputParameters& inputParameters)
{
    const IInputParameters::NamedParameters& namedParameters = inputParameters.getNamedParameters();

    return
        namedParameters.size() == 1 &&
        (namedParameters.find(CommandConstants::helpShortName) != namedParameters.end() ||
         namedParameters.find(CommandConstants::helpLongName) != namedParameters.end());
}

/**
 * Creates a result of a help command.
 */
base::IParsingResultPtr<ICommandParametersPtr> CommandParser::createHelpCommandResult()
{
    std::vector<IParameterPtr> parameters;
    parameters.push_back(CommandHelpMetadata::createHelpParameter());

    IParameterSetPtr parameterSet = ParameterSet::make(
        CommandConstants::helpParameterSetIndex,
        parameters);

    ICommandParametersPtr commandParameters = CommandParameters::make(parameterSet);

    return base::ParsingResult<ICommandParametersPtr>::successfulResult(commandParameters);
}