package datastructures.binarytree.core;

import datastructures.binarytree.interfaces.IBinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTreeTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The BinaryTreeTestData class implements data of tests for a binary tree.
 */
public final class BinaryTreeTestData implements IBinaryTreeTestData {
    /**
     * The DoublyLinkedListTestData constructor.
     */
    public BinaryTreeTestData() {
    }

    /**
     * Gets the data of the tree.
     */
    @Override
    public List<List<IBinaryTreeNode<Integer, String>>> getData() {
        List<List<IBinaryTreeNode<Integer, String>>> data = new ArrayList<>();

        data.add(this.getTreeData1());
        data.add(this.getTreeData2());
        data.add(this.getTreeData3());
        data.add(this.getTreeData4());

        return data;
    }

    /**
     * Gets the data of tree1.
     */
    private List<IBinaryTreeNode<Integer, String>> getTreeData1() {
        List<IBinaryTreeNode<Integer, String>> data = new ArrayList<>();
        return data;
    }

    /**
     * Gets the data of tree2.
     */
    private List<IBinaryTreeNode<Integer, String>> getTreeData2() {
        List<IBinaryTreeNode<Integer, String>> data = new ArrayList<>();
        data.add(BinaryTreeNode.of(1, "a"));
        return data;
    }

    /**
     * Gets the data of tree2.
     */
    private List<IBinaryTreeNode<Integer, String>> getTreeData3() {
        List<IBinaryTreeNode<Integer, String>> data = new ArrayList<>();

        data.add(BinaryTreeNode.of(1, "a"));
        data.add(BinaryTreeNode.of(2, "b"));
        data.add(BinaryTreeNode.of(3, "c"));
        data.add(new BinaryTreeEndNode<>());
        data.add(BinaryTreeNode.of(4, "d"));
        data.add(new BinaryTreeEndNode<>());
        data.add(new BinaryTreeEndNode<>());
        data.add(BinaryTreeNode.of(5, "e"));
        data.add(new BinaryTreeEndNode<>());
        data.add(new BinaryTreeEndNode<>());

        return data;
    }

    /**
     * Gets the data of tree3.
     */
    private List<IBinaryTreeNode<Integer, String>> getTreeData4() {
        List<IBinaryTreeNode<Integer, String>> data = new ArrayList<>();

        data.add(BinaryTreeNode.of(1, "a"));
        data.add(BinaryTreeNode.of(2, "b"));
        data.add(BinaryTreeNode.of(3, "c"));
        data.add(new BinaryTreeEndNode<>());
        data.add(BinaryTreeNode.of(4, "d"));
        data.add(new BinaryTreeEndNode<>());
        data.add(new BinaryTreeEndNode<>());
        data.add(BinaryTreeNode.of(5, "e"));
        data.add(BinaryTreeNode.of(6, "f"));
        data.add(new BinaryTreeEndNode<>());
        data.add(BinaryTreeNode.of(7, "g"));
        data.add(new BinaryTreeEndNode<>());
        data.add(new BinaryTreeEndNode<>());
        data.add(new BinaryTreeEndNode<>());

        return data;
    }
}
