package command.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The INamedParameterMetadata interface defines meta-data of a named parameter.
 */
public interface INamedParameterMetadata extends
    IParameterMetadata,
    IUnaryComparator<INamedParameterMetadata> {

    /**
     * Gets a short name of the parameter.
     */
    String getShortName();

    /**
     * Gets a long name of the parameter.
     */
    String getLongName();

    /**
     * Gets a short name key of the parameter.
     */
    String getShortNameKey();

    /**
     * Gets a long name key of the parameter.
     */
    String getLongNameKey();

    /**
     * Returns whether the parameter is optional.
     */
    boolean optional();

    /**
     * Gets the default value.
     */
    String getDefaultValue();
}
