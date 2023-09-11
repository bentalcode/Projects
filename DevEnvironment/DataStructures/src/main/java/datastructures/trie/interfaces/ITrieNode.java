package datastructures.trie.interfaces;

import base.interfaces.IIterator;
import base.interfaces.IReverseIterator;
import base.interfaces.IUnaryComparator;
import java.util.List;

/**
 * The ITrieNode interface defines a node of a trie.
 */
public interface ITrieNode<TKey extends Comparable<TKey>> extends IUnaryComparator<ITrieNode<TKey>> {
    /**
     * Gets a key of the node.
     */
    TKey getKey();

    /**
     * Returns whether this is an end node.
     */
    boolean isEndNode();

    /**
     * Gets children of the node.
     */
    List<ITrieNode<TKey>> getChildren();

    /**
     * Gets an iterator of children of the node.
     */
    IIterator<ITrieNode<TKey>> getChildrenIterator();

    /**
     * Gets a reverse iterator of children of the node.
     */
    IReverseIterator<ITrieNode<TKey>> getChildrenReverseIterator();

    /**
     * Adds a child to the node.
     */
    void addChild(ITrieNode<TKey> child);

    /**
     * Gets a specific child of the node.
     */
    ITrieNode<TKey> getChild(TKey key);

    /**
     * Checks whether a child exists.
     */
    boolean hasChild(TKey key);
}
