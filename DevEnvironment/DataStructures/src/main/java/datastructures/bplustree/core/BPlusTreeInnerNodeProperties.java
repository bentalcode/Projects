package datastructures.bplustree.core;

import testbase.core.Conditions;
import base.interfaces.IBinaryComparator;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNodeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeNode;

/**
 * The BPlusTreeInnerNodeProperties class implements properties of an inner node of a B+ Tree.
 */
public final class BPlusTreeInnerNodeProperties<TKey extends Comparable<TKey>> implements IBPlusTreeInnerNodeProperties<TKey> {

    private final int degree;
    private final Class<TKey> keyClassType;
    private final IBinaryComparator<TKey> keyComparator;
    private final IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator;
    private final int keySizeInBytes;

    /**
     * The BPlusTreeInnerNodeProperties constructor.
     */
    public BPlusTreeInnerNodeProperties(
        int degree,
        Class<TKey> keyClassType,
        IBinaryComparator<TKey> keyComparator,
        IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator,
        int keySizeInBytes) {

        Conditions.validate(
            degree >= 3,
            "The minimum degree of a B+ tree is 3.");

        Conditions.validateNotNull(
            keyClassType,
            "The class type of a key of a B+ tree.");

        Conditions.validateNotNull(
            nodeComparator,
            "The comparator of a node of a B+ tree.");

        Conditions.validate(
            keySizeInBytes > 0,
            "The size of bytes of a key have to be positive.");

        this.degree = degree;
        this.keyClassType = keyClassType;
        this.keyComparator = keyComparator;
        this.nodeComparator = nodeComparator;
        this.keySizeInBytes = keySizeInBytes;
    }

    /**
     * Gets the degree of the tree.
     */
    @Override
    public int getDegree() {
        return this.degree;
    }

    /**
     * Gets the class type of a key.
     */
    @Override
    public Class<TKey> getKeyClassType() {
        return this.keyClassType;
    }

    /**
     * Gets a key comparator.
     */
    @Override
    public IBinaryComparator<TKey> getKeyComparator() {
        return this.keyComparator;
    }

    /**
     * Gets a node comparator.
     */
    @Override
    public IBinaryComparator<IBPlusTreeNode<TKey>> getNodeComparator() {
        return this.nodeComparator;
    }

    /**
     * Gets the size of a key in bytes.
     */
    @Override
    public int getKeySizeInBytes() {
        return this.keySizeInBytes;
    }
}
