package datastructures.doublylinkedlist.interfaces;

import base.interfaces.ITriple;
import java.util.List;

/**
 * The IDoublyLinkedListTestData interface defines the data of the tests of a doubly linked list.
 */
public interface IDoublyLinkedListTestData {
    /**
     * Gets the doubly linked list data.
     */
    List<ITriple<String, Integer, List<Integer>>> getDoublyLinkedListData();
}
