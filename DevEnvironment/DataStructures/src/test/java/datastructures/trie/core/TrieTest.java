package datastructures.trie.core;

import base.core.ListIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.trie.interfaces.ITrie;
import datastructures.trie.interfaces.ITrieData;
import java.util.List;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import org.junit.Test;

/**
 * The TrieTest class implements tests for a trie.
 */
public final class TrieTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The TrieTest constructor.
     */
    public TrieTest() {
    }

    /**
     * Tests the creation logic of a trie.
     */
    @Test
    public void trieCreationTest() {
        List<ITrieData<Character>> data = this.testData.getTrieData().getData();

        for (ITrieData<Character> trieData : data) {
            this.testCreation(trieData);
        }
    }

    /**
     * Tests the creation logic of a binary tree.
     */
    private void testCreation(ITrieData<Character> trieData) {
        ITrie<Character> trie = this.createTrie(trieData);

        this.assertion.assertEqualsWithIterators(
            trie.getIterator(),
            ListIterator.make(trieData.getData()),
            "Invalid creation logic of a trie.");
    }

    /**
     * Creates a trie from a list of words.
     */
    private ITrie<Character> createTrie(ITrieData<Character> trieData) {
        Trie.Builder<Character> trieBuilder = new Trie.Builder<>();

        for (List<Character> word : trieData.getCreationData()) {
            trieBuilder.addSequence(word);
        }

        return trieBuilder.build();
    }
}
