package datastructures.core;

import datastructures.binarytree.core.BinaryTreeTestData;
import datastructures.binarytree.interfaces.IBinaryTreeTestData;
import datastructures.bitarray.core.BitArrayTestData;
import datastructures.bitarray.interfaces.IBitArrayTestData;
import datastructures.bplustree.core.BPlusTreeTestData;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.cache.core.CacheTestData;
import datastructures.cache.interfaces.ICacheTestData;
import datastructures.collections.core.CollectionTestData;
import datastructures.collections.interfaces.ICollectionTestData;
import datastructures.doublylinkedlist.core.DoublyLinkedListTestData;
import datastructures.doublylinkedlist.interfaces.IDoublyLinkedListTestData;
import datastructures.graph.core.GraphTestData;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.hashmap.core.HashMapTestData;
import datastructures.hashmap.interfaces.IHashMapTestData;
import datastructures.heap.core.HeapTestData;
import datastructures.heap.interfaces.IHeapTestData;
import datastructures.interfaces.ITestData;
import datastructures.linkedlist.core.LinkedListTestData;
import datastructures.linkedlist.interfaces.ILinkedListTestData;
import datastructures.list.core.ListTestData;
import datastructures.list.core.TwoDimensionalListTestData;
import datastructures.list.interfaces.IListTestData;
import datastructures.list.interfaces.ITwoDimensionalListTestData;
import datastructures.matrix.core.MatrixTestData;
import datastructures.matrix.interfaces.IMatrixTestData;
import datastructures.priorityqueue.core.PriorityQueueTestData;
import datastructures.priorityqueue.interfaces.IPriorityQueueTestData;
import datastructures.stack.core.StackTestData;
import datastructures.stack.interfaces.IStackTestData;
import datastructures.trie.core.TrieTestData;
import datastructures.trie.interfaces.ITrieTestData;
import datastructures.multileveldoublylinkedlist.core.MultiLevelDoublyLinkedListTestData;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListTestData;

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
     * Gets the data of tests of a collection.
     */
    @Override
    public ICollectionTestData getCollectionData() {
        return new CollectionTestData();
    }

    /**
     * Gets the data of tests of a bit array.
     */
    @Override
    public IBitArrayTestData getBitArrayData() {
        return new BitArrayTestData();
    }

    /**
     * Gets the data of tests of a list.
     */
    @Override
    public IListTestData getListData() {
        return new ListTestData();
    }

    /**
     * Gets the data of tests of a two dimensional list.
     */
    @Override
    public ITwoDimensionalListTestData getTwoDimensionalListData() {
        return new TwoDimensionalListTestData();
    }

    /**
     * Gets the data of tests of a stack.
     */
    @Override
    public IStackTestData getStackData() {
        return new StackTestData();
    }

    /**
     * Gets the data of tests of a linked list.
     */
    @Override
    public ILinkedListTestData getLinkedListData() {
        return new LinkedListTestData();
    }

    /**
     * Gets the data of tests of a doubly linked list.
     */
    @Override
    public IDoublyLinkedListTestData getDoublyLinkedListData() {
        return new DoublyLinkedListTestData();
    }

    /**
     * Gets the data of tests of a multi-level doubly linked list.
     */
    @Override
    public IMultiLevelDoublyLinkedListTestData getMultiLevelDoublyLinkedListData() {
        return new MultiLevelDoublyLinkedListTestData();
    }

    /**
     * Gets the data of tests of a priority queue.
     */
    @Override
    public IPriorityQueueTestData getPriorityQueueData() {
        return new PriorityQueueTestData();
    }

    /**
     * Gets the data of tests of a heap.
     */
    @Override
    public IHeapTestData getHeapData() {
        return new HeapTestData();
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
     * Gets the data of tests of a trie.
     */
    @Override
    public ITrieTestData getTrieData() {
        return new TrieTestData();
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

    /**
     * Gets the data of tests of a matrix.
     */
    @Override
    public IMatrixTestData getMatrixData() {
        return new MatrixTestData();
    }
}
