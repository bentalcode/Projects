package problems.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.interfaces.IBinaryComparator;
import problems.interfaces.ISparseSimilarityResult;

/**
 * The SparseSimilarityResult class implements a result of a sparse similarity.
 */
public final class SparseSimilarityResult implements ISparseSimilarityResult {
    private final int collectionId1;
    private final int collectionId2;
    private int intersectionSize;
    private int unionSize;
    private double sparseSimilarity;
    private final IBinaryComparator<ISparseSimilarityResult> comparator = defaultComparator();

    /**
     * The SparseSimilarityResult constructor.
     */
    public SparseSimilarityResult(
        int collectionId1,
        int collectionId2) {

        this.collectionId1 = collectionId1;
        this.collectionId2 = collectionId2;
    }

    /**
     * The SparseSimilarityResult constructor.
     */
    public SparseSimilarityResult(
        int collectionId1,
        int collectionId2,
        int intersectionSize,
        int unionSize,
        double sparseSimilarity) {

        this.collectionId1 = collectionId1;
        this.collectionId2 = collectionId2;
        this.intersectionSize = intersectionSize;
        this.unionSize = unionSize;
        this.sparseSimilarity = sparseSimilarity;
    }

    /**
     * Gets an id of collection1.
     */
    @Override
    public int getCollectionId1() {
        return this.collectionId1;
    }

    /**
     * Gets an id of collection2.
     */
    @Override
    public int getCollectionId2() {
        return this.collectionId2;
    }

    /**
     * Gets an intersection size.
     */
    @Override
    public int getIntersectionSize() {
        return this.intersectionSize;
    }

    /**
     * Sets an intersection size.
     */
    @Override
    public void setIntersectionSize(int size) {
        this.intersectionSize = size;
    }

    /**
     * Gets a union size.
     */
    @Override
    public int getUnionSize() {
        return this.unionSize;
    }

    /**
     * Sets a union size.
     */
    @Override
    public void setUnionSize(int size) {
        this.unionSize = size;
    }

    /**
     * Gets a sparse similarity.
     */
    @Override
    public double getSparseSimilarity() {
        return this.sparseSimilarity;
    }

    /**
     * Sets a sparse similarity.
     */
    @Override
    public void setSparseSimilarity(double sparseSimilarity) {
        this.sparseSimilarity = sparseSimilarity;
    }

    /**
     * Gets the hash code.
     */
    @Override
    public int hashCode() {
        return this.comparator.getHashCode(this);
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
    @Override
    public boolean isEqual(ISparseSimilarityResult other) {
        return this.comparator.isEqual(this, other);
    }

    /**
     * Determines the relative order of two instances.
     *
     * Returns -1 if the left hand side value is less than the right hand side value.
     * Returns 0 if the left hand side value is equal to the right hand side value.
     * Returns 1 if the left hand side value is greater than the right hand side value.
     */
    @Override
    public int compareTo(ISparseSimilarityResult other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <T extends Comparable<T>> IBinaryComparator<ISparseSimilarityResult> defaultComparator() {
        return new SparseSimilarityResult.Comparator();
    }

    /**
     * The Comparator class implements a comparator of a sparse similarity result.
     */
    public static final class Comparator extends AbstractBinaryComparator<ISparseSimilarityResult> {
        /**
         * The Comparator constructor.
         */
        public Comparator() {
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ISparseSimilarityResult obj) {
            return new HashCodeBuilder(19, 23)
                .withInteger(obj.getCollectionId1())
                .withInteger(obj.getCollectionId2())
                .withInteger(obj.getIntersectionSize())
                .withInteger(obj.getUnionSize())
                .withDouble(obj.getSparseSimilarity())
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ISparseSimilarityResult lhs, ISparseSimilarityResult rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withInteger(lhs.getCollectionId1(), rhs.getCollectionId1())
                .withInteger(lhs.getCollectionId2(), rhs.getCollectionId2())
                .withInteger(lhs.getIntersectionSize(), rhs.getIntersectionSize())
                .withInteger(lhs.getUnionSize(), rhs.getUnionSize())
                .withAlmostDouble(lhs.getSparseSimilarity(), rhs.getSparseSimilarity())
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
        public int compareTo(ISparseSimilarityResult lhs, ISparseSimilarityResult rhs) {
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
                .withInteger(lhs.getCollectionId1(), rhs.getCollectionId1())
                .withInteger(lhs.getCollectionId2(), rhs.getCollectionId2())
                .withInteger(lhs.getIntersectionSize(), rhs.getIntersectionSize())
                .withInteger(lhs.getUnionSize(), rhs.getUnionSize())
                .withAlmostDouble(lhs.getSparseSimilarity(), rhs.getSparseSimilarity())
                .build();
        }
    }
}
