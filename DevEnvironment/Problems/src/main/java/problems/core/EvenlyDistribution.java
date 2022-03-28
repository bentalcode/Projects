package problems.core;

import base.core.Conditions;
import base.core.MutableInteger;
import base.core.Pair;
import base.interfaces.IPair;
import problems.ProblemsException;
import problems.interfaces.IEventlyDistribution;
import java.util.Arrays;

/**
 * The EvenlyDistribution class implements an evenly distribution problem.
 */
public final class EvenlyDistribution implements IEventlyDistribution {

    /**
     * Distributes the numbers evenly.
     */
    @Override
    public IPair<int[], int[]> evenlyDistribute(int[] values) {
        Conditions.validateNotNull(
            values,
            "The values.");

        Conditions.validate(
            values.length != 0,
            "The values array should not be empty.");

        Conditions.validate(
            values.length % 2 == 0,
            "The size of the values array should include even number of elements.");

        int currIndex = 0;
        int setSize = values.length / 2;
        int[] set1 = new int[setSize];
        int[] set2 = new int[setSize];
        MutableInteger minDiff = new MutableInteger(Integer.MAX_VALUE);

        this.evenlyDistributeWithPermutation(
            values,
            currIndex,
            setSize,
            set1,
            set2,
            minDiff);

        return Pair.make(set1, set2);
    }

    /**
     * Distributes the numbers evenly by using a Heuristic algorithm.
     */
    @Override
    public IPair<int[], int[]> evenlyDistributeHeuristic(int[] values) {
        Conditions.validateNotNull(
            values,
            "The values.");

        Conditions.validate(
            values.length != 0,
            "The values array should not be empty.");

        Conditions.validate(
            values.length % 2 == 0,
            "The size of the values array should include even number of elements.");

        int setSize = values.length / 2;
        int[] set1 = new int[setSize];
        int[] set2 = new int[setSize];

        this.evenlyDistributeHeuristic(
            values,
            set1,
            set2);

        return Pair.make(set1, set2);
    }

    /**
     * Distributes the numbers evenly by using permutation.
     */
    private void evenlyDistributeWithPermutation(
        int[] values,
        int index,
        int setSize,
        int[] set1,
        int[] set2,
        MutableInteger minDiff) {

        assert(values != null && set1 != null && set2 != null);
        assert(values.length == set1.length + set2.length);
        assert(index >= 0 && index <= values.length);
        assert(set1.length == setSize);
        assert(set2.length == setSize);

        if (index == values.length) {
            int sum1 = this.calculateSubArraySum(values, 0, setSize - 1);
            int sum2 = this.calculateSubArraySum(values, setSize, values.length - 1);

            int currDiff = Math.abs(sum1 - sum2);

            if (currDiff < minDiff.get()) {
                int numberOfCopiedItems = this.copySubArraySum(values, 0, setSize - 1, set1);

                if (numberOfCopiedItems != setSize) {
                    String errorMessage = "Failed to copy all items for set1 with size: " + setSize;
                    throw new ProblemsException(errorMessage);
                }

                numberOfCopiedItems = this.copySubArraySum(values, setSize, values.length - 1, set2);

                if (numberOfCopiedItems != setSize) {
                    String errorMessage = "Failed to copy all items for set2 with size: " + setSize;
                    throw new ProblemsException(errorMessage);
                }

                minDiff.set(currDiff);
            }

            return;
        }

        for (int currIndex = index; currIndex < values.length; ++currIndex) {
            this.swap(values, index, currIndex);

            this.evenlyDistributeWithPermutation(
                values,
                index + 1,
                setSize,
                set1,
                set2,
                minDiff);

            this.swap(values, index, currIndex);
        }
    }

    /**
     * Distributes the numbers evenly by using a Heuristic algorithm.
     */
    private void evenlyDistributeHeuristic(
        int[] values,
        int[] set1,
        int[] set2) {

        int[] sorted = this.sort(values);

        int insertIndex1 = 0;
        int insertIndex2 = 0;

        boolean insertToFirstSet = true;

        for (int value : sorted) {
            if (insertToFirstSet) {
                set1[insertIndex1] = value;
                ++insertIndex1;
            }
            else {
                set2[insertIndex2] = value;
                ++insertIndex2;
            }

            insertToFirstSet = !insertToFirstSet;
        }
    }

    /**
     * Calculates a sum of a sub array.
     */
    private int calculateSubArraySum(int[] values, int startIndex, int endIndex) {
        int sum = 0;

        for (int i = startIndex; i <= endIndex; ++i) {
            sum += values[i];
        }

        return sum;
    }

    /**
     * Copies a sub array.
     * Returns the number of copies items.
     */
    private int copySubArraySum(int[] values, int startIndex, int endIndex, int[] subArray) {
        assert(values != null && subArray != null);
        assert(startIndex >= 0 && startIndex < values.length);
        assert(endIndex >= 0 && endIndex < values.length);
        assert(subArray.length >= endIndex - startIndex + 1);

        int numberOfCopiedItems = 0;
        int insertIndex = 0;

        for (int index = startIndex; index <= endIndex; ++index) {
            subArray[insertIndex] = values[index];
            ++numberOfCopiedItems;

            ++insertIndex;
        }

        return numberOfCopiedItems;
    }

    /**
     * Sorts the array.
     */
    private int[] sort(int[] values) {
        int[] sorted = values.clone();
        Arrays.sort(sorted);
        return sorted;
    }

    /**
     * Swaps items in an array.
     */
    private void swap(int[] values, int leftIndex, int rightIndex) {
        int temp = values[leftIndex];
        values[leftIndex] = values[rightIndex];
        values[rightIndex] = temp;
    }
}
