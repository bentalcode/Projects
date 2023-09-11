package base.interfaces;

/**
 * The IMatch interface defines a match predicate.
 */
public interface IMatch<T> {
    /**
     * Checks whether an element is matching.
     */
    boolean match(T element);
}
