package base.core;

/**
 * The StringEquality class implements complementary APIs for string equality.
 */
public final class StringComparable {
    /**
     * Compares strings with start and end indexes.
     */
    public static int compare(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Compares strings with start and end indexes. (Ignore case)
     */
    public static int compareIgnoreCase(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Compares strings are equals with start index and length.
     */
    public static int compare(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return compare(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Compares strings with start index and length. (Ignore case)
     */
    public static int compareIgnoreCase(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return compare(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Compares buffer strings with start and end indexes.
     */
    public static int compare(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Compares buffer strings with start and end indexes. (Ignore case)
     */
    public static int compareIgnoreCase(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Compares buffer strings with start index.
     */
    public static int compare(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);

        int leftEndIndex = left.length - 1;
        int rightEndIndex = right.length - 1;

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Compares buffer strings with start index. (Ignore case)
     */
    public static int compareIgnoreCase(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);

        int leftEndIndex = left.length - 1;
        int rightEndIndex = right.length - 1;

        return compare(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Compares buffer strings with start index and length.
     */
    public static int compare(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        return compare(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Compares buffer strings with start index and length. (Ignore case)
     */
    public static int compareIgnoreCase(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        return compare(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Compares strings with start and end indexes.
     */
    private static int compare(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return 0;
        }

        if (left == null) {
            return -1;
        }

        if (right == null) {
            return 1;
        }

        return compare(
            left.toCharArray(), leftStartIndex, leftEndIndex,
            right.toCharArray(), rightStartIndex, rightEndIndex,
            ignoreCase);
    }

    /**
     * Compares strings with start index and length.
     */
    private static int compare(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return 0;
        }

        if (left == null) {
            return -1;
        }

        if (right == null) {
            return 1;
        }

        return compare(
            left.toCharArray(), leftStartIndex,
            right.toCharArray(), rightStartIndex,
            length,
            ignoreCase);
    }

    /**
     * Compares buffer strings with start and end indexes.
     */
    private static int compare(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex,
        boolean ignoreCase) {

        assert(left != null);
        assert(right != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(leftEndIndex >= leftStartIndex && leftEndIndex < left.length);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);
        assert(rightEndIndex >= rightStartIndex && rightEndIndex < right.length);

        int leftLength = Indexes.size(leftStartIndex, leftEndIndex);
        int rightLength = Indexes.size(rightStartIndex, rightEndIndex);

        if (leftLength < rightLength) {
            return -1;
        }

        if (leftLength > rightLength) {
            return 1;
        }

        int length = leftLength;

        return compare(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            ignoreCase);
    }

    /**
     * Compares buffer strings with start index and length.
     */
    private static int compare(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length,
        boolean ignoreCase) {

        assert(left != null);
        assert(leftStartIndex >= 0 && leftStartIndex < left.length);
        assert(leftStartIndex + length - 1 < left.length);

        assert(right != null);
        assert(rightStartIndex >= 0 && rightStartIndex < right.length);
        assert(rightStartIndex + length - 1 < right.length);

        int leftIndex = leftStartIndex;
        int rightIndex = rightStartIndex;

        int counter = 0;
        while (counter < length && leftIndex < left.length && rightIndex < right.length) {
            char leftValue = left[leftIndex];
            char rightValue = right[rightIndex];

            if (ignoreCase) {
                leftValue = Character.toLowerCase(leftValue);
                rightValue = Character.toLowerCase(rightValue);
            }

            if (leftValue < rightValue) {
                return -1;
            }

            if (leftValue > rightValue) {
                return 1;
            }

            ++leftIndex;
            ++rightIndex;
            ++counter;
        }

        assert(counter == length);
        return 0;
    }

    /**
     * The StringComparable constructor - Disables the default constructor.
     */
    private StringComparable() {
    }
}
