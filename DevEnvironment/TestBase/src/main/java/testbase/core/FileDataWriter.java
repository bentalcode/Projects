package testbase.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Writers;
import base.interfaces.IIterator;
import java.io.FileWriter;
import java.io.Writer;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;

/**
 * The FileDataWriter class implements a writer of data to a file.
 */
public final class FileDataWriter {
    /**
     * Writes integers to a file.
     */
    public static void writeIntegers(
        Path path,
        String separator,
        IIterator<Integer> iterator,
        int batchSize) {

        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file.");

        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator of elements.");

        Conditions.validateNotNull(
            iterator,
            "The iterator of elements.");

        Conditions.validate(
            batchSize > 0,
            "The batch size has to be positive.");

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileWriter writer = Writers.createFileWriter(path);
            destructorHandler.register(writer);

            List<Integer> batch = new ArrayList<>(batchSize);

            while (iterator.hasNext()) {
                int currElement = iterator.next();

                batch.add(currElement);

                if (batch.size() == batchSize) {
                    writeIntegers(writer, batch, separator);
                    batch.clear();
                }
            }
        }
    }

    /**
     * Writes longs to a file.
     */
    public static void writeLongs(
        Path path,
        String separator,
        IIterator<Long> iterator,
        int batchSize) {

        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file.");

        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator of elements.");

        Conditions.validateNotNull(
            iterator,
            "The iterator of elements.");

        Conditions.validate(
            batchSize > 0,
            "The batch size has to be positive.");

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileWriter writer = Writers.createFileWriter(path);
            destructorHandler.register(writer);

            List<Long> batch = new ArrayList<>(batchSize);

            while (iterator.hasNext()) {
                long currElement = iterator.next();

                batch.add(currElement);

                if (batch.size() == batchSize) {
                    writeLongs(writer, batch, separator);
                    batch.clear();
                }
            }
        }
    }

    /**
     * Writes integers to a file.
     */
    public static void writeIntegers(
        Path path,
        String separator,
        Collection<Integer> elements,
        int batchSize) {

        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file.");

        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator of elements.");

        Conditions.validateNotNull(
            elements,
            "The collection of elements.");

        Conditions.validate(
            batchSize > 0,
            "The batch size has to be positive.");

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileWriter writer = Writers.createFileWriter(path);
            destructorHandler.register(writer);

            List<Integer> batch = new ArrayList<>(batchSize);

            for (int element : elements) {
                batch.add(element);

                if (batch.size() == batchSize) {
                    writeIntegers(writer, batch, separator);
                    batch.clear();
                }
            }
        }
    }

    /**
     * Writes longs to a file.
     */
    public static void writeLongs(
        Path path,
        String separator,
        Collection<Long> elements,
        int batchSize) {

        Conditions.validatePathNotNullOrEmpty(
            path,
            "The path of a file.");

        Conditions.validateStringNotNullOrEmpty(
            separator,
            "The separator of elements.");

        Conditions.validateNotNull(
            elements,
            "The collection of elements.");

        Conditions.validate(
            batchSize > 0,
            "The batch size has to be positive.");

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            FileWriter writer = Writers.createFileWriter(path);
            destructorHandler.register(writer);

            List<Long> batch = new ArrayList<>(batchSize);

            for (long element : elements) {
                batch.add(element);

                if (batch.size() == batchSize) {
                    writeLongs(writer, batch, separator);
                    batch.clear();
                }
            }
        }
    }

    /**
     * Writes a line of integers.
     */
    private static void writeIntegers(
        Writer writer,
        List<Integer> elements,
        String separator) {

        StringBuilder lineBuilder = new StringBuilder();

        for (int i = 0; i < elements.size(); ++i) {
            int currElement = elements.get(i);

            if (i > 0) {
                lineBuilder.append(separator);
            }

            lineBuilder.append(currElement);
        }

        Writers.writeLine(writer, lineBuilder.toString());
    }

    /**
     * Writes a line of longs.
     */
    private static void writeLongs(
        Writer writer,
        List<Long> elements,
        String separator) {

        StringBuilder lineBuilder = new StringBuilder();

        for (int i = 0; i < elements.size(); ++i) {
            long currElement = elements.get(i);

            if (i > 0) {
                lineBuilder.append(separator);
            }

            lineBuilder.append(currElement);
        }

        Writers.writeLine(writer, lineBuilder.toString());
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private FileDataWriter() {
    }
}
