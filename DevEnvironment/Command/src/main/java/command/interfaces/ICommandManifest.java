package command.interfaces;

import base.interfaces.IUnaryComparator;
import json.interfaces.IJsonSerialization;
import java.util.List;

/**
 * The ICommandManifest interface defines manifest of a command.
 */
public interface ICommandManifest extends
    IUnaryComparator<ICommandManifest>,
    IJsonSerialization {

    /**
     * Gets name of a command.
     */
    String getName();

    /**
     * Gets description of a command.
     */
    String getDescription();

    /**
     * Gets help message of a command.
     */
    String getHelpMessage();

    /**
     * Gets parameter-sets of a command.
     */
    List<IParameterSetMetadata> getParameterSets();
}
