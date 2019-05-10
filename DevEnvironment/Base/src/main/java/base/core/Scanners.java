package base.core;

import base.interfaces.IDestructor;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import java.io.FileReader;
import java.io.InputStream;
import java.io.StringReader;
import java.nio.file.Path;
import java.util.Scanner;

/**
 * The Scanners class implements complementary APIs for scanners.
 */
public final class Scanners {
    private static final Logger Log = LoggerFactory.getLogger(Scanners.class);

    /**
     * Creates a scanner to a string.
     */
    public static Scanner createStringScanner(String str) {
        Conditions.validateNotNull(
            str,
            "The string to scan.");

        Scanner scanner;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {

            StringReader reader = Readers.createStringReader(str);
            IDestructor readerDestructor = destructorHandler.register(reader);

            try {
                scanner = new Scanner(reader);
                readerDestructor.detach();
            }
            catch (Exception e) {
                String errorMessage =
                    "The Scanner to a string failed to get created" +
                    " due to the following error: " + e.getMessage();

                Scanners.Log.error(errorMessage, e);
                throw new BaseException(errorMessage, e);
            }
        }

        return scanner;
    }

    /**
     * Creates a scanner to a file.
     */
    public static Scanner createFileScanner(String path) {
        Conditions.validateStringNotNullOrEmpty(
            path,
            "The path of a file to scan.");

        return Scanners.createFileScanner(Paths.create(path));
    }

    /**
     * Creates a scanner to a file.
     */
    public static Scanner createFileScanner(Path path) {
        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file to scan.");

        Scanner scanner;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {

            FileReader reader = Readers.createFileReader(path);
            IDestructor readerDestructor = destructorHandler.register(reader);

            try {
                scanner = new Scanner(reader);
                readerDestructor.detach();
            }
            catch (Exception e) {
                String errorMessage =
                    "The Scanner to path: " + path +
                    " failed to get created due to the following error: " + e.getMessage();

                Scanners.Log.error(errorMessage, e);
                throw new BaseException(errorMessage, e);
            }
        }

        return scanner;
    }

    /**
     * Scans an input stream.
     */
    public static String scanStream(InputStream stream) {
        Conditions.validateNotNull(
            stream,
            "The input stream to convert to a string.");

        String result;

        try (Scanner scanner = new Scanner(stream)) {
            scanner.useDelimiter("\\A");

            result = scanner.hasNext() ? scanner.next() : "";
        }

        return result;
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Scanners() {
    }
}
