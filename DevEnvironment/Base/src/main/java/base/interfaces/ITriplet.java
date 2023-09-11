package base.interfaces;

/**
 * The ITriplet interface defines a triplet.
 * In quantum mechanics, a triplet is a quantum state of a system with a spin of quantum number s =1,
 * such that there are three allowed values of the spin component, ms = −1, 0, and +1.
 */
public interface ITriplet<Type1 extends Comparable<Type1>, Type2 extends Comparable<Type2>, Type3 extends Comparable<Type3>> extends IUnaryComparator<ITriplet<Type1, Type2, Type3>> {
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
