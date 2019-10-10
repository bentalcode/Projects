package datastructures.graph.core;

import base.core.ArrayLists;
import base.core.Pair;
import base.core.RandomGenerator;
import base.core.TwoDimensionalList;
import base.interfaces.IPair;
import base.interfaces.IRandomGenerator;
import base.interfaces.ITwoDimensionalList;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import java.util.ArrayList;
import java.util.List;

/**
 * The GraphTestData class implements the data of the tests of a graph.
 */
public final class GraphTestData implements IGraphTestData {
    private final IRandomGenerator randomGenerator = new RandomGenerator();

    /**
     * The GraphTestData constructor.
     */
    public GraphTestData() {
    }

    /**
     * Gets data of graphs.
     */
    @Override
    public List<IGraphData<Integer, String>> getGraphsData() {
        List<IGraphData<Integer, String>> graphsData = new ArrayList<>();

        graphsData.add(this.getGraphData1());
        graphsData.add(this.getGraphData2());

        return graphsData;
    }

    /**
     * Gets data of graphs with loops.
     */
    @Override
    public List<IGraphData<Integer, String>> getGraphsDataWithLoops() {
        List<IGraphData<Integer, String>> graphsData = new ArrayList<>();

        graphsData.add(this.getGraphDataWithLoop1());

        return graphsData;
    }

    /**
     * Gets data of topological search of graphs.
     */
    @Override
    public List<IPair<IGraphData<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>>> getTopologicalSearchData() {
        List<IPair<IGraphData<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>>> data = new ArrayList<>();

        IGraphData<Integer, String> graphData = this.getGraphData1();
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearchData = this.getGraph1TopologicalSearchData();

        data.add(Pair.of(graphData, topologicalSearchData));

        return data;
    }

    /**
     * Generates a random vertex by integer.
     */
    @Override
    public IVertex<Integer, Integer> nextVertexByInteger() {
        int key = this.randomGenerator.nextInteger();
        int value = this.randomGenerator.nextInteger();

        IVertex<Integer, Integer> vertex = Vertex.of(key, value);

        return vertex;
    }

    /**
     * Generates a random vertex by double.
     */
    @Override
    public IVertex<Double, Double> nextVertexByDouble() {
        double key = this.randomGenerator.nextDouble();
        double value = this.randomGenerator.nextDouble();

        IVertex<Double, Double> vertex = Vertex.of(key, value);

        return vertex;
    }

    /**
     * Generates a random vertex by character.
     */
    @Override
    public IVertex<Character, Character> nextVertexByCharacter() {
        char key = this.randomGenerator.nextCharacter();
        char value = this.randomGenerator.nextCharacter();

        IVertex<Character, Character> vertex = Vertex.of(key, value);

        return vertex;
    }

    /**
     * Generates a random vertex by string.
     */
    @Override
    public IVertex<String, String> nextVertexByString() {
        String key = this.randomGenerator.nextString();
        String value = this.randomGenerator.nextString();

        IVertex<String, String> vertex = Vertex.of(key, value);

        return vertex;
    }

    /**
     * Generates a random edge by integer.
     */
    @Override
    public IEdge<Integer, Integer> nextDirectedEdgeByInteger() {
        IVertex<Integer, Integer> sourceVertex = this.nextVertexByInteger();
        IVertex<Integer, Integer> destinationVertex = this.nextVertexByInteger();

        IEdge<Integer, Integer> edge = Edge.newDirectedEdge(sourceVertex, destinationVertex);

        return edge;
    }

    /**
     * Generates a random edge by double.
     */
    @Override
    public IEdge<Double, Double> nextDirectedEdgeByDouble() {
        IVertex<Double, Double> sourceVertex = this.nextVertexByDouble();
        IVertex<Double, Double> destinationVertex = this.nextVertexByDouble();

        IEdge<Double, Double> edge = Edge.newDirectedEdge(sourceVertex, destinationVertex);

        return edge;
    }

    /**
     * Generates a random edge by character.
     */
    @Override
    public IEdge<Character, Character> nextDirectedEdgeByCharacter() {
        IVertex<Character, Character> sourceVertex = this.nextVertexByCharacter();
        IVertex<Character, Character> destinationVertex = this.nextVertexByCharacter();

        IEdge<Character, Character> edge = Edge.newDirectedEdge(sourceVertex, destinationVertex);

        return edge;
    }

    /**
     * Generates a random edge by string.
     */
    @Override
    public IEdge<String, String> nextDirectedEdgeByString() {
        IVertex<String, String> sourceVertex = this.nextVertexByString();
        IVertex<String, String> destinationVertex = this.nextVertexByString();

        IEdge<String, String> edge = Edge.newDirectedEdge(sourceVertex, destinationVertex);

        return edge;
    }

