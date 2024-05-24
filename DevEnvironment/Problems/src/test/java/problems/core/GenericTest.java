package problems.core;

import org.junit.Test;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public final class GenericTest {
    /**
     * The GenericTest constructor.
     */
    public GenericTest() {
    }

    /**
     * Tests the even distribution logic.
     */
    @Test
    public void test() {
        int[] values = {1,0,-1,0,-2,2};
        List<List<Integer>> result = new Solution().fourSum(values, 0);
    }

    class Solution {
        public List<List<Integer>> fourSum(int[] nums, int target) {
            if (nums == null) {
                throw new IllegalArgumentException("The input array of numbers can not be null.");
            }

            List<List<Integer>> results = new ArrayList<>();

            int length = nums.length;

            if (length < 4) {
                return results;
            }

            int[] sorted = sort(nums);

            for (int firstIndex = 0; firstIndex < length - 3; ++firstIndex) {
                int firstValue = sorted[firstIndex];

                int matchingSum1 = target - firstValue;

                for (int secondIndex = firstIndex + 1; secondIndex < length - 2; ++secondIndex) {
                    int secondValue = sorted[secondIndex];

                    int matchingSum2 = matchingSum1 - secondValue;

                    int thirdIndex = secondIndex + 1;
                    int fourthIndex = length - 1;

                    while (thirdIndex < fourthIndex) {
                        int thirdValue = sorted[thirdIndex];
                        int fourthValue = sorted[fourthIndex];

                        int currSum = thirdValue + fourthValue;

                        if (currSum == matchingSum2) {
                            List<Integer> newResult = createQuad(firstValue, secondValue, thirdValue, fourthValue);
                            addResult(newResult, results);

                            ++thirdIndex;
                            --fourthIndex;
                        }
                        else if (currSum < matchingSum2) {
                            ++thirdValue;
                        }
                        else {
                            --fourthValue;
                        }
                    }
                }
            }

            return results;
        }

        private <T extends Comparable<T>> boolean addResult(List<T> newResult, List<List<T>> results) {
            for (List<T> currResult : results) {
                if (listEquals(currResult, newResult)) {
                    return false;
                }
            }

            results.add(newResult);
            return true;
        }

        private <T extends Comparable<T>> boolean listEquals(List<T> left, List<T> right) {
            return compare(left, right) == 0;
        }

        private <T extends Comparable<T>> int compare(List<T> left, List<T> right) {
            if (left == null && right == null) {
                return 0;
            }

            if (left == null) {
                return -1;
            }

            if (right == null) {
                return 1;
            }

            if (left.size() < right.size()) {
                return -1;
            }

            if (left.size() > right.size()) {
                return 1;
            }

            int length = left.size();

            for (int index = 0; index < length; ++index) {
                T leftValue = left.get(index);
                T rightValue = right.get(index);

                int status = leftValue.compareTo(rightValue);

                if (status != 0) {
                    return status;
                }
            }

            return 0;
        }

        private List<Integer> createQuad(int v1, int v2, int v3, int v4) {
            List<Integer> quad = new ArrayList<>(4);
            quad.add(v1);
            quad.add(v2);
            quad.add(v3);
            quad.add(v4);
            return quad;
        }

        private int[] sort(int[] values) {
            int[] sorted = clone(values);
            Arrays.sort(sorted);
            return sorted;
        }

        private int[] clone(int[] values) {
            int length = values.length;

            int[] cloned = new int[length];

            for (int index = 0; index < length; ++index) {
                cloned[index] = values[index];
            }

            return cloned;
        }
    }
}
