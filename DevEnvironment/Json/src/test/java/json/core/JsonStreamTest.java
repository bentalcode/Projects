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
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;

/**
 * The JsonStreamTest class implements tests for reading writing from/to json streams.
 */
public final class JsonStreamTest {
    private final IAssertion assertion = new Assertion();
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

        this.assertion.assertTrue(
            obj1.equals(obj2),
            "The json streaming logic is invalid.");
    }
}
