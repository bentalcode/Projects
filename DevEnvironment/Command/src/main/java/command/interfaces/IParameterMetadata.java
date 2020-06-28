package command.interfaces;

import json.interfaces.IJsonSerialization;

/**
 * The IParameterMetadata interface defines meta-data of a parameter.
 */
public interface IParameterMetadata extends IJsonSerialization {
    /**
     * Gets a name of a parameter.
     */
    String getName();

    /**
     * Gets a description of a parameter.
     */
    String getDescription();
}
