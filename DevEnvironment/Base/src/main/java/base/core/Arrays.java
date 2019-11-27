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
        Arrays.validateClassType(classType);

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
    public static <T, TClass extends T> T[] copy(
        T[] array,
        Class<TClass> classType) {

        Arrays.validateArray(array);

        int startIndex = 0;
        int endIndex = array.length - 1;

        return Arrays.copy(
            array,
            classType,
            startIndex,
            endIndex);
    }

    /**
     * Copies an instance of an array.
     */
    public static <T> T[] copy(
        T[] arr,
        Class<?> classType,
        int startIndex,
        int endIndex) {

        Arrays.validateArray(arr);
        Arrays.validateClassType(classType);
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
        T[] destinationArray,
        int destinationStartIndex,
        int size) {

        Conditions.validate(
            size > 0,
            "The number of elements to copy has to be positive.");

        Arrays.validateArray(sourceArray);
        int sourceEndIndex = sourceStartIndex + size - 1;
        Arrays.validateRange(sourceArray, sourceStartIndex, sourceEndIndex);

        Arrays.validateArray(destinationArray);
        int destinationEndIndex = destinationStartIndex + size - 1;
        Arrays.validateRange(destinationArray, destinationStartIndex, destinationEndIndex);

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
    public static <T> void swap(T[] array, int leftIndex, int rightIndex) {
        Arrays.validateArray(array);
        Arrays.validateIndex(array, leftIndex);
        Arrays.validateIndex(array, rightIndex);

        T temp = array[leftIndex];
        array[leftIndex] = array[rightIndex];
        array[rightIndex] = temp;
    }

    /**
     * Swaps values of two elements in an array.
     */
    public static void swap(int[] array, int leftIndex, int rightIndex) {
        Conditions.validateNotNull(
            array,
            "The array.");

        Arrays.validateIndex(leftIndex, 0, array.length - 1);
        Arrays.validateIndex(rightIndex, 0, array.length - 1);

        int temp = array[leftIndex];
        array[leftIndex] = array[rightIndex];
        array[rightIndex] = temp;
    }

    /**
     * Validates an index of an array.
     */
    public static <T> void validateIndex(T[] array, int index) {
        Arrays.validateIndex(index, 0, array.length - 1);
    }

    /**
     * Validates an index of an array.
     */
    public static void validateIndex(int index, int startIndex, int endIndex) {
        Conditions.validate(
            index >= startIndex && index <= endIndex,
            "The index of an array is out of bound." +
            "Index = " + index + " , Range = " + Range.of(startIndex, endIndex));
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
     * Validates an class type.
     */
    private static void validateClassType(Class<?> classType) {
        Conditions.validateNotNull(
            classType,
            "The class type.");
    }

    /**
     * The Arrays constructor - Disables the default constructor.
     */
    private Arrays() {
    }
}
