package datastructures.graph.interfaces;

import base.interfaces.IVisitor;

/**
 * The IGraphTraversal interface defines various traversals of a graph.
 */
public interface IGraphTraversal<TKey extends Comparable<TKey>, TValue> {
    /**
     * Performs a Breadth-First search.
     */
    void breadthFirstSearch(
        IVertex<TKey, TValue> vertex,
        IVisitor<IVertex<TKey, TValue>> visitor);

    /**
     * Performs a Depth-First search.
     */
    void depthFirstSearch(
        IVertex<TKey, TValue> vertex,
        IVisitor<IVertex<TKey, TValue>> visitor);
}
