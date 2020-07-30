package problems.core;

import base.interfaces.IBinaryComparator;
import datastructures.binarytree.core.BinaryTreeNode;
import datastructures.binarytree.interfaces.IBinaryTree;
import datastructures.binarytree.interfaces.IBinaryTreeNode;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import problems.interfaces.IBinaryTreeRecovery;

/**
 * The BinaryTreeRecovery class implements a recovery of a binary search tree.
 */
public final class BinaryTreeRecovery<TKey extends Comparable<TKey>, TValue>
    implements IBinaryTreeRecovery<TKey, TValue> {

    private final Logger log = LoggerFactory.getLogger(this.getClass());

    /**
     * The BinaryTreeRecovery constructor.
     */
    public BinaryTreeRecovery() {
    }

    /**
     * Recovers a binary tree.
     *
     * Two elements of a binary search tree (BST) are swapped by mistake.
     * Recover the tree without changing its structure.
     *
     * Returns false if the tree is not needed to get recovered.
     */
    @Override
    public boolean recover(IBinaryTree<TKey, TValue> tree) {
        if (tree == null) {
            return false;
        }

        //
        // Search the first and last out of order nodes in a binary search tree.
        //
        SearchResult<TKey, TValue> searchResult = new SearchResult<>();
        search(
            tree.getRoot(),
            BinaryTreeNode.defaultComparator(),
            searchResult);

        boolean status = swapNodeKeyValue(
            searchResult.firstOutOfOrderNode,
            searchResult.getLastOutOfOrderNode());

        if (status) {
            String informationalMessage =
                "The binary tree has been recovered by swapping values of nodes: " +
                searchResult.getFirstOutOfOrderNode() + " and " +
                searchResult.getLastOutOfOrderNode();

            this.log.info(informationalMessage);
        }

        return status;
    }

    /**
     * Searches the first and last out of order nodes in a binary search tree.
     */
    private static <TKey extends Comparable<TKey>, TValue> void search(
        IBinaryTreeNode<TKey, TValue> root,
        IBinaryComparator<IBinaryTreeNode<TKey, TValue>> comparator,
        SearchResult<TKey, TValue> searchResult) {

        if (root == null) {
            return;
        }

        search(root.getLeftChild(), comparator, searchResult);

        IBinaryTreeNode<TKey, TValue> prevNode = searchResult.getPrevNode();

        int compareStatus = comparator.compareTo(prevNode, root);

        if (compareStatus >= 1) {
            if (searchResult.getFirstOutOfOrderNode() == null) {
                searchResult.setFirstOutOfOrderNode(prevNode);
            }

            searchResult.setLastOutOfOrderNode(root);
        }

        searchResult.setPrevNode(root);

        search(root.getRightChild(), comparator, searchResult);
    }

    /**
     * Swaps the key-value data of two nodes.
     */
    static <TKey extends Comparable<TKey>, TValue> boolean swapNodeKeyValue(
        IBinaryTreeNode<TKey, TValue> first,
        IBinaryTreeNode<TKey, TValue> second) {

        if (first == null || second == null) {
            return false;
        }

        TKey tempKey = first.getKey();
        TValue tempValue = first.getValue();

        first.setKey(second.getKey());
        first.setValue(second.getValue());
        second.setKey(tempKey);
        second.setValue(tempValue);

        return true;
    }

    /**
     * The SearchResult class implements the captured search data.
     */
    private static class SearchResult<TKey extends Comparable<TKey>, TValue> {
        private IBinaryTreeNode<TKey, TValue> prevNode;
        private IBinaryTreeNode<TKey, TValue> firstOutOfOrderNode;
        private IBinaryTreeNode<TKey, TValue> lastOutOfOrderNode;

        public SearchResult() {
        }

        public void setPrevNode(IBinaryTreeNode<TKey, TValue> node) {
            this.prevNode = node;
        }

        public IBinaryTreeNode<TKey, TValue> getPrevNode() {
            return this.prevNode;
        }

        public void setFirstOutOfOrderNode(IBinaryTreeNode<TKey, TValue> node) {
            this.firstOutOfOrderNode = node;
        }

        public IBinaryTreeNode<TKey, TValue> getFirstOutOfOrderNode() {
            return this.firstOutOfOrderNode;
        }

        public void setLastOutOfOrderNode(IBinaryTreeNode<TKey, TValue> node) {
            this.lastOutOfOrderNode = node;
        }

        public IBinaryTreeNode<TKey, TValue> getLastOutOfOrderNode() {
            return this.lastOutOfOrderNode;
        }
    }
}
