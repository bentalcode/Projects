package datastructures.priorityqueue.core;

import base.core.AbstractBinaryComparator;
import base.core.Arrays;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IMatch;
import base.interfaces.IReverseIterator;
import base.core.Collections;
import datastructures.list.core.ArrayList;
import datastructures.list.interfaces.IList;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The AbstractPriorityQueue class implements an abstract base class for a priority queue.
 *
 * The priority queue is implemented as a heap with a dynamic array.
 *
 * A complete binary tree can be uniquely represented by storing it's level order traversal in an array.
 * The left child of an element is located at index: 2*index+1.
 * The right child of an element is located at index: 2*index+2.
 * The parent of an element is located at index: (index - 1) / 2.
 */
public abstract class AbstractPriorityQueue<T extends Comparable<T>> implements IPriorityQueue<T> {
    private final IList<T> data;
    private final IBinaryComparator<T> elementComparator;
    private final IBinaryComparator<IPriorityQueue<T>> comparator;

    /**
     * The AbstractPriorityQueue constructor.
     */
    protected AbstractPriorityQueue(
        Class<?> classType,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        this(
            ArrayList.create(classType),
            elementComparator,
            comparator);
    }

    /**
     * The AbstractPriorityQueue constructor.
     */
    protected AbstractPriorityQueue(
        IList<T> data,
        IBinaryComparator<T> elementComparator,
        IBinaryComparator<IPriorityQueue<T>> comparator) {

        Conditions.validateNotNull(
            data,
            "The data of the priority queue.");

        Conditions.validateNotNull(
            elementComparator,
            "The comparator of an element.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a priority queue.");

        this.data = data;
        this.elementComparator = elementComparator;
        this.comparator = comparator;
    }

    /**
     * Offers an element to the priority queue.
     *
     * The new element is initially appended to the end of the heap (after the last element of the array),
     * and performing heapifyUp() on the new added element for adjusting the heap.
     */
    @Override
    public void offer(T element) {
        this.data.add(element);

        if (this.size() == 1) {
            return;
        }

        this.heapifyUp(this.size() - 1);
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
            "The priority queue can not be empty.");

        T currentElement = this.data.get(0);

        this.swapValues(0, this.size() - 1);
        this.data.remove(this.size() - 1);

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
        return (this.empty()) ? null : this.data.get(0);
    }

    /**
     * Gets the size of a priority queue.
     */
    @Override
    public int size() {
        return this.data.size();
    }

    /**
     * Checks whether a priority queue is empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
    }

    /**
     * Clears the priority queue.
     */
    @Override
    public void clear() {
        this.data.clear();
    }

    /**
     * Checks whether the priority queue contains an element.
     */
    @Override
    public boolean contains(T element) {
        int index = this.find(element);
        return index != -1;
    }

    /**
     * Finds an element in a priority queue.
     * Retruns -1 if the element does not exist.
     */
    @Override
    public int find(T element) {
        for (int index = 0; index < this.data.size(); ++index) {
            T currElement = this.data.get(index);

            if (this.elementComparator.isEqual(currElement, element)) {
                return index;
            }
        }

        return -1;
    }

    /**
     * Finds an element in a priority queue by a match predicate.
     * Retruns -1 if the element does not exist.
     */
    @Override
    public int find(IMatch<T> match) {
        if (match == null) {
            return -1;
        }

        for (int index = 0; index < this.data.size(); ++index) {
            T currElement = this.data.get(index);

            if (match.match(currElement)) {
                return index;
            }
        }

        return -1;
    }

    /**
     * Updates a value of a specific element and heapify it up.
     */
    @Override
    public void updateAndHypifyUp(int index, T element) {
        Arrays.validateIndex(index, 0, this.data.size() - 1);
        this.data.set(index, element);
        this.heapifyUp(index);
    }

    /**
     * Updates a value of a specific element and heapify it down.
     */
    @Override
    public void updateAndHypifyDown(int index, T element) {
        Arrays.validateIndex(index, 0, this.data.size() - 1);
        this.data.set(index, element);
        this.heapifyDown(index);
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
        return this.data.getIterator();
    }

    /**
     * Gets a reverse iterator of the priority queue.
     */
    @Override
    public IReverseIterator<T> getReverseIterator() {
        return this.data.getReverseIterator();
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
    public static final class Comparator<T extends Comparable<T>>
        extends AbstractBinaryComparator<IPriorityQueue<T>> {

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
            return new HashCodeBuilder(647, 653)
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
     * Gets the data of the heap.
     */
    protected IList<T> getData() {
        return this.data;
    }

    /**
     * Gets the comparator of an element.
     */
    protected IBinaryComparator<T> getElementComparator() {
        return this.elementComparator;
    }

    /**
     * Gets the comparator of the heap.
     */
    protected IBinaryComparator<IPriorityQueue<T>> getComparator() {
        return this.comparator;
    }

    /**
     * Heapify an element up.
     */
    private void heapifyUp(int index) {
        assert(index >= 0 && index < this.data.size());

        if (index == 0) {
            return;
        }

        int currChildIndex = index;
        int currParentIndex = this.parentIndex(index);

        while (currParentIndex != -1) {
            T currParentValue = this.data.get(currParentIndex);
            T currChildValue = this.data.get(currChildIndex);

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
        assert(index >= 0 && index < this.data.size());

        int currParentIndex = index;

        while (!this.isLeaf(currParentIndex)) {
            int currChildIndex;
            T currChildValue;

            int currLeftChildIndex = this.leftChildIndex(currParentIndex);
            T currLeftChildValue = this.data.get(currLeftChildIndex);

            int currRightChildIndex = this.rightChildIndex(currParentIndex);

            if (currRightChildIndex != -1) {
                T currRightChildValue = this.data.get(currRightChildIndex);

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

            T currParentValue = this.data.get(currParentIndex);

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
        assert(leftIndex >= 0 && leftIndex < this.data.size());
        assert(rightIndex >= 0 && rightIndex < this.data.size());

        if (leftIndex == rightIndex) {
            return;
        }

        T temp = this.data.get(leftIndex);
        this.data.set(leftIndex, this.data.get(rightIndex));
        this.data.set(rightIndex, temp);
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

        return childIndex < this.size() ? childIndex : -1;
    }

    /**
     * Gets the index of a right child.
     * Returns -1 if not exist.
     */
    private int rightChildIndex(int index) {
        int childIndex = (index * 2) + 2;

        return childIndex < this.size() ? childIndex : -1;
    }

    /**
     * Checks whether the element is a leaf.
     */
    private boolean isLeaf(int index) {
        return index >= this.size() / 2;
    }
}
