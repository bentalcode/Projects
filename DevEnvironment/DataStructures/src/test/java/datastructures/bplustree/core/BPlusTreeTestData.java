package datastructures.bplustree.core;

import base.core.ArrayLists;
import base.core.Comparator;
import base.core.Pair;
import base.core.Triple;
import base.interfaces.IBinaryComparator;
import base.interfaces.INullable;
import base.interfaces.IPair;
import base.interfaces.IPrimitiveSize;
import base.interfaces.ITriple;
import datastructures.blocktree.core.BlockTreeLevels;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTreeTestData;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.node.core.KeyValueNodes;
import datastructures.node.interfaces.IKeyValueNodes;

import java.math.BigInteger;
import java.util.List;

/**
 * The BPlusTreeTestData class implements the data of the tests of a B+ tree.
 */
public final class BPlusTreeTestData implements IBPlusTreeTestData {
    /**
     * The BPlusTreeTestData constructor.
     */
    public BPlusTreeTestData() {
    }

    /**
     * Gets the properties of a B+ tree.
     */
    @Override
    public IBPlusTreeProperties<Integer, String> getTreeProperties() {
        IBinaryComparator<Integer> keyComparator = Comparator.make();
        IBinaryComparator<IBPlusTreeNode<Integer>> nodeComparator = BPlusTreeNode.defaultComparator(keyComparator);

        return new BPlusTreeProperties.Builder<Integer, String>()
            .withDegree(4)
            .withKeyClassType(Integer.class)
            .withValueClassType(String.class)
            .withKeyComparator(keyComparator)
            .withNodeComparator(nodeComparator)
            .withKeySizeInBytes(IPrimitiveSize.InBytes.IntegerSize)
            .withValueSizeInBytes(IPrimitiveSize.InBytes.CharacterSize)
            .build();
    }

    /**
     * Gets the creation data of a B+ tree.
     */
    @Override
    public List<IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData() {
        IKeyValueNodes<Integer, String> treeData1 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels1 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4, 9)))
            .build();

        IKeyValueNodes<Integer, String> treeData2 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels2 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10)))
            .build();

        IKeyValueNodes<Integer, String> treeData3 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels3 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10, 11)))
            .build();

        IKeyValueNodes<Integer, String> treeData4 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels4 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12)))
            .build();

        IKeyValueNodes<Integer, String> treeData5 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .addNode(12, "f")
            .addNode(13, "g")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels5 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12, 13)))
            .build();

        IKeyValueNodes<Integer, String> treeData6 = new KeyValueNodes.Builder<Integer, String>()
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
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11, 13)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12), ArrayLists.make(13, 15)))
            .build();

        IKeyValueNodes<Integer, String> treeData7 = new KeyValueNodes.Builder<Integer, String>()
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
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11, 13)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12), ArrayLists.make(13, 15, 16)))
            .build();

        IKeyValueNodes<Integer, String> treeData8 = new KeyValueNodes.Builder<Integer, String>()
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
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(13)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11), ArrayLists.make(16)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12), ArrayLists.make(13, 15), ArrayLists.make(16, 20)))
            .build();

        IKeyValueNodes<Integer, String> treeData9 = new KeyValueNodes.Builder<Integer, String>()
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
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(13)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9, 11), ArrayLists.make(16)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10), ArrayLists.make(11, 12), ArrayLists.make(13, 15), ArrayLists.make(16, 20, 25)))
            .build();

        return ArrayLists.make(
            Pair.make(treeData1, treeLevels1),
            Pair.make(treeData2, treeLevels2),
            Pair.make(treeData3, treeLevels3),
            Pair.make(treeData4, treeLevels4),
            Pair.make(treeData5, treeLevels5),
            Pair.make(treeData6, treeLevels6),
            Pair.make(treeData7, treeLevels7),
            Pair.make(treeData8, treeLevels8),
            Pair.make(treeData9, treeLevels9));
    }

    /**
     * Gets the data of B+ trees.
     */
    @Override
    public List<ITriple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> getTreesData() {
        IKeyValueNodes<Integer, String> treeData1 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels1 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4, 9)))
            .build();

        IBPlusTreeMetrics treeMetrics1 = new BPlusTreeMetrics.Builder()
            .withHeight(0)
            .withNumberOfNodes(1)
            .withNumberOfInnerNodes(0)
            .withNumberOfLeafNodes(1)
            .withSizeInBytes(BigInteger.valueOf(18))
            .withCapacityInBytes(BigInteger.valueOf(24))
            .build();

        IKeyValueNodes<Integer, String> treeData2 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels2 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10)))
            .build();

        IBPlusTreeMetrics treeMetrics2 = new BPlusTreeMetrics.Builder()
            .withHeight(1)
            .withNumberOfNodes(3)
            .withNumberOfInnerNodes(1)
            .withNumberOfLeafNodes(2)
            .withSizeInBytes(BigInteger.valueOf(44))
            .withCapacityInBytes(BigInteger.valueOf(104))
            .build();

        IKeyValueNodes<Integer, String> treeData3 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .addNode(11, "e")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels3 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(9)))
            .addLevelByKeys(ArrayLists.make(ArrayLists.make(1, 4), ArrayLists.make(9, 10, 11)))
            .build();

        IBPlusTreeMetrics treeMetrics3 = new BPlusTreeMetrics.Builder()
            .withHeight(1)
            .withNumberOfNodes(3)
            .withNumberOfInnerNodes(1)
            .withNumberOfLeafNodes(2)
            .withSizeInBytes(BigInteger.valueOf(50))
            .withCapacityInBytes(BigInteger.valueOf(104))
            .build();

        return ArrayLists.make(
            Triple.make(treeData1, treeLevels1, treeMetrics1),
            Triple.make(treeData2, treeLevels2, treeMetrics2),
            Triple.make(treeData3, treeLevels3, treeMetrics3));
    }
}
