package datastructures.graph.core;

import base.core.ListIterator;
import base.interfaces.IPair;
import base.interfaces.ITwoDimensionalList;
import datastructures.core.TestData;
import datastructures.graph.interfaces.IGraph;
import datastructures.graph.interfaces.IVertex;
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
    public void loopDetectionTest() {
        for (IGraph<Integer, String> graph : this.testData.getGraphData().getGraphs()) {
            this.testLoopDetection(graph, false);
        }

        for (IGraph<Integer, String> graph : this.testData.getGraphData().getGraphsWithLoops()) {
            this.testLoopDetection(graph, true);
        }
    }

    /**
     * Tests topological search of a graph.
     */
    @Test
    public void topologicalSearchTest() {
        for (IPair<IGraph<Integer, String>, ITwoDimensionalList<IVertex<Integer, String>>> data : this.testData.getGraphData().getTopologicalSearchData()) {
            this.testTopologicalSearch(data.first(), data.second());
        }
    }

    /**
     * Tests the logic of a loop detection of a graph.
     */
    private void testLoopDetection(IGraph<Integer, String> graph, boolean expectedStatus) {
        boolean status = graph.getGraphLogic().detectLoop();

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Invalid logic of a loop detection in a graph.");
    }

    /**
     * Tests the logic of a topological search of a graph.
     */
    private void testTopologicalSearch(IGraph<Integer, String> graph, ITwoDimensionalList<IVertex<Integer, String>> expectedResult) {
        boolean hasLoop = graph.getGraphLogic().detectLoop();
        this.assertion.assertEquals(
            hasLoop,
            false,
            "Invalid graph. The graph contains a loop. Topological search is impossible.");

        List<IVertex<Integer, String>> result = graph.getGraphLogic().topologicalSearch();

        this.assertion.assertEquals(
            ListIterator.of(result),
            expectedResult.getIterator(),
            "Invalid logic of a topological search in a graph.");
    }
}
