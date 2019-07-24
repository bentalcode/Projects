package datacommand;

import testbase.core.Conditions;
import testbase.core.DestructorHandler;
import testbase.core.Scanners;
import datacommand.core.DataCommand;
import datacommand.core.DataCommandParameters;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IDataCommand;
import datacommand.interfaces.IDataCommandParameters;
import datacommand.interfaces.IDataResult;
import java.io.PrintStream;
import java.util.Iterator;
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

            IDataCommandParameters parameters = Main.tryParse(args);

            if (parameters == null) {
                Main.usage();
                System.exit(0);

                return;
            }

            /**
             * Process the data...
             */
            IDataResult result = Main.processData(parameters);

            /**
             * Writes the result to the console...
             */
            Main.displayResult(result);

            System.exit(0);
        }
        catch(Exception e) {
            String errorMessage =
                "The Data Command has failed to process the data due to an unexpected error: " + e.getMessage() +
                ", Exit Status: -1";

            Main.writeErrorMessage(errorMessage);

            System.exit(-1);
        }
    }

    /**
     * Processes data.
     */
    private static IDataResult processData(IDataCommandParameters parameters) {

        IDataCommand dataCommand = new DataCommand(parameters);

        IDataResult dataResult;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            Scanner scanner = Scanners.createFileScanner(parameters.getDataPath());
            destructorHandler.register(scanner);

            dataResult = dataCommand.process(scanner);
        }

        return dataResult;
    }

    /**
     * Tries to parse arguments.
     */
    private static IDataCommandParameters tryParse(String[] args) {
        if (args.length != 1) {
            return null;
        }

        return new DataCommandParameters(args[0]);
    }

    /**
     * Displays usage to an output stream.
     */
    private static void usage() {
        Main.writeInformationalMessage("DataCommand <filePath>");
    }

    /**
     * Displays result to an output stream.
     */
    private static void displayResult(IDataResult result) {
        Iterator<IAggregationResult> iterator = result.getIterator();

        while (iterator.hasNext()) {
            IAggregationResult currResult = iterator.next();

            Main.writeInformationalMessage(currResult.toString());
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
     * Writes a warning message.
     */
    private static void writeWarningMessage(String message) {
        PrintStream outputStream = System.err;
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
