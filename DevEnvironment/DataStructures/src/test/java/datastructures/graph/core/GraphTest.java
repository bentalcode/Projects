package datastructures.graph.core;

import base.core.ListIterator;
import base.core.Lists;
import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
import datastructures.core.TestData;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IGraphData;
import datastructures.graph.interfaces.IGraphDefinition;
import datastructures.graph.interfaces.IRoute;
import datastructures.graph.interfaces.IVertex;
import datastructures.graph.interfaces.IWalk;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.List;

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
     * Initialize the tests.
     */
    @Before
    public void setUp() {
    }

    /**
     * Un-Initializes the tests.
     */
    @After
    public void tearDown() {
    }

    /**
     * Tests whether a graph has a loop.
     */
    @Test
    public void graphLoopDetectionTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testLoopDetection(data, false);
        }

        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsDataWithLoops()) {
            this.testLoopDetection(data, true);
        }
    }

    /**
     * Tests topological search of a graph.
     */
    @Test
    public void graphTopologicalSearchTest() {
        for (IPair<IGraphData<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>> data :
            this.testData.getGraphData().getTopologicalSearchData()) {

            this.testTopologicalSearch(
                data.first(),
                data.second());
        }
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Breadth-First search.
     */
    @Test
    public void graphFindPathsWithBreadthFirstSearchTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testFindPathsWithBreadthFirstSearch(data);
        }
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Depth-First search.
     */
    @Test
    public void graphFindPathsWithDepthFirstSearchTest() {
        for (IGraphData<Integer, String> data : this.testData.getGraphData().getGraphsData()) {
            this.testFindPathsWithDepthFirstSearch(data);
        }
    }

    /**
     * Tests the logic of a loop detection of a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testLoopDetection(
        IGraphData<TKey, TValue> data,
        boolean expectedStatus) {

        IGraph<TKey, TValue> graph = this.createGraph(data);

        boolean status = graph.getGraphLogic().detectLoop();

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Invalid logic of a loop detection in a graph.");
    }

    /**
     * Tests the logic of a topological search of a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> void testTopologicalSearch(
        IGraphData<TKey, TValue> data,
        ITwoDimensionalList<IVertex<TKey, TValue>> expectedResult) {

        IGraph<TKey, TValue> graph = this.createGraph(data);

        boolean hasLoop = graph.getGraphLogic().detectLoop();
        this.assertion.assertEquals(
            hasLoop,
            false,
            "Invalid graph. The graph contains a loop. Topological search is impossible.");

        List<IVertex<TKey, TValue>> result = graph.getGraphLogic().topologicalSearch();

        this.assertion.assertEqualsWithIterators(
            ListIterator.of(result),
            expectedResult.getIterator(),
            "Invalid logic of a topological search in a graph.");
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Breadth-First search.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindPathsWithBreadthFirstSearch(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);

        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> routesData = data.getPaths();

        for (IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>> routeData : routesData) {
            IRoute<TKey, TValue> route = routeData.first();
            List<IWalk<TKey, TValue>> expectedPaths = routeData.second();

            List<IWalk<TKey, TValue>> paths = graph.getGraphLogic().findPathsWithBreadthFirstSearch(route);

            Lists.sort(paths, Walk.defaultComparator());

            this.assertion.assertEqualsWithIterators(
                ListIterator.of(paths),
                ListIterator.of(expectedPaths),
                "Invalid logic of finding paths with a Breadth-First search in a graph.");
        }
    }

    /**
     * Tests the logic of finding paths in a graph by performing a Depth-First search.
     */
    private <TKey extends Comparable<TKey>, TValue> void testFindPathsWithDepthFirstSearch(IGraphData<TKey, TValue> data) {
        IGraph<TKey, TValue> graph = this.createGraph(data);

        List<IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>>> routesData = data.getPaths();

        for (IPair<IRoute<TKey, TValue>, List<IWalk<TKey, TValue>>> routeData : routesData) {
            IRoute<TKey, TValue> route = routeData.first();
            List<IWalk<TKey, TValue>> expectedPaths = routeData.second();

            List<IWalk<TKey, TValue>> paths = graph.getGraphLogic().findPathsWithDepthFirstSearch(route);

            Lists.sort(paths, Walk.defaultComparator());

            this.assertion.assertEqualsWithIterators(
                ListIterator.of(paths),
                ListIterator.of(expectedPaths),
                "Invalid logic of finding paths with a Depth-First search in a graph.");
        }
    }

    /**
     * Creates a graph.
     */
    private <TKey extends Comparable<TKey>, TValue> IGraph<TKey, TValue> createGraph(IGraphData<TKey, TValue> data) {
        IGraphDefinition<TKey, TValue> graphDefinition = GraphDefinition.of(data.vertices(), data.edges());
        IGraph<TKey, TValue> graph = GraphBuilder.create(graphDefinition);
        return graph;
    }
}
