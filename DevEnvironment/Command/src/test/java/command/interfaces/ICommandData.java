package command.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ICommandData interface defines data of a command.
 */
public interface ICommandData {
    /**
     * Gets the path of a manifest resource.
     */
    Path getManifestResourcePath();

    /**
     * Gets the command line strings.
     */
    List<String> getCommandlineStrings();
}
