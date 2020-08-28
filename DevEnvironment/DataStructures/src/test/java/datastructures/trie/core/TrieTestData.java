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

        creationData.add(ArrayLists.make('a'));
        creationData.add(ArrayLists.make('t', 'o'));
        creationData.add(ArrayLists.make('t', 'e', 'a'));
        creationData.add(ArrayLists.make('t', 'e', 'd'));
        creationData.add(ArrayLists.make('t', 'e', 'n'));
        creationData.add(ArrayLists.make('i', 'n', 'n'));
        creationData.add(ArrayLists.make('c', 'a', 't'));

        List<IKeyValueNode<Character, Boolean>> data = new ArrayList<>();
        data.add(KeyValueNode.make('a', true));
        data.add(KeyValueNode.make('c', false));
        data.add(KeyValueNode.make('a', false));
        data.add(KeyValueNode.make('t', true));
        data.add(KeyValueNode.make('t', false));
        data.add(KeyValueNode.make('e', false));
        data.add(KeyValueNode.make('a', true));
        data.add(KeyValueNode.make('d', true));
        data.add(KeyValueNode.make('n', true));
        data.add(KeyValueNode.make('o', true));
        data.add(KeyValueNode.make('i', false));
        data.add(KeyValueNode.make('n', false));
        data.add(KeyValueNode.make('n', true));

        return new TrieData<>(
            creationData,
            data);
    }
}
