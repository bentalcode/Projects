package datastructures.trie.core;

import base.core.ListIterator;
import datastructures.core.TestData;
import datastructures.interfaces.ITestData;
import datastructures.trie.interfaces.ITrie;
import datastructures.trie.interfaces.ITrieData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

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
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests the creation logic of a trie.
     */
    @Test
    public void TrieCreationTest() {
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
            ListIterator.of(trieData.getData()),
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
