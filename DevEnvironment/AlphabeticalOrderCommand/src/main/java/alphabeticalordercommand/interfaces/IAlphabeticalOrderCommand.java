package alphabeticalordercommand.interfaces;

import java.util.Scanner;

/**
 * The IAlphabeticalOrderCommand interface defines a command for an alphabetical order.
 */
public interface IAlphabeticalOrderCommand {
    /**
     * Processes a stream of data.
     */
    IAlphabeticalOrderResults process(Scanner stream);
}
