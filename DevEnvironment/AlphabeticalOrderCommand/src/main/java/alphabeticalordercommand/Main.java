package alphabeticalordercommand;

import alphabeticalordercommand.core.AlphabeticalOrderCommand;
import alphabeticalordercommand.core.AlphabeticalOrderCommandParameters;
import alphabeticalordercommand.interfaces.IAlphabeticalOrderCommand;
import alphabeticalordercommand.interfaces.IAlphabeticalOrderCommandParameters;
import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Scanners;
import base.interfaces.IIterator;
import java.io.PrintStream;
import java.util.Scanner;

/**
 * The main entry to the module.
 */
public final class Main {
    /**
     * The main entry.
     */
    public static void main(String[] args) {
        try {
            Conditions.validateNotNull(
                args,
                "The arguments of main.");

            IAlphabeticalOrderCommandParameters parameters = Main.tryParse(args);

            if (parameters == null) {
                Main.usage();
                System.exit(0);

                return;
            }

            //
            // Process the data...
            //
            IAlphabeticalOrderResults results = Main.processData(parameters);

            //
            // Writes the results to the console...
            //
            Main.displayResults(results);

            System.exit(0);
        }
        catch(Exception e) {
            String errorMessage =
                "The Alphabetical Order Command has failed to process the data due to an unexpected error: " +
                e.getMessage() +
                ", Exit Status: -1";

            Main.writeErrorMessage(errorMessage);

            System.exit(-1);
        }
    }

    /**
     * Processes data.
     */
    private static IAlphabeticalOrderResults processData(IAlphabeticalOrderCommandParameters parameters) {
        IAlphabeticalOrderCommand command = new AlphabeticalOrderCommand();

        IAlphabeticalOrderResults results;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            Scanner scanner = Scanners.createFileScanner(parameters.getDataPath());
            destructorHandler.register(scanner);

            results = command.process(scanner);
        }

        return results;
    }

    /**
     * Tries to parse arguments.
     */
    private static IAlphabeticalOrderCommandParameters tryParse(String[] args) {
        if (args.length != 1) {
            return null;
        }

        return new AlphabeticalOrderCommandParameters(args[0]);
    }

    /**
     * Displays usage to an output stream.
     */
    private static void usage() {
        Main.writeInformationalMessage("AlphabeticalOrderCommand <filePath>");
    }

    /**
     * Displays results to an output stream.
     */
    private static void displayResults(IAlphabeticalOrderResults results) {
        IIterator<Character> iterator = results.getIterator();

        while (iterator.hasNext()) {
            char currCharacter = iterator.next();

            Main.writeInformationalMessage(String.valueOf(currCharacter));
        }
    }

    /**
     * Writes an informational message.
     */
    private static void writeInformationalMessage(String message) {
        PrintStream outputStream = System.out;
        Main.writeMessage(message, outputStream);
    }

    /**
     * Writes an error message.
     */
    private static void writeErrorMessage(String message) {
        PrintStream outputStream = System.err;
        Main.writeMessage(message, outputStream);
    }

    /**
     * Writes a message to an output stream.
     */
    private static void writeMessage(String message, PrintStream outputStream) {
        outputStream.println(message);
        outputStream.flush();
    }
}
