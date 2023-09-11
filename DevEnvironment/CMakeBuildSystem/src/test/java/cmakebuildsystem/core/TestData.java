package cmakebuildsystem.core;

import cmakebuildsystem.interfaces.ICMakeProjectResources;
import cmakebuildsystem.interfaces.ITestData;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private final ICMakeProjectResources projectResources = new CMakeProjectResources();

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
        List<ICMakeProjectResources> projects = new ArrayList<>(1);
        projects.add(this.projectResources);
        return projects;
    }
}
