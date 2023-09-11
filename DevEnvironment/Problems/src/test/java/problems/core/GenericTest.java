package problems.core;

import java.util.*;

import base.core.Strings;
import org.junit.Test;

public final class GenericTest {
    class ListNode {
        public int val;
        public ListNode next;

        public ListNode() {
        }

        public ListNode(int val) {
            this.val = val;
        }
    }

    ;

    /**
     * The GenericTest constructor.
     */
    public GenericTest() {
    }

    /**
     * Tests the logic of the generic test.
     */
    @Test
    public void test() {
        int[] values = {1, 2, 3, 4};

        for (int i = 0; i < 10; ++i) {
            new Solution().nextPermutation(values);
        }
    }

    class Solution {
        public void nextPermutation(int[] nums) {
            if (nums == null || nums.length == 0) {
                throw new IllegalArgumentException("The input array of numbers can not be null or empty.");
            }

            int length = nums.length;

            if (length <= 1) {
                return;
            }

            int startIndex = 0;
            int endIndex = length - 1;

            int firstDecreasingIndex = findFirstDecreasingIndex(nums, startIndex, endIndex);

            if (firstDecreasingIndex == -1) {
                sort(nums);
                return;
            }

            int firstDecreasingValue = nums[firstDecreasingIndex];
            int swapIndex = findSwapIndex(nums, firstDecreasingIndex + 1, endIndex, firstDecreasingValue);

            if (swapIndex == -1) {
                assert(false);
                throw new RuntimeException("The swap index has not been found.");
            }

            swap(nums, firstDecreasingIndex, swapIndex);
            sort(nums, firstDecreasingIndex + 1, endIndex);
        }

        private int findFirstDecreasingIndex(int[] values, int startIndex, int endIndex) {
            assert(startIndex <= endIndex);

            if (startIndex == endIndex) {
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

        private int findSwapIndex(int[] values, int startIndex, int endIndex, int firstDecreasingValue) {
            int swapIndex = -1;
            int swapValue = Integer.MAX_VALUE;

            for (int index = startIndex; index <= endIndex; ++index) {
                int currValue = values[index];

                if (currValue > firstDecreasingValue && currValue < swapValue) {
                    swapIndex = index;
                    swapValue = currValue;
                }
            }

            return swapIndex;
        }

        private void swap(int[] values, int index1, int index2) {
            int temp = values[index1];
            values[index1] = values[index2];
            values[index2] = temp;
        }

        private void sort(int[] values) {
            if (values.length <= 1) {
                return;
            }

            quicksort(values, 0, values.length - 1);
        }

        private void sort(int[] values, int startIndex, int endIndex) {
            quicksort(values, startIndex, endIndex);
        }

        private void quicksort(int[] values, int startIndex, int endIndex) {
            if (startIndex >= endIndex) {
                return;
            }

            int pivotIndex = startIndex + ((endIndex - startIndex) >> 1);
            int partitionIndex = partition(values, startIndex, endIndex, pivotIndex);

            quicksort(values, startIndex, partitionIndex - 1);
            quicksort(values, partitionIndex + 1, endIndex);
        }

        private int partition(int[] values, int startIndex, int endIndex, int pivotIndex) {
            assert(startIndex <= endIndex);
            assert(pivotIndex >= startIndex && pivotIndex <= endIndex);

            int pivotValue = values[pivotIndex];
            swap(values, pivotIndex, endIndex);

            int insertIndex = startIndex;

            for (int index = startIndex; index <= endIndex - 1; ++index) {
                int currValue = values[index];

                if (currValue < pivotValue) {
                    swap(values, index, insertIndex);
                    ++insertIndex;
                }
            }

            swap(values, insertIndex, endIndex);
            return insertIndex;
        }
    }
}
