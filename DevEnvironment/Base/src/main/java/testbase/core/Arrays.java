package testbase.core;

import java.lang.reflect.Array;

/**
 * The Arrays class implements complementary APIs for arrays.
 */
public final class Arrays {
    /**
     * Creates a new instance of an array.
     */
    public static <T> T[] newInstance(Class<?> classType, int size) {
        Conditions.validateNotNull(
            classType,
            "The class type for creating an array.");

        Conditions.validate(
            size > 0,
            "The size of an array for creating has to be positive.");

        Object objectArray = Array.newInstance(classType, size);
        T[] result = Casting.cast(objectArray);

        return result;
    }

    /**
     * Swaps values of two elements in an array.
     */
    public static <T> void swap(T[] arr, int lhsIndex, int rhsIndex) {
        Arrays.validateIndex(arr, lhsIndex);
        Arrays.validateIndex(arr, rhsIndex);

        T temp = arr[lhsIndex];
        arr[lhsIndex] = arr[rhsIndex];
        arr[rhsIndex] = temp;
    }

    /**
     * Swaps the values of two elements in arrays.
     */
    public static <T> void swap(T[] lhs, T[] rhs, int lhsIndex, int rhsIndex) {
        Arrays.validateIndex(lhs, lhsIndex);
        Arrays.validateIndex(rhs, rhsIndex);

        T temp = lhs[lhsIndex];
        lhs[lhsIndex] = rhs[rhsIndex];
        rhs[rhsIndex] = temp;
    }

    /**
     * Validates an index of an array.
     */
    public static <T> void validateIndex(T[] array, int index) {
        Arrays.validateIndex(array, 0, array.length - 1, index);
    }

    /**
     * Validates an index of an array.
     */
    public static <T> void validateIndex(T[] array, int startIndex, int endIndex, int index) {
        Conditions.validateNotNull(
            array,
            "The array.");

        Conditions.validate(
            index >= startIndex && index <= endIndex,
            "The index of an array is out of bound." +
            "Array Indexes: [" + startIndex + "-" + endIndex  + "], Used Index=" + index);
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Arrays() {
    }
}
