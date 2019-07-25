package datastructures.core;

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
import datastructures.bplustree.core.BPlusTreeMetrics;
import datastructures.bplustree.core.BPlusTreeNode;
import datastructures.bplustree.core.BPlusTreeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.node.core.KeyValueNode;
import datastructures.node.core.KeyValueNodes;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodes;
import datastructures.interfaces.ITestData;
import java.util.ArrayList;
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
        IBinaryComparator<Integer> keyComparator = Comparator.DefaultComparator();
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
    public List<IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> getCreationData() {
        IKeyValueNodes<Integer, String> treeData1 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels1 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4, 9)))
            .build();

        IKeyValueNodes<Integer, String> treeData2 = new KeyValueNodes.Builder<Integer, String>()
            .addNode(1, "a")
            .addNode(4, "b")
            .addNode(9, "c")
            .addNode(10, "d")
            .build();

        IBlockTreeLevels<Integer, INullable> treeLevels2 = new BlockTreeLevels.Builder<Integer, INullable>()
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10)))
            .build();

        IKeyValueNodes<Integer, String> treeData3 = new KeyValueNodes.Builder<Integer, String>()
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

        IKeyValueNodes<Integer, String> treeData4 = new KeyValueNodes.Builder<Integer, String>()
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
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12, 13)))
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
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11, 13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15)))
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
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11, 13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15, 16)))
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
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11), ArrayLists.of(16)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15), ArrayLists.of(16, 20)))
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
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(13)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(9, 11), ArrayLists.of(16)))
            .addLevelByKeys(ArrayLists.of(ArrayLists.of(1, 4), ArrayLists.of(9, 10), ArrayLists.of(11, 12), ArrayLists.of(13, 15), ArrayLists.of(16, 20, 25)))
            .build();

        return ArrayLists.of(
            Pair.of(treeData1, treeLevels1),
            Pair.of(treeData2, treeLevels2),
            Pair.of(treeData3, treeLevels3),
            Pair.of(treeData4, treeLevels4),
            Pair.of(treeData5, treeLevels5),
            Pair.of(treeData6, treeLevels6),
            Pair.of(treeData7, treeLevels7),
            Pair.of(treeData8, treeLevels8),
            Pair.of(treeData9, treeLevels9));
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

        IKeyValueNodes<Integer, String> treeData2 = new KeyValueNodes.Builder<Integer, String>()
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

        IKeyValueNodes<Integer, String> treeData3 = new KeyValueNodes.Builder<Integer, String>()
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
            Triple.of(treeData1, treeLevels1, treeMetrics1),
            Triple.of(treeData2, treeLevels2, treeMetrics2),
            Triple.of(treeData3, treeLevels3, treeMetrics3));
    }

    /**
     * Gets the least recently used data.
     */
    @Override
    public List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> getLRUData() {
        List<ITriple<String, IKeyValueNode<Integer, String>, List<IKeyValueNode<Integer, String>>>> data = new ArrayList<>();

        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("set", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(1, "a"), ArrayLists.of(KeyValueNode.of(1, "a"), KeyValueNode.of(5, "e"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(2, "b"), ArrayLists.of(KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"), KeyValueNode.of(5, "e"))));
        data.add(Triple.of("set", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"), KeyValueNode.of(1, "a"))));
        data.add(Triple.of("set", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(2, "b"))));
        data.add(Triple.of("set", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("get", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("get", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"))));
        data.add(Triple.of("get", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"), KeyValueNode.of(5, "e"))));
        data.add(Triple.of("get", KeyValueNode.of(5, "e"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(4, "d"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("delete", KeyValueNode.of(4, "d"), ArrayLists.of(KeyValueNode.of(5, "e"), KeyValueNode.of(3, "c"))));
        data.add(Triple.of("delete", KeyValueNode.of(3, "c"), ArrayLists.of(KeyValueNode.of(5, "e"))));
        data.add(Triple.of("delete", KeyValueNode.of(5, "e"), new ArrayList<>()));

        return data;
    }

    /**
     * Gets the doubly linked list data.
     */
    @Override
    public List<ITriple<String, Integer, List<Integer>>> getDoublyLinkedListData() {
        List<ITriple<String, Integer, List<Integer>>> data = new ArrayList<>();

        data.add(Triple.of("addToFront", 1, ArrayLists.of(1)));
        data.add(Triple.of("addToFront", 2, ArrayLists.of(2, 1)));
        data.add(Triple.of("addToFront", 3, ArrayLists.of(3, 2, 1)));
        data.add(Triple.of("removeFromFront", null, ArrayLists.of(2, 1)));
        data.add(Triple.of("removeFromFront", null, ArrayLists.of(1)));
        data.add(Triple.of("addToBack", 2, ArrayLists.of(1, 2)));
        data.add(Triple.of("addToBack", 3, ArrayLists.of(1, 2, 3)));
        data.add(Triple.of("addToBack", 4, ArrayLists.of(1, 2, 3, 4)));
        data.add(Triple.of("addToBack", 5, ArrayLists.of(1, 2, 3, 4, 5)));
        data.add(Triple.of("removeFromBack", null, ArrayLists.of(1, 2, 3, 4)));
        data.add(Triple.of("removeFromBack", null, ArrayLists.of(1, 2, 3)));

        return data;
    }
}
