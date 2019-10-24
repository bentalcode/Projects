package datastructures.graph.core;

import base.core.Conditions;
import base.core.Pair;
import base.interfaces.IPair;
import datastructures.graph.GraphException;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
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
     * Find paths by performing a Breadth-First search.
     */
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
     * Find paths by performing a Depth-First search.
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

    /**
     * Find paths by performing a Breadth-First search.
     */
    private void findPathsWithBreadthFirstSearch(
        IVertex<TKey, TValue> start,
        IVertex<TKey, TValue> end,
        List<IWalk<TKey, TValue>> paths) {

        Queue<IPair<IVertex<TKey, TValue>, IWalk<TKey, TValue>>> queue = new LinkedList<>();
        queue.offer(Pair.of(start, new Walk<>()));

        while (!queue.isEmpty()) {
            IPair<IVertex<TKey, TValue>, IWalk<TKey, TValue>> curr = queue.poll();

            IVertex<TKey, TValue> currVertex = curr.first();
            IWalk<TKey, TValue> currWalk = curr.second();

            currWalk.addVertex(currVertex);

            if (currVertex.equals(end)) {
                paths.add(Walk.newWalk(currWalk));
            }
            else {
                for (IVertex<TKey, TValue> nextVertex : this.graph.getAdjacencyMatrix().getAdjacentVertices(currVertex)) {
                    if (currWalk.visited(nextVertex)) {
                        continue;
                    }

                    IWalk<TKey, TValue> nextWalk = Walk.newWalk(currWalk);
                    queue.offer(Pair.of(nextVertex, nextWalk));
                }
            }
        }
    }

    /**
     * Find paths by performing a Depth-First search.
     */
    private void findPathsWithDepthFirstSearch(
        IVertex<TKey, TValue> curr,
        IVertex<TKey, TValue> end,
        IWalk<TKey, TValue> currPath,
        Set<IVertex<TKey, TValue>> visited,
        List<IWalk<TKey, TValue>> paths) {

        if (visited.contains(curr)) {
            return;
        }

        if (curr.equals(end)) {
            IWalk<TKey, TValue> newPath = Walk.newWalk(currPath);
            newPath.addVertex(curr);
            paths.add(newPath);

            return;
        }

        currPath.addVertex(curr);
        visited.add(curr);
        assert(currPath.size() == visited.size());

        for (IVertex<TKey, TValue> next : this.graph.getAdjacencyMatrix().getAdjacentVertices(curr)) {
            if (visited.contains(next)) {
                continue;
            }

            this.findPathsWithDepthFirstSearch(
                next,
                end,
                currPath,
                visited,
                paths);
        }

        currPath.removeLastVertex();
        visited.remove(curr);
    }
}
