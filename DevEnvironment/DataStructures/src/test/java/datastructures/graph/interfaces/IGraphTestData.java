package datastructures.graph.interfaces;

import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
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
}
