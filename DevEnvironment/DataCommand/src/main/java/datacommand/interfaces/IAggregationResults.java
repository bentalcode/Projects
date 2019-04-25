package datacommand.interfaces;

import java.util.Iterator;

/**
 * The IAggregationResults interface defines aggregation results of the data.
 */
public interface IAggregationResults {
    /**
     * Sets an aggregation result.
     */
    void set(String key, IAggregationResult result);

    /**
     * Gets an aggregation result.
     */
    IAggregationResult get(String key);

    /**
     * Checks whether an aggregation result exists.
     */
    boolean has(String key);

    /**
     * Gets an iterator for iterating over the results.
     */
    Iterator<IAggregationResult> getIterator();

    /**
     * Gets the size of results in bytes.
     */
    long getSizeInBytes();

    /**
     * Checks whether the aggregation results are in intensity zone.
     */
    boolean inIntensityZone();

    /**
     * Reduces the aggregation results to the reduction size.
     */
    void reduce();
}
