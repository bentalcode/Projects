package datastructures.graph.core;

import base.core.ListIterator;
import base.core.Lists;
import base.interfaces.IEquatableComparator;
import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
import datastructures.core.TestData;
import datastructures.graph.interfaces.IEdge;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IGraphDefinition;
import datastructures.graph.interfaces.IGraphLogic;
import datastructures.graph.interfaces.IPathFinder;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import datastructures.interfaces.ITestData;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;
import java.util.Map;
import org.junit.Test;

/**
 * The GraphTest class implements tests for a graph.
 */
public final class GraphTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The GraphTest constructor.
     */
    public GraphTest() {
    }

    /**
     * Tests whether a graph has a loop.
     */
    @Test
    public void loopDetectionTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testLoopDetection(data, false);
        }

        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsDataWithLoops()) {
            this.testLoopDetection(data, true);
        }
    }

    /**
     * Tests the logic of a topological search of a graph.
     */
    @Test
    public void topologicalSearchTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testTopologicalSearch(data);
        }
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Breadth-First search.
     */
    @Test
    public void findPathsWithBreadthFirstSearchTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testFindPathsWithBreadthFirstSearch(data);
        }
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Depth-First search.
     */
    @Test
    public void findPathsWithDepthFirstSearchTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testFindPathsWithDepthFirstSearch(data);
        }
    }

    /**
     * Tests the logic of finding the shortest paths in a graph.
     */
    @Test
    public void graphFindShortestPathsTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testFindShortestPaths(data);
        }
    }

    /**
     * Tests the logic of a loop detection of a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testLoopDetection(
        IGraphData<TKey, TValue> data,
        boolean expectedStatus) {

        IGraph<TKey, TValue> graph = this.createGraph(data);
        IGraphLogic<TKey, TValue> graphLogic = new GraphLogic<>(graph);
        boolean status = graphLogic.detectLoop();

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Incorrect logic of a loop detection in a graph.");
    }

    /**
     * Tests the logic of a topological search of a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testTopologicalSearch(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);
        IGraphLogic<TKey, TValue> graphLogic = new GraphLogic<>(graph);

        List<IVertex<TKey, TValue>> topologicalSearch = graphLogic.topologicalSearch();
        ITwoDimensionalList<IVertex<TKey, TValue>> expectedTopologicalSearch = data.getTopologicalSearch();

        this.assertion.assertEqualsWithIterators(
            ListIterator.make(topologicalSearch),
            expectedTopologicalSearch.getIterator(),
            "Incorrect logic of a topological search in a graph.");
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Breadth-First search.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindPathsWithBreadthFirstSearch(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);
        IGraphLogic<TKey, TValue> graphLogic = new GraphLogic<>(graph);

        IPathFinder<TKey, TValue> pathFinder = graphLogic::findPathsWithBreadthFirstSearch;

        this.testFindPaths(
            pathFinder,
            data.getPaths(),
            "Breadth First Search");
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Depth-First search.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindPathsWithDepthFirstSearch(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);
        IGraphLogic<TKey, TValue> graphLogic = new GraphLogic<>(graph);

        IPathFinder<TKey, TValue> pathFinder = graphLogic::findPathsWithDepthFirstSearch;

        this.testFindPaths(
            pathFinder,
            data.getPaths(),
            "Depth First Search");
    }

    /**
     * Tests the logic of finding paths in a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindPaths(
        IPathFinder<TKey, TValue> pathFinder,
        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> routesData,
        String method) {

        for (IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>> routeData : routesData) {
            IRoute<TKey, TValue> route = routeData.first();
            List<IWalk<TKey, TValue>> expectedPaths = routeData.second();

            List<IWalk<TKey, TValue>> paths = pathFinder.findPaths(route);

            Lists.sort(paths, Walk.defaultComparator());

            this.assertion.assertEqualsWithIterators(
                ListIterator.make(paths),
                ListIterator.make(expectedPaths),
                "Incorrect logic of finding paths with a " + method + " + in a graph.");
        }
    }

    /**
     * Tests the logic of finding the shortest paths in a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindShortestPaths(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);
        IGraphLogic<TKey, TValue> graphLogic = new GraphLogic<>(graph);

        Map<IEdge<TKey, TValue>, Integer> weights = data.getWeights();
        Map<IVertex<TKey, TValue>, Map<IVertex<TKey, TValue>, Integer>> graphShortestPaths = data.getShortestPaths();

        for (IVertex<TKey, TValue> vertex : data.vertices()) {
            Map<IVertex<TKey, TValue>, Integer> shortestPaths = graphLogic.findShortestPaths(vertex, weights);
            Map<IVertex<TKey, TValue>, Integer> expectedShortestPaths = graphShortestPaths.get(vertex);

            IEquatableComparator<IVertex<TKey, TValue>> keyComparator = Vertex.defaultComparator();
            IEquatableComparator<Integer> valueComparator = base.core.Comparator.make();

            this.assertion.assertEquals(
                shortestPaths,
                expectedShortestPaths,
                keyComparator,
                valueComparator,
                "Incorrect logic of calculating shortest paths in a graph.");
        }
    }

    /**
     * Creates a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> IGraph<TKey, TValue> createGraph(IGraphData<TKey, TValue> data) {
        IGraphDefinition<TKey, TValue> graphDefinition = GraphDefinition.make(data.vertices(), data.edges());
        return GraphBuilder.make(graphDefinition);
    }
}
