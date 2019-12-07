package problems.core;

import base.core.Conditions;
import base.core.Doublet;
import base.core.Triplet;
import base.interfaces.IDoublet;
import base.interfaces.ITriplet;
import problems.interfaces.IMatchingTriplets;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;

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
     * Gets the matching sum by indexes.
     */
    @Override
    public List<ITriplet<Integer, Integer, Integer>> getMatchingTripletsIndexes(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values can not be null.");

        List<ITriplet<Integer, Integer, Integer>> result = new ArrayList<>();

        if (values.length < 3) {
            return result;
        }

        Map<Integer, Set<Integer>> visitedIndexes = new HashMap<>();

        for (int i = 0; i < values.length - 2; ++i) {
            int currValue = values[i];
            int matchingValue = sum - currValue;

            int startIndex = i + 1;
            int endIndex = values.length - 1;

            List<IDoublet<Integer, Integer>> matchingPairs = this.getMatchingDoubletsIndexes(
                values,
                startIndex,
                endIndex,
                matchingValue,
                visitedIndexes);

            for (IDoublet<Integer, Integer> matchingPair : matchingPairs) {
                ITriplet<Integer, Integer, Integer> newResult = Triplet.of(i, matchingPair.first(), matchingPair.second());
                result.add(newResult);
            }
        }

        return result;
    }

    /**
     * Gets the values of matching triplets.
     */
    @Override
    public Set<ITriplet<Integer, Integer, Integer>> getMatchingTriplets(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values can not be null.");

        Set<ITriplet<Integer, Integer, Integer>> result = new HashSet<>();

        int[] sorted = values.clone();
        Arrays.sort(sorted);

        for (int i = 0; i < values.length - 2; ++i) {
            int currValue = values[i];
            int matchingValue = sum - currValue;

            int startIndex = i + 1;
            int endIndex = values.length - 1;

            Set<IDoublet<Integer, Integer>> matchingPairs = this.getMatchingDoublets(
                values,
                startIndex,
                endIndex,
                matchingValue);

            for (IDoublet<Integer, Integer> matchingPair : matchingPairs) {
                ITriplet<Integer, Integer, Integer> newResult = Triplet.of(currValue, matchingPair.first(), matchingPair.second());
                result.add(newResult);
            }
        }

        return result;
    }

    /**
     * Gets the closest matching triplet.
     */
    @Override
    public ITriplet<Integer, Integer, Integer> getClosestMatchingTriplet(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values can not be null.");

        if (values.length < 3) {
            return null;
        }

        int[] sortedValues = values.clone();
        Arrays.sort(sortedValues);

        ITriplet<Integer, Integer, Integer> closestTriplet = null;
        int minDiff = Integer.MAX_VALUE;

        for (int i = 0; i < sortedValues.length - 2; ++i) {
            int currValue = sortedValues[i];
            int matchingValue = sum - currValue;

            int startIndex = i + 1;
            int endIndex = sortedValues.length - 1;
            
            IDoublet<Integer, Integer> closestPair = this.getClosestMatchingDoublet(
                sortedValues,
                startIndex,
                endIndex,
                matchingValue);

            int firstValue = currValue;
            int secondValue = closestPair.first();
            int thirdValue = closestPair.second();

            int currSum = firstValue + secondValue + thirdValue;

            if (currSum == sum) {
                return Triplet.of(firstValue, secondValue, thirdValue);
            }

            int currDiff = Math.abs(sum - currSum);

            if (closestTriplet == null || currDiff < minDiff) {
                closestTriplet = Triplet.of(firstValue, secondValue, thirdValue);
                minDiff = currDiff;
            }
        }

        return closestTriplet;
    }

    /**
     * Gets the indexes of matching doublets.
     */
    private List<IDoublet<Integer, Integer>> getMatchingDoubletsIndexes(
        int[] values,
        int startIndex,
        int endIndex,
        int sum,
        Map<Integer, Set<Integer>> visitedIndexes) {

        List<IDoublet<Integer, Integer>> result = new ArrayList<>();

        for (int i = startIndex; i <= endIndex; ++i) {
            int currValue = values[i];
            int matchingValue = sum - currValue;

            if (visitedIndexes.containsKey(matchingValue)) {
                int secondIndex = i;

                for (Integer firstIndex : visitedIndexes.get(matchingValue)) {
                    if (firstIndex >= startIndex && firstIndex < secondIndex) {
                        IDoublet<Integer, Integer> newResult = Doublet.of(firstIndex, secondIndex);

                        result.add(newResult);
                    }
                }
            }

            Set<Integer> indexes;

            if (visitedIndexes.containsKey(currValue)) {
                indexes = visitedIndexes.get(currValue);
            }
            else {
                indexes = new HashSet<>();
                visitedIndexes.put(currValue, indexes);
            }

            indexes.add(i);
        }

        return result;
    }

    /**
     * Gets the values of matching doublets.
     */
    private Set<IDoublet<Integer, Integer>> getMatchingDoublets(
        int[] values,
        int startIndex,
        int endIndex,
        int sum) {

        Set<IDoublet<Integer, Integer>> result = new HashSet<>();

        int leftIndex = startIndex;
        int rightIndex = endIndex;

        while (leftIndex < rightIndex) {
            int leftValue = values[leftIndex];
            int rightValue = values[rightIndex];

            int currSum = leftValue + rightValue;

            if (currSum == sum) {
                result.add(Doublet.of(leftValue, rightValue));

                ++leftIndex;
                --rightIndex;
            }
            else if (currSum < sum) {
                ++leftIndex;
            }
            else {
                --rightIndex;
            }
        }

        return result;
    }

    /**
     * Gets the closest values of matching doublet.
     */
    private IDoublet<Integer, Integer> getClosestMatchingDoublet(
        int[] values,
        int startIndex,
        int endIndex,
        int sum) {

        IDoublet<Integer, Integer> result = null;
        int minDiff = Integer.MAX_VALUE;

        int leftIndex = startIndex;
        int rightIndex = endIndex;

        while (leftIndex < rightIndex) {
            int leftValue = values[leftIndex];
            int rightValue = values[rightIndex];

            int currSum = leftValue + rightValue;

            if (currSum == sum) {
                return Doublet.of(leftValue, rightValue);
            }

            int currDiff = Math.abs(sum - currSum);

            if (result == null || currDiff < minDiff) {
                result = Doublet.of(leftValue, rightValue);
                minDiff = currDiff;
            }

            if (currSum < sum) {
                ++leftIndex;
            }
            else {
                --rightIndex;
            }
        }

        return result;
    }
}
