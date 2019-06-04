package datastructures.tree.interfaces;

import base.interfaces.IUnaryComparator;
import datastructures.node.interfaces.INode;

import java.util.List;

/**
 * The ITreeLevel interface defines a level of a tree.
 */
public interface ITreeLevel<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITreeLevel<TKey, TValue>> {
    /**
     * Gets the data of nodes.
     */
    List<INode<TKey, TValue>> getNodesData();
}
