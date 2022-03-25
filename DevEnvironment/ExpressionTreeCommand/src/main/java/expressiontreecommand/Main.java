package expressiontreecommand;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Scanners;
import expressiontreecommand.core.ExpressionTreeCommand;
import expressiontreecommand.core.ExpressionTreeCommandParameters;
import expressiontreecommand.interfaces.IExpressionTreeCommand;
import expressiontreecommand.interfaces.IExpressionTreeCommandParameters;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import expressiontreecommand.interfaces.IExpressionTreeResults;
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

            IExpressionTreeCommandParameters parameters = Main.tryParse(args);

            if (parameters == null) {
                Main.usage();
                System.exit(0);

                return;
            }

            //
            // Process the data...
            //
            IExpressionTreeResults results = Main.processData(parameters);

            //
            // Writes the result to the console...
            //
            Main.displayResult(results);

            System.exit(0);
        }
        catch(Exception e) {
            String errorMessage =
                "The Expression Tree Command has failed to process the data due to an unexpected error: " + e.getMessage() +
                ", Exit Status: -1";

            Main.writeErrorMessage(errorMessage);

            System.exit(-1);
        }
    }

    /**
     * Processes data.
     */
    private static IExpressionTreeResults processData(IExpressionTreeCommandParameters parameters) {
        IExpressionTreeCommand command = new ExpressionTreeCommand();

        IExpressionTreeResults results;

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
    private static IExpressionTreeCommandParameters tryParse(String[] args) {
        if (args.length != 1) {
            return null;
        }

        return new ExpressionTreeCommandParameters(args[0]);
    }

    /**
     * Displays usage to an output stream.
     */
    private static void usage() {
        Main.writeInformationalMessage("ExpressionTreeCommand <filePath>");
    }

    /**
     * Displays result to an output stream.
     */
    private static void displayResult(IExpressionTreeResults results) {
        for (IExpressionTreeResult result : results) {
            Main.writeInformationalMessage(result.toString());
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
