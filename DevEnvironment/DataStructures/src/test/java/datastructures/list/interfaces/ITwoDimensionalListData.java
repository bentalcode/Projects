package datastructures.list.interfaces;

/**
 * The ITwoDimensionalListData interface defines the data of a two dimensional list.
 */
public interface ITwoDimensionalListData<T extends Comparable<T>> {
    /**
     * Gets the creation data.
     */
    IList<IList<T>> getCreationData();

    /**
     * Gets the data.
     */
    IList<IList<T>> getData();
}
