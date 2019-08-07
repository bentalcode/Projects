package datastructures.binarytree.core;

import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
import datastructures.binarytree.interfaces.IBinaryTreeNodeReverseIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

/**
 * The BinaryTreeTest class implements tests for a binary tree.
 */
public final class BinaryTreeTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The BinaryTreeTest constructor.
     */
    public BinaryTreeTest() {
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
     * Tests the creation logic of a binary tree.
     */
    @Test
    public void BinaryTreeCreationTest() {
        List<List<IBinaryTreeNode<Integer, String>>> data = this.testData.getBinaryTreeData().getData();

        for (List<IBinaryTreeNode<Integer, String>> treeData : data) {
            this.testCreation(BinaryTreeNodeListIterator.of(treeData));
        }
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    @Test
    public void BinaryTreeIterationTest() {
        List<List<IBinaryTreeNode<Integer, String>>> data = this.testData.getBinaryTreeData().getData();

        for (List<IBinaryTreeNode<Integer, String>> treeData : data) {
            this.testIteration(
                BinaryTreeNodeListIterator.of(treeData),
                BinaryTreeNodeListReverseIterator.of(treeData));
        }
    }

    /**
     * Tests the creation logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> dataIterator) {

        //
        // Create the tree...
        //
        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder<>(dataIterator);
        IBinaryTree<TKey, TValue> tree = builder.build();

        //
        // Test the data of the tree...
        //
        this.assertion.assertEquals(
            tree.getIterator(),
            dataIterator,
            "Invalid creation logic of a binary tree.");
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testIteration(
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> dataIterator,
        IBinaryTreeNodeReverseIterator<IBinaryTreeNode<TKey, TValue>> reverseDataIterator) {

        //
        // Create the tree...
        //
        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder<>(dataIterator);
        IBinaryTree<TKey, TValue> tree = builder.build();

        //
        // Test the default iterator of the container...
        //
        for (IBinaryTreeNode<TKey, TValue> currNode : tree) {

            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of default forward iteration.");
        }

        dataIterator.reset();

        //
        // Test the forward iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> iterator = tree.getIterator();

        while (iterator.hasNext() && dataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = iterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of forward iterator.");
        }

        dataIterator.reset();

        //
        // Test the reverse iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> reverseIterator = tree.getReverseIterator();

        while (reverseIterator.hasNext() && reverseDataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = reverseIterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = reverseDataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of reverse iterator.");
        }

        reverseDataIterator.reset();
    }
}
