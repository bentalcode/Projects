package expressiontreecommand.core;

import base.core.Conditions;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import expressiontreecommand.interfaces.IExpressionTreeResults;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

/**
 * The ExpressionTreeResults class implements results of an expression tree.
 */
public final class ExpressionTreeResults implements IExpressionTreeResults {
    private final List<IExpressionTreeResult> results = new ArrayList<>();
    private int position;

    /**
     * The ExpressionTreeResults constructor.
     */
    public ExpressionTreeResults() {
    }

    /**
     * Adds a new result.
     */
    public void add(IExpressionTreeResult result) {
        Conditions.validateNotNull(
            result,
            "The result of an expression tree.");

        this.results.add(result);
    }

    /**
     * Gets an iterator for iterating over a collection.
     */
    @Override
    public Iterator<IExpressionTreeResult> iterator() {
        this.position = 0;
        return this;
    }

    /**
     * Checks whether there is a next result.
     */
    @Override
    public boolean hasNext() {
        return this.position < this.results.size();
    }

    /**
     * Gets the next result.
     */
    @Override
    public IExpressionTreeResult next() {
        assert(this.hasNext());

        IExpressionTreeResult currResult = this.results.get(this.position);
        ++this.position;

        return currResult;
    }

    /**
     * Removes the current result.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
