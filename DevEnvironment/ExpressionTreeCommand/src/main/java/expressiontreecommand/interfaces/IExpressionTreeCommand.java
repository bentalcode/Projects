package expressiontreecommand.interfaces;

import java.util.Scanner;

/**
 * The IExpressionTreeCommand interface defines a command for processing an expression tree.
 */
public interface IExpressionTreeCommand {
    /**
     * Processes a stream of data.
     */
    IExpressionTreeResults process(Scanner stream);
}
