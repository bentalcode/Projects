package command.interfaces;

import java.util.List;
import java.util.Map;

/**
 * The IInputParameters interface defines input parameters of a command.
 */
public interface IInputParameters {
    /**
     * Gets indexed parameters.
     */
    List<String> getIndexedParameters();

    /**
     * Gets named parameters.
     */
    Map<String, String> getNamedParameters();
}
