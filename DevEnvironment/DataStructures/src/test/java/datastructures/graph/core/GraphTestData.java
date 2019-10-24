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
        graphsData.add(this.getGraphData3());

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
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<IVertex<Integer, String>> vertices = ArrayLists.of(
            vertex1,
            vertex2,
            vertex3,
            vertex4);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            Edge.newDirectedEdge(vertex1, vertex2),
            Edge.newDirectedEdge(vertex1, vertex3),
            Edge.newDirectedEdge(vertex2, vertex3),
            Edge.newDirectedEdge(vertex3, vertex4));

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData1(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData1(vertices);

        return new GraphData<>(
            vertices,
            edges,
            paths,
            topologicalSearch);
    }

    /**
     * Gets data of graph2.
     */
    private IGraphData<Integer, String> getGraphData2() {
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");
        IVertex<Integer, String> vertex5 = Vertex.of(5, "e");
        IVertex<Integer, String> vertex6 = Vertex.of(6, "f");

        List<IVertex<Integer, String>> vertices = ArrayLists.of(
            vertex1,
            vertex2,
            vertex3,
            vertex4,
            vertex5,
            vertex6);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            Edge.newDirectedEdge(vertex1, vertex2),
            Edge.newDirectedEdge(vertex1, vertex3),
            Edge.newDirectedEdge(vertex2, vertex4),
            Edge.newDirectedEdge(vertex3, vertex2),
            Edge.newDirectedEdge(vertex3, vertex5),
            Edge.newDirectedEdge(vertex4, vertex5),
            Edge.newDirectedEdge(vertex4, vertex6),
            Edge.newDirectedEdge(vertex5, vertex6));

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData2(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData2(vertices);

        return new GraphData<>(
            vertices,
            edges,
            paths,
            topologicalSearch);
    }

    /**
     * Gets data of graph3.
     */
    private IGraphData<Integer, String> getGraphData3() {
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");
        IVertex<Integer, String> vertex5 = Vertex.of(5, "e");

        List<IVertex<Integer, String>> vertices = ArrayLists.of(
            vertex1,
            vertex2,
            vertex3,
            vertex4,
            vertex5);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            Edge.newDirectedEdge(vertex1, vertex2),
            Edge.newDirectedEdge(vertex1, vertex3),
            Edge.newDirectedEdge(vertex2, vertex5),
            Edge.newDirectedEdge(vertex3, vertex5),
            Edge.newDirectedEdge(vertex4, vertex5));

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData3(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData3(vertices);

        return new GraphData<>(
            vertices,
            edges,
            paths,
            topologicalSearch);
    }

    /**
     * Gets data of graph1.
     */
    private IGraphData<Integer, String> getGraphDataWithLoop1() {
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<IVertex<Integer, String>> vertices = ArrayLists.of(
            vertex1,
            vertex2,
            vertex3,
            vertex4);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            Edge.newDirectedEdge(vertex1, vertex2),
            Edge.newDirectedEdge(vertex1, vertex3),
            Edge.newDirectedEdge(vertex2, vertex3),
            Edge.newDirectedEdge(vertex3, vertex1),
            Edge.newDirectedEdge(vertex3, vertex4),
            Edge.newDirectedEdge(vertex4, vertex4));

        return new GraphData<>(
            vertices,
            edges);
    }

    /**
     * Gets the paths data of graph1.
     */
    private List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> getGraphPathsData1(
        List<IVertex<Integer, String>> vertices) {

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = new ArrayList<>();

        assert(vertices.size() == 4);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);

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

        return paths;
    }

    /**
     * Gets the paths data of graph2.
     */
    private List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> getGraphPathsData2(
        List<IVertex<Integer, String>> vertices) {

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = new ArrayList<>();

        assert(vertices.size() == 6);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);
        IVertex<Integer, String> vertex6 = vertices.get(5);

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

        return paths;
    }

    /**
     * Gets the paths data of graph3.
     */
    private List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> getGraphPathsData3(
        List<IVertex<Integer, String>> vertices) {

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = new ArrayList<>();

        assert(vertices.size() == 5);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);

        IRoute<Integer, String> route12 = Route.of(vertex1, vertex2);
        List<IWalk<Integer, String>> walks12 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2))
        );
        paths.add(Pair.of(route12, walks12));

        IRoute<Integer, String> route13 = Route.of(vertex1, vertex3);
        List<IWalk<Integer, String>> walks13 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex3))
        );
        paths.add(Pair.of(route13, walks13));

        IRoute<Integer, String> route15 = Route.of(vertex1, vertex5);
        List<IWalk<Integer, String>> walks15 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex1, vertex2, vertex5),
            ArrayLists.of(vertex1, vertex3, vertex5))
        );
        paths.add(Pair.of(route15, walks15));

        IRoute<Integer, String> route25 = Route.of(vertex2, vertex5);
        List<IWalk<Integer, String>> walks25 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex2, vertex5))
        );
        paths.add(Pair.of(route25, walks25));

        IRoute<Integer, String> route35 = Route.of(vertex3, vertex5);
        List<IWalk<Integer, String>> walks35 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex3, vertex5))
        );
        paths.add(Pair.of(route35, walks35));

        IRoute<Integer, String> route45 = Route.of(vertex4, vertex5);
        List<IWalk<Integer, String>> walks45 = Walk.createWalks(ArrayLists.of(
            ArrayLists.of(vertex4, vertex5))
        );
        paths.add(Pair.of(route45, walks45));

        return paths;
    }

    /**
     * Gets the topological search data of graph1.
     */
    private ITwoDimensionalList<IVertex<Integer, String>> getGraphTopologicalSearchData1(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 4);
        IVertex<Integer, String> vertex1 = Vertex.of(1, "a");
        IVertex<Integer, String> vertex2 = Vertex.of(2, "b");
        IVertex<Integer, String> vertex3 = Vertex.of(3, "c");
        IVertex<Integer, String> vertex4 = Vertex.of(4, "d");

        List<List<IVertex<Integer, String>>> data = ArrayLists.of(
            List.of(vertex1),
            List.of(vertex2),
            List.of(vertex3),
            List.of(vertex4));

        return new TwoDimensionalList<>(data);
    }

    /**
     * Gets the topological search data of graph2.
     */
    private ITwoDimensionalList<IVertex<Integer, String>> getGraphTopologicalSearchData2(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 6);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);
        IVertex<Integer, String> vertex6 = vertices.get(5);

        List<List<IVertex<Integer, String>>> data = ArrayLists.of(
            List.of(vertex1),
            List.of(vertex3),
            List.of(vertex2),
            List.of(vertex4),
            List.of(vertex5),
            List.of(vertex6));

        return new TwoDimensionalList<>(data);
    }

    /**
     * Gets the topological search data of graph3.
     */
    private ITwoDimensionalList<IVertex<Integer, String>> getGraphTopologicalSearchData3(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 5);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);

        List<List<IVertex<Integer, String>>> data = ArrayLists.of(
            List.of(vertex4),
            List.of(vertex1),
            List.of(vertex3),
            List.of(vertex2),
            List.of(vertex5));

        return new TwoDimensionalList<>(data);
    }
}
