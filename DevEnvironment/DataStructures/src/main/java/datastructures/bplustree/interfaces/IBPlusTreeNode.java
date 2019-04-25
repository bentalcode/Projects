package datastructures.bplustree.interfaces;

import base.interfaces.IUnaryComparator;
import datastructures.bplustree.core.TreeNodeType;
import java.util.List;

/**
 * The IBPlusTreeNode interface defines a node in a B+ Tree.
 */
public interface IBPlusTreeNode<TKey extends Comparable<TKey>> extends IUnaryComparator<IBPlusTreeNode<TKey>> {
    /**
     * Gets the type of a node.
     */
    TreeNodeType getNodeType();

    /**
     * Gets the properties of a node.
     */
    IBPlusTreeNodeProperties<TKey> getProperties();

    /**
     * Gets a key of a node by index.
     */
    TKey getKey(int index);

    /**
     * Sets a key of a node by index.
     */
    void setKey(int index, TKey key);

    /**
     * Gets the keys of a node.
     */
    List<TKey> getKeys();

    /**
     * Gets the key count of a node.
     */
    int getKeyCount();

    /**
     * Sets the key count of a node.
     */
    void setKeyCount(int keyCount);

    /**
     * Gets the parent of a node.
     */
    IBPlusTreeNode<TKey> getParent();

    /**
     * Sets the parent of a node.
     */
    void setParent(IBPlusTreeNode<TKey> parent);

    /**
     * Gets the left sibling.
     */
    IBPlusTreeNode<TKey> getLeftSibling();

    /**
     * Sets the left sibling.
     */
	void setLeftSibling(IBPlusTreeNode<TKey> sibling);

    /**
     * Gets the right sibling.
     */
	IBPlusTreeNode<TKey> getRightSibling();

    /**
     * Sets the right sibling.
     */
    void setRightSibling(IBPlusTreeNode<TKey> sibling);

    /**
     * Finds a position of a key.
     * If found the key, then return it's position, otherwise return -1.
     * For a leaf node, returns a child node index which should contain the key for an internal node.
     */
    int findPosition(TKey key);

    /**
     * Pushes up a key.
     */
    IBPlusTreeNode<TKey> pushUpKey(
        TKey key,
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild);

    /**
     * Checks whether a key can be lent.
     */
    boolean canLendAKey();

    /**
     * Checks whether an overflow condition is set.
     */
    boolean isOverflow();

    /**
     * Checks whether there is underflow condition.
     */
    boolean isUnderflow();

    /**
     * Processes an overflow.
     */
    IBPlusTreeNode<TKey> processOverflow();

    /**
     * Processes underflow.
     */
    IBPlusTreeNode<TKey> processUnderflow();

    /**
     * Processes children transfer.
     */
    void processChildrenTransfer(
        IBPlusTreeNode<TKey> borrower,
        IBPlusTreeNode<TKey> lender,
        int borrowIndex);

    /**
     * Processes children fusion.
     */
    IBPlusTreeNode<TKey> processChildrenFusion(
        IBPlusTreeNode<TKey> leftChild,
        IBPlusTreeNode<TKey> rightChild);

    /**
     * Fusions with sibling.
     */
    void fusionWithSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> rightSibling);

    /**
     * Transfers from sibling.
     */
    TKey transferFromSibling(
        TKey sinkKey,
        IBPlusTreeNode<TKey> sibling,
        int borrowIndex);

    /**
     * Gets the size of a node in bytes.
     */
    int getSizeInBytes();
}
