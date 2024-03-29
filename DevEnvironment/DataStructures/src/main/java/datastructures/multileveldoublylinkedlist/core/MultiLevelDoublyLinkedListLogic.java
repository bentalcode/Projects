package datastructures.multileveldoublylinkedlist.core;

import base.core.Conditions;
import base.core.Position;
import base.interfaces.IPosition;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedList;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListLogic;
import datastructures.multileveldoublylinkedlist.interfaces.IMultiLevelDoublyLinkedListNode;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Stack;

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
        currLevelHeads.add(this.list.getHead());

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
    public void flatten() {
        IMultiLevelDoublyLinkedListNode<T> currNode = this.list.getHead();

        IMultiLevelDoublyLinkedListNode<T> tailNode = getTail(currNode);

        while (currNode != null) {
            if (currNode.child() != null) {
                connect(tailNode, currNode.child());

                currNode.setChild(null);

                tailNode = getTail(tailNode);
            }

            currNode = currNode.next();
        }
    }

    /**
     * Flatten a multi-level doubly linked list by vertical levels.
     */
    @Override
    public void flattenByVerticalLevels() {
        IMultiLevelDoublyLinkedListNode<T> currNode = this.list.getHead();

        Queue<IMultiLevelDoublyLinkedListNode<T>> queue = new LinkedList<>();

        while (currNode != null) {
            if (currNode.next() != null) {
                queue.offer(currNode.next());
            }

            if (currNode.child() != null) {
                connect(currNode, currNode.child());
                currNode.setChild(null);
            }
            else if (!queue.isEmpty()) {
                IMultiLevelDoublyLinkedListNode<T> nextNode = queue.poll();
                connect(currNode, nextNode);
            }

            currNode = currNode.next();
        }
    }

    /**
     * Flatten a multi-level doubly linked list by depth levels.
     */
    public void flattenByDepthLevels() {
        IMultiLevelDoublyLinkedListNode<T> currNode = this.list.getHead();

        Stack<IMultiLevelDoublyLinkedListNode<T>> stack = new Stack<>();

        while (currNode != null) {
            if (currNode.child() != null) {
                if (currNode.next() != null) {
                    stack.push(currNode.next());
                }

                connect(currNode, currNode.child());
                currNode.setChild(null);
            }
            else if (currNode.next() == null && !stack.empty()) {
                IMultiLevelDoublyLinkedListNode<T> nextNode = stack.pop();
                connect(currNode, nextNode);
            }

            currNode = currNode.next();
        }
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

    /**
     * Gets the tail of a list.
     */
    private static <T extends Comparable<T>> IMultiLevelDoublyLinkedListNode<T> getTail(IMultiLevelDoublyLinkedListNode<T> node) {
        if (node == null) {
            return null;
        }

        IMultiLevelDoublyLinkedListNode<T> currNode = node;

        while (currNode.next() != null) {
            currNode = currNode.next();
        }

        return currNode;
    }

    /**
     * Connects nodes.
     */
    private static <T extends Comparable<T>> void connect(
        IMultiLevelDoublyLinkedListNode<T> left,
        IMultiLevelDoublyLinkedListNode<T> right) {

        if (left != null) {
            left.setNext(right);
        }

        if (right != null) {
            right.setPrevious(left);
        }
    }
}