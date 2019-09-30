package alphabeticalordercommand.core;

import alphabeticalordercommand.interfaces.IAlphabeticalOrderResults;
import base.core.Conditions;
import base.core.StringIterator;
import base.interfaces.ICalculator;
import datastructures.graph.core.GraphBuilder;
import datastructures.graph.core.Vertex;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphBuilder;
import datastructures.graph.interfaces.IVertex;
import java.util.Collection;
import java.util.List;
import datastructures.trie.core.Trie;
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
        ITrie<Character> wordsTrie = this.createTrie();

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
    private ITrie<Character> createTrie() {
        Trie.Builder<Character> trieBuilder = new Trie.Builder<>();

        for (String currWord : this.words) {
            trieBuilder.addSequence(StringIterator.of(currWord));
        }

        return trieBuilder.build();
    }

    /**
     * Creates an alphabetical order graph by using inorder search.
     */
    private <TKey extends Comparable<TKey>, TValue> IGraph<TKey, TValue> createAlphabeticalOrderGraph(
        ITrie<TKey> trie) {

        IGraphBuilder<TKey, TValue> graphBuilder = new GraphBuilder<>();

        if (trie.getRoot() == null) {
            return graphBuilder.build();
        }

        ITrieNode<TKey> currNode = trie.getRoot();

        this.updateAlphabeticalOrderGraph(currNode, graphBuilder);

        return graphBuilder.build();
    }

    /**
     * Updates the alphabetical order graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void updateAlphabeticalOrderGraph(
        ITrieNode<TKey> currNode,
        IGraphBuilder<TKey, TValue> graphBuilder) {

        if (currNode == null) {
            return;
        }

        Collection<ITrieNode<TKey>> children = currNode.getChildren();

        ITrieNode<TKey> prevChild = null;

        //
        // Update the alphabetical order graph for the current node...
        //
        for (ITrieNode<TKey> currChild : children) {
            if (prevChild != null && !prevChild.getKey().equals(currChild.getKey())) {

                IVertex<TKey, TValue> sourceVertex = Vertex.of(prevChild.getKey());
                IVertex<TKey, TValue> destinationVertex = Vertex.of(currChild.getKey());

                graphBuilder.addDirectedEdge(sourceVertex, destinationVertex);
            }

            prevChild = currChild;
        }

        //
        // Update the alphabetical order graph for each child...
        //
        for (ITrieNode<TKey> currChild : children) {
            this.updateAlphabeticalOrderGraph(currChild, graphBuilder);
        }
    }
}
