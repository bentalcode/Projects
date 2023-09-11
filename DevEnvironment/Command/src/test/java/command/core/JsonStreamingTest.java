package command.core;

import base.core.ResourceReader;
import command.interfaces.ICommandData;
import command.interfaces.ITestData;
import testbase.core.JsonObjectStreamingTest;
import testbase.interfaces.IJsonObjectStreamingTest;
import org.junit.Test;

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
