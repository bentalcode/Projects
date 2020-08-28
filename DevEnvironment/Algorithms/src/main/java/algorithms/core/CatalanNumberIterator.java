package algorithms.core;

import algorithms.interfaces.ICatalanNumber;
import base.core.Conditions;
import base.interfaces.IIterator;

/**
 * The CatalanNumberIterator class implements an iterator of catalan numbers.
 */
public final class CatalanNumberIterator implements IIterator<Long> {
    private static final int initialNumber = 0;

    private final ICatalanNumber catalanNumber;
    private final int maxNumber = CatalanNumber.maxCalculatedNumber;
    private int currNumber;


    /**
     * Creates a new iterator of a catalan.
     */
    public static IIterator<Long> make(ICatalanNumber catalanNumber) {
        return new CatalanNumberIterator(catalanNumber, initialNumber);
    }

    /**
     * Creates a new iterator of a catalan.
     */
    public static IIterator<Long> make(ICatalanNumber catalanNumber, int currNumber) {
        return new CatalanNumberIterator(catalanNumber, currNumber);
    }

    /**
     * The CatalanNumberIterator constructor.
     */
    private CatalanNumberIterator(ICatalanNumber catalanNumber) {
        this(
            catalanNumber,
            initialNumber);
    }

    /**
     * The CatalanNumberIterator constructor.
     */
    private CatalanNumberIterator(ICatalanNumber catalanNumber, int currNumber) {
        Conditions.validateNotNull(
            catalanNumber,
            "The catalan number.");

        this.catalanNumber = catalanNumber;
        this.currNumber = currNumber;
        this.reset(currNumber);
    }

    /**
     * Checks whether there is a next element.
     */
    @Override
    public boolean hasNext() {
        return this.currNumber <= this.maxNumber;
    }

    /**
     * Gets the next element.
     */
    @Override
    public Long next() {
        assert(this.hasNext());

        long currCatalan = this.catalanNumber.calculateCatalan(this.currNumber);
        ++this.currNumber;

        return currCatalan;
    }

    /**
     * Resets the iterator.
     */
    @Override
    public void reset() {
        this.reset(initialNumber);
    }

    /**
     * Resets the iterator.
     */
    public void reset(int currNumber) {
        this.currNumber = currNumber;
    }
}
