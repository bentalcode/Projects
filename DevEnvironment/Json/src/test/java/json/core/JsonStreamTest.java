package json.core;

import base.core.ResourceReader;
import json.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;

import java.nio.file.Path;

/**
 * The JsonStreamTest class implements tests for reading writing from/to json streams.
 */
public final class JsonStreamTest {
    private final ITestData testData = new TestData();

    /**
     * The JsonStreamTest constructor.
     */
    public JsonStreamTest() {
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
     * Tests streaming json.
     */
    @Test
    public void jsonStreamingTest() {
        for (Path path : this.testData.getSimpleJsonResources()) {
            String json = ResourceReader.loadString(path);
            this.testStreamingJson(json);
        }
    }

    /**
     * Tests streaming json.
     */
    private void testStreamingJson(String json) {
    }
}
