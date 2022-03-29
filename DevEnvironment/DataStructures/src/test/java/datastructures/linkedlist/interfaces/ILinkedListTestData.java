package datastructures.linkedlist.interfaces;

import base.interfaces.ITriple;
import java.util.List;

/**
 * The ILinkedListTestData interface defines the data of the tests of a linked list.
 */
public interface ILinkedListTestData {
    /**
     * Gets the data of linked lists.
     */
    List<ILinkedListData<Integer>> getData();

    /**
     * Gets the update data of a linked list.
     */
    List<ITriple<String, Integer, List<Integer>>> getUpdationData();
}
