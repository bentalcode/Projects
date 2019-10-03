package datastructures.doublylinkedlist.interfaces;

import base.interfaces.ITriple;
import java.util.List;

/**
 * The IDoublyLinkedListTestData interface defines the data of the tests of a doubly linked list.
 */
public interface IDoublyLinkedListTestData {
    /**
     * Gets the data of doubly linked lists.
     */
    List<IDoublyLinkedListData<Integer>> getData();

    /**
     * Gets the updation data of a doubly linked list.
     */
    List<ITriple<String, Integer, List<Integer>>> getUpdationData();
}
