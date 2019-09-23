package datastructures.doublylinkedlist.core;

import datastructures.doublylinkedlist.interfaces.IListData;
import java.util.List;

/**
 * The ListData class implements the data of a list.
 */
public final class ListData<TValue extends Comparable<TValue>> implements IListData {
    private final List<TValue> creationData;
    private final List<TValue> data;

    /**
     * The ListData constructor.
     */
    public ListData(List<TValue> creationData, List<TValue> data) {
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<TValue> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the list.
     */
    @Override
    public List<TValue> getData() {
        return this.data;
    }
}
