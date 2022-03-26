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
    private static final long MINIMUM_CACHE_SIZE = 1 << 10;
    private static final long MAXIMUM_CACHE_SIZE = 1 << 30;
    private static final long DEFAULT_CACHE_SIZE = 1 << 20;

    private static final double MINIMUM_INTENSITY_FACTOR = 0;
    private static final double MAXIMUM_INTENSITY_FACTOR = 1;

    private static final double DEFAULT_CACHE_INTENSITY_FACTOR = 0.8;
    private static final double DEFAULT_SECONDARY_INTENSITY_FACTOR = 0.9;
    private static final double DEFAULT_REDUCTION_INTENSITY_FACTOR = 0.4;

    private static final IRange<Long> CACHE_SIZE_RANGE = Range.make(
        MINIMUM_CACHE_SIZE,
        MAXIMUM_CACHE_SIZE);

    private static final IRange<Double> INTENSITY_FACTOR_RANGE = Range.make(
        RangeType.ExclusiveToExclusive,
        MINIMUM_INTENSITY_FACTOR,
        MAXIMUM_INTENSITY_FACTOR);

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
            CacheProperties.DEFAULT_CACHE_SIZE,
            CacheProperties.DEFAULT_CACHE_INTENSITY_FACTOR,
            CacheProperties.DEFAULT_SECONDARY_INTENSITY_FACTOR,
            CacheProperties.DEFAULT_REDUCTION_INTENSITY_FACTOR);
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
            CACHE_SIZE_RANGE.inRange(sizeInBytes),
            "The cache size for processing data is defined at range: " + CACHE_SIZE_RANGE);

        Conditions.validate(
            INTENSITY_FACTOR_RANGE.inRange(intensityFactor),
            "The intensity factor of a cache for processing data is defined at range: " +
            INTENSITY_FACTOR_RANGE);

        Conditions.validate(
            INTENSITY_FACTOR_RANGE.inRange(secondaryIntensityFactor),
            "The secondary intensity factor of a cache for processing data is defined at range: " +
            INTENSITY_FACTOR_RANGE);

        Conditions.validate(
            INTENSITY_FACTOR_RANGE.inRange(reductionFactor),
            "The reduction factor of a cache for processing data is defined at range: " +
            INTENSITY_FACTOR_RANGE);

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
        return (long)(this.sizeInBytes * this.reductionFactor);
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
