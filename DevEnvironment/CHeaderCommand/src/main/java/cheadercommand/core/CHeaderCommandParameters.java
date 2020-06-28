package cheadercommand.core;

import cheadercommand.interfaces.ICHeaderCommandParameters;
import java.nio.file.Path;

/**
 * The CHeaderCommandParameters class implements parameters of a c-header command.
 */
public final class CHeaderCommandParameters implements ICHeaderCommandParameters {
    private final Path directoryPath;
    private final Path filePath;

    /**
     * The CHeaderCommandParameters constructor.
     */
    public CHeaderCommandParameters(Path directoryPath, Path filePath) {
        this.directoryPath = directoryPath;
        this.filePath = filePath;
    }

    /**
     * Gets a path of a directory.
     */
    @Override
    public Path getDirectoryPath() {
        return this.directoryPath;
    }

    /**
     * Gets a path of a file.
     */
    @Override
    public Path getFilePath() {
        return this.filePath;
    }
}
