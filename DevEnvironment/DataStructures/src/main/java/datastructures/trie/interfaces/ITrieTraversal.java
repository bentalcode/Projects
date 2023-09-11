package datastructures.trie.interfaces;

import base.interfaces.IVisitor;

/**
 * The ITrieTraversal interface defines various traversals of a trie.
 */
public interface ITrieTraversal<TKey extends Comparable<TKey>> {
    /**
     * Performs a Breadth-First search.
     */
    void breadthFirstSearch(
        ITrieNode<TKey> root,
        IVisitor<ITrieNode<TKey>> visitor);

    /**
     * Performs a Depth-First search.
     */
    void depthFirstSearch(
        ITrieNode<TKey> root,
        IVisitor<ITrieNode<TKey>> visitor);
}
