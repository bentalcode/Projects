package testbase.core;

import java.util.LinkedHashMap;

/**
 * The LinkedHashMaps class implements a factory for creating linked hash-maps.
 */
public final class LinkedHashMaps {
    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(TKey key, TValue value) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key, value);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4,
        TKey key5, TValue value5) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);
        map.put(key5, value5);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4,
        TKey key5, TValue value5,
        TKey key6, TValue value6) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);
        map.put(key5, value5);
        map.put(key6, value6);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4,
        TKey key5, TValue value5,
        TKey key6, TValue value6,
        TKey key7, TValue value7) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);
        map.put(key5, value5);
        map.put(key6, value6);
        map.put(key7, value7);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4,
        TKey key5, TValue value5,
        TKey key6, TValue value6,
        TKey key7, TValue value7,
        TKey key8, TValue value8) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);
        map.put(key5, value5);
        map.put(key6, value6);
        map.put(key7, value7);
        map.put(key8, value8);

        return map;
    }

    /**
     * Creates a new instance of a linked hash-map.
     */
    public static <TKey, TValue> LinkedHashMap<TKey, TValue> of(
        TKey key1, TValue value1,
        TKey key2, TValue value2,
        TKey key3, TValue value3,
        TKey key4, TValue value4,
        TKey key5, TValue value5,
        TKey key6, TValue value6,
        TKey key7, TValue value7,
        TKey key8, TValue value8,
        TKey key9, TValue value9) {

        LinkedHashMap<TKey, TValue> map = new LinkedHashMap<>();
        map.put(key1, value1);
        map.put(key2, value2);
        map.put(key3, value3);
        map.put(key4, value4);
        map.put(key5, value5);
        map.put(key6, value6);
        map.put(key7, value7);
        map.put(key8, value8);
        map.put(key9, value9);

        return map;
    }

    /**
     * The LinkedHashMaps constructor - Disables the default constructor.
     */
    private LinkedHashMaps() {
    }
}
