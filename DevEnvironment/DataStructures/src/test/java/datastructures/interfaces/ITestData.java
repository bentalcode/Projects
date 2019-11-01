package datastructures.interfaces;

import datastructures.binarytree.interfaces.IBinaryTreeTestData;
import datastructures.bitarray.interfaces.IBitArrayTestData;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.collections.interfaces.ICollectionTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.hashmap.interfaces.IHashMapTestData;
import datastructures.linkedlist.interfaces.ILinkedListTestData;
import datastructures.list.interfaces.IListTestData;
import datastructures.list.interfaces.ITwoDimensionalList;
import datastructures.list.interfaces.ITwoDimensionalListTestData;
import datastructures.priorityqueue.interfaces.IPriorityQueueTestData;
import datastructures.stack.interfaces.IStackTestData;
import datastructures.trie.interfaces.ITrieTestData;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the data of tests of a collection.
     */
    ICollectionTestData getCollectionData();

    /**
     * Gets the data of tests of a bit array.
     */
    IBitArrayTestData getBitArrayData();

    /**
     * Gets the data of tests of a list.
     */
    IListTestData getListData();

    /**
     * Gets the data of tests of a two dimensional list.
     */
    ITwoDimensionalListTestData getTwoDimensionalListData();

    /**
     * Gets the data of tests of a stack.
     */
    IStackTestData getStackData();

    /**
     * Gets the data of tests of a linked list.
     */
    ILinkedListTestData getLinkedListData();

    /**
     * Gets the data of tests of a doubly linked list.
     */
    IDoublyLinkedListTestData getDoublyLinkedListData();

    /**
     * Gets the data of tests of a priority queue.
     */
    IPriorityQueueTestData getPriorityQueueData();

    /**
     * Gets the data of tests of a hash map.
     */
    IHashMapTestData getHashMapData();

    /**
     * Gets the data of tests of a binary tree.
     */
    IBinaryTreeTestData getBinaryTreeData();

    /**
     * Gets the data of tests of a trie.
     */
    ITrieTestData getTrieData();

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
