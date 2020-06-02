package datastructures.multileveldoublylinkedlist.core;

import base.interfaces.IIterator;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import java.util.LinkedList;

/**
 * The MultiLevelDoublyLinkedListNodeIterator class implements an iterator of nodes of
 * a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListNodeIterator<T extends Comparable<T>>
    implements IIterator<IMultiLevelDoublyLinkedListNode<T>> {

    private final IMultiLevelDoublyLinkedListNode<T> head;
    private IMultiLevelDoublyLinkedListNode<T> currNode;
    private LinkedList<IMultiLevelDoublyLinkedListNode<T>> nextLevel;

    /**
     * Creates a new iterator of a multi-level doubly linked list.
     */
    public static <T extends Comparable<T>> IIterator<IMultiLevelDoublyLinkedListNode<T>> of(IMultiLevelDoublyLinkedListNode<T> headNode) {
        return new MultiLevelDoublyLinkedListNodeIterator<>(headNode);
    }

    /**
     * The MultiLevelDoublyLinkedListNodeIterator constructor.
     */
    public MultiLevelDoublyLinkedListNodeIterator(IMultiLevelDoublyLinkedListNode<T> head) {
        this.head = head;

        this.reset();
    }

    /**
     * Checks whether there is a next node.
     */
    @Override
    public boolean hasNext() {
        return this.currNode != null || !this.nextLevel.isEmpty();
    }

    /**
     * Gets the next node.
     */
    @Override
    public IMultiLevelDoublyLinkedListNode<T> next() {
        assert(this.hasNext());

        IMultiLevelDoublyLinkedListNode<T> currNode = this.currNode;

        if (currNode.child() != null) {
            this.nextLevel.add(currNode.child());
        }

        if (this.currNode.next() != null) {
            this.currNode = this.currNode.next();
        }
        else if (!this.nextLevel.isEmpty()){
            this.currNode = this.nextLevel.removeFirst();
        }
        else {
            this.currNode = null;
        }

        return currNode;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.currNode = this.head;
        this.nextLevel = new LinkedList<>();
    }
}
