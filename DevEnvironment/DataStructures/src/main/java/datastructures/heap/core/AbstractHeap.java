package datastructures.heap.core;

import base.core.AbstractBinaryComparator;
import base.core.ArrayIterator;
import base.core.ArrayReverseIterator;
import base.core.Arrays;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.heap.HeapException;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The AbstractHeap class implements an abstract base class for a heap.
 *
 * The priority queue is implemented as a heap with a fixed array.
 *
 * A complete binary tree can be uniquely represented by storing it's level order traversal in an array.
 * The left child of an element is located at index: 2*index+1.
 * The right child of an element is located at index: 2*index+2.
 * The parent of an element is located at index: (index - 1) / 2.
 */
public abstract class AbstractHeap<T extends Comparable<T>> implements IPriorityQueue<T> {
    private final T[] data;
    private int size;
    private final IBinaryComparator<T> elementComparator;
    private final IBinaryComparator<IPriorityQueue<T>> comparator;

    /**
     * The AbstractHeap constructor.
     */
    protected AbstractHeap(
        Class<T> classType,
        int capacity,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        Conditions.validateNotNull(
            classType,
            "The class type of an element.");

        Conditions.validate(
            capacity > 0,
            "The capacity of a heap has to be positive.");

        Conditions.validateNotNull(
            elementComparator,
            "The comparator of an element.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a heap.");

        this.data = Arrays.newInstance(classType, capacity);
        this.elementComparator = elementComparator;
        this.comparator = comparator;
    }

    /**
     * The AbstractHeap constructor.
     */
    protected AbstractHeap(
        T[] data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        Conditions.validate(
            data != null && data.length > 0,
            "The initial data of the heap is not defined.");

        Conditions.validateNotNull(
            elementComparator,
            "The comparator of an element.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a heap.");

        this.data = data;
        this.elementComparator = elementComparator;
        this.comparator = comparator;

        for (int i = 0; i < data.length; ++i) {
            T currValue = data[i];
            this.offer(currValue);
        }
    }

    /**
     * Offers an element to the priority queue.
     *
     * The new element is initially appended to the end of the heap (after the last element of the array),
     * and performing heapifyUp() on the new added element for adjusting the heap.
     */
    @Override
    public void offer(T element) {
        if (this.reachedCapacity()) {
            String errorMessage = "The heap has reached its capacity.";
            throw new HeapException(errorMessage);
        }

        this.data[this.size] = element;
        ++this.size;

        if (this.size == 1) {
            return;
        }

        this.heapifyUp(this.size - 1);
    }

    /**
     * Polls the peek element from the priority queue.
     *
     * The peek element is found at the root, which is the first element of the array.
     * We swap the root with the last element and remove the last element from the array,
     * and then performing heapifyDown() on the new swapped element in the root for adjusting the heap.
     */
    @Override
    public T poll() {
        Conditions.validate(
            !this.empty(),
            "The heap can not be empty.");

        T currentElement = this.data[0];

        this.swapValues(0, this.size - 1);
        --this.size;

        if (!this.empty()) {
            this.heapifyDown(0);
        }

        return currentElement;
    }

    /**
     * Gets the peek element of the priority queue.
     */
    @Override
    public T peek() {
        return (this.empty()) ? null : this.data[0];
    }

    /**
     * Gets the size of a priority queue.
     */
    @Override
    public int size() {
        return this.size;
    }

    /**
     * Checks whether a priority queue is empty.
     */
    @Override
    public boolean empty() {
        return this.size == 0;
    }

    /**
     * Clears the priority queue.
     */
    @Override
    public void clear() {
        this.size = 0;
    }

    /**
     * Checks whether the priority queue contains an element.
     */
    @Override
    public boolean contains(T element) {
        IIterator<T> iterator = this.getIterator();

        while (iterator.hasNext()) {
            T currElement = iterator.next();

            if (this.elementComparator.isEqual(currElement, element)) {
                return true;
            }
        }

        return false;
    }

    /**
     * Gets string representation of this instance.
     */
    @Override
    public String toString() {
        return Collections.toString(this.getIterator());
    }

    /**
     * Gets an iterator of the priority queue.
     */
    @Override
    public IIterator<T> getIterator() {
        return ArrayIterator.of(this.data, 0, this.size - 1);
    }

