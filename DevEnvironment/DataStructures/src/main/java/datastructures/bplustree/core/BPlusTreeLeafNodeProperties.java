package datastructures.bplustree.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNodeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeNode;

/**
 * The BPlusTreeLeafNodeProperties class implements the properties of a node of a B+ Tree.
 */
public final class BPlusTreeLeafNodeProperties<TKey extends Comparable<TKey>, TValue>
    extends BPlusTreeNodeProperties<TKey> implements IBPlusTreeLeafNodeProperties<TKey, TValue> {

    private final Class<TValue> valueClassType;
    private final int valueSizeInBytes;

    /**
     * The BPlusTreeLeafNodeProperties constructor.
     */
    public BPlusTreeLeafNodeProperties(
        int degree,
        Class<TKey> keyClassType,
        Class<TValue> valueClassType,
        IBinaryComparator<TKey> keyComparator,
        IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator,
        int keySizeInBytes,
        int valueSizeInBytes) {

        super(
            degree,
            keyClassType,
            keyComparator,
            nodeComparator,
            keySizeInBytes);

        Conditions.validateNotNull(
            valueClassType,
            "The class type of a node of a B+ tree.");

        Conditions.validate(
            valueSizeInBytes >= 0,
            "The size of bytes of a value have to be positive.");

        this.valueClassType = valueClassType;
        this.valueSizeInBytes = valueSizeInBytes;
    }

    /**
     * Gets the class type of value.
     */
    @Override
    public Class<TValue> getValueClassType() {
        return this.valueClassType;
    }

    /**
     * Gets the size of a key in bytes.
     */
    @Override
    public int getValueSizeInBytes() {
        return this.valueSizeInBytes;
    }
}
