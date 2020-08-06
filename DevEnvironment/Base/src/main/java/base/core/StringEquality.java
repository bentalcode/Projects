package base.core;

/**
 * The StringEquality class implements complementary APIs for string equality.
 */
public final class StringEquality {
    /**
     * Checks whether strings are equals with start and end indexes.
     */
    public static boolean equals(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether strings are equals with start and end indexes. (Ignore case)
     */
    public static boolean equalsIgnoreCase(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether strings are equals with start index and length.
     */
    public static boolean equals(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Checks whether strings are equals with start index and length. (Ignore case)
     */
    public static boolean equalsIgnoreCase(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Checks whether buffer strings are equals with start and end indexes.
     */
    public static boolean equals(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether buffer strings are equals with start and end indexes. (Ignore case)
     */
    public static boolean equalsIgnoreCase(
        char[] left,
        int leftStartIndex,
        int leftEndIndex,
        char[] right,
        int rightStartIndex,
        int rightEndIndex) {

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether buffer strings are equals with start index.
     */
    public static boolean equals(
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

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            false);
    }

    /**
     * Checks whether buffer strings are equals with start index. (Ignore case)
     */
    public static boolean equalsIgnoreCase(
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

        return equals(
            left, leftStartIndex, leftEndIndex,
            right, rightStartIndex, rightEndIndex,
            true);
    }

    /**
     * Checks whether buffer strings are equals with start index and length.
     */
    public static boolean equals(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            false);
    }

    /**
     * Checks whether buffer strings are equals with start index and length. (Ignore case)
     */
    public static boolean equalsIgnoreCase(
        char[] left,
        int leftStartIndex,
        char[] right,
        int rightStartIndex,
        int length) {

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            true);
    }

    /**
     * Checks whether strings are equals with start and end indexes.
     */
    private static boolean equals(
        String left,
        int leftStartIndex,
        int leftEndIndex,
        String right,
        int rightStartIndex,
        int rightEndIndex,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return true;
        }

        if (left == null || right == null) {
            return false;
        }

        return equals(
            left.toCharArray(), leftStartIndex, leftEndIndex,
            right.toCharArray(), rightStartIndex, rightEndIndex,
            ignoreCase);
    }

    /**
     * Checks whether strings are equals with start index and length.
     */
    private static boolean equals(
        String left,
        int leftStartIndex,
        String right,
        int rightStartIndex,
        int length,
        boolean ignoreCase) {

        if (left == null && right == null) {
            return true;
        }

        if (left == null || right == null) {
            return false;
        }

        return equals(
            left.toCharArray(), leftStartIndex,
            right.toCharArray(), rightStartIndex,
            length,
            ignoreCase);
    }

    /**
     * Checks whether buffer strings are equals with start and end indexes.
     */
    private static boolean equals(
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

        int leftLength = Dimensions.length(leftStartIndex, leftEndIndex);
        int rightLength = Dimensions.length(rightStartIndex, rightEndIndex);

        if (leftLength != rightLength) {
            return false;
        }

        int length = leftLength;

        return equals(
            left, leftStartIndex,
            right, rightStartIndex,
            length,
            ignoreCase);
    }

    /**
     * Checks whether buffer strings are equals with start index and length.
     */
    private static boolean equals(
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

            if (leftValue != rightValue) {
                return false;
            }

            ++leftIndex;
            ++rightIndex;
            ++counter;
        }

        return counter == length;
    }

    /**
     * The StringEquality constructor - Disables the default constructor.
     */
    private StringEquality() {
    }
}
