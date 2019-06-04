package datastructures.plustree.core;

import base.core.ArrayLists;
import base.core.Pair;
import base.core.Triple;
import base.interfaces.IBinaryComparator;
import base.interfaces.INullable;
import base.interfaces.IPrimitiveSize;
import datastructures.blocktree.core.BlockTreeLevels;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.core.BPlusTreeMetrics;
import datastructures.bplustree.core.BPlusTreeNode;
import datastructures.bplustree.core.BPlusTreeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.node.core.Nodes;
import datastructures.node.interfaces.INodes;
import json.interfaces.ITestData;
import java.util.List;

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
     * Gets the properties of a B+ tree.
     */
    @Override
    public IBPlusTreeProperties<Integer, String> getTreeProperties() {
        IBinaryComparator<Integer> keyComparator = base.core.Comparator.DefaultComparator();
        IBinaryComparator<IBPlusTreeNode<Integer>> nodeComparator = BPlusTreeNode.DefaultComparator(keyComparator);

        IBPlusTreeProperties<Integer, String> properties = new BPlusTreeProperties.Builder<Integer, String>()
            .withDegree(4)
            .withKeyClassType(Integer.class)
            .withValueClassType(String.class)
            .withKeyComparator(keyComparator)
            .withNodeComparator(nodeComparator)
            .withKeySizeInBytes(IPrimitiveSize.InBytes.IntegerSize)
            .withValueSizeInBytes(IPrimitiveSize.InBytes.CharacterSize * 1)
            .build();

        return properties;
    }

    /**
     * Gets the creation data of a B+ tree.
     */
    @Override
    public List<Pair<INodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData() {
        INodes<Integer, String> treeData1 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels1 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4, 9)))
            .build();

        INodes<Integer, String> treeData2 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels2 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10)))
            .build();

        INodes<Integer, String> treeData3 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels3 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10, 11)))
            .build();

        INodes<Integer, String> treeData4 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels4 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12)))
            .build();

        INodes<Integer, String> treeData5 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels5 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12, 13)))
            .build();

        INodes<Integer, String> treeData6 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .addNode(15, "h")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels6 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11, 13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15)))
            .build();

        INodes<Integer, String> treeData7 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .addNode(15, "h")
            .addNode(16, "i")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels7 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11, 13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15, 16)))
            .build();

        INodes<Integer, String> treeData8 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .addNode(15, "h")
            .addNode(16, "i")
            .addNode(20, "j")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels8 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11), ArrayLists.of(16)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15), ArrayLists.of(16, 20)))
            .build();

        INodes<Integer, String> treeData9 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .addNode(15, "h")
            .addNode(16, "i")
            .addNode(20, "j")
            .addNode(25, "k")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels9 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11), ArrayLists.of(16)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15), ArrayLists.of(16, 20, 25)))
            .build();

        return ArrayLists.of(
            new Pair<>(treeData1, treeLevels1),
            new Pair<>(treeData2, treeLevels2),
            new Pair<>(treeData3, treeLevels3),
            new Pair<>(treeData4, treeLevels4),
            new Pair<>(treeData5, treeLevels5),
            new Pair<>(treeData6, treeLevels6),
            new Pair<>(treeData7, treeLevels7),
            new Pair<>(treeData8, treeLevels8),
            new Pair<>(treeData9, treeLevels9));
    }

    /**
     * Gets the data of B+ trees.
     */
    @Override
    public List<Triple<INodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> getTreesData() {
        INodes<Integer, String> treeData1 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels1 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4, 9)))
            .build();

        IBPlusTreeMetrics treeMetrics1 = new BPlusTreeMetrics.Builder()
            .withHeight(1)
            .withNumberOfNodes(1)
            .withNumberOfInnerNodes(0)
            .withNumberOfLeafNodes(1)
            .withSizeInBytes(18)
            .withCapacityInBytes(24)
            .build();

        INodes<Integer, String> treeData2 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels2 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10)))
            .build();

        IBPlusTreeMetrics treeMetrics2 = new BPlusTreeMetrics.Builder()
            .withHeight(2)
            .withNumberOfNodes(3)
            .withNumberOfInnerNodes(1)
            .withNumberOfLeafNodes(2)
            .withSizeInBytes(44)
            .withCapacityInBytes(104)
            .build();

        INodes<Integer, String> treeData3 = new Nodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels3 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10, 11)))
            .build();

        IBPlusTreeMetrics treeMetrics3 = new BPlusTreeMetrics.Builder()
            .withHeight(2)
            .withNumberOfNodes(3)
            .withNumberOfInnerNodes(1)
            .withNumberOfLeafNodes(2)
            .withSizeInBytes(50)
            .withCapacityInBytes(104)
            .build();

        return ArrayLists.of(
            new Triple<>(treeData1, treeLevels1, treeMetrics1),
            new Triple<>(treeData2, treeLevels2, treeMetrics2),
            new Triple<>(treeData3, treeLevels3, treeMetrics3));
    }
}
