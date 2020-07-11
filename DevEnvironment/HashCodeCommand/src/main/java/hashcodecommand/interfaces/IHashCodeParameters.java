package hashcodecommand.interfaces;

import java.nio.file.Path;

/**
 * The IHashCodeParameters interface defines parameters of a hashcode command.
 */
public interface IHashCodeParameters {
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
