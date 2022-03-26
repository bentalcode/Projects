package base.core;

import base.BaseException;
import base.interfaces.IConstants;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.LineNumberReader;
import java.io.Reader;
import java.io.StringReader;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Readers class implements complementary APIs for readers.
 */
public final class Readers {
    private static final Logger LOG = LoggerFactory.getLogger(Files.class);

    /**
     * Creates a string reader.
     */
    public static StringReader createStringReader(String content) {
        Conditions.validateNotNull(
            content,
            "The content of a string.");

        return new StringReader(content);
    }

    /**
     * Creates an input stream reader from an input stream.
     */
    public static InputStreamReader createInputStreamReader(InputStream stream) {
        Conditions.validateNotNull(
            stream,
            "The input stream for creating a reader.");

        return new InputStreamReader(
            stream,
            IConstants.DefaultEncoding);
    }

    /**
     * Creates an input stream reader from a file path.
     */
    public static InputStreamReader createInputStreamReader(Path path) {
        File file = Files.createFile(path);

        InputStreamReader reader;

        try {
            reader = new InputStreamReader(
                new FileInputStream(file),
                IConstants.DefaultEncoding);
        } catch (FileNotFoundException e) {
            String errorMessage =
                "The Readers class failed creating an input stream reader to resource: " + path +
                ", due to the following error: " + e.getMessage();

            Readers.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return reader;
    }

    /**
     * Creates a new line number reader.
     */
    public static LineNumberReader createLineNumberReader(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a resource.");

        return new LineNumberReader(Readers.createInputStreamReader(path));
    }

    /**
     * Creates a new buffered reader.
     */
    public static BufferedReader createBufferedReader(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a resource.");

        return Readers.createBufferedReader(Readers.createInputStreamReader(path));
    }

    /**
     * Creates a new buffered reader.
     */
    public static BufferedReader createBufferedReader(Reader reader) {
        Conditions.validateNotNull(
            reader,
            "The reader of a resource");

        return new BufferedReader(reader);
    }

    /**
     * Creates a new file reader.
     */
    public static FileReader createFileReader(Path path) {
        Conditions.validateNotNull(
            path,
            "The path of a file.");

        FileReader reader;

        try {
            reader = new FileReader(path.toString());
        }
        catch (FileNotFoundException e) {
            String errorMessage =
                "FileReader failed to be created from path: " + path +
                ", due to the following error: " + e.getMessage();

            Readers.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return reader;
    }

    /**
     * Reads a new line with a buffered reader.
     */
    public static String readLine(BufferedReader reader) {
        Conditions.validateNotNull(
            reader,
            "The reader of a resource.");

        String line;

        try {
            line = reader.readLine();
        } catch (IOException e) {
            String errorMessage =
                "The BufferedReader failed reading line due to the following error: " +
                e.getMessage();

            Readers.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }

        return line;
    }

    /**
     * Closes a reader and log a warning in case of a failure.
     */
    public static void closeQuietly(Reader reader) {
        if (reader == null) {
            return;
        }

        try {
            reader.close();
        } catch (IOException e) {
            String warningMessage =
                "The Readers class failed closing a reader due to the following error: " +
                e.getMessage();

            Readers.LOG.warn(warningMessage);
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Readers() {
    }
}
