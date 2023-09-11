package datastructures.list.core;

import datastructures.list.interfaces.IListData;
import java.util.List;

/**
 * The ListData class implements the data of a list.
 */
public final class ListData<T extends Comparable<T>> implements IListData<T> {
    private final Class<T> classType;
    private final List<T> creationData;
    private final List<T> data;

    /**
     * The ListData constructor.
     */
    public ListData(
        Class<T> classType,
        List<T> creationData,
        List<T> data) {

        this.classType = classType;
        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the class type.
     */
    public Class<T> getClassType() {
        return this.classType;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public List<T> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of the list.
     */
    @Override
    public List<T> getData() {
        return this.data;
    }
}
