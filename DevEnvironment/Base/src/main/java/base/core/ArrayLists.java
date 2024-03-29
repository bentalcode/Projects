package base.core;

import java.util.ArrayList;
import java.util.List;

/**
 * The ArrayLists class implements a factory for creating array lists.
 */
public final class ArrayLists {
    /**
     * Creates a new instance of an empty list.
     */
    public static <T> List<T> make() {
        return new ArrayList<>();
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(T value) {
        List<T> list = new ArrayList<>();
        list.add(value);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7,
        T value8) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);
        list.add(value8);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7,
        T value8,
        T value9) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);
        list.add(value8);
        list.add(value9);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7,
        T value8,
        T value9,
        T value10) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);
        list.add(value8);
        list.add(value9);
        list.add(value10);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7,
        T value8,
        T value9,
        T value10,
        T value11) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);
        list.add(value8);
        list.add(value9);
        list.add(value10);
        list.add(value11);

        return list;
    }

    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(
        T value1,
        T value2,
        T value3,
        T value4,
        T value5,
        T value6,
        T value7,
        T value8,
        T value9,
        T value10,
        T value11,
        T value12) {

        List<T> list = new ArrayList<>();

        list.add(value1);
        list.add(value2);
        list.add(value3);
        list.add(value4);
        list.add(value5);
        list.add(value6);
        list.add(value7);
        list.add(value8);
        list.add(value9);
        list.add(value10);
        list.add(value11);
        list.add(value12);

        return list;
    }



    /**
     * Creates a new instance of a list.
     */
    public static <T> List<T> make(T[] values) {
        return new ArrayList<>(java.util.Arrays.asList(values));
    }

    /**
     * Creates a new instance of a list.
     */
    public static List<Integer> make(int[] values) {
        List<Integer> list = new ArrayList<>(values.length);

        for (int value : values) {
            list.add(value);
        }

        return list;
    }

    /**
     * The ArrayLists constructor - Disables the default constructor.
     */
    private ArrayLists() {
    }
}
