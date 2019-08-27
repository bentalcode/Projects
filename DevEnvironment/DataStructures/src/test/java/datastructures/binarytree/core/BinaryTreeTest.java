package datastructures.binarytree.core;

import base.core.ListIterator;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeData;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
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
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getTreesData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testCreation(treeData);
        }
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    @Test
    public void BinaryTreeIterationTest() {
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getTreesData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testIteration(treeData);
        }
    }

    /**
     * Tests the creation logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(IBinaryTreeData<TKey, TValue> treeData) {
        //
        // Create the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> dataIterator =
            BinaryTreeNodeListIterator.of(treeData.getCreationData());

        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder<>(dataIterator);
        IBinaryTree<TKey, TValue> tree = builder.build();

        //
        // Test the data of the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> preOrderIterator =
            BinaryTreeNodeListIterator.of(treeData.getPreorder());

        this.assertion.assertEquals(
            tree.getPreorderIterator(),
            preOrderIterator,
            "Invalid creation logic of a binary tree.");
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testIteration(IBinaryTreeData<TKey, TValue> treeData) {
        //
        // Create the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> creationDataIterator =
            BinaryTreeNodeListIterator.of(treeData.getCreationData());

        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder<>(creationDataIterator);
        IBinaryTree<TKey, TValue> tree = builder.build();

        //
        // Test the default iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> dataIterator = ListIterator.of(treeData.getInorder());

        for (IBinaryTreeNode<TKey, TValue> currNode : tree) {

            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of default forward iteration.");
        }

        //
        // Test the forward iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> iterator = tree.getIterator();
        dataIterator = ListIterator.of(treeData.getInorder());

        while (iterator.hasNext() && dataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = iterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of forward iterator.");
        }

        //
        // Test the reverse iterator of the container...
        //
        IReverseIterator<IBinaryTreeNode<TKey, TValue>> reverseIterator = tree.getReverseIterator();
        IReverseIterator<IBinaryTreeNode<TKey, TValue>> reverseDataIterator =
            BinaryTreeNodeListReverseIterator.of(treeData.getInorder());

        while (reverseIterator.hasNext() && reverseDataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = reverseIterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = reverseDataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of reverse iterator.");
        }

        //
        // Test the inorder iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> inorderIterator = tree.getInorderIterator();
        dataIterator = ListIterator.of(treeData.getInorder());

        while (iterator.hasNext() && dataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = inorderIterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                    currNode,
                    dataNode,
                    "Invalid logic of inorder iterator.");
        }

        //
        // Test the preorder iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> preorderIterator = tree.getPreorderIterator();
        dataIterator = ListIterator.of(treeData.getPreorder());

        while (preorderIterator.hasNext() && dataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = preorderIterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of preorder iterator.");
        }

        //
        // Test the postorder iterator of the container...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> postorderIterator = tree.getPostorderIterator();
        dataIterator = ListIterator.of(treeData.getPostorder());

        while (postorderIterator.hasNext() && dataIterator.hasNext()) {
            IBinaryTreeNode<TKey, TValue> currNode = postorderIterator.next();
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Invalid logic of postorder iterator.");
        }
    }
}
