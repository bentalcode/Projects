package datacommand.core;

import testbase.core.Conditions;
import testbase.core.Pair;
import base.interfaces.IPair;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IAggregationResults;
import datacommand.interfaces.IDataCommand;
import datacommand.interfaces.IDataCommandParameters;
import datacommand.interfaces.IDataResult;
import java.util.Scanner;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The DataCommand class implements a command for processing data.
 */
public final class DataCommand implements IDataCommand {
    private final IDataCommandParameters parameters;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The DataCommandParameters constructor.
     */
    public DataCommand(IDataCommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of data command.");

        this.parameters = parameters;
    }

    /**
     * Processes a stream of data.
     */
    @Override
    public IDataResult process(Scanner scanner) {
        Conditions.validateNotNull(
            scanner,
            "The scanner of data.");

        //
        // Use a map for aggregating the results of the data...
        //
        IAggregationResults aggregationResults =
            this.parameters.getAggregationResultsProperties().getDataStructureType().createAggregationResults(
                this.parameters.getAggregationResultsProperties());

        //
        // Process the data stream...
        //
        while (scanner.hasNext()) {
            String line = scanner.nextLine();

            IPair<String, String> entry = this.tryParseDataEntry(line);

            if (entry == null) {
                continue;
            }

            //
            // Process data entry...
            //
            this.processDataEntry(
                entry,
                aggregationResults);

            //
            // Reduce the aggregation results if they are in the intensity zone...
            //
            this.reduceAggregationResultsIfRequired(aggregationResults);
        }

        return new DataResult(aggregationResults);
    }

    /**
     * Tries to parse data entry.
     */
    IPair<String, String> tryParseDataEntry(String entry) {
        //
        // Ignore spaces...
        //
        String entryValue = entry.trim();

        //
        // Ignore empty lines...
        //
        if (entryValue.length() == 0) {
            return null;
        }

        String[] keyValue = entryValue.split(" ");

        if (keyValue.length != 2) {
            String errorMessage =
                "The entry line: "  + entry + " is invalid since it does not contain two key-value pair tokens.";

            this.log.error(errorMessage);
            throw new DataCommandException(errorMessage);
        }

        return new Pair<>(keyValue[0], keyValue[1]);
    }

    /**
     * Processes data entry.
     */
    private void processDataEntry(
        IPair<String, String> entry,
        IAggregationResults results) {

        String key = entry.first();
        String value = entry.second();

        if (results.has(key)) {
            IAggregationResult currResult = results.get(key);
            currResult.IncrementKeyCounter();

            if (currResult.getHighestSortOrderValue().compareTo(value) < 0) {
                currResult.setHighestSortOrderValue(value);
            }
        }
        else {
            IAggregationResult currResult = new AggregationResult(key, 1, value);
            results.set(key, currResult);
        }
    }

    /**
     * Reduces the aggregation results if they are in an intensity zone.
     */
    private void reduceAggregationResultsIfRequired(IAggregationResults results) {
        if (!results.inIntensityZone()) {
            return;
        }

        results.reduce();
    }
}
