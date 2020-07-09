package command.core;

import base.core.ArrayLists;
import base.core.Conditions;
import base.core.ParsingResult;
import base.interfaces.IPair;
import base.interfaces.IParser;
import command.interfaces.ICommandManifest;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import command.interfaces.IParameterSet;
import command.interfaces.IParameterSetMetadata;
import base.interfaces.IParsingResult;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The CommandParser class implements a command parser.
 */
public final class CommandParser implements IParser<String[], ICommandParameters> {
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
        // Return if this is a help command...
        //
        if (isHelpCommand(inputParameters)) {
            return createHelpCommandResult();
        }

        //
        // Parse the parameter-sets of the command...
        //
        IParsingResult<IParameterSet> parameterSetResult = this.parseParameterSets(inputParameters);

        if (parameterSetResult.failed()) {
            return ParsingResult.failureResult(parameterSetResult);
        }

        ICommandParameters commandParameters = new CommandParameters(parameterSetResult.getResult());

        return ParsingResult.successfulResult(commandParameters);
    }

    /**
     * Parses input parameters of a command.
     */
    private IParsingResult<IInputParameters> parseInputParameters(
        String[] arguments,
        int startIndex,
        int endIndex) {

        assert(startIndex >= 0 && startIndex < arguments.length);
        assert(endIndex == -1 || endIndex >= startIndex && endIndex < arguments.length);

        List<String> indexedParameters = new ArrayList<>();
        Map<String, String> namedParameters = new HashMap<>();

        if (startIndex > endIndex) {
            return ParsingResult.successfulResult(new InputParameters(
                indexedParameters,
                namedParameters));
        }

        IParser<String, IPair<String, String>> namedParameterParser = new NamedParameterParser();

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
     * Parses parameter-sets of a command..
     */
    private IParsingResult<IParameterSet> parseParameterSets(IInputParameters inputParameters) {
        int parameterSetIndex = 0;

        for (IParameterSetMetadata parameterSetMetadata : this.manifest.getParameterSets()) {
            IParser<IInputParameters, IParameterSet> parameterSetParser = new ParameterSetParser(
                this.manifest.getName(),
                parameterSetIndex,
                parameterSetMetadata);

            IParsingResult<IParameterSet> parameterSetResult = parameterSetParser.parse(inputParameters);

            if (parameterSetResult.succeeded()) {
                return parameterSetResult;
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
     * Checks whether this is a help command.
     */
    private static boolean isHelpCommand(IInputParameters inputParameters) {
        Map<String, String> namedParameters = inputParameters.getNamedParameters();

        return
            namedParameters.size() == 1 &&
            (namedParameters.containsKey(ICommandConstants.helpShortName) ||
             namedParameters.containsKey(ICommandConstants.helpLongName));
    }

    /**
     * Checks a result of a help command.
     */
    private IParsingResult<ICommandParameters> createHelpCommandResult() {
        IParameterSetMetadata parameterSetMetadata = ParameterSetMetadata.createHelpParameterSet();
        List<IParameter> parameters = ArrayLists.of(Parameter.createHelpParameter());
        IParameterSet parameterSet = new ParameterSet(-1, parameterSetMetadata, parameters);
        return ParsingResult.successfulResult(new CommandParameters(parameterSet));
    }
}