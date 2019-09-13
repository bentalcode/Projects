package datastructures.trie.interfaces;

import base.interfaces.IVisitor;

/**
 * The ITrieTraversal interface defines various traversals of a trie.
 */
public interface ITrieTraversal<TKey extends Comparable<TKey>, TValue> {
    /**
     * Performs a Breadth-First search.
     */
    void breadthFirstSearch(
        ITrieNode<TKey, TValue> root,
        IVisitor<ITrieNode<TKey, TValue>> visitor);

    /**
     * Performs a Depth-First search.
     */
    void depthFirstSearch(
        ITrieNode<TKey, TValue> root,
        IVisitor<ITrieNode<TKey, TValue>> visitor);
}
