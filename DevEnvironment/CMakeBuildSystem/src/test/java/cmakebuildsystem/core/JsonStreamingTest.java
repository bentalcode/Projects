package cmakebuildsystem.core;

import base.core.ResourceReader;
import cmakebuildsystem.interfaces.ICMakeProjectResources;
import cmakebuildsystem.interfaces.ITestData;
import java.nio.file.Path;
import java.util.List;
import org.junit.Test;
import testbase.core.JsonObjectStreamingTest;
import testbase.interfaces.IJsonObjectStreamingTest;

/**
 * The JsonStreamTest class implements tests for reading writing from/to json streams.
 */
public final class JsonStreamingTest {
    private final ITestData testData = new TestData();
    private final IJsonObjectStreamingTest streamingTest = new JsonObjectStreamingTest();

    /**
     * The JsonStreamTest constructor.
     */
    public JsonStreamingTest() {
    }

    /**
     * Tests streaming json for the CMakeProjectManifest class.
     */
    @Test
    public void cmakeProjectManifestStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeProjectManifestStreamingTest(project);
        }
    }

    /**
     * Tests streaming json for the CMakeModuleManifest class.
     */
    @Test
    public void cmakeModuleManifestStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeModuleManifestStreaming(project);
        }
    }

    /**
     * Tests streaming json for the CMakeListsManifest class.
     */
    @Test
    public void cmakeListsManifestStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeListsManifestStreaming(project);
        }
    }

    /**
     * Tests streaming json for the CMakeProject class.
     */
    @Test
    public void cmakeProjectStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeProjectStreaming(project);
        }
    }

    /**
     * Tests streaming json for the CMakeModule class.
     */
    @Test
    public void cmakeModuleStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeModuleStreaming(project);
        }
    }

    /**
     * Tests streaming json for the CMakeProjectDeploymentResult class.
     */
    @Test
    public void cmakeProjectDeploymentResultStreamingTest() {
        List<ICMakeProjectResources> projects = this.testData.getCMakeProjects();

        for (ICMakeProjectResources project : projects) {
            testCMakeProjectDeploymentResultStreaming(project);
        }
    }

    /**
     * Tests streaming json for the CMakeProjectManifest class.
     */
    private void testCMakeProjectManifestStreamingTest(ICMakeProjectResources project) {
        for (Path path : project.getProjectManifestResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeProjectManifest.class);
        }
    }

    /**
     * Tests streaming json for the CMakeModuleManifest class.
     */
    private void testCMakeModuleManifestStreaming(ICMakeProjectResources project) {
        for (Path path : project.getModuleManifestResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeModuleManifest.class);
        }
    }

    /**
     * Tests streaming json for the CMakeListsManifest class.
     */
    private void testCMakeListsManifestStreaming(ICMakeProjectResources project) {
        for (Path path : project.getCMakeListsManifestResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeListsManifest.class);
        }
    }

    /**
     * Tests streaming json for the CMakeProject class.
     */
    private void testCMakeProjectStreaming(ICMakeProjectResources project) {
        for (Path path : project.getProjectResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeProject.class);
        }
    }

    /**
     * Tests streaming json for the CMakeModule class.
     */
    private void testCMakeModuleStreaming(ICMakeProjectResources project) {
        for (Path path : project.getModuleResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeModule.class);
        }
    }

    /**
     * Tests streaming json for the CMakeProjectDeploymentResult class.
     */
    private void testCMakeProjectDeploymentResultStreaming(ICMakeProjectResources project) {
        for (Path path : project.getProjectDeploymentResultResources()) {
            String json = ResourceReader.loadString(path);
            this.streamingTest.testStreaming(json, CMakeProjectDeploymentResult.class);
        }
    }
}
