package datastructures.list.core;

import datastructures.list.interfaces.IList;
import datastructures.list.interfaces.ITwoDimensionalListData;

/**
 * The TwoDimensionalListData class implements the data of a two dimensional list.
 */
public final class TwoDimensionalListData<T extends Comparable<T>> implements ITwoDimensionalListData<T> {
    private final IList<IList<T>> creationData;
    private final IList<IList<T>> data;

    /**
     * The TwoDimensionalListData constructor.
     */
    public TwoDimensionalListData(
        IList<IList<T>> creationData,
        IList<IList<T>> data) {

        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the creation data.
     */
    @Override
    public IList<IList<T>> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the data.
     */
    @Override
    public IList<IList<T>> getData() {
        return this.data;
    }
}
