package base.interfaces;

/**
 * The ITriple interface defines a triple.
 */
public interface ITriple<Type1, Type2, Type3> {
    /**
     * Gets first value.
     */
    Type1 first();

    /**
     * Gets second value.
     */
    Type2 second();

    /**
     * Gets third value.
     */
    Type3 third();
}
