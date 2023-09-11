package datastructures.cache.interfaces;

/**
 * The ICacheProperties interface defines properties of a cache.
 */
public interface ICacheProperties {
    /**
     * Gets a capacity of a cache.
     */
    int getCapacity();

    /**
     * Gets the number of items for making available space in the cache.
     */
    int getNumberOfItemsForMakingAvailableSpace();
}
