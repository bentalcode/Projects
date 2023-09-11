package datastructures.multileveldoublylinkedlist.interfaces;

import java.util.List;

/**
 * The IMultiLevelDoublyLinkedListLogic interface defines logic of a multi-level doubly linked list.
 */
public interface IMultiLevelDoublyLinkedListLogic<T extends Comparable<T>> {
    /**
     * Gets the levels of a multi-level doubly linked list.
     */
    List<List<T>> getLevels();

    /**
     * Gets the vertical levels of a multi-level doubly linked list.
     */
    List<List<T>> getVerticalLevels();

    /**
     * Flatten a multi-level doubly linked list by levels.
     */
    void flatten();

    /**
     * Flatten a multi-level doubly linked list by vertical levels.
     */
    void flattenByVerticalLevels();

    /**
     * Flatten a multi-level doubly linked list by depth levels.
     */
    void flattenByDepthLevels();
}