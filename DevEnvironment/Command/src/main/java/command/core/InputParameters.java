package command.core;

import base.core.Conditions;
import command.interfaces.IInputParameters;

import java.util.List;
import java.util.Map;

/**
 * The InputParameters class implements input parameters of a command.
 */
public final class InputParameters implements IInputParameters {
    private final List<String> indexedParameters;
    private final Map<String, String> namedParameters;

    /**
     * The InputParameters constructor.
     */
    public InputParameters(
        List<String> indexedParameters,
        Map<String, String> namedParameters) {

        Conditions.validateNotNull(
            indexedParameters,
            "The indexed parameters.");

        Conditions.validateNotNull(
            namedParameters,
            "The named parameters.");

        this.indexedParameters = indexedParameters;
        this.namedParameters = namedParameters;
    }

    /**
     * Gets indexed parameters.
     */
    @Override
    public List<String> getIndexedParameters() {
        return this.indexedParameters;
    }

    /**
     * Gets named parameters.
     */
    @Override
    public Map<String, String> getNamedParameters() {
        return this.namedParameters;
    }
}
