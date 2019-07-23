package json.interfaces;

import base.core.Pair;
import base.core.Triple;
import base.interfaces.INullable;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
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
    List<Pair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData();

    /**
     * Gets the data of B+ trees.
     */
    List<Triple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> getTreesData();

    /**
     * Gets the least recently used set data.
     */
    List<Pair<Integer, List<Integer>>> getLRUSetData();
}
