package datastructures.bplustree.interfaces;

import base.interfaces.IBinaryComparator;

/**
 * The IBPlusTreeNodeProperties interface defines properties of a node of a B+ tree.
 */
public interface IBPlusTreeNodeProperties<TKey extends Comparable<TKey>> {
    /**
     * Gets the degree of the B+ tree.
     */
    int getDegree();

    /**
     * Gets the class type of a key.
     */
    Class<TKey> getKeyClassType();

    /**
     * Gets a key comparator.
     */
    IBinaryComparator<TKey> getKeyComparator();

    /**
     * Gets a node comparator.
     */
    IBinaryComparator<IBPlusTreeNode<TKey>> getNodeComparator();

    /**
     * Gets the size of a key in bytes.
     */
    int getKeySizeInBytes();
}
