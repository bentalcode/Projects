package algorithms.core;

import base.core.Conditions;
import java.util.Objects;

/**
 * The CollectionMajority class implements a collection majority logic.
 */
public final class CollectionMajority {

    /**
     * Gets a majority value in an array with O(N) and O(1) memory.
     */
    public static Integer getMajorityValue(int[] values) {
        Conditions.validateNotNull(
            values,
            "The array of values.");

        if (values.length == 0) {
            return null;
        }

        int candidate = findCandidate(values);

        return majority(values, candidate) ? candidate : null;
    }

    /**
     * Gets a majority value in a generic array with O(N) and O(1) memory.
     */
    public static <T> T getMajorityValue(T[] values) {
        Conditions.validateNotNull(
            values,
            "The array of values.");

        if (values.length == 0) {
            return null;
        }

        T candidate = findCandidate(values);

        return majority(values, candidate) ? candidate : null;
    }

    /**
     * Finds a candidate for a majority value in an array.
     */
    private static int findCandidate(int[] values) {
        assert(values != null && values.length != 0);

        int candidate = 0;
        int counter = 0;

        for (int value : values) {
            if (counter == 0) {
                candidate = value;
            }

            if (value == candidate) {
                ++counter;
            }
            else {
                --counter;
            }
        }

        return candidate;
    }

    /**
     * Finds a candidate for a majority value in an array.
     */
    private static <T> T findCandidate(T[] values) {
        assert(values != null && values.length != 0);

        T candidate = null;
        int counter = 0;

        for (T value : values) {
            if (counter == 0) {
                candidate = value;
            }

            if (Objects.equals(value, candidate)) {
                ++counter;
            }
            else {
                --counter;
            }
        }

        return candidate;
    }

    /**
     * Checks if a value is a majority in an array.
     */
    private static boolean majority(int[] values, int value) {
        assert(values != null);

        if (values.length == 0) {
            return false;
        }

        int counter = 0;

        for (int currValue : values) {
            if (currValue == value) {
                ++counter;
            }
        }

        return counter > values.length / 2;
    }

    /**
     * Checks if a value is a majority in an array.
     */
    private static <T> boolean majority(T[] values, T value) {
        assert(values != null);

        if (values.length == 0) {
            return false;
        }

        int counter = 0;

        for (T currValue : values) {
            if (Objects.equals(currValue, value)) {
                ++counter;
            }
        }

        return counter > values.length / 2;
    }

    /**
     * Disables the default constructor - This is a static class.
     */
    private CollectionMajority() {
    }
}
