package json.interfaces;

import base.core.Pair;
import base.core.Triple;
import base.interfaces.INullable;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.tree.interfaces.ITreeData;
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
    List<Pair<ITreeData<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData();

    /**
     * Gets the data of B+ trees.
     */
    List<Triple<ITreeData<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> getTreesData();
}
