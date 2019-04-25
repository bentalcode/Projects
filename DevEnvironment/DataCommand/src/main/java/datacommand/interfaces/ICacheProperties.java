package datacommand.interfaces;

/**
 * The ICacheProperties interface defines the properties of a cache.
 */
public interface ICacheProperties {
    /**
     * Gets a size of the cache in bytes.
     */
    long getSizeInBytes();

    /**
     * Gets an intensity factor of a cache.
     */
    double getIntensityFactor();

    /**
     * Gets a reduction factor of a cache.
     */
    double getReductionFactor();
}
