package algorithms.core;

import algorithms.interfaces.ISort;
import base.core.Arrays;
import base.core.Conditions;
import base.core.Indexes;
import base.interfaces.IBinaryComparator;

/**
 * The MergeSort class implements a merge sort.
 */
public final class MergeSort<T> implements ISort<T> {
    private final Class<T> classType;
    private final IBinaryComparator<T> comparator;

    /**
     * The MergeSort constructor.
     */
    public MergeSort(
        Class<T> classType,
        IBinaryComparator<T> comparator) {

        Conditions.validateNotNull(
            classType,
            "The class type.");

        Conditions.validateNotNull(
            comparator,
            "The comparator of elements.");

        this.classType = classType;
        this.comparator = comparator;
    }

    /**
     * Sorts an array.
     */
    public void sort(T[] arr) {
        Conditions.validateNotNull(
            arr,
            "The array to sort.");

        if (arr.length <= 1) {
            return;
        }

        T[] buffer = Arrays.newInstance(this.classType, arr.length);
        this.mergeSort(arr, 0, arr.length - 1, buffer);
    }

    /**
     * Merge sorts an array.
     */
    private void mergeSort(
        T[] arr,
        int startIndex,
        int endIndex,
        T[] buffer) {

        int length = Indexes.size(startIndex, endIndex);

        if (length <= 1) {
            return;
        }

        int midIndex = startIndex + ((endIndex - startIndex) >> 1);
        this.mergeSort(arr, startIndex, midIndex, buffer);
        this.mergeSort(arr, midIndex + 1, endIndex, buffer);

        this.merge(arr, startIndex, midIndex, midIndex + 1, endIndex, buffer);
    }

    /**
     * Merges the arrays.
     */
    private void merge(
        T[] arr,
        int leftStartIndex,
        int leftEndIndex,
        int rightStartIndex,
        int rightEndIndex,
        T[] buffer) {

        assert(arr != null);

        assert(leftStartIndex >= 0 && leftStartIndex < arr.length);
        assert(leftEndIndex >= leftStartIndex && leftEndIndex < arr.length);

        assert(rightStartIndex >= 0 && rightStartIndex < arr.length);
        assert(rightEndIndex >= rightStartIndex && rightEndIndex < arr.length);

        assert(buffer != null);
        assert(buffer.length == arr.length);

        int leftLength = Indexes.size(leftStartIndex, leftEndIndex);
        Arrays.copy(arr, leftStartIndex, buffer, leftStartIndex, leftLength);

        int rightLength = Indexes.size(rightStartIndex, rightEndIndex);
        Arrays.copy(arr, rightStartIndex, buffer, rightStartIndex, rightLength);

        int currLeftIndex = leftStartIndex;
        int currRightIndex = rightStartIndex;

        int insertIndex = leftStartIndex;

        while (currLeftIndex <= leftEndIndex && currRightIndex <= rightEndIndex) {
            T leftValue = buffer[currLeftIndex];
            T rightValue = buffer[currRightIndex];

            int compareStatus = this.comparator.compareTo(leftValue, rightValue);

            if (compareStatus <= 0) {
                arr[insertIndex] = leftValue;
                ++currLeftIndex;
            }
            else {
                arr[insertIndex] = rightValue;
                ++currRightIndex;
            }

            ++insertIndex;
        }

        while (currLeftIndex <= leftEndIndex) {
            T value = buffer[currLeftIndex];
            arr[insertIndex] = value;

            ++currLeftIndex;
            ++insertIndex;
        }

        while (currRightIndex <= rightEndIndex) {
            T value = buffer[currRightIndex];
            arr[insertIndex] = value;

            ++currRightIndex;
            ++insertIndex;
        }
    }
}
