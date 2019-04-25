package base.core;

import base.interfaces.IPair;

/**
 * The Pair class implements a pair.
 */
public final class Pair<Type1, Type2> implements IPair<Type1, Type2> {
    private final Type1 first;
    private final Type2 second;
    
    /**
     * The Pair constructor.
     */
    public Pair(Type1 first, Type2 second) {
        this.first = first;
        this.second = second;
    }

    /**
     * Gets the first value.
     */
    @Override
    public Type1 first() {
        return this.first;
    }

    /**
     * Gets the first value.
     */
    @Override
    public Type2 second() {
        return this.second;
    }
}
