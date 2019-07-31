package graph.interfaces;

import base.interfaces.IUnaryComparator;

/**
 * The IAdjacencyMatrix interface defines an adjacency matrix of a graph.
 */
public interface IAdjacencyMatrix extends IUnaryComparator<IAdjacencyMatrix> {
    /**
     * Gets the connections of an adjacency matrix.
     */
    boolean[][] connections();

    /**
     * Checks whether two vertices are connected.
     */
    boolean connected(int row, int column);
}
