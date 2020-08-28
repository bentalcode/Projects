package datastructures.graph.core;

import datastructures.graph.interfaces.IGraphTestData;
import datastructures.graph.interfaces.IVertex;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import java.util.HashSet;
import java.util.Set;

/**
 * The VertexTest class implements tests for a vertex.
 */
public final class VertexTest {
    private final IGraphTestData testData = new GraphTestData();
    private final IAssertion assertion = new Assertion();

    /**
     * The VertexTest constructor.
     */
    public VertexTest() {
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
     * Tests identifying logic of vertices.
     */
    @Test
    public void identifyingVerticesTest() {
        for (int i = 0; i < 100; ++i) {
            this.testIdentifyingVerticesByIntegerKey();
            this.testIdentifyingVerticesByDoubleKey();
            this.testIdentifyingVerticesByCharacterKey();
            this.testIdentifyingVerticesByStringKey();
        }
    }

    /**
     * Tests identifying logic of vertices by an integer key.
     */
    private void testIdentifyingVerticesByIntegerKey() {
        IVertex<Integer, Integer> vertex1 = this.testData.nextVertexByInteger();
        IVertex<Integer, Integer> vertex2 = Vertex.make(vertex1.getKey());

        Set<IVertex> vertices = new HashSet<>();
        vertices.add(vertex1);
        vertices.add(vertex2);

        this.assertion.assertTrue(
            vertices.size() == 1,
            "Incorrect logic of identifying vertices by an integer key.");
    }

    /**
     * Tests identifying logic of vertices by a double key.
     */
    private void testIdentifyingVerticesByDoubleKey() {
        IVertex<Double, Double> vertex1 = this.testData.nextVertexByDouble();
        IVertex<Double, Double> vertex2 = Vertex.make(vertex1.getKey());

        Set<IVertex> vertices = new HashSet<>();
        vertices.add(vertex1);
        vertices.add(vertex2);

        this.assertion.assertTrue(
            vertices.size() == 1,
            "Incorrect logic of identifying vertices by a double key.");
    }

    /**
     * Tests identifying logic of vertices by a character key.
     */
    private void testIdentifyingVerticesByCharacterKey() {
        IVertex<Character, Character> vertex1 = this.testData.nextVertexByCharacter();
        IVertex<Character, Character> vertex2 = Vertex.make(vertex1.getKey());

        Set<IVertex> vertices = new HashSet<>();
        vertices.add(vertex1);
        vertices.add(vertex2);

        this.assertion.assertTrue(
            vertices.size() == 1,
            "Incorrect logic of identifying vertices by a character key.");
    }

    /**
     * Tests identifying logic of vertices by a string key.
     */
    private void testIdentifyingVerticesByStringKey() {
        IVertex<String, String> vertex1 = this.testData.nextVertexByString();
        IVertex<String, String> vertex2 = Vertex.make(vertex1.getKey());

        Set<IVertex> vertices = new HashSet<>();
        vertices.add(vertex1);
        vertices.add(vertex2);

        this.assertion.assertTrue(
            vertices.size() == 1,
            "Incorrect logic of identifying vertices by a string key.");
    }
}
