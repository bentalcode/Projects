package datacommand.core;

import base.core.Conditions;
import datacommand.interfaces.IAggregationResult;
import datacommand.interfaces.IAggregationResults;
import datacommand.interfaces.IAggregationResultsProperties;

/**
 * The AbstractAggregationResults class implements an abstract aggregation results of the data.
 */
public abstract class AbstractAggregationResults implements IAggregationResults {
    private final IAggregationResultsProperties properties;
    private long sizeInBytes;

    /**
     * The AbstractAggregationResults constructor.
     */
    public AbstractAggregationResults(IAggregationResultsProperties properties) {

        Conditions.validateNotNull(
            properties,
            "The properties of an aggregation results can not be null.");

        this.properties = properties;
    }

    /**
     * Sets an aggregation result.
     */
    @Override
    public void set(String key, IAggregationResult result) {
        AbstractAggregationResults.validateKey(key);
        AbstractAggregationResults.validateResult(result);

        //
        // Add the new entry...
        //
        this.addResult(key, result);

        //
        // Update the total size in bytes when a new entry is added...
        //
        this.updateSize(key, result);
    }

    /**
     * Gets an aggregation result.
     */
    @Override
    public IAggregationResult get(String key) {
        AbstractAggregationResults.validateKey(key);

        IAggregationResult result = this.findResult(key);

        if (result == null) {
            String errorMessage = "The aggregation result of key: " + key + " does not exist in the B+ tree.";
            throw new DataCommandException(errorMessage);
        }

        return result;
    }

    /**
     * Checks whether an aggregation result exists.
     */
    @Override
    public boolean has(String key) {
        AbstractAggregationResults.validateKey(key);

        return this.hasResult(key);
    }

    /**
     * Gets the size of results in bytes.
     */
    @Override
    public long getSizeInBytes() {
        return this.sizeInBytes;
    }

    /**
     * Checks whether the aggregation results are in intensity zone.
     */
    @Override
    public boolean inIntensityZone() {
        long currSize = this.getSizeInBytes();
        long intensityZoneSize =
            (long)(
                this.properties.getCacheProperties().getSizeInBytes() *
                this.properties.getCacheProperties().getIntensityFactor());

        return (currSize >= intensityZoneSize);
    }

    /**
     * Reduces the aggregation results to the reduction size.
     */
    @Override
    public void reduce() {
        long reductionSize =
            (long)(
                this.getSizeInBytes() *
                this.properties.getCacheProperties().getReductionFactor());

        this.reduce(reductionSize);
    }

    /**
     * Adds an aggregation result.
     */
    protected abstract void addResult(String key, IAggregationResult result);

    /**
     * Finds an aggregation result.
     */
    protected abstract IAggregationResult findResult(String key);

    /**
     * Checks whether an aggregation result exists.
     */
    protected abstract boolean hasResult(String key);

    /**
     * Calculates the size of the aggregation results.
     */
    protected abstract long calculateSize(String key, IAggregationResult result);

    /**
     * Reduces the aggregation results to the reduction size.
     */
    protected abstract void reduce(long reductionSize);

    /**
     * Updates the size of the aggregation results.
     */
    private void updateSize(String key, IAggregationResult result) {
        this.sizeInBytes = this.calculateSize(key, result);
    }

    /**
     * Validates a key of an aggregation result.
     */
    private static void validateKey(String key) {
        Conditions.validateStringNotNullOrEmpty(
            key,
            "The key of an aggregation result can not be null or empty.");
    }

    /**
     * Validates a key of an aggregation result.
     */
    private static void validateResult(IAggregationResult result) {
        Conditions.validateNotNull(
            result,
            "The aggregation result can not be null.");
    }
}
