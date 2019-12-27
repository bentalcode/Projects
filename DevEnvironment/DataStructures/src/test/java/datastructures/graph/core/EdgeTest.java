package datastructures.graph.core;

import datastructures.graph.interfaces.IGraphTestData;
import datastructures.graph.interfaces.IEdge;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.HashSet;
import java.util.Set;

/**
 * The GraphTest class implements tests for a edges.
 */
public final class EdgeTest {
    private final IGraphTestData testData = new GraphTestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The EdgeTest constructor.
     */
    public EdgeTest() {
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
     * Tests identifying logic of edges.
     */
    @Test
    public void identifyingEdgesTest() {
        for (int i = 0; i < 1; ++i) {
            this.testIdentifyingEdgesByIntegerKey();
            this.testIdentifyingEdgesByDoubleKey();
            this.testIdentifyingEdgesByCharacterKey();
            this.testIdentifyingEdgesByStringKey();
        }
    }

    /**
     * Tests identifying logic of edges by an integer key.
     */
    private void testIdentifyingEdgesByIntegerKey() {
        IEdge<Integer, Integer> edge1 = this.testData.nextDirectedEdgeByInteger();
        IEdge<Integer, Integer> edge2 = Edge.newDirectedEdge(
            Vertex.of(edge1.source().getKey()),
            Vertex.of(edge1.destination().getKey()));

        if (edge1.equals(edge2)) {
            assert(edge1.hashCode() == edge2.hashCode());
        }

        Set<IEdge> edges = new HashSet<>();
        edges.add(edge1);
        edges.add(edge2);

        this.assertion.assertTrue(
            edges.size() == 1,
            "Incorrect logic of identifying edges by an integer key.");
    }

    /**
     * Tests identifying logic of edges by a double key.
     */
    private void testIdentifyingEdgesByDoubleKey() {
        IEdge<Double, Double> edge1 = this.testData.nextDirectedEdgeByDouble();
        IEdge<Double, Double> edge2 = Edge.newDirectedEdge(
            Vertex.of(edge1.source().getKey()),
            Vertex.of(edge1.destination().getKey()));

        Set<IEdge> edges = new HashSet<>();
        edges.add(edge1);
        edges.add(edge2);

        this.assertion.assertTrue(
            edges.size() == 1,
            "Incorrect logic of identifying edges by a double key.");
    }

    /**
     * Tests identifying logic of edges by a character key.
     */
    private void testIdentifyingEdgesByCharacterKey() {
        IEdge<Character, Character> edge1 = this.testData.nextDirectedEdgeByCharacter();
        IEdge<Character, Character> edge2 = Edge.newDirectedEdge(
            Vertex.of(edge1.source().getKey()),
            Vertex.of(edge1.destination().getKey()));

        Set<IEdge> edges = new HashSet<>();
        edges.add(edge1);
        edges.add(edge2);

        this.assertion.assertTrue(
            edges.size() == 1,
            "Incorrect logic of identifying edges by a character key.");
    }

    /**
     * Tests identifying logic of edges by a string key.
     */
    private void testIdentifyingEdgesByStringKey() {
        IEdge<String, String> edge1 = this.testData.nextDirectedEdgeByString();
        IEdge<String, String> edge2 = Edge.newDirectedEdge(
            Vertex.of(edge1.source().getKey()),
            Vertex.of(edge1.destination().getKey()));

        Set<IEdge> edges = new HashSet<>();
        edges.add(edge1);
        edges.add(edge2);

        this.assertion.assertTrue(
            edges.size() == 1,
            "Incorrect logic of identifying edges by a string key.");
    }
}
