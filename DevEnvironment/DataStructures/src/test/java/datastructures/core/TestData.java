package datastructures.core;

import datastructures.bplustree.core.BPlusTreeTestData;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.core.CacheTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.doublylinkedlist.core.DoublyLinkedListTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.interfaces.ITestData;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets the data of tests of a B+ tree.
     */
    @Override
    public IBPlusTreeTestData getBPlusData() {
        return new BPlusTreeTestData();
    }

    /**
     * Gets the data of tests of a cache.
     */
    @Override
    public ICacheTestData getCacheData() {
        return new CacheTestData();
    }

    /**
     * Gets the data of tests of a doubly linked list.
     */
    @Override
    public IDoublyLinkedListTestData getDoublyLinkedListData() {
        return new DoublyLinkedListTestData();
    }
}
