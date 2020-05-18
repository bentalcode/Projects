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
    public void clionProjectManifestStreamingTest() {
        for (Path path : this.testData.getProjectManifestResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionProjectManifest.class);
        }
    }

    /**
     * Tests streaming json for the CLionModuleManifest class.
     */
    @Test
    public void clionModuleManifestStreamingTest() {
        for (Path path : this.testData.getModuleManifestResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionModuleManifest.class);
        }
    }

    /**
     * Tests streaming json for the CMakeListsManifest class.
     */
    @Test
    public void cmakeListsManifestStreamingTest() {
        for (Path path : this.testData.getCMakeListsManifestResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeListsManifest.class);
        }
    }

    /**
     * Tests streaming json for the CLionProject class.
     */
    @Test
    public void clionProjectStreamingTest() {
        for (Path path : this.testData.getProjectResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionProject.class);
        }
    }

    /**
     * Tests streaming json for the CLionModule class.
     */
    @Test
    public void clionModuleStreamingTest() {
        for (Path path : this.testData.getModuleResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionModule.class);
        }
    }

    /**
     * Tests streaming json for the CLionProjectDeploymentResult class.
     */
    @Test
    public void clionProjectDeploymentResultStreamingTest() {
        for (Path path : this.testData.getProjectDeploymentResultResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CLionProjectDeploymentResult.class);
        }
    }
}
