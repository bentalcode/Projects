package datastructures.interfaces;

import datastructures.binarytree.interfaces.IBinaryTreeTestData;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.hashmap.interfaces.IHashMapTestData;
import datastructures.list.interfaces.IListTestData;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the data of tests of a list.
     */
    IListTestData getListData();

    /**
     * Gets the data of tests of a doubly linked list.
     */
    IDoublyLinkedListTestData getDoublyLinkedListData();

    /**
     * Gets the data of tests of a hash map.
     */
    IHashMapTestData getHashMapData();

    /**
     * Gets the data of tests of a binary tree.
     */
    IBinaryTreeTestData getBinaryTreeData();

    /**
     * Gets the data of tests of a graph.
     */
    IGraphTestData getGraphData();

    /**
     * Gets the data of tests of a B+ tree.
     */
    IBPlusTreeTestData getBPlusData();

    /**
     * Gets the data of tests of a cache.
     */
    ICacheTestData getCacheData();
}
