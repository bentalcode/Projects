package base.core;

import java.util.List;
import java.util.TreeSet;

/**
 * The TreeSets class implements a factory for creating tree-sets.
 */
public final class TreeSets {
    /**
     * Creates a new instance of tree-set.
     */
    public static <TKey> TreeSet<TKey> newSet() {
        return new TreeSet<>();
    }

    /**
     * Creates a new instance of a tree-set from a list.
     */
    public static <TKey> TreeSet<TKey> from(List<TKey> list) {
        Conditions.validateNotNull(
            list,
            "The list.");

        return new TreeSet<>(list);
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(TKey[] keys) {
        TreeSet<TKey> tree = new TreeSet<>();

        if (keys == null) {
            return tree;
        }

        for (TKey key : keys) {
            tree.add(key);
        }

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(TKey key) {
        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);
        tree.add(key5);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);
        tree.add(key5);
        tree.add(key6);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);
        tree.add(key5);
        tree.add(key6);
        tree.add(key7);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);
        tree.add(key5);
        tree.add(key6);
        tree.add(key7);
        tree.add(key8);

        return tree;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> of(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8,
        TKey key9) {

        TreeSet<TKey> tree = new TreeSet<>();
        tree.add(key1);
        tree.add(key2);
        tree.add(key3);
        tree.add(key4);
        tree.add(key5);
        tree.add(key6);
        tree.add(key7);
        tree.add(key8);
        tree.add(key9);

        return tree;
    }

    /**
     * The TreeSets constructor - Disables the default constructor.
     */
    private TreeSets() {
    }
}
