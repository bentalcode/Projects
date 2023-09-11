package datastructures.binarytree.interfaces;

import base.interfaces.IReverseIterator;
import base.interfaces.ISkipIterator;

/**
 * The IBinaryTreeNodeReverseIterator interface defines a reverse iterator of binary nodes.
 */
public interface IBinaryTreeNodeReverseIterator<T> extends IReverseIterator<T> {
    /**
     * Gets the skip iterator.
     */
    ISkipIterator<T> getSkipIterator();
}
