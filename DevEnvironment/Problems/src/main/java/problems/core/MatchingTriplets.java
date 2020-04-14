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
            "The values.");

        List<ITriplet<Integer, Integer, Integer>> result = new ArrayList<>();

        if (values.length < 3) {
            return result;
        }

        Map<Integer, List<Integer>> indexesMap = this.createIndexesMap(values);

        for (int firstIndex = 0; firstIndex <= values.length - 3; ++firstIndex) {
            int currValue1 = values[firstIndex];
            int matchingValue1 = sum - currValue1;

            for (int secondIndex = firstIndex + 1; secondIndex <= values.length - 2; ++secondIndex) {
                int currValue2 = values[secondIndex];
                int matchingValue2 = matchingValue1 - currValue2;

                if (indexesMap.containsKey(matchingValue2)) {
                    for (int thirdIndex : indexesMap.get(matchingValue2)) {
                        if (thirdIndex > secondIndex) {
                            ITriplet<Integer, Integer, Integer> newResult = Triplet.of(
                                firstIndex,
                                secondIndex,
                                thirdIndex);

                            result.add(newResult);
                        }
                    }
                }
            }
        }

        return result;
    }

    /**
     * Gets the matching sum by indexes (Option 2).
     */
    public List<ITriplet<Integer, Integer, Integer>> getMatchingTripletsIndexesOption2(int[] values, int sum) {
        Conditions.validateNotNull(
                values,
                "The values.");

        List<ITriplet<Integer, Integer, Integer>> result = new ArrayList<>();

        if (values.length < 3) {
            return result;
        }

        Map<Integer, List<Integer>> indexesMap = this.createIndexesMap(values);

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
                indexesMap);

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
    public Set<ITriplet<Integer, Integer, Integer>> getMatchingTriplets(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        Set<ITriplet<Integer, Integer, Integer>> result = new HashSet<>();

        if (values.length < 3) {
            return result;
        }

        int[] sorted = values.clone();
        Arrays.sort(sorted);

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
                    ITriplet<Integer, Integer, Integer> newResult = Triplet.of(
                        firstValue,
                        secondValue,
                        thirdValue);

                    result.add(newResult);

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

        return result;
    }

    /**
     * Gets the values of matching triplets (Option2).
     */
    public Set<ITriplet<Integer, Integer, Integer>> getMatchingTriplets2(int[] values, int sum) {
        Conditions.validateNotNull(
            values,
            "The values.");

        Set<ITriplet<Integer, Integer, Integer>> result = new HashSet<>();

        if (values.length < 3) {
            return result;
        }

        int[] sorted = values.clone();
        Arrays.sort(sorted);

        for (int i = 0; i < sorted.length - 2; ++i) {
            int currValue = sorted[i];
            int matchingValue = sum - currValue;

            int startIndex = i + 1;
            int endIndex = sorted.length - 1;

            Set<IDoublet<Integer, Integer>> matchingPairs = this.getMatchingDoublets(
                sorted,
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
            "The values.");

        if (values.length < 3) {
            return null;
        }

        int[] sorted = values.clone();
        Arrays.sort(sorted);

        ITriplet<Integer, Integer, Integer> closestTriplet = null;
        int minDiff = Integer.MAX_VALUE;

        for (int firstIndex = 0; firstIndex < sorted.length - 2; ++firstIndex) {
            int firstValue = sorted[firstIndex];
            int matchingSum = sum - firstValue;

            int leftIndex = firstIndex + 1;
            int rightIndex = sorted.length - 1;

            while (leftIndex < rightIndex) {
                int secondValue = sorted[leftIndex];
                int thirdValue = sorted[rightIndex];

                int currSum = secondValue + thirdValue;

                if (currSum == matchingSum) {
                    return Triplet.of(
                        firstValue,
                        secondValue,
                        thirdValue);
                }

                int tripleSum = firstValue + secondValue + thirdValue;
                int currDiff = Math.abs(sum - tripleSum);

                if (closestTriplet == null || currDiff < minDiff) {
                    closestTriplet = Triplet.of(
                        firstValue,
                        secondValue,
                        thirdValue);
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
     * Gets the indexes of matching doublets.
     */
    private List<IDoublet<Integer, Integer>> getMatchingDoubletsIndexes(
        int[] values,
        int startIndex,
        int endIndex,
        int sum,
        Map<Integer, List<Integer>> indexesMap) {

        List<IDoublet<Integer, Integer>> result = new ArrayList<>();

        for (int i = startIndex; i <= endIndex - 1; ++i) {
            int currValue = values[i];
            int matchingValue = sum - currValue;

            if (indexesMap.containsKey(matchingValue)) {
                int firstIndex = i;

                for (Integer secondIndex : indexesMap.get(matchingValue)) {

                    if (secondIndex > firstIndex && secondIndex <= endIndex) {
                        IDoublet<Integer, Integer> newResult = Doublet.of(firstIndex, secondIndex);
                        result.add(newResult);
                    }
                }
            }
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
                IDoublet<Integer, Integer> newResult = Doublet.of(leftValue, rightValue);
                result.add(newResult);

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
     * Creates the indexes map.
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
}
