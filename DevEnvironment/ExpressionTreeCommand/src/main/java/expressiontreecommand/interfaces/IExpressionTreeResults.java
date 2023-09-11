package expressiontreecommand.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IIterator;

/**
 * The IExpressionTreeResults interface defines results of an expression tree.
 */
public interface IExpressionTreeResults extends IIterable<IExpressionTreeResult>, IIterator<IExpressionTreeResult> {
    /**
     * Adds a new result.
     */
    void add(IExpressionTreeResult result);
}
