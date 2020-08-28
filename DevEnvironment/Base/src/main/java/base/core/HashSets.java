package base.core;

import java.util.HashSet;
import java.util.List;

/**
 * The HashSets class implements a factory for creating hash-sets.
 */
public final class HashSets {
    /**
     * Creates a new instance of hash-set.
     */
    public static <TKey> HashSet<TKey> make() {
        return new HashSet<>();
    }

    /**
     * Creates a new instance of a hash-set from a list.
     */
    public static <TKey> HashSet<TKey> from(List<TKey> list) {
        Conditions.validateNotNull(
            list,
            "The list.");

        return new HashSet<>(list);
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(TKey key) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);
        set.add(key5);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);
        set.add(key5);
        set.add(key6);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);
        set.add(key5);
        set.add(key6);
        set.add(key7);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);
        set.add(key5);
        set.add(key6);
        set.add(key7);
        set.add(key8);

        return set;
    }

    /**
     * Creates a new instance of a hash-set.
     */
    public static <TKey> HashSet<TKey> make(
        TKey key1,
        TKey key2,
        TKey key3,
        TKey key4,
        TKey key5,
        TKey key6,
        TKey key7,
        TKey key8,
        TKey key9) {

        HashSet<TKey> set = new HashSet<>();
        set.add(key1);
        set.add(key2);
        set.add(key3);
        set.add(key4);
        set.add(key5);
        set.add(key6);
        set.add(key7);
        set.add(key8);
        set.add(key9);

        return set;
    }

    /**
     * The HashSets constructor - Disables the default constructor.
     */
    private HashSets() {
    }
}
