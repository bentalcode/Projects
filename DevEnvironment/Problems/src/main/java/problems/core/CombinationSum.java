package problems.core;

import base.core.Conditions;
import base.core.ListComparator;
import base.interfaces.IBinaryComparator;
import problems.interfaces.ICombinationSum;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Set;
import java.util.TreeSet;

/**
 * The CombinationSum class implements a combination sum.
 */
public final class CombinationSum implements ICombinationSum {
    /**
     * Gets the combination sum.
     * All numbers will be positive integers.
     * The result set must not contain duplicate combinations.
     */
    @Override
    public Set<List<Integer>> combinationSum(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        IBinaryComparator<List<Integer>> comparator = new ListComparator<>();
        Set<List<Integer>> results = new TreeSet<>(comparator.toComparator());

        if (values.length == 0) {
            return results;
        }

        int[] sortedValues = this.sort(values);

        List<Integer> currResult = new ArrayList<>();

        int currIndex = 0;
        int currSum = 0;

        this.combinationSum(
            sortedValues,
            sum,
            currIndex,
            currSum,
            currResult,
            results);

        return results;
    }

    /**
     * Gets the combination sum.
     * Each value should be used once.
     * All numbers will be positive integers.
     * The result set must not contain duplicate combinations.
     */
    @Override
    public Set<List<Integer>> singleCombinationSum(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        IBinaryComparator<List<Integer>> comparator = new ListComparator<>();
        Set<List<Integer>> results = new TreeSet<>(comparator.toComparator());

        if (values.length == 0) {
            return results;
        }

        int[] sortedValues = this.sort(values);

        List<Integer> currResult = new ArrayList<>();
        int currIndex = 0;
        int currSum = 0;

        this.singleCombinationSum(sortedValues, sum, currIndex, currSum, currResult, results);

        return results;
    }

    private void combinationSum(
        int[] values,
        int sum,
        int currIndex,
        int currSum,
        List<Integer> currResult,
        Set<List<Integer>> results) {

        assert (currIndex >= 0 && currIndex <= values.length);

        if (currIndex > values.length) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        if (currSum == sum) {
            List<Integer> newResult = new ArrayList<>(currResult);
            results.add(newResult);
            return;
        }

        if (currIndex == values.length) {
            return;
        }

        int currValue = values[currIndex];
        int maxNumberOfInstances = (sum - currSum) / currValue;

        for (int instanceCount = 0; instanceCount <= maxNumberOfInstances; ++instanceCount) {
            int sumSoFar = currSum + (instanceCount * currValue);
            assert(sumSoFar <= sum);

            for (int i = 0; i < instanceCount; ++i) {
                currResult.add(currValue);
            }

            this.combinationSum(values, sum, currIndex + 1, sumSoFar, currResult, results);

            for (int i = 0; i < instanceCount; ++i) {
                currResult.remove(currResult.size() - 1);
            }
        }
    }

    private void singleCombinationSum(
        int[] values,
        int sum,
        int currIndex,
        int currSum,
        List<Integer> currResult,
        Set<List<Integer>> results) {

        assert (currIndex >= 0 && currIndex <= values.length);

        if (currIndex > values.length) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        if (currSum == sum) {
            List<Integer> newResult = new ArrayList<>(currResult);
            results.add(newResult);
            return;
        }

        if (currIndex == values.length) {
            return;
        }

        int currValue = values[currIndex];
        int sumSoFar = currSum + currValue;

        if (sumSoFar > sum) {
            return;
        }

        this.singleCombinationSum(values, sum, currIndex + 1, currSum, currResult, results);

        currResult.add(currValue);
        this.singleCombinationSum(values, sum, currIndex + 1, sumSoFar, currResult, results);
        currResult.remove(currResult.size() - 1);
    }

    private int[] sort(int[] values) {
        int[] sortedValues = values.clone();
        Arrays.sort(sortedValues);

        return sortedValues;
    }
}
