package datastructures.doublylinkedlist.interfaces;

import java.util.List;

/**
 * The IDoublyLinkedListData interface defines the data of a doubly linked list.
 */
public interface IDoublyLinkedListData<T extends Comparable<T>> {
    /**
     * Gets the creation data of the list.
     */
    List<T> getCreationData();

    /**
     * Gets the actual data of the list.
     */
     List<IDoublyLinkedListNode<T>> getData();

    /**
     * Gets the actual values of the list.
     */
    List<T> getValues();
}
