package base.core;

import base.interfaces.ITriple;

/**
 * The Triple class implements a triple.
 */
public final class Triple<Type1, Type2, Type3> implements ITriple<Type1, Type2, Type3> {
    private final Type1 first;
    private final Type2 second;
    private final Type3 third;

    /**
     * The Pair constructor.
     */
    public Triple(Type1 first, Type2 second, Type3 third) {
        this.first = first;
        this.second = second;
        this.third = third;
    }

    /**
     * Gets the first value.
     */
    @Override
    public Type1 first() {
        return this.first;
    }

    /**
     * Gets the second value.
     */
    @Override
    public Type2 second() {
        return this.second;
    }

    /**
     * Gets the third value.
     */
    @Override
    public Type3 third() {
        return this.third;
    }
}
