package datastructures.binarytree.interfaces;

import base.interfaces.IIterator;
import base.interfaces.ISkipIterator;

/**
 * The IBinaryTreeNodeIterator interface defines an iterator of binary tree nodes.
 */
public interface IBinaryTreeNodeIterator<T> extends IIterator<T> {
    /**
     * Gets the skip iterator.
     */
    ISkipIterator<T> getSkipIterator();
}
