package datastructures.trie.interfaces;

import base.interfaces.IIterable;
import base.interfaces.IUnaryComparator;
import base.interfaces.ICollection;
import datastructures.node.interfaces.IKeyValueNode;

/**
 * The ITrie interface defines a trie.
 * A trie is a tree like data-structure where in the nodes of the sore the entire
 * alphabet, and strings/words can be retrieved by traversing down a branch path of the tree.
 */
public interface ITrie<TKey extends Comparable<TKey>> extends
    ICollection,
    IUnaryComparator<ITrie<TKey>>,
    IIterable<IKeyValueNode<TKey, Boolean>> {

    /**
     * Gets a root of a trie.
     */
    ITrieNode<TKey> getRoot();

    /**
     * Gets an interface of a trie traversal.
     */
    ITrieTraversal<TKey> getTrieTraversal();
}
