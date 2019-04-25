package base.interfaces;

/**
 * The ITriple interface defines a triple.
 */
public interface ITriple<Type1, Type2, Type3> {
    /**
     * Gets the first value.
     */
    Type1 first();

    /**
     * Gets the second value.
     */
    Type2 second();

    /**
     * Gets the third value.
     */
    Type3 third();
}
