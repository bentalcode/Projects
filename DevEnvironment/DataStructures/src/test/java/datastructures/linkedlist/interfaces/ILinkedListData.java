package datastructures.linkedlist.interfaces;

import java.util.List;

/**
 * The ILinkedListData interface defines the data of a linked list.
 */
public interface ILinkedListData<T extends Comparable<T>> {
    /**
     * Gets the creation data of the list.
     */
    List<T> getCreationData();

    /**
     * Gets the actual data of the list.
     */
    List<ILinkedListNode<T>> getData();

    /**
     * Gets the actual values of the list.
     */
    List<T> getValues();
}
