package datastructures.doublylinkedlist.interfaces;

import java.util.List;

/**
 * The IDoublyLinkedListData interface defines the data of a doubly linked list.
 */
public interface IDoublyLinkedListData<T extends Comparable<T>> {
    /**
     * Gets the values of the list.
     */
    List<T> getValues();

    /**
     * Gets the nodes of the list.
     */
    List<IDoublyLinkedListNode<T>> getNodes();
}
