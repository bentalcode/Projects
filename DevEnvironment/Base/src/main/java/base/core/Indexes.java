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
     * The Arrays constructor - Disables the default constructor.
     */
    private Indexes() {
    }
}
