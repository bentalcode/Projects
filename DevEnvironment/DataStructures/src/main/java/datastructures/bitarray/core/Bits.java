package datastructures.bitarray.core;

/**
 * The Bits class implements complementary APIs for bits.
 */
public final class Bits {
    /**
     * Converts the integer to a bit value: one or zero.
     */
    public static int bitValue(int bitValue) {
        return (bitValue != 0) ? 1 : 0;
    }

    /**
     * Checks whether the bit is one.
     */
    public static boolean isOne(int bitValue) {
        return bitValue != 0;
    }

    /**
     * Checks whether the bit is zero.
     */
    public static boolean isZero(int bitValue) {
        return bitValue == 0;
    }

    /**
     * Verifies that value of the bit is valid: one or zero.
     */
    public static boolean isBitValue(int bitValue) {
        return bitValue == 0 || bitValue == 1;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Bits() {
    }
}
