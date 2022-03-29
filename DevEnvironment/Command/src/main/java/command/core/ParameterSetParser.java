package command.core;

import base.core.Conditions;
import base.core.ParsingResult;
import base.interfaces.IParser;
import command.interfaces.IIndexedParameterMetadata;
import command.interfaces.IInputParameters;
import command.interfaces.INamedParameterMetadata;
import command.interfaces.IParameter;
import command.interfaces.IParameterSet;
import command.interfaces.IParameterSetMetadata;
import base.interfaces.IParsingResult;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * The ParameterSetParser class implements a parser of a parameter-set.
 */
public final class ParameterSetParser implements IParser<IInputParameters, IParameterSet> {
    private final String commandName;
    private final int parameterSetIndex;
    private final IParameterSetMetadata metadata;

    /**
     * The ParameterSetParser constructor.
     */
    public ParameterSetParser(
        String commandName,
        int parameterSetIndex,
        IParameterSetMetadata metadata) {

        Conditions.validateNotNull(
            commandName,
            "The name of a command.");

        Conditions.validateNotNull(
            metadata,
            "The metadata of a parameter-set.");

        this.commandName = commandName;
        this.parameterSetIndex = parameterSetIndex;
        this.metadata = metadata;
    }

    /**
     * Parses a parameter-set.
     */
    @Override
    public IParsingResult<IParameterSet> parse(IInputParameters inputParameters) {
        Conditions.validateNotNull(
            inputParameters,
            "The input parameters.");

        IParsingResult<List<IParameter>> result = this.parseIndexedParameters(
            this.metadata.getIndexedParameters(),
            inputParameters.getIndexedParameters());

        if (result.failed()) {
            return ParsingResult.failureResult(result);
        }

        List<IParameter> parameters = new ArrayList<>(result.getResult());

        result = this.parseNamedParameters(
            this.metadata.getNamedParameters(),
            inputParameters.getNamedParameters());

        if (result.failed()) {
            return ParsingResult.failureResult(result);
        }

        parameters.addAll(result.getResult());

        IParameterSet parameterSet = new ParameterSet(
            this.parameterSetIndex,
            this.metadata,
            parameters);

        return ParsingResult.successfulResult(parameterSet);
    }

    /**
     * Parses indexed parameters of a parameter-set.
     */
    private IParsingResult<List<IParameter>> parseIndexedParameters(
        List<IIndexedParameterMetadata> parametersMetadata,
        List<String> indexedParameters) {

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
    }

    /**
     * Parses named parameters of a parameter-set.
     */
    private IParsingResult<List<IParameter>> parseNamedParameters(
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
    }
}
