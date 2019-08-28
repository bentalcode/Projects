package datastructures.binarytree.core;

import base.core.ArrayLists;
import datastructures.binarytree.interfaces.IBinaryTreeData;
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
     * Gets the data of the trees.
     */
    @Override
    public List<IBinaryTreeData<Integer, String>> getTreesData() {
        List<IBinaryTreeData<Integer, String>> data = new ArrayList<>();

        data.add(this.getTreeData1());
        data.add(this.getTreeData2());
        data.add(this.getTreeData3());
        data.add(this.getTreeData4());

        return data;
    }

    /**
     * Gets the data of tree1.
     */
    private IBinaryTreeData<Integer, String> getTreeData1() {
        List<IBinaryTreeNode<Integer, String>> creationData = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> inorder = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> preorder = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> postorder = new ArrayList<>();

        return new BinaryTreeData<>(
            creationData,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree2.
     */
    private IBinaryTreeData<Integer, String> getTreeData2() {
        List<IBinaryTreeNode<Integer, String>> creationData = ArrayLists.of(BinaryTreeNode.of(1, "a"));
        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(BinaryTreeNode.of(1, "a"));
        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(BinaryTreeNode.of(1, "a"));
        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(BinaryTreeNode.of(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree3.
     */
    private IBinaryTreeData<Integer, String> getTreeData3() {
        List<IBinaryTreeNode<Integer, String>> creationData = new ArrayList<>();

        creationData.add(BinaryTreeNode.of(1, "a"));
        creationData.add(BinaryTreeNode.of(2, "b"));
        creationData.add(BinaryTreeNode.of(3, "c"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(BinaryTreeNode.of(4, "d"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(BinaryTreeNode.of(5, "e"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(1, "a"),
            BinaryTreeNode.of(5, "e"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(
            BinaryTreeNode.of(1, "a"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(5, "e"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(5, "e"),
            BinaryTreeNode.of(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree4.
     */
    private IBinaryTreeData<Integer, String> getTreeData4() {
        List<IBinaryTreeNode<Integer, String>> creationData = new ArrayList<>();

        creationData.add(BinaryTreeNode.of(1, "a"));
        creationData.add(BinaryTreeNode.of(2, "b"));
        creationData.add(BinaryTreeNode.of(4, "d"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(BinaryTreeNode.of(5, "e"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(BinaryTreeNode.of(3, "c"));
        creationData.add(BinaryTreeNode.of(6, "f"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(BinaryTreeNode.of(7, "h"));
        creationData.add(new BinaryTreeEndNode<>());
        creationData.add(new BinaryTreeEndNode<>());

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(5, "e"),
            BinaryTreeNode.of(1, "a"),
            BinaryTreeNode.of(6, "f"),
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(7, "h"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(
            BinaryTreeNode.of(1, "a"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(5, "e"),
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(6, "f"),
            BinaryTreeNode.of(7, "h"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(
            BinaryTreeNode.of(4, "d"),
            BinaryTreeNode.of(5, "e"),
            BinaryTreeNode.of(2, "b"),
            BinaryTreeNode.of(6, "f"),
            BinaryTreeNode.of(7, "h"),
            BinaryTreeNode.of(3, "c"),
            BinaryTreeNode.of(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            inorder,
            preorder,
            postorder);
    }
}
