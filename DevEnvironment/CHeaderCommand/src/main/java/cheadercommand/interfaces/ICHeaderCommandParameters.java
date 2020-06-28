package cheadercommand.interfaces;

import java.nio.file.Path;

/**
 * The ICHeaderCommandParameters interface defines parameters of a c-header command.
 */
public interface ICHeaderCommandParameters {
    /**
     * Gets a path of a directory.
     */
    Path getDirectoryPath();

    /**
     * Gets a path of a file.
     */
    Path getFilePath();
}
