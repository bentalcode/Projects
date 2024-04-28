package problems.core;

import base.core.Pair;
import base.interfaces.IPair;
import problems.interfaces.IMedianOfSortedArrays;

/**
 * The MedianOfSortedArrays class implements the median of sorted arrays' problem.
 */
public final class MedianOfSortedArrays implements IMedianOfSortedArrays {
    /**
     * Calculates the median of two sorted arrays.
     */
    @Override
    public double median(int[] left, int[] right) {
        if (left == null && right == null) {
            return 0.0;
        }

        if (left == null || left.length == 0) {
            return median(right);
        }

        if (right == null || right.length == 0) {
            return median(left);
        }

        return this.median(
            left, 0, left.length - 1,
            right, 0, right.length - 1);
    }

    /**
     * Calculates the median of two sorted arrays.
     */
    private double median(
        int[] left,
        int leftStartIndex,
        int leftEndIndex,
        int[] right,
        int rightStartIndex,
        int rightEndIndex) {

        int length = left.length;

        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(leftEndIndex >= leftStartIndex && leftEndIndex < left.length);

        assert(rightStartIndex >= 0 && rightStartIndex < right.length);
        assert(rightEndIndex >= rightStartIndex && rightEndIndex < right.length);

        int leftSize = indexesSize(leftStartIndex, leftEndIndex);
        int rightSize = indexesSize(rightStartIndex, rightEndIndex);

        //
        // Ensure that the size of the left side is less or equal than the size of the right side...
        //
        if (leftSize > rightSize) {
            return this.median(
                right,
                rightStartIndex,
                rightEndIndex,
                left,
                leftStartIndex,
                leftEndIndex);
        }

        if (leftSize == 1) {

            if (rightSize == 1) {
                //
                // Case 1: If both arrays are with size 1.
                //
                int leftIndex = leftStartIndex;
                int rightIndex = rightStartIndex;

                return this.medianOf(left[leftIndex], right[rightIndex]);
            }
            else if (rightSize % 2 == 0) {
                //
                // Case 2: If the larger array has even numbed of elements,
                // then consider the middle two elements of the larger array,
                // and the only element of the smaller array.
                //
                int leftIndex = leftStartIndex;
                int rightFirstIndex = midIndex(rightStartIndex, rightEndIndex);
                int rightSecondIndex = rightFirstIndex + 1;

                return this.medianOf(
                    left[leftIndex],
                    right[rightFirstIndex], right[rightSecondIndex]);
            }
            else {
                //
                // Case 3: If the larger array has odd number of element,
                // then consider the middle three elements of the larger array,
                // and the only element of the smaller array.
                //
                int leftIndex = leftStartIndex;
                int rightSecondIndex = midIndex(rightStartIndex, rightEndIndex);
                int rightFirstIndex = rightSecondIndex - 1;
                int rightThirdIndex = rightSecondIndex + 1;

                return this.medianOf(
                    left[leftIndex],
                    right[rightFirstIndex], right[rightSecondIndex], right[rightThirdIndex]);
            }
        }
        else if (leftSize == 2) {
            //
            // Case 4: If both arrays are with size 2.
            //
            if (rightSize == 2) {
                int leftFirstIndex = leftStartIndex;
                int leftSecondIndex = leftFirstIndex + 1;
                int rightFirstIndex = rightStartIndex;
                int rightSecondIndex = rightFirstIndex + 1;

                return this.medianOf(
                    left[leftFirstIndex], left[leftSecondIndex],
                    right[rightFirstIndex], right[rightSecondIndex]);
            }
            if (rightSize % 2 == 0) {
                //
                // Case 5: If the larger array has even numbed of elements,
                // then median will be one of the following 4 elements:
                //
                // 1. The middle two elements of larger array.
                // 2. The max of first element of smaller array and element
                //    just before the first middle element in larger array.
                // 3. The min of second element of smaller array and element
                //    just after the second middle in larger array.
                //
                int leftFirstIndex = leftStartIndex;
                int leftSecondIndex = leftFirstIndex + 1;
                int rightSecondIndex = midIndex(rightStartIndex, rightEndIndex);
                int rightFirstIndex = rightSecondIndex - 1;
                int rightThirdIndex = rightSecondIndex + 1;
                int rightForthIndex = rightSecondIndex + 2;

                return this.medianOf(
                    Math.max(left[leftFirstIndex], right[rightFirstIndex]),
                    right[rightSecondIndex],
                    right[rightThirdIndex],
                    Math.min(left[leftSecondIndex], right[rightForthIndex]));
            }
            else {
                //
                // Case 6: If the larger array has odd number of elements,
                // then median will be one of the following 3 elements:
                //
                // 1. The middle element of larger array.
                // 2. The max of first element of smaller array and element
                //    just before the middle element in larger array.
                // 3. The min of second element of smaller array and element
                //    just after the middle in larger array.
                int leftFirstIndex = leftStartIndex;
                int leftSecondIndex = leftFirstIndex + 1;
                int rightSecondIndex = midIndex(rightStartIndex, rightEndIndex);
                int rightFirstIndex = rightSecondIndex - 1;
                int rightThirdIndex = rightSecondIndex + 1;

                return this.medianOf(
                    Math.max(left[leftFirstIndex], right[rightFirstIndex]),
                    right[rightSecondIndex],
                    Math.min(left[leftSecondIndex], right[rightThirdIndex]));
            }
        }

        int leftMidIndex1 = midIndex(leftStartIndex, leftEndIndex);
        int leftMidIndex2 = leftSize % 2 != 0 ? leftMidIndex1 : leftMidIndex1 +1;

        double leftMedian = median(left, leftStartIndex, leftEndIndex);
        double rightMedian = median(right, rightStartIndex, rightEndIndex);

        //
        // If the left median is less or equal than the right median,
        //
        // then the result is at:
        // left[leftMidIndex...leftEndIndex] right[rightStartIndex...rightEndIndex - numberOfRemovedElements]
        //
        // otherwise, the result is at:
        // left[leftStartIndex...leftMidIndex] right[rightStartIndex + numberOfRemovedElements ...rightEndIndex]
        //
        if (leftMedian <= rightMedian) {
            int numberOfRemovedElements = indexesSize(leftStartIndex, leftMidIndex1 - 1);

            return this.median(
                left, leftMidIndex1, leftEndIndex,
                right, rightStartIndex, rightEndIndex - numberOfRemovedElements);
        }
        else {
            int numberOfRemovedElements = indexesSize(leftMidIndex2 + 1, leftEndIndex);

            return this.median(
                left, leftStartIndex, leftMidIndex2,
                right, rightStartIndex + numberOfRemovedElements, rightEndIndex);
        }
    }