    /**
     * Gets a reverse iterator of the priority queue.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return ArrayReverseIterator.of(this.data, 0, this.size - 1);
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
    public boolean isEqual(IPriorityQueue<T> other) {
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
    public int compareTo(IPriorityQueue<T> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<IPriorityQueue<T>> defaultComparator() {
        IBinaryComparator<T> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a priority queue.
     */
    public static final class Comparator<T extends Comparable<T>> extends AbstractBinaryComparator<IPriorityQueue<T>> {
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
        public int getHashCode(IPriorityQueue<T> obj) {
            return new HashCodeBuilder(569, 571)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IPriorityQueue<T> lhs, IPriorityQueue<T> rhs) {
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
        public int compareTo(IPriorityQueue<T> lhs, IPriorityQueue<T> rhs) {
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
     * Heapify an element up.
     */
    private void heapifyUp(int index) {
        assert(index >= 0 && index < this.size);

        if (index == 0) {
            return;
        }

        int currChildIndex = index;
        int currParentIndex = this.parentIndex(index);

        while (currParentIndex != -1) {
            T currParentValue = this.data[currParentIndex];
            T currChildValue = this.data[currChildIndex];

            int compareStatus = this.elementComparator.compareTo(currParentValue, currChildValue);

            if (compareStatus <= 0) {
                break;
            }

            this.swapValues(currParentIndex, currChildIndex);

            //
            // Move one level up...
            //
            currChildIndex = currParentIndex;
            currParentIndex = this.parentIndex(currParentIndex);
        }
    }

    /**
     * Heapify an element down.
     */
    private void heapifyDown(int index) {
        assert(index >= 0 && index < this.size);

        int currParentIndex = index;

        while (!this.isLeaf(currParentIndex)) {
            int currChildIndex;
            T currChildValue;

            int currLeftChildIndex = this.leftChildIndex(currParentIndex);
            T currLeftChildValue = this.data[currLeftChildIndex];

            int currRightChildIndex = this.rightChildIndex(currParentIndex);

            if (currRightChildIndex != -1) {
                T currRightChildValue = this.data[currRightChildIndex];

                if (this.elementComparator.compareTo(currLeftChildValue, currRightChildValue) <= 0) {
                    currChildIndex = currLeftChildIndex;
                    currChildValue = currLeftChildValue;
                }
                else {
                    currChildIndex = currRightChildIndex;
                    currChildValue = currRightChildValue;
                }
            }
            else {
                currChildIndex = currLeftChildIndex;
                currChildValue = currLeftChildValue;
            }

            T currParentValue = this.data[currParentIndex];

            int compareStatus = this.elementComparator.compareTo(currParentValue, currChildValue);

            if (compareStatus <= 0) {
                break;
            }

            this.swapValues(currParentIndex, currChildIndex);

            //
            // Move one level down...
            //
            currParentIndex = currChildIndex;
        }
    }

    /**
     * Swaps the values of the specifies indexes of an array.
     */
    private void swapValues(int leftIndex, int rightIndex) {
        assert(leftIndex >= 0 && leftIndex < this.size);
        assert(rightIndex >= 0 && rightIndex < this.size);

        Arrays.swap(this.data, leftIndex, rightIndex);
    }

    /**
     * Gets the index of a parent.
     * Returns -1 if not exist.
     */
    private int parentIndex(int index) {
        if (index == 0) {
            return -1;
        }

        return (index - 1) / 2;
    }

    /**
     * Gets the index of a left child.
     * Returns -1 if not exist.
     */
    private int leftChildIndex(int index) {
        int childIndex = (index * 2) + 1;

        return childIndex < this.size ? childIndex : -1;
    }

    /**
     * Gets the index of a right child.
     * Returns -1 if not exist.
     */
    private int rightChildIndex(int index) {
        int childIndex = (index * 2) + 2;

        return childIndex < this.size ? childIndex : -1;
    }

    /**
     * Checks whether the element is a leaf.
     */
    private boolean isLeaf(int index) {
        return index >= this.size / 2;
    }

    /**
     * Checks whether the heap has reached it's capacity.
     */
    private boolean reachedCapacity() {
        assert(this.size >= 0 && this.size <= this.data.length);
        return this.size == this.data.length;
    }
}
