package command.core;

import base.core.ResourceReader;
import command.interfaces.ICommandData;
import command.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.JsonObjectStreamingTest;
import testbase.interfaces.IJsonObjectStreamingTest;

/**
 * The JsonStreamTest class implements tests for reading writing from/to json streams.
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
     * Tests streaming json for the command manifest class.
     */
    @Test
    public void commandManifestStreamingTest() {
        for (ICommandData data : this.testData.getCommandsData()) {
            String json = ResourceReader.loadString(data.getManifestResourcePath());

            this.streamingTest.testStreaming(json, CommandManifest.class);
        }
    }
}
