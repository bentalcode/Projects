package cheadercommand.interfaces;

import java.nio.file.Path;

/**
 * The ICHeaderCommandParameters interface defines parameters of a c-header command.
 */
public interface ICHeaderCommandParameters {
    /**
     * Gets the path of a directory.
     */
    Path getDirectoryPath();

    /**
     * Gets the path of a file.
     */
    Path getFilePath();

    /**
     * Gets the recursive flag.
     */
    boolean recurse();
}
