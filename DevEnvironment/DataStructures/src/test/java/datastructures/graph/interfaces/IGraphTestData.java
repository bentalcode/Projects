package datastructures.graph.interfaces;

import base.interfaces.IPair;
import datastructures.list.interfaces.ITwoDimensionalList;
import java.util.List;

/**
 * The IGraphTestData interface defines the data of the tests of a graph.
 */
public interface IGraphTestData {
    /**
     * Gets graphs.
     */
    List<IGraph<Integer, String>> getGraphs();

    /**
     * Gets graphs.
     */
    List<IGraph<Integer, String>> getGraphsWithLoops();

    /**
     * Gets data of graphs.
     */
    List<IGraphData<Integer, String>> getGraphsData();

    /**
     * Gets data of graphs with loops.
     */
    List<IGraphData<Integer, String>> getGraphsDataWithLoops();

    /**
     * Gets data of topological search of graphs.
     */
    List<IPair<IGraph<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>>> getTopologicalSearchData();

    /**
     * Generates a random vertex by integer.
     */
    IVertex<Integer, Integer> nextVertexByInteger();

    /**
     * Generates a random vertex by double.
     */
    IVertex<Double, Double> nextVertexByDouble();

    /**
     * Generates a random vertex by character.
     */
    IVertex<Character, Character> nextVertexByCharacter();

    /**
     * Generates a random vertex by string.
     */
    IVertex<String, String> nextVertexByString();

    /**
     * Generates a random edge by integer.
     */
    IEdge<Integer, Integer> nextDirectedEdgeByInteger();

    /**
     * Generates a random edge by double.
     */
    IEdge<Double, Double> nextDirectedEdgeByDouble();

    /**
     * Generates a random edge by character.
     */
    IEdge<Character, Character> nextDirectedEdgeByCharacter();

    /**
     * Generates a random edge by string.
     */
    IEdge<String, String> nextDirectedEdgeByString();
}
