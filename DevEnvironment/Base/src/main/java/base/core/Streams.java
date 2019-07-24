package base.core;

import base.interfaces.IConstants;
import java.io.ByteArrayInputStream;
import java.io.Closeable;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.nio.charset.Charset;
import java.nio.file.Path;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Streams class implements complementary APIs for streams.
 */
public final class Streams {
    private static final Logger Log = LoggerFactory.getLogger(Streams.class);

    /**
     * Creates an input stream from a string.
     */
    public static InputStream createInputStream(
        String content,
        Charset encoding) {

        Conditions.validateNotNull(
          content,
          "The content of an input stream");

        Conditions.validateNotNull(
          encoding,
          "The encoding.");

        InputStream stream = new ByteArrayInputStream(content.getBytes(IConstants.DefaultEncoding));

        return stream;
    }

    /**
     * Creates an input stream from a file path.
     */
    public static InputStream createInputStream(Path path) {
        File file = Files.createFile(path);
        InputStream stream = Streams.createInputStream(file);
        return stream;
    }

    /**
     * Creates an input stream from a file.
     */
    public static InputStream createInputStream(File file) {
        Conditions.validateNotNull(
            file,
            "The file resource.");

        InputStream stream;

        try {
            stream = new FileInputStream(file);
        } catch (IOException e) {
          String errorMessage =
              "The Streams class failed opening an input stream to resource: " + file.getPath() +
              ", due to the following error: " +
              e.getMessage();

          Streams.Log.error(errorMessage, e);
          throw new BaseException(errorMessage, e);
        }

        return stream;
    }

    /**
     * Creates an output stream from a file path.
     */
    public static OutputStream createOutputStream(Path path) {
        File file = Files.createFile(path);
        OutputStream stream = Streams.createOutputStream(file);
        return stream;
    }

    /**
     * Creates an output stream from a file.
     */
    public static OutputStream createOutputStream(File file) {
        Conditions.validateNotNull(
            file,
            "The file resource.");

      OutputStream stream;

      try {
          stream = new FileOutputStream(file);
      } catch (IOException e) {
          String errorMessage =
              "The Streams class failed opening an output stream to resource: " + file.getPath() +
              ", due to the following error: " +
              e.getMessage();

          Streams.Log.error(errorMessage, e);
          throw new BaseException(errorMessage, e);
      }

      return stream;
    }

    /**
     * Closes an input stream and log a warning in case of a failure.
     */
    public static void closeQuietly(InputStream stream) {
        Streams.closeStreamQuietly(stream);
    }

    /**
     * Closes an output stream and log a warning in case of a failure.
     */
    public static void closeQuietly(OutputStream stream) {
        Streams.closeStreamQuietly(stream);
    }

    /**
     * Closes a stream and logs a warning in case of a failure.
     */
    private static void closeStreamQuietly(Closeable stream) {
        if (stream == null) {
            return;
        }

        try {
            stream.close();
        } catch (IOException e) {
            String warningMessage =
              "The Streams class failed closing a stream due to the following error: " +
              e.getMessage();

            Streams.Log.warn(warningMessage, e);
        }
    }

  /**
   * Disables the default constructor - This is a static class.
   */
  private Streams() {
  }
}
