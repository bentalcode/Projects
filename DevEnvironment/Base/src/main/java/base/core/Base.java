package base.core;

import base.interfaces.IBinaryComparator;

/**
 * The Base class implements complementary APIs for base objects.
 */
public final class Base {
    /**
     * Gets the min element with a comparator.
     */
    public static <Type extends Comparable<Type>> Type min(Type first, Type second) {
        IBinaryComparator<Type> comparator = Comparator.make();
        return Base.min(first, second, comparator);
    }

    /**
     * Gets the max element with a comparator.
     */
    public static <Type extends Comparable<Type>> Type max(Type first, Type second) {
        IBinaryComparator<Type> comparator = Comparator.make();
        return Base.max(first, second, comparator);
    }

    /**
     * Gets the min element with a comparator.
     */
    public static <Type extends Comparable<Type>> Type min(Type first, Type second, IBinaryComparator<Type> comparator) {
        int status = comparator.compareTo(first, second);
        return (status <= 0) ? first : second;
    }

    /**
     * Gets the max element with a comparator.
     */
    public static <Type extends Comparable<Type>> Type max(Type first, Type second, IBinaryComparator<Type> comparator) {
        int status = comparator.compareTo(first, second);
        return (status <= 0) ? second : first;
    }

    /**
     * The Base constructor - Disables the default constructor.
     */
    private Base() {
    }
}
