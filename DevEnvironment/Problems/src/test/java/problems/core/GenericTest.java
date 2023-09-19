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

        interval1[0] = 2; interval1[1] = 6;
        interval2[0] = 1; interval2[1] = 3;
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
                    throw new IllegalArgumentException("The input intervals can not be null.");
                }

                int length = intervals.length;

                if (length <= 1) {
                    return intervals;
                }

                int[][] sorted = sortIntervals(intervals);

                Stack<int[]> stack = new Stack<>();
                stack.push(sorted[0]);

                for (int index = 1; index < length; ++index) {
                    int[] currInterval = sorted[index];
                    int[] prevInterval = stack.pop();

                    if (intervalsOverlap(prevInterval, currInterval)) {
                        int[] mergedInterval = mergeIntervals(prevInterval, currInterval);

                        stack.push(mergedInterval);
                    }
                    else {
                        stack.push(prevInterval);
                        stack.push(currInterval);
                    }
                }

                int[][] result = getIntervals(stack);

                return result;
            }

            private boolean intervalsOverlap(int[] left, int[] right) {
                int leftEnd = left[1];
                int rightStart = right[0];

                return rightStart <= leftEnd;
            }

            private int[] mergeIntervals(int[] left, int[] right) {
                int leftStart = left[0];
                int leftEnd = left[1];

                int rightEnd = right[1];

                int start = leftStart;
                int end = Math.max(leftEnd, rightEnd);

                return createInterval(start, end);
            }

            private int[] createInterval(int start, int end) {
                int[] interval = new int[2];
                interval[0] = start;
                interval[1] = end;
                return interval;
            }

            private int[][] getIntervals(Stack<int[]> stack) {
                if (stack.isEmpty()) {
                    return null;
                }

                int length = stack.size();

                int[][] intervals = new int[length][];
                int insertIndex = length - 1;

                while (!stack.empty()) {
                    int[] currInterval = stack.pop();
                    intervals[insertIndex] = currInterval;

                    --insertIndex;
                }

                return intervals;
            }

            private int[][] sortIntervals(int[][] intervals) {
                int[][] sorted = copyIntervals(intervals);

                if (sorted == null) {
                    return null;
                }

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

                        int leftStart = left[0];
                        int leftEnd = left[1];

                        int rightStart = right[0];
                        int rightEnd = right[1];

                        if (leftStart < rightStart) {
                            return -1;
                        }

                        if (leftStart > rightStart) {
                            return 1;
                        }

                        if (leftEnd < rightEnd) {
                            return -1;
                        }

                        if (leftEnd > rightEnd) {
                            return 1;
                        }

                        return 0;
                    }
                });

                return sorted;
            }

            private int[][] copyIntervals(int[][] intervals) {
                if (intervals == null) {
                    return null;
                }

                int length = intervals.length;

                int[][] result = new int[length][];

                for (int index = 0; index < length; ++index) {
                    int[] interval = intervals[index];
                    int[] clonedInterval = copyInterval(interval);

                    result[index] = clonedInterval;
                }

                return result;
            }

            private int[] copyInterval(int[] interval) {
                if (interval == null) {
                    return null;
                }

                int[] result = new int[2];
                result[0] = interval[0];
                result[1] = interval[1];

                return result;
            }
        }
    }
