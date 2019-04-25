package datacommand.core;

import base.core.Conditions;
import datacommand.interfaces.AggregationDataStructureType;
import datacommand.interfaces.IAggregationResultsProperties;
import datacommand.interfaces.ICacheProperties;

/**
 * The AggregationResultsProperties class implements properties of an aggregation results.
 */
public final class AggregationResultsProperties implements IAggregationResultsProperties {
    private final AggregationDataStructureType dataStructureType;
    private final int keyMaxSizeInBytes;
    private final int aggregationResultMaxSize;
    private final ICacheProperties cacheProperties;

    /**
     * Returns the default properties of an aggregation results.
     */
    public static IAggregationResultsProperties DefaultProperties() {
        return new AggregationResultsProperties(
            AggregationDataStructureType.BPlusTree,
            32,
            100,
            CacheProperties.DefaultProperties());
    }

    /**
     * The AggregationResultsProperties constructor.
     */
    public AggregationResultsProperties(
        AggregationDataStructureType dataStructureType,
        int keyMaxSizeInBytes,
        int aggregationResultMaxSize,
        ICacheProperties cacheProperties) {

        Conditions.validate(
            keyMaxSizeInBytes > 0,
            "The max size of a key has to be positive.");

        Conditions.validate(
            aggregationResultMaxSize > 0,
            "The max size of an aggregation result has to be positive.");

        Conditions.validateNotNull(
            cacheProperties,
            "The properties of a cache can not be null.");

        this.dataStructureType = dataStructureType;
        this.keyMaxSizeInBytes = keyMaxSizeInBytes;
        this.aggregationResultMaxSize = aggregationResultMaxSize;
        this.cacheProperties = cacheProperties;
    }

    /**
     * Gets data-structure type of an aggregation.
     */
    @Override
    public AggregationDataStructureType getDataStructureType() {
        return this.dataStructureType;
    }

    /**
     * Gets a max size of a key in bytes.
     */
    @Override
    public int getKeyMaxSizeInBytes() {
        return this.keyMaxSizeInBytes;
    }

    /**
     * Gets a max size of an aggregation result in bytes.
     */
    @Override
    public int getAggregationResultMaxSize() {
        return this.aggregationResultMaxSize;
    }

    /**
     * Gets properties of a cache.
     */
    @Override
    public ICacheProperties getCacheProperties() {
        return this.cacheProperties;
    }
}
