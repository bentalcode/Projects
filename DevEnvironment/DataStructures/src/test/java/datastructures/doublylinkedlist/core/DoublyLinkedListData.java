package datastructures.doublylinkedlist.core;

import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListNode;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListData;
import java.util.List;

/**
 * The DoublyLinkedListData class implements the data of a list.
 */
public final class DoublyLinkedListData<T extends Comparable<T>> implements IDoublyLinkedListData<T> {
    private final List<T> values;
    private final List<IDoublyLinkedListNode<T>> nodes;

    /**
     * The DoublyLinkedListData constructor.
     */
    public DoublyLinkedListData(
        List<T> values,
        List<IDoublyLinkedListNode<T>> nodes) {

        this.values = values;
        this.nodes = nodes;
    }

    /**
     * Gets the values of the list.
     */
    @Override
    public List<T> getValues() {
        return this.values;
    }

    /**
     * Gets the nodes of the list.
     */
    @Override
    public List<IDoublyLinkedListNode<T>> getNodes() {
        return this.nodes;
    }
}
