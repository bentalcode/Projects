package datastructures.bplustree.interfaces;

/**
 * The IBPlusTreeLeafNodeProperties interface defines properties of a leaf node of a B+ tree.
 */
public interface IBPlusTreeLeafNodeProperties<TKey extends Comparable<TKey>, TValue> extends IBPlusTreeNodeProperties<TKey> {

    /**
     * Gets the class type of a value.
     */
    Class<TValue> getValueClassType();

    /**
     * Gets the size of a value in bytes.
     */
    int getValueSizeInBytes();
}
