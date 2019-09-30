package datastructures.trie.interfaces;

import datastructures.node.interfaces.IKeyValueNode;
import java.util.List;

/**
 * The ITrieData interface defines the data of a trie.
 */
public interface ITrieData<TKey extends Comparable<TKey>> {
    /**
     * Gets the creation data of a trie.
     */
    List<List<TKey>> getCreationData();

    /**
     * Gets the data of a trie.
     */
    List<IKeyValueNode<TKey, Boolean>> getData();
}
