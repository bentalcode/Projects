package command.interfaces;

import base.interfaces.IIterable;
import java.util.Map;

/**
 * The IParameterSet interface defines a parameter-set.
 */
public interface IParameterSet extends IIterable<IParameter> {
    /**
     * Gets index of a parameter-set.
     */
    int getIndex();

    /**
     * Gets metadata of a parameter-set.
     */
    IParameterSetMetadata getMetadata();

    /**
     * Gets parameters map of a parameter-set.
     */
    Map<String, IParameter> getParameters();

    /**
     * Gets a parameter by manifest name.
     * The parameter can be null.
     */
    IParameter getParameter(String name);

    /**
     * Checks whether a parameter exists by manifest name.
     */
    boolean hasParameter(String name);
}
