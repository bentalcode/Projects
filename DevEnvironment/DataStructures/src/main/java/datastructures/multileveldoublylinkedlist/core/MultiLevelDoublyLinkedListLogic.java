package datastructures.multileveldoublylinkedlist.core;

import base.core.Conditions;
import base.core.Position;
import base.interfaces.IPosition;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedList;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListLogic;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import java.util.ArrayList;
import java.util.List;

/**
 * The MultiLevelDoublyLinkedListLogic class implements logic of a multi-level doubly linked list.
 */
public final class MultiLevelDoublyLinkedListLogic<T extends Comparable<T>>
    implements IMultiLevelDoublyLinkedListLogic<T> {

    private final IMultiLevelDoublyLinkedList<T> list;

    /**
     * The MultiLevelDoublyLinkedListLogic constructor.
     */
    public MultiLevelDoublyLinkedListLogic(IMultiLevelDoublyLinkedList<T> list) {
        Conditions.validateNotNull(
            list,
            "The multi-level linked list");

        this.list = list;
    }

    /**
     * Gets the levels of a multi-level doubly linked list.
     */
    @Override
    public List<List<T>> getLevels() {
        List<List<T>> result = new ArrayList<>();

        List<IMultiLevelDoublyLinkedListNode<T>> currLevelHeads = new ArrayList<>();
        currLevelHeads.add(list.getHead());

        getLevels(currLevelHeads, result);

        return result;
    }

    /**
     * Gets the vertical levels of a multi-level doubly linked list.
     */
    @Override
    public List<List<T>> getVerticalLevels() {
        List<List<T>> result = new ArrayList<>();

        IPosition position = Position.origin();
        setVerticalLevels(this.list.getHead(), position, result);

        return result;
    }

    /**
     * Flatten a multi-level doubly linked list by levels.
     */
    @Override
    public IMultiLevelDoublyLinkedList<T> flatten() {
        return null;
    }

    /**
     * Flatten a multi-level doubly linked list by vertical levels.
     */
    @Override
    public IMultiLevelDoublyLinkedList<T> flattenByVerticalLevels() {
        return null;
    }

    /**
     * Gets the levels of a multi-level doubly linked list.
     */
    private static <T extends Comparable<T>> void getLevels(
        List<IMultiLevelDoublyLinkedListNode<T>> currLevelHeads,
        List<List<T>> result) {

        if (currLevelHeads.isEmpty()) {
            return;
        }

        List<T> currLevel = new ArrayList<>();
        List<IMultiLevelDoublyLinkedListNode<T>> nextLevelHeads = new ArrayList<>();

        for (IMultiLevelDoublyLinkedListNode<T> currHead : currLevelHeads) {
            IMultiLevelDoublyLinkedListNode<T> currNode = currHead;

            while (currNode != null) {
                currLevel.add(currNode.getValue());

                if (currNode.child() != null) {
                    nextLevelHeads.add(currNode.child());
                }

                currNode = currNode.next();
            }
        }

        result.add(currLevel);

        getLevels(nextLevelHeads, result);
    }

    /**
     * Sets vertical levels.
     */
    private static <T extends Comparable<T>> void setVerticalLevels(
        IMultiLevelDoublyLinkedListNode<T> currNode,
        IPosition currPosition,
        List<List<T>> result) {

        if (currNode == null) {
            return;
        }

        int currCol = currPosition.getColumn();

        List<T> currLevel;

        if (currCol == result.size()) {
            currLevel = new ArrayList<>();
            result.add(currLevel);
        }
        else {
            currLevel = result.get(currCol);
        }

        currLevel.add(currNode.getValue());

        if (currNode.next() != null) {
            IPosition rightPosition = Position.add(currPosition, 0, 1);
            setVerticalLevels(
                currNode.next(),
                rightPosition,
                result);
        }

        if (currNode.child() != null) {
            IPosition bottomPosition = Position.add(currPosition, 1, 0);
            setVerticalLevels(
                currNode.child(),
                bottomPosition,
                result);
        }
    }
}