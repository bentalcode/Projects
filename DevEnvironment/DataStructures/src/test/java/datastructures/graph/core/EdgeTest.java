package datastructures.graph.core;

import base.core.HashMaps;
import datastructures.graph.interfaces.IGraphTestData;
import datastructures.graph.interfaces.IEdge;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
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
     * Tests the logic of mapping an edge.
     */
    @Test
    public void mappingEdgeTest() {
        IEdge<Integer, Integer> edge1 = this.testData.nextDirectedEdgeByInteger();
        IEdge<Integer, Integer> edge2 = this.testData.nextDirectedEdgeByInteger();

        Map<IEdge<Integer, Integer>, Integer> map = HashMaps.make(edge1, 1, edge2, 2);

        this.testMappingEdge(map, edge1, true);
        this.testMappingEdge(map, edge2, true);
    }

    /**
     * Tests identifying logic of edges by an integer key.
     */
    private void testIdentifyingEdgesByIntegerKey() {
        IEdge<Integer, Integer> edge1 = this.testData.nextDirectedEdgeByInteger();
        IEdge<Integer, Integer> edge2 = Edge.newDirectedEdge(
            Vertex.make(edge1.source().getKey()),
            Vertex.make(edge1.destination().getKey()));

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
            Vertex.make(edge1.source().getKey()),
            Vertex.make(edge1.destination().getKey()));

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
            Vertex.make(edge1.source().getKey()),
            Vertex.make(edge1.destination().getKey()));

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
            Vertex.make(edge1.source().getKey()),
            Vertex.make(edge1.destination().getKey()));

        Set<IEdge> edges = new HashSet<>();
        edges.add(edge1);
        edges.add(edge2);

        this.assertion.assertTrue(
            edges.size() == 1,
            "Incorrect logic of identifying edges by a string key.");
    }

    /**
     * Tests the logic of mapping an edge.
     */
    private <TKey extends Comparable<TKey>, TValue> void testMappingEdge(
        Map<IEdge<TKey, TValue>, Integer> map,
        IEdge<TKey, TValue> edge,
        boolean exists)
    {
        boolean status = map.containsKey(edge);

        this.assertion.assertEquals(
            status,
            exists,
            "Incorrect logic of mapping an edge.");
    }
}
