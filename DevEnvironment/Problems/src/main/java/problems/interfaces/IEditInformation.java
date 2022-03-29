package problems.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IEditInformation interface defines an information of a specific edit.
 */
public interface IEditInformation<T extends Comparable<T>> extends IUnaryComparator<IEditInformation<T>> {
    /**
     * Gets the type of edit.
     */
    EditType getType();

    /**
     * Gets the corresponding source value.
     */
    T getSrcValue();

    /**
     * Gets the corresponding destination value.
     */
    T getDestValue();
}
