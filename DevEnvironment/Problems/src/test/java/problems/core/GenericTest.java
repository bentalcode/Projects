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
        int[] interval1 = new int[2];
        int[] interval2= new int[2];
        int[] interval3 = new int[2];
        int[] interval4 = new int[2];

        interval1[0] = 1; interval1[1] = 3;
        interval2[0] = 2; interval2[1] = 6;
        interval3[0] = 8; interval3[1] = 10;
        interval4[0] = 15; interval4[1] = 18;

        int[][] intervals = new int[4][];
        intervals[0] = interval1;
        intervals[1] = interval2;
        intervals[2] = interval3;
        intervals[3] = interval4;

        int[][] results = new Solution().merge(intervals);
    }

    class Solution {
        public int[][] merge(int[][] intervals) {
            if (intervals == null) {
                throw new IllegalArgumentException("The array of input intervals are null.");
            }

            int length = intervals.length;

            if (length <= 1) {
                return intervals;
            }

            int[][] sorted = sort(intervals);

            Stack<int[]> stack = new Stack<>();
            stack.push(sorted[0]);

            for (int index = 1; index < length; ++index) {
                int[] currInterval = sorted[index];
                int[] prevInterval = stack.pop();

                if (intervalOverlap(prevInterval, currInterval)) {
                    int[] mergedInterval = merge(prevInterval, currInterval);
                    stack.push(mergedInterval);
                }
                else {
                    stack.push(prevInterval);
                    stack.push(currInterval);
                }
            }

            int[][] mergedIntervals = getMergedIntervals(stack);
            return mergedIntervals;
        }

        private boolean intervalOverlap(int[] left, int[] right) {
            int leftEndIndex = left[1];
            int rightStartIndex = right[0];

            return rightStartIndex <= leftEndIndex;
        }

        private int[] merge(int[] left, int[] right) {
            assert(intervalOverlap(left, right));

            int leftStartIndex = left[0];
            int rightEndIndex = right[1];

            int[] mergedInterval = new int[2];
            mergedInterval[0] = leftStartIndex;
            mergedInterval[1] = rightEndIndex;
            return mergedInterval;
        }

        private int[][] getMergedIntervals(Stack<int[]> stack) {
            int length = stack.size();

            if (length == 0) {
                return null;
            }

            int[][] result = new int[length][];
            int insertIndex = length - 1;

            while (!stack.isEmpty()) {
                int[] interval = stack.pop();
                result[insertIndex] = interval;
                --insertIndex;
            }

            return result;
        }

        private int[][] sort(int[][] intervals) {
            int[][] sorted = copy(intervals);

            Arrays.sort(sorted, new Comparator<int[]>() {
                public int compare(int[] left, int[] right) {
                    if (left == null && right == null) {
                        return 0;
                    }

                    if (left == null) {
                        return -1;
                    }

                    if (right == null) {
                        return 1;
                    }

                    int leftStartIndex = left[0];
                    int leftEndIndex = left[1];

                    int rightStartIndex = right[0];
                    int rightEndIndex = right[1];

                    if (leftStartIndex < rightStartIndex) {
                        return -1;
                    }

                    if (leftStartIndex > rightStartIndex) {
                        return 1;
                    }

                    if (leftEndIndex < rightEndIndex) {
                        return -1;
                    }

                    if (leftEndIndex > rightEndIndex) {
                        return 1;
                    }

                    return 0;
                }
            });

            return sorted;
        }

        private int[][] copy(int[][] intervals) {
            if (intervals == null) {
                return null;
            }

            int length = intervals.length;

            int[][] result = new int[length][];

            for (int index = 0; index < length; ++index) {
                int[] interval = intervals[index];
                int[] intervalCopy = copy(interval);

                result[index] = intervalCopy;
            }

            return result;
        }

        private int[] copy(int[] interval) {
            int[] result = new int[2];
            result[0] = interval[0];
            result[1] = interval[1];
            return result;
        }
    }
}
