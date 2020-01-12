package json.core;

import base.core.Casting;
import base.core.ResourceReader;
import base.interfaces.IPair;
import java.nio.file.Path;
import json.interfaces.IJsonSerialization;
import json.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.Assertion;
import testbase.interfaces.IAssertion;
import testbase.interfaces.IJsonStreamingTest;

/**
 * The JsonStreamTest class implements tests for reading writing from/to json streams.
 */
public final class JsonStreamingTest {
    private final IAssertion assertion = new Assertion();
    private final ITestData testData = new TestData();

    /**
     * The JsonStreamTest constructor.
     */
    public JsonStreamingTest() {
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
        IJsonStreamingTest test = new testbase.core.JsonStreamingTest();

        for (IPair<Path, Class<?>> resourceInformation : this.testData.getSimpleJsonResourcesInformation()) {
            String json = ResourceReader.loadString(resourceInformation.first());

            test.testStreaming(json, Casting.cast(resourceInformation.second()));
        }
    }

    /**
     * Tests streaming json.
     */
    private <T extends IJsonSerialization> void testStreamingJson(String json, Class<T> classType) {
        T obj1 = JsonStream.deserialize(json, classType);

        String json2 = JsonStream.serialize(obj1);

        T obj2 = JsonStream.deserialize(json2, classType);

        this.assertion.assertTrue(
            obj1.equals(obj2),
            "The json streaming logic is invalid.");
    }
}
