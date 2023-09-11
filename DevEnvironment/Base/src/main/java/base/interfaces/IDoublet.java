package base.interfaces;

/**
 * The IDoublet interface defines a doublet.
 * In quantum mechanics, a doublet is a mixed quantum state of a system with a spin of 1/2,
 * such that there are two allowed values of the spin component,
 * −1/2 and +1/2.
 * Quantum systems with two possible states are sometimes called two-level systems.
 */
public interface IDoublet<Type1 extends Comparable<Type1>, Type2 extends Comparable<Type2>> extends IUnaryComparator<IDoublet<Type1, Type2>> {
    /**
     * Gets the first value.
     */
    Type1 first();

    /**
     * Gets the second value.
     */
    Type2 second();
}
