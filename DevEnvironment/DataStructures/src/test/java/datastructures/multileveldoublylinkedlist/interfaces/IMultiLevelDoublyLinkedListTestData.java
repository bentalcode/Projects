package datastructures.multileveldoublylinkedlist.interfaces;

import java.util.List;

/**
 * The IMultiLevelDoublyLinkedListTestData interface defines the data of the tests of
 * a multi-level doubly linked list.
 */
public interface IMultiLevelDoublyLinkedListTestData {
    /**
     * Gets the data of multi-level doubly linked lists.
     */
    List<IMultiLevelDoublyLinkedListData<Integer>> getData();
}
