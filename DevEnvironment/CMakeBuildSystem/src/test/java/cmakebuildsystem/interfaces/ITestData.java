package cmakebuildsystem.interfaces;

import java.util.List;

/**
 * The ITestData interface defines the data of the tests.
 */
public interface ITestData {
    /**
     * Gets cmake projects.
     */
    List<ICMakeProjectResources> getCMakeProjects();
}
