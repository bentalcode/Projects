package datastructures.priorityqueue.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.collections.core.Collections;
import datastructures.list.core.ArrayList;
import datastructures.list.interfaces.IList;
import datastructures.priorityqueue.interfaces.IPriorityQueue;

/**
 * The Heap class implements an abstract base class for a heap.
 *
 * A complete binary tree can be uniquely represented by storing it's level order traversal in an array.
 * The left child of an element is located at index: 2*index+1.
 * The right child of an element is located at index: 2*index+2.
 * The parent of an element is located at index: (index - 1) / 2.
 */
public abstract class AbstractHeap<TValue extends Comparable<TValue>> implements IPriorityQueue<TValue> {
    private final IList<TValue> data;
    private final IBinaryComparator<IPriorityQueue<TValue>> comparator;
    private final IBinaryComparator<TValue> elementComparator;

    /**
     * The AbstractHeap constructor.
     */
    protected AbstractHeap(
        Class<TValue> classType,
        IBinaryComparator<IPriorityQueue<TValue>> comparator,
        IBinaryComparator<TValue> elementComparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of a priority queue.");

        Conditions.validateNotNull(
            elementComparator,
            "The comparator of an element.");

        this.data = new ArrayList<>(classType);
        this.comparator = comparator;
        this.elementComparator = elementComparator;
    }

    /**
     * Offers an element to the priority queue.
     *
     * The new element is initially appended to the end of the heap (after the last element of the array),
     * and performing heapifyUp() on the new added element for adjusting the heap.
     */
    @Override
    public void offer(TValue element) {
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
    public TValue poll() {
        Conditions.validate(
            !this.empty(),
            "The heap can not be empty.");

        TValue currentElement = this.data.get(0);

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
    public TValue peek() {
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
    public boolean contains(TValue element) {
        IIterator<TValue> iterator = this.getIterator();

        while (iterator.hasNext()) {
            TValue currElement = iterator.next();

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
     * Gets an iterator of the heap.
     */
    @Override
    public IIterator<TValue> getIterator() {
        return this.data.getIterator();
    }

    /**
     * Gets a reverse iterator of the heap.
     */
    @Override
    public IReverseIterator<TValue> getReverseIterator() {
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
    public boolean isEqual(IPriorityQueue<TValue> other) {
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
    public int compareTo(IPriorityQueue<TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TValue extends Comparable<TValue>> IBinaryComparator<IPriorityQueue<TValue>> defaultComparator() {
        IBinaryComparator<TValue> elementComparator = base.core.Comparator.defaultComparator();
        return new Comparator<>(elementComparator);
    }

    /**
     * The Comparator class implements a comparator of a priority queue.
     */
    public static final class Comparator<TValue extends Comparable<TValue>>
        extends AbstractBinaryComparator<IPriorityQueue<TValue>> {

        private final IBinaryComparator<TValue> elementComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<TValue> elementComparator) {
            Conditions.validateNotNull(
                elementComparator,
                "The comparator of an element.");

            this.elementComparator = elementComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IPriorityQueue<TValue> obj) {
            return new HashCodeBuilder(3, 5)
                .withIterator(obj.getIterator(), this.elementComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IPriorityQueue<TValue> lhs, IPriorityQueue<TValue> rhs) {
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
        public int compareTo(IPriorityQueue<TValue> lhs, IPriorityQueue<TValue> rhs) {
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
        assert(index >= 0 && index < this.data.size());

        if (index == 0) {
            return;
        }

        int currChildIndex = index;
        int currParentIndex = this.parentIndex(currChildIndex);

        while (currParentIndex != -1) {
            TValue currParentValue = this.data.get(currParentIndex);
            TValue currChildValue = this.data.get(currChildIndex);

            int compareStatus = this.elementComparator.compareTo(currParentValue, currChildValue);

            if (compareStatus <= 0) {
                break;
            }

            this.swapValues(currParentIndex, currChildIndex);

            //
            // Move one level up...
            //
            currChildIndex = currParentIndex;
            currParentIndex = this.parentIndex(currChildIndex);
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
            TValue currChildValue;

            int currLeftChildIndex = this.leftChildIndex(currParentIndex);
            TValue currLeftChildValue = this.data.get(currLeftChildIndex);

            int currRightChildIndex = this.rightChildIndex(currParentIndex);

            if (currRightChildIndex != -1) {
                TValue currRightChildValue = this.data.get(currRightChildIndex);

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

            TValue currParentValue = this.data.get(currParentIndex);

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

        TValue temp = this.data.get(leftIndex);
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
