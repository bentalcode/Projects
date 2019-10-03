package datastructures.linkedlist.core;

import datastructures.linkedlist.interfaces.ILinkedListNode;
import datastructures.linkedlist.interfaces.ILinkedListData;
import java.util.List;

/**
 * The LinkedListData class implements the data of a linked list.
 */
public final class LinkedListData<T extends Comparable<T>> implements ILinkedListData<T> {
    private final List<T> creationData;
    private final List<ILinkedListNode<T>> data;
    private final List<T> values;

    /**
     * The ListData constructor.
     */
    public LinkedListData(
        List<T> creationData,
        List<ILinkedListNode<T>> data,
        List<T> values) {

        this.creationData = creationData;
        this.data = data;
        this.values = values;
    }

    /**
     * Gets the creation data of the list.
     */
    @Override
    public List<T> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the list.
     */
    @Override
    public List<ILinkedListNode<T>> getData() {
        return this.data;
    }

    /**
     * Gets the actual values of the list.
     */
    @Override
    public List<T> getValues() {
        return this.values;
    }
}
