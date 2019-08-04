package datastructures.graph.core;

import datastructures.core.TestData;
import datastructures.graph.interfaces.IGraph;
import datastructures.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

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
     * Tests the loop detection logic of a graph.
     */
    private void testLoopDetection(IGraph graph, boolean expectedStatus) {
        boolean status = graph.getGraphLogic().detectLoop();

        this.assertion.assertEquals(
            status,
            expectedStatus,
            "Invalid logic of loop detection in a graph.");
    }
}
