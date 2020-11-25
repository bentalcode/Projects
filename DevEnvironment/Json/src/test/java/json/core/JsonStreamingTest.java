package json.core;

import base.core.Casting;
import base.core.ResourceReader;
import base.interfaces.IPair;
import java.nio.file.Path;
import json.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.JsonObjectStreamingTest;
import testbase.interfaces.IJsonObjectStreamingTest;

/**
 * The JsonStreamingTest class implements tests for reading writing from/to json streams.
 */
public final class JsonStreamingTest {
    private final IJsonObjectStreamingTest streamingTest = new JsonObjectStreamingTest();
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
        for (IPair<Path, Class<?>> resourceInformation : this.testData.getSimpleJsonResourcesInformation()) {
            String json = ResourceReader.loadString(resourceInformation.first());

            this.streamingTest.testStreaming(json, Casting.cast(resourceInformation.second()));
        }
    }
}
