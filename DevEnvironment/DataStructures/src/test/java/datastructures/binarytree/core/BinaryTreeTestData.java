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
     * The BinaryTreeTestData constructor.
     */
    public BinaryTreeTestData() {
    }

    /**
     * Gets the data of the trees.
     */
    @Override
    public List<IBinaryTreeData<Integer, String>> getData() {
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
        List<IBinaryTreeNode<Integer, String>> levelOrder = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> inorder = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> preorder = new ArrayList<>();
        List<IBinaryTreeNode<Integer, String>> postorder = new ArrayList<>();

        return new BinaryTreeData<>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree2.
     */
    private IBinaryTreeData<Integer, String> getTreeData2() {
        List<IBinaryTreeNode<Integer, String>> creationData = ArrayLists.of(BinaryTreeNodes.node(1, "a"));
        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.of(BinaryTreeNodes.node(1, "a"));
        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(BinaryTreeNodes.node(1, "a"));
        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(BinaryTreeNodes.node(1, "a"));
        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(BinaryTreeNodes.node(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree3.
     */
    private IBinaryTreeData<Integer, String> getTreeData3() {
        List<IBinaryTreeNode<Integer, String>> creationData = new ArrayList<>();

        creationData.add(BinaryTreeNodes.node(1, "a"));
        creationData.add(BinaryTreeNodes.node(2, "b"));
        creationData.add(BinaryTreeNodes.node(3, "c"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.node(4, "d"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.node(5, "e"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.of(
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(4, "d"));

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(5, "e"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(5, "e"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder);
    }

    /**
     * Gets the data of tree4.
     */
    private IBinaryTreeData<Integer, String> getTreeData4() {
        List<IBinaryTreeNode<Integer, String>> creationData = new ArrayList<>();

        creationData.add(BinaryTreeNodes.node(1, "a"));
        creationData.add(BinaryTreeNodes.node(2, "b"));
        creationData.add(BinaryTreeNodes.node(4, "d"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.node(5, "e"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.node(3, "c"));
        creationData.add(BinaryTreeNodes.node(6, "f"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.node(7, "h"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.of(
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(6, "f"),
            BinaryTreeNodes.node(7, "h"));

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.of(
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(6, "f"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(7, "h"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.of(
            BinaryTreeNodes.node(1, "a"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(6, "f"),
            BinaryTreeNodes.node(7, "h"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.of(
            BinaryTreeNodes.node(4, "d"),
            BinaryTreeNodes.node(5, "e"),
            BinaryTreeNodes.node(2, "b"),
            BinaryTreeNodes.node(6, "f"),
            BinaryTreeNodes.node(7, "h"),
            BinaryTreeNodes.node(3, "c"),
            BinaryTreeNodes.node(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder);
    }
}
