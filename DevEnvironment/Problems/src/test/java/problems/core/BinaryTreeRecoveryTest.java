package problems.core;

import base.core.ArrayLists;
import datastructures.binarytree.core.BinaryTreeNodes;
import datastructures.binarytree.core.BinaryTreeStreamBuilder;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import java.util.ArrayList;
import java.util.List;
import problems.interfaces.IBinaryTreeRecovery;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

/**
 * The BinaryTreeRecoveryTest class implements tests for a binary tree recovery.
 */
public final class BinaryTreeRecoveryTest {
    private final IAssertion assertion = new Assertion();

    /**
     * The BinaryTreeRecoveryTest constructor.
     */
    public BinaryTreeRecoveryTest() {
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
     * Tests the logic of a recovery a binary tree.
     */
    @Test
    public void binaryTreeRecoveryTest() {
        List<IBinaryTreeNode<Integer, String>> data1 = ArrayLists.of(
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode());

        boolean status1 = false;

        List<IBinaryTreeNode<Integer, String>> result1 = data1;

        List<IBinaryTreeNode<Integer, String>> data2 = ArrayLists.of(
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode());

        boolean status2 = true;

        List<IBinaryTreeNode<Integer, String>> result2 = ArrayLists.of(
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode(),
            BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> data3 = new ArrayList<>(15);
        data3.add(BinaryTreeNodes.node(10, "d"));
        data3.add(BinaryTreeNodes.node(15, "f"));
        data3.add(BinaryTreeNodes.node(4, "a"));
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.node(7, "c"));
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.node(5, "b"));
        data3.add(BinaryTreeNodes.node(14, "e"));
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.node(17, "g"));
        data3.add(BinaryTreeNodes.endNode());
        data3.add(BinaryTreeNodes.endNode());

        boolean status3 = true;

        List<IBinaryTreeNode<Integer, String>> result3 = new ArrayList<>(15);
        result3.add(BinaryTreeNodes.node(10, "d"));
        result3.add(BinaryTreeNodes.node(5, "b"));
        result3.add(BinaryTreeNodes.node(4, "a"));
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.node(7, "c"));
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.node(15, "f"));
        result3.add(BinaryTreeNodes.node(14, "e"));
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.node(17, "g"));
        result3.add(BinaryTreeNodes.endNode());
        result3.add(BinaryTreeNodes.endNode());

        this.testBinaryTreeRecovery(data1, status1, result1);
        this.testBinaryTreeRecovery(data2, status2, result2);
        this.testBinaryTreeRecovery(data3, status3, result3);
    }

    /**
     * Tests the logic of a recovery a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testBinaryTreeRecovery(
        List<IBinaryTreeNode<TKey, TValue>> creationData,
        boolean expectedStatus,
        List<IBinaryTreeNode<TKey, TValue>> expectedData) {

        IBinaryTree<TKey, TValue> tree = BinaryTreeStreamBuilder.build(creationData);
        IBinaryTree<TKey, TValue> expectedTree = BinaryTreeStreamBuilder.build(expectedData);

        IBinaryTreeRecovery<TKey, TValue> binaryTreeRecovery = new BinaryTreeRecovery<>();
        boolean status = binaryTreeRecovery.recover(tree);

        this.assertion.assertTrue(
            status == expectedStatus && tree.equals(expectedTree),
            "Incorrect logic of a recovery of a binary tree.");
    }
}
