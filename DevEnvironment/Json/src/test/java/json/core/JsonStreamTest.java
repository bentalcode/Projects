package json.core;

import base.core.ResourceReader;
import java.nio.file.Path;
import json.interfaces.IFruit;
import json.interfaces.ITestData;
import org.junit.After;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

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
        JsonStream stream = new JsonStream();
        IFruit obj1 = stream.fromJson(json, Fruit.class);

        String json2 = stream.toJson(obj1);

        IFruit obj2 = stream.fromJson(json2, Fruit.class);

        Assert.assertTrue(
            "The json streaming logic is invalid.",
            obj1.equals(obj2));
    }
}
