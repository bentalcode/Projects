package datastructures.interfaces;

import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the data of tests of a B+ tree.
     */
    IBPlusTreeTestData getBPlusData();

    /**
     * Gets the data of tests of a cache.
     */
    ICacheTestData getCacheData();

    /**
     * Gets the data of tests of a doubly linked list.
     */
    IDoublyLinkedListTestData getDoublyLinkedListData();
}
