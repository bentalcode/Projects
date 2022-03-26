package base.core;

import base.BaseException;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.StringWriter;
import java.io.Writer;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Writers class implements complementary APIs for files.
 */
public final class Writers {
    private static final Logger LOG = LoggerFactory.getLogger(Writers.class);

    /**
     * Creates a string writer.
     */
    public static StringWriter createStringWriter() {
        return new StringWriter();
    }

    /**
     * Creates a file writer.
     */
    public static FileWriter createFileWriter(Path path) {
        Conditions.validateNotNull(
            path,
            "The path of a file.");

        FileWriter writer;

        try {
            writer = new FileWriter(path.toString());
        }
        catch (IOException e) {
           String errorMessage =
               "Failed creating a file writer to path: " + path +
               ", due to the following error: " + e.getMessage();

           throw new BaseException(errorMessage);
        }

        return writer;
    }

    /**
     * Creates a buffered writer.
     */
    public static BufferedWriter createBufferedWriter(Writer writer) {
        Conditions.validateNotNull(
            writer,
            "The writer for creating a buffered writer.");

        return new BufferedWriter(writer);
    }

    /**
     * Creates an output stream writer from a file path.
     */
    public static OutputStreamWriter createOutputStreamWriter(Path path) {
        File file = Files.createFile(path);
        return Writers.createOutputStreamWriter(file);
    }

    /**
     * Creates an output stream writer from a file.
     */
    public static OutputStreamWriter createOutputStreamWriter(File file) {
        Conditions.validateNotNull(
            file,
            "The file resource.");

        OutputStream stream = Streams.createOutputStream(file);
        return Writers.createOutputStreamWriter(stream);
    }

    /**
     * Creates an output stream writer from a stream.
     */
    public static OutputStreamWriter createOutputStreamWriter(OutputStream stream) {
        Conditions.validateNotNull(
            stream,
            "The output stream.");

        return new OutputStreamWriter(stream, Constants.DEFAULT_ENCODING);
    }

    /**
     * Writes data to a writer.
     */
    public static void write(Writer writer, String data) {
        Conditions.validateNotNull(
            writer,
            "The writer for writing data to.");

        Conditions.validateNotNull(
            data,
            "The data for writing.");

        try {
            writer.write(data);
        } catch (IOException e) {
            String errorMessage =
                "The Writers class failed writing to a writer " +
                ", due to the following error: " + e.getMessage();

            Writers.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Writes line to a writer.
     */
    public static void writeLine(Writer writer, String data) {
        String dataToWrite = data + "\n";
        write(writer, dataToWrite);
    }

    /**
     * Flushes the written content of a writer.
     */
    public static void flush(Writer writer) {
        Conditions.validateNotNull(
            writer,
            "The writer for flushing it's data.");

        try {
            writer.flush();
        } catch (IOException e) {
            String errorMessage =
                "The Writers class failed flushing written content of a writer" +
                ", due to the following error: " + e.getMessage();

            Writers.LOG.error(errorMessage, e);
            throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Closes a writer.
     */
    public static void close(Writer writer) {
        if (writer == null) {
            return;
        }

        try {
            writer.close();
        } catch (IOException e) {
            String errorMessage =
                "The Writers class failed closing a writer" +
                ", due to the following error: " + e.getMessage();

                Writers.LOG.error(errorMessage, e);
                throw new BaseException(errorMessage, e);
        }
    }

    /**
     * Closes a writer and log a warning in case of a failure.
     */
    public static void closeQuietly(Writer writer) {
        if (writer == null) {
            return;
        }

        try {
            writer.close();
        } catch (IOException e) {
            String warningMessage =
                "The Writers class failed closing a writer due to the following error: " +
                e.getMessage();

            Writers.LOG.warn(warningMessage);
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Writers() {
    }
}
