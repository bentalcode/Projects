package expressiontreecommand.core;

import expressiontreecommand.interfaces.IExpressionTreeProperties;

/**
 * The ExpressionTreeProperties class implements properties of an expression tree.
 */
public final class ExpressionTreeProperties implements IExpressionTreeProperties {
    /**
     * Returns the default properties of an expression tree.
     */
    public static IExpressionTreeProperties defaultProperties() {
        return new ExpressionTreeProperties();
    }

    /**
     * The ExpressionTreeProperties constructor.
     */
    public ExpressionTreeProperties() {
    }
}
