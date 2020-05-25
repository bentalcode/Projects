package cmakebuild.core;

import base.core.ResourceReader;
import cmakebuild.interfaces.ITestData;
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
     * Tests streaming json for the CMakeProjectManifest class.
     */
    @Test
    public void cmakeProjectManifestStreamingTest() {
        for (Path path : this.testData.getProjectManifestResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeProjectManifest.class);
        }
    }

    /**
     * Tests streaming json for the CMakeModuleManifest class.
     */
    @Test
    public void cmakeModuleManifestStreamingTest() {
        for (Path path : this.testData.getModuleManifestResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeModuleManifest.class);
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
     * Tests streaming json for the CMakeProject class.
     */
    @Test
    public void cmakeProjectStreamingTest() {
        for (Path path : this.testData.getProjectResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeProject.class);
        }
    }

    /**
     * Tests streaming json for the CMakeModule class.
     */
    @Test
    public void cmakeModuleStreamingTest() {
        for (Path path : this.testData.getModuleResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeModule.class);
        }
    }

    /**
     * Tests streaming json for the CMakeProjectDeploymentResult class.
     */
    @Test
    public void cmakeProjectDeploymentResultStreamingTest() {
        for (Path path : this.testData.getProjectDeploymentResultResources()) {
            String json = ResourceReader.loadString(path);

            this.streamingTest.testStreaming(json, CMakeProjectDeploymentResult.class);
        }
    }
}
