package expressiontreecommand.core;

import base.core.Conditions;
import expressiontreecommand.interfaces.IExpressionTreeCommandParameters;
import expressiontreecommand.interfaces.IExpressionTreeProperties;

/**
 * The ExpressionTreeCommandParameters class implements parameters of an ExpressionTree command.
 */
public final class ExpressionTreeCommandParameters implements IExpressionTreeCommandParameters {
    private final String path;
    private final IExpressionTreeProperties properties;

    /**
     * The ExpressionTreeCommandParameters constructor.
     */
    public ExpressionTreeCommandParameters(String path) {
        this(
            path,
            ExpressionTreeProperties.defaultProperties());
    }

    /**
     * The ExpressionTreeCommandParameters constructor.
     */
    public ExpressionTreeCommandParameters(
        String path,
        IExpressionTreeProperties properties) {

        Conditions.validateStringNotNullOrEmpty(
            path,
            "The path of an expression tree.");

        Conditions.validateNotNull(
            properties,
            "The properties of an expression tree.");

        this.path = path;
        this.properties = properties;
    }

    /**
     * Gets a path of data.
     */
    @Override
    public String getDataPath() {
        return this.path;
    }

    /**
     * Gets properties of an expression tree.
     */
    @Override
    public IExpressionTreeProperties getProperties() {
        return this.properties;
    }
}
