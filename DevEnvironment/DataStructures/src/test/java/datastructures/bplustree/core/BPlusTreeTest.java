package datastructures.bplustree.core;

import base.interfaces.IIterator;
import base.interfaces.INullable;
import base.interfaces.IPair;
import base.interfaces.ITriple;
import datastructures.core.TestData;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import datastructures.bplustree.interfaces.IBPlusTree;
import datastructures.bplustree.interfaces.IBPlusTreeFactory;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;
import datastructures.interfaces.ITestData;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.node.interfaces.IKeyValueNodes;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The BPlusTreeTest class implements tests for a B+ tree.
 */
public final class BPlusTreeTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The BPlusTreeTest constructor.
     */
    public BPlusTreeTest() {
    }

    /**
     * Tests the creation logic of a B+ tree.
     */
    @Test
    public void bplusTreeCreationTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getBPlusData().getTreeProperties();

        List<IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> creationData =
            this.testData.getBPlusData().getCreationData();

        for (IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>> entry : creationData) {
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
    public void bplusTreeIterationTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getBPlusData().getTreeProperties();

        List<IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>>> creationData =
            this.testData.getBPlusData().getCreationData();

        for (IPair<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>> entry : creationData) {
            IKeyValueNodes<Integer, String> treeData = entry.first();

            this.testIterateTree(
                treeProperties,
                treeData);
        }
    }

    /**
     * Tests the calculation of metrics of a B+ tree.
     */
    @Test
    public void bplusTreeCalculateMetricsTest() {
        IBPlusTreeProperties<Integer, String> treeProperties = this.testData.getBPlusData().getTreeProperties();

        List<ITriple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics>> data =
            this.testData.getBPlusData().getTreesData();

        for (ITriple<IKeyValueNodes<Integer, String>, IBlockTreeLevels<Integer, INullable>, IBPlusTreeMetrics> entry : data) {
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

        this.assertion.assertEquals(
            currTreeLevels,
            expectedTreeLevels,
            "The creation logic of the B+ tree is invalid.");
    }

    /**
     * Tests the iteration logic of a B+ tree
     */
    private <TKey extends Comparable<TKey>, TValue> void testIterateTree(
        IBPlusTreeProperties<TKey, TValue> treeProperties,
        IKeyValueNodes<TKey, TValue> treeData) {

        IBPlusTreeFactory<TKey, TValue> treeFactory = new BPlusTreeFactory<>(treeProperties);
        IBPlusTree<TKey, TValue> tree = treeFactory.create(treeData);

        IIterator<IKeyValueNode<TKey, TValue>> currDataIterator = tree.getIterator();
        IIterator<IKeyValueNode<TKey, TValue>> expectedDataIterator = treeData.getIterator();

        while (currDataIterator.hasNext() && expectedDataIterator.hasNext()) {
            IKeyValueNode<TKey, TValue> currNodeData = currDataIterator.next();
            IKeyValueNode<TKey, TValue> expectedNodeData = expectedDataIterator.next();

            this.assertion.assertTrue(
                currNodeData.equals(expectedNodeData),
                "The data of a node of a B+ tree is invalid.");
        }

        this.assertion.assertTrue(
            !currDataIterator.hasNext() && !expectedDataIterator.hasNext(),
            "The number of data of a nodes in a B+ tree is invalid.");
    }

    /**
     * Tests the calculation of metrics of a B+ tree
     */
    private <TKey extends Comparable<TKey>, TValue> void testTreeMetrics(
        IBPlusTreeProperties<TKey, TValue> treeProperties,
        IKeyValueNodes<TKey, TValue> treeData,
        IBPlusTreeMetrics expectedMetrics) {

        IBPlusTreeFactory<TKey, TValue> treeFactory = new BPlusTreeFactory<>(treeProperties);
        IBPlusTree<TKey, TValue> tree = treeFactory.create(treeData);

        IBPlusTreeMetrics currMetrics = tree.calculateMetrics();

        this.assertion.assertEquals(
            currMetrics,
            expectedMetrics,
            "Invalid metrics.");
    }
}
