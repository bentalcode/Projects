package datastructures.cache.core;

import datastructures.cache.interfaces.ICacheProperties;

/**
 * The CacheProperties class implements properties of a cache.
 */
public final class CacheProperties implements ICacheProperties  {
    private final int capacity;

    /**
     * The CacheProperties constructor.
     */
    public CacheProperties(int capacity) {
        this.capacity = capacity;
    }

    /**
     * Gets a capacity of a cache.
     */
    public int getCapacity() {
        return this.capacity;
    }
}
