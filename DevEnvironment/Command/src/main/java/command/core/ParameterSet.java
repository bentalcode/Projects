package command.core;

import base.core.CollectionIterator;
import base.core.Conditions;
import base.interfaces.IIterator;
import command.interfaces.IParameter;
import command.interfaces.IParameterSet;
import command.interfaces.IParameterSetMetadata;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ParameterSet class implements a parameter-set.
 */
public final class ParameterSet implements IParameterSet {
    private final int index;
    private final IParameterSetMetadata metadata;
    private final Map<String, IParameter> parametersMap;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

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
        this.parametersMap = createParameterMap(parameters);
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
    public Map<String, IParameter> getParameters() {
        return this.parametersMap;
    }

    /**
     * Gets a parameter by manifest id.
     */
    @Override
    public IParameter getParameter(String name) {
        return this.parametersMap.get(name);
    }

    /**
     * Checks whether a parameter exists by manifest name.
     */
    @Override
    public boolean hasParameter(String name) {
        return this.parametersMap.containsKey(name);
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<IParameter> getIterator() {
        return CollectionIterator.make(this.parametersMap.values());
    }

    /**
     * Creates the parameters map.
     */
    private static Map<String, IParameter> createParameterMap(List<IParameter> parameters) {
        Map<String, IParameter> parametersMap = new HashMap<>();

        for (IParameter parameter : parameters) {
            parametersMap.put(parameter.getMetadata().getName(), parameter);
        }

        return parametersMap;
    }
}
