package datastructures.dimentions.core;

import base.core.Conditions;
import datastructures.dimentions.interfaces.IDirection;
import datastructures.dimentions.interfaces.IDirections;
import java.util.Iterator;
import java.util.List;

/**
 * The Directions class implements 2D directions.
 */
public final class Directions implements IDirections {
    private static List<IDirection> DefaultDirections = List.of(
        new Direction(0.0), new Direction(45), new Direction(90),
        new Direction(135), new Direction(180), new Direction(225),
        new Direction(270), new Direction(315));

    private final List<IDirection> directions;
    private int index;

    /**
     * The Directions constructor.
     */
    public Directions() {
        this(Directions.DefaultDirections);
    }

    /**
     * The Directions constructor.
     */
    public Directions(List<IDirection> directions) {
        Conditions.validateNotNull(
            directions,
            "The directions.");

        this.directions = directions;
    }

    /**
     * Gets an iterator for iterating over a collection.
     */
    @Override
    public Iterator<IDirection> iterator() {
        this.index = 0;
        return this;
    }

    /**
     * Checks whether there is a next direction.
     */
    @Override
    public boolean hasNext() {
        return this.index < this.directions.size();
    }

    /**
     * Gets the next direction.
     */
    @Override
    public IDirection next() {
        IDirection currDirection = this.directions.get(this.index);
        ++this.index;

        return currDirection;
    }

    /**
     * Removes the current direction.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException();
    }
}
