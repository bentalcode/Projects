package expressiontree.interfaces;

import java.util.Scanner;

/**
 * The IExpressionTreeCommand interface defines a command for processing an expression tree.
 */
public interface IExpressionTreeCommand {
    /**
     * Processes the stream of data.
     */
    IExpressionTreeResult process(Scanner stream);
}
