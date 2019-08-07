package datastructures.doublylinkedlist.core;

import base.core.Conditions;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedList;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;

/**
 * The DoublyLinkedListStreamBuilder class implements a builder for a doubly linked list from a stream.
 */
public final class DoublyLinkedListStreamBuilder<TValue extends Comparable<TValue>> implements IBuilder<IDoublyLinkedList<TValue>> {
    private final IIterator<IDoublyLinkedListNode<TValue>> iterator;

    /**
     * The DoublyLinkedListStreamBuilder constructor.
     */
    public DoublyLinkedListStreamBuilder(IIterator<IDoublyLinkedListNode<TValue>> iterator) {
        Conditions.validateNotNull(
            iterator,
            "The iterator of list nodes.");

        this.iterator = iterator;
    }

    /**
     * Builds the doubly linked list.
     */
    @Override
    public IDoublyLinkedList<TValue> build() {
        IDoublyLinkedList<TValue> list = this.read(this.iterator);
        return list;
    }

    /**
     * Reads the doubly linked list from an input stream.
     */
    private IDoublyLinkedList<TValue> read(IIterator<IDoublyLinkedListNode<TValue>> iterator) {
        IDoublyLinkedList<TValue> list = new DoublyLinkedList<>();

        while (iterator.hasNext()) {
            IDoublyLinkedListNode<TValue> currNode = iterator.next();

            list.addToBack(currNode);
        }

        return list;
    }
}
