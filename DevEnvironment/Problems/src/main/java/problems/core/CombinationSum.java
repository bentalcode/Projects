package problems.core;

import base.core.Conditions;
import base.core.EqualBuilder;
import problems.ProblemsException;
import problems.interfaces.ICombinationSum;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

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
    public List<List<Integer>> combinationSum(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        this.validateUniquePositives(values);

        List<List<Integer>> results = new ArrayList<>();

        if (sum <= 0) {
            return results;
        }

        int[] sortedValues = this.sort(values);

        List<Integer> currResult = new ArrayList<>();

        int currIndex = 0;
        int currSum = 0;

        this.combinationSum(
            sortedValues,
            currIndex,
            currSum,
            sum,
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
    public List<List<Integer>> singleCombinationSum(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        this.validatePositives(values);

        List<List<Integer>> results = new ArrayList<>();

        if (sum <= 0) {
            return results;
        }

        int[] sortedValues = this.sort(values);

        List<Integer> currResult = new ArrayList<>();
        int currSum = 0;

        for (int startIndex = 0; startIndex < values.length; ++startIndex) {
            this.singleCombinationSum(
                sortedValues,
                startIndex,
                currSum,
                sum,
                currResult,
                results);

            assert(currResult.isEmpty());
        }

        return results;
    }

    private void combinationSum(
        int[] values,
        int currIndex,
        int currSum,
        int sum,
        List<Integer> currResult,
        List<List<Integer>> results) {

        assert(currIndex >= 0 && currIndex < values.length);

        if (currIndex >= values.length) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        int currValue = values[currIndex];
        int numberOfOccurrences = (sum - currSum) / currValue;

        for (int valueCount = 0; valueCount <= numberOfOccurrences; ++valueCount) {
            int sumSoFar = currSum + currValue * valueCount;

            assert(sumSoFar <= sum);

            for (int i = 0; i < valueCount; ++i) {
                currResult.add(currValue);
            }

            if (sumSoFar == sum) {
                List<Integer> newResult = new ArrayList<>(currResult);
                results.add(newResult);
            }
            else if (currIndex < values.length - 1){
                this.combinationSum(values, currIndex + 1, sumSoFar, sum, currResult, results);
            }

            for (int i = 0; i < valueCount; ++i) {
                currResult.remove(currResult.size() - 1);
            }

            if (currSum == sum) {
                break;
            }
        }
    }

    private void singleCombinationSum(
        int[] values,
        int currIndex,
        int currSum,
        int sum,
        List<Integer> currResult,
        List<List<Integer>> results) {

        assert(currIndex >= 0 && currIndex < values.length);

        if (currIndex >= values.length) {
            return;
        }

        if (currSum > sum) {
            return;
        }

        int currValue = values[currIndex];
        int sumSoFar = currSum + currValue;

        if (sumSoFar > sum) {
            return;
        }

        currResult.add(currValue);

        if (sumSoFar == sum) {
            List<Integer> newResult = new ArrayList<>(currResult);
            this.addResult(newResult, results);
        }
        else {
            for (int index = currIndex + 1; index < values.length; ++index) {
                this.singleCombinationSum(values, index, sumSoFar, sum, currResult, results);
            }
        }

        currResult.remove(currResult.size() - 1);
    }

    private void addResult(List<Integer> newResult, List<List<Integer>> results) {
        Collections.sort(newResult);

        if (!this.resultExists(results, newResult)) {
            results.add(newResult);
        }
    }

    private boolean resultExists(List<List<Integer>> results, List<Integer> newResult) {
        for (List<Integer> currResult : results) {
            boolean status = new EqualBuilder()
                .withCollection(currResult, newResult, base.core.Comparator.defaultComparator())
                .build();

            if (status) {
                return true;
            }
        }

        return false;
    }

    private int[] sort(int[] values) {
        int[] sortedValues = values.clone();
        Arrays.sort(sortedValues);

        return sortedValues;
    }

    private void validateUniquePositives(int[] values) {
        this.validateUnique(values);
        this.validatePositives(values);
    }

    private void validateUnique(int[] values) {
        Set<Integer> visited = new HashSet<>();

        for (int value : values) {

            if (visited.contains(value)) {
                String errorMessage = "The input values are not unique.";
                throw new ProblemsException(errorMessage);
            }

            visited.add(value);
        }
    }

    private void validatePositives(int[] values) {
        for (int value : values) {
            if (value <= 0) {
                String errorMessage = "The input value: " + value + " is not positive.";
                throw new ProblemsException(errorMessage);
            }
        }
    }
}
