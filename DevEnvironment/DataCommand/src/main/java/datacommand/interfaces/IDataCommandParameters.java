package datacommand.interfaces;

/**
 * The IDataCommandParameters interface defines the parameters of the data command.
 */
public interface IDataCommandParameters {
    /**
     * Gets a path of the data.
     */
    String getDataPath();

    /**
     * Gets properties of an aggregation results.
     */
    IAggregationResultsProperties getAggregationResultsProperties();
}
