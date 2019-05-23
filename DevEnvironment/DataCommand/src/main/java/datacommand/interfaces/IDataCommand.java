package datacommand.interfaces;

import java.util.Scanner;

/**
 * The IDataCommand interface defines a command for processing data.
 */
public interface IDataCommand {
    /**
     * Processes a stream of data.
     */
    IDataResult process(Scanner stream);
}
