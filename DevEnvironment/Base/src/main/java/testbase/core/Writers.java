package testbase.core;

import base.interfaces.IConstants;
import java.io.BufferedWriter;
import java.io.File;
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
    private static final Logger Log = LoggerFactory.getLogger(Writers.class);

    /**
     * Creates a string writer.
     */
    public static StringWriter createStringWriter() {
        return new StringWriter();
    }

    /**
     * Creates a buffered writer.
     */
    public static BufferedWriter createBufferedWriter(Writer writer) {
        Conditions.validateNotNull(
            writer,
            "The writer for creating a buffered writer.");

        BufferedWriter bufferedWriter = new BufferedWriter(writer);

        return bufferedWriter;
    }

    /**
     * Creates an output stream writer from a file path.
     */
    public static OutputStreamWriter createOutputStreamWriter(Path path) {
      File file = Files.createFile(path);
      OutputStreamWriter writer = Writers.createOutputStreamWriter(file);
      return writer;
    }

    /**
     * Creates an output stream writer from a file.
     */
    public static OutputStreamWriter createOutputStreamWriter(File file) {
        Conditions.validateNotNull(
            file,
            "The file resource.");

      OutputStream stream = Streams.createOutputStream(file);
      OutputStreamWriter writer = Writers.createOutputStreamWriter(stream);

      return writer;
    }

    /**
     * Creates an output stream writer from a stream.
     */
    public static OutputStreamWriter createOutputStreamWriter(OutputStream stream) {
      Conditions.validateNotNull(
          stream,
          "The output stream.");

      OutputStreamWriter writer = new OutputStreamWriter(stream, IConstants.DefaultEncoding);

      return writer;
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

          Writers.Log.error(errorMessage, e);
          throw new BaseException(errorMessage, e);
      }
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

          Writers.Log.error(errorMessage, e);
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

          Writers.Log.error(errorMessage, e);
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

          Writers.Log.warn(warningMessage);
        }
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Writers() {
    }
}
