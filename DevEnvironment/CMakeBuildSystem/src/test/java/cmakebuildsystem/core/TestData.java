package cmakebuildsystem.core;

import cmakebuildsystem.interfaces.ICMakeProjectResources;
import cmakebuildsystem.interfaces.ITestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private final ICMakeProjectResources devEnvironmentProject = new DevEnvironmentCMakeProjectResources();
    private final ICMakeProjectResources systemCoreProject = new SystemCoreCMakeProjectResources();

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets cmake projects.
     */
    @Override
    public List<ICMakeProjectResources> getCMakeProjects()
    {
        List<ICMakeProjectResources> projects = new ArrayList<>(2);

        projects.add(this.systemCoreProject);
        projects.add(this.devEnvironmentProject);

        return projects;
    }
}
