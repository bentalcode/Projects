package datastructures.binarytree.interfaces;

import base.interfaces.IIterator;

/**
 * The IBinaryTreeNodeIterator interface defines an iterator of binary nodes.
 */
public interface IBinaryTreeNodeIterator<T> extends IIterator<T> {
    /*
     * Skips over end nodes.
     * Returns the previous set status.
     */
    boolean skipEndNodes();

    /*
     * Includes end nodes.
     * Returns the previous set status.
     */
    boolean includeEndNodes();

    /*
     * Sets the status of skip end nodes.
     * Returns the previous configured status.
     */
    boolean setSkipEndNodesStatus(boolean status);
}