package datastructures.cache.core;

import base.core.Conditions;
import datastructures.cache.interfaces.ICacheProperties;

/**
 * The CacheProperties class implements properties of a cache.
 */
public final class CacheProperties implements ICacheProperties {
    private final int capacity;
    private final int numberOfItemsForMakingAvailableSpace;

    /**
     * The CacheProperties constructor.
     */
    public CacheProperties(
        int capacity,
        int numberOfItemsForMakingAvailableSpace) {

        Conditions.validate(
            capacity > 0,
            "The capacity of a cache has to be positive.");

        Conditions.validate(
            numberOfItemsForMakingAvailableSpace <= capacity,
            "The number of items for making available space can not exceed the cache capacity.");

        this.capacity = capacity;
        this.numberOfItemsForMakingAvailableSpace = numberOfItemsForMakingAvailableSpace;
    }

    /**
     * Gets a capacity of a cache.
     */
    @Override
    public int getCapacity() {
        return this.capacity;
    }

    /**
     * Gets the number of items for making available space in the cache.
     */
    @Override
    public int getNumberOfItemsForMakingAvailableSpace() {
        return this.numberOfItemsForMakingAvailableSpace;
    }
}
