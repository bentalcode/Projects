package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderCommand;
import alphabeticalordercommand.interfaces.IAlphabeticalOrderCommandParameters;
import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import base.core.Conditions;
import java.util.List;
import java.util.Scanner;
import base.interfaces.ICalculator;
import java.util.ArrayList;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The AlphabeticalOrderCommand class implements a command for processing alphabetical data.
 */
public final class AlphabeticalOrderCommand implements IAlphabeticalOrderCommand {
    private final IAlphabeticalOrderCommandParameters parameters;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The AlphabeticalOrderCommandParameters constructor.
     */
    public AlphabeticalOrderCommand(IAlphabeticalOrderCommandParameters parameters) {
        Conditions.validateNotNull(
            parameters,
            "The parameters of an alphabetical order command.");

        this.parameters = parameters;
    }

    /**
     * Processes a stream of data.
     */
    @Override
    public IAlphabeticalOrderResults process(Scanner scanner) {
        Conditions.validateNotNull(
            scanner,
            "The scanner of data.");

        //
        // Process the data stream...
        //
        List<String> data = new ArrayList<>();

        while (scanner.hasNext()) {
            String line = scanner.nextLine();

            String entry = this.tryParseDataEntry(line);

            if (entry == null) {
                continue;
            }

            data.add(entry);
        }

        //
        // Calculate the results...
        //
        ICalculator<IAlphabeticalOrderResults> calculator = new AlphabeticalOrderCalculator(data);
        IAlphabeticalOrderResults results = calculator.calculate();

        return results;
    }

    /**
     * Tries to parse data entry.
     */
    private String tryParseDataEntry(String entry) {
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

        String[] values = entryValue.split(" ");

        if (values.length != 1) {
            String errorMessage =
            "The entry line: "  + entry + " is invalid since it does not contain a single value.";

            this.log.error(errorMessage);
            throw new AlphabeticalOrderCommandException(errorMessage);
        }

        return values[0];
    }
}
