package base.interfaces;

/**
 * The ICircularString interface defines a circular string.
 */
public interface ICircularArray<T extends Comparable<T>> extends
    IUnaryComparator<ICircularArray<T>>,
    IIterable<T>,
    IReverseIterable<T> {

    /**
     * Gets the start index.
     */
    int getStartIndex();

    /**
     * Gets the value of an index.
     */
    T get(int index);

    /**
     * Gets the length of an array.
     */
    int length();

    /**
     * Checks whether an array is empty.
     */
    boolean empty();
}
