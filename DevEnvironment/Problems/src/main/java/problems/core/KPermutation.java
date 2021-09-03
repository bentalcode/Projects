package problems.core;

import problems.interfaces.IKPermutation;

/**
 * The KPermutation class implements a k permutation problem.
 */
public final class KPermutation implements IKPermutation {
    /**
     * The KPermutation constructor.
     */
    public KPermutation() {
    }

    /**
     * Gets the K permutation of an integer array in it's sorted order.
     */
    @Override
    public int[] kPermutation(int size, int k) {
        if (size <= 0 || k <= 0) {
            return null;
        }

        //
        // Create an initial permutation...
        //
        int[] permutation = new int[size];

        for (int index = 0; index < size; ++index) {
            permutation[index] = index + 1;
        }

        //
        // Calculate the get permutation...
        //
        for (int kIndex = 1; kIndex < k; ++kIndex) {
            boolean status = nextPermutation(permutation);

            if (!status) {
                return null;
            }
        }

        return permutation;
    }

    /**
     * Gets the next permutation.
     * Returns true whether there is a next permutation or false if there is not.
     */
    private static boolean nextPermutation(int[] permutation) {
        if (permutation.length <= 1) {
            return false;
        }

        int startIndex = 0;
        int endIndex = permutation.length - 1;

        int decreasingIndex = findFirstDecreasingIndexFromEnd(
            permutation,
            startIndex,
            endIndex);

        if (decreasingIndex == -1) {
            return false;
        }

        int decreasingValue = permutation[decreasingIndex];

        int swapIndex = findSwapIndex(
            permutation,
            decreasingIndex + 1,
            endIndex,
            decreasingValue);

        if (swapIndex == -1) {
            return false;
        }

        swap(permutation, decreasingIndex, swapIndex);
        quickSort(permutation, decreasingIndex + 1, endIndex);

        return true;
    }

    /**
     * Finds the first decreasing index from the end.
     */
    private static int findFirstDecreasingIndexFromEnd(
        int[] values,
        int startIndex,
        int endIndex) {

        if (startIndex >= endIndex) {
            return -1;
        }

        int prevValue = values[endIndex];

        for (int index = endIndex - 1; index >= startIndex; --index) {
            int currValue = values[index];

            if (currValue < prevValue) {
                return index;
            }

            prevValue = currValue;
        }

        return -1;
    }

    /**
     * Finds a swap index.
     */
    private static int findSwapIndex(
        int[] values,
        int startIndex,
        int endIndex,
        int decreasingValue) {

        if (startIndex > endIndex) {
            return -1;
        }

        int swapValue = Integer.MAX_VALUE;
        int swapIndex = -1;

        for (int index = startIndex; index <= endIndex; ++index) {
            int currValue = values[index];

            if (currValue > decreasingValue && (swapIndex == -1 || currValue < swapValue)) {
                swapValue = currValue;
                swapIndex = index;
            }
        }

        return swapIndex;
    }

    /**
     * Sorts an array.
     */
    private static void quickSort(
        int[] values,
        int startIndex,
        int endIndex) {

        if (startIndex >= endIndex) {
            return;
        }

        int midIndex = startIndex + ((endIndex - startIndex) >> 1);
        int partitionIndex = partition(values, startIndex, endIndex, midIndex);

        quickSort(values, startIndex, partitionIndex - 1);
        quickSort(values, partitionIndex + 1, endIndex);
    }

    /**
     * Partition the array.
     */
    private static int partition(
        int[] values,
        int startIndex,
        int endIndex,
        int partitionIndex) {

        int partitionValue = values[partitionIndex];

        swap(values, partitionIndex, endIndex);

        int insertIndex = startIndex;

        for (int index = startIndex; index < endIndex; ++index) {
            int currValue = values[index];

            if (currValue < partitionValue) {
                swap(values, index, insertIndex);
                ++insertIndex;
            }
        }

        swap(values, insertIndex, endIndex);
        return insertIndex;
    }

    /**
     * Swaps values.
     */
    private static void swap(int[] values, int leftIndex, int rightIndex) {
        int temp = values[leftIndex];
        values[leftIndex] = values[rightIndex];
        values[rightIndex] = temp;
    }
}
