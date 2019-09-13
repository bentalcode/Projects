package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import base.core.Conditions;
import base.interfaces.ICalculator;
import datastructures.graph.core.GraphBuilder;
import datastructures.graph.core.Vertex;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphBuilder;
import datastructures.graph.interfaces.IVertex;
import java.util.Collection;
import java.util.List;
import datastructures.trie.core.Trie;
import datastructures.trie.core.TrieNode;
import datastructures.trie.interfaces.ITrie;
import datastructures.trie.interfaces.ITrieNode;

/**
 * The AlphabeticalOrderCalculator class implements an aggregation result of the data.
 */
public final class AlphabeticalOrderCalculator implements ICalculator<IAlphabeticalOrderResults> {
    private final List<String> words;

    /**
     * The AlphabeticalOrderCalculator constructor.
     */
    public AlphabeticalOrderCalculator(List<String> words) {
        Conditions.validateNotNull(
            words,
            "The words of an alphabetical order.");

        this.words = words;
    }

    /**
     * Calculates the alphabetical order.
     */
    @Override
    public IAlphabeticalOrderResults calculate() {
        AlphabeticalOrderResults result = new AlphabeticalOrderResults();

        //
        // Create a trie from the words...
        //
        ITrie<Character, Boolean> wordsTrie = this.createTrie();

        //
        // Create a graph with the dependencies of the alphabet...
        //
        IGraph<Character, Void> alphabetGraph = this.createAlphabeticalOrderGraph(wordsTrie);

        //
        // Calculate the alphabetical order by performing a topological search...
        //
        List<IVertex<Character, Void>> alphabeticalOrder = alphabetGraph.getGraphLogic().topologicalSearch();

        for (IVertex<Character, Void> alphabetVertex : alphabeticalOrder) {
            result.add(alphabetVertex.getKey());
        }

        return result;
    }

    /**
     * Creates a trie from a list of words.
     */
    private ITrie<Character, Boolean> createTrie() {
        Trie.Builder<Character, Boolean> trieBuilder = new Trie.Builder<>();
        ITrieNode<Character, Boolean> root = TrieNode.create(null, false);
        trieBuilder.setRoot(root);

        for (String currWord : this.words) {
            this.insertWord(root, trieBuilder, currWord);
        }

        return trieBuilder.build();
    }

    /**
     * Inserts a word into the trie.
     */
    private void insertWord(
        ITrieNode<Character, Boolean> root,
        Trie.Builder<Character, Boolean> trieBuilder,
        String word) {

        ITrieNode<Character, Boolean> currNode = root;

        for (int i = 0; i < word.length(); ++i) {
            char currCharacter = word.charAt(i);

            if (currNode.hasChild(currCharacter)) {
                currNode = currNode.getChild(currCharacter);
            }
            else {
                ITrieNode<Character, Boolean> newChild = TrieNode.create(currCharacter, false);
                trieBuilder.addNode(currNode, newChild);

                currNode = newChild;
            }
        }

        currNode.setValue(true);
    }

    /**
     * Creates an alphabetical order graph by using inorder search.
     */
    private <TKey extends Comparable<TKey>, TTrieValue, TGraphValue> IGraph<TKey, TGraphValue> createAlphabeticalOrderGraph(
        ITrie<TKey, TTrieValue> trie) {

        IGraphBuilder<TKey, TGraphValue> graphBuilder = new GraphBuilder<>();

        if (trie.getRoot() == null) {
            return graphBuilder.build();
        }

        ITrieNode<TKey, TTrieValue> currNode = trie.getRoot();

        this.updateAlphabeticalOrderGraph(currNode, graphBuilder);

        return graphBuilder.build();
    }

    /**
     * Updates the alphabetical order graph.
     */
    private <TKey extends Comparable<TKey>, TTrieValue, TGraphValue> void updateAlphabeticalOrderGraph(
        ITrieNode<TKey, TTrieValue> currNode,
        IGraphBuilder<TKey, TGraphValue> graphBuilder) {

        if (currNode == null) {
            return;
        }

        Collection<ITrieNode<TKey, TTrieValue>> children = currNode.getChildren();

        ITrieNode<TKey, TTrieValue> prevChild = null;

        //
        // Update the alphabetical order graph for the current node...
        //
        for (ITrieNode<TKey, TTrieValue> currChild : children) {
            if (prevChild != null && !prevChild.getKey().equals(currChild.getKey())) {

                IVertex<TKey, TGraphValue> sourceVertex = Vertex.of(prevChild.getKey());
                IVertex<TKey, TGraphValue> destinationVertex = Vertex.of(currChild.getKey());

                graphBuilder.addDirectedEdge(sourceVertex, destinationVertex);
            }

            prevChild = currChild;
        }

        //
        // Update the alphabetical order graph for each child...
        //
        for (ITrieNode<TKey, TTrieValue> currChild : children) {
            this.updateAlphabeticalOrderGraph(currChild, graphBuilder);
        }
    }
}
