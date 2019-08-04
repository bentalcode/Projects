package datastructures.graph.core;

import base.core.Pair;
import base.interfaces.IPair;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.graph.interfaces.IVertex;
import java.util.ArrayList;
import java.util.List;

/**
 * The GraphTestData class implements the data of the tests of a graph.
 */
public final class GraphTestData implements IGraphTestData {
    /**
     * The GraphTestData constructor.
     */
    public GraphTestData() {
    }

    /**
     * Gets graphs.
     */
    @Override
    public List<IGraph<Integer, String>> getGraphs() {
        List<IGraph<Integer, String>> graphs = GraphBuilder.createGraphs(this.getGraphsData());
        return graphs;
    }

    /**
     * Gets graphs with loops.
     */
    @Override
    public List<IGraph<Integer, String>> getGraphsWithLoops() {
        List<IGraph<Integer, String>> graphs = GraphBuilder.createGraphs(this.getGraphsDataWithLoops());
        return graphs;
    }

    /**
     * Gets data of graphs.
     */
    @Override
    public List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> getGraphsData() {
        List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> graphsData = new ArrayList<>();

        graphsData.add(this.getGraphData1());

        return graphsData;
    }

    /**
     * Gets data of graphs with loops.
     */
    @Override
    public List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> getGraphsDataWithLoops() {
        List<IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>>> graphsData = new ArrayList<>();

        graphsData.add(this.getGraphDataWithLoop1());

        return graphsData;
    }

    /**
     * Gets data of graph1.
     */
    private IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>> getGraphData1() {
        List<IVertex<Integer, String>> vertices = new ArrayList<>();

        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<IEdge<Integer, String>> edges = new ArrayList<>();
        edges.add(Edge.newDirectedEdge(vertex1, vertex2));
        edges.add(Edge.newDirectedEdge(vertex1, vertex3));

        edges.add(Edge.newDirectedEdge(vertex2, vertex3));

        edges.add(Edge.newDirectedEdge(vertex3, vertex4));

        return Pair.of(vertices, edges);
    }

    /**
     * Gets data of graph2.
     */
    private IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>> getGraphDataWithLoop1() {
        List<IVertex<Integer, String>> vertices = new ArrayList<>();

        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<IEdge<Integer, String>> edges = new ArrayList<>();
        edges.add(Edge.newDirectedEdge(vertex1, vertex2));
        edges.add(Edge.newDirectedEdge(vertex1, vertex3));

        edges.add(Edge.newDirectedEdge(vertex2, vertex3));

        edges.add(Edge.newDirectedEdge(vertex3, vertex1));
        edges.add(Edge.newDirectedEdge(vertex3, vertex4));

        edges.add(Edge.newDirectedEdge(vertex4, vertex4));

        return Pair.of(vertices, edges);
    }
}
