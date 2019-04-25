package datacommand.core;

import base.core.Conditions;
import datacommand.interfaces.IAggregationResultsProperties;
import datacommand.interfaces.IDataCommandParameters;

/**
 * The DataCommandParameters class implements parameters of the data command.
 */
public final class DataCommandParameters implements IDataCommandParameters {
    private final String dataPath;
    private final IAggregationResultsProperties aggregationResultsProperties;

    /**
     * The DataCommandParameters constructor.
     */
    public DataCommandParameters(String dataPath) {
        this(
            dataPath,
            AggregationResultsProperties.DefaultProperties());
    }

    /**
     * The DataCommandParameters constructor.
     */
    public DataCommandParameters(
        String dataPath,
        IAggregationResultsProperties aggregationResultsProperties) {

        Conditions.validateStringNotNullOrEmpty(
            dataPath,
            "The path of data can not be null.");

        Conditions.validateNotNull(
            aggregationResultsProperties,
            "The properties of an aggregation results can not be null.");

        this.dataPath = dataPath;
        this.aggregationResultsProperties = aggregationResultsProperties;
    }

    /**
     * Gets a path of the data.
     */
    @Override
    public String getDataPath() {
        return this.dataPath;
    }

    /**
     * Gets properties of an aggregation results.
     */
    @Override
    public IAggregationResultsProperties getAggregationResultsProperties() {
        return this.aggregationResultsProperties;
    }
}
