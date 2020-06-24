package base.core;

/**
 * The Dimensions class implements complementary APIs for dimensions.
 */
public final class Dimensions {
    /**
     * Gets the length of a dimension.
     */
    public static int length(int startIndex, int endIndex) {
        if (startIndex > endIndex) {
            return 0;
        }

        return endIndex - startIndex + 1;
    }

    /**
     * The Dimensions constructor - Disables the default constructor.
     */
    private Dimensions() {
    }
}
