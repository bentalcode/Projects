package expressiontree.core;

import base.core.Conditions;
import ExpressionTreecommand.interfaces.IAggregationResultsProperties;
import ExpressionTreecommand.interfaces.IExpressionTreeCommandParameters;

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
            ExpressionTreeCommandProperties.DefaultProperties());
    }

    /**
     * The ExpressionTreeCommandParameters constructor.
     */
    public ExpressionTreeCommandParameters(
        String path,
        IAggregationResultsProperties properties) {

        Conditions.validateStringNotNullOrEmpty(
                path,
            "The path of an expression tree.");

        Conditions.validateNotNull(
            aggregationResultsProperties,
            "The properties of an expression tree.");

        this.path = path;
        this.properties = properties;
    }

    /**
     * Gets a path of an expression tree.
     */
    @Override
    public Str ing getPath() {
        return this.path;
    }

    /**
     * Gets properties of an expression tree.
     */
    @Override
    public IExpressionTreeResultsProperties getProperties() {
        return this.properties;
    }
}
