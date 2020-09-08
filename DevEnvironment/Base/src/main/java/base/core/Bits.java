package base.core;

import base.interfaces.IPrimitiveSize;

/**
 * The Bits class implements complementary APIs for bits.
 */
public final class Bits {
    /**
     * Converts an integer to a bit value: one or zero.
     */
    public static int bitValue(int bitValue) {
        return (bitValue != 0) ? 1 : 0;
    }

    /**
     * Checks whether the bit is on.
     */
    public static boolean isOn(int bitValue) {
        return bitValue != 0;
    }

    /**
     * Checks whether the bit is off.
     */
    public static boolean isOff(int bitValue) {
        return bitValue == 0;
    }

    /**
     * Verifies that value of a bit is valid: one or zero.
     */
    public static boolean isBitValue(int bitValue) {
        return bitValue == 0 || bitValue == 1;
    }

    /**
     * Turns on a bit at the specified index.
     */
    public static int turnOn(int value, int index) {
        validateIndex(index);

        int mask = 1 << index;
        return value | mask;
    }

    /**
     * Turns off a bit at the specified index.
     */
    public static int turnOff(int value, int index) {
        validateIndex(index);

        int mask = ~(1 << index);
        return value & mask;
    }

    /**
     * Checks whether a bit at the specified index is on.
     */
    public static boolean isOn(int value, int index) {
        return get(value, index) != 0;
    }

    /**
     * Checks whether a bit at the specified index is off.
     */
    public static boolean isOff(int value, int index) {
        return get(value, index) == 0;
    }

    /**
     * Sets a value of a bit at the specified index.
     */
    public static int set(int value, int index, int bitValue) {
        return isOn(bitValue) ? turnOn(value, index) : turnOff(value, index);
    }

    /**
     * Gets a value of a bit at the specified index.
     */
    public static int get(int value, int index) {
        validateIndex(index);

        int mask = 1 << index;
        return (value & mask) != 0 ? 1 : 0;
    }

    /**
     * Flips the value of a bit.
     */
    public static int flip(int bit) {
        assert(isBitValue(bit));
        return bit ^ 1;
    }

    /**
     * Sets the bit at the specified index to the complement of its current value.
     */
    public static int flip(int value, int index) {
        validateIndex(index);

        int mask = 1 << index;

        return value ^ mask;
    }

    /**
     * Validates the index.
     */
    private static void validateIndex(int index) {
        Indexes.validateIndex(index, 0, IPrimitiveSize.InBits.IntegerSize - 1);
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private Bits() {
    }
}
