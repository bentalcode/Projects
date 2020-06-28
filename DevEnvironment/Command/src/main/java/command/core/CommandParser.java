package command.core;

import base.core.Conditions;
import base.interfaces.IPair;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandParameters;
import command.interfaces.IIndexedParameterMetadata;
import command.interfaces.INamedParameterMetadata;
import command.interfaces.IParameter;
import command.interfaces.ICommandParser;
import command.interfaces.IParameterSetMetadata;
import command.interfaces.IParsingResult;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CommandParser class implements a command parser.
 */
public final class CommandParser implements ICommandParser {
    private final ICommandManifest manifest;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The CommandParser constructor.
     */
    public CommandParser(ICommandManifest manifest) {
        Conditions.validateNotNull(
            manifest,
            "The manifest of a command.");

        this.manifest = manifest;
    }

    /**
     * Parses parameters of a command.
     */
    @Override
    public IParsingResult<ICommandParameters> parse(String[] arguments) {
        Conditions.validate(
            arguments != null,
            "The arguments of a command.");

        //
        // Parse the parameters of the command...
        //
        int startIndex = 0;
        int endIndex = arguments.length - 1;

        IParsingResult<IInputParameters> inputParametersResult = this.parseInputParameters(
            arguments,
            startIndex,
            endIndex);

        if (inputParametersResult.failed()) {
            return ParsingResult.failureResult(inputParametersResult);
        }

        IInputParameters inputParameters = inputParametersResult.getResult();

        //
        // Process the parameter-sets of the command...
        //
        int parameterSetIndex = 0;
        for (IParameterSetMetadata parameterSet : this.manifest.getParameterSets()) {
            IParsingResult<List<IParameter>> parameterSetResult = this.parseParameterSet(
                parameterSetIndex,
                parameterSet,
                inputParameters);

            if (parameterSetResult.succeeded()) {
                ICommandParameters commandParameters = new CommandParameters(parameterSetResult.getResult());
                return ParsingResult.successfulResult(commandParameters);
            }

            ++parameterSetIndex;
        }

        String errorMessage =
            "The input parameters of command: " + this.manifest.getName() +
            " do not match any of the defined parameter sets in the manifest of the command.";

        this.log.error(errorMessage);
        return ParsingResult.failureResult(errorMessage);
    }

    /**
     * Parses input parameters of a command.
     */
    private IParsingResult<IInputParameters> parseInputParameters(
        String[] arguments,
        int startIndex,
        int endIndex) {

        assert(startIndex >= 0 && startIndex < arguments.length);
        assert (endIndex == -1 || endIndex >= startIndex && endIndex < arguments.length);

        List<String> indexedParameters = new ArrayList<>();
        Map<String, String> namedParameters = new HashMap<>();

        if (startIndex > endIndex) {
            return ParsingResult.successfulResult(new InputParameters(
                indexedParameters,
                namedParameters));
        }

        NamedParameterParser namedParameterParser = new NamedParameterParser();

        for (int i = startIndex; i <= endIndex; ++i) {
            String arg = arguments[i];

            if (NamedParameterParser.isNamedParameter(arg)) {
                IParsingResult<IPair<String, String>> namedParameterResult = namedParameterParser.parse(arg);

                if (namedParameterResult.failed()) {
                    return ParsingResult.failureResult(namedParameterResult);
                }

                String name = namedParameterResult.getResult().first();
                String value = namedParameterResult.getResult().second();

                if (namedParameters.containsKey(name)) {
                    String errorMessage =
                        "The named parameter: " + name + " + already exists in command line of " +
                        this.manifest.getName();

                    return ParsingResult.failureResult(errorMessage);
                }

                namedParameters.put(name, value);
            }
            else {
                indexedParameters.add(arg);
            }
        }

        return ParsingResult.successfulResult(new InputParameters(
            indexedParameters,
            namedParameters));
    }

    /**
     * Parses a parameter-set of a command.
     */
    private IParsingResult<List<IParameter>> parseParameterSet(
        int parameterSetIndex,
        IParameterSetMetadata parameterSet,
        IInputParameters inputParameters) {

        List<IParameter> parameters = new ArrayList<>();

        IParsingResult<List<IParameter>> result = this.parseIndexedParameters(
            parameterSetIndex,
            parameterSet.getIndexedParameters(),
            inputParameters.getIndexedParameters());

        if (result.failed()) {
            return ParsingResult.failureResult(result);
        }

        parameters.addAll(result.getResult());

        result = this.parseNamedParameters(
            parameterSetIndex,
            parameterSet.getNamedParameters(),
            inputParameters.getNamedParameters());

        if (result.failed()) {
            return ParsingResult.failureResult(result);
        }

        parameters.addAll(result.getResult());

        return ParsingResult.successfulResult(parameters);
    }

    /**
     * Parses indexed parameters of a parameter-set..
     */
    private IParsingResult<List<IParameter>> parseIndexedParameters(
        int parameterSetIndex,
        List<IIndexedParameterMetadata> parametersMetadata,
        List<String> indexedParameters) {

        if (indexedParameters.size() != parametersMetadata.size()) {
            String errorMessage =
                "The input parameters for ParameterSet " + parameterSetIndex +
                " of command: " + this.manifest.getName() +
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
    }

    /**
     * Parses named parameters of a parameter-set.
     */
    private IParsingResult<List<IParameter>> parseNamedParameters(
        int parameterSetIndex,
        List<INamedParameterMetadata> parametersMetadata,
        Map<String, String> namedParameters) {

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
                parameterValue = null;
            }
            else {
                String errorMessage =
                    "The input parameters for ParameterSet " + parameterSetIndex +
                    " of command: " + this.manifest.getName() +
                    " missing the following named parameter: " + parameterMetadata;

                return ParsingResult.failureResult(errorMessage);
            }

            IParameter parameter = new Parameter(parameterMetadata, parameterValue);
            parameters.add(parameter);
        }

        return ParsingResult.successfulResult(parameters);
    }
}
