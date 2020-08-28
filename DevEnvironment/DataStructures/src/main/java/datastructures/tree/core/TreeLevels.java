package datastructures.tree.core;

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
import datastructures.tree.interfaces.ITreeLevel;
import datastructures.tree.interfaces.ITreeLevels;
import java.util.ArrayList;
import java.util.List;

/**
 * The TreeLevels class implements levels of a tree.
 */
public final class TreeLevels<TKey extends Comparable<TKey>, TValue> implements ITreeLevels<TKey, TValue> {
    private final List<ITreeLevel<TKey, TValue>> levels;
    private final IBinaryComparator<ITreeLevels<TKey, TValue>> comparator;
    private final int hashCode;

    /**
     * The TreeLevels constructor.
     */
    public TreeLevels(List<ITreeLevel<TKey, TValue>> levels) {
        this(
            levels,
            TreeLevels.defaultComparator());
    }

    /**
     * The TreeLevels constructor.
     */
    private TreeLevels(
        List<ITreeLevel<TKey, TValue>> levels,
        IBinaryComparator<ITreeLevels<TKey, TValue>> comparator) {

        Conditions.validateNotNull(
            levels,
            "The levels of a tree.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of a tree.");

        this.levels = levels;
        this.comparator = comparator;
        this.hashCode = comparator.getHashCode(this);
    }

    /**
     * Gets the levels of a tree.
     */
    @Override
    public List<ITreeLevel<TKey, TValue>> getLevels() {
        return this.levels;
    }

    /**
     * Gets the iterator of levels.
     */
    @Override
    public IIterator<ITreeLevel<TKey, TValue>> getIterator() {
        return ListIterator.make(this.levels);
    }

    /**
     * Gets the reverse iterator of levels.
     */
    @Override
    public IReverseIterator<ITreeLevel<TKey, TValue>> getReverseIterator() {
        return ListReverseIterator.make(this.levels);
    }

    /**
     * Gets the size of the levels.
     */
    @Override
    public int size() {
        return this.levels.size();
    }

    /**
     * Checks whether the levels are empty.
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
    public boolean isEqual(ITreeLevels<TKey, TValue> other) {
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
    public int compareTo(ITreeLevels<TKey, TValue> other) {
        return this.comparator.compareTo(this, other);
    }

    /**
     * Gets the default comparator.
     */
    public static <TKey extends Comparable<TKey>, TValue> IBinaryComparator<ITreeLevels<TKey, TValue>> defaultComparator() {
        IBinaryComparator<ITreeLevel<TKey, TValue>> levelComparator = TreeLevel.defaultComparator();
        return new Comparator<>(levelComparator);
    }

    /**
     * The Comparator class implements a comparator of levels of a tree.
     */
    public static final class Comparator<TKey extends Comparable<TKey>, TValue>
        extends AbstractBinaryComparator<ITreeLevels<TKey, TValue>> {

        private final IBinaryComparator<ITreeLevel<TKey, TValue>> levelComparator;

        /**
         * The Comparator constructor.
         */
        public Comparator(IBinaryComparator<ITreeLevel<TKey, TValue>> levelComparator) {
            Conditions.validateNotNull(
                levelComparator,
                "The level comparator of a tree.");

            this.levelComparator = levelComparator;
        }

        /**
         * Gets a hash code of this instance.
         */
        @Override
        public int getHashCode(ITreeLevels<TKey, TValue> obj) {
            return new HashCodeBuilder(701, 709)
                .withCollection(obj.getLevels(), this.levelComparator)
                .build();
        }

        /**
         * Checks whether two instances are equals.
         */
        @Override
        public boolean isEqual(ITreeLevels<TKey, TValue> lhs, ITreeLevels<TKey, TValue> rhs) {
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
        public int compareTo(ITreeLevels<TKey, TValue> lhs, ITreeLevels<TKey, TValue> rhs) {
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
     * The Builder class implements a builder for creating levels of a tree.
     */
    public static final class Builder<TKey extends Comparable<TKey>, TValue> implements IBuilder<ITreeLevels<TKey, TValue>> {
        private final List<ITreeLevel<TKey, TValue>> levels = new ArrayList<>();

        /**
         * The Builder constructor.
         */
        public Builder() {
        }

        /**
         * Adds a new tree level.
         */
        public Builder<TKey, TValue> addLevel(ITreeLevel<TKey, TValue> level) {
            Conditions.validateNotNull(
                level,
                "The level of a tree.");

            this.levels.add(level);

            return this;
        }

        /**
         * Adds a new tree level by keys.
         */
        public Builder<TKey, TValue> addLevelByKeys(List<TKey> nodesKeys) {
            Conditions.validateNotNull(
                nodesKeys,
                "The keys of nodes of a tree.");

            TreeLevel.Builder<TKey, TValue> levelBuilder = new TreeLevel.Builder<>();

            for (TKey nodeKey : nodesKeys) {
                levelBuilder.addNode(nodeKey);
            }

            ITreeLevel<TKey, TValue> level = levelBuilder.build();

            return this.addLevel(level);
        }

        /**
         * Builds the levels of a tree.
         */
        @Override
        public ITreeLevels<TKey, TValue> build() {
            ITreeLevels<TKey, TValue> levels = new TreeLevels<>(
                this.levels,
                TreeLevels.defaultComparator());

            return levels;
        }
    }
}
