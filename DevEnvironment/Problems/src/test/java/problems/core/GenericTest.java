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
        // [[1,2],[3,5],[6,7],[8,10],[12,16]]
        int[] interval1 = new int[2];
        int[] interval2 = new int[2];
        int[] interval3 = new int[2];
        int[] interval4 = new int[2];
        int[] interval5 = new int[2];

        interval1[0] = 1; interval1[1] = 2;
        interval2[0] = 3; interval2[1] = 5;
        interval3[0] = 6; interval3[1] = 7;
        interval4[0] = 8; interval4[1] = 10;
        interval5[0] = 12; interval5[1] = 16;

        int[][] intervals = new int[5][];
        intervals[0] = interval1;
        intervals[1] = interval2;
        intervals[2] = interval3;
        intervals[3] = interval4;
        intervals[4] = interval5;

        int[] newInterval = new int[2];
        newInterval[0] = 4; newInterval[1] = 8;

        int[][] results = new Solution().insert(intervals, newInterval);
    }

    class Solution {
        public int[][] insert(int[][] intervals, int[] newInterval) {
            validateIntervals(intervals);
            validateInterval(newInterval);

            int length = intervals.length;

            if (length == 0) {
                int[][] result = new int[1][];
                result[0] = newInterval;
                return result;
            }

            int[][] sorted = sortIntervals(intervals);
            int insertIndex = findInsertIndex(sorted, newInterval);

            Stack<int[]> stack = new Stack<>();

            if (insertIndex == 0) {
                stack.push(newInterval);
            }
            else {
                for (int index = 0; index < insertIndex; ++index) {
                    int[] currInterval = intervals[index];
                    stack.push(currInterval);
                }

                processInterval(stack, newInterval);
            }

            for (int index = insertIndex; index < intervals.length; ++index) {
                int[] currInterval = intervals[index];
                processInterval(stack, currInterval);
            }

            int resultSize = stack.size();
            int[][] results = new int[resultSize][];
            int resultsInsertIndex = resultSize - 1;

            while (!stack.isEmpty() && resultsInsertIndex >= 0) {
                int[] currInterval = stack.pop();
                results[resultsInsertIndex] = currInterval;
                --resultsInsertIndex;
            }

            return results;
        }

        private void processInterval(Stack<int[]> stack, int[] interval) {
            int[] prevInterval = stack.pop();

            if (intervalsOverlap(prevInterval, interval)) {
                int[] mergedInterval = mergeIntervals(prevInterval, interval);
                stack.push(mergedInterval);
            }
            else {
                stack.push(prevInterval);
                stack.push(interval);
            }
        }

        private boolean intervalsOverlap(int[] before, int[] after) {
            int beforeStart = before[0];
            int beforeEnd = before[1];

            int afterStart = after[0];
            int afterEnd = after[1];

            return beforeEnd >= afterStart;
        }

        private int[] mergeIntervals(int[] before, int[] after) {
            int beforeStart = before[0];
            int beforeEnd = before[1];

            int afterStart = after[0];
            int afterEnd = after[1];

            int start = beforeStart;
            int end = Math.max(beforeEnd, afterEnd);

            return createInterval(start, end);
        }

        private boolean before(int[] before, int[] after) {
            int beforeStart = before[0];
            int beforeEnd = before[1];

            int afterStart = after[0];
            int afterEnd = after[1];

            if (beforeStart < afterStart) {
                return true;
            }

            if (beforeStart > afterStart) {
                return false;
            }

            return beforeEnd <= afterEnd;
        }

        private int indexesSize(int startIndex, int endIndex) {
            return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
        }

        private int findInsertIndex(int[][] intervals, int[] interval) {
            int length = intervals.length;

            if (length == 0) {
                return 0;
            }

            return findInsertIndex(intervals, 0, length - 1, interval);
        }

        private int findInsertIndex(int[][] intervals, int startIndex, int endIndex, int[] interval) {
            int length = intervals.length;

            assert(startIndex >= 0 && startIndex < length);
            assert(endIndex >= startIndex && endIndex < length);

            if (startIndex == endIndex) {
                int[] interval1 = intervals[startIndex];

                if (before(interval, interval1)) {
                    return startIndex;
                }
                else {
                    return endIndex + 1;
                }
            }
            else if (startIndex + 1 == endIndex) {
                int[] interval1 = intervals[startIndex];
                int[] interval2 = intervals[endIndex];

                if (before(interval, interval1)) {
                    return startIndex;
                }
                else if (before(interval, interval2)) {
                    return endIndex;
                }
                else {
                    return endIndex + 1;
                }
            }

            int midIndex = startIndex + ((endIndex - startIndex) >> 1);
            int[] midInterval = intervals[midIndex];
            int[] beforeMidInterval = intervals[midIndex - 1];
            int[] afterMidInterval = intervals[midIndex + 1];

            if (before(beforeMidInterval, interval) && before(interval, midInterval)) {
                return midIndex;
            }
            else if (before(midInterval, interval) && before(interval, afterMidInterval)) {
                return midIndex + 1;
            }

            if (before(interval, midInterval)) {
                return findInsertIndex(intervals, startIndex, midIndex - 1, interval);
            }
            else {
                return findInsertIndex(intervals, midIndex + 1, endIndex, interval);
            }
        }

        private int[][] sortIntervals(int[][] intervals) {
            int[][] sorted = copyIntervals(intervals);

            Arrays.sort(sorted, new Comparator<int[]>(){
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
                int[] copyInterval = copyInterval(interval);

                result[index] = copyInterval;
            }

            return result;
        }

        private int[] copyInterval(int[] interval) {
            if (interval == null) {
                return null;
            }

            return createInterval(interval[0], interval[1]);
        }

        private int[] createInterval(int start, int end) {
            int[] result = new int[2];
            result[0] = start;
            result[1] = end;

            return result;
        }

        private void validateIntervals(int[][] intervals) {
            if (intervals == null) {
                throw new IllegalArgumentException("The input intervals is null.");
            }

            for (int[] interval : intervals) {
                validateInterval(interval);
            }
        }

        private void validateInterval(int[] interval) {
            if (interval == null) {
                throw new IllegalArgumentException("The input interval is null.");
            }

            if (interval.length != 2) {
                throw new IllegalArgumentException("The input interval is invalid.");
            }
        }
    }
}