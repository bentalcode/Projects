package datastructures.binarytree.core;

import base.core.ArrayLists;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeData;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeNodeIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import java.util.ArrayList;
import java.util.List;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

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
    public void binaryTreeCreationTest() {
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testCreation(treeData);
        }
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    @Test
    public void binaryTreeIterationTest() {
        List<IBinaryTreeData<Integer, String>> data = this.testData.getBinaryTreeData().getData();

        for (IBinaryTreeData<Integer, String> treeData : data) {
            this.testIteration(treeData);
        }
    }

    /**
     * Tests the equality logic of a binary tree.
     */
    @Test
    public void binaryTreeEqualityTest() {
        List<IBinaryTreeNode<Integer, String>> tree1a = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> tree1b = new ArrayList<>();
        boolean status1 = true;

        List<IBinaryTreeNode<Integer, String>> tree2a = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> tree2b = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        boolean status2 = true;

        List<IBinaryTreeNode<Integer, String>> tree3a = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> tree3b = ArrayLists.make(BinaryTreeNodes.make(2, "b"));
        boolean status3 = false;

        List<IBinaryTreeNode<Integer, String>> tree4a = new ArrayList<>(11);
        tree4a.add(BinaryTreeNodes.make(1, "a"));
        tree4a.add(BinaryTreeNodes.make(2, "b"));
        tree4a.add(BinaryTreeNodes.make(4, "d"));
        tree4a.add(BinaryTreeNodes.endNode());
        tree4a.add(BinaryTreeNodes.endNode());
        tree4a.add(BinaryTreeNodes.make(5, "b"));
        tree4a.add(BinaryTreeNodes.endNode());
        tree4a.add(BinaryTreeNodes.endNode());
        tree4a.add(BinaryTreeNodes.make(3, "c"));
        tree4a.add(BinaryTreeNodes.endNode());
        tree4a.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> tree4b = new ArrayList<>(11);
        tree4b.add(BinaryTreeNodes.make(1, "a"));
        tree4b.add(BinaryTreeNodes.make(2, "b"));
        tree4b.add(BinaryTreeNodes.make(4, "d"));
        tree4b.add(BinaryTreeNodes.endNode());
        tree4b.add(BinaryTreeNodes.endNode());
        tree4b.add(BinaryTreeNodes.make(5, "b"));
        tree4b.add(BinaryTreeNodes.endNode());
        tree4b.add(BinaryTreeNodes.endNode());
        tree4b.add(BinaryTreeNodes.make(3, "c"));
        tree4b.add(BinaryTreeNodes.endNode());
        tree4b.add(BinaryTreeNodes.endNode());

        boolean status4 = true;

        List<IBinaryTreeNode<Integer, String>> tree5a = new ArrayList<>(11);
        tree5a.add(BinaryTreeNodes.make(1, "a"));
        tree5a.add(BinaryTreeNodes.make(2, "b"));
        tree5a.add(BinaryTreeNodes.make(4, "d"));
        tree5a.add(BinaryTreeNodes.endNode());
        tree5a.add(BinaryTreeNodes.endNode());
        tree5a.add(BinaryTreeNodes.make(5, "b"));
        tree5a.add(BinaryTreeNodes.endNode());
        tree5a.add(BinaryTreeNodes.endNode());
        tree5a.add(BinaryTreeNodes.make(3, "c"));
        tree5a.add(BinaryTreeNodes.endNode());
        tree5a.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> tree5b = new ArrayList<>(11);
        tree5b.add(BinaryTreeNodes.make(1, "a"));
        tree5b.add(BinaryTreeNodes.make(2, "b"));
        tree5b.add(BinaryTreeNodes.endNode());
        tree5b.add(BinaryTreeNodes.endNode());
        tree5b.add(BinaryTreeNodes.make(3, "c"));
        tree5b.add(BinaryTreeNodes.make(4, "d"));
        tree5b.add(BinaryTreeNodes.endNode());
        tree5b.add(BinaryTreeNodes.endNode());
        tree5b.add(BinaryTreeNodes.make(5, "e"));
        tree5b.add(BinaryTreeNodes.endNode());
        tree5b.add(BinaryTreeNodes.endNode());

        boolean status5 = false;

        this.testEquality(tree1a, tree1b, status1);
        this.testEquality(tree2a, tree2b, status2);
        this.testEquality(tree3a, tree3b, status3);
        this.testEquality(tree4a, tree4b, status4);
        this.testEquality(tree5a, tree5b, status5);
    }

    /**
     * Tests the creation logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(IBinaryTreeData<TKey, TValue> data) {
        //
        // Create the tree...
        //
        IBinaryTree<TKey, TValue> tree = BinaryTreeStreamBuilder.build(data.getCreationData());

        //
        // Test the data of the tree...
        //
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> levelOrderIterator =
            BinaryTreeNodeListIterator.make(data.getLevelOrder());

        this.assertion.assertEqualsWithIterators(
            tree.getLevelOrderIterator(),
            levelOrderIterator,
            "Invalid creation logic of a binary tree.");
    }

    /**
     * Tests the iteration logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testIteration(IBinaryTreeData<TKey, TValue> data) {
        //
        // Create the tree...
        //
        IBinaryTree<TKey, TValue> tree = BinaryTreeStreamBuilder.build(data.getCreationData());

        //
        // Test the logic of a default iteration...
        //
        this.testDefaultIteration(tree, BinaryTreeNodeListIterator.make(data.getInorder()));

        //
        // Test the logic of a reverse iteration...
        //
        IReverseIterator<IBinaryTreeNode<TKey, TValue>> reverseIterator = tree.getReverseIterator();
        IIterator<IBinaryTreeNode<TKey, TValue>> reverseDataIterator = BinaryTreeNodeListReverseIterator.make(data.getInorder());
        this.testIteration(reverseIterator, reverseDataIterator, "Reverse Iterator");

        //
        // Test the logic of a level order iteration...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> levelOrderIterator = tree.getLevelOrderIterator();
        IIterator<IBinaryTreeNode<TKey, TValue>> levelOrderDataIterator = BinaryTreeNodeListIterator.make(data.getLevelOrder());
        this.testIteration(levelOrderIterator, levelOrderDataIterator, "Level Order Iterator");

        //
        // Test the logic of an inorder iteration...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> inorderIterator = tree.getInorderIterator();
        IIterator<IBinaryTreeNode<TKey, TValue>> inorderDataIterator = BinaryTreeNodeListIterator.make(data.getInorder());
        this.testIteration(inorderIterator, inorderDataIterator, "Inorder Iterator");

        //
        // Test the logic of a preorder iteration...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> preorderIterator = tree.getPreorderIterator();
        IIterator<IBinaryTreeNode<TKey, TValue>> preorderDataIterator = BinaryTreeNodeListIterator.make(data.getPreorder());
        this.testIteration(preorderIterator, preorderDataIterator, "Preorder Iterator");

        //
        // Test the logic of a postorder iteration...
        //
        IIterator<IBinaryTreeNode<TKey, TValue>> postorderIterator = tree.getPostorderIterator();
        IIterator<IBinaryTreeNode<TKey, TValue>> postorderDataIterator = BinaryTreeNodeListIterator.make(data.getPostorder());
        this.testIteration(postorderIterator, postorderDataIterator, "Postorder Iterator");
    }

    /**
     * Tests the logic of default iteration of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testDefaultIteration(
        IBinaryTree<TKey, TValue> tree,
        IIterator<IBinaryTreeNode<TKey, TValue>> dataIterator) {

        for (IBinaryTreeNode<TKey, TValue> currNode : tree) {
            IBinaryTreeNode<TKey, TValue> dataNode = dataIterator.next();

            this.assertion.assertEquals(
                currNode,
                dataNode,
                "Incorrect logic of default iteration.");
        }
    }

    /**
     * Tests the logic of iteration of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testIteration(
        IIterator<IBinaryTreeNode<TKey, TValue>> treeIterator,
        IIterator<IBinaryTreeNode<TKey, TValue>> dataIterator,
        String iteratorName) {

        this.assertion.assertEqualsWithIterators(
            treeIterator,
            dataIterator,
            "Incorrect logic of iteration of: " + iteratorName);
    }

    /**
     * Tests the equality logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testEquality(
        List<IBinaryTreeNode<TKey, TValue>> left,
        List<IBinaryTreeNode<TKey, TValue>> right,
        boolean expectedStatus) {

        IBinaryTree<TKey, TValue> leftTree = BinaryTreeStreamBuilder.build(left);
        IBinaryTree<TKey, TValue> rightTree = BinaryTreeStreamBuilder.build(right);

        boolean status = leftTree.equals(rightTree);

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Incorrect logic of equality of binary trees.");
    }
}
