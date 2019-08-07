package datastructures.binarytree.core;

import base.interfaces.IBuilder;
import datastructures.binarytree.interfaces.IBinaryTree;
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
        List<List<IBinaryTreeNode<Integer, String>>> data = this.testData.getBinaryTreeData().getData();

        for (List<IBinaryTreeNode<Integer, String>> treeData : data) {
            this.testCreation(BinaryTreeNodeListIterator.of(treeData));
        }
    }

    /**
     * Tests the creation logic of a binary tree.
     */
    private <TKey extends Comparable<TKey>, TValue> void testCreation(
        IBinaryTreeNodeIterator<IBinaryTreeNode<TKey, TValue>> iterator) {

        iterator.includeEndNodes();
        IBuilder<IBinaryTree<TKey, TValue>> builder = new BinaryTreeStreamBuilder(iterator);
        IBinaryTree<TKey, TValue> tree = builder.build();
        iterator.skipEndNodes();

        this.assertion.assertEquals(
            tree.getIterator(),
            iterator,
            "Invalid creation logic of a binary tree.");
    }
}
