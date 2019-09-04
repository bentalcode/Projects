package base.interfaces;

/**
 * The ICircularString interface defines a circular string.
 */
public interface ICircularString extends IUnaryComparator<ICircularString>, IIterable<Character> {
    /**
     * Gets the start index.
     */
    int getStartIndex();

    /**
     * Gets the value of an index.
     */
    char charAt(int index);

    /**
     * Gets the length of a string.
     */
    int length();

    /**
     * Checks whether a string is empty.
     */
    boolean empty();
}
