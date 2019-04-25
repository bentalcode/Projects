package datacommand.core;

import base.core.Conditions;
import base.interfaces.IPrimitiveSize;
import datacommand.interfaces.IAggregationResult;

/**
 * The IAggregationResult class implements an aggregation result of the data.
 */
public final class AggregationResult implements IAggregationResult {
    private String key;
    private long keyCounter;
    private String highestSortOrderValue;

    /**
     * The AggregationResult constructor.
     */
    public AggregationResult(
        String key,
        long keyCounter,
        String highestSortOrderValue) {

        Conditions.validateNotNull(
            key,
            "The key of an aggregation result can not be null.");

        Conditions.validate(
            keyCounter >= 1,
            "The counter of a key of an aggregation result has to be equal or larger than one.");

        Conditions.validateNotNull(
            highestSortOrderValue,
            "The value with the highest sort order can not be null.");

        this.key = key;
        this.keyCounter = keyCounter;
        this.highestSortOrderValue = highestSortOrderValue;
    }

    /**
     * Gets the key.
     */
    @Override
    public String getKey() {
        return this.key;
    }

    /**
     * Gets the counter of the key.
     */
    @Override
    public long getKeyCounter() {
        return this.keyCounter;
    }

    /**
     * Increments the counter of the key.
     */
    @Override
    public void IncrementKeyCounter() {
        ++this.keyCounter;
    }

    /**
     * Gets the value with the highest sort order.
     */
    @Override
    public String getHighestSortOrderValue() {
        return this.highestSortOrderValue;
    }

    /**
     * Sets the value with the highest sort order.
     */
    @Override
    public void setHighestSortOrderValue(String highestSortOrderValue) {
        this.highestSortOrderValue = highestSortOrderValue;
    }

    /**
     * Returns the string representation of this instance.
     */
    @Override
    public String toString() {
        return this.key + ": " + this.keyCounter + ", " + this.highestSortOrderValue;
    }

    /**
     * Gets the size of an aggregation result in bytes.
     */
    @Override
    public int getSizeInBytes() {
        int keySize = this.key.length() * IPrimitiveSize.InBytes.CharacterSize;
        int keyCounterSize = IPrimitiveSize.InBytes.LongSize;
        int valueSize = this.highestSortOrderValue.length() * IPrimitiveSize.InBytes.CharacterSize;

        return keySize + keyCounterSize + valueSize;
    }
}
