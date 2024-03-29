package datastructures.graph.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import datastructures.graph.GraphException;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Set;
import java.util.Stack;

/**
 * The GraphLogic class implements logic of a graph.
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
        Set<IVertex<TKey, TValue>> currPath = new HashSet<>();

        for (IVertex<TKey, TValue> vertex : this.graph.vertices()) {

            if (visitedVertices.contains(vertex)) {
                continue;
            }

            if (!this.topologicalSearch(
                    vertex,
                    visitedVertices,
                    currPath,
                    resultStack)) {

                String errorMessage =
                    "The graph contains a loop, aborting topological search. No topological search is possible.";

                throw new GraphException(errorMessage);
            }

            assert(currPath.isEmpty());
        }

        List<IVertex<TKey, TValue>> result = new ArrayList<>();

        while (!resultStack.empty()) {
            result.add(resultStack.pop());
        }

        return result;
    }

    /**
     * Finds paths by performing a Breadth-First search.
     */
    @Override
    public List<IWalk<TKey, TValue>> findPathsWithBreadthFirstSearch(IRoute<TKey, TValue> route) {
        Conditions.validateNotNull(
            route,
            "The route.");

        List<IWalk<TKey, TValue>> paths = new ArrayList<>();

        this.findPathsWithBreadthFirstSearch(
            route.source(),
            route.destination(),
            paths);

        return paths;
    }

    /**
     * Finds paths by performing a Depth-First search.
     */
    @Override
    public List<IWalk<TKey, TValue>> findPathsWithDepthFirstSearch(IRoute<TKey, TValue> route) {
        Conditions.validateNotNull(
            route,
            "The route.");

        Set<IVertex<TKey, TValue>> visited = new HashSet<>();
        IWalk<TKey, TValue> currPath = new Walk<>();
        List<IWalk<TKey, TValue>> paths = new ArrayList<>();

        this.findPathsWithDepthFirstSearch(
            route.source(),
            route.destination(),
            currPath,
            visited,
            paths);

        return paths;
    }

    /**
     * Finds the shortest paths from the source vertex to all other vertices in a given graph.
     */
    @Override
    public Map<IVertex<TKey, TValue>, Integer> findShortestPaths(
        IVertex<TKey, TValue> src,
        Map<IEdge<TKey, TValue>, Integer> weights) {

        Conditions.validateNotNull(
            src,
            "The source vertex.");

        Conditions.validateNotNull(
            weights,
            "The weights of edges.");

        //
        // Initializes the distances map...
        //
        Map<IVertex<TKey, TValue>, Integer> distances = new HashMap<>();

        for (IVertex<TKey, TValue> vertex : this.graph.vertices()) {
            int initializedDistance = vertex.equals(src) ? 0 : Integer.MAX_VALUE;
            distances.put(vertex, initializedDistance);
        }

        //
        // Create the priority queue based on minimum distance...
        //
        PriorityQueue<IPair<IVertex<TKey, TValue>, Integer>> queue = new PriorityQueue<>(
                (left, right) -> {

                    if (left == null && right == null) {
                        return 0;
                    }

                    if (left == null) {
                        return -1;
                    }

                    if (right == null) {
                        return 1;
                    }

                    int leftDistance = left.second();
                    int rightDistance = right.second();

                    return Integer.compare(leftDistance, rightDistance);
                }
        );

        queue.offer(Pair.make(src, 0));

        while (!queue.isEmpty()) {
            IPair<IVertex<TKey, TValue>, Integer> curr = queue.poll();

            IVertex<TKey, TValue> currVertex = curr.first();
            int currDistance = curr.second();

            for (IEdge<TKey, TValue> edge : this.graph.getAdjacencyMatrix().getAdjacentEdges(currVertex)) {
                IVertex<TKey, TValue> nextVertex = edge.destination();

                if (!weights.containsKey(edge))
                {
                    String errorMessage = "The edge: " + edge + " does not exist in the edge-weights map.";
                    throw new GraphException(errorMessage);
                }

                int edgeWeight = weights.get(edge);

                int nextDistance = currDistance + edgeWeight;

                if (nextDistance < distances.get(nextVertex)) {
                    queue.offer(Pair.make(nextVertex, nextDistance));
                    distances.put(nextVertex, nextDistance);
                }
            }
        }

        return distances;
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
     * Performs a topological search of a graph.
     */
    private boolean topologicalSearch(
        IVertex<TKey, TValue> vertex,
        Set<IVertex<TKey, TValue>> visitedVertices,
        Set<IVertex<TKey, TValue>> currPath,
        Stack<IVertex<TKey, TValue>> resultStack) {

        if (visitedVertices.contains(vertex)) {
            return true;
        }

        visitedVertices.add(vertex);
        currPath.add(vertex);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(vertex)) {
            if (currPath.contains(nextVertex)) {
                return false;
            }

            if (visitedVertices.contains(nextVertex)) {
                continue;
            }

            boolean status = this.topologicalSearch(
                nextVertex,
                visitedVertices,
                currPath,
                resultStack);

            if (!status) {
                return false;
            }
        }

        currPath.remove(vertex);
        resultStack.push(vertex);

        return true;
    }

    /**
     * Find paths by performing a Breadth-First search.
     */
    private void findPathsWithBreadthFirstSearch(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination,
        List<IWalk<TKey, TValue>> result) {

        Queue<IPair<IVertex<TKey, TValue>, IWalk<TKey, TValue>>> queue = new LinkedList<>();
        queue.offer(Pair.make(source, new Walk<>()));

        while (!queue.isEmpty()) {
            IPair<IVertex<TKey, TValue>, IWalk<TKey, TValue>> curr = queue.poll();

            IVertex<TKey, TValue> currVertex = curr.first();
            IWalk<TKey, TValue> currWalk = curr.second();

            currWalk.addVertex(currVertex);

            if (currVertex.equals(destination)) {
                result.add(Walk.newWalk(currWalk));
            }
            else {
                for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(currVertex)) {
                    if (currWalk.visited(nextVertex)) {
                        continue;
                    }

                    IWalk<TKey, TValue> nextWalk = Walk.newWalk(currWalk);
                    queue.offer(Pair.make(nextVertex, nextWalk));
                }
            }
        }
    }

    /**
     * Find paths by performing a Depth-First search.
     */
    private void findPathsWithDepthFirstSearch(
        IVertex<TKey, TValue> source,
        IVertex<TKey, TValue> destination,
        IWalk<TKey, TValue> currPath,
        Set<IVertex<TKey, TValue>> visited,
        List<IWalk<TKey, TValue>> result) {

        if (visited.contains(source)) {
            return;
        }

        if (source.equals(destination)) {
            IWalk<TKey, TValue> newPath = Walk.newWalk(currPath);
            newPath.addVertex(source);
            result.add(newPath);

            return;
        }

        currPath.addVertex(source);
        visited.add(source);

        for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(source)) {

            if (visited.contains(nextVertex)) {
                continue;
            }

            this.findPathsWithDepthFirstSearch(
                nextVertex,
                destination,
                currPath,
                visited,
                result);
        }

        currPath.removeLastVertex();
        visited.remove(source);
    }
}
