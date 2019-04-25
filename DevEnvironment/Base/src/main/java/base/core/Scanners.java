package base.core;

import base.interfaces.IDestructor;

import java.io.FileReader;
import java.util.Scanner;

/**
 * The Scanners class implements complementary APIs for scanners.
 */
public final class Scanners {
    /**
     * Creates a scanner to a file.
     */
    public static Scanner createScanner(String path) {
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

                throw new BaseException(errorMessage, e);
            }
        }

        return scanner;
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Scanners() {
    }
}
