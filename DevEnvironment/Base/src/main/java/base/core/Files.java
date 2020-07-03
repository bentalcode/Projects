package base.core;

import base.BaseException;
import base.interfaces.IConstants;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Files class implements complementary APIs for files.
 */
public final class Files {
    private static final Logger log = LoggerFactory.getLogger(Files.class);

    /**
     * Creates a new file from a path.
     */
    public static File createFile(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file resource.");

        return new File(path.toString());
    }

    /**
     * Reads a content of a file as string.
     */
    public static String readContent(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file resource.");

        byte[] bytes = Files.readAllBytes(path);
        return new String(bytes, IConstants.DefaultEncoding);
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

          Files.log.error(errorMessage, e);
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
     * Creates a temporary file.
     */
    public static File createTemporaryFile(String prefixName, String postfixName) {
        File file;

        try {
            file = File.createTempFile(prefixName, postfixName);
        }
        catch (IOException e) {
            String errorMessage =
                "Failed to create a temporary file due to the following error: " +
                e.getMessage();

            throw new BaseException(errorMessage);
        }

        file.deleteOnExit();

        return file;
    }

    /**
     * Creates a temporary file.
     */
    public static File createTemporaryFile(
        String prefixName,
        String postfixName,
        String content) {

        File file = Files.createTemporaryFile(prefixName, postfixName);

        try (FileWriter writer = Writers.createFileWriter(file.toPath())) {
            Writers.write(writer, content);
            Writers.flush(writer);
        }
        catch (IOException e) {
            String errorMessage = "Failed to create a temporary file.";
            throw new BaseException(errorMessage);
        }

        file.deleteOnExit();

        return file;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Files() {
    }
}
