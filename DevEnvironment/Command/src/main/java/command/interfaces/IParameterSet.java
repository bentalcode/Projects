package command.interfaces;

import base.interfaces.IIterable;
import java.util.List;

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
     * Gets parameters of a parameter-set.
     */
    List<IParameter> getParameters();
}
