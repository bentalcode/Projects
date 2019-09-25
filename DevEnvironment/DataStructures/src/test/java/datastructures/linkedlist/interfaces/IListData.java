package datastructures.linkedlist.interfaces;

import java.util.List;

/**
 * The IListData interface defines the data of a list.
 */
public interface IListData<TValue extends Comparable<TValue>> {
    /**
     * Gets the creation data.
     */
    List<TValue> getCreationData();

    /**
     * Gets the actual data of the list.
     */
    List<TValue> getData();
}
