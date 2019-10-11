package datastructures.graph.interfaces;

import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
import java.util.List;

/**
 * The IGraphData interface defines data of graph.
 */
public interface IGraphData<TKey extends Comparable<TKey>, TValue> {
    /**
     * Gets the vertices of the graph.
     */
    List<IVertex<TKey, TValue>> vertices();

    /**
     * Gets the edges of the graph.
     */
    List<IEdge<TKey, TValue>> edges();

    /**
     * Gets the paths for the defined routes in the graph.
     */
    List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> getPaths();

    /**
     * Gets the topological search of the graph.
     */
    ITwoDimensionalList<IVertex<TKey, TValue>> getTopologicalSearch();
}
