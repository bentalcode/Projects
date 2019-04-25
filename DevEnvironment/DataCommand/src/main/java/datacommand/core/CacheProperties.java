package datacommand.core;

import base.core.Conditions;
import datacommand.interfaces.ICacheProperties;

/**
 * The CacheProperties class implements properties of a cache.
 */
public final class CacheProperties implements ICacheProperties {
    private static final long MinimumCacheSize = 1 << 10;
    private static final long MaximumCacheSize = 1 << 30;
    private static final long DefaultCacheSize = 1 << 20;

    private static final double DefaultCacheIntensityFactor = 0.8;
    private static final double DefaultReductionIntensityFactor = 0.4;

    private final long sizeInBytes;
    private final double intensityFactor;
    private final double reductionFactor;

    /**
     * Returns the default properties of an aggregation results.
     */
    public static ICacheProperties DefaultProperties() {
        return new CacheProperties();
    }

    /**
     * The CacheProperties constructor.
     */
    public CacheProperties() {
        this(
            CacheProperties.DefaultCacheSize,
            CacheProperties.DefaultCacheIntensityFactor,
            CacheProperties.DefaultReductionIntensityFactor);
    }

    /**
     * The CacheProperties constructor.
     */
    public CacheProperties(
        long sizeInBytes,
        double intensityFactor,
        double reductionFactor) {

        Conditions.validate(
            sizeInBytes >= CacheProperties.MinimumCacheSize && sizeInBytes <= CacheProperties.MaximumCacheSize,
            "The cache size for processing data is defined at range: " +
            "[" + CacheProperties.MinimumCacheSize + "-" + CacheProperties.MaximumCacheSize + "]");

        Conditions.validate(
            intensityFactor > 0 && intensityFactor < 1,
            "The intensity factor of a cache for processing data is defined at range: (0-1)");

        Conditions.validate(
            reductionFactor > 0 && reductionFactor < intensityFactor,
            "The reduction factor of a cache for processing data is defined at range: " +
            "(0-" + intensityFactor + ")");

        this.sizeInBytes = sizeInBytes;
        this.intensityFactor = intensityFactor;
        this.reductionFactor = reductionFactor;
    }

    /**
     * Gets a size of a cache in bytes.
     */
    @Override
    public long getSizeInBytes() {
        return this.sizeInBytes;
    }

    /**
     * Gets an intensity factor of a cache.
     */
    @Override
    public double getIntensityFactor() {
        return this.intensityFactor;
    }

    /**
     * Gets a reduction factor of a cache.
     */
    @Override
    public double getReductionFactor() {
        return this.reductionFactor;
    }
}
