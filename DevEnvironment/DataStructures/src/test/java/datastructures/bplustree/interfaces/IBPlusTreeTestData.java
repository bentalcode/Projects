package datastructures.bplustree.interfaces;

import base.interfaces.INullable;
import base.interfaces.IPair;
import base.interfaces.ITriple;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.node.interfaces.IKeyValueNodes;
import java.util.List;

/**
 * The IBPlusTreeTestData interface defines the data of the tests of a B+ tree.
 */
public interface IBPlusTreeTestData {
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
}
