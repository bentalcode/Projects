package datastructures.graph.core;

import base.core.Conditions;
import base.interfaces.IVisitor;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphTraversal;
import datastructures.graph.interfaces.IVertex;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Set;

/**
 * The GraphTraversal class implements various traversals of a graph.
 */
public final class GraphTraversal<TKey extends Comparable<TKey>, TValue> implements IGraphTraversal<TKey, TValue> {
    private final IGraph<TKey, TValue> graph;

    /**
     * The GraphTraversal constructor.
     */
    public GraphTraversal(IGraph<TKey, TValue> graph) {
        Conditions.validateNotNull(
            graph,
            "The graph.");

        this.graph = graph;
    }

    /**
     * Performs a Breadth-First search.
     */
    @Override
    public void breadthFirstSearch(
        IVertex<TKey, TValue> vertex,
        IVisitor<IVertex<TKey, TValue>> visitor) {

        Conditions.validateNotNull(
            vertex,
            "The vertex from which to start the Breadth-First search.");

        Conditions.validateNotNull(
            visitor,
            "The visitor to apply in the Breadth-First search.");

        Queue<IVertex<TKey, TValue>> queue = new LinkedList<>();
        queue.offer(vertex);

        Set<IVertex<TKey, TValue>> visited = new HashSet<>();

        while (!queue.isEmpty()) {
            IVertex<TKey, TValue> currVertex = queue.poll();

            visitor.visit(currVertex);
            visited.add(currVertex);

            for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(currVertex)) {

                if (visited.contains(nextVertex)) {
                    continue;
                }

                queue.offer(nextVertex);
            }
        }
    }

    /**
     * Performs a Depth-First search.
     */
    @Override
    public void depthFirstSearch(
        IVertex<TKey, TValue> vertex,
        IVisitor<IVertex<TKey, TValue>> visitor) {

        Conditions.validateNotNull(
            vertex,
            "The vertex from which to start the Depth-First search.");

        Conditions.validateNotNull(
            visitor,
            "The visitor to apply in the Depth-First search.");

        Set<IVertex<TKey, TValue>> visited = new HashSet<>();
        this.depthFirstSearch(vertex, visited, visitor);
    }

    /**
     * Performs a Depth-First search.
     */
    private void depthFirstSearch(
        IVertex<TKey, TValue> vertex,
        Set<IVertex<TKey, TValue>> visited,
        IVisitor<IVertex<TKey, TValue>> visitor) {

        if (visited.contains(vertex)) {
            return;
        }

        visitor.visit(vertex);
        visited.add(vertex);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(vertex)) {
            if (visited.contains(nextVertex)) {
                continue;
            }

            this.depthFirstSearch(nextVertex, visited, visitor);
        }

        visited.remove(vertex);
    }
}
