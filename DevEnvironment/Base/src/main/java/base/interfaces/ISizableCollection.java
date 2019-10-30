package base.interfaces;

/**
 * The ISizableCollection interface defines a sizable collection.
 */
public interface ISizableCollection extends ICollection {
    /**
     * Gets the size of the collection.
     */
    int size();

    /**
     * Checks whether the collection is empty.
     */
    boolean empty();
}
