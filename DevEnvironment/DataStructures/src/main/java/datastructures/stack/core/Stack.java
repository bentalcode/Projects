package datastructures.stack.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.InvertIterator;
import base.core.InvertReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.collections.core.Collections;
import datastructures.list.core.ArrayList;
import datastructures.list.interfaces.IList;
import datastructures.stack.StackException;
import datastructures.stack.interfaces.IStack;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;

/**
 * The Stack class implements a stack.
 */
public final class Stack<T extends Comparable<T>> implements IStack<T> {
    private static final int DefaultCapacity = 16;

    private final IList<T> data;
    private final IBinaryComparator<IStack<T>> comparator;
    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The Stack constructor.
     */
    public Stack(Class<T> classType) {
        this(
            classType,
            Stack.DefaultCapacity,
            Stack.defaultComparator());
    }

    /**
     * The Stack constructor.
     */
    public Stack(
        Class<T> classType,
        int capacity) {

        this(
            classType,
            capacity,
            Stack.defaultComparator());
    }
    /**
     * The Stack constructor.
     */
    public Stack(
        Class<T> classType,
        int capacity,
        IBinaryComparator<IStack<T>> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a stack.");

        this.data = new ArrayList<>(classType, capacity);
        this.comparator = comparator;
    }

    /**
     * Pushes a new element to the stack.
     */
    @Override
    public void push(T element) {
        this.data.add(element);
    }

    /**
     * Pops the peak element from the stack.
     */
    @Override
    public void pop() {
        if (this.data.empty()) {
            String errorMessage = "The stack is empty.";

            this.log.error(errorMessage);
            throw new StackException(errorMessage);
        }

        this.data.remove(this.size() - 1);
    }

    /**
     * Gets the peek element of the stack.
     */
    @Override
    public T peek() {
        if (this.data.empty()) {
            String errorMessage = "The stack is empty.";

            this.log.error(errorMessage);
            throw new StackException(errorMessage);
        }

        return this.data.get(this.size() - 1);
    }

    /**
     * Gets the size of the stack.
     */
    @Override
    public int size() {
        return this.data.size();
    }

    /**
     * Checks whether the stack is empty.
     */
    @Override
    public boolean empty() {
       return this.size() == 0;
    }

    /**
     * Clears the stack.
     */
    public void clear() {
        this.data.clear();
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return InvertReverseIterator.of(this.data.getReverseIterator());
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return InvertIterator.of(this.data.getIterator());
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
        return this.comparator.getHashCode(this);
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
    public boolean isEqual(IStack<T> other) {
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
    public int compareTo(IStack<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IStack<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of an array.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IStack<T>> {
        private final IBinaryComparator<T> elementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<T> elementComparator) {
            Conditions.validateNotNull(
                elementComparator,
                "The comparator of an element.");

            this.elementComparator = elementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IStack<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IStack<T> lhs, IStack<T> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IStack<T> lhs, IStack<T> rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withIterator(lhs.getIterator(), rhs.getIterator(), this.elementComparator)
                .build();
        }
    }
}
