package datastructures.blocktree.core;

import base.core.AbstractBinaryComparator;
import base.core.Casting;
import base.core.CompareToBuilder;
import base.core.Conditions;
import base.core.EqualBuilder;
import base.core.HashCodeBuilder;
import base.core.ListIterator;
import base.core.ListReverseIterator;
import base.interfaces.IBinaryComparator;
import base.interfaces.IBuilder;
import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import datastructures.blocktree.interfaces.IBlockTreeLevel;
import datastructures.blocktree.interfaces.IBlockTreeLevels;
import java.util.ArrayList;
import java.util.List;

/**
 * The BlockTreeLevels class implements levels of a block tree.
 */
public final class BlockTreeLevels<TKey extends Comparable<TKey>, TValue> implements IBlockTreeLevels<TKey, TValue> {
    private final List<IBlockTreeLevel<TKey, TValue>> levels;
    private final IBinaryComparator<IBlockTreeLevels<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The BlockTreeLevels constructor.
     */
    public BlockTreeLevels(List<IBlockTreeLevel<TKey, TValue>> levels) {
        this(
            levels,
            BlockTreeLevels.defaultComparator());
    }

    /**
     * The BlockTreeLevels constructor.
     */
    private BlockTreeLevels(
        List<IBlockTreeLevel<TKey, TValue>> levels,
        IBinaryComparator<IBlockTreeLevels<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            levels,
            "The levels of a block tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a block tree.");

        this.levels = levels;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the levels of a block tree.
     */
    @Override
    public List<IBlockTreeLevel<TKey, TValue>> getLevels() {
        return this.levels;
    }

    /**
     * Gets the iterator of levels of a block tree.
     */
    @Override
    public IIterator<IBlockTreeLevel<TKey, TValue>> getIterator() {
        return ListIterator.make(this.levels);
    }

    /**
     * Gets the reverse iterator of levels of a block tree.
     */
    @Override
    public IReverseIterator<IBlockTreeLevel<TKey, TValue>> getReverseIterator() {
        return ListReverseIterator.make(this.levels);
    }

    /**
     * Gets the size of the levels of a block tree.
     */
    @Override
    public int size() {
        return this.levels.size();
    }

    /**
     * Checks whether the levels a block tree are empty.
     */
    @Override
    public boolean empty() {
        return this.size() == 0;
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
    @Override
    public boolean isEqual(IBlockTreeLevels<TKey, TValue> other) {
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
    public int compareTo(IBlockTreeLevels<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<IBlockTreeLevels<TKey, TValue>> defaultComparator() {
        IBinaryComparator<IBlockTreeLevel<TKey, TValue>> levelComparator = BlockTreeLevel.defaultComparator();
        return new Comparator<>(levelComparator);
    }

    /**
     * The Comparator class implements a comparator of levels of a block tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<IBlockTreeLevels<TKey, TValue>> {

        private final IBinaryComparator<IBlockTreeLevel<TKey, TValue>> levelComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<IBlockTreeLevel<TKey, TValue>> levelComparator) {
            Conditions.validateNotNull(
                levelComparator,
                "The level comparator of a block tree.");

            this.levelComparator = levelComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(IBlockTreeLevels<TKey, TValue> obj) {
            return new HashCodeBuilder(317, 331)
                .withCollection(obj.getLevels(), this.levelComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(IBlockTreeLevels<TKey, TValue> lhs, IBlockTreeLevels<TKey, TValue> rhs) {
            if (lhs == null && rhs == null) {
                return true;
            }

            if (lhs == null || rhs == null) {
                return false;
            }

            return new EqualBuilder()
                .withCollection(lhs.getLevels(), rhs.getLevels(), this.levelComparator)
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
        public int compareTo(IBlockTreeLevels<TKey, TValue> lhs, IBlockTreeLevels<TKey, TValue> rhs) {
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
                .withCollection(lhs.getLevels(), rhs.getLevels(), this.levelComparator)
                .build();
        }
    }

    /**
     * The Builder class implements a builder for creating levels of a block tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<IBlockTreeLevels<TKey, TValue>> {
        private final List<IBlockTreeLevel<TKey, TValue>> levels = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new tree level.
         */
        public Builder<TKey, TValue> addLevel(IBlockTreeLevel<TKey, TValue> level) {
            Conditions.validateNotNull(
                level,
                "The level of a block tree.");

            this.levels.add(level);

            return this;
        }

        /**
         * Adds a new tree level by keys.
         */
        public Builder<TKey, TValue> addLevelByKeys(List<List<TKey>> nodesKeys) {
            Conditions.validateNotNull(
                nodesKeys,
                "The keys of nodes of a block tree.");

            BlockTreeLevel.Builder<TKey, TValue> levelBuilder = new BlockTreeLevel.Builder<>();

            for (List<TKey> nodeKeys : nodesKeys) {
                levelBuilder.addNode(nodeKeys);
            }

            IBlockTreeLevel<TKey, TValue> level = levelBuilder.build();

            return this.addLevel(level);
        }

        /**
         * Builds the levels of a tree.
         */
        @Override
        public IBlockTreeLevels<TKey, TValue> build() {
            IBlockTreeLevels<TKey, TValue> levels = new BlockTreeLevels<>(
                this.levels,
                BlockTreeLevels.defaultComparator());

            return levels;
        }
    }
}
