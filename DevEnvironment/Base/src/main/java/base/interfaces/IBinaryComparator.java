package base.interfaces;

/**
 * The IBinaryComparator interface defines a binary comparator.
 */
public interface IBinaryComparator<T> extends IHashCodeProvider<T>, IEquatableComparator<T>, IComparableComparator<T> {
    /**
     * Converts the comparator to the native one.
     */
    java.util.Comparator<T> toComparator();
}
