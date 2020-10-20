package base.core;

/**
 * The Dimensions class implements complementary APIs for dimensions.
 */
public final class Dimensions {
    /**
     * Gets the number of indexes in a dimension.
     */
    public static int indexes(int startIndex, int endIndex) {
        if (startIndex < 0 || endIndex < 0 || startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    /**
     * Gets the number of indexes in a dimension.
     */
    public static long indexes(long startIndex, long endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    /**
     * This is a static class - Disables the default constructor.
     */
    private Dimensions() {
    }
}
