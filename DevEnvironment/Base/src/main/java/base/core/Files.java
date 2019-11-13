package base.core;

import base.BaseException;
import base.interfaces.IConstants;
import java.io.File;
import java.io.IOException;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Files class implements complementary APIs for files.
 */
public final class Files {
    private static final Logger Log = LoggerFactory.getLogger(Files.class);

    /**
     * Creates a new file from a path.
     */
    public static File createFile(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file resource.");

        File file = new File(path.toString());

        return file;
    }

    /**
     * Reads a content of a file as string.
     */
    public static String readContent(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file resource.");

        byte[] bytes = Files.readAllBytes(path);
        String content = new String(bytes, IConstants.DefaultEncoding);

        return content;
    }

    /**
     * Reads all bytes of a file.
     */
    public static byte[] readAllBytes(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a resource file.");

        byte[] bytes;

        try {
            bytes = java.nio.file.Files.readAllBytes(path);
        } catch (IOException e) {
            String errorMessage =
                "The Files class failed reading all the bytes from: " + path +
                ", due to the following error: " + e.getMessage();

          Files.Log.error(errorMessage, e);
          throw new BaseException(errorMessage, e);
        }

        return bytes;
    }

    /**
     * Gets a path of a file.
     */
    public static Path getPath(File file) {
        Conditions.validateNotNull(
            file,
            "The file object.");

        return file.toPath();
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Files() {
    }
}
