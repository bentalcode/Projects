package datastructures.graph.interfaces;

import base.interfaces.IPair;
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
    List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> getGraphsData();

    /**
     * Gets data of graphs with loops.
     */
    List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> getGraphsDataWithLoops();
}
