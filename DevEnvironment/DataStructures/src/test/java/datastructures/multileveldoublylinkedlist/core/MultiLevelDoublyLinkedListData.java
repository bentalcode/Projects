package datastructures.multileveldoublylinkedlist.core;

import base.interfaces.IMatrix;
import base.interfaces.ITriple;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListData;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import java.util.List;

/**
 * The MultiLevelDoublyLinkedListData class implements the data of a list.
 */
public final class MultiLevelDoublyLinkedListData<T extends Comparable<T>> implements IMultiLevelDoublyLinkedListData<T> {
    private final ITriple<IMatrix<T>, boolean[][], boolean[][]> creationData;
    private final List<IMultiLevelDoublyLinkedListNode<T>> data;
    private final List<T> values;
    private final List<List<T>> levels;
    private final List<List<T>> verticalLevels;

    /**
     * The MultiLevelDoublyLinkedListData constructor.
     */
    public MultiLevelDoublyLinkedListData(
        ITriple<IMatrix<T>, boolean[][], boolean[][]> creationData,
        List<IMultiLevelDoublyLinkedListNode<T>> data,
        List<T> values,
        List<List<T>> levels,
        List<List<T>> verticalLevels) {

        this.creationData = creationData;
        this.data = data;
        this.values = values;
        this.levels = levels;
        this.verticalLevels = verticalLevels;
    }

    /**
     * Gets the creation data of a multi-level doubly linked list.
     */
    @Override
    public ITriple<IMatrix<T>, boolean[][], boolean[][]> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the actual data of a multi-level doubly linked list (By levels).
     */
    @Override
    public List<IMultiLevelDoublyLinkedListNode<T>> getData() {
        return this.data;
    }

    /**
     * Gets the actual values of the multi-level doubly linked list (By levels).
     */
    @Override
    public List<T> getValues() {
        return this.values;
    }

    /**
     * Gets the levels of a multi-level doubly linked list.
     */
    @Override
    public List<List<T>> getLevels() {
        return this.levels;
    }

    /**
     * Gets the vertical levels of a multi-level doubly linked list.
     */
    @Override
    public List<List<T>> getVerticalLevels() {
        return this.verticalLevels;
    }
}
