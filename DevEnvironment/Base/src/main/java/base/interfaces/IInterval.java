package base.interfaces;

/**
 * The IInterval interface defines an interval.
 */
public interface IInterval<Type extends Comparable<Type>> extends IUnaryComparator<IInterval<Type>> {
    /**
     * Gets a start point of an interval.
     */
    Type start();

    /**
     * Gets an end point of an interval.
     */
    Type end();
}
