package datastructures.plustree.core;

import base.core.Pair;
import base.core.Triple;
import base.interfaces.INullable;
import datastructures.core.TestData;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.core.BPlusTree;
import datastructures.bplustree.core.BPlusTreeFactory;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeFactory;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodeIterator;
import datastructures.node.interfaces.IKeyValueNodes;
import datastructures.tree.interfaces.ITreeMetrics;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import org.junit.Assert;
import java.util.List;

/**
 * The BPlusTreeTest class implements tests for a B+ tree.
 */
public final class BPlusTreeTest {
    private final ITestData testData = new TestData();

    /**
     * The BPlusTreeTest constructor.
     */
    public BPlusTreeTest() {
    }

    /**
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the creation logic of a B+ tree.
     */
    @Test
    public void createTreeTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getTreeProperties();

        List<Pair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> creationData =
            this.testData.getCreationData();

        for (Pair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>> entry : creationData) {
            IKeyValueNodes<Integer, String> treeData = entry.first();
            IBlockTreeLevels<Integer, INullable> treeLevels = entry.second();

            this.testCreateTree(
                treeProperties,
                treeData,
                treeLevels);
        }
    }

    /**
     * Tests the iteration logic of a B+ tree.
     */
    @Test
    public void iterateTreeTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getTreeProperties();

        List<Pair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> creationData =
            this.testData.getCreationData();

        for (Pair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>> entry : creationData) {
            IKeyValueNodes<Integer, String> treeData = entry.first();

            this.testIterateTree(
                treeProperties,
                treeData);
        }
    }

    /**
     * Tests the calculation of metrics of a B+ tree.
     */
    //@Test
    public void calculateTreeMetricsTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getTreeProperties();

        List<Triple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> data =
            this.testData.getTreesData();

        for (Triple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics> entry : data) {
            IKeyValueNodes<Integer, String> treeData = entry.first();
            IBPlusTreeMetrics treeMetrics = entry.third();

            this.testTreeMetrics(
                treeProperties,
                treeData,
                treeMetrics);
        }
    }

    /**
     * Tests the creation logic of a B+ tree
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreateTree(
        IBPlusTreeProperties<TKey, TValue> treeProperties,
        IKeyValueNodes<TKey, TValue> treeData,
        IBlockTreeLevels<TKey, INullable> expectedTreeLevels) {

        IBPlusTree<TKey, TValue> tree = new BPlusTree<>(treeProperties);

        IBlockTreeLevels<TKey, INullable> currTreeLevels = null;

        for (IKeyValueNode<TKey, TValue> node : treeData.getNodes()) {

            tree.insert(node.getKey(), node.getValue());

            currTreeLevels = tree.getTreeLevels();
        }

        boolean status = currTreeLevels.equals(expectedTreeLevels);

        Assert.assertTrue(
            "The creation logic of the B+ tree is invalid.",
            status);
    }

    /**
     * Tests the iteration logic of a B+ tree
     */
    private <TKey extends Comparable<TKey>, TValue> void testIterateTree(
        IBPlusTreeProperties<TKey, TValue> treeProperties,
        IKeyValueNodes<TKey, TValue> treeData) {

        IBPlusTreeFactory<TKey, TValue> treeFactory = new BPlusTreeFactory<>(treeProperties);
        IBPlusTree<TKey, TValue> tree = treeFactory.create(treeData);

        IKeyValueNodeIterator<TKey, TValue> currDataIterator = tree.getDataIterator();
        IKeyValueNodeIterator<TKey, TValue> expectedDataIterator = treeData.getIterator();

        while (currDataIterator.hasNext() && expectedDataIterator.hasNext()) {
            IKeyValueNode<TKey, TValue> currNodeData = currDataIterator.next();
            IKeyValueNode<TKey, TValue> expectedNodeData = expectedDataIterator.next();

            Assert.assertTrue(
                "The data of a node of a B+ tree is invalid.",
                currNodeData.equals(expectedNodeData));
        }

        Assert.assertTrue(
            "The number of data of a nodes in a B+ tree is invalid.",
            !currDataIterator.hasNext() && !expectedDataIterator.hasNext());
    }

    /**
     * Tests the calculation of metrics of a B+ tree
     */
    private <TKey extends Comparable<TKey>, TValue> void testTreeMetrics(
        IBPlusTreeProperties<TKey, TValue> treeProperties,
        IKeyValueNodes<TKey, TValue> treeData,
        ITreeMetrics expectedMetrics) {

        IBPlusTreeFactory<TKey, TValue> treeFactory = new BPlusTreeFactory<>(treeProperties);
        IBPlusTree<TKey, TValue> tree = treeFactory.create(treeData);

        ITreeMetrics currMetrics = tree.calculateMetrics();

        Assert.assertTrue(
            "The number of data of a nodes in a B+ tree is invalid.",
            currMetrics.equals(expectedMetrics));
    }
}
