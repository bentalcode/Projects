package datastructures.binarytree.interfaces;

import base.interfaces.IIterator;
import base.interfaces.ISkipIterator;

/**
 * The IBinaryTreeNodeIterator interface defines an iterator of binary nodes.
 */
public interface IBinaryTreeNodeIterator<T> extends IIterator<T>, ISkipIterator<T> {
}
