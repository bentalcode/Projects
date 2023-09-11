package datastructures.linkedlist.core;

import datastructures.linkedlist.interfaces.ILinkedListNode;
import datastructures.linkedlist.interfaces.ILinkedListData;
import java.util.List;

/**
 * The LinkedListData class implements the data of a list.
 */
public final class LinkedListData<T extends Comparable<T>> implements ILinkedListData<T> {
    private final List<T> values;
    private final List<ILinkedListNode<T>> nodes;

    /**
     * The LinkedListData constructor.
     */
    public LinkedListData(
        List<T> values,
        List<ILinkedListNode<T>> nodes) {

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
    public List<ILinkedListNode<T>> getNodes() {
        return this.nodes;
    }
}
