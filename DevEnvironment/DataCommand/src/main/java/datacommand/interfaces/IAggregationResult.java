package datacommand.interfaces;

/**
 * The IAggregationResult interface defines an aggregation result of the data.
 */
public interface IAggregationResult {
    /**
     * Gets the key.
     */
    String getKey();

    /**
     * Gets the counter of the key.
     */
    long getKeyCounter();

    /**
     * Increments the counter of the key.
     */
    void incrementKeyCounter();

    /**
     * Gets the value with the highest sort order.
     */
    String getHighestSortOrderValue();

    /**
     * Sets the value with the highest sort order.
     */
    void setHighestSortOrderValue(String highestSortOrderValue);

    /**
     * Gets the size of an aggregation result in bytes.
     */
    int getSizeInBytes();
}
