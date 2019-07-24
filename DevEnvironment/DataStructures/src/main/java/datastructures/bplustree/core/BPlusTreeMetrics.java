package datastructures.bplustree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBuilder;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;

/**
 * The BPlusTreeMetrics class implements metrics of a tree.
 */
public final class BPlusTreeMetrics implements IBPlusTreeMetrics {
    private final int height;
    private final int numberOfNodes;
    private final int numberOfInnerNodes;
    private final int numberOfLeafNodes;
    private final int sizeInBytes;
    private final int capacityInBytes;

    private final int hashCode;

    /**
     * The BPlusTreeMetrics constructor.
     */
    public BPlusTreeMetrics(
        int height,
        int numberOfNodes,
        int numberOfInnerNodes,
        int numberOfLeafNodes,
        int sizeInBytes,
        int capacityInBytes) {

        this.height = height;
        this.numberOfNodes = numberOfNodes;
        this.numberOfInnerNodes = numberOfInnerNodes;
        this.numberOfLeafNodes = numberOfLeafNodes;
        this.sizeInBytes = sizeInBytes;
        this.capacityInBytes = capacityInBytes;
        this.hashCode = this.calculateHashCode();
    }

    /**
     * Gets the height of a tree.
     */
    @Override
    public int getHeight() {
        return this.height;
    }

    /**
     * Gets the number of nodes of a B+ tree.
     */
    @Override
    public int getNumberOfNodes() {
        return this.numberOfNodes;
    }

    /**
     * Gets the number of inner nodes of a B+ tree.
     */
    @Override
    public int getNumberOfInnerNodes() {
        return this.numberOfInnerNodes;
    }

    /**
     * Gets the number of leaf nodes of a B+ tree.
     */
    @Override
    public int getNumberOfLeafNodes() {
        return this.numberOfLeafNodes;
    }

    /**
     * Gets the size in bytes of a B+ tree.
     */
    @Override
    public long getSizeInBytes() {
        return this.sizeInBytes;
    }

    /**
     * Gets the capacity in bytes of a B+ tree.
     */
    @Override
    public long getCapacityInBytes() {
        return this.capacityInBytes;
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.hashCode;
    }

    /**
     * Checks whether the instances are equals.
     */
    @Override
    public boolean equals(Object other) {
        if (other == null) {
            return false;
        }

        if (this == other) {
            return true;
        }

        if (!this.getClass().isInstance(other)) {
            return false;
        }

        return this.isEqual(Casting.cast(other));
    }

    /**
     * Checks whether the instances are equals.
     */
    public boolean isEqual(IBPlusTreeMetrics other) {
        return new EqualBuilder()
            .withInteger(this.getHeight(), other.getHeight())
            .withInteger(this.getNumberOfNodes(), other.getNumberOfNodes())
            .withInteger(this.getNumberOfInnerNodes(), other.getNumberOfInnerNodes())
            .withInteger(this.getNumberOfLeafNodes(), other.getNumberOfLeafNodes())
            .withLong(this.getSizeInBytes(), other.getSizeInBytes())
            .withLong(this.getCapacityInBytes(), other.getCapacityInBytes())
            .build();
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(IBPlusTreeMetrics other) {
        return new CompareToBuilder()
            .withInteger(this.getHeight(), other.getHeight())
            .withInteger(this.getNumberOfNodes(), other.getNumberOfNodes())
            .withInteger(this.getNumberOfInnerNodes(), other.getNumberOfInnerNodes())
            .withInteger(this.getNumberOfLeafNodes(), other.getNumberOfLeafNodes())
            .withLong(this.getSizeInBytes(), other.getSizeInBytes())
            .withLong(this.getCapacityInBytes(), other.getCapacityInBytes())
            .build();
    }

    /**
     * Calculates the hash code.
     */
    private int calculateHashCode() {
        return new HashCodeBuilder(3, 5)
            .withInteger(this.getHeight())
            .withInteger(this.getNumberOfNodes())
            .withInteger(this.getNumberOfInnerNodes())
            .withInteger(this.getNumberOfLeafNodes())
            .withLong(this.getSizeInBytes())
            .withLong(this.getCapacityInBytes())
            .build();
    }

    /**
     * The Builder class implements a builder for defining metrics of a B+ tree.
     */
    public static final class Builder implements IBuilder<IBPlusTreeMetrics> {
        private int height;
        private int numberOfNodes;
        private int numberOfInnerNodes;
        private int numberOfLeafNodes;
        private int sizeInBytes;
        private int capacityInBytes;

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Sets the height of a tree.
         */
        public Builder withHeight(int height) {
            this.height = height;
            return this;
        }

        /**
         * Sets the number of inner nodes of a tree.
         */
        public Builder withNumberOfNodes(int numberOfNodes) {
            this.numberOfNodes = numberOfNodes;
            return this;
        }

        /**
         * Sets the number of inner nodes of a tree.
         */
        public Builder withNumberOfInnerNodes(int numberOfNodes) {
            this.numberOfInnerNodes = numberOfNodes;
            return this;
        }

        /**
         * Sets the number of leaf nodes of a tree.
         */
        public Builder withNumberOfLeafNodes(int numberOfNodes) {
            this.numberOfLeafNodes = numberOfNodes;
            return this;
        }

        /**
         * Sets the size in bytes of a tree.
         */
        public Builder withSizeInBytes(int size) {
            this.sizeInBytes = size;
            return this;
        }

        /**
         * Sets the capacity in bytes of a tree.
         */
        public Builder withCapacityInBytes(int size) {
            this.capacityInBytes = size;
            return this;
        }

        /**
         * Builds the metrics of a tree.
         */
        @Override
        public IBPlusTreeMetrics build() {
            return new BPlusTreeMetrics(
                this.height,
                this.numberOfNodes,
                this.numberOfInnerNodes,
                this.numberOfLeafNodes,
                this.sizeInBytes,
                this.capacityInBytes);
        }
    }
}
