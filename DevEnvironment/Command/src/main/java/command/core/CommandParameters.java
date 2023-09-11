package command.core;

import base.core.Conditions;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameterSet;

/**
 * The CommandParameters class implements parameters of a command.
 */
public final class CommandParameters implements ICommandParameters {
    private final IParameterSet parameterSet;

    /**
     * The CommandParameters constructor.
     */
    public CommandParameters(IParameterSet parameterSet) {
        Conditions.validateNotNull(
            parameterSet,
            "The parameter-set of a command.");

        this.parameterSet = parameterSet;
    }

    /**
     * Gets the parameter-set of the command.
     */
    @Override
    public IParameterSet getParameterSet() {
        return this.parameterSet;
    }
}
