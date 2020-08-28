package json.core;

import base.core.Pair;
import base.interfaces.IPair;
import json.interfaces.ITestData;
import testbase.core.ResourcePaths;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.List;

/**
 * The TestData class implements the data of the tests.
 */
public final class TestData implements ITestData {
    private static final String DataDirectoryName = "data";
    private static final String SimpleJsonResourcesDirectoryName = "simpleJsonResources";

    private static final List<IPair<String, Class<?>>> SimpleJsonResourcesInformation = new ArrayList<>();

    static {
        SimpleJsonResourcesInformation.add(Pair.make("simpleResource1.json", Types.class));
        SimpleJsonResourcesInformation.add(Pair.make("simpleResource2.json", Fruit.class));
        SimpleJsonResourcesInformation.add(Pair.make("simpleResource3.json", Colors.class));
    }

    /**
     * The TestData constructor.
     */
    public TestData() {
    }

    /**
     * Gets information of simple json resources.
     */
    @Override
    public List<IPair<Path, Class<?>>> getSimpleJsonResourcesInformation() {
        List<IPair<Path, Class<?>>> information = new ArrayList<>();

        for (IPair<String, Class<?>> resourceInformation : TestData.SimpleJsonResourcesInformation) {
            Path path = ResourcePaths.create(
                TestData.DataDirectoryName,
                TestData.SimpleJsonResourcesDirectoryName,
                resourceInformation.first());

            Class<?> classType = resourceInformation.second();

            information.add(Pair.make(path, classType));
        }

        return information;
    }

}
