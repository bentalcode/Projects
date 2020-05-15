package clionbuild.core;

import base.core.ResourceReader;
import clionbuild.interfaces.ITestData;
import org.junit.After;
import org.junit.Before;
import org.junit.Test;
import testbase.core.JsonObjectStreamingTest;
import testbase.interfaces.IJsonObjectStreamingTest;
import java.nio.file.Path;

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
     * Tests streaming json for the CLionProjectManifest class.
     */
    @Test
    public void CLionProjectManifestStreamingTest() {
        for (Path path : this.testData.getProjectManifestsResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionProjectManifest.class);
        }
    }
}
