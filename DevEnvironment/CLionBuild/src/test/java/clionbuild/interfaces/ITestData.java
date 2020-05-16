package clionbuild.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the resources of project manifests.
     */
    List<Path> getProjectManifestsResources();

    /**
     * Gets the resources of CMakeLists manifests.
     */
    List<Path> getCMakeListsManifestsResources();
}
