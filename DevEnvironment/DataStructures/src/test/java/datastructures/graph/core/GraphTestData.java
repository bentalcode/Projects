package datastructures.graph.core;

import base.core.Pair;
import base.core.TwoDimensionalList;
import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
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
        graphsData.add(this.getGraphData2());

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
     * Gets data of topological search of graphs.
     */
    @Override
    public List<IPair<IGraph<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>>> getTopologicalSearchData() {
        List<IPair<IGraph<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>>> data = new ArrayList<>();

        IGraph<Integer, String> graph1 = GraphBuilder.createGraph(this.getGraphData1().first(), this.getGraphData1().second());
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearchData1 = this.getGraph1TopologicalSearchData();

        data.add(Pair.of(graph1, topologicalSearchData1));

        return data;
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
     * Gets the topological search data of graph1.
     */
    private ITwoDimensionalList<IVertex<Integer, String>> getGraph1TopologicalSearchData() {
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<List<IVertex<Integer, String>>> data = new ArrayList<>();
        List<IVertex<Integer, String>> level1 = List.of(vertex1);
        List<IVertex<Integer, String>> level2 = List.of(vertex2);
        List<IVertex<Integer, String>> level3 = List.of(vertex3);
        List<IVertex<Integer, String>> level4 = List.of(vertex4);

        data.add(level1);
        data.add(level2);
        data.add(level3);
        data.add(level4);

        return new TwoDimensionalList<>(data);
    }

    /**
     * Gets data of graph2.
     */
    private IPair<List<IVertex<Integer, String>>, List<IEdge<Integer, String>>> getGraphData2() {
        List<IVertex<Integer, String>> vertices = new ArrayList<>();

        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");
        IVertex<Integer, String> vertex5 = Vertex.of(5, "e");
        IVertex<Integer, String> vertex6 = Vertex.of(6, "f");

        List<IEdge<Integer, String>> edges = new ArrayList<>();
        edges.add(Edge.newDirectedEdge(vertex3, vertex4));

        edges.add(Edge.newDirectedEdge(vertex4, vertex2));

        edges.add(Edge.newDirectedEdge(vertex5, vertex1));
        edges.add(Edge.newDirectedEdge(vertex5, vertex2));

        edges.add(Edge.newDirectedEdge(vertex6, vertex1));
        edges.add(Edge.newDirectedEdge(vertex6, vertex3));

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
