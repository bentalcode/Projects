package datastructures.list.interfaces;

/**
 * The IArrayList interface defines a dynamic array (resizable array).
 */
public interface IArrayList<T extends Comparable<T>> extends IList<T> {
    /**
     * Trims to size.
     */
    void trimToSize();
}
