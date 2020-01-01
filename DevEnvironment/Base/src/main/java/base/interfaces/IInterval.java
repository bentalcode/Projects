package base.interfaces;

/**
 * The IInterval interface defines an interval.
 */
public interface IInterval<Type extends Comparable<Type>> extends IUnaryComparator<IInterval<Type>> {
    /**
     * Gets the start point of an interval.
     */
    Type start();

    /**
     * Gets the end point of an interval.
     */
    Type end();
}
