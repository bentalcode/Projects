package json.core;

import base.core.Casting;
import base.core.ResourceReader;
import base.interfaces.IPair;
import java.nio.file.Path;
import json.interfaces.IJsonSerialization;
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
        for (IPair<Path, Class<?>> resourceInformation : this.testData.getSimpleJsonResourcesInformation()) {
            String json = ResourceReader.loadString(resourceInformation.first());
            this.testStreamingJson(json, Casting.cast(resourceInformation.second()));
        }
    }

    /**
     * Tests streaming json.
     */
    private <T extends IJsonSerialization> void testStreamingJson(String json, Class<T> classType) {
        JsonStream stream = new JsonStream();
        T obj1 = stream.fromJson(json, classType);

        String json2 = stream.toJson(obj1);

        T obj2 = stream.fromJson(json2, classType);

        Assert.assertTrue(
            "The json streaming logic is invalid.",
            obj1.equals(obj2));
    }
}
