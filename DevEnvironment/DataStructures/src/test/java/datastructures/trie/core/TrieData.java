package datastructures.trie.core;

import datastructures.node.interfaces.IKeyValueNode;
import datastructures.trie.interfaces.ITrieData;
import java.util.List;

/**
 * The TrieData class implements the data of a trie.
 */
public final class TrieData<TKey extends Comparable<TKey>> implements ITrieData<TKey> {
    private final List<List<TKey>> creationData;
    private final List<IKeyValueNode<TKey, Boolean>> data;

    /**
     * The TrieData constructor.
     */
    public TrieData(
        List<List<TKey>> creationData,
        List<IKeyValueNode<TKey, Boolean>> data) {

        this.creationData = creationData;
        this.data = data;
    }

    /**
     * Gets the creation data of a trie.
     */
    @Override
    public List<List<TKey>> getCreationData() {
        return this.creationData;
    }

    /**
     * Gets the data of a trie.
     */
    @Override
    public List<IKeyValueNode<TKey, Boolean>> getData() {
        return this.data;
    }
}
