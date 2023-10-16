package problems.core;

import base.core.Conditions;
import base.core.Triplet;
import base.interfaces.ITriplet;
import problems.interfaces.IMatchingTriplets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * The MatchingTriplets class implements a matching triplets to a given sum.
 */
public final class MatchingTriplets implements IMatchingTriplets {
    /**
     * The MatchingTriplets constructor.
     */
    public MatchingTriplets() {
    }

    /**
     * Finds the indexes of matching triplets.
     */
    @Override
    public List<ITriplet<Integer, Integer, Integer>> findMatchingTripletsIndexes(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        List<ITriplet<Integer, Integer, Integer>> results = new ArrayList<>();

        if (values.length < 3) {
            return results;
        }

        Map<Integer, List<Integer>> indexesMap = this.createIndexesMap(values);

        for (int firstIndex = 0; firstIndex < values.length - 2; ++firstIndex) {
            int first = values[firstIndex];
            int matchingValue1 = sum - first;

            for (int secondIndex = firstIndex + 1; secondIndex < values.length - 1; ++secondIndex) {
                int second = values[secondIndex];
                int matchingValue2 = matchingValue1 - second;

                if (indexesMap.containsKey(matchingValue2)) {
                    for (int thirdIndex : indexesMap.get(matchingValue2)) {
                        if (thirdIndex > secondIndex) {
                            ITriplet<Integer, Integer, Integer> newResult = Triplet.make(
                                firstIndex,
                                secondIndex,
                                thirdIndex);

                            results.add(newResult);
                        }
                    }
                }
            }
        }

        return results;
    }

    /**
     * Finds the values of matching triplets.
     */
    @Override
    public List<ITriplet<Integer, Integer, Integer>> findMatchingTriplets(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        List<ITriplet<Integer, Integer, Integer>> results = new ArrayList<>();

        if (values.length < 3) {
            return results;
        }

        int[] sorted = this.sort(values);

        for (int firstIndex = 0; firstIndex < sorted.length - 2; ++firstIndex) {
            int firstValue = sorted[firstIndex];
            int matchingValue = sum - firstValue;

            int leftIndex = firstIndex + 1;
            int rightIndex = sorted.length - 1;

            while (leftIndex < rightIndex) {
                int secondValue = sorted[leftIndex];
                int thirdValue = sorted[rightIndex];

                int currSum = secondValue + thirdValue;

                if (currSum == matchingValue) {
                    ITriplet<Integer, Integer, Integer> newResult = Triplet.make(
                        firstValue,
                        secondValue,
                        thirdValue);

                    this.addNewResult(newResult, results);

                    ++leftIndex;
                    --rightIndex;
                }
                else if (currSum < matchingValue) {
                    ++leftIndex;
                }
                else {
                    --rightIndex;
                }
            }
        }

        return results;
    }

    /**
     * Finds the closest matching triplet.
     */
    @Override
    public ITriplet<Integer, Integer, Integer> findClosestMatchingTriplet(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        if (values.length < 3) {
            return null;
        }

        int[] sorted = this.sort(values);

        ITriplet<Integer, Integer, Integer> closestTriplet = null;
        int minDiff = Integer.MAX_VALUE;

        for (int firstIndex = 0; firstIndex < sorted.length - 2; ++firstIndex) {
            int first = sorted[firstIndex];
            int matchingSum = sum - first;

            int leftIndex = firstIndex + 1;
            int rightIndex = sorted.length - 1;

            while (leftIndex < rightIndex) {
                int second = sorted[leftIndex];
                int third = sorted[rightIndex];

                int currSum = second + third;

                if (currSum == matchingSum) {
                    return Triplet.make(
                        first,
                        second,
                        third);
                }

                int tripleSum = first + second + third;
                int currDiff = Math.abs(sum - tripleSum);

                if (closestTriplet == null || currDiff < minDiff) {
                    closestTriplet = Triplet.make(
                        first,
                        second,
                        third);
                }

                if (currSum < sum) {
                    ++leftIndex;
                }
                else {
                    --rightIndex;
                }
            }
        }

        return closestTriplet;
    }

    /**
     * Finds triplets such that sum of two equals to third element.
     */
    @Override
    public List<ITriplet<Integer, Integer, Integer>> findTriplets(int[] values) {
        Conditions.validateNotNull(
            values,
            "The values.");

        List<ITriplet<Integer, Integer, Integer>> results = new ArrayList<>();

        if (values.length < 3) {
            return results;
        }

        int[] sorted = this.sort(values);

        for (int thirdIndex = sorted.length - 1; thirdIndex >= 2; --thirdIndex) {
            int third = values[thirdIndex];

            int firstIndex = 0;
            int secondIndex = thirdIndex - 1;

            while (firstIndex < secondIndex) {
                int first = sorted[firstIndex];
                int second = sorted[secondIndex];

                int currSum = first + second;

                if (currSum == third) {
                    ITriplet<Integer, Integer, Integer> newResult = Triplet.make(first, second, third);
                    this.addNewResult(newResult, results);

                    ++firstIndex;
                    --secondIndex;
                }
                else if (currSum < third) {
                    ++firstIndex;
                }
                else {
                    --secondIndex;
                }
            }
        }

        return results;
    }

    /**
     * Creates an indexes map.
     */
    private Map<Integer, List<Integer>> createIndexesMap(int[] values) {
        Map<Integer, List<Integer>> indexesMap = new HashMap<>();

        for (int index = 0; index < values.length; ++index) {
            int currValue = values[index];

            List<Integer> indexes;

            if (indexesMap.containsKey(currValue)) {
                indexes = indexesMap.get(currValue);
            }
            else {
                indexes = new ArrayList<>();
                indexesMap.put(currValue, indexes);
            }

            indexes.add(index);
        }

        return indexesMap;
    }

    /**
     * Adds a new result.
     */
    private void addNewResult(
        ITriplet<Integer, Integer, Integer> newResult,
        List<ITriplet<Integer, Integer, Integer>> results) {

        for (ITriplet<Integer, Integer, Integer> result : results) {
            if (newResult.equals(result)) {
                return;
            }
        }

        results.add(newResult);
    }

    /**
     * Sorts an array.
     */
    private int[] sort(int[] values) {
        int[] sorted = values.clone();
        Arrays.sort(sorted);
        return sorted;
    }
}
