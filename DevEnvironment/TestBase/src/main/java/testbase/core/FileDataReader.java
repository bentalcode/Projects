package testbase.core;

import base.core.DestructorHandler;
import base.core.ResourceReader;
import base.core.Scanners;
import java.io.InputStream;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * The FileDataReader class implements a reader of data from a resource.
 */
public final class FileDataReader {
    /**
     * Reads integers from a resource.
     */
    public static List<Integer> readIntegers(Path path, String separator) {
        List<Integer> result = new ArrayList<>();

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            InputStream stream = ResourceReader.open(path);
            destructorHandler.register(stream);
            Scanner scanner = Scanners.createScanner(stream);
            destructorHandler.register(scanner);

            while (scanner.hasNext()) {
                String currLine = scanner.nextLine();

                String[] integerStrings = currLine.split(separator);

                for (String integerString : integerStrings) {
                    integerString = integerString.trim();
                    int number = Integer.parseInt(integerString);
                    result.add(number);
                }
            }
        }

        return result;
    }

    /**
     * Reads longs from a resource.
     */
    public static List<Long> readLongs(Path path, String separator) {
        List<Long> result = new ArrayList<>();

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            InputStream stream = ResourceReader.open(path);
            destructorHandler.register(stream);
            Scanner scanner = Scanners.createScanner(stream);
            destructorHandler.register(scanner);

            while (scanner.hasNext()) {
                String currLine = scanner.nextLine();

                String[] longStrings = currLine.split(separator);

                for (String longString : longStrings) {
                    longString = longString.trim();
                    long number = Long.parseLong(longString);
                    result.add(number);
                }
            }
        }

        return result;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private FileDataReader() {
    }
}
