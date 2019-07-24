package datastructures.bplustree.core;

import base.core.Conditions;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.bplustree.interfaces.IBPlusTreeInnerNodeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeLeafNodeProperties;
import datastructures.bplustree.interfaces.IBPlusTreeNode;
import datastructures.bplustree.interfaces.IBPlusTreeProperties;

/**
 * The BPlusTreeProperties class implements properties of a B+ Tree.
 */
public final class BPlusTreeProperties<TKey extends Comparable<TKey>, TValue> implements IBPlusTreeProperties<TKey, TValue> {

    private final int degree;
    private final IBPlusTreeInnerNodeProperties<TKey> innerNodeProperties;
    private final IBPlusTreeLeafNodeProperties<TKey, TValue> leafNodeProperties;
    private final IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator;
    /**
     * The BPlusTreeProperties constructor.
     */
    private BPlusTreeProperties(
        int degree,
        Class<TKey> keyClassType,
        Class<TValue> valueClassType,
        IBinaryComparator<TKey> keyComparator,
        IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator,
        int keySizeInBytes,
        int valueSizeInBytes) {

        this(
            degree,
            nodeComparator,
            new BPlusTreeInnerNodeProperties<>(
                degree,
                keyClassType,
                keyComparator,
                nodeComparator,
                keySizeInBytes),
            new BPlusTreeLeafNodeProperties<>(
                degree,
                keyClassType,
                valueClassType,
                keyComparator,
                nodeComparator,
                keySizeInBytes,
                valueSizeInBytes));
    }

    /**
     * The BPlusTreeProperties constructor.
     */
    private BPlusTreeProperties(
        int degree,
        IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator,
        IBPlusTreeInnerNodeProperties<TKey> innerNodeProperties,
        IBPlusTreeLeafNodeProperties<TKey, TValue> leafNodeProperties) {

        Conditions.validate(
            degree >= 3,
            "The minimum degree of a B+ tree has is 3.");

        Conditions.validateNotNull(
            nodeComparator,
            "The comparator of a node of a B+ tree.");

        Conditions.validateNotNull(
            innerNodeProperties,
            "The properties of an inner node of a B+ tree.");

        Conditions.validateNotNull(
            leafNodeProperties,
            "The properties of a leaf node of a B+ tree.");

        this.degree = degree;
        this.nodeComparator = nodeComparator;
        this.innerNodeProperties = innerNodeProperties;
        this.leafNodeProperties = leafNodeProperties;
    }

    /**
     * Gets the degree of the tree.
     */
    @Override
    public int getDegree() {
        return this.degree;
    }

    /**
     * Gets a node comparator.
     */
    @Override
    public IBinaryComparator<IBPlusTreeNode<TKey>> getNodeComparator() {
        return this.nodeComparator;
    }

    /**
     * Gets the properties of an inner node.
     */
    @Override
    public IBPlusTreeInnerNodeProperties<TKey> getInnerNodeProperties() {
        return this.innerNodeProperties;
    }

    /**
     * Gets the properties of a leaf node.
     */
    @Override
    public IBPlusTreeLeafNodeProperties<TKey, TValue> getLeafNodeProperties() {
        return this.leafNodeProperties;
    }

    /**
     * The Builder class implements a builder for creating properties of a B+ tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue>
        implements IBuilder<IBPlusTreeProperties<TKey, TValue>> {

        private int degree = 4;
        private Class<TKey> keyClassType;
        private Class<TValue> valueClassType;
        private IBinaryComparator<TKey> keyComparator;
        private IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator;
        private int sizeOfKeyInBytes;
        private int sizeOfValueInBytes;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets a degree of the tree.
         */
        public Builder<TKey, TValue> withDegree(int degree) {
            this.degree = degree;
            return this;
        }

        /**
         * Sets a class type of a key of the tree.
         */
        public Builder<TKey, TValue> withKeyClassType(Class<TKey> keyClassType) {
            this.keyClassType = keyClassType;
            return this;
        }

        /**
         * Sets a class type of a value of the tree.
         */
        public Builder<TKey, TValue> withValueClassType(Class<TValue> valueClassType) {
            this.valueClassType = valueClassType;
            return this;
        }

        /**
         * Sets a comparator of a key of the tree.
         */
        public Builder<TKey, TValue> withKeyComparator(IBinaryComparator<TKey> keyComparator) {
            this.keyComparator = keyComparator;
            return this;
        }

        /**
         * Sets a comparator of a node of the tree.
         */
        public Builder<TKey, TValue> withNodeComparator(IBinaryComparator<IBPlusTreeNode<TKey>> nodeComparator) {
            this.nodeComparator = nodeComparator;
            return this;
        }

        /**
         * Sets a size of a key in bytes.
         */
        public Builder<TKey, TValue> withKeySizeInBytes(int size) {
            this.sizeOfKeyInBytes = size;
            return this;
        }

        /**
         * Sets a size of a value in bytes.
         */
        public Builder<TKey, TValue> withValueSizeInBytes(int size) {
            this.sizeOfValueInBytes = size;
            return this;
        }

        /**
         * Builds properties of a B+ tree.
         */
        @Override
        public IBPlusTreeProperties<TKey, TValue> build() {
            IBPlusTreeProperties<TKey, TValue> properties = new BPlusTreeProperties<>(
                this.degree,
                this.keyClassType,
                this.valueClassType,
                this.keyComparator,
                this.nodeComparator,
                this.sizeOfKeyInBytes,
                this.sizeOfValueInBytes);

            return properties;
        }
    }
}
