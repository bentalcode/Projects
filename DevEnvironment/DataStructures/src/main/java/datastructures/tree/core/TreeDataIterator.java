package datastructures.tree.core;

import base.core.Conditions;
import datastructures.tree.interfaces.ITreeDataIterator;
import datastructures.tree.interfaces.ITreeNodeData;
import java.util.Iterator;
import java.util.List;

/**
 * The TreeDataIterator class implements an iterator of data.
 */
public final class TreeDataIterator<TKey extends Comparable<TKey>, TValue> implements ITreeDataIterator<TKey, TValue> {

    private List<ITreeNodeData<TKey, TValue>> nodesData;
    private int currentIndex;

    /**
     * The TreeDataIterator constructor.
     */
    public TreeDataIterator(List<ITreeNodeData<TKey, TValue>> nodesData) {
        Conditions.validateNotNull(
            nodesData,
            "The nodes data of a tree can not be null.");

        this.nodesData = nodesData;
    }

    /**
     * Gets an iterator for iterating over data.
     */
    @Override
    public Iterator<ITreeNodeData<TKey, TValue>> iterator() {
        return this;
    }

    /**
     * Checks whether there is a next data.
     */
    @Override
    public boolean hasNext() {
        return this.currentIndex < this.nodesData.size();
    }

    /**
     * Gets the next data.
     */
    @Override
    public ITreeNodeData<TKey, TValue> next() {
        Conditions.validate(
            this.hasNext(),
            "The iterator has already reached the end of data of a tree.");

        ITreeNodeData<TKey, TValue> currNodeData = this.nodesData.get(this.currentIndex);
        ++this.currentIndex;

        return currNodeData;
    }

    /**
     * Removes the current data.
     */
    @Override
    public void remove() {
        throw new UnsupportedOperationException("Removing data from a tree is not supported.");
    }
}
