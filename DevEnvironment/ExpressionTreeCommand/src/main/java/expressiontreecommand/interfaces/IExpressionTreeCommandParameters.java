package expressiontree.interfaces;

/**
 * The IExpressionTreeCommandParameters interface defines parameters of an expression tree command.
 */
public interface IExpressionTreeCommandParameters {
    /**
     * Gets a path of the data.
     */
    String getDataPath();

    /**
     * Gets properties of an expression tree.
     */
    IExpressionTreeCommandParametersProperties getExpressionTreeProperties();
}
