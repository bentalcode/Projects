package datastructures.bplustree.core;

import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import datastructures.bplustree.interfaces.IBPlusTreeMetrics;
import java.math.BigInteger;

/**
 * The BPlusTreeMetrics class implements metrics of a tree.
 */
public final class BPlusTreeMetrics implements IBPlusTreeMetrics {
    private final int height;
    private final int numberOfNodes;
    private final int numberOfInnerNodes;
    private final int numberOfLeafNodes;
    private final BigInteger sizeInBytes;
    private final BigInteger capacityInBytes;
    private final IBinaryComparator<IBPlusTreeMetrics> comparator;
    private final int hashCode;

    /**
     * The BPlusTreeMetrics constructor.
     */
    public BPlusTreeMetrics(
        int height,
        int numberOfNodes,
        int numberOfInnerNodes,
        int numberOfLeafNodes,
        BigInteger sizeInBytes,
        BigInteger capacityInBytes) {

        this(
            height,
            numberOfNodes,
            numberOfInnerNodes,
            numberOfLeafNodes,
            sizeInBytes,
            capacityInBytes,
            BPlusTreeMetrics.DefaultComparator());
    }

    /**
     * The BPlusTreeMetrics constructor.
     */
    public BPlusTreeMetrics(
        int height,
        int numberOfNodes,
        int numberOfInnerNodes,
        int numberOfLeafNodes,
        BigInteger sizeInBytes,
        BigInteger capacityInBytes,
        IBinaryComparator<IBPlusTreeMetrics> comparator) {

        Conditions.validateNotNull(
            sizeInBytes,
            "The size in bytes.");

        Conditions.validateNotNull(
            capacityInBytes,
            "The capacity in bytes.");

        Conditions.validateNotNull(
            capacityInBytes,
            "The comparator of metrics.");

        this.height = height;
        this.numberOfNodes = numberOfNodes;
        this.numberOfInnerNodes = numberOfInnerNodes;
        this.numberOfLeafNodes = numberOfLeafNodes;
        this.sizeInBytes = sizeInBytes;
        this.capacityInBytes = capacityInBytes;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
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
    public BigInteger getSizeInBytes() {
        return this.sizeInBytes;
    }

    /**
     * Gets the capacity in bytes of a B+ tree.
     */
    @Override
    public BigInteger getCapacityInBytes() {
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
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    public int compareTo(IBPlusTreeMetrics other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Calculates the hash code.
     */
    private int calculateHashCode() {
        return this.hashCode;
    }

    /**
     * Gets the default comparator.
     */
    public static IBinaryComparator<IBPlusTreeMetrics> DefaultComparator() {
        return new Comparator();
    }

    /**
     * The Comparator class implements a comparator of metrics of a B+ tree.
     */
    public static final class Comparator implements IBinaryComparator<IBPlusTreeMetrics> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBPlusTreeMetrics metrics) {
            return new HashCodeBuilder(3, 5)
                .withInteger(metrics.getHeight())
                .withInteger(metrics.getNumberOfNodes())
                .withInteger(metrics.getNumberOfInnerNodes())
                .withInteger(metrics.getNumberOfLeafNodes())
                .withBigInteger(metrics.getSizeInBytes())
                .withBigInteger(metrics.getCapacityInBytes())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        public boolean isEqual(IBPlusTreeMetrics lhs, IBPlusTreeMetrics rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withInteger(lhs.getHeight(), rhs.getHeight())
                .withInteger(lhs.getNumberOfNodes(), rhs.getNumberOfNodes())
                .withInteger(lhs.getNumberOfInnerNodes(), rhs.getNumberOfInnerNodes())
                .withInteger(lhs.getNumberOfLeafNodes(), rhs.getNumberOfLeafNodes())
                .withBigInteger(lhs.getSizeInBytes(), rhs.getSizeInBytes())
                .withBigInteger(lhs.getCapacityInBytes(), rhs.getCapacityInBytes())
                .build();
        }

        /**
         * Determines the relative order of two instances.
         *
         * Returns -1 if the left hand side value is less than the right hand side value.
         * Returns 0 if the left hand side value is equal to the right hand side value.
         * Returns 1 if the left hand side value is greater than the right hand side value.
         */
        @Override
        public int compareTo(IBPlusTreeMetrics lhs, IBPlusTreeMetrics rhs) {
            if (lhs == null && rhs == null) {
                return 0;
            }

            if (lhs == null) {
                return -1;
            }

            if (rhs == null) {
                return 1;
            }

            return new CompareToBuilder()
                .withInteger(lhs.getHeight(), rhs.getHeight())
                .withInteger(lhs.getNumberOfNodes(), rhs.getNumberOfNodes())
                .withInteger(lhs.getNumberOfInnerNodes(), rhs.getNumberOfInnerNodes())
                .withInteger(lhs.getNumberOfLeafNodes(), rhs.getNumberOfLeafNodes())
                .withBigInteger(lhs.getSizeInBytes(), rhs.getSizeInBytes())
                .withBigInteger(lhs.getCapacityInBytes(), rhs.getCapacityInBytes())
                .build();
        }
    }

    /**
     * The Builder class implements a builder for defining metrics of a B+ tree.
     */
    public static final class Builder implements IBuilder<IBPlusTreeMetrics> {
        private int height;
        private int numberOfNodes;
        private int numberOfInnerNodes;
        private int numberOfLeafNodes;
        private BigInteger sizeInBytes;
        private BigInteger capacityInBytes;

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
        public Builder withSizeInBytes(BigInteger size) {
            this.sizeInBytes = size;
            return this;
        }

        /**
         * Sets the capacity in bytes of a tree.
         */
        public Builder withCapacityInBytes(BigInteger size) {
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
