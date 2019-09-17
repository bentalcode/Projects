package datastructures.list.core;

import datastructures.list.interfaces.IListData;
import java.util.List;

/**
 * The ListData class implements the data of a list.
 */
public final class ListData<TValue extends Comparable<TValue>> implements IListData<TValue> {
    private final Class<TValue> classType;
    private final List<TValue> creationData;
    private final List<TValue> data;

    /**
     * The ListData constructor.
     */
    public ListData(
        Class<TValue> classType,
        List<TValue> creationData,
        List<TValue> data) {

        this.classType = classType;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    public Class<TValue> getClassType() {
        return this.classType;
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
