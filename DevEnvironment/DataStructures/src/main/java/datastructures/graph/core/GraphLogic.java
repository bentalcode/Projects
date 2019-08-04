package datastructures.graph.core;

import base.core.Conditions;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IVertex;
import java.util.HashSet;
import java.util.Set;

/**
 * The GraphLogic class implements detection logic of a graph.
 */
public final class GraphLogic<TKey extends Comparable<TKey>, TValue> implements IGraphLogic<TKey, TValue> {
    private final IGraph<TKey, TValue> graph;

    /**
     * The GraphLogic constructor.
     */
    public GraphLogic(IGraph<TKey, TValue> graph) {
        Conditions.validateNotNull(
            graph,
            "The graph.");

        this.graph = graph;
    }

    /**
     * Detects whether a graph contains a loop.
     */
    @Override
    public boolean detectLoop() {
        Set<IVertex<TKey, TValue>> visited = new HashSet<>();

        for (IVertex<TKey, TValue> vertex : this.graph.vertices()) {

            if (visited.contains(vertex)) {
                continue;
            }

            Set<IVertex<TKey, TValue>> searchStack = new HashSet<>();

            if (this.detectLoop(vertex, visited, searchStack)) {
                return true;
            }

            assert(searchStack.isEmpty());
        }

        return false;
    }

    /**
     * Detects whether a graph contains a loop.
     */
    private boolean detectLoop(
        IVertex<TKey, TValue> vertex,
        Set<IVertex<TKey, TValue>> visited,
        Set<IVertex<TKey, TValue>> searchStack) {

        if (visited.contains(vertex)) {
            return false;
        }

        visited.add(vertex);
        searchStack.add(vertex);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(vertex)) {
            if (searchStack.contains(nextVertex)) {
                return true;
            }

            if (visited.contains(nextVertex)) {
                continue;
            }

            this.detectLoop(nextVertex, visited, searchStack);
        }

        searchStack.remove(vertex);

        return false;
    }
}
