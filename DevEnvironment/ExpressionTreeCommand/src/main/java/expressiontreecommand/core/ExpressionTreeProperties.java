package expressiontreecommand.core;

import expressiontreecommand.interfaces.IExpressionTreeProperties;

/**
 * The ExpressionTreeProperties class implements properties of an expression tree.
 */
public final class ExpressionTreeProperties implements IExpressionTreeProperties {
    /**
     * Returns the default properties of an expression tree.
     */
    public static IExpressionTreeProperties DefaultProperties() {
        return new ExpressionTreeProperties();
    }

    /**
     * The ExpressionTreeProperties constructor.
     */
    public ExpressionTreeProperties() {
    }
}
