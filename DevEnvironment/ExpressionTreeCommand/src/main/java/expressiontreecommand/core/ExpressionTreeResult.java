package expressiontreecommand.core;

import base.core.Conditions;
import expressiontreecommand.interfaces.IExpressionTreeResult;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The ExpressionTreeResult class implements a result of an expression tree.
 */
public final class ExpressionTreeResult implements IExpressionTreeResult {
    private final String expression;
    private final double result;

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The ExpressionTreeResult constructor.
     */
    public ExpressionTreeResult(String expression, double result) {
        Conditions.validateNotNull(
            expression,
            "The expression.");

        this.expression = expression;
        this.result = result;
    }

    /**
     * Gets an expression.
     */
    @Override
    public String getExpression() {
        return this.expression;
    }

    /**
     * Gets result of an expression.
     */
    @Override
    public double getResult() {
        return this.result;
    }

    /**
     * Gets result of an expression.
     */
    @Override
    public String toString() {
        return this.expression + " ? = " + this.result;
    }
}
