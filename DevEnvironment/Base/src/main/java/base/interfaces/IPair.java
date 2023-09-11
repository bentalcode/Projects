package base.interfaces;

/**
 * The IPair interface defines a pair.
 */
public interface IPair<Type1, Type2> {
    /**
     * Gets first element.
     */
    Type1 first();

    /**
     * Gets second element.
     */
    Type2 second();
}
