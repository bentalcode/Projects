package command.interfaces;

import java.nio.file.Path;
import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets the resources of commands manifests.
     */
    List<Path> getCommandManifestResources();
}
