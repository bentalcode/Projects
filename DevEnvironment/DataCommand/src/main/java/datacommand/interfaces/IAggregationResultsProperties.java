package datacommand.interfaces;

/**
 * The IAggregationResultsProperties interface defines properties of an aggregation results.
 */
public interface IAggregationResultsProperties {

    /**
     * Gets data-structure type of an aggregation.
     */
    AggregationDataStructureType getDataStructureType();

    /**
     * Gets a max size of a key in bytes.
     */
    int getKeyMaxSizeInBytes();

    /**
     * Gets a max size of an aggregation result in bytes.
     */
    int getAggregationResultMaxSize();

    /**
     * Gets properties of a cache.
     */
    ICacheProperties getCacheProperties();
}
