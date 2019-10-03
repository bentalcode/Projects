package datastructures.doublylinkedlist.core;

import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import java.util.List;

/**
 * The ListData class implements the data of a list.
 */
public final class DoublyLinkedListData<T extends Comparable<T>> implements IDoublyLinkedListData<T> {
    private final List<T> creationData;
    private final List<IDoublyLinkedListNode<T>> data;
    private final List<T> values;

    /**
     * The ListData constructor.
     */
    public DoublyLinkedListData(
        List<T> creationData,
        List<IDoublyLinkedListNode<T>> data,
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
    public List<IDoublyLinkedListNode<T>> getData() {
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
