package datacommand.core;

import base.core.Conditions;
import base.core.Range;
import base.core.RangeType;
import base.interfaces.IRange;
import datacommand.interfaces.ICacheProperties;

/**
 * The CacheProperties class implements properties of a cache.
 */
public final class CacheProperties implements ICacheProperties {
    private static final long MinimumCacheSize = 1 << 10;
    private static final long MaximumCacheSize = 1 << 30;
    private static final long DefaultCacheSize = 1 << 20;

    private static final double MinimumIntensityFactor = 0;
    private static final double MaximumIntensityFactor = 1;

    private static final double DefaultCacheIntensityFactor = 0.8;
    private static final double DefaultSecondaryIntensityFactor = 0.9;
    private static final double DefaultReductionIntensityFactor = 0.4;

    private static final IRange<Long> CacheSizeRange = Range.make(
        MinimumCacheSize, MaximumCacheSize);

    private static final IRange<Double> IntensityFactorRange = Range.make(
        RangeType.ExclusiveToExclusive, MinimumIntensityFactor, MaximumIntensityFactor);

    private final long sizeInBytes;
    private final double intensityFactor;
    private final double secondaryIntensityFactor;
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
            CacheProperties.DefaultSecondaryIntensityFactor,
            CacheProperties.DefaultReductionIntensityFactor);
    }

    /**
     * The CacheProperties constructor.
     */
    public CacheProperties(
        long sizeInBytes,
        double intensityFactor,
        double secondaryIntensityFactor,
        double reductionFactor) {

        Conditions.validate(
            CacheSizeRange.inRange(sizeInBytes),
            "The cache size for processing data is defined at range: " + CacheSizeRange);

        Conditions.validate(
            IntensityFactorRange.inRange(intensityFactor),
            "The intensity factor of a cache for processing data is defined at range: " +
            IntensityFactorRange);

        Conditions.validate(
            IntensityFactorRange.inRange(secondaryIntensityFactor),
            "The secondary intensity factor of a cache for processing data is defined at range: " +
            IntensityFactorRange);

        Conditions.validate(
            IntensityFactorRange.inRange(reductionFactor),
            "The reduction factor of a cache for processing data is defined at range: " +
            IntensityFactorRange);

        this.sizeInBytes = sizeInBytes;
        this.intensityFactor = intensityFactor;
        this.secondaryIntensityFactor = secondaryIntensityFactor;
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
     * Gets a size of an intensity zone of the cache in bytes.
     */
    @Override
    public long getIntensityZoneSizeInBytes() {
        return (long)(this.sizeInBytes * this.intensityFactor);
    }

    /**
     * Gets a size of a secondary intensity zone of the cache in bytes.
     */
    @Override
    public long getSecondaryIntensityZoneSizeInBytes() {
        return (long)(this.getIntensityZoneSizeInBytes() * this.secondaryIntensityFactor);
    }

    /**
     * Gets a size of a reduction of the cache in bytes.
     */
    @Override
    public long getReductionSizeInBytes() {
        long size = (long)(this.sizeInBytes * this.reductionFactor);
        return size;
    }

    /**
     * Gets an intensity factor of a cache.
     */
    @Override
    public double getIntensityFactor() {
        return this.intensityFactor;
    }

    /**
     * Gets a secondary intensity factor of a cache.
     */
    @Override
    public double getSecondaryIntensityFactor() {
        return this.secondaryIntensityFactor;
    }

    /**
     * Gets a reduction factor of a cache.
     */
    @Override
    public double getReductionFactor() {
        return this.reductionFactor;
    }
}
