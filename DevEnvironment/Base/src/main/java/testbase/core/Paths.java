package testbase.core;

import java.io.File;
import java.nio.file.Path;

/**
 * The Paths class implements complementary APIs for paths.
 */
public final class Paths {
    /**
     * Creates a new file path.
     */
    public static Path create(String path) {
        return new File(path).toPath();
    }

    /**
     * Determines whether a path is not null or empty.
     */
    public static boolean isNullOrEmpty(Path path) {
        return path == null || path.toString().isEmpty();
    }

    /**
     * The Paths constructor - Disables the default constructor.
     */
    private Paths() {
    }
}
