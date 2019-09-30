package datastructures.trie.core;

import base.core.ArrayLists;
import datastructures.node.core.KeyValueNode;
import datastructures.node.interfaces.IKeyValueNode;
import datastructures.trie.interfaces.ITrieData;
import datastructures.trie.interfaces.ITrieTestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The TrieTestData class implements data of tests for a trie.
 */
public final class TrieTestData implements ITrieTestData {
    /**
     * The TrieTestData constructor.
     */
    public TrieTestData() {
    }

    /**
     * Gets the data of tries.
     */
    @Override
    public List<ITrieData<Character>> getData() {
        List<ITrieData<Character>> data = new ArrayList<>();

        data.add(this.getTrieData1());

        return data;
    }

    /**
     * Gets the data of trie1.
     */
    private ITrieData<Character> getTrieData1() {
        List<List<Character>> creationData = new ArrayList<>();

        creationData.add(ArrayLists.of('a'));
        creationData.add(ArrayLists.of('t', 'o'));
        creationData.add(ArrayLists.of('t', 'e', 'a'));
        creationData.add(ArrayLists.of('t', 'e', 'd'));
        creationData.add(ArrayLists.of('t', 'e', 'n'));
        creationData.add(ArrayLists.of('i', 'n', 'n'));
        creationData.add(ArrayLists.of('c', 'a', 't'));

        List<IKeyValueNode<Character, Boolean>> data = new ArrayList<>();
        data.add(KeyValueNode.of('a', true));
        data.add(KeyValueNode.of('c', false));
        data.add(KeyValueNode.of('a', false));
        data.add(KeyValueNode.of('t', true));
        data.add(KeyValueNode.of('t', false));
        data.add(KeyValueNode.of('e', false));
        data.add(KeyValueNode.of('a', true));
        data.add(KeyValueNode.of('d', true));
        data.add(KeyValueNode.of('n', true));
        data.add(KeyValueNode.of('o', true));
        data.add(KeyValueNode.of('i', false));
        data.add(KeyValueNode.of('n', false));
        data.add(KeyValueNode.of('n', true));

        return new TrieData<>(
            creationData,
            data);
    }
}
