package datastructures.string.core;

import base.core.Casting;
import base.core.Comparator;
import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.string.interfaces.ICircularString;

/**
 * The CircularString class implements a circular string.
 */
public final class CircularString implements ICircularString {
    private final String value;
    private final int startIndex;
    private final IBinaryComparator<ICircularString> comparator;
    private final int hashCode;

    /**
     * The CircularString constructor.
     */
    public CircularString(String value) {
        this(
            value,
            0,
            Comparator.defaultComparator());
    }

    /**
     * The CircularString constructor.
     */
    public CircularString(
        String value,
        int startIndex) {

        this(
            value,
            startIndex,
            Comparator.defaultComparator());
    }

    /**
     * The CircularString constructor.
     */
    public CircularString(
        String value,
        int startIndex,
        IBinaryComparator<ICircularString> comparator) {

        Conditions.validateNotNull(
            value,
            "The value of a circular string.");

        this.validateIndex(startIndex, value.length());

        Conditions.validateNotNull(
            comparator,
            "The comparator of a string.");

        this.value = value;
        this.startIndex = startIndex;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the start index.
     */
    @Override
    public int getStartIndex() {
        return this.startIndex;
    }

    /**
     * Gets the value of an index.
     */
    @Override
    public char charAt(int index) {
        this.validateIndex(index);
        int actualIndex = this.increment(this.startIndex, index);
        return this.value.charAt(actualIndex);
    }

    /**
     * Gets the size of a string.
     */
    @Override
    public int size() {
        return this.value.length();
    }

    /**
     * Checks whether a string is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<Character> getIterator() {
        return new CircularStringIterator(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<Character> getReverseIterator() {
        return new CircularStringReverseIterator(this);
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean isEqual(ICircularString other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ICircularString other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Increments an index.
     */
    private int increment(int index, int size) {
        int result = (index + size) % this.value.length();
        return result;
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        this.validateIndex(index, this.value.length());
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index, int length) {
        Conditions.validate(
            index >= 0 && index < length,
            "The index of a circular string is out of range.");
    }
}
