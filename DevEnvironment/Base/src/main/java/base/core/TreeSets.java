package base.core;

import java.util.List;
import java.util.TreeSet;

/**
 * The TreeSets class implements a factory for creating tree-sets.
 */
public final class TreeSets {
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
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(TKey[] keys) {
        return new TreeSet<>(java.util.Arrays.asList(keys));
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(TKey key) {
        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
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
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        treeSet.add(key4);
        treeSet.add(key5);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        treeSet.add(key4);
        treeSet.add(key5);
        treeSet.add(key6);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        treeSet.add(key4);
        treeSet.add(key5);
        treeSet.add(key6);
        treeSet.add(key7);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        treeSet.add(key4);
        treeSet.add(key5);
        treeSet.add(key6);
        treeSet.add(key7);
        treeSet.add(key8);
        return treeSet;
    }

    /**
     * Creates a new instance of a tree-set.
     */
    public static <TKey extends Comparable<TKey>> TreeSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8,
        TKey key9) {

        TreeSet<TKey> treeSet = new TreeSet<>();
        treeSet.add(key1);
        treeSet.add(key2);
        treeSet.add(key3);
        treeSet.add(key4);
        treeSet.add(key5);
        treeSet.add(key6);
        treeSet.add(key7);
        treeSet.add(key8);
        treeSet.add(key9);
        return treeSet;
    }

    /**
     * The TreeSets constructor - Disables the default constructor.
     */
    private TreeSets() {
    }
}
