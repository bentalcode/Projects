package datastructures.trie.interfaces;

import java.util.List;

/**
 * The ITrieTestData interface defines the data of the tests of a trie.
 */
public interface ITrieTestData {
    /**
     * Gets the data of tries.
     */
    List<ITrieData<Character>> getData();
}
