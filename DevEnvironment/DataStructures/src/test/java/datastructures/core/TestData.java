package datastructures.core;

import datastructures.binarytree.core.BinaryTreeTestData;
import datastructures.binarytree.interfaces.IBinaryTreeTestData;
import datastructures.bplustree.core.BPlusTreeTestData;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.core.CacheTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.doublylinkedlist.core.DoublyLinkedListTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.graph.core.GraphTestData;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.hashmap.core.HashMapTestData;
import datastructures.hashmap.interfaces.IHashMapTestData;
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
     * Gets the data of tests of a doubly linked list.
     */
    @Override
    public IDoublyLinkedListTestData getDoublyLinkedListData() {
        return new DoublyLinkedListTestData();
    }

    /**
     * Gets the data of tests of a hash map.
     */
    @Override
    public IHashMapTestData getHashMapData() {
        return new HashMapTestData();
    }

    /**
     * Gets the data of tests of a binary tree.
     */
    @Override
    public IBinaryTreeTestData getBinaryTreeData() {
        return new BinaryTreeTestData();
    }

    /**
     * Gets the data of tests of a graph.
     */
    @Override
    public IGraphTestData getGraphData() {
        return new GraphTestData();
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
}
