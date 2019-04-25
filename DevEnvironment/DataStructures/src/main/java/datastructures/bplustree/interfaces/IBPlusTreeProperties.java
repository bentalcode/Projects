package datastructures.bplustree.interfaces;

import base.interfaces.IBinaryComparator;

/**
 * The IBPlusTreeProperties interface defines properties of a B+ tree.
 */
public interface IBPlusTreeProperties<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the degree of the tree.
     */
    int getDegree();

    /**
     * Gets a node comparator.
     */
    IBinaryComparator<IBPlusTreeNode<TKey>> getNodeComparator();

    /**
     * Gets the properties of an inner node.
     */
    IBPlusTreeInnerNodeProperties<TKey> getInnerNodeProperties();

    /**
     * Gets the properties of a leaf node.
     */
    IBPlusTreeLeafNodeProperties<TKey, TValue> getLeafNodeProperties();
}
