package datastructures.graph.core;

import base.core.ArrayLists;
import base.core.HashMaps;
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
import java.util.HashMap;
import java.util.List;
import java.util.Map;

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

        IEdge<Integer, String> edge12 = Edge.newDirectedEdge(vertex1, vertex2);
        IEdge<Integer, String> edge13 = Edge.newDirectedEdge(vertex1, vertex3);
        IEdge<Integer, String> edge23 = Edge.newDirectedEdge(vertex2, vertex3);
        IEdge<Integer, String> edge34 = Edge.newDirectedEdge(vertex3, vertex4);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            edge12,
            edge13,
            edge23,
            edge34);

        Map<IEdge<Integer, String>, Integer> weights = HashMaps.of(
            edge12, 5,
            edge23, 2,
            edge13, 6,
            edge34, 4);

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData1(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData1(vertices);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths =
            this.getGraphShortestPaths1(vertices);

        return new GraphData<>(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
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

        IEdge<Integer, String> edge12 = Edge.newDirectedEdge(vertex1, vertex2);
        IEdge<Integer, String> edge13 = Edge.newDirectedEdge(vertex1, vertex3);
        IEdge<Integer, String> edge24 = Edge.newDirectedEdge(vertex2, vertex4);
        IEdge<Integer, String> edge32 = Edge.newDirectedEdge(vertex3, vertex2);
        IEdge<Integer, String> edge35 = Edge.newDirectedEdge(vertex3, vertex5);
        IEdge<Integer, String> edge45 = Edge.newDirectedEdge(vertex4, vertex5);
        IEdge<Integer, String> edge46 = Edge.newDirectedEdge(vertex4, vertex6);
        IEdge<Integer, String> edge56 = Edge.newDirectedEdge(vertex5, vertex6);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            edge12,
            edge13,
            edge24,
            edge32,
            edge35,
            edge45,
            edge46,
            edge56);

        Map<IEdge<Integer, String>, Integer> weights = new HashMap<>();
        weights.put(edge12, 10);
        weights.put(edge13, 8);
        weights.put(edge24, 6);
        weights.put(edge32, 4);
        weights.put(edge35, 7);
        weights.put(edge45, 9);
        weights.put(edge46, 3);
        weights.put(edge56, 2);

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData2(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData2(vertices);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths =
            this.getGraphShortestPaths2(vertices);

        return new GraphData<>(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
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

        IEdge<Integer, String> edge12 = Edge.newDirectedEdge(vertex1, vertex2);
        IEdge<Integer, String> edge13 = Edge.newDirectedEdge(vertex1, vertex3);
        IEdge<Integer, String> edge25 = Edge.newDirectedEdge(vertex2, vertex5);
        IEdge<Integer, String> edge35 = Edge.newDirectedEdge(vertex3, vertex5);
        IEdge<Integer, String> edge45 = Edge.newDirectedEdge(vertex4, vertex5);

        List<IEdge<Integer, String>> edges = ArrayLists.of(
            edge12,
            edge13,
            edge25,
            edge35,
            edge45);

        Map<IEdge<Integer, String>, Integer> weights = new HashMap<>();
        weights.put(edge12, 7);
        weights.put(edge13, 8);
        weights.put(edge25, 13);
        weights.put(edge35, 6);
        weights.put(edge45, 2);

        List<IPair<IRoute<Integer, String>, List<IWalk<Integer, String>>>> paths = this.getGraphPathsData3(vertices);
        ITwoDimensionalList<IVertex<Integer, String>> topologicalSearch = this.getGraphTopologicalSearchData3(vertices);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths =
            this.getGraphShortestPaths3(vertices);

        return new GraphData<>(
            vertices,
            edges,
            weights,
            paths,
            topologicalSearch,
            shortestPaths);
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

    /**
     * Gets the shortest paths of graph1.
     */
    private Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> getGraphShortestPaths1(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 4);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths = new HashMap<>();
        Map<IVertex<Integer, String>, Integer> shortestPaths1 = HashMaps.of(
            vertex1, 0,
            vertex2, 5,
            vertex3, 6,
            vertex4, 10);

        Map<IVertex<Integer, String>, Integer> shortestPaths2 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, 0,
            vertex3, 2,
            vertex4, 6);

        Map<IVertex<Integer, String>, Integer> shortestPaths3 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, 0,
            vertex4, 4);

        Map<IVertex<Integer, String>, Integer> shortestPaths4 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, 0);

        shortestPaths.put(vertex1, shortestPaths1);
        shortestPaths.put(vertex2, shortestPaths2);
        shortestPaths.put(vertex3, shortestPaths3);
        shortestPaths.put(vertex4, shortestPaths4);

        return shortestPaths;
    }

    /**
     * Gets the shortest paths of graph2.
     */
    private Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> getGraphShortestPaths2(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 6);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);
        IVertex<Integer, String> vertex6 = vertices.get(5);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths = new HashMap<>();
        Map<IVertex<Integer, String>, Integer> shortestPaths1 = HashMaps.of(
            vertex1, 0,
            vertex2, 10,
            vertex3, 8,
            vertex4, 16,
            vertex5, 15,
            vertex6, 17);

        Map<IVertex<Integer, String>, Integer> shortestPaths2 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, 0,
            vertex3, Integer.MAX_VALUE,
            vertex4, 6,
            vertex5, 15,
            vertex6, 9);

        Map<IVertex<Integer, String>, Integer> shortestPaths3 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, 4,
            vertex3, 0,
            vertex4, 10,
            vertex5, 7,
            vertex6, 9);

        Map<IVertex<Integer, String>, Integer> shortestPaths4 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, 0,
            vertex5, 9,
            vertex6, 3);

        Map<IVertex<Integer, String>, Integer> shortestPaths5 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, Integer.MAX_VALUE,
            vertex5, 0,
            vertex6, 2);

        Map<IVertex<Integer, String>, Integer> shortestPaths6 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, Integer.MAX_VALUE,
            vertex5, Integer.MAX_VALUE,
            vertex6, 0);

        shortestPaths.put(vertex1, shortestPaths1);
        shortestPaths.put(vertex2, shortestPaths2);
        shortestPaths.put(vertex3, shortestPaths3);
        shortestPaths.put(vertex4, shortestPaths4);
        shortestPaths.put(vertex5, shortestPaths5);
        shortestPaths.put(vertex6, shortestPaths6);

        return shortestPaths;
    }

    /**
     * Gets the shortest paths of graph3.
     */
    private Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> getGraphShortestPaths3(
        List<IVertex<Integer, String>> vertices) {

        assert(vertices.size() == 5);
        IVertex<Integer, String> vertex1 = vertices.get(0);
        IVertex<Integer, String> vertex2 = vertices.get(1);
        IVertex<Integer, String> vertex3 = vertices.get(2);
        IVertex<Integer, String> vertex4 = vertices.get(3);
        IVertex<Integer, String> vertex5 = vertices.get(4);

        Map<IVertex<Integer, String>, Map<IVertex<Integer, String>, Integer>> shortestPaths = new HashMap<>();
        Map<IVertex<Integer, String>, Integer> shortestPaths1 = HashMaps.of(
            vertex1, 0,
            vertex2, 7,
            vertex3, 8,
            vertex4, Integer.MAX_VALUE,
            vertex5, 14);

        Map<IVertex<Integer, String>, Integer> shortestPaths2 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, 0,
            vertex3, Integer.MAX_VALUE,
            vertex4, Integer.MAX_VALUE,
            vertex5, 13);

        Map<IVertex<Integer, String>, Integer> shortestPaths3 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, 0,
            vertex4, Integer.MAX_VALUE,
            vertex5, 6);

        Map<IVertex<Integer, String>, Integer> shortestPaths4 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, 0,
            vertex5, 2);

        Map<IVertex<Integer, String>, Integer> shortestPaths5 = HashMaps.of(
            vertex1, Integer.MAX_VALUE,
            vertex2, Integer.MAX_VALUE,
            vertex3, Integer.MAX_VALUE,
            vertex4, Integer.MAX_VALUE,
            vertex5, 0);

        shortestPaths.put(vertex1, shortestPaths1);
        shortestPaths.put(vertex2, shortestPaths2);
        shortestPaths.put(vertex3, shortestPaths3);
        shortestPaths.put(vertex4, shortestPaths4);
        shortestPaths.put(vertex5, shortestPaths5);

        return shortestPaths;
    }
}
