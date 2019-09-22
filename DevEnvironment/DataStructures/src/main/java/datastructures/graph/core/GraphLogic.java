package datastructures.graph.core;

import base.core.Conditions;
import datastructures.graph.GraphException;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IVertex;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
import java.util.Stack;

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
     * Returns true if a loop exists.
     */
    @Override
    public boolean detectLoop() {
        Set<IVertex<TKey, TValue>> visitedVertices = new HashSet<>();
        Set<IVertex<TKey, TValue>> searchVertices = new HashSet<>();

        for (IVertex<TKey, TValue> vertex : this.graph.vertices()) {

            if (visitedVertices.contains(vertex)) {
                continue;
            }

            if (this.detectLoop(vertex, visitedVertices, searchVertices)) {
                return true;
            }

            assert(searchVertices.isEmpty());
        }

        return false;
    }

    /**
     * Performs a topological search of a graph.
     */
    @Override
    public List<IVertex<TKey, TValue>> topologicalSearch() {
        Stack<IVertex<TKey, TValue>> resultStack = new Stack<>();

        Set<IVertex<TKey, TValue>> visitedVertices = new HashSet<>();
        Set<IVertex<TKey, TValue>> searchVertices = new HashSet<>();

        for (IVertex<TKey, TValue> vertex : this.graph.vertices()) {

            if (visitedVertices.contains(vertex)) {
                continue;
            }

            if (!this.topologicalSearch(
                    vertex,
                    visitedVertices,
                    searchVertices,
                    resultStack)) {

                String errorMessage = "The graph contains a loop. No topological search is possible.";
                throw new GraphException(errorMessage);
            }

            assert(searchVertices.isEmpty());
        }

        List<IVertex<TKey, TValue>> result = new ArrayList<>();

        while (!resultStack.empty()) {
            result.add(resultStack.pop());
        }

        return result;
    }

    /**
     * Detects whether a graph contains a loop.
     */
    private boolean detectLoop(
        IVertex<TKey, TValue> vertex,
        Set<IVertex<TKey, TValue>> visitedVertices,
        Set<IVertex<TKey, TValue>> searchVertices) {

        if (visitedVertices.contains(vertex)) {
            return false;
        }

        visitedVertices.add(vertex);
        searchVertices.add(vertex);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(vertex)) {
            if (searchVertices.contains(nextVertex)) {
                return true;
            }

            if (visitedVertices.contains(nextVertex)) {
                continue;
            }

            if (this.detectLoop(nextVertex, visitedVertices, searchVertices)) {
                return true;
            }
        }

        searchVertices.remove(vertex);

        return false;
    }

    /**
     * Detects whether a graph contains a loop.
     */
    private boolean topologicalSearch(
        IVertex<TKey, TValue> vertex,
        Set<IVertex<TKey, TValue>> visitedVertices,
        Set<IVertex<TKey, TValue>> searchVertices,
        Stack<IVertex<TKey, TValue>> resultStack) {

        if (visitedVertices.contains(vertex)) {
            return true;
        }

        visitedVertices.add(vertex);
        searchVertices.add(vertex);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(vertex)) {
            if (searchVertices.contains(nextVertex)) {
                return false;
            }

            if (visitedVertices.contains(nextVertex)) {
                continue;
            }

            if (!this.topologicalSearch(nextVertex, visitedVertices, searchVertices, resultStack)) {
                return false;
            }
        }

        searchVertices.remove(vertex);

        resultStack.push(vertex);

        return true;
    }
}
