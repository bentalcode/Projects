package base.core;

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
     * Copies an instance of an array.
     */
    public static <T> T[] copy(
        T[] arr,
        Class<T> classType,
        int startIndex,
        int endIndex) {

        Arrays.validateArray(arr);
        Arrays.validateRange(arr, startIndex, endIndex);

        int length = endIndex - startIndex + 1;
        T[] result = Arrays.newInstance(classType, length);

        int insertIndex = 0;

        for (int i = startIndex; i <= endIndex; ++i) {
            result[insertIndex] = arr[i];
            ++insertIndex;
        }

        return result;
    }

    /**
     * Copies a range from a source array to a destination array.
     */
    public static <T> void copy(
        T[] sourceArray,
        int sourceStartIndex,
        int sourceEndIndex,
        T[] destinationArray,
        int destinationStartIndex,
        int destinationEndIndex) {

        Arrays.validateArray(sourceArray);
        Arrays.validateArray(destinationArray);
        Arrays.validateRange(sourceArray, sourceStartIndex, sourceEndIndex);
        Arrays.validateRange(destinationArray, destinationStartIndex, destinationEndIndex);

        int sourceSize = sourceEndIndex - sourceStartIndex + 1;
        int destinationSize = destinationEndIndex - destinationStartIndex + 1;

        Conditions.validate(
            sourceSize == destinationSize,
            "The range of the destination array is not matching the corresponding of the source array.");

        int sourceIndex = sourceStartIndex;
        int destinationIndex = destinationStartIndex;

        while (sourceIndex <= sourceEndIndex && destinationIndex <= destinationEndIndex) {
            destinationArray[destinationIndex] = sourceArray[sourceIndex];

            ++sourceIndex;
            ++destinationIndex;
        }
    }

    /**
     * Swaps values of two elements in an array.
     */
    public static <T> void swap(T[] arr, int lhsIndex, int rhsIndex) {
        Arrays.validateArray(arr);
        Arrays.validateIndex(arr, lhsIndex);
        Arrays.validateIndex(arr, rhsIndex);

        T temp = arr[lhsIndex];
        arr[lhsIndex] = arr[rhsIndex];
        arr[rhsIndex] = temp;
    }

    /**
     * Validates an index of an array.
     */
    public static <T> void validateIndex(T[] array, int index) {
        Arrays.validateArrayIndex(index, 0, array.length - 1);
    }

    /**
     * Validates an index of an array.
     */
    public static void validateIndex(int index, int startIndex, int endIndex) {
        Arrays.validateArrayIndex(index, startIndex, endIndex);
    }

    /**
     * Validates a range of an array.
     */
    public static <T> void validateRange(T[] array, int startIndex, int endIndex) {
        Arrays.validateIndex(array, startIndex);
        Arrays.validateIndex(array, endIndex);

        Conditions.validate(
            startIndex <= endIndex,
            "The end index has to be equal or larger than the start index.");
    }

    /**
     * Validates an array.
     */
    private static <T> void validateArray(T[] array) {
        Conditions.validateNotNull(
            array,
            "The array.");
    }

    /**
     * Validates an index of an array.
     */
    private static void validateArrayIndex(int index, int startIndex, int endIndex) {
        Conditions.validate(
            index >= startIndex && index <= endIndex,
            "The index of an array is out of bound." +
            "Index = " + index + " , Range = " + Range.of(startIndex, endIndex));
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Arrays() {
    }
}
