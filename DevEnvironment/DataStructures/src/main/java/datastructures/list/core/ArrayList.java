package datastructures.list.core;

import base.core.AbstractBinaryComparator;
import base.core.Arrays;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.list.interfaces.IList;

/**
 * The ArrayList class implements an array list.
 */
public final class ArrayList<T extends Comparable<T>> implements IList<T> {
    private static final int DefaultCapacity = 16;

    private final Class<T> classType;
    private final int capacity;
    private final IBinaryComparator<IList<T>> comparator;
    private T[] array;
    private int size;

    /**
     * The ArrayList constructor.
     */
    public ArrayList(Class<T> classType) {
        this(
            classType,
            ArrayList.DefaultCapacity,
            ArrayList.DefaultComparator());
    }

    /**
     * The ArrayList constructor.
     */
    public ArrayList(
        Class<T> classType,
        int capacity,
        IBinaryComparator<IList<T>> comparator) {

        Conditions.validateNotNull(
            classType,
            "The class type of an element.");

        Conditions.validate(
            capacity > 0,
            "The capacity of an array has to be positive.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a list.");

        this.classType = classType;
        this.capacity = capacity;
        this.comparator = comparator;
        this.array = this.create(capacity);
    }

    /**
     * Appends a specified element to the end of the list.
     */
    @Override
    public void add(T element) {
        int index = this.size;

        if (this.overCapacity()) {
            this.resize();
        }

        this.array[index] = element;
        ++this.size;

        assert(this.size >= 0 && this.size <= this.array.length);
    }

    /**
     * Sets an element at the specified index.
     */
    @Override
    public void set(int index, T element) {
        this.validateIndex(index);

        this.array[index] = element;
    }

    /**
     * Gets an element at the specified index.
     */
    @Override
    public T get(int index) {
        this.validateIndex(index);

        return Casting.cast(this.array[index]);
    }

    /**
     * Removes an element at specified index.
     * Shifts any subsequent elements to the left.
     * Returns the element that was removed from the list.
     */
    @Override
    public T remove(int index) {
        T elementToRemove = this.get(index);

        this.shiftLeft(index + 1, 1);

        return elementToRemove;
    }

    /**
     * Gets the size of an array.
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Checks whether the list is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Clears the elements of the list.
     */
    @Override
    public void clear() {
        this.array = this.create(this.capacity);
    }

    /**
     * Checks whether the list contains an element.
     */
    @Override
    public boolean contains(T element) {
        return this.indexOf(element) != -1;
    }

    /**
     * Gets the corresponding index of the first element which is matching to the specified element.
     * Returns -1 if no element was found.
     */
    @Override
    public int indexOf(T element) {
        int index = 0;

        IIterator<T> iterator = this.getIterator();

        while (iterator.hasNext()) {
            T currElement = iterator.next();

            if (currElement.equals(element)) {
                return index;
            }

            ++index;
        }

        return -1;
    }

    /**
     * Sorts the list.
     */
    @Override
    public void sort() {
        java.util.Arrays.sort(this.array, 0, this.size - 1);
    }

    /**
     * Gets the iterator.
     */
    @Override
    public IIterator<T> getIterator() {
        return ListIterator.of(this);
    }

    /**
     * Gets the reverse iterator.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return ListReverseIterator.of(this);
    }

    /**
     * Converts the array to a native array.
     */
    @Override
    public T[] toArray() {
        if (this.empty()) {
            return null;
        }

        T[] result = Arrays.copy(this.array, this.classType, 0, this.size - 1);
        return result;
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
    public boolean isEqual(IList<T> other) {
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
    public int compareTo(IList<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IList<T>> DefaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.DefaultComparator();
        return new ArrayList.Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of an array.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IList<T>> {
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
        public int getHashCode(IList<T> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IList<T> lhs, IList<T> rhs) {
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
        public int compareTo(IList<T> lhs, IList<T> rhs) {
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

    /**
     * Creates an array with the specified capacity.
     */
    private T[] create(int capacity) {
        return Arrays.newInstance(this.classType, capacity);
    }

    /**
     * Checks whether the capacity is over the limit.
     */
    private boolean overCapacity() {
        assert(this.size <= this.array.length);

        return this.size == this.array.length;
    }

    /**
     * Resizes the array.
     */
    private void resize() {
        assert(this.size <= this.array.length);

        int newCapacity = this.size * 2;
        T[] newArray = Arrays.newInstance(this.classType, newCapacity);

        int startIndex = 0;
        int endIndex = this.size - 1;

        Arrays.copy(
            this.array,
            startIndex,
            endIndex,
            newArray,
            startIndex,
            endIndex);

        this.array = newArray;
    }

    /**
     * Shifts the array left by the specified size.
     */
    private void shiftLeft(int index, int shiftSize) {
        assert(shiftSize > 0);
        assert(index - shiftSize >= 0);

        for (int i = index; i < this.size; ++i) {
            int sourceIndex = i;
            int destinationIndex = i - shiftSize;

            this.array[destinationIndex] = this.array[sourceIndex];
        }

        this.size -= shiftSize;
    }

    /**
     * Validates an index.
     */
    private void validateIndex(int index) {
        Arrays.validateIndex(index, 0, this.size - 1);
    }
}
