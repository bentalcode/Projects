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
        List<IBinaryTreeNode<Integer, String>> creationData = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.make(BinaryTreeNodes.make(1, "a"));
        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.make(BinaryTreeNodes.make(1, "a"));

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

        creationData.add(BinaryTreeNodes.make(1, "a"));
        creationData.add(BinaryTreeNodes.make(2, "b"));
        creationData.add(BinaryTreeNodes.make(3, "c"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.make(4, "d"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.make(5, "e"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.make(
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(4, "d"));

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.make(
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(5, "e"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.make(
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(5, "e"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.make(
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(1, "a"));

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

        creationData.add(BinaryTreeNodes.make(1, "a"));
        creationData.add(BinaryTreeNodes.make(2, "b"));
        creationData.add(BinaryTreeNodes.make(4, "d"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.make(5, "e"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.make(3, "c"));
        creationData.add(BinaryTreeNodes.make(6, "f"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.make(7, "h"));
        creationData.add(BinaryTreeNodes.endNode());
        creationData.add(BinaryTreeNodes.endNode());

        List<IBinaryTreeNode<Integer, String>> levelOrder = ArrayLists.make(
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(6, "f"),
            BinaryTreeNodes.make(7, "h"));

        List<IBinaryTreeNode<Integer, String>> inorder = ArrayLists.make(
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(6, "f"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(7, "h"));

        List<IBinaryTreeNode<Integer, String>> preorder = ArrayLists.make(
            BinaryTreeNodes.make(1, "a"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(6, "f"),
            BinaryTreeNodes.make(7, "h"));

        List<IBinaryTreeNode<Integer, String>> postorder = ArrayLists.make(
            BinaryTreeNodes.make(4, "d"),
            BinaryTreeNodes.make(5, "e"),
            BinaryTreeNodes.make(2, "b"),
            BinaryTreeNodes.make(6, "f"),
            BinaryTreeNodes.make(7, "h"),
            BinaryTreeNodes.make(3, "c"),
            BinaryTreeNodes.make(1, "a"));

        return new BinaryTreeData<>(
            creationData,
            levelOrder,
            inorder,
            preorder,
            postorder);
    }
}
