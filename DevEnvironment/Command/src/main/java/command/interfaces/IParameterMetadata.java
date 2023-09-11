package command.interfaces;

import json.interfaces.IJsonSerialization;

/**
 * The IParameterMetadata interface defines meta-data of a parameter.
 */
public interface IParameterMetadata extends IJsonSerialization {
    /**
     * Gets name of a parameter.
     */
    String getName();

    /**
     * Gets description of a parameter.
     */
    String getDescription();
}
