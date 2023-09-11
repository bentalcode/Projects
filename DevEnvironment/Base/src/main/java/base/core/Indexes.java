package base.core;

/**
 * The Indexes class implements complementary APIs for indexes.
 */
public final class Indexes {
    /**
     * Validates an index.
     */
    public static void validateIndex(int index, int startIndex, int endIndex) {
        Conditions.validate(
            index >= startIndex && index <= endIndex,
            "The index: " + index + " is out of bound." +
            "The specified range is: " + Range.make(startIndex, endIndex));
    }

    /**
     * Gets the number of indexes in a dimension.
     */
    public static int size(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    /**
     * Gets the number of indexes in a dimension.
     */
    public static long size(long startIndex, long endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    /**
     * This is a static class - Disables the default constructor.
     */
    private Indexes() {
    }
}
