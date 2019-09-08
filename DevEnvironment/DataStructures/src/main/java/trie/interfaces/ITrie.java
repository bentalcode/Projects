package trie.interfaces;

import base.interfaces.IBinaryComparator;
import base.interfaces.IUnaryComparator;

/**
 * The ITrie interface defines a trie.
 */
public interface ITrie<TKey extends Comparable<TKey>, TValue> extends IUnaryComparator<ITrie<TKey, TValue>> {
    /**
     * Gets a root of a trie.
     */
    ITrieNode<TKey, TValue> getRoot();

    /**
     * Sets a root of a trie.
     */
    void setRoot(ITrieNode<TKey, TValue> root);

    /**
     * Gets an interface of a trie traversal.
     */
    ITrieTraversal<TKey, TValue> getTrieTraversal();

    /**
     * Gets an interface of a trie traversal.
     */
    ITrieTraversal<TKey , TValue> getTrieTraversal(IBinaryComparator<ITrieNode<TKey, TValue>> nodeComparator);
}
