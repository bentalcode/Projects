package expressiontreecommand.interfaces;

import base.interfaces.IIterator;

/**
 * The IExpressionTreeResults interface defines results of an expression tree.
 */
public interface IExpressionTreeResults extends IIterator<IExpressionTreeResult> {
    /**
     * Adds a new result.
     */
    void add(IExpressionTreeResult result);
}
