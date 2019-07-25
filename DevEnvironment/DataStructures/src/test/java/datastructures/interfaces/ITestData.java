package datastructures.interfaces;

import base.interfaces.INullable;
import base.interfaces.IPair;
import base.interfaces.ITriple;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodes;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the properties of a B+ tree.
     */
    IBPlusTreeProperties<Integer, String> getTreeProperties();

    /**
     * Gets the creation data of B+ trees.
     */
    List<IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData();

    /**
     * Gets the data of B+ trees.
     */
    List<ITriple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> getTreesData();

    /**
     * Gets the least recently used data.
     */
    List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getLRUData();

    /**
     * Gets the doubly linked list data.
     */
    List<ITriple<String, Integer, List<Integer>>> getDoublyLinkedListData();
}
