package algorithms.core;

import algorithms.interfaces.ISort;
import base.core.Arrays;
import base.core.Conditions;
import base.interfaces.IBinaryComparator;

/**
 * The QuickSort class implements a quick sort.
 */
public final class QuickSort<T> implements ISort<T> {
    private final IBinaryComparator<T> comparator;

    /**
     * The QuickSort constructor.
     */
    public QuickSort(
        IBinaryComparator<T> comparator) {

        Conditions.validateNotNull(
            comparator,
            "The comparator of elements.");

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

        this.quickSort(arr, 0, arr.length - 1);
    }

    /**
     * Quick sorts an array.
     */
    private void quickSort(T[] arr, int startIndex, int endIndex) {
        int length = endIndex - startIndex + 1;

        if (length <= 1) {
            return;
        }

        int midIndex = startIndex + ((endIndex - startIndex) >> 1);

        int partitionIndex = this.partition(arr, startIndex, endIndex, midIndex);

        this.quickSort(arr, startIndex, partitionIndex);
        this.quickSort(arr, partitionIndex + 1, endIndex);
    }

    /**
     * Partitions an array.
     */
    private int partition(
        T[] arr,
        int startIndex,
        int endIndex,
        int partitionIndex) {

        assert(startIndex >= 0 && startIndex < arr.length);
        assert(endIndex >= startIndex && endIndex < arr.length);
        assert(partitionIndex >= startIndex && partitionIndex <= endIndex);

        T partitionValue = arr[partitionIndex];

        Arrays.swap(arr, partitionIndex, endIndex);

        int insertIndex = startIndex;

        for (int i = startIndex; i <= endIndex; ++i) {
            T currValue = arr[i];

            int compareStatus = this.comparator.compareTo(currValue, partitionValue);

            if (compareStatus < 0) {
                Arrays.swap(arr, i, insertIndex);
                ++insertIndex;
            }
        }

        Arrays.swap(arr, insertIndex, endIndex);

        return insertIndex;
    }
}
