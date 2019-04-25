package base.core;

import java.io.FileNotFoundException;
import java.io.FileReader;

/**
 * The Readers class implements complementary APIs for readers.
 */
public final class Readers {
    /**
     * Creates a reader to a file.
     */
    public static FileReader createFileReader(String path) {
        Conditions.validateNotNull(
            path,
            "The path of a file can not be null or empty.");

        FileReader reader;

        try {
            reader = new FileReader(path);
        }
        catch (FileNotFoundException e) {
            String errorMessage =
                "The file at path: " + path + " was not found, due to the following error: " +
                e.getMessage();

            throw new BaseException(errorMessage, e);
        }

        return reader;
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Readers() {
    }
}