    /**
     * Gets data of graph1.
     */
    private IGraphData<Integer, String> getGraphData1() {
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

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = new ArrayList<>();

        IRoute<Integer, String> route12 = Route.of(vertex1, vertex2);
        List<IWalk<Integer, String>> walks12 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2))
        );
        paths.add(Pair.of(route12, walks12));

        IRoute<Integer, String> route13 = Route.of(vertex1, vertex3);
        List<IWalk<Integer, String>> walks13 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex3),
            ArrayLists.of(vertex1, vertex3))
        );
        paths.add(Pair.of(route13, walks13));

        IRoute<Integer, String> route14 = Route.of(vertex1, vertex4);
        List<IWalk<Integer, String>> walks14 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex3, vertex4),
            ArrayLists.of(vertex1, vertex3, vertex4))
        );
        paths.add(Pair.of(route14, walks14));

        IRoute<Integer, String> route23 = Route.of(vertex2, vertex3);
        List<IWalk<Integer, String>> walks23 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex2, vertex3))
        );
        paths.add(Pair.of(route23, walks23));

        IRoute<Integer, String> route24 = Route.of(vertex2, vertex4);
        List<IWalk<Integer, String>> walks24 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex2, vertex3, vertex4))
        );
        paths.add(Pair.of(route24, walks24));

        IRoute<Integer, String> route34 = Route.of(vertex3, vertex4);
        List<IWalk<Integer, String>> walks34 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex3, vertex4))
        );
        paths.add(Pair.of(route34, walks34));

        return new GraphData<>(
            vertices,
            edges,
            paths);
    }

    /**
     * Gets data of graph2.
     */
    private IGraphData<Integer, String> getGraphData2() {
        List<IVertex<Integer, String>> vertices = new ArrayList<>();

        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");
        IVertex<Integer, String> vertex5 = Vertex.of(5, "e");
        IVertex<Integer, String> vertex6 = Vertex.of(6, "f");

        List<IEdge<Integer, String>> edges = new ArrayList<>();
        edges.add(Edge.newDirectedEdge(vertex1, vertex2));
        edges.add(Edge.newDirectedEdge(vertex1, vertex3));
        edges.add(Edge.newDirectedEdge(vertex2, vertex4));
        edges.add(Edge.newDirectedEdge(vertex3, vertex2));
        edges.add(Edge.newDirectedEdge(vertex3, vertex5));
        edges.add(Edge.newDirectedEdge(vertex4, vertex5));
        edges.add(Edge.newDirectedEdge(vertex4, vertex6));
        edges.add(Edge.newDirectedEdge(vertex5, vertex6));

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = new ArrayList<>();

        IRoute<Integer, String> route12 = Route.of(vertex1, vertex2);
        List<IWalk<Integer, String>> walks12 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2),
            ArrayLists.of(vertex1, vertex3, vertex2))
        );
        paths.add(Pair.of(route12, walks12));

        IRoute<Integer, String> route13 = Route.of(vertex1, vertex3);
        List<IWalk<Integer, String>> walks13 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex3))
        );
        paths.add(Pair.of(route13, walks13));

        IRoute<Integer, String> route14 = Route.of(vertex1, vertex4);
        List<IWalk<Integer, String>> walks14 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex4),
            ArrayLists.of(vertex1, vertex3, vertex2, vertex4))
        );
        paths.add(Pair.of(route14, walks14));

        IRoute<Integer, String> route15 = Route.of(vertex1, vertex5);
        List<IWalk<Integer, String>> walks15 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex4, vertex5),
            ArrayLists.of(vertex1, vertex3, vertex2, vertex4, vertex5),
            ArrayLists.of(vertex1, vertex3, vertex5))
        );
        paths.add(Pair.of(route15, walks15));

        IRoute<Integer, String> route16 = Route.of(vertex1, vertex6);
        List<IWalk<Integer, String>> walks16 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex4, vertex5, vertex6),
            ArrayLists.of(vertex1, vertex2, vertex4, vertex6),
            ArrayLists.of(vertex1, vertex3, vertex2, vertex4, vertex5, vertex6),
            ArrayLists.of(vertex1, vertex3, vertex2, vertex4, vertex6),
            ArrayLists.of(vertex1, vertex3, vertex5, vertex6))
        );
        paths.add(Pair.of(route16, walks16));

        return new GraphData<>(
            vertices,
            edges,
            paths);
    }

    /**
     * Gets data of graph2.
     */
    private IGraphData<Integer, String> getGraphDataWithLoop1() {
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

        return new GraphData<>(
            vertices,
            edges,
            new ArrayList<>());
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
}
