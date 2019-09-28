package datastructures.linkedlist.interfaces;

import java.util.List;

/**
 * The IListData interface defines the data of a list.
 */
public interface IListData<T extends Comparable<T>> {
    /**
     * Gets the creation data.
     */
    List<T> getCreationData();

    /**
     * Gets the actual data of the list.
     */
    List<T> getData();
}
