package command.core;

import base.core.CollectionIterator;
import base.core.Conditions;
import base.interfaces.IIterator;
import command.interfaces.ICommandParameters;
import command.interfaces.IParameter;
import java.util.List;

/**
 * The CommandParameters class implements parameters of a command.
 */
public final class CommandParameters implements ICommandParameters {
    private final List<IParameter> parameters;

    /**
     * The CommandParameters constructor.
     */
    public CommandParameters(List<IParameter> parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of a command.");

        this.parameters = parameters;
    }

    /**
     * Gets the parameters of the command.
     */
    @Override
    public List<IParameter> getParameters() {
        return this.parameters;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<IParameter> getIterator() {
        return CollectionIterator.of(this.parameters);
    }
}
