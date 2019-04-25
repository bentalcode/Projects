package base.core;

import base.interfaces.IRange;

/**
 * The Range class implements a range.
 */
public final class Range<T> implements IRange<T> {
    private final T start;
    private final T end;

    /**
     * The Range constructor.
     */
    public Range(T start, T end) {
        this.start = start;
        this.end = end;
    }

    /**
     * Gets the start value.
     */
    @Override
    public T start() {
        return this.start;
    }

    /**
     * Gets the end value.
     */
    @Override
    public T end() {
        return this.end;
    }

    /**
     * Gets the string representation of a range.
     */
    @Override
    public String toString() {
        return "[" + this.start + "-" + this.end + "]";
    }
}
