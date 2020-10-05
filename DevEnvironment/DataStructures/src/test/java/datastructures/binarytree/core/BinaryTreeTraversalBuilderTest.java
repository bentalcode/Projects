package datastructures.binarytree.core;

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
 * The BinaryTreeTraversalBuilderUnitTest class implements tests of building a binary tree
 * from various traversals.
 */
public final class BinaryTreeTraversalBuilderTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The BinaryTreeTraversalBuilderTest constructor.
     */
    public BinaryTreeTraversalBuilderTest() {
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
     * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
     */
    @Test
    public void binaryTreePreorderInorderTraversalBuilderTest() {
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testPreorderInorderTraversalBuilder(treeData);
        }
    }

    /**
     * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
     */
    @Test
    public void binaryTreePreorderPostorderTraversalBuilderTest() {
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testPreorderPostorderTraversalBuilder(treeData);
        }
    }

    /**
     * Tests the creation logic of a binary tree from a preorder and an inorder traversal.
     */
    private <TKey extends Comparable<TKey>, TValue> void testPreorderInorderTraversalBuilder(
        IBinaryTreeData<TKey, TValue> data) {

        //
        // Create the tree...
        //
        IBinaryTree<TKey, TValue> tree = BinaryTreeTraversalsBuilder.buildFromPreorderInorderTraversal(
            data.getPreorderData(),
            data.getInorderData());

        //
        // Test the data of the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> levelOrderIterator =
            BinaryTreeNodeListIterator.make(data.getLevelOrder());

        this.assertion.assertEqualsWithIterators(
            tree.getLevelOrderIterator(),
            levelOrderIterator,
            "Invalid creation logic of a binary tree from a preorder and an inorder traversal.");
    }

    /**
     * Tests the creation logic of a binary tree from a preorder and a postorder traversal.
     */
    private <TKey extends Comparable<TKey>, TValue> void testPreorderPostorderTraversalBuilder(
        IBinaryTreeData<TKey, TValue> data) {

        //
        // Create the tree...
        //
        IBinaryTree<TKey, TValue> tree = BinaryTreeTraversalsBuilder.buildFromPreorderPostorderTraversal(
            data.getPreorderData(),
            data.getPostorderData());

        //
        // Test the data of the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> levelOrderIterator =
            BinaryTreeNodeListIterator.make(data.getLevelOrder());

        this.assertion.assertEqualsWithIterators(
            tree.getLevelOrderIterator(),
            levelOrderIterator,
            "Invalid creation logic of a binary tree from a preorder and a postorder traversal.");
    }
}
