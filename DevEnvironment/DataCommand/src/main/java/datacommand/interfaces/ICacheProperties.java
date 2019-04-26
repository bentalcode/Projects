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
     * Gets a size of an intensity zone of the cache in bytes.
     */
    long getIntensityZoneSizeInBytes();

    /**
     * Gets a size of a secondary intensity zone of the cache in bytes.
     */
    long getSecondaryIntensityZoneSizeInBytes();

    /**
     * Gets a size of a reduction of the cache in bytes.
     */
    long getReductionSizeInBytes();

    /**
     * Gets an intensity factor of a cache.
     */
    double getIntensityFactor();

    /**
     * Gets a secondary intensity factor of a cache.
     */
    double getSecondaryIntensityFactor();

    /**
     * Gets a reduction factor of a cache.
     */
    double getReductionFactor();
}
