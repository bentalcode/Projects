package base.interfaces;

/**
 * The IPair interface defines a pair.
 */
public interface IPair<Type1, Type2> {
    /**
     * Gets the first value.
     */
    Type1 first();

    /**
     * Gets the second value.
     */
    Type2 second();
}
