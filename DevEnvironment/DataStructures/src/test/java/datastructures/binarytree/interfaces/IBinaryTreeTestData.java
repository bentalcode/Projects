package datastructures.binarytree.interfaces;

import java.util.List;

/**
 * The IBinaryTreeTestData interface defines the data of the tests of a binary tree.
 */
public interface IBinaryTreeTestData {
    /**
     * Gets the data of the tree.
     */
    List<List<IBinaryTreeNode<Integer, String>>> getData();
}
