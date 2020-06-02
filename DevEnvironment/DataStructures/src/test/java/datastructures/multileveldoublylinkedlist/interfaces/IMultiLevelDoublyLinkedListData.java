package datastructures.multileveldoublylinkedlist.interfaces;

import base.interfaces.IMatrix;
import base.interfaces.ITriple;
import java.util.List;

/**
 * The IMultiLevelDoublyLinkedListData interface defines the data of a multi-level doubly linked list.
 */
public interface IMultiLevelDoublyLinkedListData<T extends Comparable<T>> {
    /**
     * Gets the creation data of the multi-level doubly linked list.
     */
    ITriple<IMatrix<T>, boolean[][], boolean[][]> getCreationData();

    /**
     * Gets the actual data of the multi-level doubly linked list (By levels).
     */
    List<IMultiLevelDoublyLinkedListNode<T>> getData();

    /**
     * Gets the actual values of the multi-level doubly linked list (By levels).
     */
    List<T> getValues();
}
