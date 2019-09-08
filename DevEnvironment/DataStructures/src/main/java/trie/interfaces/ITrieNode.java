package trie.interfaces;

import base.interfaces.IUnaryComparator;

import java.util.Collection;
import java.util.List;
import java.util.Map;

/**
 * The ITrieNode interface defines a node in a trie.
 */
public interface ITrieNode<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITrieNode<TKey, TValue>> {
    /**
     * Gets the key of the node.
     */
    TKey getKey();

    /**
     * Gets the value of the node.
     */
    TValue getValue();

    /**
     * Sets the value of the node.
     */
    void setValue(TValue value);

    /**
     * Gets the children of the node.
     */
    Collection<ITrieNode<TKey, TValue>> getChildren();

    /**
     * Adds a child to the node.
     */
    void addChild(ITrieNode<TKey, TValue> child);

    /**
     * Adds a child of the node.
     */
    ITrieNode<TKey, TValue> getChild(TKey key);

    /**
     * Checks whether a child exists.
     */
    boolean hasChild(TKey key);
}
