package datacommand.core;

import base.core.Conditions;
import base.core.DestructorHandler;
import base.core.Scanners;
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
        Conditions.validateNotNull(args, "The arguments can not be null.");

        IDataCommandParameters parameters = Main.tryParse(args);

        /**
         * Process the data...
         */
        IDataResult result = Main.processData(parameters);

        /**
         * Writes the result to the console...
         */
        Main.displayResult(
            result,
            System.out);
    }

    /**
     * Processes the data.
     */
    private static IDataResult processData(IDataCommandParameters parameters) {

        IDataCommand dataCommand = new DataCommand(parameters);

        IDataResult dataResult;

        try (DestructorHandler destructorHandler = new DestructorHandler()) {
            Scanner scanner = Scanners.createScanner(parameters.getDataPath());
            destructorHandler.register(scanner);

            dataResult = dataCommand.process(scanner);
        }

        return dataResult;
    }

    /**
     * Writes the result to the writer.
     */
    private static void displayResult(IDataResult result, PrintStream outputStream) {
        Iterator<IAggregationResult> iterator = result.getIterator();

        while (iterator.hasNext()) {
            IAggregationResult currResult = iterator.next();

            outputStream.println(currResult);
            outputStream.flush();
        }
    }

    /**
     * Tries to parse the arguments.
     */
    private static IDataCommandParameters tryParse(String[] args) {
        if (args.length != 1) {
            return null;
        }

        return new DataCommandParameters(args[0]);
    }
}