    /**
     * Gets the median of values.
     */
    private double median(int[] values) {
        return this.median(values, 0, values.length - 1);
    }

    /**
     * Gets the median of values.
     */
    private double median(int[] values, int startIndex, int endIndex) {
        assert(startIndex >= 0 && startIndex < values.length);
        assert(endIndex >= startIndex && endIndex < values.length);

        int length = indexesSize(startIndex, endIndex);

        if (length % 2 == 0) {
            IPair<Integer, Integer> medians = this.medianValues(values, startIndex, endIndex);
            return (double)(medians.first() + medians.second()) / 2.0;
        }
        else {
            return this.medianValue(values, startIndex, endIndex);
        }
    }

    /**
     * Gets the median of value of an array with an odd length.
     */
    private int medianValue(int[] values, int startIndex, int endIndex) {
        assert(startIndex >= 0 && startIndex < values.length);
        assert(endIndex >= startIndex && endIndex < values.length);
        assert(indexesSize(startIndex, endIndex) % 2 == 1);

        int midIndex = midIndex(startIndex, endIndex);

        return values[midIndex];
    }

    /**
     * Gets the median values of an array with an even length.
     */
    private IPair<Integer, Integer> medianValues(int[] values, int startIndex, int endIndex) {
        assert(startIndex >= 0 && startIndex < values.length);
        assert(endIndex >= startIndex && endIndex < values.length);
        assert(indexesSize(startIndex, endIndex) % 2 == 0);

        int midIndex1 = midIndex(startIndex, endIndex);
        int midIndex2 = midIndex1 + 1;

        return Pair.make(values[midIndex1], values[midIndex2]);
    }

    /**
     * Gets the median of two values.
     */
    private double medianOf(int value1, int value2) {
        return (double)(value1 + value2) / 2.0;
    }

    /**
     * Gets the median of three values, by implementing bubble sort inline.
     */
    private double medianOf(int value1, int value2, int value3) {
        int first = value1;
        int second = value2;
        int third = value3;

        //
        // Position the third value...
        //
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }

        if (second > third) {
            int temp = second;
            second = third;
            third = temp;
        }

        assert(third >= first && third >= second);

        //
        // Position the second value...
        //
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }

        assert(second >= first);

        return second;
    }

    /**
     * Gets the median of four values, by implementing bubble sort inline.
     */
    private double medianOf(int value1, int value2, int value3, int value4) {
        int first = value1;
        int second = value2;
        int third = value3;
        int fourth = value4;

        //
        // Position the forth value...
        //
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }

        if (second > third) {
            int temp = second;
            second = third;
            third = temp;
        }

        if (third > fourth) {
            int temp = third;
            third = fourth;
            fourth = temp;
        }

        assert(fourth >= first && fourth >= second && fourth >= third);

        //
        // Position the third value...
        //
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }

        if (second > third) {
            int temp = second;
            second = third;
            third = temp;
        }

        assert(third >= first && third >= second);

        //
        // Position the second value...
        //
        if (first > second) {
            int temp = first;
            first = second;
            second = temp;
        }

        assert(second >= first);

        return (double)(second + third) / 2.0;
    }

    private static int midIndex(int startIndex, int endIndex) {
        return startIndex + ((endIndex - startIndex) >> 1);
    }

    private static int indexesSize(int startIndex, int endIndex) {
        return startIndex <= endIndex ? endIndex - startIndex + 1 : 0;
    }
}
