package expressiontreecommand.interfaces;

import java.util.Iterator;

/**
 * The IExpressionTreeResults interface defines results of an expression tree.
 */
public interface IExpressionTreeResults extends Iterable<IExpressionTreeResult>, Iterator<IExpressionTreeResult> {
    /**
     * Adds a new result.
     */
    void add(IExpressionTreeResult result);
}
