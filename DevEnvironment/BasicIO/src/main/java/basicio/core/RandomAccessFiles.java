package basicio.core;

import base.core.Conditions;
import basicio.BasicIOException;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.RandomAccessFile;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The RandomAccessFiles class implements complementary APIs for random access files.
 */
public final class RandomAccessFiles {
    private static final Logger log = LoggerFactory.getLogger(RandomAccessFiles.class);

    /**
     * Creates a random access file.
     */
    public static RandomAccessFile create(Path path, String mode) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file.");

        Conditions.validateStringNotNullOrEmpty(
            mode,
            "The creation mode of a file.");

        try {
            return new RandomAccessFile(path.toFile(), mode);
        }
        catch (FileNotFoundException e) {
            String errorMessage =
                "Failed creating a random access file due to the following error: " + e;

            log.error(errorMessage, e);
            throw new BasicIOException(errorMessage, e);
        }
    }

    /**
     * Sets the file-pointer offset, measured from the beginning of this
     * file, at which the next read or write occurs.
     */
    public static void seek(RandomAccessFile randomAccessFile, long position) {
        Conditions.validateNotNull(
            randomAccessFile,
            "The random access file.");

        try {
            randomAccessFile.seek(position);
        }
        catch (IOException e) {
            String errorMessage =
                "The RandomAccessFile failed setting file-pointer at position: " + position +
                "due to following error: " + e;

            log.error(errorMessage, e);
            throw new BasicIOException(errorMessage, e);
        }
    }

    /**
     * Reads a line from a random access file.
     */
    public static String readLine(RandomAccessFile randomAccessFile) {
        Conditions.validateNotNull(
            randomAccessFile,
            "The random access file.");

        try {
            return randomAccessFile.readLine();
        }
        catch (IOException e) {
            String errorMessage =
                "The RandomAccessFile failed reading a line due to the following error: " + e;

            log.error(errorMessage, e);
            throw new BasicIOException(errorMessage, e);
        }
    }

    /**
     * Gets a file pointer.
     */
    public static long getFilePointer(RandomAccessFile randomAccessFile) {
        Conditions.validateNotNull(
            randomAccessFile,
            "The random access file.");

        try {
            return randomAccessFile.getFilePointer();
        }
        catch (IOException e) {
            String errorMessage =
                "The RandomAccessFile failed getting file pointer due to the following error: " + e;

            log.error(errorMessage, e);
            throw new BasicIOException(errorMessage, e);
        }
    }

    /**
     * Writes a string.
     */
    public static void write(RandomAccessFile randomAccessFile, String content) {
        Conditions.validateNotNull(
            randomAccessFile,
            "The random access file.");

        try {
            randomAccessFile.writeBytes(content);
        }
        catch (IOException e) {
            String errorMessage =
                "The RandomAccessFile failed writing string: " + content +
                " due to the following error: " + e;

            log.error(errorMessage, e);
            throw new BasicIOException(errorMessage, e);
        }
    }
}
