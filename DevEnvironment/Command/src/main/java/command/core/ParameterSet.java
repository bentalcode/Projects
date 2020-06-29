package command.core;

import base.core.CollectionIterator;
import base.core.Conditions;
import base.interfaces.IIterator;
import command.interfaces.IParameter;
import command.interfaces.IParameterSet;
import command.interfaces.IParameterSetMetadata;
import java.util.List;

/**
 * The ParameterSet class implements a parameter-set.
 */
public final class ParameterSet implements IParameterSet {
    private final int index;
    private final IParameterSetMetadata metadata;
    private final List<IParameter> parameters;

    /**
     * The ParameterSet constructor.
     */
    public ParameterSet(
        int index,
        IParameterSetMetadata metadata,
        List<IParameter> parameters) {

        Conditions.validateNotNull(
            metadata,
            "The metadata of a parameter-set.");

        Conditions.validateNotNull(
            parameters,
            "The parameters of a parameter-set.");

        this.index = index;
        this.metadata = metadata;
        this.parameters = parameters;
    }

    /**
     * Gets index of a parameter-set.
     */
    @Override
    public int getIndex() {
        return this.index;
    }

    /**
     * Gets metadata of a parameter-set.
     */
    @Override
    public IParameterSetMetadata getMetadata() {
        return this.metadata;
    }

    /**
     * Gets parameters of a parameter-set.
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
