package datastructures.linkedlist.interfaces;

import java.util.List;

/**
 * The ILinkedListData interface defines the data of a linked list.
 */
public interface ILinkedListData<T extends Comparable<T>> {
    /**
     * Gets the values of the list.
     */
    List<T> getValues();

    /**
     * Gets the nodes of the list.
     */
    List<ILinkedListNode<T>> getNodes();
}
