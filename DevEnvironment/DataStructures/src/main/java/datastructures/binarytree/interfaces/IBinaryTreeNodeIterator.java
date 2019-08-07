package datastructures.binarytree.interfaces;

import base.interfaces.IIterator;

/**
 * The IBinaryTreeNodeIterator interface defines an iterator of binary nodes.
 */
public interface IBinaryTreeNodeIterator<T> extends IIterator<T> {
    /*
     * Skips over end nodes.
     */
    void skipEndNodes();

    /*
     * Includes end nodes.
     */
    void includeEndNodes();
}
